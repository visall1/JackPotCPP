#include<iostream>
#define Forloop(i,count_) for(;i<count_;i++)
using namespace std;
int main(){
    
    const int count = 10;
    int i=0;
    Forloop(i,count){
        cout<<"I hate you "<<endl;
    }
    
    return 0;
}