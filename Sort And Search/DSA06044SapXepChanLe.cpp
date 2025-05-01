#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;cin >> n;
    int a[n];
    vector<int> chan,le;
    for(int i=0 ; i<n ;i++){
        cin >> a[i];
        if(i%2==0) chan.push_back(a[i]);
        else le.push_back(a[i]);
    }
    sort(chan.begin(),chan.end());
    sort(le.begin(),le.end(),greater<int>());
    int i=0,j=0;
    for(int k=0 ; k<n ; k++){
        if(k%2==0){
            a[k]=chan[i];
            ++i;
        }
        else{
            a[k]=le[j];
            ++j;
        }
    }
    for(int x : a){
        cout << x <<" ";
    }
}