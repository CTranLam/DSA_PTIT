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
node* insertNode(int a[], int l,int r){
    if(l > r) return NULL;
    // chia doi mang de chon node goc giup cay luon can bang
    int m=(l+r)/2;
    node* root=new node(a[m]);
    root->left = insertNode(a,l,m-1);
    root->right = insertNode(a,m+1,r);
    return root;
}
void Preorder(node* root){
    if(root == NULL) return;
    cout << root->data <<" ";
    Preorder(root->left);
    Preorder(root->right);
}
int main(){
    int t; cin >>  t;
    while(t--){
        int n; cin >> n;
        int a[n],b[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        node* root = insertNode(a,0,n-1);
        Preorder(root);
        cout << endl;
    }
}