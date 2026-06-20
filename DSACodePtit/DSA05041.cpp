// Cho xâu ký tự S. Nhiệm vụ của bạn là tìm số phép loại bỏ ít nhất các ký tự trong S để S trở thành xâu đối xứng. Chú ý, phép loại bỏ phải bảo toàn tính trước sau của các ký tự trong S.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự được viết trên một dòng
// T, str thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤100.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

//  Input

// Output

// 2
// aebcbda
// geeksforgeeks

// 2
// 8

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<vector<int>> dp(n, vector<int> (n));

    for(int len = 2; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            if(s[i] == s[j]){
                dp[i][j] = dp[i + 1][j - 1];
            }
            else{
                dp[i][j] = min(dp[i + 1][j] , dp[i][j - 1]) + 1;
            }
        }
    }
    cout << dp[0][n - 1] << endl;
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