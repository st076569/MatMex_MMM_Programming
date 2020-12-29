#ifndef FUNCTIONS_H
#define FUNCTIONS_H

////////// st076569_9 ////////////////////////////////////////////////////////
// Автор  : Баталов Семен                                                   //
// Дата   : 15.10.2020                                                      //
// Задача : Используя псевдопараллелизм Linux, запустить параллельно        //
//          несколько одинаковых программ.                                  //
//////////////////////////////////////////////////////////////////////////////

#include <ctime>
#include <iomanip>
#include <iostream>

namespace bat
{
    // Общий вещественный тип
    typedef double Real;
    
    // Максимальное время работы
    const Real DURATION = 5;
    
    ////////// void delay ////////////////////////////////////////////////////
    // Осуществляет задержку на время "duration" в секундах.                //
    //////////////////////////////////////////////////////////////////////////
    
    void delay(Real duration);
    
    ////////// Real time /////////////////////////////////////////////////////
    // Возвращает время от начала работы программы в секундах.              //
    //////////////////////////////////////////////////////////////////////////
    
    Real time();
    
    ////////// void run //////////////////////////////////////////////////////
    // Производит случайную задержку по времени и вывод информации на       //
    // экран.                                                               //
    //////////////////////////////////////////////////////////////////////////
    
    void run();
}
    
#endif