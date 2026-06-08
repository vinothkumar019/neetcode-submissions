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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (l1 || l2 || carry) {

            int s1 = (l1 ? l1->val : 0);
            int s2 = (l2 ? l2->val : 0);

            int sum = s1 + s2 + carry;

            carry = sum / 10;
            int digit = sum % 10;

            ListNode* node = new ListNode(digit);

            if (head == nullptr) {
                head = node;
                tail = node;
            } else {
                tail->next = node;
                tail = tail->next;
            }

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return head;
    }
};