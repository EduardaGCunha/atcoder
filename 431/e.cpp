#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define endl '\n'

const int INF = 1e9;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int reflect[4][3] = {
    // A(0)   B(1)   C(2)
    {0,     1,     3}, // R (0) -> Out: R, D, U
    {1,     0,     2}, // D(1)  -> Out: D, R, L
    {2,     3,     1}, // L (2)  -> Out: L, U, D
    {3,     2,     0}  // U (3)    -> Out: U, L, R
};

void solve(){
	int n, m; cin >> n >> m;
	int grid[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char a; cin >> a;
			grid[i][j] = a - 'A';
		}
	}
	

	vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4, INF)));

	deque<tuple<int, int, int>> dq;

	dist[0][0][0] = 0;
	dq.push_front({0, 0, 0});

	int ans = INF;
	while(!dq.empty()){
		auto [x, y, dir] = dq.front();
		dq.pop_front();

		for(int i = 0; i < 3; i++){
			int cost = (grid[x][y] != i); 
			int dirout = reflect[dir][i];
			int nx = x + dx[dirout];
			int ny = y + dy[dirout];
			if(x == n-1 && y == m-1 && dirout == 0){
				ans = min(ans, dist[x][y][dir] + cost);
			}
			if(nx < 0 || nx >= n) continue;
			if(ny < 0 || ny >= m) continue;

			if(dist[nx][ny][dirout] > dist[x][y][dir] + cost){
				dist[nx][ny][dirout] = dist[x][y][dir] + cost;
				if(cost) dq.push_back({nx, ny, dirout});
				else dq.push_front({nx, ny, dirout});
			}
		}
	}

	cout << ans << endl;
}
signed main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}