// Cho mảng đã được sắp xếp A[] gồm N phần tử không có hai phần tử giống nhau và số X. Nhiệm vụ của bạn là tìm floor(X). Trong đó, K=floor(X) là phần tử lớn nhất trong mảng A[] nhỏ hơn hoặc bằng X.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số N là số phần tử của mảng A[] và số X; dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤107; 1≤ A[i]≤1018.
// Output:

// Đưa ra vị trí của  floor(X) trong mảng A[] hoặc -1 nếu không tồn tại floor(X) của mỗi test theo từng dòng.
//    Ví dụ:

// Input

// Output

// 3
// 7 0
// 1 2 8 10 11 12 19
// 7 5
// 1 2 8 10 11 12 19
// 7 10
// 1 2 8 10 11 12 19

// -1
// 2

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void testCase(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i] <= x){
            cnt++;
        }
        else{
            break;
        }
    }
    cout << (cnt == 0 ? -1 : cnt) << endl;
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