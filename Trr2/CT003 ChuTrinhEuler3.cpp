#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,ul;
int a[105][105];
vector<int> dsk[105],dsk2[105];
int mtk[105][105];
int visited[105];
int degIn[105], degOut[105];
void dfs(int u){
    visited[u]=1;
    for(int v : dsk[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
bool checkConnect(){ // kiem tra lien thong yeu
    dfs(1);
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]) return false;
    }
    return true;
}
vector<int> ans; // luu thu tu nguoc cua chu trinh euler
void Euler(int x){
    while(!dsk2[x].empty()){
        int y=dsk2[x].back();
        dsk2[x].pop_back();
        auto it = find(dsk2[y].begin(),dsk2[y].end(),x);
        if(it != dsk2[y].end()){
            dsk2[y].erase(it);
        }
        Euler(y);
    }
    ans.push_back(x);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> t >> n;
    if(t==2) cin >> ul;
    for(int i=1; i<=n; i++){
        int k;
		cin>>k;
		for(int j=0; j<k; j++){
			int l; cin>>l;
			mtk[i][l]=1;
		}
	}
	for(int i=1; i<=n; i++){
	    for(int j=1; j<=n; j++){
	        if(mtk[i][j]) {
                dsk[i].push_back(j);
                dsk[j].push_back(i);

                dsk2[i].push_back(j); 

                degIn[j]++;
                degOut[i]++;
	        }
	    }
	}
    if(!checkConnect()){
        cout << 0 << endl;
        return 0;
    }
    if(t==1){
        int cnt=0;
        for(int i=1 ; i<=n ; i++){
            int x=abs(degIn[i]-degOut[i]);
            if(x==1) ++cnt;
            if(x > 1){
                cout << 0 << endl;
                return 0;
            }
        }
        if(cnt == 0) cout << 1 << endl;
        else if(cnt==2) cout << 2 << endl;
        else cout << 0 << endl;
    }
    else{
        Euler(ul);
        reverse(ans.begin(),ans.end());
        for(int x : ans){
            cout << x <<" ";
        }
        cout << endl;
        return 0;
    }
}   