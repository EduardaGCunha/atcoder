#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e12;
const int MAXN = 2e5+7;
vector<int> graph[MAXN];
int dist[MAXN][2], origin[MAXN][2];

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    string s; cin >> s;

    for(int i = 0; i < n; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
        origin[i][0] = -1;
        origin[i][1] = -1;
    }
    //dist, o, v
    priority_queue<tuple<int, int, int>> pq;
    for(int i = 0; i < n; i++){
        if(s[i] == 'S'){
            dist[i][0] = 0;
            origin[i][0] = i;
            pq.push({0, i, i});
        }
    }

    while(!pq.empty()){
        auto [d, o, v] = pq.top(); pq.pop();
        d = -d;
        if(dist[v][1] < d) continue;
        for(auto u : graph[v]){
            if(o == origin[u][0]){
                if(dist[u][0] > d+1){
                    dist[u][0] = d+1;
                    pq.push({-dist[u][0], o, u});
                }
            }else if(o == origin[u][1]){
                if(dist[u][1] > d+1){
                    dist[u][1] = d+1;
                    pq.push({-dist[u][1], o, u});
                }
            }else if(dist[u][0] > d + 1){
                dist[u][1] = dist[u][0];
                origin[u][1] = origin[u][0];

                dist[u][0] = d+1;
                origin[u][0] = o;
                pq.push({-dist[u][0], o, u});
            }else if(dist[u][1] > d + 1){
                dist[u][1] = d+1;
                origin[u][1] = o;
                pq.push({-dist[u][1], o, u});
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(s[i] == 'D'){
            cout << dist[i][0] + dist[i][1] << endl;
        }
    }
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}