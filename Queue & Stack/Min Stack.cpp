class MinStack {
public:
    stack<int> minStack;
    stack<int> value;
    MinStack() {
        //do nothing
    }
    
    void push(int val) {
        if(minStack.empty() || val <= minStack.top())
            minStack.push(val);
        value.push(val);
    }
    
    void pop() {
        if(value.empty()) return;
        if(minStack.top() == value.top())
            minStack.pop();
        
        value.pop();
    }
    
    int top() {
        return !value.empty() ? value.top() : -1;
    }
    
    int getMin() {
        return !minStack.empty() ? minStack.top() : -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */