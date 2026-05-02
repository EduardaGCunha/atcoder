#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'


signed main(){
    int q; cin >> q;
    priority_queue<int> pq;
    int ans = 0;
    while(q--){
        int op, x; cin >> op >> x;
        if(op == 1){
            pq.push(-x);
            ans++;
        }else{
            while(!pq.empty()){
                auto v = -pq.top();
                if(v > x) break;
                pq.pop();
                ans--;
            }
        }
        cout << ans << endl;
    }
}