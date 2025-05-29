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
node* insertNode(node* root,int key){
    if(root==NULL) return new node(key);
    if(key < root->data) {
        root->left=insertNode(root->left,key);
    }
    else if(key > root->data){
        root->right=insertNode(root->right,key);
    }
    return root;
}
void Duyet(node* root){
    if(root==NULL) return;
    if(root->left == NULL && root->right==NULL){
        cout << root->data <<" ";
    }
    Duyet(root->left);
    Duyet(root->right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for(int i=0; i<n ; i++){
            cin >>  a[i];
        }
        node* root= new node(a[0]); //Goc
        for(int i=1 ; i<n ; i++){
            root=insertNode(root,a[i]);
        }
        Duyet(root);
        cout << endl;
    }
}