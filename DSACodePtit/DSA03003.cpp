// Cho mảng A[] gồm N phần tử.Nhiệm vụ của bạn là tìm  bằng cách sắp đặt lại các phần tử trong mảng. Chú ý, kết quả của bài toán có thể rất lớn vì vậy bạn hãy đưa ra kết quả lấy modulo với 109+7.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số phần tử của mảng N; dòng tiếp theo đưa vào N số A[i] tương ứng với các phần tử của mảng A[]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N, A[i] ≤107.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 5
// 5 3 2 4 1
// 3
// 1 2 3

// 40
// 8

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

void countSort(vector<ll> &a , int n , ll pos){
    vector<int> cnt(10) , preSum(10);
    for(int i=0;i<n;i++){
        cnt[(a[i] / pos) % 10]++;
    }
    preSum[0] = cnt[0];
    for(int i=1;i<10;i++){
        preSum[i] = preSum[i-1] + cnt[i];
    }

    vector<ll> res(n);
    for(int i=n-1;i>=0;i--){
        int digit = (a[i] / pos) % 10;
        res[preSum[digit]-1] = a[i];
        preSum[digit]--;
    }
    for(int i=0;i<n;i++){
        a[i] = res[i];
    }
}

void RadixSort(vector<ll> &a , int n){
    ll Max = a[0];
    for(int i=1;i<n;i++){
        Max = max(Max , a[i]);
    }
    for(ll pos = 1 ; (Max / pos) > 0 ; pos *= 10){
        countSort(a , n , pos);
    }
}

void testCase(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    RadixSort(a , n);
    
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum = (sum + (a[i] * i) % mod) % mod;
    }
    cout << sum << endl;
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