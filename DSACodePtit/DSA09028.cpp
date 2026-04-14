// Một trong những bài toán kinh điển của lý thuyết đồ thị là bài toán Tô màu đồ thị. Bài toán được phát biểu như sau: Cho đồ thị vô hướng G =<V, E> được biểu diễn dưới dạng danh sách cạnh và số M. Nhiệm vụ của bạn là kiểm tra xem đồ thị có thể tô màu các đỉnh bằng nhiều nhất M màu sao cho hai đỉnh kề nhau đều có màu khác nhau hay không?

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào ba số V, E, M tương ứng với số đỉnh, số cạnh và số màu; phần thứ hai đưa vào các cạnh của đồ thị.
// T, V, E, M thỏa mãn ràng buộc: 1≤T ≤100; 1≤V≤10; 1≤ E ≤N(N-1), 1≤V≤N.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 4  5  3
// 1 2

// 2 3

// 3 4

// 4 1

// 1 3
// 3 3 2
// 1 2

// 2 3

// 1 3

// YES
// NO

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a[101];
vector<int> color;
int n , m;
bool ok;

bool check(int u , int c){
    for(int v : a[u]){
        if(color[v] == c) return false;
    }
    return true;
}

void dfs(int u){
    if(ok) return;
    
    if(u > n){
        ok = true;
        return;
    }

    for(int i=1;i<=m;i++){
        if(check(u , i)){
            color[u] = i;
            dfs(u+1);
            color[u] = 0;
        }
    }
}

void testCase(){
    int e;
    cin >> n >> e >> m;

    for(int i=1;i<=n;i++){
        a[i].clear();
    }

    color.assign(n+1 , 0);

    ok = false;

    while(e--){
        int u , v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        sort(a[i].begin() , a[i].end());
    }

    dfs(1);

    cout << (ok ? "YES" : "NO") << endl;
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