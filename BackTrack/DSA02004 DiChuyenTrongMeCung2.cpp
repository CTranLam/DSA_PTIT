#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10][10];
int n;
bool check=false;
void Try(int i,int j,string s){
    if(i==n && j==n){
        check=true;
        cout << s <<" ";
    }
    if(i+1 <=n && a[i+1][j]==1){
        a[i+1][j]=0;
        s+="D";
        Try(i+1,j,s);
        s.pop_back();
        a[i+1][j]=1;
    }
    if(j-1 >=1 && a[i][j-1]==1){
        a[i][j-1]=0;
        s+="L";
        Try(i,j-1,s);
        a[i][j-1]=1;
        s.pop_back();
    }
    if(j+1 <=n && a[i][j+1]==1){
        a[i][j+1]=0;
        s+="R";
        Try(i,j+1,s);
        a[i][j+1]=1;
        s.pop_back();
    }
    if(i-1 >=1 && a[i-1][j]==1){
        a[i-1][j]=0;
        s+="U";
        Try(i-1,j,s);
        a[i-1][j]=1;
        s.pop_back();
    }
}
int main(){
    int t;cin >> t;
    while(t--){
        cin >> n;
        memset(a,0,sizeof(a));
        check=false;
        for(int i=1 ; i<=n ; i++){
            for(int j=1; j<=n ; j++){
                cin >> a[i][j];
            }
        }
        if(a[1][1]==0){
            cout << -1 << endl;
        }
        else{
            a[1][1]=0;
            vector<string> v;
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