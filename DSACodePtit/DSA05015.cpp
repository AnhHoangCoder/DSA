// P(n, k) là số phép biểu diễn các tập con có thứ tự gồm k phần tử của tập gồm n phần tử. Số P(n, k) được định nghĩa theo công thức sau:

// Cho số hai số n, k. Hãy tìm P(n,k) theo modulo 109+7.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một cặp số n, k được viết trên một dòng.
// T, n, k thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ n,k ≤ 1000.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 5 2
// 4 2
 
// 20
// 12

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

void testCase(){
    int n , k;
    cin >> n >> k;
    if(k > n){
        cout << 0 << endl;
        return;
    }
    
    if(k == n){
        cout << 1 << endl;
        return;
    }

    ll res = 1;
    for(int i = 0; i < k; i++){
        res = res * (n - i) % mod;
    }
    cout << res << endl;
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