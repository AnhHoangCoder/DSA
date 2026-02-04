// Số nhị phân được xem là cách mặc định biểu diễn các số. Tuy nhiên, trong nhiều ứng dụng của điện tử và truyền thông lại dùng một biến thể của mã nhị phân đó là mã Gray. Mã Gray độ dài n có mã đầu tiên là n số 0, mã kế tiếp của nó là một xâu nhị phân độ dài n khác biệt với xâu trước đó một bít. Ví dụ với n=3 ta có 23 mã Gray như sau: 000, 001, 011, 010, 110, 111, 101, 100. Hãy viết chương trình liệt kê các mã Gray có độ dài n.

// Input:

// Dòng đầu tiên là số lượng test T.
// T dòng kế tiếp ghi lại mỗi dòng một test. Mỗi test là một số tự nhiên n.
// T, n thỏa mãn ràng buộc: 1≤T, n≤10.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
 

// Input:

// 2

// 3

// 4

// Output:

// 000 001 011 010 110 111 101 100

// 0000 0001 0011 0010 0110 0111 0101 0100 1100 1101 1111 1110 1010 1011 1001 1000

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> res;
set<vector<int>> used;

bool backTrack(vector<int> &cur){
    if(res.size() == (1 << n)) return true;
    for(int i=n-1;i>=0;i--){
        cur[i] ^= 1;
        if(!used.count(cur)){
            used.insert(cur);
            res.push_back(cur);

            if(backTrack(cur)) return true;

            res.pop_back();
            used.erase(cur);
        }
        cur[i] ^= 1;
    }
    return false;
}

void testCase(){
    cin >> n;
    
    vector<int> start(n , 0);
    res.push_back(start);
    used.insert(start);

    backTrack(start);
    
    for(auto x : res){
        for(int &bit : x){
            cout << bit;
        }
        cout << " ";
    }
    cout << endl;
    res.clear();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        testCase();
    }
    return 0;
}