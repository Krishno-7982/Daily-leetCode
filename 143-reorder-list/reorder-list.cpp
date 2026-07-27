class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        while (second) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // Merge
        ListNode* first = head;
        ListNode* secondHalf = prev;

        while (secondHalf) {
            ListNode* t1 = first->next;
            ListNode* t2 = secondHalf->next;

            first->next = secondHalf;
            secondHalf->next = t1;

            first = t1;
            secondHalf = t2;
        }
    }
};