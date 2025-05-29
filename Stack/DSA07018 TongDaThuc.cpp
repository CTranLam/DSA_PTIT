#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(string s1,string s2){
    stringstream ss1(s1);
    stringstream ss2(s2);
    map<int,int> mp1,mp2;
    string t;
    while(ss1 >> t){
        for(char &x : t){
            if(!isdigit(x)){
                x=' ';
            }
        }
        stringstream ss(t);
        string res;
        vector<int> v;
        while(ss >> res){
            v.push_back(stoi(res));
        }
        mp1[v[1]]=v[0];
    }
    while(ss2 >> t){
        for(char &x : t){
            if(!isdigit(x)){
                x=' ';
            }
        }
        stringstream ss(t);
        string res;
        vector<int> v;
        while(ss >> res){
            v.push_back(stoi(res));
        }
        mp2[v[1]]=v[0];
    }
    // cout << mp1.size() <<" "<<mp2.size() << endl;
    map<int,int> mpa;
    for(auto x : mp1){
        int bac=x.first;
        int hs=x.second;
        for(auto p : mp2){
            if(bac==p.first){
                hs+=p.second;
            }
            mpa[bac]=hs;
        }
    }
    for(auto x : mp2){
        if(mpa.count(x.first)==0){
            mpa[x.first]=x.second;
        }
    }
    vector<pair<int,int>> v;
    for(auto x : mpa){
        v.push_back({x.first,x.second});
    }
    reverse(v.begin(),v.end());
    for(int i=0 ; i<v.size(); i++){
        if(i != v.size()-1){
            cout << v[i].second <<"*x^" << v[i].first <<" + ";
        }
        else{
            cout << v[i].second <<"*x^" << v[i].first;
        }
    }
    cout << endl;
}
int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        for(char &x : s1){
            if(x=='+') x=' ';
        }
        for(char &x : s2){
            if(x=='+') x=' ';
        }
        solve(s1,s2);
    }
}