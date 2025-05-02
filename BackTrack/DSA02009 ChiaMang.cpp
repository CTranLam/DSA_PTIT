#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,cnt;
int a[100];
int tar;
int used[100];
bool check;
void Try(int i,int sum){
    if(sum==tar){
        ++cnt;
        if(cnt==k){
            check=true;
            return;
        }
        return;
    }
    if(sum > tar || check) return;
    for(int j=i ; j<n ; j++){
        if(!used[j]){
            used[j]=1;
            sum+=a[j];
            Try(j+1,sum);
            sum-=a[j];
            used[j]=0;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int sum=0;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            sum+=a[i];
        }
        sort(a,a+n,greater<int>());
        if(sum%k !=0){
            cout << 0 << endl;
        }
        else{
            tar=sum/k;
            memset(used,0,sizeof(used));
            cnt=0;
            check=false;
            Try(0,0);
            if(check) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}