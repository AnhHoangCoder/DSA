// Bài toán Tháp Hà Nội đã rất nổi tiểng. Bắt đầu có các đĩa xếp chồng lên cột A theo thứ tự kích thước giảm dần, nhỏ nhất ở trên cùng. Cột B và cột C ban đầu không có đĩa nào cả.

// Mục tiêu của bạn là di chuyển toàn bộ các đĩa theo đúng thứ tự về cột C, tuân theo các quy tắc sau:

// Mỗi lần chỉ có thể di chuyển một đĩa.
// Mỗi lần di chuyển sẽ lấy đĩa trên từ một trong các cột và đặt nó lên trên một cột khác.
// Không được đặt đĩa lên trên đĩa nhỏ hơn..
// Input:

// Số tự nhiên  0 < N < 10

// Output:

// In ra lần lượt từng bước theo mẫu trong ví dụ. Chú ý giữa các chữ cái và dấu -> có khoảng trống.

// Ví dụ:

// Input

// 3 

// Output

// A -> C

// A -> B

// C -> B

// A -> C

// B -> A

// B -> C

// A -> C

#include <iostream>

using namespace std;

int n;

//A là cọc nguồn , B là cọc trung gian , C là cọc đích
void hanoi(int n , char A , char B , char C){
    if(n == 1){
        cout << A << " -> " << C << endl;
        return;
    }

    hanoi(n-1 , A , C , B); //đưa n-1 từ A sang B
    cout << A << " -> " << C << endl; //đưa cọc lớn nhất từ A sang C
    hanoi(n-1 , B , A , C); //đưa n-1 từ B sang C
}

int main(){
    cin >> n;
    hanoi(n , 'A' , 'B' , 'C');
    return 0;    
}