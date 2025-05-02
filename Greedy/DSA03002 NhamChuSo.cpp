#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
int min_sum(){
    for(char &x : a){
        if(x=='6') x='5';
    }
    for(char &x : b){
        if(x=='6') x='5';
    }
    return stoi(a)+stoi(b);
}
int max_sum(){
    for(char &x : a){
        if(x=='5') x='6';
    }
    for(char &x : b){
        if(x=='5') x='6';
    }
    return stoi(a)+stoi(b);
}
int main(){
    cin >> a >> b;
    cout << min_sum() <<" "<<max_sum() << endl;
}