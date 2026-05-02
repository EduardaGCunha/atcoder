#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n; cin >> n;
    for(int i = n; i>=1; i--){
        cout << i;
        if(i == 1) cout << endl;
        else cout << ",";
    }
}