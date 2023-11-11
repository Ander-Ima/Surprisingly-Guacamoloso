#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        bool possible = true;

        for (int i = 0; i < n; i++) {
            vector<int> a = b;
            int x = i + 1;
            for (int j = 0; j < n; j++) {
                int new_pos = (j - x + n) % n;
                if (a[new_pos] != b[j]) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                if (k % __gcd(n, i + 1) == 0) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
                break;
            }
        }

        if (!possible) {
            cout << "No" << endl;
        }
    }

    return 0;
}
