/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        
        map<ListNode*,int> exist;
        
        ListNode* loop = head;

        while(loop != NULL){ //if not exist faster addr keep loop
            if(exist.find(loop) != exist.end())
                return true;
            exist.insert(pair<ListNode*,int>(loop,0));
            loop = loop->next;
            // it need at least o(n) to loop over all and add to the tree
            //it need at most O(n) space to store all element to the tree node
        }
        return false;
    }
};

//using the std::map(RBTree) to find,a bit slower and O(N) space