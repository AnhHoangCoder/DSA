// Cho số tự nhiên N. Hãy tìm số nguyên dương X nhỏ nhất được tạo bởi số 9 và số 0 chia hết cho N. Ví dụ với N = 5 ta sẽ tìm ra  X = 90.

// Input:

// Dòng đầu tiên ghi lại số lượng test T (T≤100).
// Những dòng kế tiếp mỗi dòng ghi lại một test. Mỗi test là một số tự nhiên N được ghi trên một dòng (N≤100).
// Output:

// Đưa ra theo từng dòng số X nhỏ nhất chia hết cho N tìm được .
// Ví dụ:

// Input

// Output

// 2

// 5

// 7

// 90

// 9009

#include <iostream>
#include <queue>

using namespace std;

void testCase(){
    int n;
    cin >> n;

    queue<pair<string,int>> q;
    q.push({"9" , 9 % n});

    while(true){
        auto [s , r] = q.front();
        q.pop();

        if(r == 0){
            cout << s << endl;
            break;
        }

        q.push({s + "0" , (r * 10) % n});
        q.push({s + "9" , (r * 10 + 9) % n});
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