// Cho mảng A[] gồm n phần tử. Các phần tử của mảng A[] chỉ bao gồm các số 0, 1, 2. Hãy sắp xếp mảng A[] theo thứ tự tăng dần. Ví dụ với A[] = {0, 2, 1, 2, 0} ta kết quả A[] = {0, 0, 1, 2, 2}.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng A[]; dòng tiếp theo là n số A [i] của mảng A []các số được viết cách nhau một vài khoảng trống.
// T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 0≤ A[i] ≤2; 1≤ n ≤106.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input:

// 2
// 5
// 0 2 1 2 0

// 3
// 0 1 0

// Output:

// 0 0 1 2 2

// 0 0 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Radix_sort(vector<int> &a , int n){
    int i , Max = a[0] , b[n] , exp = 1;
    for(int i=1;i<n;i++){
        if(a[i] > Max) Max = a[i];
    }
    while(Max / exp > 0){
        vector<int> bucket(10);
        for(int i=0;i<n;i++){
            bucket[(a[i] / exp) % 10]++;
        }
        for(int i=1;i<10;i++){
            bucket[i] += bucket[i-1];
        }
        for(int i=n-1;i>=0;i--){
            b[--bucket[(a[i] / exp) % 10]] = a[i];
        }
        for(int i=0;i<n;i++){
            a[i] = b[i];
        }
        exp *= 10;
    }
}

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];   
    }
    Radix_sort(a , n);
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i < n-1) cout << " ";
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