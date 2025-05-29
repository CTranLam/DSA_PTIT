#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{
    int data;
    Node *left;
    Node *right;
};
typedef struct Node *node;
node root = NULL;
Node *MakeNode(int x){
    node n=new Node;
    n->data=x;
    n->left=NULL;
    n->right=NULL;
    return n;
}
int main(){
    node root=MakeNode(50);
    node node40 = MakeNode(40);
    node node60 = MakeNode(60);
    node node30 = MakeNode(30);
    node node20 = MakeNode(20);
    node node65 = MakeNode(65);
    node node70 = MakeNode(70);
    node node25 = MakeNode(25);
    node node15 = MakeNode(15);

    root->left=node40;
    root->right=node60;
    node40->left=node30;
    node40->right=node20;
}