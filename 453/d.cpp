#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MAXN = 1005;
char grid[MAXN][MAXN];
int n, m;

// R:0, D:1, L:2, U:3
int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};
char dirc[] = {'R', 'D', 'L', 'U'};

struct state {
    int x, y, d;
};

int visited[MAXN][MAXN][4];
state parent[MAXN][MAXN][4];

bool valid(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

signed main(){
    fastio;
    if (!(cin >> n >> m)) return 0;
    int a = -1, b = -1, gx = -1, gy = -1;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++){
            grid[i][j] = s[j];
            if(s[j] == 'S'){
                a = i; b = j;
            }else if(s[j] == 'G'){
                gx = i; gy = j;
            }
        }
    }

    queue<state> q;
    for(int i = 0; i < 4; i++){
        int dx = a + d1[i];
        int dy = b + d2[i];
        if(!valid(dx, dy) || grid[dx][dy] == '#') continue;
        visited[dx][dy][i] = 1;
        parent[dx][dy][i] = {a, b, -1};
        q.push({dx, dy, i});
    }

    int fd = -1;
    while(!q.empty()){
        auto [x, y, dir] = q.front(); q.pop();
        if(x == gx && y == gy){
            fd = dir;
            break;
        }

        for(int i = 0; i < 4; i++){
            if(grid[x][y] == 'o' && i != dir) continue;
            if(grid[x][y] == 'x' && i == dir) continue;

            int dx = x + d1[i];
            int dy = y + d2[i];

            if(valid(dx, dy) && grid[dx][dy] != '#' && !visited[dx][dy][i]){
                visited[dx][dy][i] = 1;
                parent[dx][dy][i] = {x, y, dir};
                q.push({dx, dy, i});
            }
        }
    }

    if(fd != -1){
        cout << "Yes\n";
        string s = "";
        state curr = {gx, gy, fd};
        while(curr.d != -1){
            s += dirc[curr.d];
            curr = parent[curr.x][curr.y][curr.d];
        }   
        reverse(s.begin(), s.end());
        cout << s << endl;
    } else {
        cout << "No\n";
    }
    return 0;
}