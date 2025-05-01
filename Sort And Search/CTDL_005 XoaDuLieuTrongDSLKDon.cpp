#include <bits/stdc++.h> 
using namespace std; 
int c = 0; 
struct node{ 
    int data; 
    node *next; 
}; 
node *makeNode(int x) { 
    node *newNode = new node(); 
    newNode->data = x; 
    newNode->next = NULL; 
    return newNode; 
} 
void pushBack(node **head, int x) { 
    node *newNode = makeNode(x); 
    node *tmp = *head; 
    if(*head == NULL) { 
        *head = newNode; 
        return; 
    } 
    while(tmp->next != NULL) { 
        tmp = tmp->next; 
    } 
    tmp->next = newNode;
} 
void display(node *head) { 
    while(head != NULL) { 
        cout << head->data << " "; 
        head = head->next; 
    } 
} 
int size(node *head) { 
    int cnt = 0; 
    while(head != NULL) { 
        ++cnt; 
        head = head->next; 
    } 
    return cnt; 
} 
void popFront(node **head) { 
    if(*head == NULL) return; 
    node *tmp = *head; 
    *head = tmp->next; 
    delete tmp; 
} 
void remove(node **head, int pos) {
     int n = size(*head); 
     if(pos < 1 || pos > n) return ; 
     if(pos == 1) popFront(&*head); 
     else { 
        node *tmp = *head; 
        for(int i = 1; i<=pos-2; i++) tmp = tmp->next; 
        node *k = tmp->next; 
        tmp->next = k->next; 
        delete(k); 
    } 
} 
void solve(node **head, int val) { 
    int cnt = 1; 
    node *tmp = *head; 
    while(tmp != NULL) { 
        if(tmp->data == val) { 
            remove(head,cnt); 
            c = 1; return; 
        } 
        ++cnt; 
        tmp = tmp->next; 
    } 
} 
int main() { 
    node *head = NULL; 
    int n,k; cin >> n; 
    for(int i = 1; i<=n; i++) { 
        int x; cin >> x; 
        pushBack(&head,x); 
    } 
    cin >> k; 
    while(1) { 
        c = 0; 
        solve(&head,k); 
        if(c == 0) 
        break; 
    } 
    display(head); 
} /* 6 6 1 6 3 4 6 6 */