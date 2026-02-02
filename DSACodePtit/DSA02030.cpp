// Cho chữ cái c in hoa (‘A’ < c < ’K’) và số nguyên K (0 < K < (c – ‘A’)).

// Hãy tìm cách  liệt kê tất cả các xâu ký tự khác nhau được tạo ra bởi các chữ cái tính từ ‘A’ đến ký tự c. Các ký tự được phép lặp lại nhưng không tính các xâu là hoán vị của xâu nào đó đã liệt kê trước đó.

// Xem ví dụ để hiểu thêm yêu cầu đề bài.

// Input

// Chỉ có một dòng ghi chữ cái c và số nguyên K thỏa mãn ràng buộc đề bài.

// Output

// Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển, mỗi xâu trên một dòng.

// Ví dụ

// Input

// D 2

// Output

// AA

// AB

// AC

// AD

// BB

// BC

// BD

// CC

// CD

// DD

#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;
vector<int> res;

void backTrack(int pos , int start){
    if(pos == k){
        for(int x : res){
            cout << char(x + 'A');
        }
        cout << endl;
        return;
    }
    for(int i=start;i<n;i++){
        res.push_back(a[i]);
        backTrack(pos+1 , i);
        res.pop_back();
    }
}

int main(){
    char c;
    cin >> c >> k;
    n = (c - 'A') + 1;
    a.assign(n, 0);
    for(int i=0;i<n;i++){
        a[i] = i;
    }
    backTrack(0 , 0);
    return 0;
}