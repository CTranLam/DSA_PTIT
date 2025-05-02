#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[100];
bool final= false;
void init(int n){
    for(int i=1 ; i<=n ; i++){
        x[i]=0;
    }
}
void sinh(int n){
    int i=n;
    while(i >= 1 && x[i]==1){
        x[i]=0;
        --i;
    }
    if(i==0){
        final=true;
    }
    else x[i]=1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin >> n >> k;
    int a[n+5];
    for(int i=1 ; i<=n ; i++){
        cin >> a[i];
    }
    init(n);
    int cnt=0;
    while(!final){
        vector<int> v;
        int sum=0;
        for(int i=1 ; i<=n ; i++){
            if(x[i]==1){
                sum+=a[i];
                v.push_back(a[i]);
            }
        }
        if(sum==k){
            ++cnt;
            for(int x : v){
                cout << x <<" ";
            }
            cout << endl;
        }
        sinh(n);
    }
    cout << cnt << endl;
}