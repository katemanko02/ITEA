#include <iostream>
#include <string>
using namespace std;
using information_t = string;
int main()
{
    information_t name;
    information_t surname;
    auto year = 0;
    
    cout<<"Enter your name:"<<endl;
    cin>>name;
    
    cout<<"Enter your surname:"<<endl;
    cin>>surname;
    
    cout<<"Enter your year:"<<endl;
    cin>>year;
    
    cout<<"Your personal information is:"<<name<<" "<<surname<<" "<<year<<endl;
    
    return 0;
}