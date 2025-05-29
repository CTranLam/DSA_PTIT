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
node* insertNode(node* root,int key){
    if(root==NULL) return new node(key); 
    if(key < root->data){
        root->left= insertNode(root->left,key);
    }
    if(key > root->data){
        root->right= insertNode(root->right,key);
    }
    return root;
}
void Duyet(node* root,int& cnt){
    if(root==NULL) return;
    if(root->left != NULL || root->right != NULL){
        ++cnt;
    }
    Duyet(root->left,cnt);
    Duyet(root->right,cnt);
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        node* root= new node(a[0]);
        for(int i=1 ; i<n ; i++){
            root=insertNode(root,a[i]);
        }
        int cnt=0;
        Duyet(root,cnt);
        cout<< cnt << endl;
    }
}