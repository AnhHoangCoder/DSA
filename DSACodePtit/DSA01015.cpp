// Cho số nguyên N. Nhiệm vụ của bạn cần tìm số nguyên X nhỏ nhất là bội của N, và X chỉ chứa hai chữ số 0 và 9.

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10000). Mỗi bộ test chứa số nguyên N trên một dòng (1 ≤ N ≤ 500).

// Output:  Với mỗi test in ra đáp án tìm được trên một dòng.

// Ví dụ:

// Input

// 3

// 2

// 5

// 11

// Output

// 90

// 90

// 99

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void testCase(){
    int n;
    cin >> n;

    vector<bool> visited(n , false);
    vector<int> parent(n , -1); //đóng vai trò như là nơi lữu trữ các phần từ đằng sau n
    vector<char> digit(n);

    int start = 9 % n;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    digit[start] = '9';

    int endState = -1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == 0){
            endState = cur;
            break;
        }
        int next0 = (cur * 10) % n;
        if(!visited[next0]){
            visited[next0] = true;
            parent[next0] = cur;
            digit[next0] = '0';
            q.push(next0);
        }

        int next9 = (cur * 10 + 9) % n;
        if(!visited[next9]){
            visited[next9] = true;
            parent[next9] = cur;
            digit[next9] = '9';
            q.push(next9);
        }
    }

    string ans;
    for(int i = endState ; i != -1 ; i = parent[i]){
        ans.push_back(digit[i]);
    }
    reverse(ans.begin() , ans.end());
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}