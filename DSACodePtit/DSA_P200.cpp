// Cho dãy số a[] có n số nguyên dương. Tất cả các số trong dãy đều có đúng 4 chữ số.

// Hãy sắp xếp dãy số a theo thứ tự tăng dần và in kết quả ra màn hình. 

// Input

// Dòng đầu ghi số bộ test, không quá 10.

// Mỗi bộ test:

// Dòng đầu ghi số n
// Dòng thứ 2 ghi n số của dãy a[]
// Output

// Với mỗi bộ test, ghi ra lần lượt các số trong dãy a[] theo đúng thứ tự tăng dần, mỗi số cách nhau 1 khoảng trống.

// Ví dụ

// Input

// 2

// 4

// 5 7 1 4

// 7

// 123 456 100 989 444 111 90

// Output

// 1 4 5 7

// 90 100 111 123 444 456 989

 

// Các trường hợp dữ liệu vào:

// Trường hợp 1: 0 < n ≤ 1.000
// Trường hợp 2: 0 < n ≤ 10.000
// Trường hợp 3: 0 < n ≤ 100.000
// Trường hợp 4: 0 < n ≤ 1.000.000
// Trường hợp 5: 0 < n ≤ 5.000.000

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;

// //Selection sort
// //O(n^2)
// void sort_1(){
//     for(int i=0;i<n-1;i++){
//         int Min = i;
//         for(int j=i+1;j<n;j++){
//             if(a[j] < a[Min]){
//                 Min = j;
//             }
//         }
//         swap(a[i] , a[Min]);
//     }
// }
// //AC(TH1 , TH2)
// //TLE(TH3 , TH4 , TH5)





// //Insertion sort
// //O(n^2)
// void sort_2(){
//     for(int i=1;i<n;i++){
//         int key = a[i];
//         int j = i - 1;
//         while(j >= 0 && a[j] > key){
//             a[j+1] = a[j];
//             j--;
//         }
//         a[j+1] = key;
//     }
// }
// //AC(TH1 , TH2)
// //TLE(TH3 , TH4 , TH5)




// //Bubble sort
// //O(n^2)
// void sort_3(){
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<n-i-1;j++){
//             if(a[j] > a[j+1]){
//                 swap(a[j] , a[j+1]);
//             }
//         }
//     }
// }
// //AC(TH1 , TH2)
// //TLE(TH3 , TH4 , TH5)






// //Quick sort
// //O(nlog(n))
// int Partition(int l , int r){
//     int x = a[r] , i = l-1;
//     for(int j = l ; j < r ; j++){
//         if(a[j] <= x){
//             i++;
//             swap(a[i] , a[j]);
//         }
//     }
//     swap(a[i+1] , a[r]);
//     return i+1;
// }

// void sort_4(int l , int r){
//     if(l < r){
//         int p = Partition(l,r);
//         sort_4(l , p-1);
//         sort_4(p+1 , r);
//     }
// }
// //AC(TH1 , TH2 , TH3)
// //TLE(Th4 , TH5)





//Radix sort
//O(d(n+d))
void sort_5(){
    int i , Max = a[0] , B[n] , exp = 1;
    for(int i=1;i<n;i++){
        if(a[i] > Max) Max = a[i];
    }
    while(Max / exp > 0){
        vector<int> bucket(10);
        for(i=0;i<n;i++){
            bucket[(a[i] / exp) % 10]++;
        }
        for(i=1;i<10;i++){
            bucket[i] += bucket[i-1];
        }
        for(i=n-1;i>=0;i--){
            B[--bucket[(a[i] / exp) % 10]] = a[i];
        }
        for(int i=0;i<n;i++){
            a[i] = B[i];
        }
        exp *= 10;
    }
}
//AC(2.69s)

void test_case(){
    cin >> n;
    a.assign(n+1 , 0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort_5();
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        test_case();
    }    
    return 0;
}