#include <bits/stdc++.h>
using namespace std;

// Chuyển mã Gray sang mã nhị phân
string grayToBinary(string gray) {
    int n = gray.length();
    string binary = "";
    
    // Bit đầu tiên của nhị phân giống hệt bit đầu tiên của Gray
    binary += gray[0];

    // Tính các bit còn lại
    for (int i = 1; i < n; i++) {
        // B_i = B_(i-1) ⊕ G_i
        char bit = (binary[i - 1] - '0') ^ (gray[i] - '0') + '0';
        binary += bit;
    }

    return binary;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        string gray;
        cin >> gray;
        cout << grayToBinary(gray) << endl;
    }
    return 0;
}
