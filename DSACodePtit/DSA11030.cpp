// Cho một cây có N node, gốc tại 1. Có Q truy vấn, mỗi truy vấn yêu cầu bạn tìm khoảng cách giữa hai node u và v.

// Input:

// Dòng đầu tiên là số lượng bộ test T( T≤ 20).

// Mỗi test bắt đầu bằng số nguyên N (1 ≤ N ≤ 1000). N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết node u nối với node v.

// Dòng tiếp theo là số lượng truy vấn Q (1 ≤ Q ≤ 1000). Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên u và v.

// Output: 

// Với mỗi test, in ra Q dòng là đáp án với mỗi truy vấn.

// Test ví dụ:

// Input:

// Output

// 1

// 8

// 1 2

// 1 3

// 2 4

// 2 5

// 3 6

// 3 7

// 6 8

// 5

// 4 5

// 4 6

// 3 4

// 2 4

// 8 5

// 2

// 4

// 3

// 1

// 5

#include <iostream>
#include <vector>

using namespace std;

const int Max = 1005;

vector<int> adj[Max];
int depth[Max];
int parent[Max];

void dfs(int u , int par){
    parent[u] = par;

    for(auto v : adj[u]){
        if(v != par){
            depth[v] = depth[u] + 1;
            dfs(v , u);
        }
    }
}

int lca(int u , int v){
    while(depth[u] > depth[v]){
        u = parent[u];
    }

    while(depth[v] > depth[u]){
        v = parent[v];
    }

    while(u != v){
        u = parent[u];
        v = parent[v];
    }
    return u;
}

void testCase(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        adj[i].clear();
    }

    for(int i = 0 ; i < n - 1 ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0;
    dfs(1 , 0);
    
    int q;
    cin >> q;
    while(q--){
        int u , v;
        cin >> u >> v;

        int p = lca(u , v);

        int dist = depth[u] + depth[v] - 2 * depth[p];
        cout << dist << endl;
    }
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