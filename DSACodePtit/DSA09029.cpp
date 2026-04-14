// Đường đi đơn trên đồ thị có hướng hoặc vô hướng đi qua tất cả các đỉnh của đồ thị mỗi đỉnh đúng một lần được gọi là đường đi Hamilton. Cho đồ thị vô hướng G = <V, E>, hãy kiểm tra xem đồ thị có đường đi Hamilton hay không?

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào hai số V, E tương ứng với số đỉnh, số cạnh của đồ thị; phần thứ hai đưa vào các cạnh của đồ thị.
// T, V, E thỏa mãn ràng buộc: 1≤T ≤100; 1≤V≤10; 1≤ E ≤15.
// Output:

// Đưa ra 1 hoặc 0 tương ứng với test có hoặc không có đường đi Hamilton theo từng dòng.
//            Ví dụ:

// Input

// Output

// 2
// 4 4
// 1 2 2 3 3 4 2 4
// 4 3
// 1 2 2 3 2 4

// 1

// 0

#include <iostream>
#include <vector>

using namespace std;

vector<int> a[101];
vector<bool> used;
int n;
bool ok;

void dfs(int u , int cnt){
    if(ok) return;

    if(cnt == n){
        ok = true;
        return;
    }

    for(int v : a[u]){
        if(!used[v]){
            used[v] = true;
            dfs(v , cnt+1);
            used[v] = false;
        }
    }
}

void testCase(){
    int m;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        a[i].clear();
    }
    used.resize(n+1);
    ok = false;

    while(m--){
        int u , v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        fill(used.begin() , used.end() , false);
        used[i] = true;
        dfs(i , 1);
        if(ok) break;
    }

    cout << (ok ? 1 : 0) << endl;
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