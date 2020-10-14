#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

bool trySize_tParse(const string& input, size_t& size);

size_t getIntValue(
        const string& message = "",
        const size_t leftBound = numeric_limits<size_t>::min(),
        const size_t rightBound = numeric_limits<size_t>::max());

bool tryDoubleParse(const string& input, double& value);

double getDoubleValue(
    const string& message = "",
    const double leftBound = numeric_limits<double>::min(),
    const double rightBound = numeric_limits<double>::max());

const double* getGeneratedArray(
    const size_t size,
    const double leftBound,
    const double rightBound);

string toString(const double* myArray, const size_t size);

double getMaxValue(const double* myArray, const size_t size);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const auto size = getIntValue("Input size = ", 0);
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

size_t getIntValue(
    const string& message,
    const size_t leftBound,
    const size_t rightBound)
{
    size_t tempSize;
    while (true)
    {
        cout << message;
        string tempInput;
        getline(std::cin, tempInput);

        const auto isFail = (cin.fail()
            || !trySize_tParse(tempInput, tempSize))
            && !(tempSize >= leftBound && tempSize <= rightBound);
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
        value = std::stod(input);
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
        getline(cin, tempInput);

        const auto isFail = (cin.fail()
            || !tryDoubleParse(tempInput, tempValue))
            && !(tempValue >= leftBound && tempValue <= rightBound);
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
    srand(static_cast<unsigned int>(time(nullptr)));
    const auto array = new double[size];
    for (size_t i = 0; i < size; ++i)
    {
        array[i] = static_cast<double>(rand()) / RAND_MAX * (rightBound - leftBound) + leftBound;
    }
    return array;
}

string toString(const double* myArray, const size_t size)
{
    stringstream ss;
    ss << "My array is: { ";
    for (size_t i = 0; i < size - 1; ++i)
    {
        ss << myArray[i] << ", ";
    }
    ss << myArray[size - 1] << " }";
    return ss.str();
}

double getMaxValue(const double* myArray, const size_t size)
{
    auto max = myArray[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (max < myArray[i])
            max = myArray[i];
    }
    return max;
}
