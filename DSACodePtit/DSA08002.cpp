// Yêu cầu bạn xây dựng một queue với các truy vấn sau đây:

// “PUSH x”: Thêm phần tử x vào cuối của queue (0 ≤ x ≤ 1000).

// “PRINTFRONT”: In ra phần tử đầu tiên của queue. Nếu queue rỗng, in ra “NONE”.

// “POP”: Xóa phần tử ở đầu của queue. Nếu queue rỗng, không làm gì cả.

// Dữ liệu vào:

// Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000).

// Mỗi truy vấn có dạng như trên.

// Kết quả:

 

// Với mỗi truy vấn “PRINT”, hãy in ra phần tử đầu tiên của queue. Nếu queue rỗng, in ra “NONE”.

// Ví dụ:

 

 

// Input

// Output

// 9

// PUSH 1

// PUSH 2

// POP

// PRINTFRONT

// PUSH 3

// PRINTFRONT

// POP

// POP

// PRINTFRONT

// 2

// 2

// NONE

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int q;
    cin >> q;

    queue<int> qe;
    while(q--){
        string s;
        cin >> s;
        if(s == "PUSH"){
            int x;
            cin >> x;
            qe.push(x);
        }
        else if (s == "POP"){
            if(!qe.empty()) qe.pop();
        }
        else{
            if(!qe.empty()){
                cout << qe.front();
            }
            else{
                cout << "NONE";
            }
            cout << endl;
        }
    }
    return 0;
}