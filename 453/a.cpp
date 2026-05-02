#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n; cin >> n;
    string s; cin >> s;
    int i = 0;
    while(s[i] == 'o') i++;

    for(int idx = i; idx < n; idx++) cout << s[idx];
    cout << endl;
}