// Cho hai số A, B ở hệ cơ số K. Hãy tính tổng hai số đó ở hệ cơ số K.

// Input: Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test ghi 3 số K,A,B.

//             (2≤K≤10; A và B nếu biểu diễn trong hệ cơ số 10 đều nhỏ hơn 109)

// Output: In ra tổng của A và B trong hệ cơ số K

// Ví dụ:

// Input

// Output

// 1

// 2 1 10

// 11

#include <iostream>

using namespace std;
using ll = long long;

ll kTo10(ll n , int k){
    ll res = 0;
    ll p = 1;
    while(n > 0){
        res += (n % 10) * p;
        p *= k;
        n /= 10;
    }
    return res;
}

ll toK(ll n , int k){
    ll res = 0;
    ll p = 1;
    while(n > 0){
        res += (n % k) * p;
        p *= 10;
        n /= k;
    }
    return res;
} 

void testCase(){
    int k;
    ll a , b;
    cin >> k >> a >> b;
    ll ans = kTo10(a , k) + kTo10(b , k);
    cout << toK(ans , k) << endl;
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