class MyQueue {
public:
    stack<int> stackA;
    stack<int> stackB;
    MyQueue() {
    }
    
    //O(1)
    void push(int x) {
        stackA.push(x);
    }
    
    //O(1)
    int pop() {
        int front  = peek();
        stackB.pop();
        return front;
    }
    
    //O(N) -> get top and pop from A to B
    int peek() {
        //check the front is empty?
        if(stackB.empty()){
            //push all A elements to B
            while(!stackA.empty()){
                stackB.push(stackA.top());
                stackA.pop();
            }
        }
        return stackB.top();
    }
    
    //O(1)
    bool empty() {
      return stackA.empty() && stackB.empty() ? true:false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */