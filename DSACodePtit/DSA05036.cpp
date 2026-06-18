// Cho hai dãy số thực A[] và B[] đều có N phần tử, các giá trị là số thực và không quá 100.

// Hãy tính độ dài dài nhất của dãy các vị trí (không cần liên tiếp) thỏa mãn cả hai điều kiện:

// Nếu xét các vị trí đó trên dãy A[] thì dãy con thu được thỏa mãn tính chất tăng dần (giá trị bằng nhau không được tính vào dãy tăng).
// Nếu xét các vị trí đó trên dãy B[] thì dãy con thu được thỏa mãn tính chất giảm dần (giá trị bằng nhau không được tính vào dãy giảm).
// Input

// Dòng đầu ghi số bộ test (không quá 100).

// Mỗi bộ test bắt đầu bởi số N (không quá 500).

// Tiếp theo là N dòng, mỗi dòng ghi 2 giá trị A[i] và B[i]

// Output

// Với mỗi test, ghi ra độ dài tính được trên một dòng.

// Ví dụ

// Input

// Output

// 3

// 2

// 1.0 1.0

// 1.5 0.0

// 3

// 1.0 1.0

// 1.0 1.0

// 1.0 1.0

// 6

// 1.5 9.0

// 2.0 2.0

// 2.5 6.0

// 3.0 5.0

// 4.0 2.0

// 10.0 5.5

// 2

// 1

// 4

#include <iostream>
#include <vector>

using namespace std;
using db = double;

void testCase(){
    int n;
    cin >> n;
    
    vector<db> a(n) , b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    
    vector<int> dp(n , 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] < a[i] && b[j] > b[i]){
                dp[i] = max(dp[i] , dp[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans , dp[i]);
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