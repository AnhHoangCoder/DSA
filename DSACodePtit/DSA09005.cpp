// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toán duyệt theo chiều rộng bắt đầu tại đỉnh uÎV (BFS(u)=?)

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào ba số |V|, |E|, uÎV tương ứng với số đỉnh, số cạnh và đỉnh bắt đầu duyệt; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra danh sách các đỉnh được duyệt theo thuật toán BFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
//      Ví dụ:

// Input:

// Output:

// 1
// 6 9 1
// 1 2
// 1 3
// 2 3
// 2 5
// 3 4
// 3 5
// 4 5
// 4 6
// 5 6

// 1 2 3 5 4 6

#include <iostream>
#include <queue>

using namespace std;

#define Max 1000

int n , a[Max][Max];
bool visited[Max];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int u = q.front();
        cout << u << " ";
        q.pop();

        for(int v = 1 ; v <= n ; v++){
            if(a[u][v] == 1 && !visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void testCase(){
    int  m , u , i , j;
    cin >> n >> m >> u;

    for(int i=1;i<=n;i++){
        visited[i] = false;
        for(int j=1;j<=n;j++){
            a[i][j] = 0;
        }
    }
    for(int k=0;k<m;k++){
        cin >> i >> j;
        a[i][j] = 1;
        a[j][i] = 1;    
    }
    bfs(u);
    cout << endl;
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