#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 20;
const int INF = -1e9;

int n, a[MAX_N][MAX_N];
int dp[1 << MAX_N]; // DP trạng thái bitmask

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        // Khởi tạo DP
        fill(dp, dp + (1 << n), INF);
        dp[0] = 0; // Trạng thái ban đầu: chưa chọn cột nào, tổng = 0

        // Duyệt qua tất cả các trạng thái mask
        for (int mask = 0; mask < (1 << n); mask++) {
            int row = __builtin_popcount(mask); // Đếm số hàng đã chọn

            if (row >= n) continue; // Nếu đã chọn đủ hàng thì bỏ qua
            
            for (int col = 0; col < n; col++) {
                if (!(mask & (1 << col))) { // Nếu cột này chưa được chọn
                    int new_mask = mask | (1 << col);
                    dp[new_mask] = max(dp[new_mask], dp[mask] + a[row][col]);
                }
            }
        }

        cout << dp[(1 << n) - 1] << endl; // Kết quả khi đã chọn hết N hàng, N cột
    }

    return 0;
}
