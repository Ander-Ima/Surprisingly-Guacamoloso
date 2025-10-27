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

struct range{
    int l = 0, r = 0, length = (r - l);
    friend bool operator<(const range& a, const range& b){
        return abs(a.r - a.l) < abs(b.r - b.l);
    };
};

void run_case() {
    int x, n;
    cin >> x >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    set<int> lights;
    multiset<range> best;
    lights.insert(0), lights.insert(x);
    best.insert({0, x});
    for(int i = 0; i < n; ++i){
        int leftLight, rightLight;
        rightLight = *lights.upper_bound(a[i]);
        leftLight = *prev(lights.upper_bound(a[i]));
        best.erase(best.find({rightLight, leftLight}));
        best.insert({leftLight, a[i]});
        best.insert({a[i], rightLight});
        lights.insert(a[i]);
        auto ans = *prev(best.end());
        cout << ans.length << " ";
    }
    cout << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests = 1;
    //cin >> tests;
    while (tests-- > 0)
        run_case();
}