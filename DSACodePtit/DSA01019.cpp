// Khi chat chit vui vẻ, anh em chiến hữu thường hay gõ HAHA để thể hiện sự sảng khoái. Đôi khi cũng có thể gõ HAHAAAAA chẳng hạn cho thêm phần nhấn mạnh.

// Giả sử một xâu ký tự được coi là HAHA nếu thỏa mãn các điều kiện:

// Ký tự đầu tiên phải là chữ H, ký tự cuối cùng phải là chữ A
// Không có hai chữ H nào liền nhau
// Cho trước độ dài N, hãy liệt kê tất cả các xâu ký tự HAHA theo thứ tự từ điển.

// Input

// Dòng đầu ghi số bộ test T (không quá 10)
// Mỗi bộ test ghi độ dài N (2 <= N < 16)
// Output

// Với mỗi bộ test, ghi ra tất cả các xâu HAHA tìm được theo thứ tự từ điển, mỗi xâu viết trên một dòng.
// Ví dụ

// Input

// 2

// 2

// 4

// Output

// HA

// HAAA

// HAHA

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;

void back_track(int i){
    if(i > n){
        bool check_1 = true , check_2 = false; // check_1 là check xem có 2 số 1 nào cạnh nhau ko . check 2 xem có phải số đầu tiên là 1 và cuối là 0 ?
        for(int j=1;j<n;j++){
            if(a[j] == 1 && a[j+1] == 1){
                check_1 = false;
                break;
            }
        }
        if(a[1] == 1 && a[n] == 0){
            check_2 = true;
        }
        if(check_1 && check_2){
            for(int j=1;j<=n;j++){
                cout << ((a[j] == 1) ? 'H' : 'A');
            }
            cout << "\n";
        }
        return;
    }
    for(int j=0;j<=1;j++){
        a[i] = j;
        back_track(i+1);
    }
}

void test_case(){
    cin >> n;
    a.assign(n+1 , 0);
    back_track(1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}