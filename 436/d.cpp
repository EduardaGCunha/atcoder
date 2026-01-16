#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e9+7;
const int MAXN = 1e3+7;
vector<vector<pair<int, int>>> graph(27);
char grid[MAXN][MAXN];
int dist[MAXN][MAXN];
int vis[27];

int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};

int n, m;

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            dist[i][j] = INF;
            if(grid[i][j] >= 'a' || grid[i][j] <= 'z'){
                graph[grid[i][j] - 'a'].push_back({i, j});
            }
        }
    }
    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        int d = dist[x][y];

        //cout << x << " " << y << endl;
        if(grid[x][y] >= 'a' && grid[x][y] <= 'z'){
            int ch = grid[x][y] - 'a';
            if(!vis[ch]){
                vis[ch] = 1;
                for(auto [a, b] : graph[ch]){
                    if(dist[a][b] > d + 1){
                        dist[a][b] = d + 1;
                        q.push({a, b});
                    }
                }
            }
        } 
        for(int i = 0; i < 4; i++){
            int dx = d1[i] + x;
            int dy = d2[i] + y;

            if(dx < 0 || dx >= n) continue;
            if(dy < 0 || dy >= m) continue;
            if(grid[dx][dy] == '#') continue;

            if(dist[dx][dy] > d + 1){
                dist[dx][dy] = d+1;
                q.push({dx, dy});
            }
        }
    }   

    int ans = dist[n-1][m-1];

    if(dist[n-1][m-1] == INF) ans = -1;
    cout << ans << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
} 