// Cho số tự nhiên n. Hãy in ra tất cả các số nhị phân từ 1 đến n.

// Input:

// Dòng đầu tiên ghi lại số lượng test T (T≤100).
// Mỗi test là một số tự nhiên n được ghi trên một dòng (n≤10000).
// Output:

// Đưa ra kết quả mỗi test trên một dòng.
// Ví dụ:

// Input

// Output

// 2

// 2

// 5

// 1 10

// 1 10 11 100 101

#include <iostream>
#include <queue>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");

    for(int i=1;i<=n;i++){
        string s = q.front();
        q.pop();

        cout << s << " ";

        q.push(s + "0");
        q.push(s + "1");
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