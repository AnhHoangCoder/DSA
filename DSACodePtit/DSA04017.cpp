// Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N-1 phần tử. Các phần tử của mảng A[] chỉ khác mảng B[] một phần tử duy nhất. Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[].

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số N; dòng tiếp theo đưa vào N số của mảng A[];dòng tiếp theo đưa vào N-1 số của mảng B[]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤107; 0≤ A[i]≤1018.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 7
// 2 4 6 8 9 10 12
// 2 4 6 8 10 12
// 6
// 3 5 7 9 11 13
// 3 5 7 11 13

// 5
// 4

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

inline void nhap(vector<ll> &a , int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

void testCase(){
    int n;
    cin >> n;
    vector<ll> a(n) , b(n-1);
    nhap(a , n);    
    nhap(b , n-1);

    int i = 0 , j = 0 , cnt = 1;
    while(i < n && j < n-1){
        if(a[i] == b[j]){
            cnt++;
            i++;
            j++;
        }
        else{
            cout << cnt << endl;
            return;
        }
    }
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