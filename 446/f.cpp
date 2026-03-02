#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MAXN = 3e5+7;
vector<int> graph[MAXN], rev[MAXN];
set<int> conn, nconn;
int k = 1;

void dfs(int v){
    conn.insert(v);
    for(auto u : graph[v]){
        if(u <= k){
            if(conn.find(u) == conn.end()) dfs(u);
        }else nconn.insert(u);
    }
}

signed main(){
    int n, m; cin >> n >> m;   
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        rev[b].push_back(a);
    } 

    conn.insert(0);
    rev[1].push_back(0);
    for(int i = 1; i <= n; i++){
        k = i;
        bool ok = false;
        for(auto u : rev[i]){
            if(conn.find(u) != conn.end()) ok = true;
        }   
        if(ok){
            if(nconn.find(i) != nconn.end()) nconn.erase(i);
            dfs(i);
            if(conn.size() ==i+1) cout << nconn.size() << endl;
            else cout << -1 << endl;
        }else cout << "-1\n";
        // cout << conn.size() << endl;
        // for(auto u : conn) cout << u << " ";
        // cout << endl;
    }
}