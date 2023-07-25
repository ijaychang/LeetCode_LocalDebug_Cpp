//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
// 
//
// 
//提示：
//
// 
// 链表中的节点数目为 n 
// 1 <= k <= n <= 5000 
// 0 <= Node.val <= 1000 
// 
//
// 
//
// 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？ 
//
// 
// 
// Related Topics 递归 链表 
// 👍 2084 👎 0


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
//    迭代法[较为拙劣]
//    ListNode *reverseKGroup(ListNode *head, int k) {
//        ListNode *p = head, *pre = nullptr;
//        vector<ListNode *> track;
//        bool isFirst = true;
//        for (; p != nullptr;) {
//            int i = 0;
//            track.clear();
//            for (; i < k && p != nullptr; i++) {
//                track.push_back(p);
//                p = p->next;
//            }
//            // 说明是该组是有k个元素的,如果不是k个元素，则保留原顺序
//            if (i == k) {
//                // 记录最后一个元素的指向，即是p所指向的元素
//                if (isFirst) {
//                    head = track[track.size() - 1];
//                }
//                if (pre) {
//                    pre->next = track[track.size() - 1];
//                }
//                isFirst = false;
//                for (int j = track.size() - 1; j >= 1; j--) {
//                    track[j]->next = track[j - 1];
//                }
//                pre = track[0];
//                track[0]->next = p;
//            }
//        }
//        return head;
//    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *a = head, *b = head;
        for (int i = 0; i < k; i++) {
            // 不到k直接返回head即可
            if (b == nullptr) {
                return head;
            }
            b = b->next;
        }

        // 反转从a至b(不含b)的链表
        ListNode *newHead = reverse(a,b);
        // 原来的a现在应该就是尾巴了，所以可以用a->next指向
        a->next = reverseKGroup(b,k);
        return newHead;
    }

    /**
     * [head,tail)
     *
     * @param a 闭
     * @param b 开
     * @return
     */
    ListNode *reverse(ListNode *a, ListNode *b) {
        if (!a) {
            return nullptr;
        }
        ListNode *pre = nullptr, *cur = a, *nxt = nullptr;
        for (; cur != b;) {
            // nxt用于暂时保存cur->next
            nxt = cur->next;
            // 逐个节点反转
            cur->next = pre;
            // pre用于记录上次操作的节点
            pre = cur;
            cur = nxt;
        }
        return pre;
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> data{1, 2, 3, 4, 5, 6, 7, 8};
    List *list = new List(data);
    ListNode *head = s.reverseKGroup(list->head, 3);
    print_list(head);
}