// Hãy in ra tất cả các xâu nhị phân độ dài N, có K bit 1 theo thứ tự từ điển tăng dần.

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm 2 số nguyên N, K (1 ≤ K ≤ N ≤ 16).

// Output:  Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.

// Ví dụ:

// Input

// 2

// 4 2

// 3 2

// Output

// 0011

// 0101

// 0110

// 1001

// 1010

// 1100

// 011

// 101

// 110

#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;

bool sinh(){
    int i = n;
    while(i > 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i == 0) return false;
    a[i] = 1;
    return true;
}

void test_case(){
    cin >> n >> k;
    a.assign(n+1 , 0);
    do{
        int dem = 0;
        for(int i=1;i<=n;i++){
            if(a[i] == 1) dem++;
        }
        if(dem != k){
            continue;
        }
        for(int i=1;i<=n;i++){
            cout << a[i];
        }
        cout << "\n";
    }while(sinh());
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}