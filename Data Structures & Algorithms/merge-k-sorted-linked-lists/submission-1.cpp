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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cpm = [](ListNode* a,ListNode*b){return a->val > b->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cpm)> P(cpm);
        for(auto l:lists){
            if(l) P.push(l);
        }
        if(P.empty()) return nullptr;
        ListNode* head=P.top();
        P.pop();
        if(head->next) P.push(head->next);
        head->next=nullptr;
        ListNode* curr=head;
        while(!P.empty()){
            ListNode* n=P.top();
            P.pop();
            curr->next=n;
            curr=n;
            if(n->next) P.push(n->next);
        }
        return head;
    }
};
