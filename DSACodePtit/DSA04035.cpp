// Cho hai số nguyên không âm a và b. Hãy tính ab.

// Nếu kết quả quá lớn hãy chia dư cho 109 + 7.

// Input

// Gồm không quá 20 bộ test, mỗi test ghi trên một dòng hai số a,b; a không quá 9 chữ số, b không quá 18 chữ số.

// Input kết thúc khi a = b = 0

// Output

// Với mỗi test ghi ra kết quả tính được trên một dòng.

// Ví dụ

// Input

// Output

// 2 3

// 2 4

// 3 2

// 0 0

// 8

// 16

// 9

#include <iostream>

using namespace std;
using ll = long long;

const ll mod = 1e9+7;

ll power(int a , ll b){
    if(b == 0) return 1;

    ll x = power(a , b/2);
    ll tmp = (x * x) % mod ;
    if(b % 2 == 0) return tmp;
    return ((ll)a * tmp) % mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        int a;
        ll b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        
        cout << power(a , b) << endl;
    }
    return 0;
}