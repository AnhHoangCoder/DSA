// Cho một mảng S gồm 2×N ký tự, trong đó có N ký tự ‘[’ và N ký tự ‘]’. Xâu S được gọi là viết đúng nếu S có dạng S2[S1] trong đó S, S2 là các xâu viết đúng. Nhiệm vụ của bạn là tìm số các phép đổi chỗ ít nhất các ký tự kề nhau của xâu S viết sai để  S trở thành viết đúng. Ví dụ với xâu S =”[]][][” ta có số phép đổi chỗ kề nhau ít nhất là 2.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu S viết sai theo nguyên tắc kể trên.
// T, S thòa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤100000.
// Output:

// Đưa kết quả trên một dòng.
// Ví dụ:

// Input

// Output

// 2

// []][][

// [][][]

// 2
// 0

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    string s;
    cin >> s;
    int n = s.size();

    vector<int> q;
    for(int i=0;i<n;i++){
        if(s[i] == '['){
            q.push_back(i);
        }
    }

    int open = 0 , close = 0;
    int idx = 0;
    long long ans = 0;

    for(int i=0;i<n;i++){
        if(s[i] == '['){
            open++;
            idx++;
        }
        else{
            close++;
        }

        if(close > open){
            ans += q[idx] - i;
            swap(s[i] , s[q[idx]]);
            idx++;
            open++;
            close--;
        }
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