// Xâu ký tự S được tạo ra bằng cách bổ sung dần các ký tự chữ cái Tiếng Anh in hoa như sau.

// Bước 1: Chỉ có chữ cái A
// Bước 2: Thêm chữ cái B vào giữa 2 chữ A => S = "ABA"
// Bước 3: Thêm chữ cái C vào giữa 2 xâu đã có ở bước 2: S = "ABACABA"
// Cứ như vậy cho đến bước thứ N (0 < N < 26)

// Hãy xác định ký tự thứ K trong bước biến đổi thứ N là chữ cái gì?

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm số nguyên dương N và K (1 ≤ N ≤ 25, 1 ≤ K ≤ 2N - 1).
// Output: 

// Với mỗi test, in ra đáp án trên một dòng.
// Ví dụ:

// Input:

// Output

// 2

// 3 2

// 4 8

// B

// D

#include <iostream>

using namespace std;
using ll = long long;

ll f[26];

ll solve(int n , ll k){
    if(n == 1) return 1;

    ll mid = f[n-1] + 1;
    if(k == mid){
        return n;
    }
    else if(k < mid){
        return solve(n-1 , k);
    }
    else{
        return solve(n-1 , k - mid);
    }
}

void testCase(){
    int n;
    ll k;
    cin >> n >> k;
    cout << char(solve(n , k) - 1 + 'A') << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    f[1] = 1;
    for(int i=2;i<26;i++){
        f[i] = 2 * f[i-1] + 1;
    }

    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}