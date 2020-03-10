#include <iostream>
#include <stdlib.h>
using namespace std;

class Children 
{ 
    private:
    string name, surname;
    string age;

    public:

    void setName()
 {
     bool flag= true;
     string name;
     cout << "Введите имя ребенка: "<<endl;
     cin >> name;
    for (int i=0; i < name.size(); i++) 
{
    if ((name[i]-48 >= 0) && (name[i] - 48 <= 9)){
        cout << "Некорректный ввод данных, попробуйте ввести имя снова!" << endl;
        setName();
        flag= false;
        break;
    }
    
}
    if(flag)
        this->name = name;
 }

    string getName()
 {
     return name;
 }

    void setSurname()
    {
        bool flag= true;
     string surname;
     cout << "Введите фамилию ребенка: "<<endl;
     cin >> surname;
      for (int i=0; i < surname.size(); i++) 
      {
    if ((surname[i]-48 >= 0) && (surname[i] - 48 <= 9)){
        cout << "Некорректный ввод данных, попробуйте ввести фамилию снова!" << endl;
        setSurname();
        flag= false;
        break;
       }}
       if(flag)
        this->surname = surname;
    }

    string getSurname()
 {
     return surname;
 }
  
  void setAge ()
  {
      bool flag= true;
      string age;
      cout<< "Введите возраст ребенка: "<<endl;
      cin>>age;
      for(int i= 0; i<age.length(); i++)
      {
          if(!isdigit(age[i]))
            {
                cout<<"Некорректный ввод данных, попробуйте ввести возраст снова!"<<endl;
                flag= false;
                setAge();
            }
      }
      if(flag)
      {
          int t= atoi(age.c_str());;
          
          if(t>18)
        {
            cout<<"Ваш ребенок вырос!"<<endl;
            setAge();
        }
        else
        {
         this->age= age;
        }
      }
  }
    

    
  string getAge()
  {
      return age;
  }

};

int main(){

    setlocale(LC_ALL, "rus");
    
    Children a;
    a.setName();
    a.setSurname();
    a.setAge();
    cout<<"Информация о ребенке: "<<a.getName()<<" "<<a.getSurname()<<" "<<a.getAge();
    
    cout<<endl<<endl;
    
    Children b;
    b.setName();
    b.setSurname();
    b.setAge();
    cout<<"Информация о ребенке: "<<b.getName()<<" "<<b.getSurname()<<" "<<b.getAge();

    return 0;

}