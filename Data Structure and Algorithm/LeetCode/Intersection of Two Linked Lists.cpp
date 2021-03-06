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
    }
};
