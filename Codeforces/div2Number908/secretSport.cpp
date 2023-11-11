#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int winsA = 0, winsB = 0;
        int setsA = 0, setsB = 0;
        char lastWinner = ' ';

        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                winsA++;
                lastWinner = 'A';
            } else {
                winsB++;
                lastWinner = 'B';
            }

            if (winsA >= 3 && winsA > winsB + 1) {
                setsA++;
                winsA = 0;
                winsB = 0;
            } else if (winsB >= 3 && winsB > winsA + 1) {
                setsB++;
                winsA = 0;
                winsB = 0;
            }

            if (setsA == setsB) {
                // Reset the wins for both players if it's a new set
                winsA = 0;
                winsB = 0;
            }
        }

        if (setsA > setsB) {
            cout << "A" << endl;
        } else if (setsB > setsA) {
            cout << "B" << endl;
        } else {
            // Determine the winner based on the last winning player
            if (lastWinner == 'A') {
                cout << "A" << endl;
            } else {
                cout << "B" << endl;
            }
        }
    }

    return 0;
}
