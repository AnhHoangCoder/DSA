// Cho đơn đồ thị vô hướng liên thông G = (V, E) gồm N đỉnh và M cạnh, các đỉnh được đánh số từ 1 tới N và các cạnh được đánh số từ 1 tới M.

// Có Q truy vấn, mỗi truy vấn yêu cầu bạn tìm đường đi ngắn nhất giữa đỉnh X[i] tới Y[i].

// Input:

// Dòng đầu tiên hai số nguyên N và M (1 ≤ N ≤ 100, 1 ≤ M ≤ N*(N-1)/2).
// M dòng tiếp theo, mỗi dòng gồm 3 số nguyên u, v, c cho biết có cạnh nối giữa đỉnh u và v có độ dài bằng c (1 ≤ c ≤ 1000).
// Tiếp theo là số lượng truy vấn Q (1 ≤ Q ≤ 100 000).
// Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên X[i], Y[i].
// Output: 

// Với mỗi truy vấn, in ra đáp án là độ dài đường đi ngắn nhất tìm được.
// Ví dụ:

// Input:

// Output

// 5 6

// 1 2 6

// 1 3 7

// 2 4 8

// 3 4 9

// 3 5 1

// 4 5 2

// 3

// 1 5

// 2 5

// 4 3

 

// 8

// 10

// 3