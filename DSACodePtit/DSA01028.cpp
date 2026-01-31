// Cho dãy số A[] có N phần tử. Hãy liệt kê tất cả các tổ hợp chập K của tập các phần tử khác nhau trong A[]. Các tổ hợp cần liệt kê theo thứ tự từ điển (tức là trong mỗi tổ hợp thì giá trị từ nhỏ đến lớn, và tổ hợp sau lớn hơn tổ hợp trước).

// Input

// Dòng đầu ghi hai số N và K.

// Dòng thứ 2 ghi N số của mảng A[]. Các giá trị không quá 1000.

// Dữ liệu đảm bảo số phần tử khác nhau của A[] không quá 20 và K không quá 10.

// Output

// Ghi ra lần lượt các tổ hợp tìm được, mỗi tổ hợp trên một dòng.

// Ví dụ

// Input

// 8 3

// 2 4 4 3 5 1 3 4

// Output

// 1 2 3

// 1 2 4

// 1 2 5

// 1 3 4

// 1 3 5

// 1 4 5

// 2 3 4

// 2 3 5

// 2 4 5

// 3 4 5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> a;
vector<int> res;

void backTrack(int pos){
    if(pos > k){
        for(int i=0;i<k;i++){
            cout << a[res[i+1]-1] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=res[pos-1]+1 ; i <= n-k+pos ; i++){
        res[pos] = i;
        backTrack(pos+1);
    }
}

void testCase(){
    cin >> n >> k;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin() , a.end());
    a.erase(unique(a.begin() , a.end()) , a.end());

    n = a.size();
    res.assign(n+1 , 0);
    backTrack(1);    
}

int main(){
    testCase();
    return 0;
}