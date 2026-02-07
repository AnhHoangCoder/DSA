// Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các số trong mảng A[] có thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số. Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:

// [2, 2, 2, 2], [2, 2, 4], [2, 6], [4, 4], [8].

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và X; dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống.
// T, N, X, A[i] thỏa mãn ràng buộc: 1≤T ≤10; 1≤X, A[i]≤100. N ≤ 20.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng. Mỗi đường tổ hợp được bao bởi cặp ký tự [, ]. Đưa ra -1 nếu không có tổ hợp nào thỏa mãn yêu cầu bài toán.
// Input

// 1
// 4  8

// 2  4  6  8

// Output

// [2 2 2 2] [2 2 4] [2 6] [4 4] [8]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,x;
vector<int> a;
vector<int> res;
bool checkOk;

void backTrack(int sum , int start){
    if(sum > x) return;
    if(sum == x){
        checkOk = true;
        cout << "[";
        for(int i=0;i<res.size();i++){
            cout << res[i];
            if(i < res.size()-1) cout << " ";
        }
        cout << "]";
    }

    for(int i=start;i<n;i++){
        res.push_back(a[i]);
        backTrack(sum + a[i] , i);
        res.pop_back();
    }
}

void testCase(){
    cin >> n >> x;
    a.clear();
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    res.clear();
    checkOk = false;
    backTrack(0 , 0);
    if(!checkOk){
        cout << "-1";
    }
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