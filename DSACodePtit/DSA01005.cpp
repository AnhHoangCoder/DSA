// Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của 1, 2, .., N. Ví dụ với N = 3 ta có kết quả: 123, 132, 213, 231, 312, 321.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
// T, n thỏa mãn ràng buộc: 1≤T, N≤10.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input

// Output

// 2

// 2

// 3

// 12  21

// 123 132  213  231  312  321

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;

//sinh hoán vị
bool sinh(){
    int i = n-1;
    while(i>0 && a[i] > a[i+1]) i--;
    if(i == 0) return false;
    int j = n;
    while(a[j] < a[i]) j--;
    swap(a[i] , a[j]);
    reverse(a.begin() + i + 1 , a.end());
    return true;
}

void test_case(){
    cin >> n;
    a.assign(n+1 , 0);
    for(int i=1;i<=n;i++){
        a[i] = i;
    }
    do{
        for(int i=1;i<=n;i++){
            cout << a[i];
        }
        cout << " ";
    }while(sinh());
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}