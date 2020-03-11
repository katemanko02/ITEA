#include <iostream>
#include <cstdlib>
 
 using namespace std;
 
class Boxer //класс Боксер
{
    private:
    int hP;
   
    public:
    Boxer(int HealthPoint) // конструктор класса
    {
        setHealthPoint(HealthPoint); // вызов функции установки здоровья
    }
   
    void setHealthPoint(int HealthPoint) // установка Здоровья
    {
        //Сеттер для установки значения здоровья боксеров
        hP = HealthPoint;
    }
    int getHealthPoint()
    {
        //Геттер для доступа к здоровью боксеров
        return hP;
    }
    void printHealthPoint()
    {
        cout << "Health Point is: "<< hP << " !!!" << endl;
    }
};
 
 
 
int main() {
    //Устанавливаем стартовое значение здоровья для боксеров
 
    Boxer playerBoxer(100), computerBoxer(100);
   
    //Приравниваю показатели здоровья переменным для использования.
    int countPlayerHP{playerBoxer.getHealthPoint()};
    int countComputerHP{computerBoxer.getHealthPoint()};
   
   
    while (countPlayerHP > 0 && countComputerHP > 0){
    // Игровое поле
       
       
        int theHitsOf_Player{0}; //Удар который вы выберете (Всего их 3)
        int theHitsOf_Copmuter{1 + rand() % 3};//Рандом от 1 до 3 включительно для компьютера
        cout <<"Выберите, куда хотите УДАРИТЬ! (1-Голову|2-Печень|3-Корпус)" << endl;
        cin >> theHitsOf_Player;
 
       
       
        int checkGuard_Player{0}; //Защита которую вы выберете (Всего их 3)
        int checkGuard_Computer{1 + rand() % 3};//Рандом от 1 до 3 включительно для Компьютера
       
       
        //Выбор ударов для Игрока
        switch (theHitsOf_Player) {
            case 1:
                cout << "вы бьете противника в голову" << endl;
                if (checkGuard_Computer == theHitsOf_Player) {
                    cout << "Удар заблокирован!" << endl;
                } else {
                countComputerHP -= 20; //Удар в голову
                    cout << "Copmuter HP: " << countComputerHP << endl;}
                    break;
               
            case 2:
                cout << "Вы бьете противника в печень" << endl;
                if (checkGuard_Computer == theHitsOf_Player) {
                    cout << "Удар заблокирован!" << endl;
                } else {
                countComputerHP -= 33; //Удар в печень
                    cout << "Copmuter HP: " << countComputerHP << endl;}
                    break;
                   
            case 3:
                cout << "Вы бьете противника по корпусу" << endl;
                if (checkGuard_Computer == theHitsOf_Player) {
                    cout << "Удар заблокирован!" << endl;
                } else {
                countComputerHP -= 5; //Удар по корпусу
                    cout << "Copmuter HP: " << countComputerHP << endl;}
                    break;
 
            default:
                 cout << "Выберите 1, 2 или 3 удар!" << endl;
                break;
        }
       
        cout <<"Выберите, что хотите ЗАЩИТИТЬ! (1-Голову|2-Печень|3-Корпус)" << endl;
        cin >> checkGuard_Player;
       
        cout << endl;
       
       
        //Удары для компьютера
        switch (theHitsOf_Copmuter) {
        case 1:
                cout << "Компьютер бьет вас в голову" << endl;
                if (checkGuard_Player == theHitsOf_Copmuter) {
                    cout << "Удар заблокирован!" << endl;
                } else {
            countPlayerHP -= 20; //Удар в голову
                    cout << "Player HP: " << countPlayerHP << endl;}
            break;
        case 2:
                cout << "Компьютер бьет вас в печень" << endl;
                if (checkGuard_Player == theHitsOf_Copmuter) {
                    cout << "Удар заблокирован!" << endl;
                } else {
            countPlayerHP -= 33; //Удар в печень
                    cout << "Player HP: " << countPlayerHP << endl;}
            break;
        case 3:
            cout << "Компьютер бьет вас по корпусу" << endl;
            if (checkGuard_Player == theHitsOf_Copmuter) {
                cout << "Удар заблокирован!" << endl;
            } else {
            countPlayerHP -= 5; //Удар по корпусу
            cout << "Player HP: " << countPlayerHP << endl;}
            break;
        }
        cout << "----------------------------" <<endl;
       
    }//Выход из цикла
   
   
   
    //Проверка на победу
    if (countPlayerHP <= 0) {
        cout << "Выиграл Компьютер !!! Поражение !!!" <<endl;
    }
    else if(countComputerHP <= 0)
    {
        cout << "Вы победили компьютер !!!" <<endl;
    }
   
   
    cout << endl;
       
        return 0;
}