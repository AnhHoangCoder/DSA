// Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.

// Input:

// Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
// T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
//   Output:

// Dòng đầu tiên là số lượng số lộc phát tìm được. Dòng thứ hai in đáp án theo thứ tự tăng dần.
//   Ví dụ:

// Input

// Output

// 2

// 2

// 3

// 6

// 6 8 66 68 86 88

// 14

// 6 8 66 68 86 88 666 668 686 688 866 868 886 888

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void testCase(){
    int n;
    cin >> n;

    queue<string> q;
    q.push("6");
    q.push("8");

    vector<string> res;
    while(true){
        string s = q.front();
        q.pop();

        res.push_back(s);
        if(s.size() == n){
            break;
        }

        q.push(s + "6");
        q.push(s + "8");
    }

    while(!q.empty()){
        string s = q.front();
        q.pop();

        res.push_back(s);
    }
    cout << res.size() << endl;
    for(string s : res){
        cout << s << " ";
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