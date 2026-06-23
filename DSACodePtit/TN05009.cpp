// Cho đồ thị vô hướng G= được biểu diễn dưới dạng danh sách cạnh. Hãy kiểm tra xem đồ thị có chu trình từ đỉnh 1 hay không, nếu có, hãy in ra chu trình đầu tiên tìm thấy theo DFS.

// Input:

// Dòng đầu tiên đưa vào T là số lượng bộ test.
// Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số N, M  tương ứng với số đỉnh, số cạnh.
// Dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh của đồ thị.
// T, N, M thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤103; 1≤ M ≤ N*(N-1)/2;
// Output:

// Đưa ra chu trình đầu tiên tìm thấy theo DFS từ đỉnh 1.
// Nếu không có chu trình từ đỉnh 1, ghi ra NO
//       Ví dụ:

// Input:

// Output:

// 1

// 6 9

// 1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6

// 1 2 3 1