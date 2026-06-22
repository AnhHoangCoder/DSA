// Cho N cặp số Ai (xi, yi). Cặp (x1, y1) < (x2,y2) nếu như x1 < x2 và y1 < y2.

// Nhiệm vụ của bạn là hãy tìm dãy con tăng dài nhất trên mảng các cặp số này.

// Input:

// Dòng đầu tiên là số nguyên N (N ≤ 100 000).

// N dòng tiếp theo, mỗi dòng gồm 2 số nguyên xi, yi. Các số có giá trị tuyệt đối không vượt quá 109.

// Output: 

// In ra một số nguyên là độ dài dãy con tăng dài nhất tìm được.

 

// Input:

// Output

// 8

// 1 3

// 3 2

// 1 1

// 4 5

// 6 3

// 9 9

// 8 7

// 7 6

// 3

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
    int u , v;
};

void testCase(){
    int n;
    cin >> n;
    vector<Data> a(n);
    for(int i = 0; i < n; i++){
        int u , v;
        cin >> u >> v;
        a[i].u = u;
        a[i].v = v;
    }

    sort(a.begin(), a.end(), [](Data a, Data b){
        if(a.u != b.u) return a.u < b.u;
        return a.v > b.v;
    });

    vector<int> Lis;
    for(auto p : a){
        auto it = lower_bound(Lis.begin(), Lis.end(), p.v);

        if(it == Lis.end()){
            Lis.push_back(p.v);
        }
        else{
            *it = p.v;
        }
    }
    cout << Lis.size() << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        testCase();
    }
    return 0;
}