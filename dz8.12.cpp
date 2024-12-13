#include <iostream>
#include <string>

struct Rat {
    std::string name;       // Имя крысы
    double speed;           // Скорость крысы (в метрах в секунду)
    double position;        // Текущее положение крысы (в метрах)
    int age;               // Возраст крысы (в годах)
    std::string color;      // Цвет крысы
    bool isHungry;         // Состояние голода (истина, если крыса голодна)
};

// Функция для создания новой крысы
Rat createRat(const std::string &name, double speed, double position, int age, const std::string &color, bool isHungry) {
    Rat newRat;
    newRat.name = name;
    newRat.speed = speed;
    newRat.position = position;
    newRat.age = age;
    newRat.color = color;
    newRat.isHungry = isHungry;
    return newRat;
}

// Функция для изменения положения крысы
void updatePosition(Rat &rat, double time) {
    rat.position += rat.speed * time; // Обновляем положение крысы
}

// Функция для изменения имени и скорости крысы
void changeRatNameAndSpeed(Rat &rat, const std::string &newName, double newSpeed) {
    rat.name = newName;
    rat.speed = newSpeed;
}

// Функция для вывода информации о крысе
void printRatInfo(const Rat &rat) {
    std::cout << "Name: " << rat.name << std::endl;
    std::cout << "Speed: " << rat.speed << " m/s" << std::endl;
    std::cout << "Position: " << rat.position << " m" << std::endl;
    std::cout << "Age: " << rat.age << " years" << std::endl;
    std::cout << "Color: " << rat.color << std::endl;
    std::cout << "Is Hungry: " << (rat.isHungry ? "Yes" : "No") << std::endl;
}

int main() {
    // Создаем новую крысу
    Rat myRat = createRat("Rattus", 1.5, 0.0, 2, "Gray", true);
    
    // Выводим информацию о крысе
    std::cout << "Initial Rat Info:" << std::endl;
    printRatInfo(myRat);
    
    // Обновляем положение крысы через 5 секунд
    updatePosition(myRat, 5.0);
    
    // Выводим обновленную информацию о крысе
    std::cout << "\nUpdated Rat Info after 5 seconds:" << std::endl;
    printRatInfo(myRat);
    
    // Меняем имя и скорость крысы
    changeRatNameAndSpeed(myRat, "Speedy", 2.0);
    
    // Выводим информацию о крысе после изменений
    std::cout << "\nRat Info after name and speed change:" << std::endl;
    printRatInfo(myRat);
    
    return 0;
}