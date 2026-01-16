#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 3e5+7;
vector<int> graph[MAXN];
int visited[MAXN];
int c = 0;

void dfs(int v){
    visited[v] = 1;
    c++;
    for(auto u : graph[v]) if(!visited[u]) dfs(u);
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        graph[i].push_back(x);
        graph[x].push_back(i);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            c = 0;
            dfs(i);
            ans += (c*(c-1))/2;
        }
    }

    cout << ans << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
} 