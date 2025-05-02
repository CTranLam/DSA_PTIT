#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s1,s2;
        cin >> s1 >> s2;
        int n=s1.size(),m=s2.size();
        s1="@"+s1;
        s2="@"+s2;
        int f[n+1][m+1]; // luu do dai day con dai nhat chua i phan tu s1,j phan tu s2
        for(int i=0 ; i<=n ; i++){
            for(int j=0 ; j<=m ; j++){
                if(i==0 || j==0) f[i][j]=0;
                else{
                    if(s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1;// gia tang do dai
                    else{
                        f[i][j]=max(f[i-1][j],f[i][j-1]);
                    }
                }
            }
        }
        cout << f[n][m] << endl;
    }
}