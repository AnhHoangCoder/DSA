// Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một.

// Hãy sắp xếp dãy theo thứ tự giảm dần, sau đó liệt kê tất cả các dãy con (đúng thứ tự trước sau) của A[] có tổng các phần tử là số lẻ.

// Các dãy con được liệt kê theo thứ tự từ điển tăng dần.

// Input

// Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

// Dòng đầu ghi số N (2 < N <15)
// Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
// Output

// Với mỗi test, liệt kê tất cả các dãy con có tổng các phần tử là số lẻ theo thứ tự từ điển tăng dần, mỗi dãy con trên một dòng.  

// Ví dụ

// Input

// 1

// 4

// 2 3 4 5

// Output

// 3

// 3 2

// 4 3

// 4 3 2

// 5

// 5 2

// 5 4

// 5 4 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a , tmp;
vector<vector<int>> res;

void Try(int idx , int sum){
    if(sum % 2 != 0){
        res.push_back(tmp);
    }

    for(int i=idx;i<n;i++){
        tmp.push_back(a[i]);
        Try(i+1 , sum + a[i]);
        tmp.pop_back();
    }
}

void testCase(){
    cin >> n;
    a.assign(n , 0);
    tmp.clear();
    res.clear();
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end() , greater<int>());
    Try(0 , 0);
    sort(res.begin() , res.end());
    for(auto &y : res){
        for(int x : y){
            cout << x << " ";
        }
        cout << endl;
    }
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