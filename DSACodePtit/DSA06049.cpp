// Cho mảng A[] gồm n số nguyên dương và số k. Nhiệm vụ của bạn là đếm số các cặp phần tử có hiệu nhỏ hơn k. Ví dụ A[] = {1, 10, 4, 2 }, k=3 ta nhận được kết quả là 2 tương ứng với hiệu các cặp (1, 2), (4, 2).

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n, tương ứng với số phần tử của mảng A[] và số k; dòng tiếp theo là n số A[i] ; các số được viết cách nhau một vài khoảng trống.
// T, n, k, A[i] thỏa mãn ràng buộc: 1 ≤  T  ≤ 100; 1 ≤  n  ≤ 104; 1 ≤  k ≤ 103; 1 ≤  A[i]  ≤ 105.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 4 3
// 1 10 4 2
// 3 5
// 2 3 4

// 2
// 3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

// void countSort(vector<int> &a , int n , int pos){
//     vector<int> cnt(10) , presum(10);

//     for(int i=0;i<n;i++){
//         cnt[(a[i] / pos) % 10]++;
//     }

//     presum[0] = cnt[0];
//     for(int i=1;i<10;i++){
//         presum[i] = cnt[i] + presum[i-1];
//     }

//     vector<int> ans(n);
//     for(int i=n-1;i>=0;i--){
//         ans[presum[(a[i] / pos) % 10]-1] = a[i];
//         presum[(a[i] / pos) % 10]--;
//     }

//     for(int i=0;i<n;i++){
//         a[i] = ans[i];
//     }
// }

// void radixSort(vector<int> &a , int n){
//     int maxx = a[0];
//     for(int i=1;i<n;i++){
//         maxx = max(maxx , a[i]);
//     }
//     for(int pos = 1 ; (maxx / pos) > 0 ; pos*=10){
//         countSort(a , n , pos);
//     }
// }

void testCase(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    sort(a.begin() , a.end());

    ll cnt = 0;
    int l = 0;
    for(int r = 1 ; r < n ; r++){
        while(a[r] - a[l] >= k){
            l++;
        }
        cnt += (r - l);
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