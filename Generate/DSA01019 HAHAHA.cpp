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
bool solve(string res){
    for(int i=1 ; i<res.length() ; i++){
        if(res[i]=='H' && res[i]==res[i-1]){
            return false;
        }
    }
    return res[res.length()-1] != 'H';
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;cin >> n;
        n--;
        int a[n+5];
        init(a,n);
        check=false;
        while(!check){
            string res="H";
            for(int i=1 ; i<=n ; i++){
                if(a[i]==0){
                    res+="A";
                }
                else{
                    res+="H";
                }
            }
            if(solve(res)) cout << res << endl;

            sinh(a,n);
        }
    }
}