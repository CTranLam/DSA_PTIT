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
    if(x=='L'){
        root->left=new node(v);
    }
    else{
        root->right=new node(v);
    }
}
void insertNode(node* root,int u,int v,char x){
    if(root==NULL) return;
    if(root->data == u){ // tim thay node cha
        makeNode(root,u,v,x);
    }
    else{
        insertNode(root->left,u,v,x);
        insertNode(root->right,u,v,x);
    }
}
void Level_Order(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tmp=q.front();
        q.pop();
        cout << tmp->data <<" ";
        if(tmp->left != NULL){
            q.push(tmp->left);
        }
        if(tmp->right != NULL){
            q.push(tmp->right);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int u,v; // u node cha, v la node con
        char x; // xac dinh v la node con trai hay phai
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
        Level_Order(root);
        cout << endl;
    }
}