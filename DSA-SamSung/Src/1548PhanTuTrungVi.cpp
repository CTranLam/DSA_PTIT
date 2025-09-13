#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    multiset<int> s;
    auto mid = s.end(); // con trỏ tới median

    for (int i = 0; i < Q; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int x; cin >> x;
            if (s.empty()) {
                s.insert(x);
                mid = s.begin();
            } else {
                s.insert(x);
                if (s.size() % 2 == 1) { 
                    // số phần tử lẻ
                    if (x < *mid) mid--;
                } 
                else { 
                    // số phần tử chẵn
                    if (x >= *mid) mid++;
                }
            }
        } 
        else if (cmd == "del") {
            int x; cin >> x;
            if (s.size() == 1) {
                s.erase(s.find(x));
                mid = s.end();
            } else {
                if (s.size() % 2 == 1) { 
                    // số phần tử lẻ
                    if (x == *mid) {
                        auto it = mid;
                        it++;
                        s.erase(mid);
                        mid = it;
                    } else if (x < *mid) {
                        s.erase(s.find(x));
                        mid++;
                    } else {
                        s.erase(s.find(x));
                    }
                } else { 
                    // số phần tử chẵn
                    if (x == *mid) {
                        auto it = mid;
                        it++;
                        s.erase(mid);
                        mid = it;
                        mid--;
                    } else if (x < *mid) {
                        s.erase(s.find(x));
                        mid--;
                    } else {
                        s.erase(s.find(x));
                    }
                }
            }
        } 
        else if (cmd == "print") {
            cout << *mid << "\n";
        }
    }

    return 0;
}
