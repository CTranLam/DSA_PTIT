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
void addNode(int n, node*& root){
    map<int,node* > mp;
    for(int i=0 ; i<n ; i++){
        int u,v; char c;
        cin >> u >> v >> c;
        if(mp.find(u)==mp.end()){
            root= new node(u);
            mp[u] = root;
        }
        node* parent = mp[u];
        node* child= new node(v);

        if(c=='L') parent->left=child;
        else parent->right=child;
        mp[v]=child;
    }
}
bool isLeaf(node* root){
    return root && !root->left && !root->right;
}
int sumRight(node * root){
    if(!root) return 0;
    int res=0;
    if(isLeaf(root->right)){
        res+=root->right->data;
    }
    return res + sumRight(root->left) + sumRight(root->right);
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int u,v;
        char x;
        node* root=NULL;
        addNode(n,root);
        cout << sumRight(root) << endl;
    }
}