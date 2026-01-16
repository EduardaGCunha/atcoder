#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        int pos = -1;
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[i]) pos = j;
        }
        
        if(pos == -1) cout << -1 << endl;
        else cout << pos+1 << endl;
    }
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}