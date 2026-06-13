// Cho số nguyên dương N được biểu diễn như một xâu ký tự số. Nhiệm vụ của bạn là tìm tổng của tất cả các số tạo bởi các xâu con của N. Ví dụ N=”1234” ta có kết quả là 1670 = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N.
// T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤1012.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 1234
// 421

// 1670
// 491

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void testCase(){
    string s;
    cin >> s;

    int n = (int)s.size();
    vector<ll> dp(n);
    dp[0] = s[0] - '0';

    ll ans = dp[0];
    for(int i = 1; i < n; i++){
        int d = s[i] - '0';
        dp[i] = 10 * dp[i - 1] + 1LL * d * (i + 1);

        ans += dp[i];
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}