// Cho mảng A[] gồm n phần tử đã được sắp xếp. Hãy đưa ra 1 nếu X có mặt trong mảng A[], ngược lại đưa ra -1.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n, X là số các phần tử của mảng A[] và số X cần tìm; dòng tiếp theo đưa vào n số A[i] (1≤i≤n) các số được viết cách nhau một vài khoảng trống.
// T, n, A, X thỏa mãn ràng buộc: 1≤T≤100; 1≤N, X, A[i] ≤106.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input:

// Output:

// 2 
// 5 16
// 2 4 7 9 16
// 7 98
// 1 22 37 47 54 88 96

// 1
// -1

#include <iostream>

using namespace std;

// O(log(n))
bool binarySearch(int a[] , int n , int x){
    int left = 0 , right = n-1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(a[mid] == x){
            return true;
        }
        else if(a[mid] < x){
            //Tìm ở nửa bên phải
            left = mid + 1;
        }
        else{
            //Tìm ở nửa bên trái
            right = mid - 1;
        }
    }
    return false;
}

void testCase(){
    int n,x;
    cin >> n >> x;

    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    cout << (binarySearch(a , n , x) ? 1 : -1) << endl;
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