#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int x[1005];
vector<string> v;
vector<string> res;
void Try(int i){
    if(i == k+1){
        for(int j=1 ; j<=k ; j++){
            cout << v[x[j]-1] <<" ";
        }
        cout << endl;
    }
    else{
        for(int j=x[i-1]+1 ; j<=n-k+i ; j++){
            x[i]=j;
            Try(i+1);
        }
    }
}
int main(){
    cin >> n >> k;
    set<string> se;
    for(int i=0 ; i<n ; i++){
        string s;
        cin >> s;
        se.insert(s);
    }
    for(string x : se){
        v.push_back(x);
    }
    n=se.size();
    Try(1);
}