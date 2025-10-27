#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;  // Número de casos de prueba

    while (t--) {
        int n;
        cin >> n;  // Longitud del array

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int cnt = 0;
        bool sorted = true;

        for (int i = 0; i < n; i++) {
            if (a[i] > i) {
                int diff = a[i] - i;
                if (diff % 2 == 0) {
                    cnt = max(cnt, diff / 2);
                } else {
                    sorted = false;
                }
            }
        }

        if (sorted) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
