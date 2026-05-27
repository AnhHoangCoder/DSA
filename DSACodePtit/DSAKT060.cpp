// Cho số nguyên S gồm N chữ số. Có Q truy vấn, mỗi truy vấn thuộc một trong hai loại sau:

// q L R: yêu cầu xác định xâu con S[L, L+1, …, R] có phải là một xâu đối xứng hay không?

// c U x: thay đổi kí tự thứ U thành chữ số x.

// Input

// Dòng đầu tiên chứa số nguyên S gồm N kí tự (N  <= 10^5).
// Tiếp theo là số lượng truy vấn Q (Q <= 10^5)
// Q dòng tiếp theo, mỗi dòng gồm một loại truy vấn.
// Output

// Với mỗi truy vấn loại 1, nếu xâu con là một số đối xứng, hãy in ra “YES”, ngược lại in ra “NO”.
// Test ví dụ:

// Input

// Output

// 12345

// 5

// q 1 5

// q 5 5

// c 4 3

// q 3 5

// q 3 4

 

// NO

// YES

// NO

// YES

#include <iostream>

using namespace std;

bool check(string &s , int l , int r){
    l-- , r--;
    
    while(l < r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void testCase(){
    string s;
    cin >> s;

    int q;
    cin >> q;
    while(q--){
        char c;
        int u , x;
        cin >> c >> u >> x;
        if(c == 'q'){
            cout << (check(s , u , x) ? "YES" : "NO") << endl;
        }
        else{
            char tmp = x + '0';
            s[u-1] = tmp;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    testCase();
    return 0;
}