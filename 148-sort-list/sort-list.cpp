class Solution {
public:
    ListNode* sortList(ListNode* head) {

        // Base case
        if(head == nullptr || head->next == nullptr)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split
        ListNode* second = slow->next;
        slow->next = nullptr;

        // Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        // Merge
        ListNode dummy(-1);
        ListNode* temp = &dummy;

        while(left && right){
            if(left->val < right->val){
                temp->next = left;
                left = left->next;
            }else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        if(left)
            temp->next = left;

        if(right)
            temp->next = right;

        return dummy.next;
    }
};