#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

int d1[] = {1, 0, -1, 0};
int d2[] = {0, 1, 0, -1};
const int MAXN = 507;
const int MAXM = 507;
const int INF = (int)1e17;
char grid[2][MAXN][MAXM];
int dist[2][MAXN][MAXM];

void solve(){
	int n, m; cin >> n >> m;
	pair<int, int> st, fim;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char a; cin >> a;
			if(a == 'S') st.first = i, st.second = j;
			else if(a == 'G') fim.first = i, fim.second = j;
			if(a == 'x'){
				grid[0][i][j] = 'x';
				grid[1][i][j] = 'o';
			}else if(a == 'o'){
				grid[0][i][j] = 'o';
				grid[1][i][j] = 'x';
			}else{
				grid[0][i][j] = a;
				grid[1][i][j] = a;
			}
			dist[0][i][j] = INF;
			dist[1][i][j] = INF;
		}
	}

	// dist, x, y, g
	priority_queue< tuple<int,int,int,int> > pq;
	// start in state 0 only
	dist[0][st.first][st.second] = 0;
	pq.push({0, st.first, st.second, 0});

	while(!pq.empty()){
		auto [negd, x, y, g] = pq.top(); pq.pop();
        int d = -negd;
		if(dist[g][x][y] < d) continue;
		for(int i = 0; i < 4; i++){
			int dx = d1[i] + x;
			int dy = d2[i] + y;
			if(dx < 0 || dx >= n) continue;
			if(dy < 0 || dy >= m) continue;

			// if it's a switch: you move there and the state flips
			if(grid[g][dx][dy] == '?'){
				if(dist[!g][dx][dy] > d + 1){
					dist[!g][dx][dy] = d + 1;
					pq.push({-dist[!g][dx][dy], dx, dy, !g});
				}
			}
			// otherwise can move if not obstacle and not closed door in current state
			else if(grid[g][dx][dy] != '#' && grid[g][dx][dy] != 'x'){
				if(dist[g][dx][dy] > d + 1){
					dist[g][dx][dy] = d + 1;
					pq.push({-dist[g][dx][dy], dx, dy, g});
				}
			}
		}
	}

	int ans = min(dist[0][fim.first][fim.second], dist[1][fim.first][fim.second]);
	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}
