#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y; cin >> x >> y;
    double ans = 0;
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            if(i + j >= x || abs(i - j) >= y) ans++;
        }
    }
    cout << fixed << setprecision(12);
    cout << (ans/36.0) << endl;
}