#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void printResult(int correctPosition, int wrongPosition) {
    cout << "Правильные позиции: " << correctPosition << endl;
    cout << "Неправильные позиции: " << wrongPosition << endl;
}

bool isValidCombination(const vector<int>& combination) {
    for (int num : combination) {
        if (num < 1 || num > 6) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> secretCombination(4);
    cout << "Игрок 1, введите комбинацию из 4 чисел от 1 до 6 (через пробел): ";
    
    for (int i = 0; i < 4; ++i) {
        cin >> secretCombination[i];
    }

    // Проверка на корректность введенной комбинации
    if (!isValidCombination(secretCombination)) {
        cout << "Некорректная комбинация! Все числа должны быть от 1 до 6." << endl;
        return 1;
    }

    cout << "Игрок 2, у вас есть 6 попыток, чтобы угадать комбинацию." << endl;

    for (int attempt = 1; attempt <= 6; ++attempt) {
        vector<int> guess(4);
        cout << "Попытка " << attempt << ": введите вашу комбинацию (4 числа от 1 до 6): ";
        
        for (int i = 0; i < 4; ++i) {
            cin >> guess[i];
        }

        // Проверка на корректность введенной комбинации
        if (!isValidCombination(guess)) {
            cout << "Некорректная комбинация! Все числа должны быть от 1 до 6." << endl;
            --attempt; // Не считать эту попытку
            continue;
        }

        int correctPosition = 0;
        int wrongPosition = 0;
        vector<bool> guessed(4, false);
        vector<bool> secretUsed(4, false);

        // Подсчет правильных позиций
        for (int i = 0; i < 4; ++i) {
            if (guess[i] == secretCombination[i]) {
                correctPosition++;
                guessed[i] = true;
                secretUsed[i] = true;
            }
        }

        // Подсчет неправильных позиций
        for (int i = 0; i < 4; ++i) {
            if (!guessed[i]) {
                for (int j = 0; j < 4; ++j) {
                    if (!secretUsed[j] && guess[i] == secretCombination[j]) {
                        wrongPosition++;
                        secretUsed[j] = true; // Помечаем, что это число уже использовано
                        break;
                    }
                }
            }
        }

        printResult(correctPosition, wrongPosition);

        if (correctPosition == 4) {
            cout << "Поздравляем! Игрок 2 угадал комбинацию!" << endl;
            return 0;
        }
    }

    cout << "Игрок 2 не смог угадать комбинацию. Правильная комбинация: ";
    for (int num : secretCombination) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}