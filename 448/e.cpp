#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll P;

ll power(ll base, ll exp) {
    ll res = 1;
    base %= P;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % P;
        base = (__int128)base * base % P;
        exp /= 2;
    }
    return res;
}

// Computes (10^0 + 10^1 + ... + 10^{l-1}) % P
ll sum_powers(ll l) {
    if (l == 0) return 0;
    if (l == 1) return 1;
    if (l % 2 == 0) {
        ll half = sum_powers(l / 2);
        return (__int128)half * (1 + power(10, l / 2)) % P;
    } else {
        return (1 + (__int128)10 * sum_powers(l - 1)) % P;
    }
}

int main() {
    int K;
    ll M;
    cin >> K >> M;
    P = 10007 * M;

    ll N_mod_P = 0;
    for (int i = 0; i < K; ++i) {
        int c;
        ll l;
        cin >> c >> l;
        
        ll p10l = power(10, l);
        ll block = (__int128)c * sum_powers(l) % P;
        
        N_mod_P = ((__int128)N_mod_P * p10l + block) % P;
    }

    ll ans = (N_mod_P / M) % 10007;
    cout << (int)ans << endl;

    return 0;
}