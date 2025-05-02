#include <iostream>
using namespace std;

string binaryToDecimal(const string &binary) {
    string decimal = "0";
    for (char bit : binary) {
        string temp = decimal;
        int carry = 0;
        for (int i = temp.size() - 1; i >= 0; i--) {
            int num = (temp[i] - '0') * 2 + carry;
            temp[i] = (num % 10) + '0';
            carry = num / 10;
        }
        if (carry) temp = char(carry + '0') + temp;

        if (bit == '1') {
            int carry = 1;
            for (int i = temp.size() - 1; i >= 0; i--) {
                int num = (temp[i] - '0') + carry;
                temp[i] = (num % 10) + '0';
                carry = num / 10;
            }
            if (carry) temp = char(carry + '0') + temp;
        }

        decimal = temp;
    }
    return decimal;
}

string multiplyLargeNumbers(string num1, string num2) {
    int len1 = num1.size(), len2 = num2.size();
    string result(len1 + len2, '0');

    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; j--) {
            int sum = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            result[i + j + 1] = (sum % 10) + '0';
            carry = sum / 10;
        }
        result[i] += carry;
    }

    size_t startPos = result.find_first_not_of("0");
    return (startPos == string::npos) ? "0" : result.substr(startPos);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S1, S2;
        cin >> S1 >> S2;

        string num1 = binaryToDecimal(S1);
        string num2 = binaryToDecimal(S2);

        string product = multiplyLargeNumbers(num1, num2);

        cout << product << endl;
    }
    return 0;
}
