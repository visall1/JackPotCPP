#include<iostream>
#include<string>
using namespace std;
class CircularQueue {
    string *wait;
    int MaxQueueLength;
    int QueueLength;
public:
    CircularQueue(int m);
    CircularQueue(const CircularQueue &other);
    ~CircularQueue();
    CircularQueue& Add(string n);//enqueue
    string Extract();//dequeue
    bool IsFull();
    bool IsEmpty();
    void Clear();
    friend ostream&operator<<(ostream&os, const CircularQueue&queue);
    CircularQueue&operator<<(string n);
    void Show(int line, int col);
    string operator[](int index);
};

CircularQueue::CircularQueue(int m)
{
    MaxQueueLength = m;
    QueueLength = 0;
    wait = new string[m];
}

CircularQueue::CircularQueue(const CircularQueue &other)
{
    QueueLength = other.QueueLength;
    MaxQueueLength = other.MaxQueueLength;
    wait = new string[MaxQueueLength];
    for(int i=0;i<QueueLength;i++){
        wait[i] = other.wait[i];
    }
}

CircularQueue::~CircularQueue()
{
    delete[]wait;
}

CircularQueue& CircularQueue::Add(string n)
{
    if(!IsFull()){
        wait[QueueLength++] = n;
    }else{
        cout<<"Queue Full! come another time.\n";
    }
    return *this;
}

string CircularQueue::Extract()
{
    if(!IsEmpty()){
        string ret =wait[0];
        for(int i=1;i<QueueLength; i++){
            wait[i-1] = wait[i];
        }
        QueueLength--;
        Add(ret);
        return ret;
    }else{
        cout<<"Queue is Empty!\n";
    }
    return "";
}

bool CircularQueue::IsFull()
{
    return QueueLength==MaxQueueLength;
}

bool CircularQueue::IsEmpty()
{
    return QueueLength == 0;
}

void CircularQueue::Clear()
{
    QueueLength = 0;
}

CircularQueue &CircularQueue::operator<<(string n)
{
    return Add(n);
}

void CircularQueue::Show(int line, int col)
{
    for (int i = 0; i < QueueLength; i++)
    {
        cout<<"\033["<<(line+i)<<";"<<col<<"H";
        cout.width(10);
        cout<<wait[i]<<endl;
    }
    
}

string CircularQueue::operator[](int index)
{
    if(index>=0 && index<QueueLength) return wait[index];
    return string();
}

ostream &operator<<(ostream &os, const CircularQueue &queue)
{
    for(int i=queue.MaxQueueLength-1; i>=0; i-- ){
        os.width(3);
        if(i>=queue.QueueLength){os<<" ";}
        else{os<<queue.wait[i];}
    }
    os<<endl;
    return os;
}
