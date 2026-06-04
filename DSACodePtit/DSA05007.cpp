// Cho dãy số A[] gồm N phần tử. Hãy tìm tổng lớn nhất của dãy con của dãy số A[] sao cho dãy con không có hai số cạnh nhau trong A[]. Ví dụ với A[] = {6, 7, 1, 3, 8, 2, 4} ta có kết quả là 19 tương ứng với tổng của dãy con {6, 1, 6, 4} không có haI phần tử nào kề nhau trong A[].

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là một số N; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤106; 1≤A[i] ≤107.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 6
// 5 5 10 100 10 5
// 4
// 3 2 7 10

// 110
// 13

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void testCase(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> dp(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    dp[0] = a[0];
    dp[1] = max(a[0] , a[1]);
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1] , dp[i-2] + a[i]);
    }

    cout << dp[n-1] << endl;
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