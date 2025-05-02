#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    // x-t-d
    int cx=0,ct=0;
    for(char x : s){
        if(x=='X') ++cx;
        else if(x=='T') ++ct;
    }
    int ans=0;
    for(int i=0 ; i<cx ; i++){
        if(s[i]=='T'){
            int j=cx; // uu tien tim xanh gan nhat de sap xep luon T
            // neu chon j < cx thi doi cho vo nghia
            while(s[j] != 'X') ++j;
            swap(s[i],s[j]);
            ++ans;
        }
        else if(s[i]=='D'){
            int j=n-1;// uu tien tim xa nhat ve
            while(s[j] != 'X') --j;
            swap(s[i],s[j]);
            ++ans;
        }
    }
    // chi con T va D sai vi tri
    for(int i=cx ; i<cx + ct ; i++){
        if(s[i] != 'T'){
            int j=cx+ct;
            while(s[j] != 'T'){
                ++j;
            }
            swap(s[j],s[i]);
            ++ans;
        }
    }
    cout << ans << endl;
}