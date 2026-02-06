// Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:

// Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
// Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
// Left (L): Chuột được phép sang trái dưới nếu ô bên trái nó có giá trị 1.
// Up (U): Chuột được phép lên trên nếu ô trên nó có giá trị 1.
// Hãy đưa ra tất cả các hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là kích cỡ của mê cung; dòng tiếp theo đưa vào ma trận nhị phân A[N][N].
// T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤8; 0≤A[i][j] ≤1.
// Output:

// Đưa ra các xâu ký tự được sắp xếp, trong đó mỗi xâu là một đường đi của con chuột trong mê cung. In ra đáp án theo thứ tự từ điển. Đưa ra -1 nếu chuột không đi được đến đích.
// Input

// 3

// 4
// 1 0 0 0

// 1 1 0 1

// 0 1 0 0

// 0 1 1 1

// 4

// 1 0 0 0

// 1 1 0 1

// 1 1 0 0

// 0 1 1 1

// 5

// 1 0 0 0 0

// 1 1 1 1 1

// 1 1 1 0 1

// 0 0 0 0 1

// 0 0 0 0 1

// Output

// DRDDRR

// DDRDRR DRDDRR

// DDRRURRDDD DDRURRRDDD DRDRURRDDD DRRRRDDD

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> a;
vector<vector<bool>> visited;
vector<string> res;
//Right -> down -> left -> up
vector<int> dx = {0 , 1 , 0 , -1};
vector<int> dy = {1 , 0 , -1 , 0};
vector<char> dirLabels = {'R' , 'D' , 'L' , 'U'};

void backTrack(int x , int y , string s){
    visited[x][y] = true;
    if(x == n-1 && y == n-1){
        visited[x][y] = false;
        res.push_back(s);
        return;
    }
    for(int i=0;i<4;i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
            if(a[nx][ny] == 1 && !visited[nx][ny]){
                visited[nx][ny] = true;
                backTrack(nx , ny , s + dirLabels[i]);
            }
        }
    }
    visited[x][y] = false;
}

void testCase(){
    cin >> n;
    a.assign(n , vector<int> (n));
    visited.assign(n , vector<bool> (n , false));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    backTrack(0 , 0 , "");
    if(res.empty() || a[0][0] == 0){
        cout << "-1" << endl;
        return;
    }
    sort(res.begin() , res.end());
    for(string &s : res){
        cout << s << " ";
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