//Program for Heap Data Structure

/*
 * Created by Devashish Katoriya on 10-04-2017
 */

#include <iostream>

using namespace std;

#define MAX 20

template <class T>
class Heap
{
    T array[MAX];
    int n;
    void reHeapUp();
    void reHeapDown();
    inline int parent(int i)
    {
        return i>0 ? (i-1)/2 : 0;
    }
    inline int child(int i)
    {
        return i<=n/2-1 ? (2*i)+1 : -1;
    }
public:
    Heap()
    {
        n = 0;
        /*
        for(int i=0;i<MAX;i++)
            array[i] = -1;
        */
    }
    void insert_element(T);
    T delete_element();
    void display();
    inline bool isEmpty()
    {
        return n==0;
    }
    inline bool isFull()
    {
        return n==MAX-1;
    }
};

template <class T>
void Heap<T>::insert_element(T element)
{
    array[n] = element;
    n++;
    reHeapUp();
}

template <class T>
void Heap<T>::reHeapUp()
{
    T temp;
    for(int i=n-1;i>0;i = parent(i))
    {
        if(array[i] > array[parent(i)])
        {
            temp = array[parent(i)];
            array[parent(i)] = array[i];
            array[i] = temp;
        }
    }
}

template <class T>
void Heap<T>::display()
{
    cout<<"\nThe contents of Heap are \n";
    for(int i=0;i<n;i++)
        cout<<array[i]<<"\t";
}

template <class T>
T Heap<T>::delete_element()
{
    T value;
    value = array[0];
    array[0] = array[n-1];
    n--;
    reHeapDown();
    return value;
}

template <class T>
void Heap<T>::reHeapDown()
{
    T temp;
    for(int i=0;i<=n/2-1;i = child(i))
    {
        if(array[i]<array[child(i)])
        {
            temp = array[i];
            array[i] = array[child(i)];
            array[child(i)] = temp;
        }
    }
}

int main()
{
    Heap <int>obj;
    int ch;
    int value;
    cout<<"\nProgram to Implement Heap Data Structure.";
    do
    {
        ch = 0;
        cout<<"\n\n-------------------------------";
        cout<<"\n 1 for Insertion.";
        cout<<"\n 2 for Deletion.";
        cout<<"\n 3 for Display.";
        cout<<"\n 4 for isEmpty.";
        cout<<"\n 5 for isFull.";
        cout<<"\n 0 for Exit.";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        cout<<"-------------------------------\n";
        switch (ch)
        {
            case 1: cout<<"\nEnter value to insert : ";
                    cin>>value;
                    obj.insert_element(value);
                    cout<<"\nElement Inserted Successfully!";
                    break;
            case 2: value = obj.delete_element();
                    cout<<"\nDeleted element is "<<value;
                    break;
            case 3: obj.display();
                    break;
            case 4: if(obj.isEmpty())
                        cout<<"\nYes, the Heap is Empty!";
                    else
                        cout<<"\nThe Heap is NOT empty";
                    break;
            case 5: if(obj.isFull())
                    cout<<"\nYes, the Heap is Full!";
                    else
                        cout<<"\nThe Heap is NOT full";
                    break;
            case 0: break;
            default:cout<<"\nInvalid Option!";
        }
    }while(ch!=0);
    
    cout<<"\nThank you for using this program :) \n\n";
    return 0;
}