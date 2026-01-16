#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'
const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int visited[MAXN];
int cnt = 0;

void dfs(int v){
    visited[v] = 1;
    cnt++;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
}

void solve(){
    int n; cin >> n;
    vector<int> st;
    for(int i = 1; i <= n; i++){
        int a, b; cin >> a >> b;
        if(a == 0 && b == 0){
            st.push_back(i);
        }else{
            graph[a].push_back(i);
            graph[b].push_back(i);
        }
    }

    for(auto u : st){
        if(!visited[u]) dfs(u);
    }

    cout << cnt << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}