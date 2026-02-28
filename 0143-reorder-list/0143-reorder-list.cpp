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
    
    void reorderList(ListNode* head) {
        ListNode * f=head;
        ListNode *s=head;
        while(f->next && f->next->next ){
            f=f->next->next;
            s=s->next;
        }
        ListNode* p=s;
        s=s->next;
        p->next=nullptr;
        p=nullptr;
        while(s){
            ListNode* t=s->next;
            s->next=p;
            p=s;
            s=t;
        }
        //cout<<p->next<<" "<<p<<"snxt\n";
        ListNode * nw=head;
        while(nw && p){
            ListNode* m=nw->next;
            nw->next=p;
            ListNode* m2=p->next;
            p->next=m;
            p=m2;
            nw=m;
        }
        return ;
    }
};