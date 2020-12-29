#ifndef MANAGERLIB_H
#define MANAGERLIB_H

////////// st076569_12 ///////////////////////////////////////////////////////
// Автор  : Баталов Семен                                                   //
// Дата   : 29.10.2020                                                      //
// Задача : Реализовать потокобезопасную очередь. С помощью такой очереди   //
//          написать эффективную программу, обрабатывающую в k потоках      //
//          N >> k задач, каждая из которых требует t1 времени на preparing //
//          и t2 на processing.                                             //
//////////////////////////////////////////////////////////////////////////////

#include "queuelib.h"
#include <iomanip>
#include <iostream>

#include <ctime>
#include <vector>
#include <thread>

namespace bat
{
    // Общий вещественный тип
    typedef double Real;
    
    // Наибольшее время "processing" (sec)
    const int MAX_DURATION = 6;
    
    // Наибольшая задержка между появлением задач (sec)
    const int MAX_DELAY    = 2;
    
    // Кол-во поступающих в обработчик задач
    const int BUFFER_SIZE  = 10;
    
    ////////// struct Task ///////////////////////////////////////////////////
    // Эта структура представляет собой задачу для выполнения.              //
    //////////////////////////////////////////////////////////////////////////
    
    struct Task
    {
        public :
            
            Real duration;      // Продолжительность выполнения задачи (сек)
            Real start;         // Время поступления задачи (сек)
            bool isFinal;       // Завершающая задача?
            int  id;            // Уникальный номер задачи
            
        public :
            
            // (1) Конструктор
            Task();
            
            // (2) Конструктор копирования
            Task(const Task& task) = default;
            
            // (3) Перегрузка оператора присваивания
            Task& operator=(const Task& task) = default;
            
            // (4) Выводит информацию о задании на экран
            void print() const;
            
            // (5) Обнуляет поля
            void clear();
            
            // (6) Деструктор
            ~Task() = default;
    };
    
    ////////// struct Container //////////////////////////////////////////////
    // Эта структура характеризует очередь с возможностью параллельной      //
    // обработки задач в ней.                                               //
    //////////////////////////////////////////////////////////////////////////
    
    struct Container
    {
        public :
            
            bat::SafetyQueue<Task> dataList;    // Безопасная очередь задач
            std::mutex             printMut;    // "mutex" для вывода на экран
            int                    step;        // Очередной номер для вывода
            
        public :
            
            // (1) Конструктор
            Container();
            
            // (2) Конструктор копирования
            Container(const Container& newContainer) = delete;
            
            // (3) Перегрузка оператора присваивания
            Container& operator=(const Container& newContainer) = delete;
            
            // (5) Деструктор
            ~Container() = default;
    };
    
    ////////// class Buffer //////////////////////////////////////////////////
    // Класс, содержащий информацию о количестве и очередности поступления  //
    // задач. Производит закрузку задач в очередь диспетчера.               //
    //////////////////////////////////////////////////////////////////////////
    
    class Buffer
    {
        private :
            
            std::vector<Task> tasks_;       // Массив потенциальных задач
            Real              startPoint_;  // Точка начала отсчета
            int               step_;        // Номер очередной задачи
            
        public :
            
            // (1) Конструктор
            Buffer();
            
            // (2) Конструктор копирования
            Buffer(const Buffer& buffer) = default;
            
            // (3) Перегрузка оператора присваивания
            Buffer& operator=(const Buffer& buffer) = default;
            
            // (4) Инициализировать массив задач
            void initialize();
            
            // (5) Зафиксировать точку отсчета времени
            void setStartPoint(Real start);
            
            // (6) Если пришла очередная задача
            bool haveTask() const;
            
            // (7) Пуст ли буфер?
            bool empty() const;
            
            // (8) Вернуть поступившую задачу
            Task getTask();
            
            // (9) Возвращает счетчик в начало
            void back();
            
            // (10) Выводит информацию о заданиях на экран
            void print() const;
            
            // (11) Обнуляет поля
            void clear();
            
            // (12) Деструктор
            ~Buffer() = default;
    };
    
    ////////// void delay ////////////////////////////////////////////////////
    // Осуществляет задержку на время "duration" в секундах.                //
    //////////////////////////////////////////////////////////////////////////
    
    void delay(Real duration);
    
    ////////// Real time /////////////////////////////////////////////////////
    // Возвращает время от начала работы программы в секундах.              //
    //////////////////////////////////////////////////////////////////////////
    
    Real time();
    
    ////////// void dataPreparation //////////////////////////////////////////
    // Добавляет в очередь очередной элемент. Предназначена для вызова в    //
    // отдельном потоке.                                                    //
    //////////////////////////////////////////////////////////////////////////
    
    void dataPreparation(Container& dataQueue, Buffer& taskSeq);
    
    ////////// void dataProcessing ///////////////////////////////////////////
    // Считывает из очереди один элемент и обрабатывает его. Предназначена  //
    // для вызова в отдельном потоке.                                       //
    //////////////////////////////////////////////////////////////////////////
    
    void dataProcessing(Container& dataQueue);
    
    ////////// void parallelManager //////////////////////////////////////////
    // Обрабатывает последовательность элементов параллельно в нескольких   //
    // потоках.                                                             //
    //////////////////////////////////////////////////////////////////////////
    
    void parallelManager(Buffer& taskSeq);
    
    ////////// void consistentManager ////////////////////////////////////////
    // Обрабатывает последовательность элементов последовательно в одном    //
    // потоке.                                                              //
    //////////////////////////////////////////////////////////////////////////
    
    void consistentManager(Buffer& taskSeq);
    
    ////////// void message //////////////////////////////////////////////////
    // Инструкция.                                                          //
    //////////////////////////////////////////////////////////////////////////
    
    void message();
}

#endif