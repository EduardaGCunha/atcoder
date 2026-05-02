#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MAXN = 3e5+7;
vector<int> graph[MAXN];
int visited[MAXN];
vector<int> order;
int cnt = 0;
queue<int> q;

void dfs(int v){
    visited[v] = 1;
    if(graph[v].size() == 1){
        cnt++;
        q.push(v);
    }
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
    order.push_back(v);
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        graph[i].clear();
        visited[i] = 0;
    }

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }  

    dfs(0);

    vector<pair<int, int>> colors;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        colors.push_back({x, i});
    }
    sort(colors.rbegin(), colors.rend());
    priority_queue<pair<int, int>> pq;
    for(auto u : colors) pq.push(u);
    vector<int> ans(n, 0);
    while(!q.empty()){
        auto c = pq.top(); pq.pop();
        if(c.first == 1 && cnt){
            cout << "No\n";
            return;
        }
        c.first -=1;
        pq.push(c);
        auto v = q.front(); q.pop();
        ans[v] = c.second;
    }

    cout << "Yes\n";
    for(auto u : ans) cout << u << " ";
    cout << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}