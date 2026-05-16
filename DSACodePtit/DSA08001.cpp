// Ban đầu cho một queue rỗng. Bạn cần thực hiện các truy vấn sau:

// Trả về kích thước của queue
// Kiểm tra xem queue có rỗng không, nếu có in ra “YES”, nếu không in ra “NO”.
// Cho một số nguyên và đẩy số nguyên này vào cuối queue.
// Loại bỏ phần tử ở đầu queue nếu queue không rỗng, nếu rỗng không cần thực hiện.
// Trả về phần tử ở đầu queue, nếu queue rỗng in ra -1.
// Trả về phần tử ở cuối queue, nếu queue rỗng in ra -1.
// Dữ liệu vào

// Dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, mỗi bộ dữ theo dạng sau.

// Dòng đầu tiên chứa số nguyên n - lượng truy vấn (1 ≤ n ≤ 1000)

// N dòng tiếp theo, mỗi dòng sẽ ghi loại truy vấn như trên, với truy vấn loại 3 sẽ có thêm một số nguyên, không quá 106.

// Kết quả: In ra kết quả của các truy vấn..

// Ví dụ:

// Input

// Output

// 1

// 14

// 3 1

// 3 2

// 3 3

// 5

// 6

// 4

// 4

// 4

// 4

// 4

// 3 5

// 3 6

// 5

// 1

// 1

// 3

// 5

// 2

#include <iostream>
#include <deque>

using namespace std;

void testCase(){
    int tv , tmp;
    cin >> tv;
    deque<int> q;
    while(tv--){
        cin >> tmp;
        if(tmp == 1){
            cout << q.size() << endl;
        }
        else if(tmp == 2){
            cout << (q.empty() ? "YES" : "NO") << endl;
        }
        else if(tmp == 3){
            int n;
            cin >> n;
            q.push_back(n);
        }
        else if(tmp == 4){
            if(!q.empty()){
                q.pop_front();
            }
        }
        else if(tmp == 5){
            if(!q.empty()) cout << q.front() << endl;
            else cout << -1 << endl; 
        }
        else if(tmp == 6){
            if(!q.empty()) cout << q.back() << endl;
            else cout << -1 << endl;
        }
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