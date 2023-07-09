#include "database.h"

int partition(double* data, int low, int high) {
    double pivot = data[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (data[j] < pivot) {
            i++;
            std::swap(data[i], data[j]);
        }
    }

    std::swap(data[i + 1], data[high]);
    return i + 1;
}

double quickSelect(double* data, int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(data, low, high);

        if (pivotIndex == k) {
            return data[pivotIndex];
        }

        if (k < pivotIndex) {
            return quickSelect(data, low, pivotIndex - 1, k);
        }
        else {
            return quickSelect(data, pivotIndex + 1, high, k);
        }
    }

    return -1;  // Возвращаем -1, если что-то пошло не так
}

std::pair<double, int> calculateMedian(double* data, int n) {
    // Расчет медианы
    double median;
    int medianIndex;

    if (n % 2 == 0) {
        // Если количество значений четное, берем среднее из двух средних
        double median1 = quickSelect(data, 0, n - 1, n / 2 - 1);
        double median2 = quickSelect(data, 0, n - 1, n / 2);
        median = (median1 + median2) / 2.0;
        medianIndex = n / 2 - 1;
    }
    else {
        // Если количество значений нечетное, берем средний элемент
        median = quickSelect(data, 0, n - 1, n / 2);
        medianIndex = n / 2;
    }

    return std::make_pair(median, medianIndex);
}

dataBase::dataBase(QObject *parent)
    : QObject{parent}
{

}

std::pair<__int16*, __int16*> dataBase::getPairMinMax()
{
    return MinMaxValue;
}

QList<QPointF> dataBase::getPoints()
{
    return points;
}

QPointF dataBase::getPointMedian()
{
    return pointMedian;
}

QPointF dataBase::getMax()
{
    return Max;
}

void dataBase::setInformation(__int16 points[4096])
{   qDebug()<<"Начало";
    this->points.clear();
    double points2[4096];
    MinMaxValue = std::minmax_element(points,points+4096);
    Max.setY(*MinMaxValue.second);
    for(int i=0;i<4096;i++){
        this->points.append(QPointF(i,points[i]));
        points2[i] = points[i];
        if(points[i]==Max.y()){
            Max.setX(i);
        }
    }
    qDebug()<<"Максимум тут"<<Max;
    int summElem = 0;

    int n = sizeof(points) / sizeof(points[0]);
    qDebug()<<n;
    std::pair<double, int> result = calculateMedian(points2, 4096);

    double median = result.first;
    int medianIndex = result.second;
    pointMedian.setX(medianIndex);
    pointMedian.setY(median);
}

