/**
 * Практическое занятие №1. Базовые типы данных, операторы языка, простой
 * ввод-вывод.
 *
 * В результате выполнения данной работы слушатель получает много мелких, но
 * необходимых для дальнейшей работы навыков, поэтому задание построено как
 * последовательность закомментированных блоков, которые требуется
 * последовательно раскомментировать, отвечая при этом на поставленные вопросы.
 *
 * Необходимое программное обеспечение:
 *
 * - Unix-совместимая командная строка (для Windows необходимо установить WSL);
 * - компилятор g++, отладчик gdb (для установки в командной строке:
 *   `apt update; apt install gcc g++ gdb`)
 * - любимый текстовый редактор.
 *
 * Примерная последовательность действий при отладке проекта:
 * 1. наберите (исправьте, раскомментируйте нужный фрагмент) исходный текст
 *    программы;
 * 2. скомпилируйте программу (в командной строке: `g++ -g lab1.cpp`);
 * 3. запустите отладчик (в командной строке `gdb ./a.out`);
 * 4. в отладчике установите точку останова на нужной строке (например,
 *    `break 55` для 55 строки или `b 55` - так короче) и начните выполнение
 *    программы (`run` или `r`).
 * 5. выведите значение интересующей переменной (`print cByte` или `p cByte`)
 *    или добавьте переменную для постоянного отслеживания (`watch cByte`).
 * 6. Переходите к следующей точке останова (`c`) или к следующей строке (`n`).
 */

#include  <iostream>

int nTwin = 1;
namespace TwinSpace { int nTwin = 2; }

using namespace std;

int main()
{

    /**
     * Задание 1. Работа с отладчиком. Базовые типы данных. Литералы.
     *
     * Выполняя программу по шагам, следите за значениями переменных и
     * интерпретируйте результат (помните, что количество байт, отводимых под
     * int, системо-зависимо).
     *
     * Обратите внимание на разную интерпретацию отладчиком signed и unsigned
     * целых типов данных, а также на внутреннее представление отрицательных
     * целых чисел.
     */

    char cByte = 'A';
    cByte = 0x42;
    cByte = 66;
    cByte = -1;

    unsigned char ucByte = 0x41;
    ucByte = 'B';
    ucByte = -1;

    int iInt = 0xffffffff;

    unsigned int uiInt = 0xffffffff;

    float fFloat = 1.f;
    double dDouble = 1.;

    /**
     * Выполните фрагмент, приведенный далее. В комментариях отразите, что
     * реально заносится в переменную. Объясните разницу между этим значением и
     * инициализатором.
     */

    double d = 0.1234567890123456789123456789; // 0.12345678901234568
    float  f = 0.1234567890123456789123456789; // 0.123456791

    d = 1.; //1
    d = 0.999999999999999999999999999999999; //1

    /**
     * В комментариях напишите результат, возвращаемый оператором sizeof для
     * переменной типа wchar_t (ее размер)
     */

    wchar_t cw = L'Ф';
    size_t n = sizeof(cw); //4

    /**
     * Задание 2a. Неявное приведение типов данных.
     *
     * Объясните разницу результата при выполнении (1) и (2): Покажите явно
     * (напишите в коде) преобразования, которые неявно выполняет компилятор
     */

    iInt = 1;
    double dDouble1 = iInt / 3;     // (1)
    double dDouble2 = iInt / 3.;    // (2)

    // (1) Выполняет операцию с int типом. Приводит к целому --> зн. пепеменной 0
    // (2) Выполняет преобразоване типов к double --> зн. пепеменной 0.33333333333333331

    /**
     * Ассоциативность операторов.
     *
     * Синтаксис языка C допускает "цепочечное" присваивание (как в строках (1)
     * и (2)). Посмотрев результаты выполнения строк (1) и (2) (значения
     * переменных dDouble, fFloat, nInt, sShort, cByte), определите порядок
     * выполнения присваиваний при цепочечной записи и объясните результат.
     *
     * Расставьте скобки, явно определяющие порядок выполнения, как это сделал
     * бы компилятор. Объясните (в комментариях) предупреждения (warnings)
     * компилятора.
     */

    short sShort;
    dDouble = (fFloat = (iInt = (sShort = (cByte = 3.3 / 3)))); // (1)

    cByte = (sShort = (iInt = (fFloat = (dDouble = 3.3 / 3)))); // (2)

    /**
     * Ниже Вам дан пример "небрежного" использования неявного приведения
     * типов, что может привести к нежелательным результатам - объясните (в
     * комментариях), к каким?
     *
     * Напишите явно преобразования, которые неявно выполняет компилятор.
     */

    iInt = 257;
    cByte = iInt; //iInt - числовой тип, cByte - строковый => cByte присваивается строковое значание (1 '\001')

    unsigned char cN1 = 255, cN2 = 2, cSum;
    cSum = cN1 + cN2; //cN1, cN2, cSum - переменные строкового типа => для cSum присвается строковое значение (1 '\001')

    /**
     * Сравните предыдущую строчку с приведенной ниже.
     *
     * Объясните (в комментариях), почему в следующей строке не происходит
     * выход за разрядную сетку
     *
     * Напишите явно преобразования, которые неявно выполняет компилятор
     */

    int iSum = cN1 + cN2; //iSum - числовой тип (может хранить 4 байта инф.) - является суммой номеров строковых cN1 и cN2
    // (char) 255 '\377' + (char) 2 '\002' = (int) 257

    /**
     * Напишите, почему при сложении одинаковых значений (одинаковых в двоичной
     * системе) в строках (1) и (2) получаются разные результаты.
     *
     * Напишите явно преобразования, которые неявно выполняет компилятор и
     * объясните, что при этом происходит.
     */

    char c1 = 0xff, c2 = 2;
    unsigned char uc1 = 0xff, uc2 = 2;
    int iSum1 = c1 + c2;   //iSum1 - число, обозначающее номер некого символа char c = c1 + c2
                           //Т.к. char занимает в памяти 1 байт, то сложение c1 + c2 приводит к переплонению ячейки
    int iSum2 = uc1 + uc2; //iSum2 - тоже число, обозначающее номер некого символа unsigned char c = c1 + c2
                           //Однако unsigned char хранит в себе только неотрицательные значение, поэтому сложение c1 и c2 не приводит к переполнению ячейки


    /**
     * Задание 2b. Явное приведение типов данных.
     *
     * Проинтерпретируйте результат (значения переменной dDouble) в строке (3).
     *
     * Напишите явно преобразования, которые неявно выполняет компилятор.
     */

    int nTmp = 100, nn = 3;
    dDouble = 3.3 + nTmp / nn; // double dDouble = double + int/int --> совершает операцию над int/int (100/3 = 33)  --> приводит к double и прибавляет 3.3 --> 36.299999999999997

    /**
     * Получите результат без потери точности с помощью оператора явного
     * приведения типа.
     */

     double dDouble3 = 3.3 + double(nTmp) / double(nn); // --> 36.633333333333333

    /**
     * Задание 3. Область действия, область видимости и время существования
     * переменных.
     *
     * В этом фрагменте фигурируют четыре переменных с одним и тем же именем
     * nTwin - одна глобальная, вторая определена в своем пространстве имен,
     * (определены выше в начале модуля) третья - локальная внутри функции
     * main(), четвертая - вложенная локальная внутри блока.
     *
     * В данном задании требуется в выделенных местах фрагмента определить, к
     * какой из четырех переменных идет обращение, а также факт существования и
     * видимости для всех четырех, заполнив приведенные в задании табwtлицы.
     *
     * Для выведения информации в отладчике можно воспользоваться командой
     * `info locals`, которая выведет локальные переменные в функции main(),
     * и командой `watch nTwin` или `wacth ::nTwin` для отслеживания значений
     * переменных.
     */

    nTwin = 100; //Old value = 1 -- New value = 100
    TwinSpace::nTwin = 300;
    nTwin++; 

    int nTwin;
    nTwin = 200; //200 - не глобальная
    ::nTwin++; //Old value = 100 -- New value = 101
    {
        int nTwin;
        nTwin = -1;
        ::nTwin++; //Old value = 101 -- New value = 102
        TwinSpace::nTwin++;
    }

    nTwin--;


    /**
     * Задание 4. Спецификатор класса памяти - static.
     *
     * 1. Для каждой итерации цикла напишите значения пременных nLocal# и
     *    nStatic#.
     * 2. Напишите, когда выполняется инициализация обеих переменных.
     * 3. Поясните (в комментарии) разницу между способом инициализации
     *    переменных nStatic1 и nStatic2 и поясните побочный эффект, влияющий
     *    на переменную nLocal2.
     */

    for (int i = 0; i < 3; i++)
    {
        static int nStatic1 = 100;
        int nLocal1 = 100;
        int nLocal2 = 200;
        static int nStatic2 = nLocal2++ * 2;
        nStatic1++;
        nStatic2++;
        nLocal1++;
    }

    // Значения в конце итерации цикла: 
    // i=0:
    // nLocal1=101
    // nLocal2=201
    // nStatic2=101
    // nStatic2=401
    // i=1:
    // nLocal1=101
    // nLocal2=201
    // nStatic2=102
    // nStatic2=402
    // i=2:
    // nLocal1=101
    // nLocal2=201
    // nStatic2=103
    // nStatic2=403

    // Инициализация nLocal# происходит на каждой итерации цикла -- с каждой новой итерацией перезаписывается ячейка памяти
    // Инициализация nStatic# происходит при первой итерации цикла -- с каждой новой итерацией изменяется только значение переменной

    // К переменной nLocal1 прибавляется 1

    /**
     * Напишите:
     * 1. как изменилось поведение пременной nStatic1?
     * 2. как эта переменная _инициализирована_?
     */

    for (int i = 0; i < 3; i++)
    {
        static int nStatic1;
        nStatic1 = 100;
        int nLocal1 = 100;
        nStatic1++;
        nLocal1++;
    }

    /**
     * Задание 5. Перечисления - enum.
     *
     * Обратите внимание на явную и неявную инициализацию констант.
     *
     * Выполняя задание по шагам, следите за значениями, которые принимает
     * переменная myColors.
     */

    enum eColors
    {
        BLACK,
        BLUE,
        GREEN,
        RED=5,
        YELLOW,
        WHITE=RED+4
    };

    eColors myColors; //объявление переменной типа eColors
    myColors = BLACK;
    myColors = BLUE;
    myColors = GREEN;
    myColors = RED;
    myColors = YELLOW;
    myColors = WHITE;

    int nnn = BLACK; //любой целочисленной переменной можно присвоить
                     //значение из списка инициализирующих значений
    std::cout << nnn << endl;
    //Именованные константы можно использовать в выражениях:
    nnn = BLUE | YELLOW;

    /**
     * Раскомментируйте следующую строку и обратите внимание на ошибку при
     * компиляции.
     *
     * Модифицируйте выражение таким образом, чтобы компилятор не выдывал
     * ошибки.
     */

    myColors = BLACK;

    /**
     * Выполните следующее присваивание НЕ меняя перечисление и тип переменной
     * myColors.
     */

    // myColors = 123;


    /**
     * Задание 6.1 Логический тип bool.
     *
     * Выполняя задание по шагам, следите за значениями переменной b и
     * интерпретируйте результат.
     *
     * Напишите эти значения в комментариях.
     */

    int nNumber = 1;
    bool b = (nNumber != 0); //
    b = (nNumber == 0); //
    b = (nNumber > 0); //
    b = (nNumber > 1); //
    b = 5; //

    /**
     * Вы всегда можете преобразовать логическое значение к целому явно или
     * компилятор может это сделать самостоятельно (неявно).
     *
     * Обратите внимание: как интерпретирует значения логических переменных
     * компилятор?
     */

    int tmp =  b + 1; //

    /**
     * Задание 6.2.
     *
     * В Григорианском календаре (которым мы все пользуемся) високосный год
     * определяется по следующему алгоритму: високосным является каждый
     * четвертый год, но каждый сотый високосным не является, при этом каждый
     * 400-й год все таки високосный. Т.е. 1823 - не високосный, 1824 -
     * високосный, 1900 - не високосный, 2000 - високосный.
     *
     * Напишите фрагмент кода, такой что логическая переменная isLeapYear
     * принимает значение true, если год, заданный переменной year -
     * високосный. Проверьте значение в отладчике.
     *
     * Указание: в этом задании нельзя использовать операторы if-else, switch и
     * тернарный оператор; необходимо написать логическое выражение в одну
     * строку.
     */

    {
        int year = 1823;
        // year = 1824;
        // year = 1900;
        // year = 2000;

        // bool isLeapYear =
    }

    /**
     * Задание 7. Модификатор const и переменные.
     *
     * Раскомментируйте следующие две строчки и объясните (в комментариях)
     * ошибки при компиляции.
     */

    {
        //  const int nN; //
        //  nN = 1; //
    }

    /**
     * Задание 8. Потоки ввода и вывода C++.
     *
     * Напишите фрагмент кода, который бы с помощью объектов потока std::cin и
     * std::cout делал бы следующее:
     *
     * 1. Выводил бы на экран номер задания.
     * 2. Считывал целое число.
     * 3. Считывал символ.
     * 4. Выводил пользователю введенный им символ.
     * 5. Выводил пользователю введенное им целое число.
     *
     * При этом добавьте в места, где от пользователя ожидается ввод,
     * соответствующие приглашения ко вводу (например, `Введите целое число: `).
     */

    {
        int inputInt;
        char inputChar;
    }

    /**
     * Задание 9. Логические условные операторы и операторы отношения.
     */

    /**
     * Задание 9.1.
     *
     * Напишите фрагмент кода, который переводит код символа, хранящийся в
     * переменной ch в противоположный регистр.
     *
     * Требуется предусмотреть проверку ситуации, когда пользователь ввел цифру
     * или нажал другую клавишу, которой символ не соответствует.
     *
     * Подсказка: работаем только с символами английского алфавита, для
     * которого в таблице кодов ASCII код каждой буквы нижнего регистра на 0x20
     * больше кода соответствующей буквы верхнего регистра.
     */

    {
        char ch;
        /** Тут сформируйте значение переменной ch с помощью потока ввода. */

        /** Тут измените регистр. */

        /** Тут вывели получившийся символ пользователю. */
    }

    /**
     * Задание 9.2.
     *
     * Напишите фрагмент кода, который реализует с помощью if (if/else)
     * следующую логику: если x меньше или равен 0, y=0, если x больше 0 но
     * меньше 1, то y=x, если x больше или равен 1, то y=1.
     *
     * Подумайте: какого типа должны или могут быть x и y?
     */

    {
    }

    /**
     * Задание 9.3
     *
     * Напишите фрагмент кода, который реализует с помощью switch следующую
     * логику: в переменной cInput типа char дано значение символа, введенного
     * любым способом.
     *
     * Если введен символ 'y' (т.е. yes) в любом регистре, то присвоить
     * переменной у значение переменной x.
     *
     * Если введен символ 'n' (т.е. no) в любом регистре, то присвоить
     * переменной у значение (x * 2).
     *
     * Если любой другой симол, то вывести сообщение об ошибке.
     */

    {
        char ch;
    }

    /**
     * Задание 10. Циклы.
     */

    /**
     * Задание 10.1.
     *
     * Напишите фрагмент кода, который реализует с помощью for следующую
     * логику: найти сумму заданного диапазона целых чисел.
     *
     * Введите границы с помощью потока ввода или с помощью средств отладки.
     *
     * Предусмотрите защиту от ввода нижней границы больше, чем верхней.
     */

    {
        /** сформироыать границы диапазона */

        /** проверить корректность значений */

        /** вычислить сумму */

        /** проверить в отладчике значение */
    }

    /**
     * Задание 10.2.
     *
     * Напишите фрагмент кода, который реализует с помощью do-while следующую
     * логику: на каждой итерации цикла ввести с консоли целое значение и
     * покинуть цикл, если значение удовлетворяет условию: значение больше или
     * равно 10 и четное.
     */

    {

    }

    /**
     * Задание 10.3.
     *
     * Напишите фрагмент кода, который реализует с помощью while следующую логику:
     *
     * 1. исходно int x = 0;
     * 2. на каждой итерации x = x + 1, sum = sum + 1 / x;
     * 3. необходимо найти значение x, при котором sum > 1.7.
     */

    {

    }

    /**
     * Задание 10.4.
     *
     * Раскомментируйте следующий блок кода, который считает сумму 10
     * последовательных натуральных чисел, начиная со 120.
     *
     * Объясните логические ошибки в нем и исправьте их.
     */

    {
        // char start = 120, sum = 0;
        // for (char n = start; n < start + 10; ++n) {
        //    sum += n;
        // }
    }

    return 0; /** код завершения приложения */
}
