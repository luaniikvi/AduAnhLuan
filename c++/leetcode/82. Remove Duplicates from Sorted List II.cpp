#include "_lib.h"
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
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode * dummy = new ListNode(0,head);
            ListNode * prev = dummy;
            ListNode * curr = head;

            while (curr)
            {
                bool isDuplicate = false;
                while( curr->next != nullptr && curr->val == curr->next->val ){
                    isDuplicate = true;
                    curr = curr->next;
                }

                if(!isDuplicate){
                    prev->next = curr;
                    prev = prev->next;
                }
                else
                    prev->next = curr->next;

                
                curr = curr->next;
            }
            return dummy->next;
        }      
};