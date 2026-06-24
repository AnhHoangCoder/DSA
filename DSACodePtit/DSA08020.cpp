// Cho cặp số S và T là các số nguyên tố có 4 chữ số (Ví dụ S = 1033, T = 8197 là các số nguyên tố có 4 chữ số). Hãy viết chương trình tìm cách dịch chuyển S thành T thỏa mãn đồng thời những điều kiện dưới đây:

// Mỗi phép dịch chuyển chỉ được phép thay đổi một chữ số của số ở bước trước đó (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1733 là hợp lệ);
// Số nhận được cũng là một số nguyên tố có 4 chữ số (ví dụ nếu S=1033 thì phép dịch chuyển S thành 1833 là không hợp lệ, và S dịch chuyển thành 1733 là hợp lệ);
// Số các bước dịch chuyển là ít nhất.
// Ví dụ số các phép dịch chuyển ít nhất để S = 1033 thành  T = 8179 là 6 bao gồm các phép dịch chuyển như sau:       

// 8179 ß 8779ß 3779ß 3739ß 3733ß 1733ß 1033.

// Input:

// Dòng đầu tiên đưa vào số lượng test T (T≤100)
// Những dòng kế tiếp mỗi dòng đưa vào một test. Mỗi test là một bộ đôi S, T.
// Output:

// Đưa ra kết quả mỗi test theo từng dòng.
// Ví dụ:

// Input

// Output

// 2

// 1033 8179

// 1033 8779

// 6

// 5