#include <QCoreApplication>
#include <iostream>

using namespace std;

double getValue()
{
    while (true)
    {
       int a;
       cout<<"Enter a size of array: " << "\n";
       cin >> a;
       if (cin.fail()== 1 || a==0)
         {
             cin.clear();
             cin.ignore(32767,'\n');
             cout << "Incorrect input" << endl;
         }
       else
       return a;

   }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    double *values,MaxDouble=0;
    int size = getValue();
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
