// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh,  số cạnh của đồ thị; Dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra YES hoặc “NO” kết quả test theo từng dòng tương ứng với đồ thị tồn tại hoặc không tồn tại chu trình.
//       Ví dụ:

// Input:

// Output:

// 1

// 6  9

// 1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6

// YES

#include <iostream>
#include <vector>

using namespace std;

#define Max 1000

vector<int> a[Max + 1];
vector<bool> used;
int n;
bool check;

void dfs(int u , int parent){
    used[u] = true;

    for(int x : a[u]){
        if(!used[x]){
            dfs(x , u);
        }
        else if(x != parent){
            check = true;
            return;
        }

        if(check){
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

    used.assign(n+1 , false);
    check = false;

    while(m--){
        int u , v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!used[i]){
            dfs(i , -1);
        }
    }

    cout << (check ? "YES" : "NO") << endl;
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