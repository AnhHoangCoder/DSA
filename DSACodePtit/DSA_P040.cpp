// Cho một bảng kích thước 4 x N (gồm N cột). Mỗi ô (i, j) có điểm bằng A[i][j]. Bạn cần chọn một tập hợp các ô sao cho điểm đạt được là lớn nhất, và trong các ô được chọn, không có 2 ô nào có chung cạnh.

// Ví dụ với bảng có N = 3 như hình vẽ trên. Cách chọn tập tối ưu là (3,1), (1, 2), (4, 2) và (3, 3).

// Input:

// Dòng đầu tiên là số lượng bộ test T (T <= 20).

// Mỗi test bắt đầu bởi số nguyên dương N (1 <= N <= 10000).

// 4 dòng tiếp theo, mỗi dòng gồm N số A[i][j], là điểm tại ô (i,j) (-10000 <= A[i][j] <= 10000).

// Output: 

// Với mỗi test, in ra đáp án tìm được trên một dòng.

// Ví dụ:

// Input:

// Output

// 2

// 3

// -1 9 3

// -4 5 -6

// 7 8 9

// 9 7 2

// 2

// -1 -5

// -2 -6

// -3 -7

// -4 -8

// 32

// -1

#include <iostream>
#include <vector>

using namespace std;

const int inf = -1e9;

void testCase(){
    int n;
    cin >> n;
    vector<vector<int>> a(4 , vector<int> (n));

    int best = inf;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> a[i][j];
            best = max(best , a[i][j]);
        }
    }

    int N = 1 << 4;
    vector<vector<int>> dp(n , vector<int> (N , inf));

    vector<int> valid;
    for(int mask = 0 ; mask < N ; mask++){
        if((mask & (mask << 1)) == 0){
            valid.push_back(mask);
        }
    }

    for(int mask : valid){
        int sum = 0;
        for(int i = 0 ; i < 4 ; i++){
            if(mask & (1 << i)){
                sum += a[i][0];
            }
        }
        dp[0][mask] = sum;
    }

    for(int col = 1 ; col < n ; col++){
        for(int mask : valid){
            int sum = 0;
            for(int i = 0 ; i < 4 ; i++){
                if(mask & (1 << i)){
                    sum += a[i][col];
                }
            }

            for(int prev : valid){
                if((mask & prev) == 0){
                    dp[col][mask] = max(dp[col][mask] , dp[col-1][prev] + sum);
                }
            }
        }
    }

    int res = inf;
    for(int mask : valid){
        res = max(res , dp[n-1][mask]);
    }
    cout << (res == 0 ? best : res) << endl;
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