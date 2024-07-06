#include<iostream>
using namespace std;
class PriorityExQueue {
    int *wait;
    int *priority;
    int MaxQueueLength;
    int QueueLength;
public:
    PriorityExQueue(int m);
    ~PriorityExQueue();
    PriorityExQueue& Add(int n, int prio=1);//enqueue
    int Extract();//dequeue
    bool IsFull();
    bool IsEmpty();
    void Clear();
    friend ostream&operator<<(ostream&os, const PriorityExQueue&queue);
    PriorityExQueue&operator<<(int n);
};
int main()
{
    PriorityExQueue q(20);
    cout<<"q.IsEmpty? "<<q.IsEmpty()<<endl;
    cout<<"q.IsFull? "<<q.IsFull()<<endl;
    q.Add(8, 10)
     .Add(10, 10)
     .Add(7, 12)
     .Add(6, 15);
    q<<5<<2<<1;
    cout<<q;
    while(!q.IsEmpty()){
        cout<<"Extracted: "<<q.Extract()<<endl;
        cout<<q;
    }
    return 0;
}

PriorityExQueue::PriorityExQueue(int m)
{
    MaxQueueLength = m;
    QueueLength = 0;
    wait = new int[m];
    priority = new int[m];
}

PriorityExQueue::~PriorityExQueue()
{
    delete[] wait;
}

PriorityExQueue& PriorityExQueue::Add(int n, int prio)
{
    if(!IsFull()){
        wait[QueueLength] = n;
        priority[QueueLength] = prio;
        QueueLength++;
    }else{
        cout<<"Queue Full! come another time.\n";
    }
    return *this;
}

int PriorityExQueue::Extract()
{
    if(!IsEmpty()){
        //find max priority guy
        int mIndex = QueueLength;
        for(int i=mIndex-1;i>=0;i--){
            if(priority[mIndex] <= priority[i]){
                mIndex = i;
            }
        }
        int ret =wait[mIndex];
        for(int i=mIndex+1;i<QueueLength; i++){
            wait[i-1] = wait[i];
            priority[i-1] = priority[i];
        }
        QueueLength--;
        return ret;
    }else{
        cout<<"Queue is Empty!\n";
    }
    return 0;
}

bool PriorityExQueue::IsFull()
{
    return QueueLength==MaxQueueLength;
}

bool PriorityExQueue::IsEmpty()
{
    return QueueLength == 0;
}

void PriorityExQueue::Clear()
{
    QueueLength = 0;
}

PriorityExQueue &PriorityExQueue::operator<<(int n)
{
    return Add(n);
}

ostream &operator<<(ostream &os, const PriorityExQueue &queue)
{
    for(int i=queue.MaxQueueLength-1; i>=0; i-- ){
        os.width(3);
        if(i>=queue.QueueLength){os<<" ";}
        else{os<<queue.wait[i];}
    }
    os<<endl;
    return os;
}
