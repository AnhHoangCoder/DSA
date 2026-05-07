// Cho đồ thị có trọng số không âm G=<V, E> được biểu diễn dưới dạng danh sách cạnh trọng số. Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào hai ba số |V|, |E| tương ứng với số đỉnh và uÎV là đỉnh bắt đầu; |E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w tương ứng với một cạnh cùng với trọng số canh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra kết quả của mỗi test theo từng dòng. Kết quả mỗi test là trọng số đường đi ngắn nhất từ đỉnh u đến các đỉnh còn lại của đồ thị theo thứ tự tăng dần các đỉnh.
//      Ví dụ:

// Input:

// Output:

// 1

// 9  12 1

// 1  2   4

// 1  8   8

// 2  3   8

// 2  8   11

// 3  4   7

// 3  6   4

// 3  9   2

// 4  5   9

// 4  6  14

// 5  6  10

// 6  7  2

// 6  9  6

// 0 4 12 19 26 16 18 8 14 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1e9;

void testCase(){
    int V , E , s;
    cin >> V >> E >> s;

    vector<pair<int,int>> adj[V+1];
    while(E--){
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({v , w});
        adj[v].push_back({u , w});
    }

    vector<int> dist(V+1 , inf);
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

    dist[s] = 0;
    pq.push({0 , s});

    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto x : adj[u]){
            int v = x.first;
            int w = x.second;

            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i=1;i<=V;i++){
        cout << dist[i] << " ";
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