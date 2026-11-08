class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {

        head = reverse(head);

        int maxVal = INT_MIN;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr) {

            if(curr->val < maxVal) {
                prev->next = curr->next;
            }
            else {
                maxVal = curr->val;
                prev = curr;
            }

            curr = curr->next;
        }

        return reverse(head);
    }
};