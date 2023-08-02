//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//
// 
//
// 示例 1： 
//
// 
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
// 
//
// 示例 2： 
//
// 
//输入：l1 = [], l2 = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [], l2 = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 两个链表的节点数目范围是 [0, 50] 
// -100 <= Node.val <= 100 
// l1 和 l2 均按 非递减顺序 排列 
// 
// Related Topics 递归 链表 
// 👍 3192 👎 0


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
    // 迭代法
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy, *p1 = list1, *p2 = list2;

        for (; p1 != nullptr && p2 != nullptr;) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        // 剩下的尾巴接上去就可以了
        p->next = p1 != nullptr ? p1 : p2;
        return dummy->next;
    }

    // 递归法
    // 递归定义
    // list1[p1]当前元素+mergeTwoLists(list1[p1->next..],list2[p2])
    // list2[p2]当前元素+mergeTwoLists(list1[p1..],list2[p2->next])
//    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
//        if (list1 == nullptr) {
//            return list2;
//        }
//        if (list2 == nullptr) {
//            return list1;
//        }
//
//        if (list1->val <= list2->val) {
//            list1->next = mergeTwoLists(list1->next, list2);
//            return list1;
//        }
//
//        list2->next = mergeTwoLists(list1, list2->next);
//        return list2;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    List *list1 = new List({1, 2, 4});
    List *list2 = new List({1, 3, 4, 5, 6, 7});
    ListNode *list = s.mergeTwoLists(list1->head, list2->head);
    print_list(list);
}