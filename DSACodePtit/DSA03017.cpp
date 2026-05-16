// Cho xâu ký tự S. Ta gọi giá trị của xâu S là tổng bình phương số lần xuất hiện mỗi ký tự trong S. Hãy tìm giá trị nhỏ nhất của xâu S sau khi thực hiện K lần loại bỏ ký tự.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là số K; phần thứ hai là một xâu ký tự S được viết trên một dòng.
// T, S, K thỏa mãn ràng buộc: 1≤T≤100;  1≤length(S)≤10000; 1≤K≤1000.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2
// 2

// ABCCBC
// 2

// AAAB

// 6
// 2

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void testCase(){
    int k;
    string s;
    cin >> k >> s;

    vector<int> a(26);
    for(int i=0;i<s.size();i++){
        a[s[i] - 'A']++;
    }

    priority_queue<int> pq;
    for(int x : a){
        if(x > 0){
            pq.push(x);
        }
    }

    while(k-- && !pq.empty()){
        int top = pq.top();
        pq.pop();

        top--;
        if(top > 0) pq.push(top);
    }

    long long sum = 0;

    while(!pq.empty()){
        long long x = pq.top();
        pq.pop();

        sum += (x * x);
    }
    cout << sum << endl;
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