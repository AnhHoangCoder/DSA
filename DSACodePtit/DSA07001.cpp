// Cho một ngăn xếp các số nguyên. Các thao tác gồm 3 lệnh: push, pop và show. Trong đó thao tác push kèm theo một giá trị cần thêm (không quá 1000). Hãy viết chương trình ghi ra kết quả của các lệnh show.

// Input: Gồm nhiều dòng, mỗi dòng chứa một lệnh push, pop hoặc show. Input đảm bảo số lượng phần tử trong stack khi nhiều nhất cũng không vượt quá 200.

// Output: Ghi ra màn hình các phần tử đang có trong stack theo thứ tự lưu trữ mỗi khi gặp lệnh show. Các số viết cách nhau đúng một khoảng trống. Nếu trong stack không còn gì thì in ra dòng “empty”

// Ví dụ:

// Input

// Output

// push 3

// push 5

// show

// push 7

// show

// pop

// pop

// show

// 3 5

// 3 5 7

// 3

#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> st;
    string s;
    while(cin >> s){
        if(s == "push"){
            int n;
            cin >> n;
            st.push(n);
        }
        else if(s == "pop"){
            st.pop();
        }
        else if(s == "show"){
            if(st.empty()){
                cout << "empty" << endl;
                continue;
            }

            stack<int> tmp1 = st;
            stack<int> tmp2;
            while(!tmp1.empty()){
                int n = tmp1.top();
                tmp2.push(n);

                tmp1.pop();
            }

            while(!tmp2.empty()){
                int n = tmp2.top();
                cout << n << " ";

                tmp2.pop();
            }
            cout << endl;
        }
    }    
    return 0;
}