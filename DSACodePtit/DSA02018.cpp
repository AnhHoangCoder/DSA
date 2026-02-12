// Cho 5 số nguyên dương A, B, C, D, E. Bạn có thể hoán vị các phần tử cho nhau, hãy đặt các dấu biểu thức +, -, * sao cho biểu thức sau đúng:

// [[[A o(1) B] o(2) C] o(3) D] o(4) E = 23

// Trong đó: o(1) … o(4) là các phép toán +, -, *.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test gồm 5 số nguyên dương A, B, C, D, E có giá trị không vượt quá 100.

// Output: Với mỗi test, in ra đáp án tìm được, mỗi xâu in ra trên một dòng.

// Ví dụ:

// Input

// 3

// 1 1 1 1 1

// 1 2 3 4 5

// 2 3 5 7 11

// Output 

// NO

// YES

// YES

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
vector<int> a;
bool isOk;

bool sinh(){
    int i = n-2;
    while(i >= 0 && a[i] >= a[i+1]) i--;
    if(i < 0) return false;
    int j = n-1;
    while(a[j] <= a[i]) j--;
    swap(a[i] , a[j]);
    reverse(a.begin() + i + 1 , a.end());
    return true;
}

void Try(int idx , ll sum){
    if(isOk) return;
    if(idx == n){
        if(sum == 23){
            isOk = true;
        }
        return;
    }
    Try(idx + 1 , sum + a[idx]);   
    Try(idx + 1 , sum - a[idx]);
    Try(idx + 1 , sum * a[idx]);
}

void testCase(){
    n = 5;
    a.assign(n , 0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    isOk = false;
    sort(a.begin() , a.end());

    do{
        Try(1 , a[0]);
    }while(sinh());
    
    if(isOk){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}