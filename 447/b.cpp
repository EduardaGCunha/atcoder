#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    string s; cin >> s;
    int n = s.size();
    map<int, int> freq;
    int mx = 0;
    for(int i = 0; i < n; i++){
        freq[s[i]]++;
        mx = max(mx, freq[s[i]]);
    }

    for(int i = 0; i < n; i++){
        if(freq[s[i]] == mx) continue;
        else cout << s[i];
    }
    cout << endl;
}