#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

signed main(){
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i] %=k;
    }

    sort(arr, arr+n);
    int diff = arr[n-1] - arr[0];
    for(int i = 1; i < n; i++){
        
    }
}