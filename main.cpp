#include <cstdlib>
#include <iostream>
#include <math.h>

#include "LibShapes.h"
#include "LibCylinder.h"

using namespace std;

Cylinder* Select_Figure();
double Select_Height();

int main()
{
    double V;
    Cylinder* Cyl;

    Cyl = Select_Figure();

    V = Cyl->CalcVolume();
    cout << endl <<"\n Обьем фигуры: " << V << endl;

    return 0;
}

double Select_Height()
{
    cout << "\n Введите высоту фигуры: ";

    double h; cin >> h;

    return h;
}

Cylinder* Select_Figure()
{
    Cylinder* Cyl;
    Figure* figure;
    short int v;

    cout << "\n Выберите фигуру: "
        <<"\n\n 1) Треугольник"
        <<"\n 2) Круг"
        <<"\n 3) Правильная звезда"
        <<"\n\n > ";

    cin >> v;

    if(v == 1)
    {
        double a,b,c;

        cout << "\n Введите стороны треугольника: \n";
        cin >> a >> b >> c;

        try
        {
            figure = new Triangle<double>(a,b,c);
            Cyl = TringleCylinder::CreateInstance(static_cast<Triangle<double>*>(figure), Select_Height());
        }
        catch(MyEx& e)
        {
            cout << "\nCatch MyEx" << e.GetMessage() << ": " << e.GetValue() << endl;
            exit(1);
        }
        catch (...)
        {
	        cout << "\n!Catch ...:" << "Неизвестная ошибка!" << endl;
	        exit(1);
	    }


    }

    if(v == 2)
    {
        double r;
        cout << "\n Введите радиус круга: "; cin>> r;

        try
        {
            figure = new Circle<double>(r);
            Cyl = CircleCylinder::CreateInstance(static_cast<Circle<double>*>(figure), Select_Height());
        }
        catch(MyEx& e)
        {
            cout << "\nCatch MyEx" << e.GetMessage() << ": " << e.GetValue() << endl;
            exit(1);
        }
        catch (...)
        {
	        cout << "Catch ...:" << "Неизвестная ошибка!" << endl;
	        exit(1);
	    }

    }

    if(v == 3 )
    {
        double d;
        cout << "\n Введите длину основания луча: \n"; cin >> d;

        try
        {
            figure = new Star<double>(d);
            Cyl = StarCylinder::CreateInstance(static_cast<Star<double>*>(figure), Select_Height());
        }
        catch(MyEx& e)
        {
            cout << "\nCatch MyEx" << e.GetMessage() << ": " << e.GetValue() << endl;
            exit(1);
        }
        catch (...)
        {
	        cout << "Catch ...:" << "Неизвестная ошибка!" << endl;
	        exit(1);
	    }
    }

    delete figure;
    return Cyl;
}
