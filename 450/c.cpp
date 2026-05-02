#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};

signed main(){
    int n, m; cin >> n >> m;
    string grid[n];
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        cin >> grid[i];
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.'){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    visited[i][j] = 2;
                    q.push({i, j});
                }
            }
        }
    }

    auto bfs = [&]() {
        while(!q.empty()){
            auto [x, y] = q.front(); 
            q.pop();
            for(int i = 0; i < 4; i++){
                int dx = d1[i] + x;
                int dy = d2[i] + y;
                if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;   
                if(!visited[dx][dy] && grid[dx][dy] == '.'){
                    visited[dx][dy] = visited[x][y];
                    q.push({dx, dy});
                }
            }
        }
    };

    bfs();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && grid[i][j] == '.'){
                visited[i][j] = 1;
                cnt++;
                q.push({i, j});
                bfs();
            }
        }
    }

    cout << cnt << endl;
}