// Cho một hoán vị của N số nguyên dương đầu tiên.

// Hãy xác định xem đó là hoán vị thứ bao nhiêu nếu liệt kê theo thứ tự tăng dần (tính từ 1).

// Input

// Dòng đầu ghi số T là số bộ test (T < 10)

// Mỗi bộ test gồm 2 dòng

// Dòng đầu ghi số nguyên dương N (3 < N < 10)
// Dòng tiếp theo ghi một hoán vị của các số nguyên dương từ 1 đến N.  
// Output

// Với mỗi bộ test, ghi ra trên một dòng số thứ tự của hoán vị (tính từ 1, theo thứ tự liệt kê tăng dần).

// Ví dụ

// Input

// 2

// 4

// 1 4 3 2

// 4

// 1 2 3 4

// Output

// 6

// 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;

bool sinh(){
    int i = n-2;
    while(i>=0 && a[i] > a[i+1]) i--;
    if(i < 0) return false;
    int j = n-1;
    while(a[j] < a[i]) j--;
    swap(a[i] , a[j]);
    reverse(a.begin() + i + 1 , a.end());
    return true;
}

void test_case(){
    cin >> n;
    a.assign(n,0);

    for(int i=0;i<n;i++){
        a[i] = i+1;
    }    
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    int dem = 0;
    do{
        dem++;
        if(a == b){
            break;
        }
    } while (sinh());
    cout << dem << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}