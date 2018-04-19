//
// Created by m on 4/18/18.
//

#ifndef LEETCODE_LIST_NODE_H
#define LEETCODE_LIST_NODE_H

#include <iostream>

using namespace std;

template <typename T>
class ListNode
{
public:
    ListNode();
    ListNode(T data);
    ~ListNode();
    void setData(T data);
    T getData();
    void setNext(ListNode<T> *next);
    ListNode* getNext();
    void printData();

public:
    T *val;
    ListNode<T> *next;
};


template <typename T>
ListNode<T>::ListNode()
{
    val = new T;
    next=NULL;
}

template <typename T>
ListNode<T>::ListNode(T data)
{
    val = new T(data);
    next=NULL;
}

template <typename T>
ListNode<T>::~ListNode()
{
    delete val;
    val=NULL;
}

template <typename T>
void ListNode<T>::setData(T data)
{
    *val = data;
}

template <typename T>
T ListNode<T>::getData()
{
    return *val;
}

template <typename T>
void ListNode<T>::setNext(ListNode<T> *next)
{
    this->next = next;
}

template <typename T>
ListNode<T>* ListNode<T>::getNext()
{
    return next;
}

template <typename T>
void ListNode<T>::printData()
{
    if(next != nullptr)
        cout<<*val<< " -> ";
    else
        cout << *val << " -> end" << endl;
}


/**
 * LinkList
 */


using namespace std;

template <typename T>
class LinkList
{
public:
    LinkList();
    ~LinkList();
    bool isListEmpty();
    bool clearList();
    int getListLength();
    int getElemIndex(T &elem);
    bool getListElem(int index,T* elem);
    //bool getListPrevious(int index,T* elem);
    //bool getListNext(int index,T* elem);
    bool ListInsert(int index,T &elem);
    bool ListDelete(int index,T *elem);
    void ListPrint(void);
private:
    ListNode<T> *m_pList;
    int m_iLength;

};

template <typename T>
LinkList<T>::LinkList()
{
    m_pList = new ListNode<T>;
    m_pList->setData(NULL);
    m_pList->setNext(NULL);
    m_iLength=0;
}

template <typename T>
LinkList<T>::~LinkList()
{
    ListNode<T> *nextNode = m_pList;
    while(nextNode->getNext()!=NULL)    //delete ListNode while pointerNext == NULL
    {
        nextNode=m_pList->getNext();
        delete m_pList;
        m_pList = nextNode;
    }
    delete m_pList;//delete last ListNode
    m_pList = NULL;
}

template <typename T>
bool LinkList<T>::isListEmpty()
{
    if(m_iLength==0)
        return true;
    return false;
}


template <typename T>
bool LinkList<T>::clearList()
{
    if(isListEmpty())
    {
        cout<<"List empty clear fail"<<endl;
        return false;
    }

    //delete All node except first node
    ListNode<T> *nowNode = m_pList->getNext();
    ListNode<T> *nextNode = m_pList->getNext();
    while(nextNode->getNext()!=NULL)
    {
        nextNode=nowNode->getNext();
        delete nowNode;
        nowNode = nextNode;
    }
    delete nowNode;//delete last ListNode

    m_iLength = 0;
    m_pList->setNext(NULL);
    return true;
}

template <typename T>
int LinkList<T>::getListLength()
{
    return m_iLength;
}
template <typename T>
int LinkList<T>::getElemIndex(T &elem)
{
    ListNode<T> *tempNode = m_pList;
    for(int i=0;i<m_iLength;i++)
    {
        tempNode = tempNode->getNext();
        if(elem == tempNode->getData())
        {
            return i;
        }
    }
    return -1;
}
template <typename T>
bool LinkList<T>::getListElem(int index,T* elem)
{
    if(index<0 || index>= m_iLength)
    {
        return false;
    }

    ListNode<T> *tempNode = m_pList;
    for(int i=0;i<=index;i++)
    {
        tempNode=tempNode->getNext();
    }

    *elem = tempNode->getData();
    return true;
}



template <typename T>
bool LinkList<T>::ListInsert(int index,T &elem)
{
    //index out of range
    if(index<0 || index>m_iLength)
    {
        return false;
    }

    //
    ListNode<T> *tempPreNode = m_pList;
    for(int i=0;i<index;i++)
    {
        tempPreNode = tempPreNode->getNext();
    }

    ListNode<T> *newnode = new ListNode<T>;    //create a new node
    if(newnode == NULL)
    {
        cout<<"new node create fail"<<endl;
        return false;
    }
    ListNode<T> *tempNode= tempPreNode->getNext();//save pre node pointer
    tempPreNode->setNext(newnode); //set pre node pointer to new node address
    newnode->setNext(tempNode);//set new node pointer to pre node pointer
    newnode->setData(elem);    //set new node new data
    m_iLength++;
    return true;
}

template <typename T>
bool LinkList<T>::ListDelete(int index,T *elem)
{
    //index out of range
    if(index<0 || index>=m_iLength)
    {
        return false;
    }

    //
    ListNode<T> *tempPreNode = m_pList; //pre node
    for(int i=0;i<index;i++)//find pre node
    {
        tempPreNode = tempPreNode->getNext();
    }

    ListNode<T> * tempNode = tempPreNode->getNext();//save delete point pointer
    tempPreNode->setNext(tempNode->getNext());//set pre node  point to next node
    *elem = tempNode->getData();
    delete tempNode;

    m_iLength--;
    return true;
}

template <typename T>
void LinkList<T>::ListPrint(void)
{
    if(isListEmpty())
    {
        cout<<"List empty"<<endl;
        return;
    }
    ListNode<T> *tempNode=m_pList->getNext();
    while(tempNode->getNext() != NULL)
    {
        tempNode->printData();
        tempNode = tempNode->getNext();
    }
    tempNode->printData();
    cout<<"end"<<endl;
}


#endif //LEETCODE_LIST_NODE_H
