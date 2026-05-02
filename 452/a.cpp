#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int a, b; cin >> a >> b;
    if(a == 1 && b == 7) cout << "Yes\n";
    else if(a == 3 && b == 3) cout << "Yes\n";
    else if(a == 5 && b == 5) cout << "Yes\n";
    else if(a == 7 && b == 7) cout << "Yes\n";
    else if(a == 9 && b == 9) cout << "Yes\n";
    else cout << "No\n";
}