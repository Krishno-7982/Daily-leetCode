class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* l = list1;
        ListNode* r = list1;

        // l = node just before a
        for(int i = 0; i < a - 1; i++) {
            l = l->next;
        }

        // r = node just after b
        for(int i = 0; i <= b; i++) {
            r = r->next;
        }

        // connect l to list2
        l->next = list2;

        // go to end of list2
        ListNode* temp = list2;
        while(temp->next != nullptr) {
            temp = temp->next;
        }

        // connect list2 to r
        temp->next = r;

        return list1;
    }
};