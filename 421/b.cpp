#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 13;
int arr[MAXN];
/*
f[0] = x
f[1] = y
f[x] = rev(f[x-1]+f[x-2])
 */


void solve(){
    int x, y; cin >> x >> y;
    arr[0] = x;
    arr[1] = y;
    int cnt = 2;
    while(cnt < 10){
        string s = to_string(arr[cnt-1] + arr[cnt-2]);
        reverse(s.begin(), s.end());
        arr[cnt] = stoll(s);
        cnt++;
    }
    cout << arr[cnt-1] << endl;

}

signed main(){
	fastio;
	int t = 1;
	while(t--){
		solve();
	}
}
