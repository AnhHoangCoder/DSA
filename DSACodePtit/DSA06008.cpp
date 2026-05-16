// Cho mảng X[] gồm n phần tử và mảng Y[] gồm m phần tử. Hãy đếm số các cặp xy>yx, trong đó x€X[] và y€Y[]. Ví dụ X[] = {2, 1, 6 }, Y[] = {1, 5} ta có kết quả là 3 cặp (2, 1), (2, 5), (6, 1).

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa vào n, m tương ứng với số phần tử của mảng X[] và Y[]; dòng tiếp theo là n số X[i] của mảng X[]; dòng cuối cùng là m số của mảng Y[]; các số được viết cách nhau một vài khoảng trống.
// T, n, m, X[i], Y[j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m ≤105; 0≤ X[i], Y[j] ≤103.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input:

// 1
// 3 2
// 2 1 6
// 1 5

// Output:

// 3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll countForX(int x, const vector<int>& y, int n, int cntY[]) {
    // Nếu x = 0, không có cặp nào thỏa mãn 0^y > y^0
    if (x == 0) return 0;

    // Nếu x = 1, chỉ có cặp (1, 0) thỏa mãn 1^0 > 0^1
    if (x == 1) return cntY[0];

    // Với x > 1, mặc định các cặp x^y > y^x khi y > x
    auto it = upper_bound(y.begin(), y.end(), x);
    ll ans = y.end() - it;

    // Các trường hợp y = 0 và y = 1 luôn đúng với x > 1
    ans += (cntY[0] + cntY[1]);

    // Trường hợp đặc biệt khi x = 2: 
    // 2^3 < 3^2 và 2^4 = 4^2 nên phải trừ bớt số lượng y=3 và y=4
    if (x == 2) {
        ans -= (cntY[3] + cntY[4]);
    }

    // Trường hợp đặc biệt khi x = 3:
    // 3^2 > 2^3 nên cộng thêm số lượng y=2
    if (x == 3) {
        ans += cntY[2];
    }

    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(m);
    int cntY[5] = {0}; // Mảng đếm số lượng 0, 1, 2, 3, 4 trong Y

    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < m; i++) {
        cin >> y[i];
        if (y[i] < 5) cntY[y[i]]++;
    }

    sort(y.begin(), y.end());

    ll totalPairs = 0;
    for (int val : x) {
        totalPairs += countForX(val, y, m, cntY);
    }
    cout << totalPairs << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}