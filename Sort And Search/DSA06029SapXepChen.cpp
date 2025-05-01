#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> v;

void sortt (int a[] , int n){ 
    for (int i = 0; i < n; ++i) { 
        int j = i; 
        while (j > 0 && a[j] < a[j - 1]) { 
            swap(a[j], a[j - 1]); 
            j--; 
        } 
        vector<int> tmp;
        for (int j = 0; j <= i; ++j) { 
            tmp.push_back(a[j]); 
        } 
        v.push_back(tmp);
    } 
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    sortt(a,n);
    for(int i=v.size()-1 ; i>=0 ; i--){
        cout << "Buoc " <<i <<": ";
        for(int x : v[i]){
            cout << x <<" ";
        }
        cout << endl;
    }
}