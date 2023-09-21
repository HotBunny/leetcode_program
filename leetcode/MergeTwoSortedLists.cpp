#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode *dummy = new ListNode(0); //create a dummy node to avoid edge case
    ListNode *tail = dummy; // tail will point to the last node in the merged list

    while (l1 != nullptr && l2 != nullptr){
        if ( l1->val <= l2->val){
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next; // move tail tot he last node in the merged list
    }

    // at this point, either l1 or l2 has reached the end of the of the list
    if (l1 != nullptr){
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy->next; // return the head of the merged list (after the dummy node)
}

int main(){
    //create the input linked lists
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // merge the two lists
    ListNode *merged = mergeTwoLists(l1, l2);

    // print the merged list
    while (merged != nullptr){
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;

    return 0;
}