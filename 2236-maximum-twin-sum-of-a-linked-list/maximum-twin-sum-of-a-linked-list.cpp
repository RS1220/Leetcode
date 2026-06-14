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
     ListNode* reverseList(ListNode* head) {
      if(head==NULL || head->next==NULL) return head;
      ListNode* newhead=reverseList(head->next);
      head->next->next=head;
      head->next=NULL;
      return newhead;
    }
    int pairSum(ListNode* head) {

       // if(head==NULL || head->next==NULL) return return 


        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }

         ListNode* newHead=slow->next;
         slow->next=nullptr;
        

       slow=head;
    fast=reverseList(newHead);



        int ans=0;
        while(slow!=NULL){
            ans=max(ans , slow->val + fast->val);
            
            slow=slow->next;
            fast=fast->next;
        }

       return ans;
         

    }
};