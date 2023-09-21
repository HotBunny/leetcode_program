#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* head;
    int len;

public:
    Solution(ListNode* h) {
        head = h;
        len = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            len++;
            curr = curr->next;
        }
        srand(time(NULL));
    }

    int getRandom() {
        int idx = rand() % len;
        ListNode* curr = head;
        for (int i = 0; i < idx; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution* obj = new Solution(head);
    cout << obj->getRandom() << endl;
    cout << obj->getRandom() << endl;
    cout << obj->getRandom() << endl;
    return 0;
}
