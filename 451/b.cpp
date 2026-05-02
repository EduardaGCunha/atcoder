#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n, m; cin >> n >> m;
    vector<int> cur(m, 0), next(m, 0);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        cur[a]++;
        next[b]++;
    }

    for(int i = 0; i < m; i++){
        cout << next[i]-cur[i]<< endl;
    }
}