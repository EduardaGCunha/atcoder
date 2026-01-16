#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y; cin >> x >> y;
    int ans = (x+y)%12;
    if(!ans) ans = 12;
    cout << ans << endl;
}