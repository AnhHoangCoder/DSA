// Trong 8 chữ cái Tiếng Anh đầu tiên (ABCDEFGH) thì có 2 nguyên âm là ‘A’, ‘E’, còn lại là phụ âm.

// Người ta muốn ghép các chữ cái bắt đầu từ chữ cái ‘A’ cho đến chữ cái c (‘D’ <= c <= ‘H’) sao cho mỗi chữ cái được sử dụng đúng một lần và xâu kết quả không có nguyên âm nào bị kẹp giữa bởi hai phụ âm.

// Hãy liệt kê các xâu thỏa mãn theo thứ tự từ điển.

// Input

// Chỉ có một dòng ghi chữ cái c (đảm bảo từ ‘D’ đến ‘H’).

// Output

// Liệt kê các xâu thỏa mãn, mỗi xâu trên một dòng.

// Ví dụ

// Input

// D

// Output

// ABCD

// ABDC

// ACBD

// ACDB

// ADBC

// ADCB

// BCDA

// BDCA

// CBDA

// CDBA

// DBCA

// DCBA

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;
vector<string> res;
vector<bool> used;

bool check(char c){
    return c == 'A' || c == 'E';
}

void backTrack(int pos , string s){
    if(pos > n){
        res.push_back(s);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!used[i]){
            char ch = char('A' + i - 1);

            if(s.size() >= 2){
                char a = s[s.size() - 2];
                char b = s[s.size() - 1];
                char c = ch;

                if(!check(a) && check(b) && !check(c)) continue;
            }
            
            used[i] = true;
            backTrack(pos + 1 , s + ch);
            used[i] = false;
        }
    }
}

int main(){
    char c;
    cin >> c;
    n = c - 'A' + 1;
    a.assign(n+1 , 0);
    used.assign(n+1 , false);
    for(int i=1;i<=n;i++){
        a[i] = i;
    }
    backTrack(1 , "");
    sort(res.begin() , res.end());
    for(string &x : res){
        cout << x << endl;
    }
    return 0;
}