// Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy đưa ra tất cả các đỉnh trụ của đồ thị?

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra danh sách các đỉnh trụ của mỗi test  theo từng dòng.
//       Ví dụ:

// Input:

// Output:

// 1

// 5 5

// 1 2 1 3 2 3 2 5 3 4

// 2 3

#include <iostream>
#include <vector>

using namespace std;

#define Max 1000

vector<int> a[Max + 1];
vector<int> num , low;
int n , timer;
vector<bool> check;

void dfs(int u , int parent){
    num[u] = low[u] = ++timer;
    int child = 0;

    for(int x : a[u]){
        if(x == parent) continue;
        if(!num[x]){
            child++;
            dfs(x , u);

            low[u] = min(low[u] , low[x]);
            if(parent != -1 && low[x] >= num[u]){
                check[u] = true;
            }
        }
        else{
            low[u] = min(low[u] , num[x]);
        }
    }
    //Đỉnh đố phải liền kề với 2 đỉnh trở lên 
    if(parent == -1 && child >= 2){
        check[u] = true;
    }
}

void testCase(){
    int m;
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        a[i].clear();
    }

    num.assign(n+1 , 0);
    low.assign(n+1 , 0);
    check.assign(n+1 , false);
    timer = 0;

    while(m--){
        int u , v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1 , -1);

    for(int i=1;i<=n;i++){
        if(check[i]){
            cout << i << " ";
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