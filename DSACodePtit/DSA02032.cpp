// Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các số trong mảng A[] có thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số. Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:

// {2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}.

// Input: Dòng đầu tiên đưa vào số lượng bộ test T. Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và X; dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống. T, N, X, A[i] thỏa mãn ràng buộc: 1≤T ≤10; 1≤X, A[i]≤100. N ≤ 20.

// Output: Đưa ra kết quả mỗi test theo từng dòng. Đầu tiên là số lượng  tổ hợp thỏa mãn. Mỗi tổ hợp được bao bởi cặp ký tự { } và cách nhau một dấu cách. Đưa ra -1 nếu không có tổ hợp nào thỏa mãn yêu cầu bài toán.

// Ví dụ:

// Input

// 2
// 4  8

// 2  4  6  8

// 2 9

// 10 11

// Output

// 5 {2 2 2 2} {2 2 4} {2 6} {4 4} {8}

// -1

#include <iostream>
#include <vector>

using namespace std;

int n,x;
vector<int> a;
vector<int> tmp;
vector<vector<int>> res;

void backTrack(int start , int sum){
    if(sum > x) return;
    if(sum == x){
        res.push_back(tmp);
        return;
    }
    for(int i=start;i<n;i++){
        if(sum + a[i] <= x){
            tmp.push_back(a[i]);
            backTrack(i , sum + a[i]);
            tmp.pop_back();       
        }
    }
}

void testCase(){
    cin >> n >> x;
    a.clear();
    res.clear();
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    backTrack(0 , 0);
    if(res.empty()){
        cout << "-1" << endl;
        return;
    }
    cout << res.size() << " ";
    for(auto &s : res){
        cout << "{";
        for(int i=0;i<s.size();i++){
            cout << s[i];
            if(i < s.size()-1) cout << " ";
        }
        cout << "} ";
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