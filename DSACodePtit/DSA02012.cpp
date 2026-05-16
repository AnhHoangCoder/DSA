// Cho ma trận A[M][N]. Nhiệm vụ của bạn là đếm tất cả các đường đi từ phần tử A[0][0] đến phần tử A[M-1][N-1]. Bạn chỉ được phép dịch chuyển xuống dưới hoặc sang phải phần tử liền kề với vị trí hiện tại.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số M, N tương ứng với số hàng và số cột của ma trận; dòng tiếp theo đưa vào các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.
// T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 1≤M, N, A[i][j]≤100.
// Output:

// Đưa ra số cách di chuyển của mỗi test theo từng dòng.
// Giải thích test 1: Có 3 cách di chuyển là [1 4 5 6], [1 2 5 6] và [1 2 3 6].
 
// Input

// 2

// 2  3

// 1  2  3 

// 4  5  6

// 2  2

// 1  2 

// 3  4

// Output

// 3

// 2

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void testCase(){
    int n , m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin >> x;
        }
    }
    int down = n-1 , right = m-1;
    int total = down + right;
    // Nếu dùng giai thừa thì dễ bị TLE
    // Tổ hợp C(down + right , down) = n/1 + (n-1)/2 +  ... + (n-k+1)/k
    long double res = 1;
    for(int i=1;i<=min(down , right);i++){
        res = res * (total - i + 1) / i;
    }
    cout << (long long)(res + 0.5) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}