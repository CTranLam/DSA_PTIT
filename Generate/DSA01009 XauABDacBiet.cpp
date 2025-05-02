#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void init(int a[],int n){
    for(int i=1 ; i<=n ; i++){
        a[i]=0;
    }
}
bool check=false;
void sinh(int a[],int n){
    int i=n;
    while(i >= 1 && a[i]==1){
        a[i]=0;
        --i;
    }
    if(i==0) check=true;
    else a[i]=1;
}
bool solve(int a[],int n,int k){
    int max_cnt=0;
    int cntA=0;
    for(int i=1 ; i<=n ; i++){
        if(a[i]==0){
            ++cntA;
            max_cnt=max(max_cnt,cntA);
        }
        else{
            cntA=0;
        }
    }
    return max_cnt==k;
}
int main(){
    int n,k;
    cin >> n >> k;
    int a[n+5];
    init(a,n);
    vector<string> v;
    while(!check){
        if(solve(a,n,k)){
            string tmp="";
            for(int i=1; i<=n ; i++){
                if(a[i]==0) tmp+="A";
                else tmp+="B";
            }
            v.push_back(tmp);
        }
        sinh(a,n);
    }
    cout << v.size() << endl;
    for(string x : v){
        cout << x <<endl;
    }
}