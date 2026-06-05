// Catalan Number là dãy số thỏa mãn biểu thức:

// Dưới đây là một số số Catalan với n=0, 1,2,.. : 1, 1, 2, 5, 14, 42, 132, 429,… Cho số tự nhiên N. Nhiệm vụ của bạn là đưa ra số Catalan thứ N.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên n.
// T, n thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ n ≤ 100.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 3
// 5
// 4
// 10

// 42
// 14
// 16796

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void testCase(){
    int n;
    cin >> n;

    vector<ll> dp(n+1 , 0);

    dp[0] = 1;
    for(int i=1;i<=n;i++){
        dp[i] = 0;
        for(int j=0;j<i;j++){
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }

    cout << dp[n] << endl;
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