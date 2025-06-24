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
int find(int IN[],int n,int x){
    for(int i=0 ; i<n ; i++){
        if(IN[i] == x) return i;
    }
    return -1;
}
// xay dung cay nhi phan thuc te
void makeNode(node* &root,int IN[],int LE[],int n ){
    int k=find(IN,n,LE[0]); // so luong phan tu ben cay trai
    root=new node(LE[0]);
    int L[10001],R[10001]; // chua cac phan tu thuoc cay con trai va phai
    int l=0,r=0;
    for(int i=1 ; i<n ; i++){
        if(find(IN,n,LE[i]) < k){
            L[l++]=LE[i];
        }
        else R[r++]=LE[i];
    }
    // noi node con vao node cha
    if(l > 0) makeNode(root->left,IN,L,l);
	if(r > 0) makeNode(root->right,IN+k+1,R,r);
}
void Postorder(node* root){
    if(root->left != NULL) Postorder(root->left);
    if(root->right != NULL) Postorder(root->right);
    cout << root->data <<" ";
}
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int IN[n],LE[n];
        for(int i=0 ; i<n ; i++) cin >> IN[i];
        for(int i=0 ; i<n ; i++) cin >> LE[i];
        node* root=NULL;
        makeNode(root,IN,LE,n);
        Postorder(root);
        cout << endl;
    }
}