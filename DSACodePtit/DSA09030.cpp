// Đồ thị hai phía là một đồ thị đặc biệt, trong đó tập các đỉnh có thể được chia thành hai tập không giao nhau thỏa mãn điều kiện không có cạnh nối hai đỉnh bất kỳ thuộc cùng một tập. Cho đồ thị N đỉnh và M cạnh, bạn hãy kiểm tra đồ thị đã cho có phải là một đồ thị hai phía hay không?

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤  20).
// Mỗi test bắt đầu bởi số nguyên N và M (1 ≤  N, M ≤  1000).
// M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
// Output: 

// Với mỗi test, in ra “YES” nếu đồ thị đã cho là một đồ thị hai phía, in ra “NO” trong trường hợp ngược lại.
// Ví dụ:

// Input:

// Output

// 2

// 5 4

// 1 5

// 1 3

// 2 3

// 4 5

// 3 3

// 1 2

// 1 3

// 2 3

// YES

// NO

#include <iostream>
#include <vector>

using namespace std;

#define Max 1000

vector<int> a[Max + 1];
vector<int> color; //1 , 2 là 2 tập
int n;
bool ok;

void dfs(int u){
    for(int x : a[u]){
        if(color[x] == 0){
            color[x] = 3 - color[u];
            dfs(x);
        }
        else if(color[x] == color[u]){
            ok = false;
            return;
        }
    }
}

void testCase(){
    int m;
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        a[i].clear();
    }

    color.assign(n+1 , 0);

    ok = true;

    while(m--){
        int u , v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(color[i] == 0){
            color[i] = 1;
            dfs(i);
        }
    }

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