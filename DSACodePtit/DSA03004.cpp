// Cho mảng A[] gồm các số từ 0 đến 9. Nhiệm vụ của bạn là tìm tổng nhỏ nhất của hai số được tạo bởi các số trong mảng A[]. Chú ý, tất cả các số trong mảng A[] đều được sử dụng để tạo nên hai số.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số phần tử của mảng N; dòng tiếp theo đưa vào N số A[i] tương ứng với các phần tử của mảng A[]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤20; 0≤A[i]≤9.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví  dụ:

// Input

// Output

// 2
// 6
// 6 8 4 5 2 3
// 5
// 5 3 0 7 4

// 604
// 82

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());

    ll num1 = 0 , num2 = 0;
    for(int i=0;i<n;i++){
        if(i % 2 == 0){
            num1 = num1 * 10 + a[i];
        }
        else{
            num2 = num2 * 10 + a[i];
        }
    }
    cout << num1 + num2 << endl;
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