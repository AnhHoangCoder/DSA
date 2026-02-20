// Cho mảng A[] gồm n phần tử. Nhiệm vụ của bạn là đưa ra mảng đã được sắp xếp bao gồm các chữ số của mỗi phần tử trong A[]. Ví dụ A[] = {110, 111, 112, 113, 114 }ta có kết quả là {0, 1, 2, 3, 4}.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng A[]; dòng tiếp theo là n số A[i] ; các số được viết cách nhau một vài khoảng trống.
// T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤107; 0≤ A[i] ≤1016.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input:

// 2
// 3
// 131 11 48
// 4
// 111 222 333 446

// Output:

// 1 3 4 8
// 1 2 3 4 6

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void testCase(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<bool> res(10);
    for(int i=0;i<n;i++){
        ll x = a[i];
        while(x > 0){
            res[x % 10] = true;
            x /= 10;
        }
    }
    for(int i=0;i<10;i++){
        if(res[i]){
            cout << i;
            if(i < 9) cout << " ";
        }
    }
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