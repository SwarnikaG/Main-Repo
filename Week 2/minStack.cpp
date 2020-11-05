class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> minst;
    MinStack() {
    }
    
    void push(int x) {
        st.push(x);
        if(minst.size()==0 or x<=minst.top())
            minst.push(x);
    }
    
    void pop() {
        int temp=st.top();
        st.pop();
        if(minst.top()==temp)
            minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */