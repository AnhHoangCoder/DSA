// Cho một dãy gồm n ( n ≤ 1000) số nguyên dương A1, A2, ..., An và số nguyên dương k (k ≤ 50). Hãy tìm dãy con gồm nhiều phần tử nhất của dãy đã cho sao cho tổng các phần tử của dãy con này chia hết cho k. 

// Input: Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test gồm 2 dòng. Dòng đầu tiên chứa hai số n, k.  Dòng tiếp theo ghi n số của dãy A. Các số đều không vượt quá 100.   

// Output: Gồm 1 dòng duy nhất ghi số lượng phần tử của dãy con dài nhất thoả mãn. Dữ liệu vào luôn đảm bảo sẽ có ít nhất một dãy con có tổng chia hết cho k.

// Ví dụ:

// Input

// Output

// 1

// 10 3
// 2 3 5 7 9 6 12 7 11 15

// 9

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    const int INF = 1e9 + 7;
    vector<int> dp(k , -INF);

    dp[0] = 0;
    for(int x : a){
        vector<int> ndp = dp;
        for(int r = 0; r < k; r++){
            if(dp[r] != -INF){
                int nr = (r + x) % k;
                ndp[nr] = max(ndp[nr] , dp[r] + 1);
            }
        }
        dp = ndp;
    }
    cout << dp[0] << endl;
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