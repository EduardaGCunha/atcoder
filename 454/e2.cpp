#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int N, A, B;
    if (!(cin >> N >> A >> B)) return;

    // Parity check
    if (N % 2 != 0 || (A + B) % 2 == 0) {
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    string path = "";
    int x = 1, y = N, x1 = 1, y2 = N;

    // Strip top rows until A is in the top two rows
    while (A > x + 1) {
        for (int j = x1; j < y2; ++j) path += 'R';
        path += 'D';
        for (int j = y2; j > x1; --j) path += 'L';
        path += 'D';
        x += 2;
    }

    // Strip left columns until B is in the left two columns
    while (B > x1 + 1) {
        for (int i = x; i < y; ++i) path += 'D';
        path += 'R';
        for (int i = y; i > x; --i) path += 'U';
        path += 'R';
        x1 += 2;
    }

    // Now (A,B) is relative (1,2) or (2,1) in the remaining subgrid
    int h = y - x + 1;
    int w = y2 - x1 + 1;
    int posA = A - x + 1;
    int posB = B - x1 + 1;

    if (posA == 1 && posB == 2) {
        // Skip (1,2): Move Down-Right-Down-Left... in first 2 columns
        for (int i = 1; i < h; ++i) {
            path += 'D';
            path += (i % 2 != 0) ? 'R' : 'L';
        }
        // Then snake the remaining columns
        if (w > 2) {
            path += 'R';
            for (int j = 3; j <= w; ++j) {
                for (int i = 1; i < h; ++i) {
                    path += (j % 2 != 0) ? 'U' : 'D';
                }
                if (j < w) path += 'R';
            }
        }
    } else {
        // Skip (2,1): Move Right-Down-Right-Up... in first 2 rows
        for (int j = 1; j < w; ++j) {
            path += 'R';
            path += (j % 2 != 0) ? 'D' : 'U';
        }
        // Then snake the remaining rows
        if (h > 2) {
            path += 'D';
            for (int i = 3; i <= h; ++i) {
                for (int j = 1; j < w; ++j) {
                    path += (i % 2 != 0) ? 'L' : 'R';
                }
                if (i < h) path += 'D';
            }
        }
    }

    cout << path << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}