#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int data;
    node* left;
    node* right;
    int degree;
    node(int x){
        data=x;
        degree=0;
        left=right=NULL;
    }
};
void makeNode(node* root,int u,int v,char x){
    if(root==NULL) return;
    if(x=='L'){
        root->left=new node(v);
    }
    else{
        root->right=new node(v);
    }
}
void insertNode(node* root,int u,int v,char x){
    if(root==NULL) return;
    if(root->data == u){
        makeNode(root,u,v,x);
    }
    else{
        insertNode(root->left,u,v,x);
        insertNode(root->right,u,v,x);
    }
}

bool check(node* root){
    if(root== NULL) return true;
    if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right==NULL)){
        return false;
    }
    return check(root->left) && check(root->right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int u,v;
        char x;
        node* root=NULL;
        for(int i=0 ; i<n ; i++){
            cin >> u >> v >> x;
            if(root==NULL){
                root=new node(u);
                makeNode(root,u,v,x);
            }
            else{
                insertNode(root,u,v,x);
            }
        }
        if(check(root)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}