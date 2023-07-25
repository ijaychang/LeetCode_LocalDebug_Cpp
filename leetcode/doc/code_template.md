# 反转链表

![reverse_linked_list](reverse_linked_list.gif)
```c++
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
```