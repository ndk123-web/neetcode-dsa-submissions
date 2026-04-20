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
    int getGcd(int a, int b) {
        if (b == 0)
            return a;
        return getGcd(b, (a % b));
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* track = head;
        ListNode* prev = head;

        while (track != nullptr && track->next != nullptr) {
            prev = track;
            track = track->next;

            int a = prev->val;
            int b = track->val;
            int gcd = this->getGcd(a, b);

            prev->next = new ListNode(gcd);
            prev = prev->next;
            prev->next = track;
        }

        return head;
    }
};