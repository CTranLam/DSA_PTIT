#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void init(int a[],int n){
    for(int i=1 ; i<=n ; i++){
        a[i]=6;
    }
}
bool check=false;
void sinh(int a[],int n){
    int i=n;
    while(i >= 1 && a[i]==8){
        a[i]=6;
        --i;
    }
    if(i==0){
        check=true;
    }
    else{
        a[i]=8;
    }
}
bool solve(string s){
    for(int i=1 ; i<s.size(); i++){
        if(s[i] == s[i-1] && s[i]== '8') return false;
    }
    int cnt6=0;
    for(int i=0 ; i<s.length(); i++){
        if(s[i]=='6'){
            ++cnt6;
            if(cnt6 > 3) return false;
        }
        else{
            cnt6=0;
        }
    }
    return true;
}
int main(){
    int n;cin >> n;
    n-=2;
    int a[n+5];
    init(a,n);
    while(!check){
        string s="8";
        for(int i=1 ; i<=n ; i++){
            s+=to_string(a[i]);
        }
        s+="6";
        if(solve(s)){
            cout << s << endl;
        }
        sinh(a,n);
    }
}