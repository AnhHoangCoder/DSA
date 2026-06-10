// Cho một bảng số N hàng, M cột chỉ gồm 0 và 1. Bạn hãy tìm hình vuông có kích thước lớn nhất, sao cho các số trong hình vuông toàn là số 1.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
// Mỗi test bắt đầu bởi 2 số nguyên N, M (1 ≤ N, M ≤ 500).
// N dòng tiếp theo, mỗi dòng gồm M số mô tả một hàng của bảng.
// Output: 

// Với mỗi test, in ra đáp án là kích thước của hình vuông lớn nhất tìm được trên một dòng.
// Ví dụ:

// Input:

// Output

// 2

// 6 5

// 0 1 1 0 1

// 1 1 0 1 0

// 0 1 1 1 0

// 1 1 1 1 0

// 1 1 1 1 1

// 0 0 0 0 0

// 2 2

// 0 0

// 0 0

// 3

// 0

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int> (m));
    
    int ans = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1] , min(dp[i][j-1] , dp[i-1][j])) + 1;
                }
                ans = max(ans , dp[i][j]);
            }
        }
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