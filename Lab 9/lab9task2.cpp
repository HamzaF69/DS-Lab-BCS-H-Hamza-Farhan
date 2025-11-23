#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    int price;
    Node(int p):price(p){
        left=right=nullptr;
    }
};

int height(Node* n){
    if (n==nullptr)
    {
        return 0;
    }else{
        int left_h=height(n->left);
        int right_h=height(n->right);
        if (left_h>right_h)
        {
            return left_h+1;
        }else{
            return right_h+1;
        }
    }
}

int getBalance(Node* node){
    if (node==nullptr)
    {
        return 0;
    }
    return height(node->left)-height(node->right);
    
}

Node* rightRot(Node* y){
    Node *x =y->left;
    Node *t2 =x->right;

    x->right=y;
    y->left=t2;
    return x;
}

Node* leftRot(Node* x){
    Node* y=x->right;
    Node* t2=y->left;
    y->left=x;
    x->right=t2;
    return y;
}

Node* insert(Node* root,int price){
    if (root==nullptr){
        Node* newNode=new Node(price);
        return newNode;
    }

    if (price<root->price)
    {
        root->left=insert(root->left,price);
    }else if(price>root->price) {
        root->right=insert(root->right,price);
    }else{
        return root;
    }

    int balance=getBalance(root);
    if (balance>1 && price<root->left->price)
    {
        return rightRot(root); 
    }
    if (balance<-1 && price > root->right->price)
    {
        return leftRot(root); 
    }
    if (balance>1 && price>root->left->price)
    {
        root->left=leftRot(root->left);
        return rightRot(root); 
    }
    if (balance < -1 && price<root->right->price)
    {
        root->right=rightRot(root);
        return leftRot(root); 
    }
    return root;
}

void inorder(Node* root,int x, int y){
    if (root==nullptr)
    {
        return;
    }
    if (root->price > x){
        inorder(root->left, x, y);
    }

    if (root->price >= x && root->price <= y){
        cout << root->price << " ";
    }
    if (root->price < y){
        inorder(root->right, x, y);
    }
}
int main(){
    Node* root=nullptr;
    root=insert(root,1200);
    root=insert(root,450);
    root=insert(root,999);
    root=insert(root,1750);
    root=insert(root,600);
    root=insert(root,3000);
    root=insert(root,1500);

    int x=500,y=1800;
    cout<<"Prices between "<<x <<" and "<<y<<":\n";
    inorder(root,x,y);
    return 0;
}