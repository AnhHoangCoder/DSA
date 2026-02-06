// Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các cách phân tích số tự nhiên N thành tổng các số tự nhiên nhỏ hơn hoặc bằng N. Phép hoán vị vủa một cách được xem là giống nhau. Ví dụ với N = 5 ta có kết quả là: (5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
// T, n thỏa mãn ràng buộc: 1≤T, N≤10.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Input

// 2

// 4

// 5

// Output

// (4) (3 1) (2 2) (2 1 1) (1 1 1 1)

// (5) (4 1)  (3 2)  (3 1 1) (2 2 1)  (2 1 1 1)  (1 1 1 1 1)

#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;

bool sinh(){
    int i = k;
    while(i>0 && a[i] == 1) i--;
    if(i == 0) return false;
    a[i]--;
    int sum = 0;
    for(int j=1;j<=i;j++){
        sum += a[j];
    }
    int res = n - sum;
    k = i;
    while(res > a[i]){
        a[++k] = a[i];
        res -= a[i];
    }
    if(res > 0){
        a[++k] = res;
    }
    return true;
}

void testCase(){
    cin >> n;
    a.assign(n+1 , 0);
    k = 1;
    a[k] = n;
    do{
        cout << "(";
        for(int i=1;i<=k;i++){
            cout << a[i];
            if(i < k) cout << " ";
        }
        cout << ") ";
    }while(sinh());
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}