#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;
    Node(string n) {
        name=n;
        left=right=nullptr;
    }
};

int height(Node* root) {
    if(!root) return 0;
    return 1+max(height(root->left), height(root->right));
}

void printLeaves(Node* root) {
    if(!root) return;
    if(root->left==nullptr&&root->right==nullptr){
        cout << root->name << endl;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

void printLevels(Node* root, int level) {
    if(root==nullptr) return;
    cout<<root->name<<" is at level "<<level<<endl;
    printLevels(root->left, level+1);
    printLevels(root->right, level+1);
}

int main(){
    Node* root = new Node("hamza");
    root->left = new Node("mother");
    root->right = new Node("father");

    root->left->left = new Node("grandma");
    root->left->right = new Node("grandpa");

    root->right->left = new Node("grandmother");
    root->right->right = new Node("grandfather");

    cout<<"root:"<<root->name<<endl<<endl;
    cout<<"leaf nodes:\n";
    printLeaves(root);
    cout<<"height of tree: "<<height(root)<<endl<<endl;

    cout<<"level of member:\n";
    printLevels(root, 0);
    return 0;
}
