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
void spiral(node* root){
    stack<node* > s1,s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            node* top=s1.top();
            s1.pop();
            cout << top->data <<" ";
            if(top->right != NULL){
                s2.push(top->right);
            }
            if(top->left != NULL){
                s2.push(top->left);
            }
        }
        while(!s2.empty()){
            node* top=s2.top();
            s2.pop();
            cout << top->data <<" ";
            if(top->left != NULL){
                s1.push(top->left);
            }
            if(top->right != NULL){
                s1.push(top->right);
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int u,v; // node cha, node con
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
        spiral(root);
        cout << endl;
    }
}