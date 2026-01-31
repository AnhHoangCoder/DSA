// Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:

// Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
// Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
// Hãy đưa ra một hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.

                        

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là kích cỡ của mê cung; dòng tiếp theo đưa vào ma trận nhị phân A[N][N].
// T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤10; 0≤A[i][j] ≤1.
// Output:

// Đưa ra tất cả đường đi của con chuột trong mê cung theo thứ tự từ điển. Đưa ra -1 nếu chuột không đi được đến đích.
// Input

// 2

// 4

// 1  0  0  0

// 1  1  0  1 

// 0  1  0  0 

// 1  1  1  1

// 5

// 1 0 0 0 0

// 1 1 1 1 1

// 1 1 0 0 1

// 0 1 1 1 1

// 0 0 0 1 1

// Output

// DRDDRR

// DDRDRRDR DDRDRRRD DRDDRRDR DRDDRRRD DRRRRDDD

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> a;
vector<string> res;

void dfs(int x , int y , string s){
    if(x == n-1 && y == n-1){
        res.push_back(s);
        return;
    }

    if(x < n-1 && a[x+1][y] == 1){
        dfs(x+1 , y , s+"D");
    }

    if(y < n-1 && a[x][y+1] == 1){
        dfs(x , y+1 , s+"R");
    }
}

void testCase(){
    cin >> n;
    a.assign(n , vector<int> (n , 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    if(a[0][0] == 0){
        cout << "-1" << endl;
        return;
    }
    dfs(0,0,"");
    if(res.empty()){
        cout << "-1" << endl;
        return;
    }
    sort(res.begin() , res.end());
    for(auto &x : res){
        cout << x << " ";
    }
    cout << endl;
    res.clear();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}