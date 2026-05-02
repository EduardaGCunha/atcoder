#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n; cin >> n;
    map<int, int> sums;
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            for(int k = 1; k <= 6; k++){
                sums[i+j+k]++;
            }
        }
    }

    if(sums[n] > 0) cout << "Yes\n";
    else cout << "No\n";
}