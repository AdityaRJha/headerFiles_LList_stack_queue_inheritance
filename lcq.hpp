#pragma once
#if !defined(LCQ_H)
#define LCQ_H

struct node
{
    int data;
    node* next;
};

class base
{
protected:
    node *head; //remember our head never stores any value.
    int num;
public:
    base();
    node* createNode(int data);
    void display();
    void deleteNode(int n);
    ~base();
};

class llist: public base
{
private:
    /* data */
public:
    llist(/* args */);
    void insertSortedAs(int data);
    ~llist();
};

class stack: public base
{
private:
    /* data */
public:
    stack(/* args */);
    void insertAtTop(int data);
    ~stack();
};

class queue: public base
{
private:
    node* rear;

public:
    queue(/* args */);
    void insertAtRear(int data);
    void deleteFromFront(int n);
    ~queue();
};


#endif