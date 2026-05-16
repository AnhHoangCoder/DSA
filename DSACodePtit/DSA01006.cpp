// Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của 1, 2, .., N theo thứ tự ngược. Ví dụ với N = 3 ta có kết quả: 321, 312, 231, 213, 132, 123.

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

// 21 12 

// 321 312 231 213 132 123

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;
vector<bool> used;

void back_track(int i){
    if(i > n){
        for(int i=1;i<=n;i++){
            cout << a[i];
        }
        cout << " ";
        return;
    }
    for(int j=n;j>0;j--){
        if(!used[j]){
            a[i] = j;
            used[j] = true;
            
            back_track(i+1);

            used[j] = false;
        }
    }
}

void test_case(){
    cin >> n;
    a.assign(n+1 , 0);
    used.assign(n+1 , false);
    back_track(1);
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