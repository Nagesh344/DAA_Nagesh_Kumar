class Solution {
public:
    int countLessEqual(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int count = 0, r = n - 1, c = 0;
        while (r >= 0 && c < n) {
            if (matrix[r][c] <= mid) {
                count += (r + 1);
                c++;
            } else {
                r--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (countLessEqual(matrix, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
