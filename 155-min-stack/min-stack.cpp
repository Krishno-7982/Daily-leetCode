class MinStack {
public:
    stack<int> st;
    stack<int> mn;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);

        if(mn.empty()) {
            mn.push(value);
        }
        else {
            mn.push(min(value, mn.top()));
        }
    }
    
    void pop() {
        st.pop();
        mn.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};