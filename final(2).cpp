#include <iostream>
#include <cstdlib>
#include <string>
 
class
    Boxer //класс Боксер
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
 
 
void func_Of_Switch(bool is_Player, int &theHits, int &checkGuard, int &count_HP)
//Функция с выбором удара. Эта конструкция прописана одинаково для Игрока и Компьютера.
//По первому полю которое мы передаем в функцию мы понимаю, обращаемся мы к игроку или к PC.
{
    //Благодаря конструкции If else мы выбираем какой из вариантов печати нам нужен.
    switch (theHits) {
    case 1:
        is_Player ? std::cout << "Вы бьете противника в голову" << std::endl :      //Обычное ветвление (If ) ? 1 : 2
            std::cout << "Компьютер бьет вас в голову" << std::endl;
        if (checkGuard == theHits) {
            std::cout << "Удар заблокирован!" << std::endl;
        }
        else {
            count_HP -= 20; //Удар в голову
            if(count_HP < 0)
            {
                count_HP = 0;
                is_Player ? std::cout << "Copmuter HP: " << count_HP << std::endl :
                std::cout << "Ваш HP: " << count_HP << std::endl;
            }
            else
            {
            is_Player ? std::cout << "Copmuter HP: " << count_HP << std::endl :
                std::cout << "Ваш HP: " << count_HP << std::endl;
            }
        }
        break;
 
    case 2:
        is_Player ? std::cout << "Вы бьете противника в печень" << std::endl :      //ветвление (If ) ? 1 : 2
            std::cout << "Компьютер бьет вас в печень" << std::endl;
        if (checkGuard == theHits) {
            std::cout << "Удар заблокирован!" << std::endl;
        }
        else {
            count_HP -= 33; //Удар в печень
            if(count_HP < 0)
            {
                count_HP = 0;
                is_Player ? std::cout << "Copmuter HP: " << count_HP << std::endl :
                std::cout << "Ваш HP: " << count_HP << std::endl;
            }
            else
            {
            is_Player ? std::cout << "Copmuter HP: " << count_HP << std::endl :     //ветвление (If ) ? 1 : 2
                std::cout << "Ваш HP: " << count_HP << std::endl;
            }
        }
        break;
 
    case 3:
        is_Player ? std::cout << "Вы бьете противника по корпусу" << std::endl :    //ветвление (If ) ? 1 : 2
            std::cout << "Компьютер бьет вас по корпусу" << std::endl;
        if (checkGuard == theHits) {
            std::cout << "Удар заблокирован!" << std::endl;
        }
        else {
            count_HP -= 5; //Удар по корпусу
            if(count_HP < 0)
            {
                count_HP = 0;
                is_Player ? std::cout << "Copmuter HP: " << count_HP << std::endl :
                std::cout << "Ваш HP: " << count_HP << std::endl;
            }
            else
            {
            is_Player ? std::cout << "Copmuter HP: " << count_HP << std::endl :     //ветвление (If ) ? 1 : 2
                std::cout << "Ваш HP: " << count_HP << std::endl;
            }
        }
        break;
 
    default:
        std::cout << "Выберите 1, 2 или 3 удар!" << std::endl;      //Кейс свича которые выполниться если остальные не сработали
        break;
    }
}
 
void hello_Funk() //Функция приветствия
{
    //Использование стандартных std:: потоков и библиотеки <string>
    std::cout << "Введите свое Имя : ";
    std::string name_Of_Player;
    std::cin >> name_Of_Player;
    std::cout << "Здравствуйте " << name_Of_Player << "." << std::endl;
    std::cout << "Хорошего боя !" << std::endl;
   
}
 
void print_Line()   //Функция для разграничивания игровых раундов
{
    std::string S(40, '=');     //Стандартный конструктор из <string>
    std::cout << S << std::endl;  //Вывод этой строки
}
 
int main() {
   
    hello_Funk(); //Функция приветсвия
    print_Line(); //Функция разграничения раундов
   
    //Устанавливаем стартовое значение здоровья для боксеров
    Boxer playerBoxer(100), computerBoxer(100);
 
    //Приравниваю показатели здоровья переменным для использования и сравнения
    int countPlayerHP{ playerBoxer.getHealthPoint() };
    int countComputerHP{ computerBoxer.getHealthPoint() };
 
 
    while (countPlayerHP > 0 && countComputerHP > 0) {
        //Игра продолжаеться до тех пор, пока здоровье любого бойца не станет меньше или равно 0
       
        // Игровое поле
       
       
       
        int theHitsOf_Player{ 0 }; //Удар который вы выберете (Всего их 3)
        int theHitsOf_Copmuter{ 1 + rand() % 3 };//Рандом от 1 до 3 включительно для компьютера
        std::cout << "Выберите удар! (1-Голова|2-Печень|3-Корпус)" << std::endl;
        std::cin >> theHitsOf_Player; //Введенные данные с потока идут в переменную
 
       
        int checkGuard_Player{ 0 }; //Защита которую вы выберете (Всего их 3)
        int checkGuard_Computer{ 1 + rand() % 3 };//Рандом от 1 до 3 включительно для Компьютера
 
        //Функция выбора ударов для Игрока
        func_Of_Switch(true, theHitsOf_Player, checkGuard_Computer, countComputerHP);
        if(countComputerHP <= 0)
        {
            break;
        } else {
         std::cout << "Выберите защиту! (1-Голова|2-Печень|3-Корпус)" << std::endl;
        std::cin >> checkGuard_Player;
 
        //Функция выбора ударов для Компьютера
        func_Of_Switch(false, theHitsOf_Copmuter, checkGuard_Player, countPlayerHP);
       
        //Разграничение раундов - каждой итерации цикла
        print_Line();
        print_Line();
            std::cout << std::endl;
        }
    }//Выход из цикла
 
 
    //Проверка на победу
    if (countPlayerHP <= 0) {
        print_Line();
        std::cout << "Выиграл Компьютер !!! Поражение !!!" << std::endl;
        print_Line();
    }
    else if (countComputerHP <= 0)
    {
        print_Line();
        std::cout << "Вы победили компьютер !!!" << std::endl;
        print_Line();
    }
 
    std::cout << std::endl;
 
    return 0;
}