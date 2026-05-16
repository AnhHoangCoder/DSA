// Một người có cái túi thể tích V (V<1000). Anh ta có N đồ vật cần mang theo (N≤1000), mỗi đồ vật có thể tích là A[i] (A[i]≤100) và giá trị là C[i] (C[i]≤100). Hãy xác định tổng giá trị lớn nhất của các đồ vật mà người đó có thể mang theo, sao cho tổng thể tích không vượt quá V.

// Input

// Dòng đầu ghi số bộ test T (T<10)
// Mỗi bộ test gồm ba dòng. Dòng đầu ghi 2 số N và V. Dòng tiếp theo ghi N số của mảng A. Sau đó là một dòng ghi N số của mảng C.
// Dữ liệu vào luôn đảm bảo không có đồ vật nào có thể tích lớn hơn V.
// Output

// Với mỗi bộ test, ghi trên một dòng giá trị lớn nhất có thể đạt được.
// Ví dụ

// Input

// Output

// 1

// 15 10

// 5 2 1 3 5 2 5 8 9 6 3 1 4 7 8

// 1 2 3 5 1 2 5 8 7 4 1 2 3 2 1

// 15

#include <iostream>
#include <vector>

using namespace std;

inline void nhap(vector<int> &a , int n){
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
}

void testCase(){
    int v,n;
    cin >> n >> v;
    vector<int> a(n+1) , c(n+1);
    nhap(a , n);
    nhap(c , n);

    vector<vector<int>> dp(n+1 , vector<int> (v+1 , 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=v;j++){
            if(j < a[i]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i-1][j - a[i]] + c[i]);
            }
        }
    }
    cout << dp[n][v] << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}