class MyCircularQueue {
public:
    vector<int> queue;
    int max = 0;
    int headIndex = 0,tailIndex = -1; //current queue is no element
    int currentVal = 0;
    MyCircularQueue(int k) {
        queue.reserve(k);
        this->max = k;
    }
    
    bool enQueue(int value) {
        //add the value to queue if current queue is not full
        if(this->isFull()) return false;
        //just need to calcuate the tail and insert to tail
        tailIndex = (tailIndex+1)%max;
        queue[tailIndex] = value;
        currentVal ++;
        return true;
        
    }
    
    bool deQueue() {
        if(this->isEmpty()) return false; //the queue is empty
        //no need to erase ,just re-calculate the head
        headIndex = (headIndex+1)%max;
        currentVal --;
        return true;
    }
    
    int Front() {
       return this->isEmpty() ? -1 : queue[headIndex];
    }
    
    int Rear() {
       return this->isEmpty() ? -1 : queue[tailIndex];
    }
    
    bool isEmpty() {
        return currentVal == 0 ;
    }
    
    bool isFull() {
        return currentVal == max ;
    }
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */