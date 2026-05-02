#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    double n; cin >> n;
    double pi = 3.141592653589793;
    n /=2;
    double ans = (n*n)*pi;
    cout << fixed << setprecision(20) << ans << endl;
}