// Cho dãy A[] gồm N số tự nhiên khác nhau và số tự nhiên K. Hãy viết chương trình liệt kê tất cả các dãy con của dãy số A[] sao cho tổng các phần tử trong dãy con đó đúng bằng K. Dữ liệu vào trên bàn phím (n=5, K=50), 5 số dòng thứ 2 là các phần tử dãy A:

//    5                      50       

//    5                      10                    15                    20                    25   

// Các dãy con thoả mãn điều kiện tìm được liệt kê trên màn hình:

// Mỗi dòng ghi lại một dãy con. Hai phần tử khác nhau của dãy con được viết cách nhau bởi một  khoảng trống.
// Dòng cuối cùng ghi lại số các dãy con có tổng các phần tử đúng bằng K tìm được.
//            10                    15                    25

//            5                      20                    25

//           5                      10                    15                    20

//            3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> a , tmp;
vector<vector<int>> res;

void backtrack(int idx , int sum){
    if(sum == k){
        res.push_back(tmp);
        return;
    }
    if(idx == n || sum > k) return;
    tmp.push_back(a[idx]);
    backtrack(idx + 1 , sum + a[idx]);
    tmp.pop_back();

    backtrack(idx + 1 , sum);
}

int main(){
    cin >> n >> k;
    a.resize(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    backtrack(0,0);

    reverse(res.begin() , res.end());
    for(auto &v : res){
        for(int i=0;i<v.size();i++){
            cout << v[i];
            if(i+1 < v.size()) cout << " ";
        }
        cout << endl;
    }
    cout << res.size() << endl;
    return 0;
}