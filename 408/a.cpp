#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, s; cin >> n >> s;
    int prev = 0;
    string ans = "Yes";
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x - prev > s) ans = "No";
        prev = x;
    }
    cout << ans << endl;
}