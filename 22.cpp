#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 
 
class Student { 
 
public: 
  string name; 
  string surname; 
  int year_of_birth; 
  int year_of_entire; 
  string budget; 
  bool scholarship; 
  void print() 
  { 
      cout<<name<<" "<<surname<<" "<<year_of_birth<<" " <<year_of_entire<<" "<<budget<<" ";
      if(scholarship)
        cout<<"Has scholarship"<<endl;
      else
        cout<<"Has no scholarship"<<endl;
  } 
 
}; 
 
int main() 
{ 
    setlocale(0, ""); 

    int k = 0;
    cout << "Enter the amount of students in DB: "<<endl;
    cin >> k;
  Student* stud = new Student [k]; 
    char T;
  for (int i = 0; i < k  ; i++){
      cout <<  "Enter the name of the student: "<< endl;
      cin >> stud[i].name;
      cout <<  "Enter the surname of the student: "<< endl;
      cin >> stud[i].surname;
      cout <<  "Enter the year of birth of the student: "<< endl;
      cin >> stud[i].year_of_birth;
      cout <<  "Enter the year of entire of the student: "<< endl;
      cin >> stud[i].year_of_entire;
      cout<<"Is student on budget? Y/N"<< endl;
      cin>>T;
      if(T=='Y')
        stud[i].budget= "budget";
      else 
         stud[i].budget= "contract";
        
      cout<<"Is student with scholarship? Y/N"<<endl;
      cin>>T;
      if(T=='Y')
        stud[i].scholarship = true;
  }
  
 cout << endl;
 cout << "All your DB is: " << endl;
 
    for(int i= 0; i < k;i++) 
    { 
        stud[i].print(); 
    } 
    
     int temp; 
    cout<<"Enter the entry year: "<<endl; 
    cin>>temp; 
    for(int i= 0; i < k; i++) 
    { 
        if(stud[i].year_of_entire==temp) 
            stud[i].print(); 
        else if(stud[i].year_of_entire!=temp) 
        {
        cout<<"You do not have such student in the DB!"<<endl;
        break;
            
        }
    } 
    
    cout<<"Students on budget:"<<endl; 
    for(int i= 0; i < k; i++) 
    { 
        if(stud[i].budget=="budget") 
            stud[i].print(); 
    } 
    
 
    cout<<"Enter the birth year"; 
    cin>>temp; 
    int counter= 0;
    for(int i= 0; i < k; i++) 
    { 
        if(stud[i].year_of_birth==temp) {
            stud[i].print(); 
            counter++;}
    } 
if(k!=1 && counter > 1){
     Student buf;
    cout<<"Students sorted by year of birth";
    for(int i= 0; i<k;i++)
    {
        for(int j= 0; j<k-i-1; j++)
        {
            if(stud[j].year_of_birth<stud[j+1].year_of_birth)
            {
                buf= stud[j];
                stud[j]= stud[j+1];
                stud[j+1]= buf;
            }
            else
            {
                if(stud[j].year_of_birth==stud[j+1].year_of_birth)   
                {
                    if(stud[j].surname[0]>stud[j+1].surname[0])
                    {
                            buf= stud[j];
                            stud[j]= stud[j+1];
                            stud[j+1]= buf;
                    }
                    
                }
            }
        }
    }
    }
    return 0;
}