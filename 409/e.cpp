#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5+2;
vector<pair<int, int>> graph[MAXN];
int arr[MAXN], cost = 0;

void dfs(int v, int p){
    for(auto [u, w] : graph[v]){
        if(u == p) continue;
        dfs(u, v);
        cost += (abs(arr[u])*w);
        arr[v] += arr[u];
    }
}

void solve(){
	int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n-1; i++){
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    dfs(0, -1);
    cout << cost << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}