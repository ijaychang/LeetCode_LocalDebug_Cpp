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
    // 三指针技巧反转链表
    ListNode* reverse(ListNode* head) {
        // 初始 cur 指向头节点，prev 为 nullptr，next 为 nullptr
        ListNode *cur = head,*prev = nullptr,*next = nullptr;
        for (;cur != nullptr;) {
            // 令 next 指向 cur 的后一个节点
            next = cur->next;
            // cur->next 指针指向 prev
            cur->next = prev;
            // prev 用于记录之前的 cur 所指向的节点
            prev = cur;
            // 将 cur 移动到下一个节点
            cur = next;
        }
        // prev 为原链表的最后一个节点
        return prev;
    }

};

int main() {
    Solution s;
    vector<int> data = {1, 2, 3, 4, 5, 6, 7};
    List *list = new List(data);
    ListNode *head = s.reverse(list->head);
    print_list(head);

}