//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。 
//
// 你应当 保留 两个分区中每个节点的初始相对位置。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,4,3,2,5,2], x = 3
//输出：[1,2,2,4,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [2,1], x = 2
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 200] 内 
// -100 <= Node.val <= 100 
// -200 <= x <= 200 
// 
// Related Topics 链表 双指针 
// 👍 739 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) {
            return nullptr;
        }
        // leftDummy 每个元素都小于x
        ListNode *leftDummy = new ListNode(-1);
        // leftDummy 每个元素都大于或等于x
        ListNode *rightDummy = new ListNode(-1);

        ListNode *p = head, *lp = leftDummy, *rp = rightDummy;
        for (; p != nullptr; p = p->next) {
            if (p->val < x) {
                lp->next = p;
                lp = lp->next;
            } else {
                rp->next = p;
                rp = rp->next;
            }
        }
        if (rp != nullptr) {
            rp->next = nullptr;
        }
        if (leftDummy->next == nullptr) {
            return rightDummy->next;
        }
        lp->next = rightDummy->next;
        return leftDummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{1, 4, 3, 2, 5, 2};
    List *list = new List(data);
    ListNode *head = s.partition(list->head, 3);
    print_list(head);
}