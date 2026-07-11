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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;   // <-- Missing line

        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* prevnode = nullptr;
        ListNode* nextnode = nullptr;

        for (int i = 0; i <= right - left; i++) {
            nextnode = curr->next;
            curr->next = prevnode;
            prevnode = curr;
            curr = nextnode;
        }

        ListNode* tail = prev->next;
        prev->next = prevnode;
        tail->next = curr;

        return dummy->next;
    }
};