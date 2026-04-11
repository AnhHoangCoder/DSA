// Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy tìm đường đi từ đỉnh sÎV đến đỉnh tÎV trên đồ thị bằng thuật toán DFS.

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào bốn số |V|, |E|, sÎV, tÎV tương ứng với số đỉnh, số cạnh,  đỉnh u, đỉnh v; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra đường đi từ đỉnh s đến đỉnh t của mỗi test theo thuật toán DFS của mỗi test theo khuôn dạng của ví dụ dưới đây. Nếu không có đáp án, in ra -1.
//       Ví dụ:

// Input:

// Output:

// 1

// 6  9  1  6

// 1 2 2 5 3 1 3 2 3 5 4 3 5 4 5 6 6 4

// 1 2 5 6

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Max 1000

vector<int> a[Max + 1];
vector<bool> used;
vector<int> res;
bool check;
int n , t;

void dfs(int s){
    used[s] = true;

    if(s == t){
        check = true;
        return;
    }

    for(int x : a[s]){
        if(!used[x]){
            res[x] = s;
            dfs(x);
        }
    }
}

void testCase(){
    int m,s;
    cin >> n >> m >> s >> t;
    
    check = false;

    for(int i=1;i<=n;i++){
        a[i].clear();
    }

    used.assign(n+1 , false);
    res.assign(n+1 , -1);

    while(m--){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        sort(a[i].begin() , a[i].end());
    }
    dfs(s);

    if(!check){
        cout << -1 << endl;
        return;
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