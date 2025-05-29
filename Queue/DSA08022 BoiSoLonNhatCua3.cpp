// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// string comp(string s,string t){
//     if(s.length() > t.length()) return s;
//     else if(s.length() < t.length()) return t;
//     else if(s > t) return s;
//     else return t;
// }
// string solve(int a[],int n){
//     queue<pair<string,int>> q;
//     string ans="";
//     set<string> se;
//     q.push({to_string(a[0]),a[0]%3});
//     while(!q.empty()){
//         string s=q.front().first;
//         int mod=q.front().second;
//         q.pop();
//         if(mod==0){
//             ans=comp(ans,s);
//         }
//         for(int i=1 ; i<n ; i++){
//             string t=to_string(a[i]);
//             s+=t;
//             if(!se.count(s)){
//                 se.insert(s);
//                 q.push({s,(mod+a[i])%3});
//             }
//         }
//     }
//     if(ans=="") return "-1";
//     else return ans;
// }
// int main(){
//     int t; cin >> t;
//     while(t--){
//         int n; cin >> n;
//         int a[n];
//         for(int i=0 ; i<n ; i++){
//             cin >> a[i];
//         }
//         sort(a,a+n,greater<int>());
//         cout << solve(a,n) << endl;
//     }
// }