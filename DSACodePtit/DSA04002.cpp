// Cho mảng số N. Ta gọi số đảo của N là R. Hãy tìm lũy thừa R của N. Đưa ra kết quả của bài toán dưới dạng modulo với 109 + 7.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm là số N được ghi trên một dòng.
// T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤1010.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 2
// 12

// 4
// 864354781

#include <iostream>

using namespace std;
using ll = long long;

const ll mod = 1e9+7;

ll power(ll a , ll b){
    if(b == 0) return 1;

    ll x = power(a , b/2);
    x = (x * x) % mod;
    if(b % 2) x = (x * a) % mod;
    return x;
}

ll reverse(ll n){
    ll r = 0;
    while(n > 0){
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}

void testCase(){
    ll n;
    cin >> n;
    ll inv = reverse(n);
    cout << power(n , inv) << endl;
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