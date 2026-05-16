// Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng, mạng lưới giao thông này được cho bởi mảng C[1…n, 1…n] ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j.

// Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.

// Dữ liệu vào: Dòng đầu tiên là số nguyên n – số thành phố (n ≤ 15); n dòng sau, mỗi dòng chứa n số nguyên thể hiện cho mảng 2 chiều C.

// Kết quả: Chi phí mà người đó phải bỏ ra.

// Ví dụ:

// INPUT

// 4

// 0 20 35 10

// 20 0 90 50

// 35 90 0 12

// 10 50 12 0

// Output

// 117

#include <iostream>
#include <climits>

using namespace std;

#define Max 20

int n;
int a[Max]; // Mảng lưu hành trình
int b[Max]; // Mảng đánh dấu (1 : đi , 0 : chưa đi)
int c[Max][Max]; // Ma trận chi phí
int can; // Chi phí cận
int c_min; // Chi phí nhỏ nhất của 1 cạnh bất kỳ
int fopt; // Chi phí tối ưu(kết quả)

void readData(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> c[i][j];
        }
    }
}

int minMatrix(){
    int Min = INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i != j && Min > c[i][j]){
                Min = c[i][j];
            }
        }
    }
    return Min;
}

void init(){
    c_min = minMatrix();
    fopt = INT_MAX , can = 0 , a[1] = 1;
    for(int i=1;i<=n;i++){
        b[i] = 1;
    }
    b[1] = 0;
}


void Try(int idx){
    for(int i=2;i<=n;i++){
        if(b[i]){
            a[idx] = i;
            b[i] = 0;
            can += c[a[idx-1]][a[idx]];
            if(idx == n){
                int sum = can + c[a[n]][1];
                if(sum < fopt){
                    fopt = sum;                    
                }
            }
            else if(can + (n-idx+1) * c_min < fopt){
                Try(idx+1);
            }
            b[i] = 1;
            can -= c[a[idx-1]][a[idx]];
        }
    }
}

int main(){
    readData();
    init();
    Try(2);
    cout << fopt << endl;
    return 0;
}