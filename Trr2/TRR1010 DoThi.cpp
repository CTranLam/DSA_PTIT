
#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, w;  // u: đỉnh đầu, v: đỉnh cuối, w: trọng số
};

int c[105][105];
int main() {
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    int t, n;
    cin >> t >> n;
    for (int i = 1;i<=n; i++) {
        for (int j =1; j <=n; j++){
            cin >> c[i][j];
        }
    }

    if (t == 1) {
        for (int i = 1; i <=n; i++) {
            int degree = 0;
            for (int j =1; j <=n; j++) {
                if (c[i][j] != 10000 && i != j && c[i][j] != 0){
                    degree++;
                }
            }
            cout << degree << " ";
        }
        cout << endl;
    } 
    else if (t == 2) {
        vector<Edge> v;
        for(int i=1 ; i<=n ; i++){
            for(int j=i+1 ; j<=n ; j++){
                if(c[i][j] != 10000 && c[i][j] != 0){
                    v.push_back({i,j,c[i][j]});
                }
            }
        }
        
        cout << n << " " << v.size() << endl;
        for (auto edge : v) {
            cout << edge.u << " " << edge.v << " " << edge.w << endl;
        }
    }

    return 0;
}
