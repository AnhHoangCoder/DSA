// Kỳ thi ICPC có K đội của PTIT tham gia và đội tuyển đang rất đau đầu không biết chọn các cái tên như thế nào cho các đội. Yêu cầu phải đảm bảo tên không có khoảng trống và không được trùng nhau. Sau khi thảo luận, có N cái tên được đề xuất (có thể bị trùng nhau). Với K<15 và 4 < N < 30.

// Hãy liệt kê tất cả danh sách các tổ hợp K cái tên khác nhau có thể được tạo ra theo thứ tự từ điển.

// Input

// Dòng đầu ghi 2 số N và K.

// Tiếp theo là 1 dòng ghi N cái tên, mỗi cái tên có độ dài không quá 15 và cách nhau một khoảng trống. Tất cả đều là ký tự in hoa.

// Output

// Ghi ra tất cả các tổ hợp tên có thể được lựa chọn theo thứ tự từ điển.

// Tức là các tên trong mỗi tổ hợp liệt kê theo thứ tự từ điển và các tổ hợp cũng được liệt kê theo thứ tự từ điển.

// Ví dụ

// Input

// 6 2

// DONG TAY NAM BAC TAY BAC

// Output

// BAC DONG

// BAC NAM

// BAC TAY

// DONG NAM

// DONG TAY

// NAM TAY

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N , k;
vector<int> a;
vector<string> b;

void backTrack(int pos){
    if(pos > k){
        for(int i=1;i<=k;i++){
            cout << b[a[i] - 1] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=a[pos-1] + 1;i<=N-k+pos;i++){
        a[pos] = i;
        backTrack(pos+1);
    }
}

void testCase(){
    int n;
    cin >> n >> k;
    b.resize(n);

    for(int i=0;i<n;i++){
        cin >> b[i];
    }

    sort(b.begin() , b.end());
    b.erase(unique(b.begin() , b.end()) , b.end()); 
    N = b.size();

    a.assign(N+1 , 0);
    backTrack(1);
}

int main(){
    testCase();
    return 0;
}