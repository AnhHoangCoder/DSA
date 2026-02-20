// Cho mảng A[] gồm n phần tử và số k. Đếm tất cả các cặp phần tử của mảng có tổng bằng k. Ví dụ A[] = {1, 5, 3, 4, 2 }, k = 7 ta có kết quả là 2 cặp (3, 4), (5, 2).

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng A[] và k; dòng tiếp theo là n số A[i] của mảng A[]các số được viết cách nhau một vài khoảng trống.
// T, n, k, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤100; 0≤ k ≤100, 0≤ A[i] ≤103.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input:

// 2
// 5 9 
// 1 5 4 1 2
// 3 2

// 1 1 1

// Output:

// 1
// 3

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void QuickSort(vector<int> &a , int l , int r){
    if(l >= r) return;
    int i = l , j = r;
    int pivot = a[(l+r)/2];
    
    while(i <= j){
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j){
            swap(a[i] , a[j]);
            i++;
            j--;
        }
    }
    QuickSort(a , l , j);
    QuickSort(a , i , r);
}

void testCase(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    QuickSort(a , 0 , n-1);

    ll cnt = 0;
    int l = 0 , r = n-1;
    while(l < r){
        int sum = a[l] + a[r];

        if(sum == k){
            // Case 1 :Tất cả phần từ giữa l và r giống nhau
            if(a[l] == a[r]){
                ll len = r - l + 1;
                cnt += len * (len - 1) / 2;
                break;
            }
            ll left = 1 , right = 1;
            while(l < r-1 && a[l] == a[l+1]){
                left++;
                l++;
            }
            while(r > l+1 && a[r] == a[r-1]){
                right++;
                r--;
            }
            cnt += left * right;

            l++;
            r--;
        }
        else if(sum < k){
            l++;
        }
        else{
            r--;
        }
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