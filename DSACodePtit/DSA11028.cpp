// Cho một cây có N node, gốc tại  1. Độ cao của một node u được tính bằng khoảng cách từ u tới node gốc. Độ cao của node gốc bằng 0. Nhiệm vụ của bạn là hãy tìm node xa node gốc nhất và in ra độ cao của node này.

// Input:

// Dòng đầu tiên là số lượng bộ test T( T≤ 20).

// Mỗi test bắt đầu bằng số nguyên N (1 ≤ N ≤ 100 000).

// N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết node u nối với node v.

// Output: 

// Với mỗi test, in ra một số nguyên là độ cao của cây.

// Test ví dụ:

// Input:

// Output

// 2

// 5

// 1 2

// 1 3

// 2 4

// 2 5

// 4

// 1 2

// 2 3

// 3 4

 

// 2

// 3

#include <iostream>
#include <vector>

using namespace std;

#define Max 100000

vector<int> adj[Max + 5];
int ans;

void dfs(int u , int parent , int depth){
    ans = max(ans , depth);

    for(int v : adj[u]){
        if(v != parent){
            dfs(v , u , depth + 1);
        }
    }
}

void testCase(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        adj[i].clear();
    }
    while(--n){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    ans = 0;
    dfs(1 , -1 , 0);
    cout << ans << endl;
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
