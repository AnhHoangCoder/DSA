// Cho ma trận A[M][N]. Nhiệm vụ của bạn hãy tìm số bước đi ít nhất dịch chuyển từ vị trí A[1][1] đến vị trí A[M][N]. Biết mỗi bước đi ta chỉ được phép dịch chuyển đến vị trí A[i][j+A[i][j]] hoặc vị trí A[i+A[i][j]][j] bên trong ma trận.

// Input:

// Dòng đầu tiên đưa vào số lượng test T.
// Dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số M, N; phần thứ hai là các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.
// T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T≤100; 1≤M, N, A[i][j]≤103.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng. In ra -1 nếu không tìm được đáp án.
// Ví dụ:

// Input

// Output

// 1

// 3  3

// 2  1  2

// 1  1  1

// 1  1  1

// 2

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void testCase(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n , vector<int> (m));
    vector<vector<bool>> used(n , vector<bool> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    queue<pair<int,int>> q;
    q.push({0 , 0});
    used[0][0] = true;
    int cnt = 0;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto [i,j] = q.front();
            q.pop();

            if(i == n-1 && j == m-1){
                cout << cnt << endl;
                return;
            }

            int ni = i + a[i][j];
            if(ni < n && !used[ni][j]){
                used[ni][j] = true;
                q.push({ni , j});
            }

            int nj = j + a[i][j];
            if(nj < m && !used[i][nj]){
                used[i][nj] = true;
                q.push({i , nj});
            }
        }
        cnt++;
    }
    cout << -1 << endl;
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