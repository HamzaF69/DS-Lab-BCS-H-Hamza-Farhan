#include<iostream>
#include<string>
using namespace std;
 
class Node{
    public:
    Node* left;
    Node* right;
    int count;
    string name;
    Node(string n):name(n){
        left=right=nullptr;
        count=0;
    }
    void play(){
        count++;
    }
};

Node* insert(Node* root,Node* node){
    if (root==nullptr){
        return node;
    }
    if (node->count < root->count)
    {
        root->left=insert(root->left,node);
    }else if(node->count > root->count){
        root->right=insert(root->right,node);
    }
    return root;
}

Node* search(Node* root, string data){
    if (root==nullptr||root->name==data)
    {
        return root;
    }
    Node* leftResult = search(root->left, data);
    if(leftResult != nullptr){
        return leftResult;
    }
    return search(root->right,data);
}

void inorder(Node* root){
    if (root==nullptr)
    {
        return;
    }
    inorder(root->left);
    cout<<root->name<<"\n";
    inorder(root->right);
}
void postOrder(Node* root){
    if (root==nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->name<<"\n";
}

Node* findMin(Node* root){
    while(root->left!=nullptr){
        root=root->left;
    }
    return root;
}

Node* deleteN(Node* root, int count){
    if (root==nullptr)
    {
        return root;
    }
    if (count < root->count)
    {
        root->left=deleteN(root->left,count);
    } else if (count > root->count)
    {
        root->right=deleteN(root->right,count);
    } else{
        if (root->left== nullptr)
        {
            Node* temp =root->right;
            free(root);
            return temp;
        } else if (root->right==nullptr){
            Node* temp =root->left;
            free(root);
            return temp;
        }
        Node* temp=findMin(root->right);
        root->count=temp->count;
        root->right=deleteN(root->right, temp->count);
    }
    return root;
    
    
}

int main() {
    Node* root = new Node("let down");
    Node* n1 = new Node("no.1 party anthem");
    Node* n2 = new Node("faasle");
    Node* n3 = new Node("die for you");
    Node* n4 = new Node("fake plastic trees");

    for (int i = 0; i < 8; i++){
        root->play();
    }
    for (int i = 0; i < 6; i++){
        n1->play();
    }
    for (int i = 0; i < 5; i++){
        n4->play();
    }
    for (int i = 0; i < 2; i++){
        n2->play();
    }
    
    for (int i = 0; i < 4; i++){
        n3->play();
    }
    
    root=insert(root,n1);
    root=insert(root,n2);
    root=insert(root,n3);
    root=insert(root,n4);
    search(root,"let down");
    cout<<"inorder:\n";
    inorder(root);
    cout<<"postorder:\n";
    postOrder(root);
    deleteN(root,2);
    cout<<"after deleting:\n";
    postOrder(root);
    return 0;
}
