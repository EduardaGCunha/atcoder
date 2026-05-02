#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'



struct DSU{
    int n;
    vector<int> p, r;
    vector<set<int>> v;
    void init(int x){
        n = x;
        p.resize(n);
        r.resize(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
            r[i] = i;
        }
    }
}

signed main(){
    int n, q; cin >> n >> q;
    while(q--){
        int a, b; cin >> a >> b;
        a--, b--;
    }
}