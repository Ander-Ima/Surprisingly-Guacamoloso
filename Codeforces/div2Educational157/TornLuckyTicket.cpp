#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> tickets(n);
    unordered_map<int, int> sum_count; // Usamos un mapa para contar las sumas de dígitos en los fragmentos

    long long total_pairs = 0;

    for (int i = 0; i < n; i++) {
        cin >> tickets[i];

        int sum = 0;
        for (char digit : tickets[i]) {
            sum += digit - '0';
        }

        total_pairs += sum_count[sum];
        sum_count[sum]++;
    }

    for (int i = 0; i < n; i++) {
        int len = tickets[i].size();
        int sum = 0;
        for (char digit : tickets[i]) {
            sum += digit - '0';
        }

        if (len % 2 == 0) {
            int half_sum = sum / 2;
            if (sum_count.find(half_sum) != sum_count.end()) {
                total_pairs += sum_count[half_sum] - (tickets[i] <= to_string(half_sum));
            }
        }
    }

    cout << total_pairs << endl;

    return 0;
}
