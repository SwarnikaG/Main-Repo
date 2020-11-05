class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    queue<int> q1;
    queue<int> q2;
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        // Leave one element in q1 and push others in q2. 
        while(q1.size()>1) {
            q2.push(q1.front());
            q1.pop();
        }
		// Pop the only left element from q1 
        int ans = q1.front();
        q1.pop();
        // swap the names of two queues 
        queue<int> x = q2;
        q2=q1;
        q1=x;
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (q1.size()==0);
    }
};