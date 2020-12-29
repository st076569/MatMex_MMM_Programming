////////// st076569_9 ////////////////////////////////////////////////////////
// Автор  : Баталов Семен                                                   //
// Дата   : 15.10.2020                                                      //
// Задача : Используя псевдопараллелизм Linux, запустить параллельно        //
//          несколько одинаковых программ.                                  //
//////////////////////////////////////////////////////////////////////////////

#include "functions.h"

////////// void delay ////////////////////////////////////////////////////////
// Описание : functions.h                                                   //
//////////////////////////////////////////////////////////////////////////////

void bat::delay(bat::Real duration)
{
    Real start = time();
    
    // Задержка по времени на "duration"
    while (time() - start < duration)
    {
        // В пустую
    }
}

////////// Real time /////////////////////////////////////////////////////////
// Описание : functions.h                                                   //
//////////////////////////////////////////////////////////////////////////////

bat::Real bat::time()
{
    return static_cast<Real> (clock()) / CLOCKS_PER_SEC;
}

////////// void run //////////////////////////////////////////////////////////
// Описание : functions.h                                                   //
//////////////////////////////////////////////////////////////////////////////

void bat::run()
{
    // Задержка на случайное время
    delay(DURATION);
    
    // Вывод информации
    std::cout << "duration : " << DURATION << " sec\n";
}