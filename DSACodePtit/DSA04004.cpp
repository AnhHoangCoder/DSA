// Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N-1 phép biến đổi “gấp đôi” dãy số như sau:

// Với dãy số A hiện tại, dãy số mới có dạng A, x, A trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A.

// Ví dụ với 2 bước biến đổi, ta có [1] - [1 2 1] - [1 2 1 3 1 2 1].

// Các bạn hãy xác định số thứ K trong dãy số cuối cùng là bao nhiêu?

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test gồm số nguyên dương N và K (1 ≤ N ≤ 50, 1 ≤ K ≤ 2N - 1).

// Output: 

// Với mỗi test, in ra đáp án trên một dòng.

// Ví dụ:

// Input

// Output

// 2

// 3 2

// 4 8

// 2

// 4

#include <iostream>

using namespace std;
using ll = long long;

ll f[51];

ll solve(int n , ll k){
    if(n == 1) return 1;
    //để ý rằng với mỗi phần tử giữa = số f[của phần tử đấy]
    //vd : index 8 = 8 
    ll mid = f[n-1] + 1;
    if(k == mid) return n;
    else if(k < mid) return solve(n-1 , k);
    return solve(n-1 , k - mid);
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
    
    for(int i=2;i<51;i++){
        f[i] = 2 * f[i-1] + 1;
    }

    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}