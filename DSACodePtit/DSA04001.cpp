// Cho số nguyên dương N và K. Hãy tính NK modulo 109+7.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test gồm 1 số nguyên N và K (1 ≤ N ≤ 1000, 1 ≤ K ≤ 109).

// Output: 

// Với mỗi test, in ra đáp án trên một dòng.

// Ví dụ:

// Input:

// Output

// 2

// 2 3

// 4 2

// 8

// 16

#include <iostream>

using namespace std;
using ll = long long;

const ll mod = 1e9+7;

ll power(int n , int k){
    if(k == 0) return 1;

    ll x = power(n , k/2);
    ll tmp = (x * x) % mod;

    if(k % 2 == 0) return tmp;
    return ((ll)n * tmp) % mod;
}

void testCase(){
    int n,k;
    cin >> n >> k;
    cout << power(n , k) << endl;   
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