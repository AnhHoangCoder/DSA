// Hãy thực hiện thuật toán sắp xếp chọn trên dãy N số nguyên. Ghi ra các bước thực hiện thuật toán.

// Dữ liệu vào: Dòng 1 ghi số N (không quá 100). Dòng 2 ghi N số nguyên dương (không quá 100).

// Kết quả: Ghi ra màn hình từng bước thực hiện thuật toán. Mỗi bước trên một dòng, các số trong dãy cách nhau đúng một khoảng trống.

// Ví dụ:

// Input

// Output

// 4

// 5 7 3 2

// Buoc 1: 2 7 3 5

// Buoc 2: 2 3 7 5

// Buoc 3: 2 3 5 7

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n-1;i++){
        int Min = i;
        for(int j=i+1;j<n;j++){
            if(a[j] < a[Min]){
                Min = j;
            }
        }
        swap(a[i] , a[Min]);
        
        cout << "Buoc " << i+1 << ": ";
        for(int k=0;k<n;k++){
            cout << a[k];
            if(k < n-1) cout << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        testCase();
    }
    return 0;
}