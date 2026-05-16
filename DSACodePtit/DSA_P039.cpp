// Cho ma trận kích thước N x N (1 <= a[i][j] <= 10^6). Hãy chọn N ô, mỗi hàng một ô, một cột một ô, sao cho tổng các phần tử được chọn là lớn nhất.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T <= 20).

// Mỗi test bắt đầu bởi số nguyên dương N (2 <= N <= 20).

// N dòng tiếp theo, mỗi dòng gồm N số nguyên mô tả ma trận.

// Output: 

// Với mỗi test, in ra đáp án tìm được trên một dòng.

 

// Ví dụ:

// Input:

// Output

// 2

// 3

// 3 1 2

// 1 1 2

// 1 4 2

// 2

// 1 2

// 2 1

// 9

// 4

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n;
    cin >> n;

    vector<vector<int>> a(n , vector<int> (n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }

    int N = 1 << n;
    vector<int> dp(N , 0);
    for(int mask = 0 ; mask < N ; mask++){
        int row = __builtin_popcount(mask);

        if(row >= n) continue;

        for(int col = 0 ; col < n ; col++){
            if(!(mask & (1 << col))){
                int newMask = mask | (1 << col);
                dp[newMask] = max(dp[newMask] , dp[mask] + a[row][col]);
            }
        }
    } 
    cout << dp[N-1] << endl;
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