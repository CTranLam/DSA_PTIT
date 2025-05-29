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
void bfs(node* root,bool& check,vector<node*>& v){
    queue<node*> q;
    q.push(root);
    root->degree=0;
    while(!q.empty()){
        node* cur=q.front();
        q.pop();
        if(cur->left != NULL){
            cur->left->degree = cur->degree +1;
            q.push(cur->left);
        }
        if(cur->right != NULL){
            cur->right->degree = cur->degree + 1;
            q.push(cur->right);
        }
        if((cur->left==NULL && cur->right != NULL) ||(cur->left != NULL && cur->right==NULL)){
            check=false;
        }
        if((cur->left==NULL && cur->right == NULL)){
            v.push_back(cur);
        }
    }
}
bool check_valid(vector<node*> v){
    for(int i=1 ; i<v.size() ; i++){
        if(v[i]->degree != v[i-1]->degree) return false;
    }
    return true;
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
        vector<node*> res;
        bool check=true;
        bfs(root,check,res);
        if(!check || !check_valid(res)){
            cout << "No" << endl;
        }
        else cout << "Yes" << endl;
    }
}