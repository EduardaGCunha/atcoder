#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MAXN = 107;
int grid[MAXN][MAXN];

signed main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++) cin >> grid[i][j];
    }

    // for(int i = 0; i < n-1; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int pos = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(grid[i][j] + grid[j][k] < grid[i][k]){
                    cout << "Yes\n";
                    pos = 1;
                    break;
                }
            }
            if(pos) break;
        }
        if(pos) break;
    }
    if(!pos) cout << "No\n";
}