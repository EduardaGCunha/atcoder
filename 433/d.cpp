#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
toda vez q mudar o numero nesse caractere, eu zero a soma e comeco dnv
*/

void solve(){
    int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    //placing numbers to the left of ai
    //how many numbers give remainder j if placed to the left of a number with k digits?
    vector<vector<int>> cnt(11, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        int val = arr[i]%m;
        int pot = (10%m);
        //ai*10^len
        for(int j = 1; j <= 10; j++){
            cnt[j][(val*pot)%m]++;
            pot = (pot*10)%m;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        string s = to_string(arr[i]);
        int l = s.size();
        int r = (m-arr[i]%m)%m;
        ans += cnt[l][r];
    }
    cout << ans << endl;
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}