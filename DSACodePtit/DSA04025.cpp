// Dãy số nguyên dương vô hạn A[] được định nghĩa một cách đệ quy như sau:

// A[0] = 0
// A[1] = 1;
// A[i] = A[i-1] + A[i-2] với mọi n ≥ 2.
// Cho số nguyên dương N không quá 109. Hãy xác định số thứ N trong dãy A[]. Nếu kết quả quá lớn, hãy in ra theo modulo 109+7.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 1000).
// Mỗi test bắt gồm một số nguyên N (1 ≤ N ≤ 109).
// Output: 

// Với mỗi test, in ra đáp án trên một dòng.
// Ví dụ:

// Input:

// Output

// 2

// 2

// 6

 

// 1

// 8

#include <iostream>

using namespace std;
using ll = long long;

const ll mod = 1e9+7;

struct Matrix{
    ll a[3][3];
};

Matrix mulMatrix(Matrix A , Matrix B){
    Matrix C;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            C.a[i][j] = 0;
            for(int k=1;k<=2;k++){
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
            }
        }
    }
    return C;
}

Matrix powerMatrix(Matrix A , int n){
    if(n == 1){
        return A;
    }

    Matrix x = powerMatrix(A , n/2);
    Matrix tmp = mulMatrix(x , x);
    if(n % 2 == 0) return tmp;
    return mulMatrix(A , tmp);
}

void testCase(){
    int n;
    cin >> n;
    if(n < 3){
        cout << 1 << endl;
        return;
    }
    Matrix A;
    A.a[1][1] = 1 , A.a[1][2] = 1;
    A.a[2][1] = 1 , A.a[2][2] = 0;

    Matrix ans = powerMatrix(A , n-1);
    cout << ans.a[1][1] << endl;
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