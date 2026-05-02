#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++) cout << "#";
    cout << endl;
    for(int i = 1; i < n-1; i++){
        for(int j = 0; j < m; j++){
            if(j == 0 || j == m-1) cout << "#";
            else cout << ".";
        }
        cout << endl;
    }
    for(int i = 0; i < m; i++) cout << "#";
    cout << endl;
}