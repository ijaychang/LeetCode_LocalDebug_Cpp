//给定一个二维矩阵 matrix，以下类型的多个请求： 
//
// 
// 计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。 
// 
//
// 实现 NumMatrix 类： 
//
// 
// NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化 
// int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1) 、右下
//角 (row2, col2) 所描述的子矩阵的元素 总和 。 
// 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: 
//["NumMatrix","sumRegion","sumRegion","sumRegion"]
//[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,
//1,2,2],[1,2,2,4]]
//输出: 
//[null, 8, 11, 12]
//
//解释:
//NumMatrix numMatrix = new NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,
//0,1,7],[1,0,3,0,5]]);
//numMatrix.sumRegion(2, 1, 4, 3); // return 8 (红色矩形框的元素总和)
//numMatrix.sumRegion(1, 1, 2, 2); // return 11 (绿色矩形框的元素总和)
//numMatrix.sumRegion(1, 2, 2, 4); // return 12 (蓝色矩形框的元素总和)
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 200 
// -105 <= matrix[i][j] <= 105 
// 0 <= row1 <= row2 < m 
// 0 <= col1 <= col2 < n 
// 最多调用 104 次 sumRegion 方法 
// 
// Related Topics 设计 数组 矩阵 前缀和 
// 👍 510 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class NumMatrix {
public:
    // preSum[row][col] 定义为从坐标(0,0) 到 坐标(row,col)组成的矩形区域内元素之和
    vector<vector<int>> preSum;

    NumMatrix(vector<vector<int>> &matrix) {
        int sz = matrix.size();
        // preSum第一行为全0的行
        preSum.push_back(vector<int>(matrix[0].size() + 1, 0));
        for (int row = 0; row < sz; row++) {
            // 取出当前行的所有元素 curNums
            vector<int> curNums = matrix[row];
            // curPreSum第一个元素始终为0
            vector<int> curPreSum(curNums.size() + 1, 0);
            // 取出上一行prevPreSum,preSum第一行全0，所以preSum[row]即是上一行
            vector<int> prevPreSum = preSum[row];
            for (int col = 1; col < curNums.size() + 1; col++) {
                curPreSum[col] = curPreSum[col - 1] + prevPreSum[col] + curNums[col - 1] - prevPreSum[col - 1];
            }
            preSum.push_back(curPreSum);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // 矩形[(0,0),(row2,col2)]元素和-矩形[(0,0),(row2,col1)]元素和-矩形[(0,0),(row1,col2)]+矩形[(0,0),(row1,col1)]元素和
        return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {

    vector<vector<int>> matrix = {{-4, -5}};
    NumMatrix *s = new NumMatrix(matrix);
    int res = s->sumRegion(0, 0, 0, 0);
    cout << res << endl;
    res = s->sumRegion(0, 0, 0, 1);
    cout << res << endl;
}