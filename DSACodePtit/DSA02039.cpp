// Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các cách phân tích số tự nhiên N thành tổng các số tự nhiên nhỏ hơn hoặc bằng N. Phép hoán vị của một cách được xem là giống nhau. Ví dụ với N = 5 ta có kết quả là: (5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
// T, n thỏa mãn ràng buộc: 1≤T, N≤10.
// Output:

// Dòng đầu tiên là số lượng cách phân tích thỏa mãn. Dòng tiếp theo liệt kê đáp án theo mẫu ví dụ đã cho.
//             Ví dụ:

// Input

// 2

// 4

// 5

// Output

// 5

// (4) (3 1) (2 2) (2 1 1) (1 1 1 1)

// 7

// (5) (4 1) (3 2) (3 1 1) (2 2 1) (2 1 1 1) (1 1 1 1 1)

#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;
int cnt;
vector<string> str;

bool sinh(){
    int i = k;
    while(i>0 && a[i] == 1) i--;
    if(i == 0) return false;
    a[i]--;
    int sum = 0;
    for(int j=1;j<=i;j++){
        sum += a[j];
    }
    k = i;
    int res = n - sum;
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
    cnt = 0;
    str.clear();
    do{
        string tmp = "(";
        for(int i=1;i<=k;i++){
            tmp += to_string(a[i]);
            if(i < k) tmp += " ";   
        }
        tmp += ")";
        cnt++;
        str.push_back(tmp);
        
    }while(sinh());
    cout << cnt << endl;
    for(int i=0;i<cnt;i++){
        cout << str[i];
        if(i < cnt-1) cout << " ";
    }
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