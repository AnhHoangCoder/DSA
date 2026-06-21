// Cho số nguyên dương N có không quá 1000 chữ số. Hãy tính độ dài lớn nhất của một số thuận nghịch tạo được bằng cách lấy liên tiếp các chữ số trong N.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
// Mỗi test ghi ra một số nguyên dương N không quá 1000 chữ số.
// Output:  Với mỗi test, in ra đáp án tìm được.

// Ví dụ:

// Input

// Output

// 2

// 13731456

// 44444

// 5

// 5

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    string s;
    cin >> s;
    int n = (int)s.size();

    vector<vector<bool>> dp(n, vector<bool> (n, false));

    for(int i = 0; i < n; i++){
        dp[i][i] = true;
    }

    int ans = 0;
    for(int len = 2; len <= n; len++){
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            if(s[i] == s[j]){
                if(len == 2 || dp[i + 1][j - 1]){
                    dp[i][j] = true;
                    ans = max(ans , len);
                }
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