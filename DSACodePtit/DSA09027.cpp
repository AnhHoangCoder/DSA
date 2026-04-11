// Cho đồ thị vô hướng có N đỉnh và M cạnh. Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh x và y có tồn tại đường đi tới nhau hay không?

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test gồm 2 số nguyên N, M (1 ≤ N, M ≤ 1000).
// M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
// Dòng tiếp là số lượng truy vấn Q (1 ≤ Q ≤ 1000).
// Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên x và y.
// Output:  Với mỗi truy vấn, in ra “YES” nếu có đường đi từ x tới y, in ra “NO” nếu ngược lại.

// Ví dụ:

// Input:

// Output

// 1

// 6 5

// 1 2

// 2 3

// 3 4

// 1 4

// 5 6

// 2

// 1 5

// 2 4

// NO

// YES

#include <iostream>
#include <vector>

using namespace std;

#define Max 1000

vector<int> a[Max + 1];
vector<bool> used;
int n , t;
bool found;

void dfs(int u){
    if(u == t){
        found = true;
        return;        
    }
    for(int x : a[u]){
        if(!used[x]){
            used[x] = true;
            dfs(x);
            if(found) return;
        }
    }
}

void testCase(){
    int m , q;
    cin >> n >> m;
    
    for(int i = 1 ; i <= n ; i++){
        a[i].clear();
    } 

    while(m--){
        int u , v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    cin >> q;
    while(q--){
        int x , y;
        cin >> x >> y;

        used.assign(n + 1 , false);
        found = false;
        t = y;
        dfs(x);
        cout << (found ? "YES" : "NO") << endl;
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