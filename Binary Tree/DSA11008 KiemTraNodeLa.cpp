#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int data;
    int degree;
    node* left;
    node* right;
    node(int x){
        data=x;
        degree=0;
        left=right=NULL;
    }
};
void makeNode(node* root,int u,int v,char x){
    if(root==NULL) return;
    if(x=='L'){
        root->left = new node(v);
    }
    else root->right=new node(v);
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
vector<node*> res;
void bfs(node* root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    root->degree=0;
    while(!q.empty()){
        node* cur=q.front();
        q.pop();
        if(cur->left != NULL){
            cur->left->degree= cur->degree + 1;
            q.push(cur->left);
        }
        if(cur->right != NULL){
            cur->right->degree = cur->degree + 1;
            q.push(cur->right);
        }
        if(cur->right == NULL && cur->left == NULL){
            res.push_back(cur);
        }
    }
}
bool comp(){
    for(int i=1 ; i<res.size() ; i++){
        if(res[i]->degree != res[i-1]->degree){
            return false;
        }
    }
    return true;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int u,v; // node cha va node con
        char x;
        node* root= NULL;
        for(int i=0 ; i<n ; i++){
            cin >> u >> v >> x;
            if(root == NULL){
                root=new node(u);
                makeNode(root,u,v,x);
            }
            else{
                insertNode(root,u,v,x);
            }
        }
        bfs(root);
        if(comp()) cout << 1 << endl;
        else cout << 0 << endl;
        res.clear();
    }
}