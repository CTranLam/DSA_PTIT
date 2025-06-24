#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    cin.ignore();
    vector<pair<int,int>> dsc;
    for(int i=1 ; i<=n ; i++){
        string s;
        getline(cin,s);
        string tmp;
        stringstream ss(s);
        while(ss >> tmp){
            if(i<stoi(tmp)){
                //dsc chi lay dai dien i<j thoi
                dsc.push_back({i,stoi(tmp)});
            }
        }
    }
    for(auto x : dsc){
        cout << x.first <<" "<<x.second<< endl;
    }
}