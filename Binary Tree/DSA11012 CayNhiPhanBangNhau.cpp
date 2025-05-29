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
bool check(node* root1,node* root2){
    if(root1==NULL && root2==NULL) return true;
    if((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) return false;
    if(root1->data != root2->data) return false;
    return check(root1->left,root2->left)  && check(root1->right,root2->right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n1;
        cin >> n1;
        int u,v;
        char x;
        node* root1=NULL;
        for(int i=0 ; i<n1 ; i++){
            cin >> u >> v >> x;
            if(root1 == NULL){
                root1 = new node(u);
                makeNode(root1,u,v,x);
            }
            else{
                insertNode(root1,u,v,x);
            }
        }
        
        int n2; cin >> n2;
        node* root2=NULL;
        for(int i=0 ; i<n2 ; i++){
            cin >> u >> v >> x;
            if(root2 == NULL){
                root2 = new node(u);
                makeNode(root2,u,v,x);
            }
            else{
                insertNode(root2,u,v,x);
            } 
        }
        if(check(root1,root2)){
            cout << 1 << endl;
        }   
        else cout << 0 << endl;
    }
}