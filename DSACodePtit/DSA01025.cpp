// Vương quốc PTIT sử dụng bảng chữ cái gồm N chữ cái Latinh viết hoa. Quy tắc đặt tên của gia đình Hoàng gia  PTIT là chọn ra K chữ cái (không trùng nhau) và sắp xếp lại theo thứ tự từ điển.

// Hãy liệt kê tất cả các cái tên có thể có của gia đình Hoàng gia PTIT

// Input

// Dòng đầu ghi số bộ test T (không quá 10)
// Mỗi bộ test ghi 2 số N và K (3 < K < N < 16)
// Output

// Với mỗi bộ test, ghi ra tất cả các cái tên có thể được tạo ra, mỗi kết quả viết trên một dòng.
// Ví dụ

// Input

// 1

// 4 2

// Output

// AB

// AC

// AD

// BC

// BD

// CD

#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;

bool sinh(){
    int i = k;
    while(i>0 && a[i] == n-k+i) i--;
    if(i == 0) return false;
    a[i]++;
    for(int j=i+1;j<=k;j++){
        a[j] = a[j-1] + 1;
    }
    return true;
}

void testCase(){
    cin >> n >> k;
    a.assign(n+1 , 0);

    for(int i=1;i<=k;i++){
        a[i] = i;
    }
    do{
        for(int i=1;i<=k;i++){
            cout << char((a[i]-1) + 'A');
        }
        cout << endl;
    }while(sinh());
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}