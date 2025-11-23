#include<iostream>
#include<string>
using namespace std;

string rotations="";

class Node{
    public:
    Node* left;
    Node* right;
    int id;
    int height;
    Node(int d):id(d){
        left=right=nullptr;
        height=0;
    }
};

int height(Node *node){
    if(node==nullptr){
        return 0;
    }else{
        int left_h=height(node->left);
        int right_h=height(node->right);
        if (left_h>right_h)
        {
            return left_h+1;
        }else{
            return right_h+1;
        }
    }
}

int max(int a,int b){
    if (a>b)
    {
        return a;
    }else{
        return b;
    }
}

int getBalance(Node* node){
    if(node==nullptr){
        return 0;
    }
    return height(node->left)-height(node->right);
}

Node* rightRot(Node* y){
    Node* x=y->left;
    Node* t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x;
}

Node* leftRot(Node* x){
    Node* y=x->right;
    Node* t2=y->left;
    
    y->left=x;
    x->right=t2;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return y;
}

Node* insert(Node* root, int key){
    if (root==nullptr)
    {
        Node* newNode=new Node(key);
        return newNode;
    }

    if (key<root->id)
    {
        root->left=insert(root->left,key);
    }else if(key>root->id){
        root->right=insert(root->right,key);
    }else{
        return root;
    }
    
    root->height=1+max(height(root->left),height(root->right));
    
    int balance=getBalance(root);

    
    if (balance>1 && key<root->left->id)
    {
        rotations+=" LL ";
        return rightRot(root);
    }
    
    if (balance<-1 && key>root->right->id)
    {
        rotations+=" RR ";
        return leftRot(root);
    }
    
    if (balance>1 && key>root->left->id)
    {
        rotations+=" RL ";
        root->left= leftRot(root->left);
        return rightRot(root);
    }
    
    if (balance<-1 && key < root->right->id)
    {
        rotations+=" LR ";
        root->right= rightRot(root->right);
        return leftRot(root);
    }
    return root;
}
Node* minValNode(Node* root){
    Node* curr=root;
    while (curr->left!=nullptr)
    {
        curr=curr->left;
    }
    return curr;
}

Node* deletion(Node* root,int key){
    if(root==nullptr){
        return root;
    }
    if (key<root->id)
    {
        root->left=deletion(root->left,key);
    }else if(key>root->id){
        root->right=deletion(root->right,key);
    }else{
        if ((root->left==nullptr)||(root->right==nullptr))
        {
            Node* temp;
            if (root->left==nullptr){
                temp=root->left;
            }else{
                temp=root->right;
            }

            if (temp==nullptr){
                temp=root;
                root=nullptr;
            }else{
                *root=*temp;
            }
            delete temp;

        }else{
            Node* temp=minValNode(root->right);
            root->id=temp->id;
            root->right=deletion(root->right,key);
        }
    }

    if (root==nullptr)
    {
        return root;
    }
    
    root->height=max(height(root->left),height(root->right))+1;
    int balance=getBalance(root);

    if (balance>1 && getBalance(root->left)>=0)
    {
        return rightRot(root);
    }
    
    if (balance<-1 && getBalance(root->right)<=0)
    {
        return leftRot(root);
    }

    if (balance>1 && getBalance(root->left)<0)
    {
        root->left=leftRot(root->left);
        return rightRot(root);
    }
    
    if (balance<-1 && getBalance(root->right)>0)
    {
        root->right = rightRot(root->right);
        return leftRot(root);
    }

    return root;
}

int main() {
    Node* root = nullptr;
    cout << "inserting:\n";
    root = insert(root,30);
    cout<<"Inserted 30 | Height: "<<height(root)<<" | Rotations:"<<rotations<<" | Balance: "<<getBalance(root)<<endl;
    rotations = "";
    root = insert(root, 20);
    cout << "Inserted 20 | Height: " << height(root) << " | Rotations:" << rotations<< " | Balance: " << getBalance(root) << endl;
    rotations = "";

    root=insert(root, 10);
    cout<<"Inserted 10 | Height: "<<height(root)<< " | Rotations:" << rotations<< " | Balance: " << getBalance(root) << endl;
    rotations = "";

    root = insert(root, 90);
    cout << "Inserted 90 | Height: " << height(root)<< " | Rotations:" << rotations<< " | Balance: " << getBalance(root) << endl;
    rotations = "";
    cout << "deleting:\n";

    root = deletion(root, 20);
    cout<<"Deleted 20 | Height: "<<height(root)<<" | Rotations:"<<rotations<<" | Balance: "<<getBalance(root)<<endl;
    rotations = "";

    root=deletion(root, 10);
    cout<<"Deleted 10 | Height: "<<height(root)<< " | Rotations:"<<rotations<<" | Balance: "<<getBalance(root)<<endl;
    rotations = "";
    return 0;
}
