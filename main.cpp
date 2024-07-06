#include<iostream>
#include<thread>
#include<string>
#include "CircularQueue.cpp"
using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

int main()
{
    CircularQueue q(20);
    //cout<<"q.IsEmpty? "<<q.IsEmpty()<<endl;
    //cout<<"q.IsFull? "<<q.IsFull()<<endl;
    q.Add("Spain")
     .Add("France")
     .Add("Portugal")
     .Add("Germany");
    q<<"Netherland"<<"Swiss"<<"England"<<"Japen";
    CircularQueue q2 = q;
    CircularQueue q3 = q;
    
    cout<<"\033[2J";//clear screen
    cout<<"\033[?25l";//hide cursor
    //cout<<"\033[8;5H";//move cursor to line 3, column 5
    //cout<<"Hello";
    srand(time(NULL));
    int i1=rand()%50;
    int i2=rand()%50;
    int i3=rand()%50;
    int m = max(i1,max(i2,i3));
    for(int i=0; i<m;i++){
        if(i1-->0) q.Extract();
        if(i2-->0) q2.Extract();
        if(i3-->0) q3.Extract();
        q.Show(1,1);
        q2.Show(1,12);
        q3.Show(1,23);
        sleep_for(i*10ms);
    }
    if(q[3]==q2[3] && q2[3]==q3[3]){
        cout<<"You hits the Jackpot.\n";
    }else if(
        (q[2]==q2[3] && q2[3]==q3[4]) ||
        (q[4]==q2[3] && q2[3]==q3[2])
    ){
        cout<<"Bingo!!\n";
    }
    return 0;
}
