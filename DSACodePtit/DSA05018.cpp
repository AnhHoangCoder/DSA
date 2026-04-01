// Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự.

// Hãy tìm xâu con đối xứng dài nhất của S.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
// Mỗi test gồm một xâu S có độ dài không vượt quá 1000, chỉ gồm các kí tự thường.
// Output:  Với mỗi test, in ra đáp án tìm được.

// Ví dụ:

// Input

// Output

// 2

// abcbadd

// aaaaa

 

// 5

// 5

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    string s;
    cin >> s;
    s = ' ' + s;
    int n = s.size()-1;

    int maxLen = 1;
    vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0));

    for(int i=1;i<=n;i++){
        dp[i][i] = 1;
        if(i < n){
            dp[i][i+1] = (s[i] == s[i+1]);
            if(dp[i][i+1]){
                maxLen = 2;
            }
        }        
    }

    for(int len = 3 ; len <= n ; len++){
        for(int i = 1 ; i <= n - len + 1 ; i++){
            int j = i + len - 1;
            dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
            if(dp[i][j]){
                maxLen = max(maxLen , len);
            }
        }
    }
    cout << maxLen << endl;
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