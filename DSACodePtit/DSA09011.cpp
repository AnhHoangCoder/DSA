// Cho một bản đồ kích thước N x M được mô tả bằng ma trận A[][].

// A[i][j] = 1 có nghĩa vị trí (i, j) là nổi trên biển. 2 vị trí (i, j) và (x, y) được coi là liền nhau nếu như nó có chung đỉnh hoặc chung cạnh. Một hòn đảo là một tập hợp các điểm (i, j) mà A[i][j] = 1 và có thể di chuyển giữa hai điểm bất kì trong đó.

// Nhiệm vụ của bạn là hãy đếm số lượng đảo xuất hiện trên bản đồ.

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test bắt đầu bởi 2 số nguyên N và M (1 ≤ N, M ≤ 500).

// N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j].

// Output:  Với mỗi test, in ra số lượng hòn đảo tìm được.

// Ví dụ:

// Input:

// Output

// 1

// 5 5

// 1 1 0 0 0

// 0 1 0 0 1

// 1 0 0 1 1

// 0 0 0 0 0

// 1 0 1 0 1

 

// 5

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> a;
vector<vector<bool>> used;

vector<int> di = {0 , 0 , -1 , -1 , -1 , 1 , 1 , 1};
vector<int> dj = {-1 , 1 , -1 , 1 , 0 , -1 , 1 , 0};
int n , m;

// void dfs(int i , int j){
//     used[i][j] = true;

//     for(int u=0;u<8;u++){
//         int ni = i + di[u];
//         int nj = j + dj[u];

//         if(ni >= 0 && ni < n && nj >= 0 && nj < m && !used[ni][nj] && a[ni][nj] == 1){
//             dfs(ni , nj);
//         }
//     }
// }

void bfs(int i , int j){
    queue<pair<int,int>> q;
    q.push({i , j});
    used[i][j] = true;

    while(!q.empty()){
        auto t = q.front();
        q.pop();

        for(int k=0;k<8;k++){
            int u = t.first + di[k];
            int v = t.second + dj[k];
            if(u >= 0 && u < n && v >= 0 && v < m && a[u][v] == 1 && !used[u][v]){
                q.push({u , v});
                used[u][v] = true;
            }
        }
    }
}

void testCase(){
    cin >> n >> m;

    a.assign(n , vector<int> (m));
    used.assign(n , vector<bool> (m , false));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 1 && !used[i][j]){
                cnt++;
                // dfs(i , j);
                bfs(i , j);
            }
        }
    }
    cout << cnt << endl;
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