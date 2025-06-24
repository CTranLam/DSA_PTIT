#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5];
bool check;
void Try(int i,int sum){
    if(check) return;
    if(i == 5){
        if(sum==23){
            check=true;
        }
        return;
    }
    Try(i+1,sum+a[i]);
    Try(i+1,sum-a[i]);
    Try(i+1,sum*a[i]);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i=0 ; i<5 ; i++){
            cin >> a[i];
        }
        sort(a,a+5);
        check=false;
        do{
            Try(1,a[0]); // de thoa man trong th nhan
        }while(next_permutation(a,a+5) && !check);
        if(check){
            cout << "YES" <<endl;
        }
        else cout << "NO" << endl;
    }
}