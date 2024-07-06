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

/**
 * Constructor for CircularQueue class.
 * Initializes the instance variables of the class.
 * 
 * @param m The maximum length of the queue.
 */
CircularQueue::CircularQueue(int m)
{
    // Set the maximum length of the queue.
    MaxQueueLength = m;
    
    // Initialize the QueueLength to 0.
    // This means that the queue is empty at the beginning.
    QueueLength = 0;
    
    // Create a new array of strings with the size of MaxQueueLength.
    // This array will be used to store the elements of the queue.
    wait = new string[m];
}

/**
 * Copy constructor for the CircularQueue class.
 * Initializes a new CircularQueue object with the same elements as the 
 * object being copied.
 * 
 * @param other The CircularQueue object being copied.
 */
CircularQueue::CircularQueue(const CircularQueue &other)
{
    // Set the QueueLength to the same value as the object being copied.
    QueueLength = other.QueueLength;
    
    // Set the MaxQueueLength to the same value as the object being copied.
    MaxQueueLength = other.MaxQueueLength;
    
    // Create a new array of strings with the size of MaxQueueLength.
    // This array will be used to store the elements of the queue.
    wait = new string[MaxQueueLength];
    
    // Loop through each element in the original queue and copy it to the new queue.
    for(int i=0;i<QueueLength;i++){
        // Copy the element at index i in the original queue to the new queue.
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

/**
 * @brief Get the element at the specified index in the queue.
 * 
 * This function returns the element at the specified index in the queue.
 * If the index is within the valid range of the queue, the function returns
 * the element at that index. Otherwise, it returns an empty string.
 * 
 * @param index The index of the element to retrieve.
 * @return The element at the specified index, or an empty string if the index
 * is out of range.
 */
string CircularQueue::operator[](int index)
{
    // Check if the index is within the valid range of the queue.
    if(index>=0 && index<QueueLength) {
        // If the index is valid, return the element at that index.
        return wait[index];
    } else {
        // If the index is out of range, return an empty string.
        return string();
    }
}

ostream &operator<<(ostream &os, const CircularQueue &queue)
{
    for(int i=queue.MaxQueueLength-1; i>=0; i--){
        os.width(3);
        if(i>=queue.QueueLength){os<<" ";}
        else{os<<queue.wait[i];}
    }
    os<<endl;
    return os;
}
