// Hãy thực hiện thuật toán sắp xếp nổi bọt trên dãy N số nguyên. Ghi ra các bước thực hiện thuật toán.

// Dữ liệu vào: Dòng 1 ghi số N (không quá 100). Dòng 2 ghi N số nguyên dương (không quá 100).

// Kết quả: Ghi ra màn hình từng bước thực hiện thuật toán. Mỗi bước trên một dòng, các số trong dãy cách nhau đúng một khoảng trống.

// Ví dụ:

// Input

// Output

// 4

// 5 3 2 7

// Buoc 1: 3 2 5 7

// Buoc 2: 2 3 5 7

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
        bool check = false;
        for(int j=0;j<n-i-1;j++){
            if(a[j] > a[j+1]){
                check = true;
                swap(a[j] , a[j+1]);
            }
        }
        if(!check) break;
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