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
 * 反转链表
 * @param root
 */
    // 拙劣版
//    ListNode *reverse(ListNode *head) {
//        if (!head) {
//            return nullptr;
//        }
//        ListNode *pre = nullptr, *cur, *nxt, *tmp;
//        for (cur = head; cur != nullptr;) {
//            // nxt指向cur后一个节点
//            nxt = cur->next;
//
//            // cur下一个节点指向pre
//            cur->next = pre;
//            pre = cur;
//
//            if (!nxt) {
//                break;
//            }
//            tmp = nxt->next;
//            nxt->next = cur;
//            cur = tmp;
//            pre = nxt;
//        }
//
//        return pre;
//    }

// 精简版
    ListNode *reverse(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode *pre = nullptr, *cur = head, *nxt = nullptr;
        for (cur = head; cur != nullptr;) {
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

int main() {
    Solution s;
    vector<int> data = {1, 2, 3, 4, 5, 6, 7};
    List *list = new List(data);
    ListNode *head = s.reverse(list->head);
    print_list(head);

}