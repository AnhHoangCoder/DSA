// Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Hãy viết chương trình thực hiện chuyển đổi biểu diễn đồ thị dưới dạng danh sách kề.

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E| +1 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh của đồ thị; |E| dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
// T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
// Output:

// Đưa ra danh sách kề của các đỉnh tương ứng theo khuôn dạng của ví dụ dưới đây. Các đỉnh trong danh sách in ra theo thứ tự tăng dần.
//      Ví dụ:

 

// Input:

// Output:

// 1

// 6  9

// 1  2

// 2  5

// 3  1

// 3  2

// 3  5

// 4  3

// 5  4

// 5  6

// 6  4

// 1: 2

// 2: 5

// 3: 1 2 5

// 4: 3

// 5: 4 6

// 6: 4

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n,m,i,j;
    cin >> n >> m;

    vector<int> a[1001];
    while(m--){
        cin >> i >> j;
        a[i].push_back(j);
    }

    for(int i=1;i<=n;i++){
        cout << i << ": ";
        for(int x : a[i]){
            cout << x << " ";
        }
        cout << endl;
    }
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