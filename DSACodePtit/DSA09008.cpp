// Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy tìm số thành phần liên thông của đồ thị.

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra số thành phần liên thông của đồ thị.
//       Ví dụ:

// Input:

// Output:

// 2

// 5 6 

// 1 2 1 3 2 3 3 4 3 5 4 5

// 4 2

// 1 2 3 4

 

// 1

// 2

#include <iostream>
#include <vector>

using namespace std;

#define Max 1000

vector<int> a[Max + 1];
vector<bool> used;

void dfs(int u){
    used[u] = true;
    for(int x : a[u]){
        if(!used[x]){
            dfs(x);
        }
    }    
}

int cnt(int n){
    int res = 0;
    for(int i=1;i<=n;i++){
        if(!used[i]){
            res++;
            dfs(i);
        }
    }
    return res;
}

void testCase(){
    int n,m,u,v;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        a[i].clear();
    }
    used.assign(n+1 , false);
    
    for(int i=0;i<m;i++){
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    } 

    int count = cnt(n);
    cout << count << endl;
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