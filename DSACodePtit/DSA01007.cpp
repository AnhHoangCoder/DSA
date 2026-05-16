// Xâu ký tự str được gọi là xâu AB nếu mỗi ký tự trong xâu hoặc là ký tự ‘A’ hoặc là ký tự ‘B’. Ví dụ xâu str=”ABBABB” là xâu AB độ dài 6. Nhiệm vụ của bạn là hãy liệt kê tất cả các xâu AB có độ dài n.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên n.
// T, n thỏa mãn ràng buộc: 1≤T≤10; 1≤n≤10.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng. Mỗi xâu cách nhau 1 khoảng trống.
 

// Input

// Output

// 2

// 2

// 3

// AA AB BA BB

// AAA AAB ABA ABB BAA BAB BBA BBB

#include <iostream>
#include <vector>

using namespace std;

int n;
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
    cin >> n;
    a.assign(n+1 , 0);
    do{
        for(int i=1;i<=n;i++){
            cout << ((a[i] == 0) ? 'A' : 'B');
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