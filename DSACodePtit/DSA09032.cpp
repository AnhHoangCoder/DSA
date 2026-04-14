// Trường học X có N sinh viên, trong đó có M cặp là bạn bè của nhau. Bạn của bạn cũng là bạn, tức là nếu A là bạn của B, B là bạn của C thì A và C cũng là bạn bè của nhau.

// Các bạn hãy xác định xem số lượng sinh viên nhiều nhất trong một nhóm bạn là bao nhiêu?

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test bắt đầu bởi 2 số nguyên N và M (N, M ≤ 100 000).

// M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v (u #v) cho biết sinh viên u là bạn của sinh viên v.

// Output: 

// Với mỗi test, in ra đáp án tìm được trên một dòng.

// Ví dụ:

// Input:

// Output

// 2

// 3 2

// 1 2

// 2 3

// 10 12

// 1 2

// 3 1

// 3 4

// 5 4

// 3 5

// 4 6

// 5 2

// 2 1

// 7 1

// 1 2

// 9 10

// 8 9

 

// 3

// 7

#include <iostream>
#include <vector>

using namespace std;

#define Max 100000

vector<int> a[Max + 1];
vector<int> color;
int n;

void dfs(int u , int tmp){
    for(int x : a[u]){
        if(color[x] == 0){
            color[x] = tmp;
            dfs(x , tmp);
        }
    }
}

void testCase(){
    int m;
    cin >> n >> m;

    for(int i=1;i<=n;i++){
        a[i].clear();
    }

    color.assign(n+1 , 0);

    while(m--){
        int u , v;
        cin >> u >> v;

        a[u].push_back(v);
        a[v].push_back(u);
    }

    int timer = 1;
    for(int i=1;i<=n;i++){
        if(color[i] == 0){
            color[i] = timer;
            dfs(i , timer);
            timer++;
        }
    }

    vector<int> res(timer , 0);
    for(int i=1;i<=n;i++){
        res[color[i]]++;
    }

    int ans = 0;
    for(int i=1;i<timer;i++){
        ans = max(ans , res[i]);
    }
    cout << ans << endl;
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