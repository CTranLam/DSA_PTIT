#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int data;
    node* left;
    node* right;
    node(int x){
        data=x;
        left=right=NULL;
    }
};
node* insertNode(node* root, int key){
    if(root==NULL) return new node(key);
    if(root->data > key){
        root->left = insertNode(root->left,key);
    }
    if(root->data < key){
        root->right = insertNode(root->right,key);
    }
    return root;
}
void Preorder(node* root){
    if(root == NULL) return;
    cout << root->data <<" ";
    Preorder(root->left);
    Preorder(root->right);
}
int main(){
    int t; cin >>  t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        node* root=new node(a[0]);
        for(int i=1 ; i<n ; i++){
            root=insertNode(root,a[i]);
        }
        Preorder(root);
        cout << endl;
    }
}