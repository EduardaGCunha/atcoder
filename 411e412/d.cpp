#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        if(a > b) swap(a, b);
        grid[a][b] = 1;
    }
    
    int ans = 101;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 0);
    do{
        //ciclo de 1
        vector<vector<int>> grid2(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            int u = arr[i], v = arr[(i+1)%n];
            if(u > v) swap(u, v);
            grid2[u][v] = 1;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != grid2[i][j]) cnt++;
            }
        }
        ans = min(ans, cnt);
        
        //escolher um ponto pra ser a quebra
        for(int x = 3; x <= n-3; x++){
            cnt = 0;
            vector<vector<int>> grid3(n, vector<int>(n, 0));
            for(int i = 0; i < x; i++){
                int u = arr[i], v = arr[(i+1)%x];
                if(u > v) swap(u, v);
                grid3[u][v] = 1;
            }

            for(int i = 0; i < n - x; i++){
                int u = arr[x+i], v = arr[x+(i+1)%(n-x)];
                if(u > v) swap(u, v);
                grid3[u][v] = 1;
            }

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] != grid3[i][j]) cnt++;
                }
            }
            ans = min(ans, cnt);
        }
    }while(next_permutation(arr.begin(), arr.end()));
    cout << ans << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}