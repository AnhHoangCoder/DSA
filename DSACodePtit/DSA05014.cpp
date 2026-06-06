// Catalan Number là dãy số thỏa mãn biểu thức:

// Dưới đây là một số số Catalan với n=0, 1,2,.. : 1, 1, 2, 5, 14, 42, 132, 429,… Cho số tự nhiên N. Nhiệm vụ của bạn là đưa ra số Catalan thứ N.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên n.
// T, n thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ n ≤ 100.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 3
// 5
// 4
// 10

// 42
// 14
// 16796

#include <iostream>
#include <vector>

using namespace std;

vector<int> add(vector<int> &a , vector<int> &b){
    vector<int> res;
    int carry = 0;
    int n = max(a.size() , b.size());

    for(int i = 0; i < n || carry; i++){
        int x = carry;
        if(i < a.size()) x += a[i];
        if(i < b.size()) x += b[i];
        
        res.push_back(x % 10);
        carry = x / 10;
    }
    return res;
}

vector<int> mul(vector<int> &a , vector<int> &b){
    vector<int> res(a.size() + b.size() , 0);

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            res[i + j] += a[i] * b[j];
        }
    }

    for(int i = 0; i < res.size(); i++){
        if(res[i] >= 10){
            if(i + 1 == res.size()) res.push_back(0);
            res[i + 1] += res[i] / 10;
            res[i] %= 10;
        }
    }

    while(res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

void testCase(){
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1);
    dp[0] = {1};
    for(int i = 1; i <= n; i++){
        dp[i].clear();
        for(int j = 0; j < i; j++){
            vector<int> tmp = mul(dp[j] , dp[i - j - 1]);
            dp[i] = add(dp[i] , tmp);
        }
    }

    for(int i = dp[n].size() - 1; i >= 0; i--){
        cout << dp[n][i];
    }
    cout << endl;
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