#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    vector<vector<int>> v;
    for(int i=0 ; i<n-1 ; i++){
        int minPos=i;
        for(int j=i+1 ; j<n ; j++){
            if(a[j] < a[minPos]){
                minPos=j;
            }
        }
        swap(a[minPos],a[i]);
        vector<int> tmp;
        for(int x : a){
            tmp.push_back(x);
        }
        v.push_back(tmp);
    }
    for(int i=v.size()-1 ; i>=0 ; i--){
        cout << "Buoc " <<i+1 <<": ";
        for(int x : v[i]){
            cout << x <<" ";
        }
        cout << endl;
    }
}