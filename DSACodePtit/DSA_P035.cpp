// Công ty X chuyên tổ chức các hành trình du lịch trong vùng lãnh thổ gồm N điểm du lịch trọng điểm, được đánh số từ 1 tới N. Hệ thống giao thông trong vùng gồm M tuyến đường một chiều khác nhau, tuyến đường thứ j (j = 1,2,…M) cho phép đi từ địa điểm uj tới địa điểm vj với chi phí đi lại là số nguyên dương c (uj, vj). Công ty vừa nhận được một hợp đồng yêu cầu xây dựng một hành trình du lịch xuất phát từ địa điểm du lịch 1 và đi thăm K địa điểm du lịch s1, s2, …, sk (khác địa điểm 1) và sau đó quay về địa điểm xuất phát 1 với tổng chi phí là nhỏ nhất.

// Yêu cầu: Cho thông tin về hệ thống giao thông và k địa điểm du lịch s1, s2, …, sk. Hãy xây dựng một hành trình du lịch xuất phát từ địa điểm du lịch 1 và đi thăm k địa điểm, sau đó quay về địa điểm du lịch 1 với tổng chi phí nhỏ nhất.

// Input:

// • Dòng thứ nhất chứa 3 số nguyên N, M, K (N <= 1000, M <= 10^5, K <= 15).

// • Dòng thứ hai chứa K số nguyên dương s1, s2, …, sk.

// • M dòng tiếp, mỗi dòng gồm 3 số nguyên u, v, c (u != v, c <= 10^9) mô tả thông tin về tuyến đường giữa địa điểm u và v có độ dài bằng c.

// Output: 

// In ra một số nguyên là tổng chi phí nhỏ nhất tìm được. Nếu không tìm được một hành trình du lịch nào, in ra số -1.

 

// Ví dụ:

// Input:

// Output

// 6 8 2

// 2 5

// 1 2 4

// 2 4 2

// 4 3 3

// 3 1 4

// 4 1 5

// 3 5 5

// 5 3 1

// 5 6 7

// 19