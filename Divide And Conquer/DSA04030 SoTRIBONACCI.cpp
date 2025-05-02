#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
const ll mod = 1000000000000007; 
#define max_n 1001 
#define Quick() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
ll multi(ll a, ll b){ 
    if(b <= 1) return a % mod * b; 
    ll tmp = multi(a, b / 2); 
    if(b % 2 == 0) return tmp % mod + tmp % mod; 
    else return tmp % mod + tmp % mod + a % mod; 
} 
struct Matrix{ 
    ll a[4][4]; 
    friend Matrix operator * (Matrix x, Matrix y){ 
        Matrix res; 
        for(int i = 0; i < 4; i++){ 
            for(int j = 0; j < 4; j++){ 
                res.a[i][j] = 0; 
                for(int k = 0; k < 4; k++){ 
                    res.a[i][j] = res.a[i][j] % mod + multi(x.a[i][k], y.a[k][j]) % mod; 
                    res.a[i][j] %= mod; 
                } 
            } 
        } 
        return res; 
    }; 
}; 
Matrix matrix; 
void init(){ 
    matrix.a[0][0] = matrix.a[0][1] = matrix.a[0][2] = 1; 
    matrix.a[0][3] = 0; 
    matrix.a[1][0] = 1; 
    matrix.a[1][1] = matrix.a[1][2] = matrix.a[1][3] = 0; 
    matrix.a[2][0] = 0; 
    matrix.a[2][1] = 1; 
    matrix.a[2][2] = matrix.a[2][3] = 0; 
    matrix.a[3][0] = matrix.a[3][1] = matrix.a[3][2] = matrix.a[3][3] = 1; 
} 
Matrix binPow(Matrix x, int n){ 
    if(n == 1) return x; 
    Matrix tmp = binPow(x, n / 2); 
    if(n % 2 == 0) return tmp * tmp; 
    else return tmp * tmp * x; 
} 
ll findTribonacciSum(int n){ 
    if(n == 1) return 1; 
    if(n == 2) return 3; 
    if(n == 3) return 6; 
    Matrix res = binPow(matrix, n + 2); 
    ll Tn = res.a[0][2] - 1; 
    return Tn; 
} 
void TestCase(){ 
    int n; 
    cin >> n; init(); 
    cout << findTribonacciSum(n) << endl; 
} 
int main(){ 
    Quick(); 
    int t; cin >> t; 
    while(t--){ 
        TestCase(); 
    } return 0; 
} 