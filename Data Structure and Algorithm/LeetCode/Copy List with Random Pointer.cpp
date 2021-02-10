/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    Node* copyRandomList(Node* head) {
        
        if(head == nullptr) return head;
        
        Node newHead(0);
        Node* newCur;

        Node* org = head;
        newCur = &newHead;
        
        unordered_map<Node*, Node*> m;
        
        while(org){
            newCur->next = new Node(org->val);

            m[org] = newCur->next;
            org = org->next;
            
            newCur = newCur->next;           
        }
        
        org = head;
        while(org)
        {
            if(org->random){
                m[org]->random = m[org->random];    
            }
            
            org = org->next;            
        }
        
        return newHead.next;
    }
    
};
