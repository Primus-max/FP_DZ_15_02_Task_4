// Пользователь вводит прибыль фирмы за год
// (12 месяцев).Необходимо определить месяц, в котором
// прибыль была максимальна и месяц, в котором прибыль
// была минимальна.

#include <iostream>;
#include <windows.h>;
using namespace std;

const int CalendarSize = 12;
int Calendar[CalendarSize];
double ProfitsPerMonth[CalendarSize];


/// <summary>
/// Метод проверки високосного года
/// </summary>
/// <param name="year">Текущий год</param>
/// <returns>bool является год високосным или нет</returns>
bool IsLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


/// <summary>
/// Метод заполнения массива днями 
/// </summary>
/// <param name="year">Текущий год</param>
/// <returns>Заполняет массив</returns>
void FillDaysInMonth(int year)
{
    for (int i = 1; i <= CalendarSize; i++)
    {
        // Формула расчёта дней в году
        int daysInMonth = 28 + (i + i / 8) % 2 + 2 % i + 2 * (1 / i);

        if (i == 2 && IsLeapYear(year))
            daysInMonth++;

        Calendar[i - 1] = daysInMonth;
    }
}


/// <summary>
/// Метод расчёта прибыли по месяцам
/// </summary>
/// <param name="totalProfit">Заполняет массив</param>
void CalcProfitPerMonth(double totalProfit)
{
    int totalDaysInYear = 0;

    // Получаю общее количество дней в году
    for (int i = 0; i < CalendarSize; i++)
        totalDaysInYear += Calendar[i];

    // Распределяю прибыль по месяцам
    for (int i = 0; i < CalendarSize; i++)
        ProfitsPerMonth[i] = totalProfit * (static_cast<double>(Calendar[i]) / totalDaysInYear);
}

/// <summary>
/// Метод для подсчёта и вывода максимального дохода
/// </summary>
void FindMaxProfit(int monthStart, int monthEnd)
{
    int maxProfitMonth = monthStart + 1;
    double maxProfit = ProfitsPerMonth[monthStart];

    for (int i = monthStart ; i <= monthEnd; i++)
    {
        if (ProfitsPerMonth[i] > maxProfit)
        {
            maxProfit = ProfitsPerMonth[i];
            maxProfitMonth = i + 1;
        }
    }

    std::cout << "Максимальная прибыль была в " << maxProfitMonth
        << " месяце, составила: " << maxProfit << " денег " << std::endl;
}

/// <summary>
/// Метод для подсчёта и вывода минимального дохода
/// </summary>
void FindMinProfit(int monthStart, int monthEnd)
{
    int minProfitMonth = monthStart + 1;
    double minProfit = ProfitsPerMonth[monthStart];

    for (int i = monthStart + 1 ; i <= monthEnd; i++)
    {
        if (ProfitsPerMonth[i] < minProfit)
        {
            minProfit = ProfitsPerMonth[i];
            minProfitMonth = i + 1;
        }
    }

    std::cout << "Минимальная прибыль была в " << minProfitMonth
        << " месяце, составила: " << minProfit << " денег " << std::endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double profitForYear = 0, maxProfit = 0, minProfit = 0;
    int year = 0, monthStart = 0, monthEnd = 11;

    FillDaysInMonth(2023);
    CalcProfitPerMonth(300000);

    cout << "Калькулятор расчёта прибыли за указанный период в году. " << endl
        << +"Будет рассчитана максимальная и минимальная прибыль за указанный период\n";
    cout << "--------------------------------------------------------" << endl;
    cout << "Введите год для расчёта : ";
    cin >> year;
    cout << "Введите прибыль за весь год : ";
    cin >> profitForYear;   


    FindMaxProfit(monthStart, monthEnd);
    FindMinProfit(monthStart, monthEnd);
}