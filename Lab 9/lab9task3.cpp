#include<iostream>
#include<string>
using namespace std;
 
string rotations="";

class Node{
    public:
    Node* left;
    Node* right;
    int id;
    int severity;
    int height;
    Node(int d,int s):id(d),severity(s){
        left=right=nullptr;
        height=0;
    }
};

int height(Node* n){
    if (n==nullptr)
    {
        return 0;
    }
    
    int left_h=height(n->left);
    int right_h=height(n->right);
    if (left_h>right_h)
    {
        return left_h+1;
    }else{
        return right_h+1;
    }
}

int getBalance(Node* node){
    if (node==nullptr)
    {
        return 0;
    }
    return height(node->left)-height(node->right);
}

int max(int a,int b){
    if (a>b)
    {
        return a;
    }else{return b;}
}

Node* rightrot(Node* y){
    Node* x =y->left;
    Node* t2 =x->right;
    
    x->right=y;
    y->left=t2;
    y->height=1+max(height(y->left),height(y->right));
    x->height=1+max(height(x->left),height(x->right));

    return x;
}

Node* leftrot(Node* x){
    Node* y=x->right;
    Node* t2=y->left;

    y->left=x;
    x->right=t2;
    y->height=1+max(height(y->left),height(y->right));
    x->height=1+max(height(x->left),height(x->right));

    return y;
}

Node* insert(Node* root,int id,int pr){
    if (root==nullptr)
    {
        Node* newNode=new Node(id,pr);
        return newNode;
    }
    if (pr<root->severity)
    {
        root->left=insert(root->left,id,pr);
    }else if(pr>root->severity){
        root->right=insert(root->right,id,pr);
    }else{
        return root;
    }
    root->height=1+max(height(root->left),height(root->right));
    int balance=getBalance(root);
    if (balance>1 && pr < root->left->severity){
        rotations+=" RR ";
        return rightrot(root);
    }
    if(balance<-1 && pr > root->right->severity){
        rotations+= " LL ";
        return leftrot(root);   
    }
    if (balance > 1 && pr > root->left->severity) {
        rotations+= " LR ";
        root->left = leftrot(root->left);
        return rightrot(root);
    }
    
    if (balance < -1 && pr < root->right->severity) {
        rotations+= " RL ";
        root->right = rightrot(root->right);
        return leftrot(root);
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

Node* deletion(Node*root,int pr){
    if (root==nullptr)
    {
        return root;
    }
    if (pr<root->severity){
        root->left=deletion(root->left,pr);
    } else if(pr>root->severity){
        root->right=deletion(root->right,pr);
    }else{
        if (root->left==nullptr || root->right==nullptr)
        {
            Node* temp;
            if (root->left==nullptr){
                temp=root->left;
            }else if(root->right==nullptr){
                temp=root->left;
            }

            if(temp==nullptr){
                temp=root;
                root=nullptr;
            }else{
                *temp=*root;
            }
            delete temp;
        } else {
            Node* temp = minValNode(root->right);
            root->severity = temp->severity;
            root->right = deletion(root->right, temp->severity);
        }
    }
    
    if (root == nullptr)
        return root;


    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightrot(root);

        
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftrot(root->left);
        return rightrot(root);
    }

    
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftrot(root);

    
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightrot(root->right);
        return leftrot(root);
    }
    return root;
}
int highestSeverity(Node* root) {
    if (root == nullptr) return -1;
    while (root->right != nullptr)
        root = root->right;
    return root->severity;
}

int main(){
    Node* root=nullptr;
    cout<<"inserting:\n";

    int patients[] = {30, 20, 40, 10, 25, 50, 5};  
    int n = 7;

    for (int i = 0; i < n; i++) {
        int sev = patients[i];
        rotations = "";  
        root = insert(root, i+1, sev);
        cout << "Inserted severity " << sev<< " | Height: " << height(root)<< " | Rotations:" << (rotations == "" ? " None" : rotations)<< " | Highest severity: " << highestSeverity(root)<< endl;
    }

    
    cout << "DISCHARGING PATIENTS \n";

    int discharged[] = {20, 5, 40};  
    int d = 3;

    for (int i = 0; i < d; i++) {
        int sev = discharged[i];
        rotations = "";

        root = deletion(root, sev);

        cout << "Deleted severity " << sev<<" | Height: " << height(root)<<" | Rotations:" << (rotations == "" ? " None" : rotations)<<" | Highest severity: " << highestSeverity(root)<<endl;
    }

    return 0;
}