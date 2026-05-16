// Cho N công việc. Mỗi công việc được biểu diễn như một bộ 3 số nguyên dương <JobId, Deadline, Profit>, trong đó JobId là mã của việc, Deadline là thời gian kết thúc của việc, Profit là lợi nhuận đem lại nếu hoàn thành việc đó đúng hoặc trước thời gian. Thời gian tối thiểu để hoàn thành mỗi công việc là 1 đơn vị thời gian. Hãy cho biết lợi nhuận lớn nhất có thể thực hiện các việc với giả thiết mỗi việc được thực hiện đơn lẻ.

// Input:

// Dòng đầu tiên đưa vào số lượng bộ test T.
// Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là số lượng Job N; phần thứ hai đưa vào 3×N số tương ứng với N job.
// T, N, JobId, Deadline, Profit thỏa mãn ràng buộc:1≤T≤100;  1≤N≤1000; 1≤ JobId ≤1000; 1≤ Deadline ≤1000; 1≤ Profit ≤1000.
// Output:

// Đưa số lượng công việc tương ứng và lợi nhuận lớn nhất có thể đạt được.
// Ví dụ:

// Input

// Output

// 2
// 4
// 1 4 20

// 2 1 10

// 3 1 40

// 4 1 30
// 5
// 1 2 100

// 2 1 19

// 3 2 27

// 4 1 25

// 5 1 15

// 2 60
// 2 127

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Max 1000

struct job{
    int id , dead , profit;
};

bool cmp(job a , job b){
    return a.profit > b.profit;
}

void testCase(){
    int n;
    cin >> n;

    vector<job> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].id >> a[i].dead >> a[i].profit;
    }

    sort(a.begin() , a.end() , cmp);
    vector<int> slot(Max+1 , -1);
    int sum = 0 , cnt = 0;

    for(auto x : a){
        for(int t = x.dead ; t >= 1 ; t--){
            if(slot[t] == -1){
                slot[t] = x.id;
                cnt++;
                sum += x.profit;
                break;
            }
        }
    }

    cout << cnt << " " << sum << endl;
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