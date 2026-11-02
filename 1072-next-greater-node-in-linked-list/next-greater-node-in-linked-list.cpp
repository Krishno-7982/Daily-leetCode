class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = nullptr;

        // Reverse the linked list
        while(curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        vector<int>ans;
        stack<int>st;
        while(prev!=nullptr){
            while(!st.empty() && st.top() <= prev->val){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(st.top());
            }
            st.push(prev->val);
            prev = prev->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};