#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[20];
void Try(vector<int>& v){
    cout <<"[";
    for(int i=0 ; i<v.size()-1; i++){
        cout << v[i] <<" ";
    }
    cout << v.back() <<"]"<< endl;
    if(v.size()==1) return;
    else{
        vector<int> tmp;
        for(int i=1 ; i<v.size(); i++){
            tmp.push_back(v[i]+v[i-1]);
        }
        Try(tmp);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            v.push_back(a[i]);
        }
        Try(v);
    }
}