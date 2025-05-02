#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void solveHN(int i,char a,char b,char c){
    if(i==1){
        cout << a <<" -> " <<c << endl;
        return;
    }
        solveHN(i-1,a,c,b);// chuyen n-1 dia tu A sang B
        cout << a <<" -> " << c << endl;// chuyen dia to nhat sang C
        solveHN(i-1,b,a,c);// chuyen n-1 dia tu B sang C
}
int main(){
    cin >> n;
    solveHN(n,'A','B','C');
}