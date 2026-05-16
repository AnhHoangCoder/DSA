// Dãy số Fibonacci được xác định bằng công thức như sau:

// F[0] = 0, F[1] = 1;

// F[n] = F[n-1] + F[n-2] với mọi n >= 2.

// Các phần tử đầu tiên của dãy số là 0, 1, 1, 2, 3, 5, 8, ...

// Nhiệm vụ của bạn là hãy xác định số Fibonaci thứ n. Do đáp số có thể rất lớn, in ra kết quả theo modulo 109+7.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 1000).

// Mỗi test bắt gồm một số nguyên N (1 ≤ N ≤ 109).

// Output: 

// Với mỗi test, in ra đáp án trên một dòng.

// Ví dụ:

// Input:

// Output

// 3

// 2

// 6

// 20

 

// 1

// 8

// 6765

#include <iostream>

using namespace std;
using ll = long long;

const ll mod = 1e9+7;

struct Matrix{
    ll a[3][3];
};

//Tính tích giữa 2 ma trận
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

//Chia và trị tính ma trận A^(n-1)
Matrix powerMatrix(Matrix A , int n){
    if(n == 1) return A;
    
    Matrix x = powerMatrix(A , n / 2);
    if(n % 2 == 0){
        return mulMatrix(x , x);
    }
    return mulMatrix(A , mulMatrix(x , x));
}

void testCase(){
    int n;
    cin >> n;

    if(n < 2){
        cout << n << endl;
        return;
    }

    Matrix A;
    A.a[1][1] = 1 , A.a[1][2] = 1;
    A.a[2][1] = 1 , A.a[2][2] = 0;
    Matrix res = powerMatrix(A , n-1);
    cout << res.a[1][1] << endl;
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