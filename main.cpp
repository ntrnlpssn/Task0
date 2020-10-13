#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include<random>

using namespace std;

bool trySize_tParse(const string& input, size_t& size);

size_t getIntegerValue(
        const string& message = "",
        const size_t leftBound = numeric_limits<size_t>::lowest(),
        const size_t rightBound = numeric_limits<size_t>::max());

bool tryDoubleParse(const string& input, double& value);

double getDoubleValue(
    const string& message = "",
    const double leftBound = numeric_limits<double>::lowest(),
    const double rightBound = numeric_limits<double>::max());

const double* getGeneratedArray(
    const size_t size,
    const double leftBound,
    const double rightBound);

string toString(const double* array, const size_t size);

double getMaxValue(const double* array, const size_t size);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const auto size = getIntegerValue("Input size = ", 0);
    const auto minValue = getDoubleValue("Input min value = ");
    const auto maxValue = getDoubleValue("Input max value = ", minValue);

    const auto myArray = getGeneratedArray(size, minValue, maxValue);
    cout << toString(myArray, size) << endl;

    cout << "Max value of array: " << getMaxValue(myArray, size) << endl;

    delete[] myArray;
    system("PAUSE");
    return a.exec();
}

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

size_t getIntegerValue(
    const string& message,
    const size_t leftBound,
    const size_t rightBound)
{
    size_t tempSize;
    while (true)
    {
        cout << message;
        string tempInput;
        cin >> tempInput;
        
        const auto isFail = cin.fail()
                    || !trySize_tParse(tempInput, tempSize)
                    || !(tempSize >= leftBound && tempSize <= rightBound)
                    || tempSize==0;
        if (isFail)
        {
            clearInput();
            cout << "Incorrect input" << endl;
        }
        else
        {
            return tempSize;
        }
    }
}


bool trySize_tParse(const string& input, size_t& size)
{
    try
    {
        const auto tempDouble = stod(input);
        const size_t tempInteger = stoul(input);

        if (tempDouble - tempInteger < numeric_limits<double>::epsilon())
        {
            size = tempInteger;
            return true;
        }

        return false;
    }
    catch (exception e)
    {
        return false;
    }
}

bool tryDoubleParse(const string& input, double& value)
{
    try
    {
        value = stod(input);
        return true;
    }
    catch (exception e)
    {
        return false;
    }
}

double getDoubleValue(
    const string& message,
    const double leftBound,
    const double rightBound)
{
    double tempValue;
    while (true)
    {
        cout << message;
                string tempInput;
                cin >> tempInput;

       const auto isFail = cin.fail()
               || !tryDoubleParse(tempInput, tempValue)
               || !(leftBound <= tempValue && tempValue <= rightBound);
        if (isFail)
        {
            clearInput();
            cout << "Incorrect input" << endl;
        }
        else
        {
            return tempValue;
        }
    }
}

const double* getGeneratedArray(
    const size_t size,
    const double leftBound,
    const double rightBound)
{
    const uniform_real_distribution<double> distribution(leftBound, rightBound);
        default_random_engine engine;
        const auto array = new double[size];
        for (size_t i = 0; i < size; ++i)
        {
            array[i] = distribution(engine);
        }
    return array;
}

string toString(const double* array, const size_t size)
{
    stringstream ss;
    ss << "My array is: { ";
    for (size_t i = 0; i < size - 1; ++i)
    {
        ss << array[i] << ", ";
    }
    ss << array[size - 1] << " }";
    return ss.str();
}

double getMaxValue(const double* array, const size_t size)
{
    auto max = array[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (max < array[i])
            max = array[i];
    }
    return max;
}
