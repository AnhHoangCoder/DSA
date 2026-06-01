// Cho mảng A[] gồm N phần tử. Ta gọi cặp nghịch thế của mảng A[] là số các cặp i, j sao cho i<j và A[i]>A[j]. Đối với mảng đã được sắp xếp thì số cặp nghịch thế bằng 0. Mảng đã sắp theo thứ tự giảm dần có số đảo ngược cực đại. Nhiệm vụ của bạn là hãy đưa ra số cặp nghịch thế của mảng A[] gồm N phần tử.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N tương ứng với số phần tử của mảng A[]; phần thứ 2 là N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤106; 1≤A[i]≤1018.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 5
// 2 4 1 3 5

// 5

// 5 4 3 2 1

// 3

// 10

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll mergeSort(vector<ll> &a , int l , int r){
    if(l >= r) return 0;

    int mid = (l + r) / 2;

    ll cnt = 0;
    cnt += mergeSort(a , l , mid);
    cnt += mergeSort(a , mid + 1 , r);

    vector<ll> tmp;
    int i = l , j = mid + 1;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]){
            tmp.push_back(a[i++]);
        }
        else{
            cnt += mid - i + 1;
            tmp.push_back(a[j++]);
        }
    }

    while(i <= mid) tmp.push_back(a[i++]);
    while(j <= r) tmp.push_back(a[j++]);

    for(int k=l;k<=r;k++){
        a[k] = tmp[k - l];
    }

    return cnt;
}

void testCase(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << mergeSort(a , 0 , n - 1) << endl;
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