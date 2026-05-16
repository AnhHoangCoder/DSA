// Một con ếch có thể nhảy 1, 2, 3 bước để có thể lên đến một đỉnh cần đến. Hãy đếm số các cách con ếch có thể nhảy đến đỉnh.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là số n là số bước con ếch có thể lên được đỉnh.
// T, n thỏa mãn ràng buộc: 1≤T≤100;  1≤n ≤50.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 1
// 5

// 1
// 13

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void testCase(){
    int n;
    cin >> n;
    vector<ll> dp(51);
    dp[1] = 1 , dp[2] = 2 , dp[3] = 4;
    for(int i=4;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
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