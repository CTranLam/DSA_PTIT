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

void strInorder(node* root,vector<int>& v_num,vector<node*>& v_node){
    if(root==NULL) return;
    strInorder(root->left,v_num,v_node);
    v_num.push_back(root->data);
    v_node.push_back(root);
    strInorder(root->right,v_num,v_node);
}

void Inorder(node* root){
    if(root==NULL) return;
    Inorder(root->left);
    cout << root->data <<" ";
    Inorder(root->right);
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
        vector<int> v_num;
        vector<node*> v_node;
        strInorder(root,v_num,v_node);

        sort(v_num.begin(),v_num.end());
        for(int i=0 ; i<v_node.size() ; i++){
            v_node[i]->data = v_num[i];
        }
        Inorder(root);
        cout << endl;
    }
}