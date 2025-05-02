#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt=0;
void merge(ll a[],int l,int m,int r){
    vector<int> vx(a+l,a+m+1);
    vector<int> vy(a+m+1,a+r+1);
    int i=0,j=0;
    while(i < vx.size() && j<vy.size()){
        if(vx[i] <= vy[j]){
            a[l]=vx[i];
            ++i;
            ++l;
        }
        else{
            cnt+=vx.size()-i;
            a[l]=vy[j];
            ++j;
            ++l;
        }
    }
    while(i < vx.size()){
        a[l]=vx[i];
        ++i;++l;
    }
    while(j < vy.size()){
        a[l]=vy[j];
        ++j;++l;
    }
}
void merge_sort(ll a[],int l,int r){
    if(l >= r){
        return;
    }
    int m=(l+r)/2;
    merge_sort(a,l,m);
    merge_sort(a,m+1,r);
    merge(a,l,m,r);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cnt=0;
        int n;cin >> n;
        ll a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        merge_sort(a,0,n-1);
        cout << cnt << endl;
    }
}