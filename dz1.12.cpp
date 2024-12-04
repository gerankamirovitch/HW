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
