#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check=false;
void init(int a[],int n){
    for(int i=1 ; i<=n ; i++){
        a[i]=0;
    }
}
void sinh(int a[],int n){
    int i=n;
    while(i >= 1 && a[i]==1){
        a[i]=0;
        --i;
    }
    if(i==0) check=true;
    else a[i]=1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;cin >> n>>k;
        int a[n+5];
        init(a,n);
        check=false;
        vector<string> v;
        while(!check){
            string res="";
            int cnt=0;
            for(int i=1 ; i<=n ; i++){
                res+=to_string(a[i]);
                if(a[i]==1) ++cnt;
            }
            if(cnt==k) v.push_back(res);
            sinh(a,n);
        }
        for(string x : v){
            cout << x <<endl;
        }
    }
}