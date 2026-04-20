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
private:

    int getGcd(int a, int b) {
        if (b == 0) 
            return a;
        
        return getGcd(b, (a % b));
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* newHead = new ListNode(head->val);
        ListNode* root = newHead;
        ListNode* track = head;

        while(track != nullptr) {
            int a = track->val;
            track = track->next;

            if (track == nullptr) 
                return root;

            int b = track->val;

            int gcd = getGcd(a,b);
            newHead->next = new ListNode(gcd);

            newHead = newHead->next;

            newHead->next = new ListNode(track->val);
            newHead = newHead->next;
        }

        return root;
    }
};