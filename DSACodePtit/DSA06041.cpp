// Cho dãy số A[] gồm có N phần tử. Nhiệm vụ của bạn là hãy tìm một số có tần số xuất hiện nhiều nhất, yêu cầu lớn hơn N/2 lần xuất hiện trong dãy số.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

// Mỗi test gồm số nguyên N (1≤ N ≤ 100 000), số lượng phần tử trong dãy số ban đầu.

// Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 1 000 000).

// Output: 

// Với mỗi test in ra đáp án của bài toán trên một dòng. Nếu không tìm được đáp án, in ra “NO”.

// Ví dụ:

// Input:

// Output

// 2

// 9

// 3 3 4 2 4 4 2 4 4

// 8

// 3 3 4 2 4 4 2 4

// 4

// NO

#include <iostream>
#include <vector>

using namespace std;

void testCase(){
    int n;
    cin >> n;
    vector<int> a(n);
    int count = 0 , candidate = 0;

    // Tìm xem phần tử nào có tần số lớn nhất
    for(int i=0;i<n;i++){
        cin >> a[i];

        if(count == 0){
            candidate = a[i];
            count = 1;
        }
        else if(candidate == a[i]){
            count++;
        }
        else{
            count--;
        }
    }

    //Đếm tần số lớn nhất của phần tử
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i] == candidate){
            cnt++;
        }
    }

    if(cnt > n/2){
        cout << candidate;
    }
    else{
        cout << "NO";
    }
    cout << endl;
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