// Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một. Hãy liệt kê tất cả các hoán vị của dãy số A[] theo thứ tự tăng dần, tức là hoán vị đầu tiên có giá trị tăng dần từ trái qua phải, hoán vị cuối cùng giảm dần từ trái qua phải.

// Input

// Dòng đầu ghi số N (1 < N < 9)

// Dòng thứ 2 ghi N số của dãy A[] (0 < A[i] < 10000)

// Output

// Ghi mỗi hoán vị của dãy số trên một dòng

// Ví dụ

// Input

// 3

// 88 77 99

// Output

// 77 88 99

// 77 99 88

// 88 77 99

// 88 99 77

// 99 77 88

// 99 88 77

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;
vector<int> b;
vector<bool> used;

void backTrack(int pos){
    if(pos == n){
        for(int i=0;i<n;i++){
            cout << b[a[i] - 1] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            a[pos] = i+1;
            used[i] = true;
            backTrack(pos+1);
            used[i] = false;
        }
    }
}

void testCase(){
    cin >> n;
    a.resize(n);
    b.resize(n);

    used.assign(n , false);
    for(int i=0;i<n;i++){
        a[i] = i+1;
    }
    
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    sort(b.begin() , b.end());
    backTrack(0);
}

int main(){
    testCase();    
    return 0;
}