// Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra xâu nhị phân trước của X[]. Ví dụ X[] =”111111” thì xâu nhị phân trước của X[] là “111110”. Với xâu X[] =“000001” thì xâu nhị trước của X[] là “000000”. Chú ý: nếu xâu dữ liệu trong input là xâu đầu tiên thì trước nó sẽ là xâu cuối cùng.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu nhi phân X.
// T, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤length(X)≤103.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// 2

// 010101

// 111111

// Output

// 010100

// 111110

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;

void sinh_truoc(){
    int i = n-1;
    while(i >= 0 && a[i] == 0){
        a[i] = 1;
        i--;
    }
    if(i < 0){
        for(int i=0;i<n;i++){
            a[i] = 1;
        }
        return;
    }
    a[i] = 0;
}

void test_case(){
    string s;
    cin >> s;
    n = s.length();

    a.assign(n , 0);
    for(int i=0;i<n;i++){
        a[i] = (s[i] - '0');
    }
    sinh_truoc();
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