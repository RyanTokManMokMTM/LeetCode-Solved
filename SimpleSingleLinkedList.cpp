class MyLinkedList {
    private:
        int val;
        MyLinkedList* next;
        MyLinkedList* firstNode;
        MyLinkedList* pre;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->val = -1;
        this->next = NULL;
        this->firstNode = NULL;
        this->pre = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(this->firstNode == NULL)
            return -1;
        if(index == 0)
            return this->firstNode->val;
        
        MyLinkedList* current = firstNode;
        
        for(int i = 0;i<index;i++){
            current = current->next;
            if(current == NULL)
                return -1;
        }

        return current->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyLinkedList* Node = new MyLinkedList();
        Node->val = val;
        
        if(this->firstNode ==NULL){
            this->firstNode = Node;
            return;
        }
        
        
        MyLinkedList* currentHead = this->firstNode;
        
        Node->next = currentHead;
        this->firstNode = Node;
            
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyLinkedList* Node = new MyLinkedList();
        Node->val = val;
        if(this->firstNode == NULL){
            this->firstNode = Node;
            return;
        }
        
        MyLinkedList* current = this->firstNode;
        
        while(current->next != NULL){
            current = current->next;
        }
        
        current->next = Node;
        
        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == 0){
            this->addAtHead(val);
            return;
        }
        
        MyLinkedList* current = this->firstNode;
        MyLinkedList* Node = new MyLinkedList();
        Node->val = val;
        int i = 0;
        while(i != (index - 1) &&(current->next != NULL)){
            current = current->next;
            i++;
        }
        
        if(current->next == NULL && i!= index -1)
            return;
        
        
        
        if(current->next == NULL){
            this->addAtTail(val);
            return;
        }
        
        
        MyLinkedList* currentNext = current->next;
        
        Node->next= currentNext;
        
        current->next = Node;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(this->firstNode == NULL){
            printf("IS Empty");
            return ;
        }
        
        MyLinkedList* current = this->firstNode;
        if(index == 0){
            printf("index 0");
            this->firstNode = current->next == NULL ? NULL : current->next;
            current->next = NULL;
            delete current;
            return;
        }

        int i;
        for(i = 0;i<index-1;i++){
            current = current->next;
             if(current == NULL){
                 printf("large");
                 //for the case large than last one
                    return;
            }
        }

        printf("%d",current->val);
        if(current->next ==NULL){
            //this for the case  last node +1
            printf("invail index");
            return;
        }
         MyLinkedList* remove = current->next;
        if(remove->next == NULL){
            printf("last");
            current->next = NULL;
        }else{
            printf("Not last");
            MyLinkedList* tempNode = remove->next;
            current->next = tempNode;
        }
        delete remove;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */