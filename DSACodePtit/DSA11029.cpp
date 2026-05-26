// Cho một cây có N node, gốc tại 1. Với mỗi node lá, bạn hãy in ra đường đi từ node gốc tới nó.

// Input:

// Dòng đầu tiên là số lượng bộ test T( T≤ 20).

// Mỗi test bắt đầu bằng số nguyên N (1 ≤ N ≤ 1000).

// N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết node u nối với node v.

// Output: 

// Với mỗi test, in ra K dòng, trong đó K là số lượng node lá. Mỗi dòng là đường đi từ node gốc tới node lá X. Node lá nào có nhãn nhỏ hơn, in ra trước.

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

 

// 1 3

// 1 2 4

// 1 2 5

// 1 2 3 4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Max 1000

vector<int> adj[Max + 5];
vector<vector<int>> ans;
vector<int> path;
vector<bool> used;

void dfs(int u){
    used[u] = true;
    path.push_back(u);

    bool isLeaf = true;
    for(auto v : adj[u]){
        if(!used[v]){
            isLeaf = false;
            dfs(v);
        }
    }

    if(isLeaf){
        ans.push_back(path);
    }
    path.pop_back();
}

void testCase(){
    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++){
        adj[i].clear();
    }
    
    ans.clear();
    path.clear();
    used.assign(n+1 , false);
    for(int i = 0 ; i < n-1 ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    sort(ans.begin() , ans.end() , [](vector<int> &a , vector<int> &b){
        return a.back() < b.back();
    });
    for(auto &y : ans){
        for(int x : y){
            cout << x << " ";
        }
        cout << endl;
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