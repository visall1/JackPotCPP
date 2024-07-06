#include<iostream>
using namespace std;
class Circle
{
private:
   int radius;
public:
    Circle(int r): radius(r){}
    void Show(){
        cout<<"Circle with radius: "<<radius<<endl
        <<"Parimeter : "<<(2*radius*3.14)<<endl
        <<"Surface : "<<(radius*radius*3.14)<<endl;
    }

    friend Circle operator+(int number,Circle&r);
    Circle operator+(int number){
        return Circle(radius+number);
    }
};

Circle operator+(int number,Circle &r)
{
    return Circle(number+r.radius);
}
int main(){
    Circle c1(3);
    Circle c2 = c1 + 2;
    Circle c3 = 4 + c2;

    c1.Show();
    c2.Show();
    c3.Show();
}
