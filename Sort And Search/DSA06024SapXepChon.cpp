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
    for(int i=0 ; i<n-1 ; i++){
        int minPos=i;
        for(int j=i+1 ; j<n ; j++){
            if(a[j] < a[minPos]){
                minPos=j;
            }
        }
        swap(a[minPos],a[i]);
        cout << "Buoc " << i+1 <<": ";
        for(int x : a){
            cout << x <<" ";
        }
        cout << endl;
    }
}