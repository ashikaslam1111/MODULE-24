#include<bits/stdc++.h>
using namespace std;
const int maxx=5;
class Queue
{
public:
    int arr[maxx];
    int l,r;
    int sz;
    Queue()
    {
        l=0;
        r=-1;
        sz=0;
    }
    void enqueue(int value)//O(1)
    {
        if(sz==maxx)
        {
            cout<<"full";
            return;
        }
        r++;
        if(r==maxx)
        {
            r=0;
        }
        arr[r]=value;
        sz++;
    }
    void dequeue()//O(1)
    {
        if(sz==0)
        {
            cout<<"empty";
            return;
        }
        l++;
        if(l==maxx)
        {
            l=0;
        }
        sz--;
    }
    int front_()//O(1)
    {
        if(sz==0)
        {
            cout<<"empty";
            return -1;
        }
        return arr[l];
    }
    int size_()//O(1)
    {
        return sz;
    }
};
int main()
{
    Queue l;
    l.enqueue(2);
    l.enqueue(4);
    l.enqueue(9);
    l.enqueue(7);
    l.enqueue(0);
    l.dequeue();
    l.enqueue(3);
    l.dequeue();
    l.dequeue();
    l.dequeue();
    l.dequeue();
    cout<<l.front_();
    return 0;
}
