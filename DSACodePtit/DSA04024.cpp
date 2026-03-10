// Cho ma trận vuông A kích thước N x N. Nhiệm vụ của bạn là hãy tính ma trận X = AK với K là số nguyên cho trước. Sau đó, tính tổng các phần tử của cột cuối cùng. Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 109+7.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 100).

// Mỗi test bắt gồm một số nguyên N và K (1 ≤ N ≤ 10, 1 ≤ K ≤ 109) là kích thước của ma trận và số mũ.

// Output: 

// Với mỗi test, in ra kết quả của ma trận X.

// Ví dụ:

// Input:

// Output

// 2

// 2 5

// 1 1

// 1 0

// 3 1000000000

// 1 2 3

// 4 5 6

// 7 8 9

// 8

// 581039956

#include <iostream>

using namespace std;
using ll = long long;

const ll mod = 1e9+7;

int n;

struct Matrix{
    ll a[11][11];
};

Matrix mulMatrix(Matrix A , Matrix B){
    Matrix C;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            C.a[i][j] = 0;
            for(int k=1;k<=n;k++){
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
            }
        }
    }
    return C;
}

Matrix powerMatrix(Matrix a , int k){
    if(k == 1) return a;

    Matrix x = powerMatrix(a , k/2);

    Matrix tmp = mulMatrix(x , x);
    if(k % 2 == 0) return tmp;
    return mulMatrix(a , tmp);
}

void testCase(){
    int k;
    cin >> n >> k;

    Matrix A;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> A.a[i][j];
        }
    }

    Matrix ans = powerMatrix(A , k);

    ll sum = 0;
    for(int i=1;i<=n;i++){
        sum = (sum + ans.a[i][n]) % mod;
    }
    cout << sum << endl;
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