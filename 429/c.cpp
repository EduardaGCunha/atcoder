#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    map<int, int> freq;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int ans = 0;
    for(auto [v, qtd] : freq){
        if(qtd <= 1) continue;
        int tot = (qtd*(qtd-1))/2;
        //cout << tot << " " << n-qtd << endl;
        ans += (tot*(n-qtd));
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