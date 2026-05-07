// Bài làm tốt nhất
// Cho đồ thị vô hướng có trọng số G=<V, E, W>. Nhiệm vụ của bạn là hãy xây dựng một cây khung nhỏ nhất của đồ thị bằng thuật toán Kruskal.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào hai số V, E tương ứng với số đỉnh và số cạnh của đồ thị; phần thứ 2 đưa vào E cạnh của đồ thị, mỗi cạnh là một bộ 3: đỉnh đầu, đỉnh cuối và trọng số của cạnh.
// T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤V≤100; 1≤E, W≤10000.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 3 3
// 1 2 5

// 2 3 3

// 1 3 1
// 2 1
// 1 2 5

// 4
// 5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int u , v , w;
};

bool cmp(Edge a , Edge b){
    return a.w < b.w;
}

int parent[10005];

//Tìm tập hợp
int Find(int u){
    if(parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u , int v){
    u = Find(u);
    v = Find(v);

    if(u == v) return false;

    parent[u] = v;
    return true;
}

void testCase(){
    int n , m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for(int i=0;i<m;i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin() , edges.end() , cmp);

    for(int i=1;i<=n;i++){
        parent[i] = i;
    }

    int res = 0;
    for(auto e : edges){
        if(Union(e.u , e.v)){
            res += e.w;
        }
    }
    cout << res << endl;
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