// Cho số nguyên dương N (2 < N <10). Một số nguyên dương K có N chữ số được gọi là số xa cách nếu thỏa mãn:

// K không chứa chữ số 0
// Tất cả các chữ số từ 1 đến N đều xuất hiện trong K đúng 1 lần
// Không có hai chữ số liên tiếp nào trong K có hiệu bằng 1. 
// Hãy liệt kê tất cả các số thỏa mãn theo thứ tự tăng dần.

// Input

// Dòng đầu ghi số bộ test (không quá 10)
// Mỗi bộ test là 1 số nguyên dương N (2 < N < 10)
// Output

// Liệt kê tất cả các số thỏa mãn, mỗi số trên một dòng.

// Sau mỗi test in ra một khoảng trống.

// Ví dụ

// Input

// 2

// 3

// 4

// Output 

// 2413

// 3142

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> a;
vector<bool> used;

void backTrack(int pos){
    if(pos > n){
        for(int i=1;i<=n;i++){
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for(int i = 1 ; i <= n ; i++){
        if(!used[i]){
            if(pos > 1 && (abs(i - a[pos-1]) == 1)) continue;
            a[pos] = i;
            used[i] = true;
            backTrack(pos + 1);
            used[i] = false;
        }
    }
}

void testCase(){
    cin >> n;
    a.assign(n+1 , 0);
    used.assign(n+1 , false);
    backTrack(1);
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}