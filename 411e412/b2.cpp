#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n; cin >> n;
    n--;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++){
        int x = 0;
        for(int j = i; j < n; j++){
            x = arr[j] + x;
            cout << x << " ";
        }
        cout << endl;
    }
}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}