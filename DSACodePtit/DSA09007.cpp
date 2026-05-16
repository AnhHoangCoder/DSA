// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường đi từ đỉnh sÎV đến đỉnh tÎV trên đồ thị bằng thuật toán BFS. Yêu cầu code bằng danh sách kề.

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào bốn số |V|, |E|, sÎV, tÎV tương ứng với số đỉnh, số cạnh,  đỉnh u, đỉnh v; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra đường đi từ đỉnh s đến đỉnh t của mỗi test theo thuật toán BFS của mỗi test theo khuôn dạng của ví dụ dưới đây. Nếu không có đáp án, in ra -1.
//      Ví dụ:

// Input:

// Output:

// 1

// 6 9 1 6

// 1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6

// 1 2 5 6

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define Max 1000

void testCase(){
    int n , m , s , t;
    cin >> n >> m >> s >> t;
    
    vector<int> a[Max + 1];
    vector<bool> used(n + 1 , false);

    bool check = false;

    while(m--){
        int u , v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    queue<int> q;
    q.push(s);
    used[s] = true;

    vector<int> res(n+1 , -1);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(u == t){
            check = true;
            break;
        }
        for(int x : a[u]){
            if(!used[x]){
                used[x] = true;
                res[x] = u;
                
                q.push(x);
            }
        }
    }

    vector<int> ans;
    int cur = t;

    while(cur != -1){
        ans.push_back(cur);
        cur = res[cur];
    }

    reverse(ans.begin() , ans.end());

    for(int x : ans){
        cout << x << " ";
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