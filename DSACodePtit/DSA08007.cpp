// Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 có nghĩa. Ví dụ số K = 1, 10, 101. Cho số tự nhiên N (N<263). Hãy cho biết có bao nhiêu số BDN nhỏ hơn N. Ví dụ N=100 ta có 4 số BDN bao gồm các số: 1, 10, 11, 100.

// Input:

// Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
// T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một số tự nhiên N.
//             Output:

// Đưa ra kết quả mỗi test theo từng dòng.
//             Ví dụ:

// Input

// Output

// 3

// 10

// 100

// 200

// 2

// 4

// 7

#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

void testCase(){
    ll n;
    cin >> n;

    int cnt = 0;
    queue<ll> q;
    q.push(1);
    
    while(!q.empty()){
        ll num = q.front();
        q.pop();

        if(num > n){
            continue;
        }

        cnt++;

        q.push(num * 10);
        q.push(num * 10 + 1);
    }
    cout << cnt << endl;
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