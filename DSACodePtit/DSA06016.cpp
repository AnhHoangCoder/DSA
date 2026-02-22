// Cho mảng A[] gồm n phần tử và mảng B[] gồm m phần tử. Nhiệm vụ của bạn là tìm tích giữa phần tử lớn nhất của mảng A[] và phần tử nhỏ nhất của mảng B[]. Ví dụ A[] = {5, 7, 112, 9, 3, 6, 2 }, B[] = {1, 2, 6, -1, 0, 9} ta có kết quả là -9 = 9*(-1).

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa vào n, m tương ứng với số phần tử của mảng A[] và B[]; dòng tiếp theo là n số A[i] ; dòng cuối cùng là m số B[i]; các số được viết cách nhau một vài khoảng trống.
// T, n, m, A[i], B[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m ≤106; -108≤ A[i] ≤108.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input:

// Output:

// 2
// 6 6
// 5 7 9 3 6 2
// 1 2 6 -1 0 9
// 6 6

// 1 4 2 3 10 2
// 4 2 6 5 2 9

// -9
// 20

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void testCase(){
    int n,m;
    cin >> n >> m;

    ll numMin = 1e9 , numMax = -1e9;
    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        if(x > numMax){
            numMax = x;
        }
    }

    for(int i=0;i<m;i++){
        ll x;
        cin >> x;
        if(x < numMin){
            numMin = x;
        }
    }

    cout << numMin * numMax << endl;
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