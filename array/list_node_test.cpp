#include <iostream>
#include "list_node.h"
using namespace std;

int main()
{
    /*insert data check*/
    int data[10]={0,1,2,3,4,5,6,7,8,9};
    ListNode<int> *list_node = new ListNode<int>;
    for(int i=0;i<5;i++)
    {
        list_node->ListInsert(i,data[i]);
    }
    list_node->ListPrint();

    return 0;
}