// Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một và một số K < N.

// Hãy liệt kê tất cả các dãy con khác nhau có K phần tử của A[], mỗi dãy đều được sắp xếp theo thứ tự tăng dần.

// Các dãy con được liệt kê lần lượt theo thứ tự từ điển.

// Input

// Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

// Dòng đầu ghi hai số N và K (2 < K < N <15)
// Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
// Output

// Với mỗi test, liệt kê tất cả các dãy con thỏa mãn, mỗi dãy con trên một dòng. 

// Ví dụ

// Input

// Output

// 1

// 4 3

// 3 2 5 4

// 2 3 4

// 2 3 5

// 2 4 5

// 3 4 5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> a , tmp;

void Try(int idx , int start){
    if(idx == k){
        for(int i=0;i<tmp.size();i++){
            cout << tmp[i];
            if(i < tmp.size()-1) cout << " ";
        }
        cout << endl;
        return;
    }
    for(int i=start;i<=n-k+idx;i++){
        tmp.push_back(a[i]);
        Try(idx + 1 , i + 1);
        tmp.pop_back();
    }
}

void testCase(){
    cin >> n >> k;
    a.clear();
    tmp.clear();
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    Try(0 , 0);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}