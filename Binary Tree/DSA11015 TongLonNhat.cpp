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

int res=INT_MIN;
int sumLeaf(node* root){
    if(root==NULL) return 0;
    int sumLeft=sumLeaf(root->left);
    int sumRight=sumLeaf(root->right);
    if(root->left == NULL && root->right== NULL){
        return root->data;
    }
    if(root->left == NULL){ // neu node chi co node con phai
        return sumRight + root->data;
    }
    if(root->right == NULL){ // neu node chi co node con trai
        return sumLeft + root->data;
    }
    if(root -> left && root->right){ // neu node co ca 2 node con
        res=max(res,sumLeft + sumRight + root->data);
        return max(sumLeft,sumRight) + root->data;
    }
    return -1;
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
        res=INT_MIN;
        sumLeaf(root);
        cout << res << endl;
    }
}