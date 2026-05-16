// Cho mảng A[] gồm n phần tử và mảng B[] gồm m phần tử. Nhiệm vụ của bạn là hợp nhất hai mảng A[] và B[] để được một mảng mới đã được sắp xếp. Ví dụ A[] = {5, 7, 112, 9, 3, 6, 2 }, B[] = {1, 2, 6, -1, 0, 9} ta có kết quả là C[] = {-1, 1, 0, 2, 3, 5, 6, 6, 7, .

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm ba dòng: dòng đầu tiên đưa vào n, m tương ứng với số phần tử của mảng A[] và B[]; dòng tiếp theo là n số A[i] ; dòng cuối cùng là m số B[i]; các số được viết cách nhau một vài khoảng trống.
// T, n, m, A[i], B[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m ≤106; -108≤ A[i] ≤108.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input:

// Output:

// 1

// 3 3

// 10 5 15

// 20 3 2

// 2 3 5 10 15 20

#include <iostream>
#include <vector>

using namespace std;

inline void nhap(vector<int> &a , int n){
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
}

void merge(vector<int> &a , int left , int mid , int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> l(n1) , r(n2);

    for(int i=0;i<n1;i++){
        l[i] = a[left + i];
    }
    for(int j=0;j<n2;j++){
        r[j] = a[mid + j + 1];
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
        k++;
        i++;
    }

    while(j < n2){
        a[k] = r[j];
        k++;
        j++;
    }
}

void MergeSort(vector<int> &a , int left , int right){
    if(left >= right) return;

    int mid = left + (right - left) / 2;

    MergeSort(a , left , mid);
    MergeSort(a , mid + 1 , right);

    merge(a , left , mid , right);
}

void testCase(){
    int n,m;
    cin >> n >> m;
    vector<int> a;
    nhap(a , n);
    nhap(a , m);
    int end = n + m;
    MergeSort(a , 0 , end-1);
    for(int i=0;i<end;i++){
        cout << a[i];
        if(i < end - 1) cout << " ";
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