#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> buildLPS(string pat){
    int m = pat.size();
    vector<int> lps(m,0);
    int len = 0;
    for(int i = 0 ; i<m ;){
        if(pat[i] == pat[len]){
            lps[i++] = ++len;
        }
        else{
            if(len != 0) len = lps[len-1];
            else lps[i++]=0;
        }
    }
    return lps;
}
void KMP(string txt, string pat){
    int n = txt.size();
    int m = pat.size();
    vector<int> lps = buildLPS(pat);
    int i = 0;
    int j = 0;
    while(i < n){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }
        if(j == m){
            cout << "found at index :" <<i <<" "<<j << endl;
            j = lps[j-1];
        }
        else if(i <n && txt[i] != pat[j]){
            if(j != 0) j=lps[j-1];
            else i++;
        }
    }
}
int main(){
    string text,pattern;
    cin >> text >> pattern;
    KMP(text,pattern);
}