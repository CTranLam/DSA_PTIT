#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int k = 0;
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				k++;
			}
		}
		if (k) {
			cout << "Buoc " << i << ": ";
			for (int l = 0; l < n; l++)cout << a[l] << " ";
			cout << endl;
		}
	}
}