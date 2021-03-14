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
    ListNode* swapNodes(ListNode* head, int k) {
        
        int count = 0;
        
        ListNode* left;
        ListNode* right;
        
        ListNode* h = head;
        while(h){
            if(count == k-1){
                left = h;
                cout << count << h->val << "\n";
            }            
            
            count += 1;
            h = h->next;
        }
        
        int rindex = count - k;
        
        h = head;
        count = 0;
        while(h){
            if(count == rindex){
                right = h;
                cout << count << h->val << "\n";
            }            
            
            count += 1;
            h = h->next;
        }
        
        int t = left->val;
        left->val = right->val;
        right->val = t;
        
        return head;
    }
};
