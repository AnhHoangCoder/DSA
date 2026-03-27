// Bạn được giao cho N công việc, công việc thứ i có thời gian bắt đầu là A[i] và kết thúc tại B[i]. Tại một thời điểm, bạn chỉ có thể làm một công việc.

// Bạn hãy lựa chọn các công việc một cách tối ưu sao cho số công việc làm được là nhiều nhất.

// Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

// Mỗi test gồm 1 số nguyên N ( 1 ≤ N ≤ 100 000).

// N dòng tiếp theo, mỗi dòng gồm 2 số A[i] và B[i] (0 ≤ A[i] < B[i] ≤ 106).

// Output:  Với mỗi test, in ra đáp án trên một dòng.

// Ví dụ:

// Input

// Output

// 1

// 6

// 5 9

// 1 2

// 3 4

// 0 6

// 5 7

// 8 9

 

// 4

// Giải thích test: Lựa chọn công việc 2, 3, 5, 6.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct workTime{
    int start , end;
};

bool cmp(workTime a , workTime b){
    return a.end < b.end;
}

void testCase(){
    int n;
    cin >> n;
    vector<workTime> x(n);
    for(int i=0;i<n;i++){
        cin >> x[i].start >> x[i].end;
    }
    sort(x.begin() , x.end() , cmp);
    
    int cnt = 1 , last = x[0].end;
    for(int i=1;i<n;i++){
        if(x[i].start >= last){
            cnt++;
            last = x[i].end;
        }
    }
    cout << cnt << endl;
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