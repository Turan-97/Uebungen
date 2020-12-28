#pragma once

#include <iostream>

using namespace std;


template <class T>
class heap_t
{
    private:
        
        heap_t *head;
        heap_t *next = NULL;
        T value = 0;


    public:

        heap()
        {
            head = NULL;
        }

        heap(int *values)
        {
            head = NULL;

            for(int i = 0; i < 99; i++)
                insert(*value);
        }

        bool isEmpty();

        void insert(T value);

        T minimum();

        void extractMin();

        void printArray();

        ~heap()
        {
            delete head;
        }
};


template <class T>
bool heap_t<T>:: isEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}


template <class T>
void heap_t<T>:: insert(T value)
{
    heap_t *new_element = new heap_t;
    new_element->value = value;

    if(isEmpty() == true)
    {
        head = new_element;
        return;
    }
    
    heap_t *temp = head;
    
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new_element;
}


template <class T>
T heap_t<T>:: minimum()
{
    try
    {
        if(isEmpty() == true)
            throw "Minimum existiert nicht, da der heap leer ist.\nProgramm wird beendet!\n";

        heap_t *temp = head;
        T Min = temp->value;

        while(temp->next != NULL)
        {
            temp = temp->next;
            if(Min < temp)
                Min = temp->value;
        }

        return Min;

    }catch(const char *err)
    {
        cerr << err << endl;
    };
}


template <class T>
void heap_t<T>:: extractMin()
{
    try
    {
        if(isEmpty() == true)
            throw "Minimum konnte nicht geloescht werden, da der heap leer ist.\nProgramm wird beendet!\n";

        delete minimum();

    }catch(const char *err)
    {
        cerr << err << endl;
    };
}


template <class T>
void heap_t<T>:: extractMin()
{
    try
    {
        if(isEmpty() == true)
            throw "Minimum konnte nicht geloescht werden, da der heap leer ist.\nProgramm wird beendet!\n";

        delete minimum();

    }catch(const char *err)
    {
        cerr << err << endl;
    };
}


template <class T>
void heap_t<T>:: printArray()
{
    try
    {
        if(isEmpty() == true)
            throw "heap ist leer.\nKeine Ausgabe moeglich.\n";

        int n = 0;
        heap_t *temp = head;

        while(temp != NULL){
            cout << temp->value << endl;
            temp = temp->next;
        }

    }catch(const char *err)
    {
        cerr << err << endl;
    };
}
