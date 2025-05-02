#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string min_digit(int n,int s){
    s--;
    n--;
    string res="";
    while(n--){
        if(s >= 9){
            res="9"+res;
            s-=9;
        }
        else{
            res=to_string(s)+res;
            s=0;
        }
    }
    s+=1;
    res=to_string(s)+res;
    return res;
}
string max_digit(int n,int s){
    string res="";
    while(n--){
        if(s >= 9){
            res=res+"9";
            s-=9;
        }
        else{
            res=res+to_string(s);
            s=0;
        }
    }
    return res;
}
int main(){
    int n,s;
    cin >> n >> s;
    if((s==0&& n >0) || (n*9 < s)){
        cout << -1 <<" "<<-1 << endl;
    }
    else{
        cout << min_digit(n,s) <<" "<<max_digit(n,s) << endl;
    }
}