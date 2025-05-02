#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int k;
string s;
string ans;
void Try(int pos,int cnt){
    ans=max(ans,s); // so lon nhat sau khi thuc hien k lan chuyen
    if(cnt==k) return;
    for(int i=pos; i<s.length() ; i++){
        for(int j=i+1 ; j<s.length(); j++){
            if(s[j] > s[i]){
                swap(s[i],s[j]);
                Try(i+1,cnt+1);
                swap(s[i],s[j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> k;
        cin >> s;
        if(k==0){
            cout << s << endl;
        }
        else{
            ans="";
            Try(0,0);
            cout << ans << endl;
        } 
    }
}