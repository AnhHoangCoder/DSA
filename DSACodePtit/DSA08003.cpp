// Yêu cầu bạn xây dựng một hàng đợi hai đầu với các truy vấn sau đây:

// “PUSHFRONT x”: Thêm phần tử x vào đầu của dequeue (0 ≤ x ≤ 1000).

// “PRINTFRONT”: In ra phần tử đầu tiên của dequeue. Nếu dequeue rỗng, in ra “NONE”.

// “POPFRONT”: Xóa phần tử đầu của dequeue. Nếu dequeue rỗng, không làm gì cả.

// “PUSHBACK x”: Thêm phần tử x vào cuối của dequeue (0 ≤ x ≤ 1000).

// “PRINTBACK”: In ra phần tử cuối của dequeue. Nếu dequeue rỗng, in ra “NONE”.

// “POPBACK”: Xóa phần tử cuối của dequeue. Nếu dequeue rỗng, không làm gì cả.

// Dữ liệu vào:

// Dòng đầu tiên là số lượng truy vấn Q (Q ≤ 100000).

// Mỗi truy vấn có dạng như trên.

// Kết quả: 

// Với mỗi truy vấn “PRINTFRONT” và “PRINTBACK”, hãy in ra kết quả trên một dòng.

// Ví dụ:

// Input

// Output

// 10

// PUSHBACK 1

// PUSHFRONT 2

// PUSHBACK 3

// PRINTFRONT

// POPFRONT

// PRINTFRONT

// POPFRONT

// PRINTBACK

// POPFRONT

// PRINTBACK

 

// 2

// 1

// 3

// NONE

#include <iostream>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    deque<int> dq;
    string s;
    while(n--){
        cin >> s;
        if(s == "PUSHFRONT"){
            int x;
            cin >> x;
            dq.push_front(x);
        }

        if(s == "PRINTFRONT"){
            if(dq.empty()){
                cout << "NONE";
            }
            else{
                cout << dq.front();
            }
            cout << endl;
        }

        if(s == "POPFRONT"){
            if(!dq.empty()){
                dq.pop_front();
            }
        }

        if(s == "PUSHBACK"){
            int x;
            cin >> x;
            dq.push_back(x);
        }

        if(s == "PRINTBACK"){
            if(!dq.empty()){
                cout << dq.back();
            }
            else{
                cout << "NONE";
            }
            cout << endl;
        }

        if(s == "POPBACK"){
            if(!dq.empty()){
                dq.pop_back();
            }
        }
    }
    return 0;
}