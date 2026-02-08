// Độ chênh lệch của một dãy số nguyên dương được định nghĩa là hiệu của số lớn nhất trừ đi số nhỏ nhất trong dãy.

// Cho hai số nguyên dương n và k, với 1 <= n, k <= 8.

// Với n xâu ký tự số có độ dài k, có thể có chữ số 0 ở đầu. Hãy tìm cách duyệt tất cả hoán vị các chữ số của từng số trong danh sách sao cho độ chênh lệch của dãy số tạo được là bé nhất có thể.

// Input

// Dòng đầu ghi hai số n và k.

// Tiếp theo là n dòng, mỗi dòng ghi một xâu ký tự đúng k chữ số.

// Output

// Ghi ra độ chênh lệch bé nhất có thể.

// Ví dụ

// Input

// 6 4

// 5237

// 2753

// 7523

// 5723

// 5327

// 2537

// Output

// 2700

// Input

// 3 3

// 010

// 909

// 012

// Output

// 3

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, k;
vector<string> a;
vector<int> perm;
vector<bool> used;
int minDiff;

void calculate() {
    int currentMax = -1;
    int currentMin = INT_MAX;

    for (int i = 0; i < n; i++) {
        int val = 0;
        for (int j = 0; j < k; j++) {
            // perm[j] lưu chỉ số cột (0 đến k-1)
            int digit = a[i][perm[j]] - '0';
            val = val * 10 + digit;
        }

        if (val < currentMin) currentMin = val;
        if (val > currentMax) currentMax = val;
    }
    
    int diff = currentMax - currentMin;
    if (diff < minDiff) {
        minDiff = diff;
    }
}

// idx chạy từ 0 đến k-1
void Try(int idx) {
    if (minDiff == 0) return; // Nhánh cận

    if (idx == k) {
        calculate();
        return;
    }

    for (int i = 0; i < k; i++) { // Duyệt qua k cột
        if (!used[i]) {
            used[i] = true;
            perm[idx] = i; // Lưu chỉ số cột vào vị trí hoán vị hiện tại
            Try(idx + 1);
            used[i] = false;
        }
    }
}

void testCase() {
    if (!(cin >> n >> k)) return;
    
    a.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Reset các biến phục vụ quay lui cho k cột
    perm.assign(k, 0);
    used.assign(k, false);
    minDiff = INT_MAX;

    Try(0);
    cout << minDiff << endl;
}

int main() {
    // Tối ưu tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testCase();
    return 0;
}