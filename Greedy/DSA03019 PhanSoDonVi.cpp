#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll p,q;
        cin >> p >> q;
        // chia ca tu va mau cho p de tu bang 1
        while(q%p != 0){
            int newq=(q/p)+1; // tham lam nen day la so lon nhat
            cout << "1/" << newq <<" + ";
            p=p*newq-q;
            q=q*newq;
        }
        cout << "1/" <<q/p << endl;
    }
}