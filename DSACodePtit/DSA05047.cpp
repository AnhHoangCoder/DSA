// Cho một bảng kích thước 4 x N (gồm N cột). Mỗi ô (i, j) có điểm bằng A[i][j]. Bạn cần chọn một tập hợp các ô sao cho điểm đạt được là lớn nhất, và trong các ô được chọn, không có 2 ô nào có chung cạnh.

// Ví dụ với bảng có N = 3 như hình vẽ trên. Cách chọn tập tối ưu là (3,1), (1, 2), (4, 2) và (3, 3).

// Input:

// Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

// Mỗi test bắt đầu bởi số nguyên dương N (1 ≤ N ≤ 10000).

// 4 dòng tiếp theo, mỗi dòng gồm N số A[i][j], là điểm tại ô (i,j) (-10000 ≤ A[i][j] ≤ 10000).

// Output: 

// Với mỗi test, in ra đáp án tìm được trên một dòng.

// Ví dụ:

// Input

// Output

// 2

// 3

// -1 9 3

// -4 5 -6

// 7 8 9

// 9 7 2

// 2

// -1 -5

// -2 -6

// -3 -7

// -4 -8

// 32

// -1