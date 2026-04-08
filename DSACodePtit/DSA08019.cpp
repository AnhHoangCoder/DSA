// Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.

// Input:

// Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
// T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
//             Output:

// Dòng đầu tiên là số lượng số lộc phát tìm được. Dòng thứ hai in ra đáp án theo thứ tự giảm dần.
//             Ví dụ:

// Input

// Output

// 2

// 2

// 3

// 6

// 88 86 68 66 8 6

// 14

// 888 886 868 866 688 686 668 666 88 86 68 66 8 6

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    
    deque<string> dq;
    dq.push_back("6");
    dq.push_back("8");

    vector<string> res;
    
    while(true){
        string s = dq.front();
        dq.pop_front();

        res.push_back(s);
        if(s.size() == n) break;

        dq.push_back(s + "6");
        dq.push_back(s + "8");
    }
    while(!dq.empty()){
        string s = dq.front();
        dq.pop_front();

        res.push_back(s);
    }
    cout << res.size() << endl;
    for(int i = res.size() - 1 ; i >= 0 ; i--){
        cout << res[i] << " ";
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