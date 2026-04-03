// Khu vui chơi trẻ em thiết kế một cầu thang có N bậc để di chuyển lên đỉnh tháp. Sinh viên PTIT cũng được phép leo lên cầu thang này nhưng nhìn chung chân sinh viên PTIT khá là dài nên có thể đi từ 1 đến K bậc mỗi bước (chứ không chỉ là 1 bậc như trẻ em).

// Hãy tính xem sinh viên PTIT có bao nhiêu cách để leo lên đến đỉnh.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
// Mỗi test gồm hai số nguyên dương N và K (1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).
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

 

// Giải thích test 2: Có 5 cách lần lượt là: (1, 1, 1, 1), (1, 1, 2), (1, 2, 1), (2, 1, 1), (2, 2).

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

void testCase(){
    int n,k;
    cin >> n >> k;
    vector<ll> dp(n+1 , 0);
    //0 bậc thì vẫn tính là 1 bước
    dp[0] = 1;
    ll sum = 1;
    for(int i=1;i<=n;i++){
        dp[i] = sum % mod;
        sum = (sum + dp[i]) % mod;
        //Tránh số bước bị trùng thì ta phải trừ đi từ 1 -> i-k
        if(i >= k){
            sum = (sum - dp[i-k] + mod) % mod;
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