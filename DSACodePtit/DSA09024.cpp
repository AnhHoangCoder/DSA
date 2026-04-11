// Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toán duyệt theo chiều rộng bắt đầu tại đỉnh uÎV (BFS(u)=?)

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào ba số |V|, |E|, uÎV tương ứng với số đỉnh, số cạnh và đỉnh bắt đầu duyệt; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra danh sách các đỉnh được duyệt theo thuật toán BFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
//       Ví dụ:

// Input:

// Output:

// 1

// 6  9  1

// 1 2 2 5 3 1 3 2 3 5 4 3 5 4 5 6 6 4

// 1 2 5 4 6 3

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define Max 1000

void testCase(){
    int n,m,u;
    cin >> n >> m >> u;

    vector<int> a[Max + 1];
    vector<bool> used(n+1 , false);

    while(m--){
        int i,j;
        cin >> i >> j;
        a[i].push_back(j);
    }

    queue<int> q;
    q.push(u);
    used[u] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        cout << v << " ";

        for(int x : a[v]){
            if(!used[x]){
                used[x] = true;
                q.push(x);
            }
        }
    }
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