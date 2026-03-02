#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MOD = 998244353;

struct DSU{
    int n;
    int comp;
    vector<int> p, r;
    void init(int x){
        n = x;
        comp = x;
        p.resize(n+1);
        r.resize(n+1, 0);
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
    }

    int find(int x){
        return p[x] == x? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return true;
        if(comp == 2) return false;
        if(r[a] == r[b]) r[a]++;
        if(r[a] > r[b]){
            r[a]++;
            p[b] = a;
        }else{
            p[a] = b;
            r[b]++;
        }
        comp--;
        return true;
    }
};

int fastexpo(int a, int b){
    int res = 1;
    a %= MOD;
    while(b > 0){
        if(b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>=1;
    }
    return res;
}

signed main(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        edges.push_back({a, b});
    }

    DSU dsu;
    dsu.init(n);
    int ans = 0;

    for(int i = m-1; i >= 0; i--){
        auto [a, b] = edges[i];
        if(!dsu.unite(a, b)){
            //cout << a << " " << b << endl;
            ans = (ans + (fastexpo(2, i+1)))%MOD;
        }
    }
    cout << ans << endl;
}