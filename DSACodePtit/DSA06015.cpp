// Cho mảng A[] gồm N phần tử chưa được sắp xếp. Nhiệm vụ của bạn là sắp xếp các phần tử của mảng A[] theo thứ tự tăng dần bằng thuật toán Merge Sort.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N tương ứng với số phần tử của mảng A[]; phần thứ 2 là N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
// T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N, A[i]≤106.
// Output:

// Đưa ra kết quả các test theo từng dòng.
// Input

// Output

// 2
// 5
// 4 1 3 9 7
// 10
// 10 9 8 7 6 5 4 3 2 1

// 1 3 4 7 9
// 1 2 3 4 5 6 7 8 9 10

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a , int left , int mid , int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> l(n1);
    vector<int> r(n2);

    for(int i=0;i<n1;i++){
        l[i] = a[left + i];
    }
    for(int i=0;i<n2;i++){
        r[i] = a[mid + i + 1];
    }

    int i = 0 , j = 0 , k = left;
    
    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            a[k] = l[i];
            i++;
        }
        else{
            a[k] = r[j];
            j++;
        }
        k++;
    }
    
    while(i < n1){
        a[k] = l[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &a , int left , int right){
    if(left >= right) return;

    //Tránh tràn số nếu dùng (left + right ) / 2
    int mid = left + (right - left) / 2;

    mergeSort(a , left , mid);
    mergeSort(a , mid+1 , right);

    merge(a , left , mid , right);
}

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    mergeSort(a , 0 , n-1);
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