#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

struct DSU {
    int n; 
    vector<int> p, r, edges, vertices;
    void init(int n_){
        n = n_;

        p.resize(n);
        r.resize(n);
        edges.resize(n);
        vertices.resize(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
            r[i] = 0;
            edges[i] = 0;
            vertices[i] = 1;
        }
        
    }

    int find(int x){
        return (p[x] == x)? x : p[x] = find(p[x]);
    }

    void unite(int x, int y){
        int a = find(x), b = find(y);

        if(a == b) edges[a]++;
        else{
            p[b] = a;
            edges[a] += edges[b] + 1;
            vertices[a] += vertices[b];
        }
        
    } 
};

signed main(){
    fastio;
    int n; cin >> n;
    vector<int> coord;
    vector<pair<int, int>> vec;
    for(int i = 0; i < n; i++){
        int x, r; cin >> x >> r;
        coord.push_back(x+r);
        coord.push_back(x-r);
        vec.push_back({x+r, x-r});
    }

    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());

    auto get_id = [&](long long val) {
        return lower_bound(coord.begin(), coord.end(), val) - coord.begin();
    };

    DSU dsu;
    dsu.init(coord.size());
    for(int i = 0; i < n; i++){
        int a = get_id(vec[i].first);
        int b = get_id(vec[i].second);

        dsu.unite(a, b);
    }

    int ans = 0;
    for(int u = 0; u < coord.size(); u++){
        if(u != dsu.find(u)) continue;
        ans += min(dsu.edges[u], dsu.vertices[u]);
    }
    cout << ans << endl;

}