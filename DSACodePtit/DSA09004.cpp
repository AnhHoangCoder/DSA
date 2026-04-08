// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toán duyệt theo chiều sâu bắt đầu tại đỉnh uÎV (DFS(u)=?)

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E| +1 dòng: dòng đầu tiên đưa vào ba số |V|, |E| tương ứng với số đỉnh và số cạnh của đồ thị, và u là đỉnh xuất phát; |E| dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra danh sách các đỉnh được duyệt theo thuật toán DFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
//       Ví dụ:

// Input:

// Output:

// 1

// 6 9 5

// 1 2

// 1 3

// 2 3

// 2 4

// 3 4

// 3 5

// 4 5

// 4 6

// 5 6

// 5 3 1 2 4 6

#include <iostream>
#include <vector>

using namespace std;

#define Max 1000

vector<vector<int>> a;
vector<bool> used;
int n;

void dfs(int pos){
    cout << pos << " ";
    used[pos] = true;
    for(int i=1;i<=n;i++){
        if(a[pos][i] && !used[i]){
            used[i] = true;
            dfs(i);
        }
    }
}

void testCase(){
    int v , e , u , j , k;
    cin >> v >> e >> u;
    n = v;  
    a.assign(v+1 , vector<int> (v+1));
    used.assign(v+1 , false);

    for(int i=0;i<e;i++){
        cin >> j >> k;

        a[j][k] = 1;
        a[k][j] = 1;
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