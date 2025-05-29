#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int data;
    node* left;
    node* right;
    int depth;
    node(int x){
        data=x;
        depth=0;
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
int max_depth;
void bfs(node* root){
    queue<node*> q;
    q.push(root);
    root->depth=0;
    while(!q.empty()){
        node* tmp=q.front();
        q.pop();
        max_depth=max(max_depth,tmp->depth);
        if(tmp->left != NULL){
            tmp->left->depth = tmp->depth + 1;
            q.push(tmp->left);
        }
        if(tmp->right != NULL){
            tmp->right->depth = tmp->depth + 1;
            q.push(tmp->right);
        }
    }
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
        max_depth=0;
        bfs(root);
        cout<< max_depth << endl;
    }
}