//车上最初有 capacity 个空座位。车 只能 向一个方向行驶（也就是说，不允许掉头或改变方向） 
//
// 给定整数 capacity 和一个数组 trips , trip[i] = [numPassengersi, fromi, toi] 表示第 i 次旅行有
// numPassengersi 乘客，接他们和放他们的位置分别是 fromi 和 toi 。这些位置是从汽车的初始位置向东的公里数。 
//
// 当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false。 
//
// 
//
// 示例 1： 
//
// 
//输入：trips = [[2,1,5],[3,3,7]], capacity = 4
//输出：false
// 
//
// 示例 2： 
//
// 
//输入：trips = [[2,1,5],[3,3,7]], capacity = 5
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 1 <= trips.length <= 1000 
// trips[i].length == 3 
// 1 <= numPassengersi <= 100 
// 0 <= fromi < toi <= 1000 
// 1 <= capacity <= 105 
// 
// Related Topics 数组 前缀和 排序 模拟 堆（优先队列） 
// 👍 267 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> diff;

    bool carPooling(vector<vector<int>> &trips, int capacity) {
        diff.assign(1000, 0);
        diff[0] = capacity;

        for (int i = 0; i < trips.size(); i++) {
            vector<int> trip = trips[i];
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            diff[from] -= numPassengers;
            if (to < diff.size() - 1) {
                diff[to] += numPassengers;
            }
        }

        int leftSeatNum = diff[0];
        if (leftSeatNum < 0) {
            return false;
        }
        for (int i = 1; i < diff.size(); i++) {
            leftSeatNum = leftSeatNum + diff[i];
            if (leftSeatNum < 0) {
                return false;
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> trips = {{2, 1, 5},
                                 {3, 3, 7}};
    bool flag = s.carPooling(trips, 4);

    cout << flag << endl;

    flag = s.carPooling(trips, 5);

    cout << flag << endl;
}