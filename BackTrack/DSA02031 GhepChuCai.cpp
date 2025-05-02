#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
int used[100];
int F['Z'];
bool check(string s){
    for(int i=1 ; i<s.size()-1 ; i++){
       if(F[s[i]]==1 && F[s[i-1]]==0 && F[s[i+1]]==0){
        return false;
       }
    }
    return true;
}
void Try(vector<int> v){
    if(v.size()==(c-'A')+1){
        string s="";
        for(int x : v){
            s+=('A'+x);
        }
        if(check(s)){
            cout << s << endl;
        }
        return;
    }
    for(int j=0 ; j<=c-'A' ; j++){
        if(!used[j]){
            used[j]=1;
            v.push_back(j);
            Try(v);
            v.pop_back();
            used[j]=0;
        }
    }
}
int main(){
    cin >> c;
    vector<int> v;  
    F['A']=1;
    F['E']=1;
    Try(v);
}