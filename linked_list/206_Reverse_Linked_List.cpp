/**
 * Reverse a singly linked list.
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

#include <iostream>
#include "list_node.h"
using namespace std;


ListNode<int>* reverseList(ListNode<int>* head)
{
    ListNode<int> *p = head;
    ListNode<int> *q = p->next;
    ListNode<int> *r = q->next;

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


int main()
{
    /*insert data check*/
    int data[10]={0,1,2,3,4,5,6,7,8,9};
    ListNode<int> *list = new ListNode<int>(data[0]);
    ListNode<int> *pre_node = list;
    for (int j = 1; j < 10; ++j)
    {
        ListNode<int> *tmp = new ListNode<int>(data[j]);
        pre_node->setNext(tmp);
        pre_node = pre_node->next;

    }

    ListNode<int> *reserve_list = reverseList(list);


    ListNode<int> *list_copy = reserve_list;
    while(list_copy->next)
    {
        list_copy->printData();
        list_copy = list_copy->getNext();
    }
    list_copy->printData();


//    LinkList<int> *list_node = new LinkList<int>;
//    for(int i=0;i<5;i++)
//    {
//        list_node->ListInsert(i,data[i]);
//    }
//    list_node->ListPrint();

    return 0;
}