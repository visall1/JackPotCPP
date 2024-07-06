#include<iostream>
#include<thread>
#include<string>
#include "CircularQueue.cpp"
using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

// This is the main function that runs the game.
int main()
{
    // Create a CircularQueue object with a maximum length of 20.
    CircularQueue q(20);
    
    // Add countries to the queue (using the Add() function).
    q.Add("Spain")
     .Add("France")
     .Add("Portugal")
     .Add("Germany");
    
    // Add more countries to the queue using the << operator.
    q<<"Netherland"<<"Swiss"<<"England"<<"Japen";
    
    // Create copies of the queue objects.
    CircularQueue q2 = q;
    CircularQueue q3 = q;
    
    // Clear the screen and hide the cursor.
    cout<<"\033[2J";
    cout<<"\033[?25l";
    
    // Generate random numbers.
    srand(time(NULL));
    int i1=rand()%10 + 20;
    int i2=rand()%10 + 20;
    int i3=rand()%10 + 20;
    
    // Find the maximum of the three random numbers.
    int m = max(i1,max(i2,i3));
    
    // Game loop.
    for(int i=0; i<m;i++){
        // If the first random number is greater than 0,
        // extract an element from the first queue.
        if(i1-->0) q.Extract();
        
        // If the second random number is greater than 0,
        // extract an element from the second queue.
        if(i2-->0||i2==m) q2.Extract();
        
        // If the third random number is greater than 0,
        // extract an element from the third queue.
        if(i3-->0||i3==m) q3.Extract();
        
        // Display the current state of the queues.
        q.Show(1,1);
        q2.Show(1,12);
        q3.Show(1,23);
        
        // Wait for a short period of time.
        sleep_for(i*5ms);
    }

    // Check if the first, second, and third countries in
    // all the queues are the same.
    if(q[3]==q2[3] && q2[3]==q3[3]){
        cout<<"You hits the Jackpot.\n";
    }
    // Check if the second country in the first queue is the same as the third
    // country in the second queue, and the third country in the second queue is
    // the same as the fourth country in the third queue.
    else if(
        (q[2]==q2[3] && q2[3]==q3[4]) ||
        (q[4]==q2[3] && q2[3]==q3[2])
    ){
        cout<<"Bingo!!\n";
    }
    
    // Return 0 to indicate successful execution.
    return 0;
}

