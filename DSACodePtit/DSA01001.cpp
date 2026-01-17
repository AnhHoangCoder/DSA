// Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân tiếp theo của X[]. Ví dụ X[] =”010101” thì xâu nhị phân tiếp theo của X[] là “010110”.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.
// T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤103.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input

// Output

// 2

// 010101

// 111111

// 010110

// 000000

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;

void sinh(){
    int i = n-1;
    while(i >= 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if(i < 0) return;
    a[i]++;
}

void test_case(){
    string s;
    cin >> s;
    n = s.size();
    a.assign(n , 0);
    for(int i=0;i<n;i++){
        a[i] = (s[i] - '0');
    }
    sinh();
    for(int i=0;i<n;i++){
        cout << a[i];
    }
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