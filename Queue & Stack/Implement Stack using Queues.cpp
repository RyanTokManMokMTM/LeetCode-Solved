class MyStack {
public:
    queue<int> q;
    queue<int> q2;
    MyStack() {
        
    }
    
    //O(N)
    void push(int x) {
        q2.push(x);
        while(!q.empty()){
            q2.push(q.front());q.pop();
        }
        q = q2;
        clear(q2);
    }
    
    //O(1)
    int pop() {
        if(empty()) return -1;
        int value = q.front();q.pop();
        return value;
    }
    
    void clear(queue<int>& q){
        queue<int> empty;
	    swap(empty, q);
    }
    
    int top() {
        if(empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty() ? true : false; 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
