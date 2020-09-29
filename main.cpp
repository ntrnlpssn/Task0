#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    double *values,MaxDouble=0;
    int size;
    cout<<"Enter a size of array: " << "\n";
    cin>>size;
    values = new double[size];

    for(int i=0 ; i<size; i++)
    {
        values[i] = (rand() % 1000)/100.0+0.01;
        cout << values[i] << " ";
    }

    cout <<"\n";

    for(int i=0 ; i<size; i++)
    {
        if(MaxDouble < values[i])
            MaxDouble =values[i];
    }

    cout <<"Max value of array: " << MaxDouble <<"\n" ;

  system("PAUSE");

    return a.exec();
}
