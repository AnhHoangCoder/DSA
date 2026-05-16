// Cho 2 số nguyên n, k. Bạn hãy tính C(n, k) modulo 109+7.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm 2 số nguyên n, k (1 ≤ k ≤ n ≤ 1000).
// Output: 

// Với mỗi test, in ra đáp án trên một dòng.
// Ví dụ:

// Input

// Output

// 2

// 5 2

// 10 3

 

// 10

// 120

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

void testCase(){
    int n,k;
    cin >> n >> k;
    vector<vector<ll>> c(n+1 , vector<ll> (n+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(j == 0 || j == i){
                c[i][j] = 1;
            }
            else{
                c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
            }
        }
    }
    cout << c[n][k] << endl;
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