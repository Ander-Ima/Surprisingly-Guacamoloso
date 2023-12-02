#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000001;

int mpp[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int N;
    cin >> N;
    int xr = 0, cnt = 0;
    mpp[xr]++;
    for(int i = 0; i < N; ++i){
        int a;
        cin >> a;
        xr ^= a;
        cnt += mpp[xr];
        mpp[xr]++;
    }
    cout << cnt << "\n";
    return 0;
}
