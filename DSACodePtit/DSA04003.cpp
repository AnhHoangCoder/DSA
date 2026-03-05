// Cho số nguyên dương n. Hãy cho biết có bao nhiêu dãy số nguyên dương có tổng các phần tử trong dãy bằng n. 

// Dữ liệu vào: dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, mỗi bộ dữ liệu ghi một số nguyên dương n duy nhất không qua 1018. 

// Kết quả: Mỗi bộ dữ liệu ghi ra một số nguyên duy nhất là số dư của kết quả tìm được khi chia cho 123456789.

// Ví dụ:

// Input

// Output

// 1

// 3

// 4

#include <iostream>

using namespace std;
using ll = long long;

const ll mod = 123456789;

ll power(ll a , ll b){
    if(b == 0) return 1;

    ll x = power(a , b/2);
    x = (x * x) % mod;
    if(b % 2) x = (x * a) % mod;
    return x;
}

//với n thì đếm dãy có tổng = n với công thức 2^(n-1)
//3
//3 || 2 + 1 || 1 + 2 || 1 + 1 + 1

void testCase(){
    ll n;
    cin >> n;
    cout << power(2 , n-1) << endl;
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