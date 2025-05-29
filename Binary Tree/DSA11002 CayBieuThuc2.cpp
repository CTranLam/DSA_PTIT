#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    string data;
    node* left;
    node* right;
    node(string x){
        data=x;
        left=right=NULL;
    }
};
//cay nhi phan day du bieu dien theo muc
node* makeNode(vector<string> v,int i,int n){
    if(i >= n) return NULL;
    node* root=new node(v[i]);
    root->left=makeNode(v,2*i + 1,n);
    root->right=makeNode(v,2*i + 2,n);
    return root; 
}
int solve(node* root){
    if(root->left==NULL && root->right==NULL){ // la node la
        return stoi(root->data);
    }
    else{
        int left_val=solve(root->left);
        int right_val=solve(root->right);
        if(root->data == "+") return left_val+right_val;
        else if(root->data == "-") return left_val-right_val;
        else if(root->data == "*") return left_val*right_val;
        else return left_val/right_val;
    }
    return 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> v(n);
        for(int i=0 ; i<n ; i++){
            cin >> v[i];
        }
        node* root=makeNode(v,0,n);
        cout << solve(root) << endl;
    }
}