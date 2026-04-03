// Một bản tin M đã mã hóa bí mật thành các con số theo ánh xạ như sau: ‘A’->1, ‘B’->2, .., ‘Z’->26. Hãy cho biết có bao nhiêu cách khác nhau để giải mã bản tin M. Ví dụ với bản mã M=”123” nó có thể được giải mã thành ABC (1 2 3), LC (12 3), AW(1 23).

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự số M.
// T, M thỏa mãn ràng buộc: 1≤T≤100;  1≤length(M)≤40.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 123
// 2563

// 3
// 2

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int stringToNum(char a , char b){
    return (a - '0') * 10 + (b - '0');
}

void testCase(){
    string s;
    cin >> s;
    int n = s.size();
    vector<ll> dp(n , 0);
    if(s[0] != '0'){
        dp[0] += 1;
    }

    if(n == 1){
        cout << dp[0] << endl;
        return;
    }

    if(s[1] != '0'){
        dp[1] += dp[0];
    }

    int num = stringToNum(s[0] , s[1]);
    if(num >= 10 && num <= 26){
        dp[1] += 1;
    }
    for(int i=2;i<n;i++){
        if(s[i] != '0'){
            dp[i] += dp[i-1];
        }

        num = stringToNum(s[i-1] , s[i]);
        if(num >= 10 && num <= 26){
            dp[i] += dp[i-2];
        }        
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