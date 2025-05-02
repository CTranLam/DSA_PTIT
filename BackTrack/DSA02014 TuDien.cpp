#include <bits/stdc++.h> 
using namespace std; 
int m ,n , k; 
char a[4][4]; 
int f[4][4]; 
string s = ""; 
set<string> se; 
vector<string> ans; 
bool flag; 
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}; 
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; 
void Try(int i, int j){ 
    s += a[i][j]; 
    if(se.find(s) != se.end()){ 
        ans.push_back(s); 
        flag = true; 
    } 
 
    for(int k = 0; k < 8; k++){ 
        int i1 = i + dx[k]; 
        int j1 = j + dy[k]; 
        if(i1 >= 1 && i1 <= m && j1 >= 1 && j1 <= n && f[i1][j1]){ 
            f[i1][j1] = 0; 
            Try(i1, j1); 
            f[i1][j1] = 1; 
            } 
        } 
        s.pop_back(); 
    } 
    int main(){ 
        int t; cin >> t; 
        while(t--){ 
            se.clear(); 
            ans.clear(); 
            flag = false; 
            cin >> k >> m >> n; 
            for(int i = 0; i < k; i++){ 
                string w; cin >> w; 
                se.insert(w); 
            } 
            for(int i = 1; i <= m; i++){ 
                for(int j = 1; j <= n; j++){ 
                    cin >> a[i][j]; 
                } 
            } 
            memset(f, 1, sizeof(f)); 
            for(int i = 1; i <= m; i++){ 
                for(int j = 1; j <= n; j++){ 
                    Try(i, j); 
                } 
            } 
            if(!flag) cout << -1; 
            else{ 
                for(auto it : ans) 
                cout << it << " "; 
            } 
            cout << endl; 
        } 
    }