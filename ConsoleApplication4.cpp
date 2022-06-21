#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

// Робота зроблена Линником Богданом для П3 з предмету Числені Методи 20.06.2022р.

double Func(double x)
{
  // return 6 * x * x * x * x  - x * x * x -x*x- 10*x-8;
    return 2 * x * x * x * x +3*x * x * x - 8*x * x +5* x +1;
}
double firstFunc(double x)
{
  // return 24*x*x*x-3*x*x-2*x-10;
    return 8 * x * x * x + 9 * x * x - 16 * x + 5;
}
double secondFunc(double x)
{
   //return 72*x*x-6*x-2;
    return 24 * x * x + 18 * x - 16;
}
double thirdFunc(double x)
{
  // return 144 * x - 6;
    return 48 * x + 18;
}

int main()
{
    setlocale(LC_ALL, "rus");

    int i,x0;
    double h;
    cout << "Введите i "; cin >> i; cout << endl;
    cout << "Введите x0 "; cin >>x0; cout << endl;
    cout << "Введите h "; cin >> h; cout << endl;
    int defI = i * 2;
    double* arrayX = new double[defI];
    double* arrayF = new double[defI];
    double* arrayF1 = new double[defI];
    double* arrayF2 = new double[defI];
    double* arrayF3 = new double[defI];
    double* arrayFLEFT = new double[defI-2];
    double* arrayFRIGHT = new double[defI-2];
    double* arrayFCENTER = new double[defI-2];
    double* arrayOLD = new double[defI-2];
    //------------------------------------
    double* arrayFLEFTABS= new double[defI - 2];
    double* arrayFRIGHTABS = new double[defI - 2];
    double* arrayFCENTERABS = new double[defI - 2];
    double* arrayOLDABS = new double[defI - 2];
    //---------------------------------------------
    double* arrayFLEFTGRAN= new double[defI - 2];
    double* arrayFRIGHTGRAN = new double[defI - 2];
    double* arrayFCENTERGRAN = new double[defI - 2];
//------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
    cout << "Значення Хi" << endl;
    for (int xn = (i-defI); xn <= i; xn++)
    {
        arrayX[xn] = x0 + xn * h;
        cout << "Значення " << xn << " елемента є " << arrayX[xn] << endl;
    }
    cout << endl;
//-------------------------------------------------------------------------------------
    cout << "Значення функцii при Хi" << endl;
    for (int xn = (i - defI); xn <= i; xn++)
    {
        arrayF[xn] = Func(arrayX[xn]);
        cout << "Значення F" << xn << " елемента є " << arrayF[xn] << endl;
    }
    cout << endl;
//------------------------------------------------------------------------------------
    cout << "Значення 1 похiдноi при Хi" << endl;
    for (int xn = (i - defI); xn <= i; xn++)
    {
        arrayF1[xn] = firstFunc(arrayX[xn]);
        cout << "Значення F'" << xn << " елемента є " << arrayF1[xn] << endl;
    }
    cout << endl;
//------------------------------------------------------------------------------------
    cout << "Значення 2 похiдноi при Хi" << endl;
    for (int xn = (i - defI); xn <= i; xn++)
    {
        arrayF2[xn] = secondFunc(arrayX[xn]);
        cout << "Значення F''" << xn << " елемента є " << arrayF2[xn] << endl;
    }
    cout << endl;
//----------------------------------------------------------------------------------
    cout << "Значення 3 похiдноi при Хi" << endl;
    for (int xn = (i - defI); xn <= i; xn++)
    {
        arrayF3[xn] = thirdFunc(arrayX[xn]);
        cout << "Значення F'''" << xn << " елемента є " << arrayF3[xn] << endl;
    }
    cout << endl;
    //----------------------------------------------------------------------------------
    cout << "Обичислення похiдних за допомогую способами кiнцевих рiзниць,\n(за допомогую лiвих рiзниць, правих центральних,другоi похідноi, старших похiдних)";
    cout << endl;
    cout << endl;
//--------------------------------------------------------------------------------
    cout << "Формула лiвих рiзниць" << endl;
    for (int xn = (i - defI+1); xn <= i-1; xn++)
    {

        arrayFLEFT[xn] = (Func(arrayX[xn]) - Func(arrayX[xn - 1])) / h;
        cout << "Значення FLeft'" << xn << " елемента є " << arrayFLEFT[xn] << endl;
    }
    cout << endl;
//------------------------------------------------------------------------------------------
    cout << "Формула правих рiзниць" << endl;
    for (int xn = (i - defI + 1); xn <= i-1; xn++)
    {

        arrayFRIGHT[xn] = (Func(arrayX[xn+1]) - Func(arrayX[xn])) / h;
        cout << "Значення FRIGHT'" << xn << " елемента є " << arrayFRIGHT[xn] << endl;
    }
    cout << endl;
//-------------------------------------------------------------------------------------------
    cout << "Формула центральних рiзниць" << endl;
    for (int xn = (i - defI + 1); xn <= i - 1; xn++)
    {

        arrayFCENTER[xn] = (Func(arrayX[xn + 1]) - Func(arrayX[xn-1])) / (2*h);
        cout << "Значення FСENTER'" << xn << " елемента є " << arrayFCENTER[xn] << endl;
    }
    cout << endl;
//-----------------------------------------------------------------------------------------------
    cout << "Формула старших похiдных" << endl;
    for (int xn = (i - defI + 1); xn <= i - 1; xn++)
    {
       // arrayOLD[xn] = (((Func(arrayX[xn + 1]) - Func(arrayX[xn])) / h) - ((Func(arrayX[xn]) - Func(arrayX[xn - 1])) / h))/(h*h);
        arrayOLD[xn] = (Func(arrayX[xn + 1]) - 2 * Func(arrayX[xn]) + Func(arrayX[xn - 1])) / (h * h);
        cout << "Значення FOLD''" << xn << " елемента є " << arrayOLD[xn] << endl;
    }
    cout << endl;
//-------------------------------------------------------------------------------------------------------------------------------
    cout << "Абсолютнi похибки " << endl;
    cout << endl;
//------------------------------------------------------------------------------------------------------------------------------
    cout << "Абсолютна похибка левих рiзниць " << endl;
    cout << endl;
    for (int xn = (i - defI + 1); xn <= i - 1; xn++)
    {
        arrayFLEFTABS[xn] = abs(arrayF1[xn]- arrayFLEFT[xn]);
        cout << "Значення arrayFLEFTABS " << xn << " елемента є " << arrayFLEFTABS[xn] << endl;
    }
    cout << endl;
//---------------------------------------------------------------------------------------------------------
    cout << "Абсолютна похибка правих рiзниць " << endl;
    cout << endl;
    for (int xn = (i - defI + 1); xn <= i - 1; xn++)
    {
        arrayFRIGHTABS[xn] = abs(arrayF1[xn] - arrayFRIGHT[xn]);
        cout << "Значення  arrayFRIGHTABS " << xn << " елемента є " << arrayFRIGHTABS[xn] << endl;
    }
    cout << endl;
//----------------------------------------------------------------------------------------
    cout << "Абсолютна похибка центральних рiзниць " << endl;
    cout << endl;
    for (int xn = (i - defI + 1); xn <= i - 1; xn++)
    {
        arrayFCENTERABS[xn] = abs(arrayF1[xn] - arrayFCENTER[xn]);
        cout << "Значення arrayFCENTERABS " << xn << " елемента є " << arrayFCENTERABS[xn] << endl;
    }
    cout << endl;
//------------------------------------------------------------------------------------------------
    cout << "Абсолютна похибка старших похiдних " << endl;
    cout << endl;
    for (int xn = (i - defI + 1); xn <= i - 1; xn++)
    {
        arrayOLDABS[xn] = abs(arrayF2[xn] - arrayOLD[xn]);
        cout << "Значення  arrayOLDABS " << xn << " елемента є " << arrayOLDABS[xn] << endl;
    }
    cout << endl;
//---------------------------------------------------------------------------------------------------
    cout << "Граничнi похибки " << endl;
    cout << endl;
//-----------------------------------------------------------------------------------------------------
    cout << "Гранична похибка левих рiзниць " << endl;
    cout << endl;
    for (int xn = (i - defI + 1); xn <= i - 1; xn++)
    {
        arrayFLEFTGRAN[xn] =(h/2) * abs(max(arrayF2[xn-1], arrayF2[xn]));
        cout << "Значення arrayFLEFTGRAN " << xn << " елемента є " << arrayFLEFTGRAN[xn] << endl;
    }
    cout << endl;
//----------------------------------------------------------------------------------------------------
    cout << "Гранична похибка правих рiзниць " << endl;
    cout << endl;
    for (int xn = (i - defI + 1); xn <= i - 1; xn++)
    {
        arrayFRIGHTGRAN[xn] = (h / 2) * abs(max(arrayF2[xn], arrayF2[xn+1]));
        cout << "Значення arrayRightGRAN " << xn << " елемента є " << arrayFRIGHTGRAN[xn] << endl;
    }
    cout << endl;
    //----------------------------------------------------------------------------------------------------
    cout << "Гранична похибка центральних рiзниць " << endl;
    cout << endl;
    for (int xn = (i - defI + 1); xn <= i - 1; xn++)
    {
        arrayFCENTERGRAN[xn] = (h*h/ 6) * abs(max(abs(thirdFunc(arrayX[xn]-1)), abs(thirdFunc(arrayX[xn] + 1))));
        cout << "Значення arrayFCENTERGRAN " << xn << " елемента є " << arrayFCENTERGRAN[xn] << endl;
    }
    cout << endl;
    //----------------------------------------------------------------------------------------------------
    cout << endl;
    cout << endl;

    cout << "| Вузол |" << setw(4) << "| Значення Х |" << setw(10) << "| Аналит. F' |" << setw(10) << "| Аналит. F'' |" << setw(10) << "| Аналит. F''' |" << setw(10) << "| Лев. F' |" << setw(10) << "| Прав. F' |" << setw(10) << "| Центр. F' |" << setw(10) << "| Старш. F'' |"<<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    for (int xn = (i - defI+1); xn <= i-1; xn++)
    {
        cout <<" X"<< xn << setw(10) << arrayX[xn] << setw(16) << arrayF1[xn] << setw(16) << arrayF2[xn] << setw(15) << arrayF3[xn] << setw(15) << arrayFLEFT[xn] << setw(10) << arrayFRIGHT[xn]<< setw(13) << arrayFCENTER[xn]<< setw(12) << arrayOLD[xn]<< endl;
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
    }
    cout << endl;
    cout << endl;
    cout << setw(75) << "Похибка" << endl;
    cout << endl;

    cout << "| Вузол |" << setw(4) << "| Абсолютна Лев. |" << setw(10) << "| Абсолютна Прав. |" << setw(10) << "| Абсолютна Центр. |" << setw(10) << "| Абсолютна Старш. F'' |" << setw(10) << "| Гран Лев. |" << setw(10) << "| Гран Прав. |" << setw(10) << "| Гран Центр. |" << setw(10) << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    for (int xn = (i - defI + 1); xn <= i - 1; xn++)
    {
        cout << " X" << xn << setw(13) << arrayFLEFTABS[xn] << setw(18) << arrayFRIGHTABS[xn] << setw(18) << arrayFCENTERABS[xn] << setw(25) << arrayOLDABS[xn] << setw(20) << arrayFLEFTGRAN[xn] << setw(15) << arrayFRIGHTGRAN[xn] << setw(13) << arrayFCENTERGRAN[xn] << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    cout << endl;



    delete[] arrayX;
    delete[] arrayF;
    delete[] arrayF1;
    delete[] arrayF2;
    delete[] arrayF3;
    delete[] arrayFLEFT;
    delete[] arrayFRIGHT;
    delete[] arrayFCENTER;
    delete[] arrayOLD;
    delete[] arrayFLEFTABS;
    delete[] arrayFRIGHTABS;
    delete[] arrayFCENTERABS;
    delete[] arrayOLDABS;
    delete[] arrayFLEFTGRAN;
    delete[] arrayFRIGHTGRAN;
    delete[] arrayFCENTERGRAN;
}
