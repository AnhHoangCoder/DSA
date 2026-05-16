// Một phân số đơn vị nếu tử số của phân số đó là 1. Mọi phân số nguyên dương đều có thể biểu diễn thành tổng các phân số đơn vị. Ví dụ 2/3 = 1/2  + 1/6. Cho phân số nguyên dương P/Q bất kỳ (P < Q), hãy biểu diễn phân số nguyên dương thành tổng phân số đơn vị với số hạng tử là ít nhất.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ đôi tử số P và mẫu số Q của phân số nguyên dương được viết trên một dòng.
// T, P, Q thỏa mãn ràng buộc: 1≤T≤100;  1≤P, Q≤100.
// Output:

// Đưa ra đáp án tìm được trên 1 dòng, theo dạng “1/a + 1/b + …”
// Ví dụ:

// Input

// Output

// 2

// 2 3

// 1 3

// 1/2 + 1/6 

// 1/3

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void egypt(ll p , ll q){
    while(1){
        //x là mẫu số nhỏ nhất có thể
        if(q % p == 0){
            cout << "1/" << q / p;
            return;
        }
        ll x = (q + p - 1) / p;//ceil(q / p)

        cout << "1/" << x;

        //cập nhật phân số mới
        p = p * x - q;
        q = q * x;

        if(p != 0){
            cout << " + ";
        }

        ll g = __gcd(p , q);
        p /= g;
        q /= g;
    }
    cout << "1/" << q;
}

void testCase(){
    ll p , q;
    cin >> p >> q;
    egypt(p , q);
    cout << endl;
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