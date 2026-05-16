// Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toán duyệt theo chiều sâu bắt đầu tại đỉnh uÎV (DFS(u)=?)

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào ba số |V|, |E|, uÎV tương ứng với số đỉnh, số cạnh và đỉnh bắt đầu duyệt; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra danh sách các đỉnh được duyệt theo thuật toán DFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
//Ví dụ:

// Input:

// Output:

// 1

// 6 9 5

// 1 2 2 5 3 1 3 2 3 5 4 3 5 4 5 6 6 3

// 5 4 3 1 2 6

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Max 1000

vector<int> a[Max + 1];
vector<bool> used;
int n;

void dfs(int u){
    cout << u << " ";
    used[u] = true;

    for(int x : a[u]){
        if(!used[x]){
            dfs(x);
        }
    }
}

void testCase(){
    int m,u;
    cin >> n >> m >> u;

    for(int i=1;i<=n;i++){
        a[i].clear();
    }

    used.assign(n+1 , false);

    for(int k=0;k<m;k++){
        int i,j;
        cin >> i >> j;
        a[i].push_back(j);
    }

    for(int i=1;i<=n;i++){
        sort(a[i].begin() , a[i].end());
    }
    dfs(u);
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