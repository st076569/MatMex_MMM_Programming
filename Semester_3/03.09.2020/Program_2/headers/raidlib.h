#ifndef RAIDLIB_H
#define RAIDLIB_H

////////// RAID 5 ////////////////////////////////////////////////////////////
// Автор  : Баталов Семен                                                   //
// Дата   : 10.09.2020                                                      //
// Задача : Решить задачу с помощью STL. Эффективно смоделировать RAID 5,   //
//          для k буферов размера n кБайт. Технология использует            //
//          контрольные суммы для восстановления данных в случае выхода из  //
//          строя одного жёсткого диска. Нужно проделать тоже самое, только //
//          на буферах (массивах фиксированной длины). В моделировании      //
//          нужно заполнить несколько буферов данных, по ним построить      //
//          буфер контрольных сумм. Затем выбрать случайным образом один из //
//          буферов, как исчезнувший. После восстановить исчезнувшие данные //
//          и сравнить восстановленные данные с настоящими.                 //
//////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <bitset>

namespace bat
{
    // Размер битового блока (кол-во бит)
    const int BLOCK_SIZE = 64;
    
    // Максимальный размер буфера (в блоках)
    const int MAX_BUFFER_SIZE   = 50;
    
    // Максимальное количество буферов в массиве
    const int MAX_BUFFER_NUMBER = 50;
    
    // Тип : Битовый блок
    typedef std::bitset<BLOCK_SIZE> Block;
    
    // Тип : Массив битовых блоков
    typedef std::vector<Block>      BlockVector;
    
    ////////// struct Buffer /////////////////////////////////////////////////
    // Эта структура представляет из себя буфер, состоящий из битовых       //
    // блоков и являющийся элементом массива RAID.                          //
    //////////////////////////////////////////////////////////////////////////
    
    struct Buffer
    {
        public :
            
            BlockVector blocks;             // Массив битовых блоков
            bool        isCrashed;          // Переменная состояния буфера
            
        public :
            
            // (1) Конструктор
            Buffer();
	    
            // (2) Конструктор копирования
            Buffer(const Buffer& buffer);
	    
            // (3) Перегрузка оператора присваивания
            Buffer& operator=(const Buffer& buffer);
            
            // (4) Вывод в консоль
            void print();
            
            // (5) Изменяет размер буфера
            void resize(const int& blockNumber);
            
            // (6) Задает случайные значения
            void setRandomValues();
            
            // (7) Сбрасывает значение статуса
            void resetStatus();
            
            // (8) Сбрасывает значения всех битов до нуля
            void reset();
            
            // (9) Очищает элементы буфера
            void clear();
            
            // (10) Деструктор
            ~Buffer();
    };
    
    ////////// class Raid5 ///////////////////////////////////////////////////
    // Этот класс представляет модель технологии "Raid 5". Она позволяет    //
    // быстро востанавливать данные в случае выхода из строя одного из      //
    // носителей.                                                           //
    //////////////////////////////////////////////////////////////////////////
    
    class Raid5
    {
        private :
            
            std::vector<Buffer> buffers_;        // Массив буферов
            int                 bufferNumber_;   // Кол-во буферов
            int                 bufferSize_;     // Размер буферов
        
        public :
            
            // (1) Конструктор
            Raid5();
	    
            // (2) Конструктор копирования
            Raid5(const Raid5& raid5);
	    
            // (3) Перегрузка оператора присваивания
            Raid5& operator=(const Raid5& raid5);
            
            // (4) Вывод в консоль
            void print();
            
            // (5) Изменяет размеры рейда
            void resize(const int& buffferNumber, const int& bufferSize);
            
            // (6) Задает случайные значения буферов
            void setRandomValues();
            
            // (7) Записать все контрольные суммы
            void setControlSums();
            
            // (8) Разрушить буфер под номером "bufferNumber"
            void crashBuffer(const int& bufferNumber);
            
            // (9) Восстановить утраченную информацию
            void recoverInformation();
            
            // (10) Сбрасывает значения всех статусов
            void resetStatuses();
            
            // (11) Сбрасывает значения всех битов до нуля, сбрасывает статусы
            void reset();
            
            // (12) Очищает элементы буфера
            void clear();
            
            // (13) Деструктор
            ~Raid5();
    };
}

#endif
