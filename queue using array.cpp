#include<bits/stdc++.h>
using namespace std;
 const int maxx=500;
class Queue
{
public:
    int arr[maxx];
    int l,r;
    Queue()
    {
        l=0;
        r=-1;
    }
    void enqueue(int value)//O(1)
    {
        if(r+1>=maxx)
        {
            cout<<"full";
            return;
        }
        r++;
        arr[r]=value;
    }
    void dequeue()//O(1)
    {
        if(l>r)
        {
            cout<<"empty";
            return;
        }
        l++;
    }
    int front_()//O(1)
    {
        if(l>r)
        {
            cout<<"empty";
            return -1;
        }
        return arr[l];
    }
    int size_()//O(1)
    {
        return r-l+1;
    }
};
int main()
{

    Queue l;
    l.enqueue(2);
    l.enqueue(4);
    cout<<l.front_();
    return 0;
}
