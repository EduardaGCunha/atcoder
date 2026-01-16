#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 13;
char grid[MAXN][MAXN];
int n, m; 
pair<int, int> t, up, down, l, r;

pair<int, char> best(){
    pair<int, char> ans;
    if((l.first) > (r.first - t.first)) ans.first = min(ans.first, l.first), ans.second = 'L';
    if((m - r.first) > (t.first - l.first)) ans.first = min(ans.first, (m - r.first)), ans.second = 'R';
    if((up.second) > (down.second - t.first)) ans.first = min(ans.first, up.second), ans.second = 'U';
    if((n - down.second) > (t.first - up.second)) ans.first = min(ans.first, n - down.second), ans.second = 'D';
    return ans;
}


void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'T'){
                t = {i, j};
            }
        }
    }

    up = {t.first, 0}, down = {t.first, n+1};
    l = {0, t.second}, r = {m+1, t.second};
    //achar as 2 posicoes l r
    for(int i = 0; i < m; i++){
        if(i < t.first && grid[i][t.second] == '#') l = {i, t.second};
        else if(i > t.first && grid[i][t.second] == '#') r = {i, t.second};
    }

    //achar as 4 posicoes up down
    for(int i = 0; i < n; i++){
        if(i < t.first && grid[t.first][i] == '#') up = {t.first, i};
        else if(i > t.first && grid[t.first][i] == '#') down = {t.first, i};
    }

    pair<int, char> ans = best();
    if(ans.first == 1e5){
        cout << -1 << endl;
        return;
    }



}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}