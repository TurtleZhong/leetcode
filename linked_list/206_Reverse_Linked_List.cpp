/**
 * Reverse a singly linked list.
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

#include <iostream>
#include "list_node.h"
using namespace std;
typedef Node<int> ListNode;


ListNode* reverseList(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode *p = head;
    ListNode *q = p->next;
    ListNode *r = q->next;

    p->setNext(nullptr);
    while (q->next != nullptr)
    {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    return q;
}

ListNode* reserveList2(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode *new_head = reserveList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}


int main()
{
    /*insert data check*/
    int data[10]={0,1,2,3,4,5,6,7,8,9};
    ListNode *list = new ListNode(data[0]);
    ListNode *pre_node = list;
    for (int j = 1; j < 10; ++j)
    {
        ListNode *tmp = new ListNode(data[j]);
        pre_node->setNext(tmp);
        pre_node = pre_node->next;

    }

//    ListNode *reserve_list = reverseList(list);
    ListNode *reserve_list1 = reserveList2(list);



    ListNode *list_copy = reserve_list1;
    while(list_copy->next)
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