#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MAXN = 3e6+7;
int arr[MAXN], diff[MAXN];

signed main(){
    int n, d; cin >> n >> d;
    multiset<int> ms;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        ms.insert(x);
        auto it = ms.lower_bound(x-d) - ms.begin();
        cout << it << endl;
    }
}