#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

void solve(){
    int n, d; cin >> n >> d;
    priority_queue<pair<int, int>> pq;
    int arr[n], brr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i];

    for(int i = 0; i < n; i++){
        //add the amount of eggs
        pq.push({-(i+1), arr[i]});
        //take bi eggs from priority queue
        //cout << "remocoes dia " << i+1 << endl;
        int qtd = brr[i]; 
        while(!pq.empty()){
            auto [dia, amnt] = pq.top(); pq.pop();
            //cout << dia << " " << amnt << endl;
            if(amnt > qtd){
                amnt -= qtd;
                pq.push({dia, amnt});
                break;
            }else qtd -= amnt;
        }
        //cout << "retirando velhos dia " << i+1 << endl;
        while(!pq.empty()){
            auto [dia, amnt] = pq.top();
            dia = -dia;
            //cout << i+1 << " " << dia << " " << (i+1) - dia << endl;
            if((i+1) - dia >= d) pq.pop();
            else break;
        }
    }

    int ans = 0;
    while(!pq.empty()){
        auto [dia, amnt] = pq.top(); pq.pop();
        ans += amnt;
    }
    cout << ans << endl;
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}