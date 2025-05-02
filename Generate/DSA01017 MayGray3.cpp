#include <bits/stdc++.h>
using namespace std;

// Hàm chuyển mã nhị phân thành mã Gray
string binaryToGray(string binary) {
    int n = binary.length();
    string gray = "";  

    // Bit đầu tiên của mã Gray giống hệt bit đầu tiên của nhị phân
    gray += binary[0];

    // Các bit còn lại: G[i] = B[i] ⊕ B[i-1]
    for (int i = 1; i < n; i++) {
        char bit = (binary[i] - '0') ^ (binary[i - 1] - '0') + '0';
        gray += bit;
    }

    return gray;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        string binary;
        cin >> binary;
        cout << binaryToGray(binary) << endl;
    }
        return 0;
}
