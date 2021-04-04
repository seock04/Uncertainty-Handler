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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
/*
        unordered_map<ListNode*, int> hashmap;
        
        for(ListNode * iter = headA; iter != nullptr; iter = iter->next){
            hashmap[iter] = 1;
        }
        
        for(ListNode * iter = headB; iter != nullptr; iter = iter->next){
            if(hashmap[iter] == 1){
                return iter;
            }
        }
        
        return nullptr;
  */      
        
        //or
        vector<ListNode*> stackA;
        vector<ListNode*> stackB;
        
        while(headA != nullptr){
            stackA.push_back(headA);
            cout << stackA.back() << "\n";
            headA = headA->next;
        }
        
        while(headB != nullptr){
            stackB.push_back(headB);
            cout << stackB.back() << "\n";
            headB = headB->next;
        }
        
        ListNode* result = nullptr;
        while(!stackA.empty() and !stackB.empty() and stackA.back() == stackB.back()){
            cout << stackA.back() << " " << stackB.back() << "\n";
            result = stackA.back();
            stackA.pop_back();
            stackB.pop_back();
        }        
        
        return result;          
            
    }
};
