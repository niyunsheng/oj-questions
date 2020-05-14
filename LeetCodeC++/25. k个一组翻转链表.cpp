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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* ans=new ListNode(0);
        ListNode* tail=ans;//带头尾节点的单链表
        ListNode* tmp=head;
        int n=0;
        while(tmp){tmp=tmp->next;n++;}
        n/=k;
        while(n--){
            for(int i=0;i<k;i++){
                tmp=head;
                //printf("%d\n",head->val);
                head=head->next;
                tmp->next=tail->next;
                tail->next=tmp;
            }
            while(tail->next)tail=tail->next;
        }
        tail->next=head;
        return ans->next;
    }
};
