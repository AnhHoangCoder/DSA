// Cho danh sách liên kết đơn lưu giữ các số nguyên được quản lý bởi con trỏ First. Viết chương trình con lọc tất cả các phần tử có giá trị trùng nhau trong danh sách liên kết đơn First, chỉ để lại 1 phần tử đại diện cho nhóm trùng. Sau khi lọc xong, liệt kê các phần tử  trong danh sách liên kết đơn First.

// Ví dụ: Ta có Input :

// 12 : là số lượng phân tử trong danh sách

// 1 1 1 4  5 1 4  7 7 8 1 9 : là số phần tử

// Output : 1 4 5 7 8 9

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> res;
    for(int i=0;i<n;i++){
        bool check = false;
        for(int x : res){
            if(a[i] == x){
                check = true;
                break;
            }
        }
        if(!check){
            res.push_back(a[i]);
        }
    }
    for(int x : res){
        cout << x << " ";
    }
    return 0;
}