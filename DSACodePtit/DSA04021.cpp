// Người ta tạo ra một dãy xâu ký tự nhị phân X[] trong đó:

// X[1] = “0”

// X[2] = “1”

// X[i] = X[i-2] + X[i-1] với i>2

// Với phép cộng (+) là phép nối hai xâu với nhau. 

// Cho hai số tự nhiên N và K (1<N<93; K đảm bảo trong phạm vi của xâu X[N]).

// Hãy xác định ký tự thứ K trong xâu X[N] là ký tự ‘0’ hay ký tự ‘1’.

// Input: Dòng 1 ghi số bộ test. Mỗi bộ test ghi trên một dòng 2 số nguyên N và K.

// Output: Ghi ra màn hình kết quả tương ứng với từng bộ test.

// Ví dụ:

// Input

// Output

// 2

// 3 1

// 4 3

// 0

// 1

#include <iostream>

using namespace std;
using ll = long long;

ll f[93];

char solve(int n , ll k){
    if(n == 1) return '0';
    if(n == 2) return '1';

    if(k <= f[n-2]){
        return solve(n-2 , k);
    }
    else{
        return solve(n-1 , k - f[n-2]);
    }
}

void testCase(){
    int n;
    ll k;
    cin >> n >> k;
    cout << solve(n , k) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    f[1] = 1;
    f[2] = 1;
    for(int i=3;i<93;i++){
        f[i] = f[i-1] + f[i-2];
    }

    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}