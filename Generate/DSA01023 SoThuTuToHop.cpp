#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check=false;
void init(int a[],int n,int k){
    for(int i=1 ; i<=k ; i++){
        a[i]=i;
    }
}
void sinh(int a[],int n,int k){
    int i=k;
    while(i >= 1 && a[i]==n-k+i){
        --i;
    }
    if(i==0) check=true;
    else{
        a[i]++;
        for(int j=i+1 ; j<=k ; j++){
            a[j]=a[j-1]+1;
        }
    }
}
int main(){
    int t;cin >> t;
    while(t--){
        int n,k;cin >> n>>k;
        int a[n+5];
        string res="";
        for(int i=0 ; i<k ; i++){
            int x;cin >> x;
            res+=to_string(x);
        }
        init(a,n,k);
        int cnt=0;
        check=false;
        while(!check){
            ++cnt;
            string cur="";
            for(int i=1 ; i<=k ; i++){
                cur+=to_string(a[i]);
            }
            if(cur==res){
                cout << cnt << endl;
                break;
            }
            else{
                sinh(a,n,k);
            }
        }
    }
}