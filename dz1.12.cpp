#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

// 1. Функция для подсчета четных элементов
int countEven(const vector<int>& vec) {
    return count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
}

// 2. Функция для вычисления скользящей средней
vector<double> movingAverage(const vector<int>& vec, int windowSize) {
    vector<double> averages;
    for (size_t i = 0; i <= vec.size() - windowSize; ++i) {
        double sum = accumulate(vec.begin() + i, vec.begin() + i + windowSize, 0);
        averages.push_back(sum / windowSize);
    }
    return averages;
}

// 3. Функция для центрирования вектора
void centerVector(vector<double>& vec) {
    double mean = accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
    for (auto& x : vec) {
        x -= mean;
    }
}

// 4. Функция для поиска максимального элемента, делящегося на 13
int maxDivisibleBy13(const vector<int>& vec) {
    auto it = max_element(vec.begin(), vec.end(), [](int a, int b) {
        return (a % 13 != 0) && (b % 13 == 0);
    });
    return (it != vec.end() && *it % 13 == 0) ? *it : -1; // Возвращаем -1, если нет подходящего элемента
}

// 5. Функция для поиска медианы
double findMedian(vector<int> vec) {
    sort(vec.begin(), vec.end());
    size_t n = vec.size();
    if (n % 2 == 0) {
        return (vec[n / 2 - 1] + vec[n / 2]) / 2.0;
    } else {
        return vec[n / 2];
    }
}

// 6. Функция для подсчета элементов больше n
int countGreaterThanN(const vector<int>& vec, int n) {
    return count_if(vec.begin(), vec.end(), [n](int x) { return x > n; });
}

int main() {
    vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 13, 26, 39};

    // 1. Подсчет четных элементов
    cout << "Количество четных элементов: " << countEven(data) << endl;

    // 2. Скользящая средняя
    int windowSize = 3;
    vector<double> averages = movingAverage(data, windowSize);
    cout << "Скользящая средняя: ";
    for (double avg : averages) {
        cout << avg << " ";
    }
    cout << endl;

    // 3. Центрирование вектора
    vector<double> centerData(data.begin(), data.end());
    centerVector(centerData);
    cout << "Центрированный вектор: ";
    for (double x : centerData) {
        cout << x << " ";
    }
    cout << endl;

    // 4. Максимальный элемент, делящийся на 13
    int maxDiv13 = maxDivisibleBy13(data);
    cout << "Максимальный элемент, делящийся на 13: " << (maxDiv13 != -1 ? to_string(maxDiv13) : "Нет") << endl;

    // 5. Медиана
    double median = findMedian(data);
    cout << "Медиана: " << median << endl;

    // 6. Количество элементов больше n
    int n = 5;
    cout << "Количество элементов больше " << n << ": " << countGreaterThanN(data, n) << endl;

    return 0;
}