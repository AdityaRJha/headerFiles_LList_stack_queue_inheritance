#include "lcq.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;


base::base(/* args */)
{
    head = NULL;
    num = 0;
}

void base::deleteNode(int n)
{
    if(head != NULL)
    {
        while (n)
        {
            --n;
            node* temp = head ->next;
            head ->next = head ->next ->next;
            delete[] temp;
            --num;
        }      
        
    }
}

base::~base()
{
    while(head != NULL)
    {
        deleteNode(1); // to deleted the first to be deleted
    }
}

node* base::createNode(int data)
{
    node *send = new node();
    send ->data = data;
    return send;
}

void base::display()
{
    if (head != NULL)
    {
        node* temp = head ->next;
        while(temp != NULL)
        {
            cout<<temp->data<<endl;
        }
    }    
}

llist::llist(/* args */):base()
{
}

void llist::insertSortedAs(int data)
{
    node* temp = head;
    if (head != NULL)
    {
        while (temp != NULL)
        {
            if (temp -> next ->data <= data && temp ->next ->next ->data > data)
            {
                node* newNode = createNode(data);
                newNode -> next = temp ->next ->next;
                temp ->next = newNode;
                ++num;
                return;
            }
            else if (temp ->next == NULL && temp ->next ->data <= data)
            {
                node* newNode = createNode(data);
                temp ->next = newNode;
                ++num;
                return;
            }
            else if(temp -> next ->data <= data && temp ->next ->next == NULL)
            {
                node* newNode = createNode(data);
                newNode -> next = temp ->next ->next;
                temp ->next = newNode;
                ++num;
                return;
            }
            temp = temp ->next;
            
        }
    }
    else
    {
        node* newNode = createNode(data);
        head -> next = newNode;
        ++num;
        return;
    }  
    
}


llist::~llist()
{
    while(head != NULL)
    {
        deleteNode(1); // to deleted the first to be deleted
    }
    
}

stack::stack(/* args */):base()
{
}


void stack::insertAtTop(int data)
{
    node* newNode = createNode(data);
    newNode -> next = head;
    head = newNode;
}

stack::~stack()
{
    while(head != NULL)
    {
        deleteNode(1); // to deleted the first to be deleted
    }
}

queue::queue(/* args */):base()
{
    rear ->next = head;
}

void queue::insertAtRear(int data)
{
    node* newNode = createNode(data);
    newNode -> next = head;
    head = newNode;
}

void queue::deleteFromFront(int n)
{
    node* temp = rear ->next;
    if(temp ->next != head)
    {
        while (n)
        {
            --n;
            delete[] head;
            head = temp;
            --num;
        }      
        
    } 
}

queue::~queue()
{
    if(rear != NULL)
    {
        while (rear -> next = head)
        {
           deleteFromFront(1);
        }      
        
    }
}