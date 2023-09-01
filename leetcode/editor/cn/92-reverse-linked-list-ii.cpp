//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链
//表节点，返回 反转后的链表 。
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], left = 2, right = 4
//输出：[1,4,3,2,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [5], left = 1, right = 1
//输出：[5]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点数目为 n 
// 1 <= n <= 500 
// -500 <= Node.val <= 500 
// 1 <= left <= right <= n 
// 
//
// 
//
// 进阶： 你可以使用一趟扫描完成反转吗？ 
// Related Topics 链表 
// 👍 1635 👎 0


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


    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == right) {
            return head;
        }
        // 初始 cur 指向头节点，prev 为 nullptr，next 为 nullptr
        // 三指针技巧反转链表
        // 定义 pos 为 cur 所在位置，初始位置为 1
        int pos = 1;
        // 定义该节点为 left 位置所在节点的前一个节点(这里定义一个虚拟节点，避免空指针问题)
        ListNode *pPrevLeft = new ListNode(-1);
        // 定义该节点为 right 位置所在节点的后一个节点
        ListNode *pLeft = nullptr;
        ListNode *cur = head, *prev = nullptr, *next = nullptr;
        for (; cur != nullptr; pos++) {
            // 令 next 指向 cur 的后一个节点
            next = cur->next;
            if (pos == left - 1) {
                pPrevLeft = cur;
            } else if(pos == left) {
                pLeft = cur;
            } else if (pos == right) {
                pPrevLeft->next = cur;
                pLeft->next = cur->next;
            }
            // cur->next 指针指向 prev
            if (pos >= left + 1 && pos <= right) {
                cur->next = prev;
            }
            // prev 用于记录之前的 cur 所指向的节点
            prev = cur;
            // 将 cur 移动到下一个节点
            cur = next;
        }

        // prev 为原链表的最后一个节点
        // 如果 pPrevLeft 不为nullptr 说明 left > 1，pPrevLeft 为 nullptr 则说明 left == 1，此时只要返回 prev即可
        return left == 1 ? pPrevLeft->next : head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{3,5,4,7};
    List *list = new List(data);
    ListNode *head = s.reverseBetween(list->head,1,2);
    print_list(head);
}