// Cho hai số nguyên lớn N và M có không quá 1000 chữ số. Người ta muốn tính xem liệu có thể lấy ra nhiều nhất bao nhiêu chữ số trong N (không cần liên tiếp) và giữ nguyên thứ tự của nó để tạo ra một số X sao cho ta cũng có thể tìm thấy X trong số M theo cách tương tự.

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm hai dòng, dòng thứ nhất ghi số N, dòng thứ 2 ghi số M.

// Output:  Với mỗi test, hãy in ra số chữ số nhiều nhất có thể của X.

// Ví dụ:

// Input

// Output

// 2

// 144615

// 4976135

// 44

// 88

// 4

// 0

// Giải thích test 1: số X tìm được là 4615.

#include <iostream>
#include <vector>

using namespace std;

int cnt(string a , string b){
    int n = a.size() , m = b.size();
    vector<vector<int>> c(n+1 , vector<int> (m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
            }
            else{
                c[i][j] = max(c[i-1][j] , c[i][j-1]);
            }
        }
    }
    return c[n][m];
}

void testCase(){
    string n , m;
    cin >> n >> m;

    cout << cnt(n , m) << endl;
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