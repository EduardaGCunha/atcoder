#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

const int MAXN = 3e6+7;
int arr[MAXN], diff[MAXN];

signed main(){
    int n; cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    for(int i = 0; i < n; i++){
        diff[1]++;
        diff[arr[i]+1]--;
    }

    for(int i = 1; i <= MAXN-1; i++){
        diff[i] += diff[i-1];
    }

    for(int i = 1; i <= MAXN-1; i++){
        if(diff[i] >= 10){
            diff[i+1] += diff[i]/10;
            diff[i] =  diff[i]%10;
        }
    }

    int st = MAXN-1;
    for(; st > 1; st--){
        if(diff[st] != 0) break;
    }
    for(int i = st; i > 0; i--){
        cout << diff[i];
    }
    cout << endl;
}