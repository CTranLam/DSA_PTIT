#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1001][1001];
int main(){
    int n;
    cin >> n;
    cin.ignore();
    for(int i=1 ; i<=n ; i++){
        string s;
        getline(cin,s);
        string tmp;
        stringstream ss(s);
        while(ss >> tmp){
            a[i][stoi(tmp)]=1;
            a[stoi(tmp)][i]=1;
        }
    }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }
}