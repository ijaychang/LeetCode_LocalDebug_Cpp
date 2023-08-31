//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [1], n = 1
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1,2], n = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中结点的数目为 sz 
// 1 <= sz <= 30 
// 0 <= Node.val <= 100 
// 1 <= n <= sz 
// 
//
// 
//
// 进阶：你能尝试使用一趟扫描实现吗？ 
// Related Topics 链表 双指针 
// 👍 2653 👎 0


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
    /**
     * 寻找第 n 个节点
     * @param head 头结点
     * @param n 第 n 个
     * @return
     */
    ListNode* findNthFromEnd(ListNode* dummy, int n) {
        ListNode *p1 = dummy->next, *p2 = dummy;
        // 先让 p1 走 k 步
        int step = 1;
        for(;p1 != nullptr && step <= n; step++) {
            p1 = p1->next;
        }
        // 然后 p1 , p2 同时开始前进，直到 p1 = nullptr
        for(;p1 != nullptr;) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        // 找到倒数第 n + 1 个节点
        ListNode *nodeOfNPlusOneFromEnd = findNthFromEnd(dummy, n);
        nodeOfNPlusOneFromEnd->next = nodeOfNPlusOneFromEnd->next->next;
        return dummy->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    List *list = new List({1});
    ListNode *res = s.removeNthFromEnd(list->head,1);
    print_list(res);
}