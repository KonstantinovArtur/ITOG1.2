#include <iostream>
#include "Authorization.h"
#include "Inventory.h"
#include "User.h"
#include <thread>
#include <chrono>

using namespace std;

void threadFunction() {
    std::cout << "Начало приготовления" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Готовка завершена" << std::endl;
}

class Zakaz
{
private:
   
    double balacne;
   
public:
    Zakaz( int balacne) {

   
        this->balacne = balacne;
       
    }
public:
    double deposit(double dip) {
        balacne += dip;
        cout << "Сумма заказа: " << balacne <<  endl;
        return balacne;
    }
    double getBalance() {
        double new_balacne = balacne;
        balacne = new_balacne;
        return balacne;
    }
    double balance() {
        return balacne;
    }
};

class BALANCE
{
private:
   
    double balacne;
   
public:
    BALANCE( int balacne) {

     
        this->balacne = balacne;
       
    }
public:
    double deposit(double dip) {
        balacne += dip;
        cout << "Баланс ресторана: " << balacne << endl;
        return balacne;
    }
   
    double getBalance() {
        double new_balacne = balacne;
        balacne = new_balacne;
        cout << "Баланс ресторана: " << balacne << endl;
        return balacne;
    }


};

int main()
{
    setlocale(LC_ALL, "RUS");
    Inventory inventory;
    inventory.addProduct(1, "Огурцы", 3);
    inventory.addProduct(2, "Помидоры", 3);
    inventory.addProduct(3, "Краб", 3);
    inventory.addProduct(4, "Курица", 3);
    inventory.addProduct(5, "Грибы", 3);
    inventory.addProduct(5, "Картошка",3);
    inventory.addProduct(7, "Морковь", 3);
    inventory.addProduct(8, "Яйца", 3);
    inventory.addProduct(9, "Рыба", 3);
  
    
    

    
            Zakaz bank( 0);
            BALANCE bank1( 0);
            string zak;
    do
    {

        std::cout << "=== Добро пожаловать в систему авторизации ===" << std::endl;
        std::cout << "Введите логин (для входа в качестве гостя введите 'guest'): ";
        std::string login;
        std::cin >> login;
        if (login == "guest") {
            string menu;
            

            do
            {
            int kart = inventory.getProductQuantity("Картошка");
            int kart1 = inventory.getProductQuantity("Огурцы");
                cout << "Выберите Салат";
                cout << "\nCezar - 250р";
                cout << "\nOlivie - 307р";
                cout << "\nMimoza - 450р";
                cout << "\nGribnoy - 500р";
                cout << "\nKraboviy - 700р";

                cout << "\nВведите салат (Если хотите вернуться к авторизации напишите '1', для оплаты заказа напишите '2', для проверки статуса заказа '4'): ";

                cin >> menu;
                if (menu == "Cezar" && kart1 > 0) {



                    inventory.useProduct("Огурцы", 1);
                    inventory.useProduct("Курица", 1);
                    inventory.useProduct("Помидоры", 1);
                    double rubl;
                    rubl = 250;
                    bank.deposit(rubl);
                    cout << "\n";
                }
                else if (menu == "Olivie" && kart > 0) {


                    inventory.useProduct("Картошка", 1);
                    inventory.useProduct("Морковь", 1);
                    inventory.useProduct("Яйца", 1);
                    inventory.useProduct("Курица", 1);
                    inventory.useProduct("Огуры", 1);

                    double rubl;
                    rubl = 307;
                    bank.deposit(rubl);
                    cout << "\n";

                }
                else if (menu == "Mimoza" && kart > 0) {

                    inventory.useProduct("Картошка", 1);
                    inventory.useProduct("Рыба", 1);
                    inventory.useProduct("Яйца", 1);
                    double rubl;
                    rubl = 450;
                    bank.deposit(rubl);
                    cout << "\n";

                }
                else if (menu == "Gribnoy" && kart > 0) {

                    inventory.useProduct("Грибы", 1);
                    inventory.useProduct("Морковь", 1);
                    inventory.useProduct("Картошка", 1);
                    double rubl;
                    rubl = 500;
                    bank.deposit(rubl);
                    cout << "\n";

                }
                else if (menu == "Kraboviy" && kart1 > 0) {

                    inventory.useProduct("Краб", 1);
                    inventory.useProduct("Огурцы", 1);
                    inventory.useProduct("Яйца", 1);
                    double rubl;
                    rubl = 700;
                    bank.deposit(rubl);
                    cout << "\n";

                }
                else if (menu == "1") {

                 

                }
                else if (menu == "4") {

                    cout << "Статус заказа: " + zak;
                    cout << "\n";

                }
                else if (menu == "2") {

                    cout << "Сумма к оплате: " << bank.getBalance();
                    cout << "\n";
                    cout << "\nНажмите '3' чтобы оплатить: ";
                    string v1;
                    
                    do
                    {
                            
                            int b;
                            cin >> v1;
                        if (v1 == "3") {

                             b = bank.balance();

                            cout << "\nЗаказ оплачен ";
                            
                            zak = "Оплачен и передан на кухню";
                            cout << "\nСтатус заказа: " + zak;
                            cout << "\n";
                            bank1.deposit(b);


                        }
                        else  {

                            int b = bank.balance();

                            cout << "\nОшибка оплаты ";
                            cout << "\n";
                            cout << "\nНажмите '3' чтобы оплатить: ";
                            


                        }
                    } while (v1 != "3");
                    
                }
                
                else {
                    double rubl;
                    rubl = 0;
                    cout << "Ошибка в обработке заказа"; 
                    cout << "\n";
                    bank.deposit(rubl);
                    cout << "\n";
                }

            } while (menu != "1");

        }
        else if (login == "Admin")
        {
           
                std::cout << "Введите пароль: ";
                std::string password;
                std::cin >> password;

                User* user = authorizeUser(login, password);
                if (user != nullptr) {
                    std::cout << "Авторизация успешна. Добро пожаловать, " << user->role << "!\n";
                }
                else {
                    std::cout << "Неверный логин или пароль.\n";
                }
            
                string menu1;
            do
            {
                cout << "Выберите действие";
                cout << "\n1.Добавить продукт";
                cout << "\n2.Удалить продукт";
                cout << "\n3.Посмотреть склад";
                cout << "\n4.Посмотреть сотрудников";
                cout << "\n5.Посмотреть баланс ресторана";
                cout << "\n6.Вернуться к авторизации";
                cout << "\n";
                cin >> menu1;
                if (menu1 == "1")
                {
                    int i;
                    string n;
                    int k;
                    cout << "\nВвести id ";
                    cin >> i;
                    cout << "\nВвести название ";
                    cin >> n;
                    cout << "\nВвести количество ";
                    cin >> k;
                    cout << "\n";


                    inventory.addProduct(i, n, k);
                }
                else if (menu1 == "2")
                {
                    string p;
                    cout << "\nВведите название продукта";
                    cin >> p;
                    inventory.removeProduct(p);
                }
                else if (menu1 == "3")
                {
                    inventory.printAllProducts();
                }
                else if (menu1 == "4")
                {
                    cout << "Официант - Иванов Иван Иванович";
                    cout << "\n";
                    cout << "Повар - Петров Петр Петрович";
                    cout << "\n";
                }
                else if (menu1 == "5")
                {
                    bank1.getBalance();
                }
                else if (menu1 == "6")
                {
                  
                }
                else 
                {
                    cout << "\nОшибка ввода ";
                }
            } while (menu1 != "6");
            
        }
        else if (login == "Povar")
        {
            std::cout << "Введите пароль: ";
            std::string password;
            std::cin >> password;

            User* user = authorizeUser(login, password);
            if (user != nullptr) {
                std::cout << "Авторизация успешна. Добро пожаловать, " << user->role << "\n";
            }
            else {
                std::cout << "Неверный логин или пароль.\n";
            }
            string menu2;
            do
            {
                cout << "Выберите действие";
                cout << "\n1.Посмотреть заказ";
                cout << "\n2.Приготовить заказ";
                cout << "\n3.Посмотреть склад";
                cout << "\n4.Вернуться к авторизации";
                cout << "\n";
                cin >> menu2;
                if (menu2 == "1")
                {
                    
                    cout << "\nЗаказ на сумму: " << bank.getBalance() << "   " << zak;
                   
                    cout << "\n";

                }
                else if (menu2 == "2")
                {
                    std::thread t(threadFunction);

                    t.join();
                    zak = "Передан официанту на выдачу";
                    cout << "\nЗаказ на сумму: " << bank.getBalance() << "   " << zak;
                  
                  
                }
                else if (menu2 == "3")
                {
                    inventory.printAllProducts();
                }
                else if (menu2 == "4")
                {
                 
                }
                
                else
                {
                    cout << "\nОшибка ввода ";
                }
            } while (menu2 != "4");

        }
        else if (login == "Oficiant")
        {
            std::cout << "Введите пароль: ";
            std::string password;
            std::cin >> password;

            User* user = authorizeUser(login, password);
            if (user != nullptr) {
                std::cout << "Авторизация успешна. Добро пожаловать, " << user->role << "\n";
            }
            else {
                std::cout << "Неверный логин или пароль.\n";
            }
            string menu1;
            do
            {
                cout << "Выберите действие";
                cout << "\n1.Посмотреть заказ";
                cout << "\n2.Отнести заказ";
         
                cout << "\n3.Вернуться к авторизации";
                cout << "\n";
                cin >> menu1;
                if (menu1 == "1")
                {

                    cout << "\nЗаказ на сумму: " << bank.getBalance() << "   " << zak;

                    cout << "\n";

                }
                else if (menu1 == "2")
                {
                
                    zak = "Выполнен";
                    cout << "\n";
                    cout << "\nЗаказ на сумму: " << bank.getBalance() << "   " << zak;


                }
                else if (menu1 == "3")
                {
               
                }
            

                else
                {
                    cout << "\nОшибка ввода ";
                }
            } while (menu1 != "3");
        }
        else if (login != "Oficiant" && login != "Admin" && login != "Povar")
        {

            std::cout << "Неверный логин\n";

        }

    } while (true);
    

   
}
