// Biểu thức ngoặc là xâu chỉ gồm các ký tự ‘(’ hoặc ‘)’. Biểu thức ngoặc đúng và bậc của biểu thức ngoặc được định nghĩa một cách đệ qui như sau:

// Biểu thức rỗng là biểu thức ngoặc đúng và có bậc bằng 0,
// Nếu A là biểu thức ngoặc đúng có bậc bằng k thì (A) cũng là một biểu thức ngoặc đúng có bậc bằng k+1,
// Nếu A và B là hai biểu thức ngoặc đúng và có bậc tương ứng là k_1 và k_2 thì AB cũng là một biểu thức ngoặc đúng có bậc bằng max(k_1,k_2).
// Ví dụ, ‘()(())’ là một biểu thức ngoặc đúng có bậc bằng 2 còn ‘(()(()))’ là một biểu thức ngoặc đúng và có bậc bằng 3.

// Cho số nguyên K và xâu S là một xâu chỉ gồm các ký tự ‘(‘, ‘)’ và ‘?’, hãy đếm số cách cách thay các ký tự ‘?’ trong xâu S thành ký tự ‘(‘ hoặc ‘)’ để nhận được xâu T là biểu thức ngoặc đúng có bậc bằng K.

// Input

// Dòng đầu chứa số nguyên dương K.
// Dòng thứ hai chứa xâu S chỉ gồm các ký tự ‘(‘, ‘)’ và ‘?’.
// Giới hạn:

// Subtask 1 (50%) độ dài xâu S không vượt quá 20.

// Subtask 2 (50%) độ dài xâu S không vượt quá 200.

// Output

// Hãy in ra đáp án trên một dòng.
// Test ví dụ:

// Input

// Output

// 2

// ????(?

// 1

// 1

// ((???(

// 0

// 2

// ((???()???(?

// 4