// Cho mảng A[] gồm n phần tử, hãy tìm k phần tử lớn nhất của mảng. Các phần tử được đưa ra theo thứ tự giảm dần.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào N và K; dòng tiếp theo đưa vào n số A[i]; các số được viết cách nhau một vài khoảng trống.
// T, N, K, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤K < N ≤103, 1≤A[i] ≤106.
// Output:

// Đưa ra k phần tử lớn nhất trên một dòng.
// Input:

// 2
// 5 3

// 10 7 9 12 6

// 6 2

// 9 7 12 8 6 5

// Output:

// 12 10 9

// 12 9

#include <iostream>
#include <vector>

using namespace std;

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
    for(int i=0;i<k;i++){
        cout << a[n-i-1];
        if(i < k-1) cout << " ";
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