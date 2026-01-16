#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 5e5+7;
vector<int> graph[MAXN];
int dist[3][MAXN];
int init = 0;
int dis = 0, cur = 0;

void dfs(int v, int p, int d){
    dist[init][v] = d;
    if(d > dis){
        dis = d;
        cur = v;
    }else if (d == dis) {
        cur = max(cur, v);
    }

    for(auto u : graph[v]){
        if(u == p) continue;
        dfs(u, v, d+1);
    }

}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dis = -1;
    cur = -1;
    dfs(0, 0, 0);
    init++;
    int v1 = cur;

    dis = -1;
    cur = -1;
    dfs(v1, v1, 0);
    init++;
    int v2 = cur;

    dis = -1;
    cur = -1;
    dfs(v2, v2, 0);
    if(v1 > v2){
        swap(v1, v2);
        swap(dist[1], dist[2]);
    }
    //cout << v1+1 << " " << v2+1<< endl;
    for(int i = 0; i < n; i++){
        if(dist[1][i] > dist[2][i]) cout << v1+1 << endl;
        else cout << v2+1 << endl;
    }
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}