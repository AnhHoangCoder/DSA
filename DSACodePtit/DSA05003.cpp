// Cho ba xâu ký tự X, Y, Z. Nhiệm vụ của bạn là tìm độ dài dãy con chung dài nhất có mặt trong cả ba xâu.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào độ dài xâu X, Y, X; dòng tiếp theo đưa vào ba xâu X, Y, Z.
// T, X, Y, Z thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ size(X), size(Y), size(Z) ≤ 100.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2

// 5 8 13

// geeks geeksfor geeksforgeeks

// 7 6 5

// abcd1e2 bc12ea bd1ea

// 5

// 3

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int x , y , z;
    cin >> x >> y >> z;
    string a , b ,c;
    cin >> a >> b >> c;

    vector<vector<vector<int>>> dp(x + 1 , vector<vector<int>> (y + 1 , vector<int> (z + 1 , 0)));

    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            for(int k=1;k<=z;k++){
                if(a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]){
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                }
                else{
                    dp[i][j][k] = max(dp[i - 1][j][k] , max(dp[i][j - 1][k] , dp[i][j][k - 1]));
                }
            }
        }
    }
    
    cout << dp[x][y][z] << endl;
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