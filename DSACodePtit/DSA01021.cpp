// Cho số nguyên dương (1<N<40) và số nguyên dương K<N. Với 1 tổ hợp chập K phần tử của N, hãy cho biết tổ hợp tiếp theo sẽ có bao nhiêu phần tử mới. Nếu tổ hợp đã cho là cuối cùng thì kết quả là K.  

// Dữ liệu vào: Dòng đầu ghi số bộ test, không quá 20. Mỗi bộ test viết trên hai dòng

// Dòng 1: hai số nguyên dương N và K (K<N)
// Dòng 2 ghi K số của tổ hợp ban đầu. Theo đúng thứ tự tăng dần, không có số nào trùng nhau.
// Kết quả: Với mỗi bộ dữ liệu in ra số lượng phần tử mới.

//  Ví dụ:

// INPUT

// 3

// 5 3

// 1 3 5

// 5 3

// 1 4 5

// 6 4

// 3 4 5 6

// Output

// 1

// 2

// 4

#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;

void sinh(){
    int i = k;
    while(i > 0 && a[i] == n-k+i){
        i--;
    }
    if(i == 0) return;
    a[i]++;
    for(int j=i+1;j<=k;j++){
        a[j] = a[j-1] + 1;
    }
}

void test_case(){
    cin >> n >> k;
    a.assign(k+1 , 0);
    vector<int> check1(n+1 , 0);
    vector<int> check2(n+1 , 0);
    vector<int> old(k+1);

    int dem = 0;
    for(int i=1;i<=k;i++){
        cin >> a[i];
        old[i] = a[i];
    }

    sinh();

    if(old == a){
        cout << k << "\n";
        return;
    }
    
    for(int i=1;i<=k;i++){
        check1[a[i]]++;
        check2[old[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(check1[i] == 1 && check2[i] == 0){
            dem++;
        }
    }
    cout << dem << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}