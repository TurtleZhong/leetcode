/**
 * Reverse a linked list from position m to n. Do it in one-pass.
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * Example:
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 */

#include <iostream>
#include "list_node.h"
using namespace std;



typedef Node<int> ListNode;

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if(m == n || head == NULL)
        return head;

    ListNode* p = NULL;
    ListNode* q = head;
    for (int i = 0; i < m-1; ++i)
    {
        p = q;
        q = p->next;
    }

    ListNode* end = q;
    ListNode* q_prev = q;
    q = q->next;
    ListNode* q_next = q->next;

    for (int j = m; j < n-1; ++j)
    {
        q->next = q_prev;
        q_prev = q;
        q = q_next;
        q_next = q_next->next;

    }
    q->next = q_prev;
    if(p)
        p->next = q;
    else
        head = q;

    end->next = q_next;
    return head;
}

int main()
{
    /*insert data check*/
    int data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *list = new ListNode(data[0]);
    ListNode *pre_node = list;
    for (int j = 1; j < 2; ++j)
    {
        ListNode *tmp = new ListNode(data[j]);
        pre_node->setNext(tmp);
        pre_node = pre_node->next;

    }

    ListNode* list1 = reverseBetween(list, 1, 2);


    ListNode *list_copy = list1;
    while (list_copy->next)
    {
        list_copy->printData();
        list_copy = list_copy->getNext();
    }
    list_copy->printData();


//    LinkList *list_node = new LinkList;
//    for(int i=0;i<5;i++)
//    {
//        list_node->ListInsert(i,data[i]);
//    }
//    list_node->ListPrint();

    return 0;
}
