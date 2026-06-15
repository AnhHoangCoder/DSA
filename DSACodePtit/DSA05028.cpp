// Cho hai xâu ký tự str1, str2 bao gồm các ký tự in thường và các thao tác dưới đây:

// Insert: chèn một ký tự bất kỳ vào str1.
// Delete: loại bỏ một ký tự bất kỳ trong str1.
// Replace: thay một ký tự bất kỳ trong str1.
// Nhiệm vụ của bạn là đếm số các phép Insert, Delete, Replace ít nhất thực hiện trên str1 để trở thành str2.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ đôi hai xâu str1 và str2.
// T, str1, str2 thỏa mãn ràng buộc: 1≤T≤100;  1≤length(str1),length(str2) ≤100.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 1

// geek gesek

// 1

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    string s1, s2;
    cin >> s1 >> s2;
    
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1 , vector<int> (m + 1));

    for(int i = 0; i <= n; i++){
        dp[i][0] = i;
    }

    for(int j = 0; j <= m; j++){
        dp[0][j] = j;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = 1 + min(dp[i - 1][j - 1] , min(dp[i - 1][j] , dp[i][j - 1]));
            }
        }
    }
    cout << dp[n][m] << endl;
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