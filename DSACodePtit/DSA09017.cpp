// Một đồ thị N đỉnh là một cây, nếu như nó có đúng N-1 cạnh và giữa 2 đỉnh bất kì, chỉ tồn tại duy nhất 1 đường đi giữa chúng.

// Cho một đồ thị N đỉnh và N-1 cạnh, hãy kiểm tra đồ thị đã cho có phải là một cây hay không?

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
// Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 1000).
// N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
// Output: 

// Với mỗi test, in ra “YES” nếu đồ thị đã cho là một cây, in ra “NO” trong trường hợp ngược lại.
// Ví dụ:
 

// Input

// Output

// 2

// 4

// 1 2

// 1 3

// 2 4

// 4

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
vector<bool> used;
int n;

void dfs(int u){
    used[u] = true;

    for(int x : a[u]){
        if(!used[x]){
            dfs(x);
        }
    }
}

void testCase(){
    cin >> n;
    int m = n-1;

    for(int i=1;i<=n;i++){
        a[i].clear();
    }

    used.assign(n+1 , false);
    while(m--){
        int u , v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1);

    for(int i=1;i<=n;i++){
        if(!used[i]){
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