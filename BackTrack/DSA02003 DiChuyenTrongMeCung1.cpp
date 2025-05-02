#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100][100];
int n;
bool check;
void Try(int i,int j,string s){
    if(i==n && j==n){
        cout << s <<" ";
        check=true;
        return;
    }
    if(i+1 <= n && a[i+1][j]==1){
        s+="D";
        Try(i+1,j,s);
        s.pop_back();
    }
    if(j+1 <= n && a[i][j+1]==1){
        s+="R";
        Try(i,j+1,s);
        s.pop_back();
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                cin >> a[i][j];
            }
        }
        check=false;
        if(a[1][1]==0){
            cout << -1 << endl;
        }
        else{
            Try(1,1,"");
            if(!check){
                cout << -1 << endl;
            }
            else{
                cout << endl;
            }
        }
    }
}