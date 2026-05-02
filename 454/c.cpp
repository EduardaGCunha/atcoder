#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MAXN = 3e5+7;
vector<int> graph[MAXN];
int visited[MAXN];
int cnt =0;

void dfs(int v){
    visited[v]++;
    cnt++;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
}

signed main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    dfs(1);
    cout << cnt << endl;
}