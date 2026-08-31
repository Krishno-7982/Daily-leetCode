class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* prev = head;
        ListNode* curr = head->next;

        int first = -1;
        int last = -1;
        int position = 2;
        int minDist = INT_MAX;

        while (curr->next != nullptr) {
            
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (first == -1) {
                    first = position;
                    last = position;
                }
                else {
                    minDist = min(minDist, position - last);
                    last = position;
                }
            }

            prev = curr;
            curr = curr->next;
            position++;
        }

        if (first == -1 || first == last) {
            return {-1, -1};
        }

        int maxDist = last - first;

        return {minDist, maxDist};
    }
};