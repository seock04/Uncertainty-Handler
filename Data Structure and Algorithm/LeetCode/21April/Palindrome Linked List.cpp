/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *p, *q, *mid;
        p = q = head;
        
        while(p != nullptr and p->next != nullptr){
            p = p->next->next;
            q = q->next;
        }
        if(p != nullptr){
            mid = q->next;
        }
        else{
            mid = q;
        }
        
        mid = Reverse(mid);
        
        while(head != nullptr and mid != nullptr){
            if(head->val != mid->val) return false;
            head = head->next;
            mid = mid->next;
        }
        
        return true;        
    }
    
    ListNode* Reverse(ListNode* head)
    {
        ListNode* current, *prev, *next;
        current = head;
        prev = nullptr;
        
        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
};
