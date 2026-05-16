// Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy đưa ra tất cả các cạnh cầu của đồ thị?

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E| + 1 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; |E| dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra danh sách các cạch cầu của mỗi test theo từng dòng. In ra đáp án theo thứ tự từ điển, theo dạng “a b …” với a < b.
//        Ví dụ:

// Input:

// Output:

// 1

// 5 5

// 1 2 

// 1 3

// 2 3

// 2 5

// 3 4

// 2 5 3 4

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Max 1000

vector<int> a[Max + 1];
int num[Max + 1] , low[Max + 1] , timer;
int n , m;

vector<pair<int,int>> res;

void dfs(int u , int parent){
    num[u] = low[u] = ++timer;

    for(int v : a[u]){
        if(v == parent) continue; //Tránh tạo thành 1 chu trình

        if(!num[v]){
            dfs(v , u);

            low[u] = min(low[u] , low[v]);
            if(low[v] > num[u]){
                res.push_back({min(u , v) , max(u , v)});
            }
        }
        else{
            low[u] = min(low[u] , num[v]);
        }
    }
}

void testCase(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        a[i].clear();
    }

    res.clear();
    for(int i=0;i<m;i++){
        int u , v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    timer = 0;
    for(int i=1;i<=n;i++){
        num[i] = 0;
        low[i] = 0;
    }

    for(int i=1;i<=n;i++){
        if(!num[i]){
            dfs(i , -1);
        }
    }

    sort(res.begin() , res.end());
    for(auto x : res){
        cout << x.first << " " << x.second << " ";
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