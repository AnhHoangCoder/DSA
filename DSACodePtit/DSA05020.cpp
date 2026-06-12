// Cho bảng A[] kích thước N x M (N hàng, M cột). Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo dưới. Khi đi qua ô (i, j), điểm nhận được bằng A[i][j].

// Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho tổng điểm là nhỏ nhất.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm số nguyên dương N và M.
// N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j] (0 ≤ A[i] ≤ 1000).
// Output: 

// Với mỗi test, in ra kết quả trên một dòng.
// Ví dụ:

// Input

// Output

// 1

// 3 3

// 1 2 3

// 4 8 2

// 1 5 3

 

// 8

 

// Giải thích test: Đường đi (1, 1) à (1, 2) à (2, 3) à (3, 3).

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

    vector<vector<int>> dp(n, vector<int> (m, 0));
    dp[0][0] = a[0][0];
    for(int j = 1; j < m; j++){
        dp[0][j] = dp[0][j-1] + a[0][j];
    }
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i-1][0] + a[i][0];
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            dp[i][j] = a[i][j] + min(dp[i-1][j-1] , 
                min(dp[i-1][j] , dp[i][j-1]));
        }
    }
    cout << dp[n-1][m-1] << endl;
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