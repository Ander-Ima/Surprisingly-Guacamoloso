#include <bits/stdc++.h>
using namespace std;

int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >> t;

    while (t--) {
        int x, k;
        cin >> x >> k;

        int y = x;
        while (sum_of_digits(y) % k != 0) {
            y++;
        }

        cout << y << endl;
    }

    return 0;
}
