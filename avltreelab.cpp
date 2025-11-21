#include<iostream>
#include<algorithm>
using namespace std;
struct node{
int height;
int data;
node*left;
node*right;
node(int v,int h){
height=h;
data=v;
left=right=nullptr;
}};
//Calculation of height of node
int height(node*n){
    if(n==nullptr){return 0;}
return(n->height);}

//Function for balancing after new addition of nodes
int Balancefact(node* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}
//Function for creating a new node
node * newnode(int val){
node*newn=new node(val,1);
return newn;
}
// Function to get maximum value of two integers
int max(int v1, int v2) {
    return (v1 > v2) ? v1 : v2;
}
// Update the height of a node
void updateHeight(node* Node) {
    if (Node != nullptr)
        Node->height = 1 + max(height(Node->left), height(Node->right));
}

//Left rotate function
node* leftrotate(node*n){
node*x=n->right;
node*t2=x->left;
x->left=n;
n->right=t2;
 // Update heights
    updateHeight(n);
    updateHeight(x);
    return x;
}

node* rightrotate(node* n){
 node* x = n->left;
node* T2 = x->right;
    // Performing rotation
    x->right = n;
    n->left = T2;
    // Update heights
    updateHeight(n);
    updateHeight(x);
    // Returning the new root
    return x;}
    
// Insert a node in AVL tree
node* insertAVL(node* root, int key) {
    // 1. Perform normal BST insertion
    if (root == nullptr)
        return newnode(key);

    if (key < root->data)
        root->left = insertAVL(root->left, key);
    else if (key > root->data)
        root->right = insertAVL(root->right, key);
    else
        return root; // Equal keys not allowed in BST

    // 2. Update height of this ancestor node
    updateHeight(root);


    // 3. Get the balance factor
    int balance = Balancefact(root);

    // 4. Balance the node if unbalanced

    // Case 1 - Left Left
    if (balance > 1 && key < root->left->data)
        return rightrotate(root);

    // Case 2 - Right Right
    if (balance < -1 && key > root->right->data)
        return leftrotate(root);

    // Case 3 - Left Right
    if (balance > 1 && key > root->left->data) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    // Case 4 - Right Left
    if (balance < -1 && key < root->right->data) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    // Return the (unchanged) node pointer
    return root;
}
void preorder(node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
node *root=nullptr;
int fixarr[]={5,2,2,4,5,5};
int n=6;
for (int i =0;i<n;i++){
root=insertAVL(root,fixarr[i]);}
cout<<"Preorder \n";
preorder(root);
//The equal numbers in the code are ignored because repeating values are not allowed
}