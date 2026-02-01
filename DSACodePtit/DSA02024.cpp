// Cho dãy số a[] có n phần tử là các số nguyên dương khác nhau từng đôi một. Hãy liệt kê tất cả các dãy con có từ 2 phần tử trở lên của dãy a[] thỏa mãn tính chất tăng dần.

// Dãy con tạo được bằng cách lấy ra các phần tử trong dãy a[] nhưng vẫn giữ nguyên thứ tự ban đầu.

// Coi mỗi dãy con như một xâu ký tự với các phần tử cách nhau một khoảng trống, hãy liệt kê theo thứ tự từ điển.

// Input

// Dòng đầu ghi số n (không quá 20)
// Dòng thứ 2 ghi n số của dãy a[]. Các số khác nhau từng đôi một và có giá trị không quá 100.
// Output

// Ghi ra lần lượt các dãy con tăng dần theo thứ tự từ điển.

// Ví dụ

// Input

// 4

// 6 3 7 11

// Output

// 3 11

// 3 7

// 3 7 11

// 6 11

// 6 7

// 6 7 11

// 7 11

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a , cur;
vector<string> res;

void backTrack(int start){
    if(cur.size() >= 2){
        string s;
        for(int j=0;j<cur.size();j++){
            s += to_string(cur[j]) + " ";
        }
        res.push_back(s);
    }

    for(int i=start;i<n;i++){
        if(cur.empty() || a[i] > cur.back()){
            cur.push_back(a[i]);
            backTrack(i+1);
            cur.pop_back();     
        }
    }
}

int main(){
    cin >> n;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    backTrack(0);
    sort(res.begin()  , res.end());
    for(string &str : res){
        cout << str << endl;
    }
    return 0;
}