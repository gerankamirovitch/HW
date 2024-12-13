#include <iostream>
#include <string>

struct Phone {
    std::string brand;       // Бренд телефона
    std::string model;      // Модель телефона
    std::string color;      // Цвет телефона
    double price;           // Цена телефона
    int storage;            // Объем памяти (в ГБ)
};

// Процедура для изменения поля структуры
void changePhoneColor(Phone &phone, const std::string &newColor) {
    phone.color = newColor;
}

// Процедура для создания объекта телефона
Phone createPhone(const std::string &brand, const std::string &model, const std::string &color, double price, int storage) {
    Phone newPhone;
    newPhone.brand = brand;
    newPhone.model = model;
    newPhone.color = color;
    newPhone.price = price;
    newPhone.storage = storage;
    return newPhone;
}

// Функция для вывода информации о телефоне
void printPhoneInfo(const Phone &phone) {
    std::cout << "Brand: " << phone.brand << std::endl;
    std::cout << "Model: " << phone.model << std::endl;
    std::cout << "Color: " << phone.color << std::endl;
    std::cout << "Price: $" << phone.price << std::endl;
    std::cout << "Storage: " << phone.storage << " GB" << std::endl;
}

int main() {
    // Создаем объект телефона
    Phone myPhone = createPhone("Apple", "iPhone 14", "Black", 999.99, 128);
    
    // Выводим информацию о телефоне
    std::cout << "Original Phone Info:" << std::endl;
    printPhoneInfo(myPhone);
    
    // Меняем цвет телефона
    changePhoneColor(myPhone, "Red");
    
    // Выводим обновленную информацию о телефоне
    std::cout << "\nUpdated Phone Info:" << std::endl;
    printPhoneInfo(myPhone);
    
    return 0;
}