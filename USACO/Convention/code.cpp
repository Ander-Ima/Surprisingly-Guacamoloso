//
// Created by Ariel on 10/25/2025.
//
#include <bits/stdc++.h>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>& t) { os << '('; apply([&os](const Args&... args) { size_t n = 0; ((os << args << (++n != sizeof...(Args) ? ", " : "")), ...); }, t); return os << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

int getBiggest(int capacity, vector<int>& arrive) {
    int worst = 0;
    for (int i = 0; i < arrive.size(); i += capacity) {
        int aux1 = ((int)min(i + capacity - 1, (int)(arrive.size() - 1))), aux2 = ((int)min(i, (int)(arrive.size() - 1)));
        int actual = abs(arrive[aux2] - arrive[aux1]);
        worst = max(worst, actual);
    }
    return worst;
}

void run_case() {
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 1, r = c , biggest_time = INT32_MAX;
    while (l < r) {
        int mid = l + (r - l) / 2;
        int timeWith = getBiggest(mid, a);
        if (timeWith > biggest_time) {
            l = mid ;
        }else {
            r = mid + 1;
            biggest_time = timeWith;
        }
        cout << mid << " ";
    }
    cout << biggest_time << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    while (tests-- > 0)
        run_case();
}