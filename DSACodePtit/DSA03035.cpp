// Cho một dãy số a[] có n phần tử gồm các số từ 1 đến n theo 1 thứ tự ngẫu nhiên. Nhiệm vụ của bạn là sắp xếp lại dãy số này theo thứ tự tăng dần với điều kiện : ở mỗi bước sắp xếp, bạn chỉ được chọn 1 số ở 1 vị trí bất kì và chuyển số đó lên đầu dãy hoặc về cuối dãy.

// Hãy tính số bước tối thiểu cần thực hiện để hoàn thành việc sắp xếp.

// Input

// Dòng đầu tiên ghi 1 số n: số lượng phần tử của dãy a (1 ≤ n ≤ 100000)
// Dòng tiếp theo gồm n số từ 1 đến n theo thứ tự ngẫu nhiên
// Output

// Một số nguyên duy nhất là số bước tối thiểu cần thực hiện để hoàn thành việc sắp xếp.
// Ví dụ

// Input

// Output

// 5

// 4 1 2 5 3

// 2

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n+1) , idx(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        idx[a[i]] = i;
    }    

    int len = 1 , maxLen = 1;
    for(int i=2;i<=n;i++){
        if(idx[i] > idx[i-1]){
            len++;
        }
        else{
            len = 1;
        }
        maxLen = max(maxLen , len);
    }
    cout << n - maxLen << endl;
    return 0;
}