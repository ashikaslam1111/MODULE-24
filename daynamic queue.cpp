#include<bits/stdc++.h>
using namespace std;
const int maxx=5;
class Queue
{
public:
    int* arr;
    int cap;
    int l,r;
    int sz;
    Queue()
    {
        arr=new int[1];
        l=0;
        r=-1;
        sz=0;
        cap=1;
    }
    void remove_circular()
    {
        if(l>r)
        {
            int *temp=new int[cap];
            int indx=0;
            for(int i=l; i<cap; i++)
            {
                temp[indx]= arr[i];
                indx++;
            }
            for(int i=0; i<=r; i++)
            {
                temp[indx]=arr[i];
                indx++;
            }
            swap(temp,arr);
            l=0;
            r=cap-1;
            delete [] temp;
        }
    }
    void increas_size()
    {
        remove_circular();
        int *temp=new int[cap*2];
        for(int i=0; i<cap; i++)
        {
            temp[i]=arr[i];
        }
        swap(arr,temp);
        cap=cap*2;
        delete [] temp;
    }
    void enqueue(int value)//O(1)
    {
        if(sz==cap)
        {
            cout<<"full";
            return;
        }
        r++;
        if(r==cap)
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
        if(l==cap)
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

