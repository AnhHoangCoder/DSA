// Cho hai số N, K.

// Ta đã biết sẽ có tất cả C(N,K) tổ hợp của K số tự nhiên trong N số tự nhiên đầu tiên, được đánh số thứ tự từ 1 đến C(N,K).

// Ký hiệu C(N,K) là số tổ hợp chập K của N.

 

// Hãy liệt kê các tổ hợp của K số tự nhiên trong N số tự nhiên đầu tiên và có thứ tự là số nguyên tố.

// Input

// Chỉ có 1 dòng ghi hai số N, K (1 < K < N < 20).

// Output

// Ghi ra các tổ hợp thoả mãn điều kiện bao gồm cả số thứ tự theo mẫu như trong ví dụ dưới đây.

// Ví dụ

// Input

// Output

// 5 3

// 2: 1 2 4

// 3: 1 2 5

// 5: 1 3 5

// 7: 2 3 4

#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;

bool so_nt(int n){
    if(n < 2) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0) return false;
    }
    return true;
}

bool sinh(){
    int i = k;
    while(i > 0 && a[i] == n-k+i) i--;
    if(i == 0) return false;
    a[i]++;
    for(int j=i+1;j<=k;j++){
        a[j] = a[j-1] + 1;
    }
    return true;
}

int main(){
    cin >> n >> k;
    a.resize(k+1);
    for(int i=1;i<=k;i++){
        a[i] = i;
    }
    int dem = 1;
    do{
        if(so_nt(dem)){
            cout << dem << ": ";
            for(int i=1;i<=k;i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        dem++;
    }while(sinh());
    return 0;
}