#pragma once
#include <iostream>
using namespace std;

template <class T>
class stack_t
{
    private:

        stack_t *head;
        stack_t *next;
        T value;


    public:

        stack_t()
        {
            head = NULL;
        }

        bool isEmpty();

        void push(T value);

        float top();

        void pop();

        void print();

        ~stack_t()
        {
            delete head;
            head = NULL;
        }
};


template <class T>
bool stack_t<T>:: isEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}


template <class T>
void stack_t<T>:: push(T value)
{
    stack_t *newelement = new stack_t;
    newelement->value = value;

    stack_t *temp = head; 

    if(isEmpty() == true)
    {
        head = newelement;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newelement;
}


template <class T>
float stack_t<T>:: top()
{
    try{
        stack_t *temp = head;

        if(temp == NULL)
        {
            throw "Error!";
        }

        while(temp->next != NULL)
            temp = temp->next;

        return temp->value;

    }catch(const char *Err)
    {
        cerr << Err << endl;
        return 0;
    }
}


template <class T>
void stack_t<T>:: pop()
{
    try
    {
        stack_t *temp = head;
        
        if(temp == NULL)
        {
            throw "Error!";
        }

        while(temp->next->next != NULL)
            temp = temp->next;

        stack_t *temp2 = temp->next;

        temp->next = NULL;

        delete temp2;

    }catch(const char *Err)
    {
        cerr << Err << endl;
        return;
    }
}


template <class T>
void stack_t<T>:: print()
{
    stack_t *temp = head;

    while(temp != NULL)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
}