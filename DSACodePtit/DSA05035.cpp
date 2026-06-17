// Xét các số X có các chữ số được sắp xếp tăng dần, tức a[1] ≤ a[2] ≤ … ≤ a[N] trong đó a[1], a[2], …, a[N] lần lượt là các chữ số của X. Chẳng hạn 223, 8999, …

// Cho trước số chữ số N. Nhiệm vụ của bạn là đếm xem có bao nhiêu số như vậy.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
// Mỗi test gồm một số nguyên dương N (1 ≤ N ≤ 100).
// Output: 

// Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 109+7.
// Ví dụ:

// Input:

// Output

// 3

// 1

// 2

// 3

// 10

// 55

// 220

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll Mod = 1e9 + 7;

void testCase(){
    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll> (10, 0));
    for(int j = 0; j <= 9; j++){
        dp[1][j] = 1;
    }

    ll ans = 0;

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            dp[i][j] = 0;
            for(int k = 0; k <= j; k++){
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % Mod;
            }
        }
    }

    for(int j = 0; j <= 9; j++){
        ans = (ans + dp[n][j]) % Mod;
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