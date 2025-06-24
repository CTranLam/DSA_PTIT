#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    char data;
    node* left;
    node* right;
    node(char x){
        data=x;
        left=NULL;
        right=NULL;
    }
};
void inorder(node* root){
    if(root == NULL) return;
    else{
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s; cin >> s;
        stack<node*> st;
        for(char c : s){
            if(isalpha(c)){
                st.push(new node(c));
            }
            else{
                node* tmp=new node(c);
                tmp->right=st.top();
                st.pop();
                tmp->left=st.top();
                st.pop();
                st.push(tmp);
            }
        }
        inorder(st.top());
        cout << endl;
    }
}