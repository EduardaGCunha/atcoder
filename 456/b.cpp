#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false);cin.tie(nullptr);
#define endl '\n'

bool aux(int a, int b, int c){
    if(a == 4 && b == 5 && c == 6) return true;
    else if(a == 4 && b == 6 && c == 5) return true;
    else if(a == 5 && b == 4 && c == 6) return true;
    else if(a == 5 && b == 6 && c == 4) return true;
    else if(a == 6 && b == 5 && c == 4) return true;
    else if(a == 6 && b == 4 && c == 5) return true;
    return false;
}

signed main(){
    vector<int> a(7, 0), b(7, 0), c(7, 0);
    for(int i = 1; i <= 6; i++)cin >> a[i];
    for(int i = 1; i <= 6; i++)cin >> b[i];
    for(int i = 1; i <= 6; i++)cin >> c[i];

    double ans = 0;
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            for(int k = 1; k <= 6; k++){
                if(aux(a[i], b[j], c[k])) ans = ans + 1.0;
            }
        }
    }
    cout << fixed << setprecision(10);
    cout << ans/216.0 << endl;
    
}