#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 6005;
int matrix[maxn][maxn];
int preSum[maxn][maxn];
int a,b,c,d,e;
int getSum(int i,int j, int u , int v){
    return preSum[u][v]-preSum[i-1][v]-preSum[u][j-1]+preSum[i-1][j-1];
}
bool check(int s){
    for(int i=1 ; i+s-1 <= a ; i++){
        for(int j=1 ; j+s-1 <= b ; j++){
            if(getSum(i,j,i+s-1,j+s-1) <= e) return true;
        }
    }
    return false;
}
int main(){
    cin >> a >> b >> c >> d >> e;
    for(int i = 0 ; i<c ; i++){
        int ik,jk; cin >> ik >> jk;
        matrix[ik][jk]=1;
    }
    for(int i=1 ; i<=a ; i++){
        for(int j=1 ; j<=b ; j++){
            preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i][j] - preSum[i-1][j-1];
        }
    }
    int l= d, r = min(a,b),maxLenEdge=0;
    while(l <= r){
        int mid = (l+r)/2;
        mid = (mid/d) * d;
        if(check(mid)){
            maxLenEdge = mid;
            l = mid + d;
        }
        else{
            r = mid-d;
        }
    }
    cout << maxLenEdge << endl;
}