#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

int fat(int x){
    if(x == 1) return 1;
    return x*fat(x-1);
}

int spf(int x){
    if(x == 1) return 1;
    return fat(x)*spf(x-1);
}

signed main(){
    int x; cin >> x;
    cout << spf(x) << endl;
}