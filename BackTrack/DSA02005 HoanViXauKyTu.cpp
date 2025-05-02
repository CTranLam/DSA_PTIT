#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[100];
int used[100];
string s;
int n;
void Try(int i){
    if(i==n+1){
        string res="";
        for(int i=1 ; i<=n ; i++){
            res+=s[x[i]-1];
        }
        cout <<res <<" ";
    }
    for(int j=1 ; j<=n ; j++){
        if(!used[j]){
            x[i]=j;
            used[j]=1;
            Try(i+1);
            used[j]=0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        n=s.length();
        Try(1);
        cout << endl;
    }
}