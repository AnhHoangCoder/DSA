// Cho ai, ci , W, N (i =1, 2,..,N; N£100) là những số nguyên dương  và tập hợp

// Hãy viết chương trình tìm phương án tối ưu XOPT =(x1,x2,..,xN) và giá trị tối ưu FOPT=F(XOPT) của hàm mục tiêu

//       Dữ liệu vào cho bởi file data.in theo khuôn dạng sau:

// Dòng đầu tiên ghi lại số tự nhiên N và W. Hai số được viết cách nhau một vài khoảng trống;
// Dòng kế tiếp ghi lại N số cj (j=1,2,..,N). Hai số được viết cách nhau một vài khoảng trống;
// Dòng kế tiếp ghi lại N số aj (j=1,2,..,N). Hai số được viết cách nhau một vài khoảng trống;
// Giá trị tối ưu FOPT và phương án XOPT tìm được sẽ liệt kê trên màn hình theo khuôn dạng:

// Dòng đầu tiên ghi lại giá trị tối ưu FOPT;
// Dòng kế tiếp ghi lại phương án tối ưu XOPT. Hai phần tử khác nhau của phương án tối ưu được viết cách nhau bởi một khoảng trống.
// Ví dụ sau sẽ minh họa khuôn dạng cho file data.in  của bài toán.

//                   data.in                                                                           

// 4                      10                               

// 6          5          3          7    

// 5          4          6          5

#include <iostream>
#include <algorithm>

using namespace std;

#define Max 101

int n;
int a[Max] , c[Max] , xopt[Max] , x[Max];
int w , weight = 0;
int g = 0 , FOPT = 0;

inline void nhap(int a[]){
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
}

void Branch(int i){
    for(int j=1;j>=0;j--){
        x[i] = j;
        weight += a[i] * x[i];
        if(weight <= w){
            g += c[i] * x[i];
            if(i == n){
                if(g > FOPT){
                    FOPT = g;
                    for(int i=1;i<=n;i++){
                        xopt[i] = x[i];
                    }
                }
            }
            else{
                double ub = g + (double)c[i+1] / (double)a[i+1] * double(w - weight);
                if(ub > FOPT){
                    Branch(i+1);
                }
            }
            g -= c[i] * x[i];
        }
        weight -= a[i] * x[i];
    }
}

int main(){
    cin >> n >> w;
    nhap(c);
    nhap(a);
    int idx[Max];
    for(int i=1;i<=n;i++){
        idx[i] = i;
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(1.0 * c[i] / a[i] < 1.0 * c[j] / a[j]){
                swap(a[i] , a[j]);
                swap(c[i] , c[j]);
                swap(idx[i] , idx[j]);
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        x[i] = 0;
        xopt[i] = 0;
    }

    Branch(1);

    cout << FOPT << endl;
    int ans[Max] = {0};
    for(int i=1;i<=n;i++){
        ans[idx[i]] = xopt[i];
    }
    for(int i=1;i<=n;i++){
        cout << ans[i] << (i == n ? "\n" : " ");
    }
    return 0;
}