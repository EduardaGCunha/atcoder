#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

/*
we're going to start a bfs from all the black parts 
and traverse the reversed graph
if at any point
*/
const int MAXN = 3e5+7;
vector<int> graph[MAXN];
int visited[MAXN];

void dfs(int v){
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
}

signed main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[b].push_back(a);
    }

    int q; cin >> q;
    while(q--){
        int op, v; cin >> op >> v;
        op--, v--;
        if(op){
            if(!visited[v]) cout << "No\n";
            else cout << "Yes\n";
        }else{
            if(!visited[v]) dfs(v);
        }
    }

}