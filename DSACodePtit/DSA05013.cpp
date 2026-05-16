// Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước lên trên tối đa K bước. Hỏi có tất cả bao nhiêu cách bước để đi hết cầu thang? (Tổng số bước đúng bằng N).

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
// Mỗi test gồm hai số nguyên dương N và K(1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).
// Output: 

// Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 109+7.
// Ví dụ:

// Input

// Output

// 2

// 2 2

// 4 2

 

// 2

// 5

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll mod = 1e9+7;

void testCase(){
    int n,k;
    cin >> n >> k;
    vector<ll> dp(n+1);
    dp[0] = 1;
    ll sum = 1;
    for(int i=1;i<=n;i++){
        dp[i] = sum % mod;

        sum = (sum + dp[i]) % mod;
        if(i - k >= 0){
            sum = (sum - dp[i-k] + mod) % mod;
        }
    }
    cout << dp[n] % mod << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}