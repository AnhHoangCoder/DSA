// Cho một tổ hợp chập K của N số nguyên dương đầu tiên (2 < K < N < 15).

// Hãy xác định xem đó là tổ hợp thứ bao nhiêu nếu liệt kê tất cả các tổ hợp theo thứ tự tăng dần (tính từ 1).

// Input

// Dòng đầu ghi số T là số bộ test (T < 10)

// Mỗi bộ test gồm 2 dòng

// Dòng đầu ghi 2 số nguyên dương N và K (2 < K < N < 15)
// Dòng tiếp theo ghi một tổ hợp chập K của các số nguyên dương từ 1 đến N.  
// Output

// Với mỗi bộ test, ghi ra trên một dòng số thứ tự của tổ hợp (tính từ 1, theo thứ tự liệt kê tăng dần).

// Ví dụ

// Input

// 2

// 6 4

// 1 3 5 6

// 6 4

// 2 3 4 6

// Output

// 9

// 12

#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;

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

bool check(vector<int> &a , vector<int> &b){
    for(int i=1;i<=k;i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

void testCase(){
    cin >> n >> k;
    a.assign(k+1 , 0);

    for(int i=1;i<=k;i++){
        a[i] = i;
    }
    vector<int> b(k+1);
    
    for(int i=1;i<=k;i++){
        cin >> b[i];
    }
    int dem = 0;
    do{
        dem++;
        if(check(a,b)){
            break;
        }
    }while(sinh());
    cout << dem << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}