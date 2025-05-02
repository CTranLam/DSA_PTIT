#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
vector<string> v;
void Try(int i,string tmp){
    if(tmp != "" && tmp.length() <= s.length()){
        v.push_back(tmp);
    }
    for(int j=i ; j<s.length() ; j++){
        tmp+=s[j];
        Try(j+1,tmp);
        tmp.pop_back();
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n >> s;
        Try(0,"");
        for(string x : v){
            cout << x <<" ";
        }
        cout << endl;
        v.clear();
    }
}