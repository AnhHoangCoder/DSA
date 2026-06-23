// Trên sân thi đấu được có giới hạn 109 x 109, các chú robot sử dụng công nghệ dò đường line sẽ di chuyển theo các vạch chỉ đường có sẵn. Mỗi bước, robot sẽ dịch chuyển được 1 ô đơn vị theo một trong 8 hướng. Robot có thể thực hiện được phép quay 45 độ hay 90 độ nếu như ô kế cận cũng đã được kẻ vạch.

// Hình vẽ dưới đây minh họa các hướng di chuyển của robot trên một sân thi đấu có sẵn, các vị trí đánh dấu X mô tả robot không được đi theo hướng này.

// Nhiệm vụ của bạn là hãy lập chương trình để di chuyển robot vị trí (xA, yA) tới vị trí (xB, yB) với số bước ít nhất. Input đảm bảo hai vị trí A và B chắc chắn đã được kẻ vạch.

// Input:

// Dòng đầu tiên là số lượng bộ test T (T <= 10).

// Mỗi test gồm số nguyên xA, yA, xB, yB mô tả tọa độ hai điểm A và B.

// Tiếp theo là số nguyên N (N <= 10^5), mô tả số vạch đường chỉ dẫn.

// N dòng tiếp theo, mỗi dòng gồm 3 số nguyên x, y1, y2 (y1 <= y2) cho biết có một vạch chỉ dẫn từ ô (x, y1) tới (x, y2). Input đảm bảo tổng số lượng số ô được kẻ vạch trên sân thi đấu không vượt quá 105. Giới hạn: 0 <= x, y1, y2 <= 109.

// Output: 

// Với mỗi test, in ra số bước di chuyển ít nhất tìm được.

// Giới hạn:  0 ≤ x, y1, y2 ≤ 109

// Ví dụ:            

// Input

// Output

// 2

// 0 6 2 2

// 3

// 0 6 6

// 1 6 10

// 2 2 5

// 1 1 2 10

// 2

// 1 1 4

// 2 8 10

// 5

// -1