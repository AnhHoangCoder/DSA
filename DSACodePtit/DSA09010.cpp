// Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có liên thông mạnh hay không?

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; Dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra “YES”, hoặc “NO” theo từng dòng tương ứng với test là liên thông mạnh hoặc không liên thông mạnh.
//       Ví dụ:

// Input:

// Output:

// 1

// 6 9 

// 1 2 2 4 3 1 3 2 3 5 4 3 5 4 5 6 6  3

// YES

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Max 1000

void dfs(int u , vector<int> a[] , vector<bool> &used){
    used[u] = true;
    for(int x : a[u]){
        if(!used[x]){
            dfs(x , a , used);
        }
    }
}

void testCase(){
    int n , m;
    cin >> n >> m;

    vector<int> adj[Max + 1] , adj_rev[Max + 1];
    vector<bool> used(n+1 , false) , used_rev(n+1 , false);

    while(m--){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }    

    dfs(1 , adj , used);
    dfs(1 , adj_rev , used_rev);

    for(int i=1;i<=n;i++){
        if(!used[i] || !used_rev[i]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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