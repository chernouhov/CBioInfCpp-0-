// Документы CBioInfCpp.h, About_CBioInfCpp.rtf, About_CBioInfCpp.pdf (все указанные файлы размещены в настоящем каталоге) составляют собой одно произведение, которое распространяется на условиях лицензии Creative Commons Attribution 4.0 International Public License (сокращенно - CC BY, гиперссылка на текст лицензии: https://creativecommons.org/licenses/by/4.0/legalcode.ru).

// Автор CBioInfCpp.h, About_CBioInfCpp.rtf, About_CBioInfCpp.pdf - Черноухов Сергей (chernouhov@rambler.ru)

// The documents About_CBioInfCpp.pdf, CBioInfCpp.h, About_CBioInfCpp.rtf (all of them are placed in this directory) constitute a single Work (i.e. this Work is divided into these 3 files), and this Work is distributed under Creative Commons Attribution 4.0 International Public License (CC BY) (hyperlink to the License: https://creativecommons.org/licenses/by/4.0/legalcode.ru).

// CBioInfCpp.h, About_CBioInfCpp.rtf, About_CBioInfCpp.pdf are written by Sergey Chernouhov (chernouhov@rambler.ru).

#ifndef CBIOINFCPP_H
#define CBIOINFCPP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#include <limits.h>
#include <float.h>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <functional>



int FastaRead (std::ifstream & fin, std::vector <std::string> & IndexS, std::vector <std::string> & DataS)

// Чтение строк FASTA из файла. Возвращает 0, если кол-во индексов строк равно кол-ву самих строк, самая первая строка является индексом (не начинается с ">") и в процессе считывания не встретились 2 индекса подряд. Иначе вернет -1.

// Reads FASTA dataset from file. Returns 0 if the number of indexes of strings = number of strings, the first string in dataset is index (starts with ">") and in dataset there is no 2 indexes one-by-one without a data string in between. Otherwise returns -1.


{
IndexS.clear();
// Сюда будут записываться индексы (обозначения) строк
// Here indexes of strings will be contained

DataS.clear();
// Сюда будут записываться сами строки
// Here data strings will be contained

std::string TempS = "";

int q = -1;

char f = 'd';
// флаг f = 'd'(data) или 'i' (индекс) - для исключения ситуации когда подряд идут 2 индекса
// flag f may be set as 'd' (data) or 'i' (index) - to prevent code-after-code situation.


while (!fin.eof())
    {
       TempS.clear();
       getline (fin, TempS);
       if (TempS[0] == '>')
        {
           if (f == 'i') {IndexS.clear(); DataS.clear(); return -1;}
           q++;
           f = 'i';
           DataS.push_back("");
           TempS.erase(0,1); // Вырезание начального символа ">"  cutting symbol ">" from string's code
           IndexS.push_back(TempS);
        }
        else
        {
            if (q==-1) return -1;
            if (TempS.length() !=0) {DataS[q] = DataS[q] + TempS; f = 'd';};
        }

   }

        if (DataS.size()!=IndexS.size()) {IndexS.clear(); DataS.clear(); return -1;}

return 0;
}

void StringsRead (std::ifstream & fin, std::vector <std::string> & DataS) // reads all strings from file to vector DataS

{
   std::string TempS = "";
    while (!fin.eof())
    {
        getline (fin, TempS);
        if (TempS.length()!=0) DataS.push_back(TempS);
        TempS.clear();
}

}

int MatrixSet (std::vector <std::vector <double>> & B, const int NLines, const int NColumns, const double i)
// Создает матрицу NLines х NColumns и заполняет значением i (double). Возвращает -1 если число строк или столбцов неположительно
// Sets (resets) matrix NLines x NColumns filled value "i" (double). Returns -1 if NLines or NColumns <=0

{

    if ((NLines<=0) || (NColumns<=0)) return -1;

    B.resize (NLines);
    for (unsigned int row = 0; (row< NLines); row++)
    {
        B [row].resize(NColumns);
        for (unsigned int column = 0; column < NColumns; column++)
            {
                B [row] [column] = i;
            }

    }
    return 0;
}


int MatrixSet (std::vector <std::vector <int>> & B, const int NLines, const int NColumns, const int i)
// Создает матрицу NLines х NColumns и заполняет значением i (int). Возвращает -1 если число строк или столбцов неположительно
// Sets (resets) matrix NLines x NColumns filled value "i" (int). Returns -1 if NLines or NColumns <=0

{

    if ((NLines<=0) || (NColumns<=0)) return -1;

    B.resize (NLines);
    for (unsigned int row = 0; (row< NLines); row++)
    {
        B [row].resize(NColumns);
        for (unsigned int column = 0; column < NColumns; column++)
            {
                B [row] [column] = i;
            }
    }
    return 0;
}



int MatrixSet (std::vector <std::vector <long long int>> & B, const int NLines, const int NColumns, const long long int i)
// Создает матрицу NLines х NColumns и заполняет значением i (long long int). Возвращает -1 если число строк или столбцов неположительно
// Sets (resets) matrix NLines x NColumns filled value "i" (long long int). Returns -1 if NLines or NColumns <=0

{

    if ((NLines<=0) || (NColumns<=0)) return -1;

    B.resize (NLines);
    for (unsigned int row = 0; (row< NLines); row++)
    {
        B [row].resize(NColumns);
        for (unsigned int column = 0; column < NColumns; column++)
            {
                B [row] [column] = i;
            }
    }
    return 0;
}




int MatrixSet (std::vector <std::vector <long double>> & B, const int NLines, const int NColumns, const long double i)
// Создает матрицу NLines х NColumns и заполняет значением i (long double). Возвращает -1 если число строк или столбцов неположительно
// Sets (resets) matrix NLines x NColumns filled value "i" (long double). Returns -1 if NLines or NColumns <=0

{

    if ((NLines<=0) || (NColumns<=0)) return -1;

    B.resize (NLines);
    for (unsigned int row = 0; (row< NLines); row++)
    {
        B [row].resize(NColumns);
        for (unsigned int column = 0; column < NColumns; column++)
            {
                B [row] [column] = i;
            }

    }
    return 0;
}



int MatrixSet (std::vector <std::vector <short int>> & B, const int NLines, const int NColumns, const short int i)
// Создает матрицу NLines х NColumns и заполняет значением i (short int). Возвращает -1 если число строк или столбцов неположительно
// Sets (resets) matrix NLines x NColumns filled value "i" (short int). Returns -1 if NLines or NColumns <=0

{

    if ((NLines<=0) || (NColumns<=0)) return -1;

    B.resize (NLines);
    for (unsigned int row = 0; (row< NLines); row++)
    {
        B [row].resize(NColumns);
        for (unsigned int column = 0; column < NColumns; column++)
            {
                B [row] [column] = i;
            }

    }
    return 0;
}


int MatrixSet (std::vector <std::vector <bool>> & B, const int NLines, const int NColumns, const bool i)
// Создает матрицу NLines х NColumns и заполняет значением i (bool). Возвращает -1 если число строк или столбцов неположительно
// Sets (resets) matrix NLines x NColumns filled value "i" (bool). Returns -1 if NLines or NColumns <=0

{

    if ((NLines<=0) || (NColumns<=0)) return -1;

    B.resize (NLines);
    for (unsigned int row = 0; (row< NLines); row++)
    {
        B [row].resize(NColumns);
        for (unsigned int column = 0; column < NColumns; column++)
            {
                B [row] [column] = i;
            }

    }
    return 0;
}


int MatrixCout (std::vector <std::vector <int>> & B, char g = ' ')
// Вывод матрицы (int) на экран через пробелы. Возвращает -1, если матрица не содержит строк/ столбцов
// Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
// "Couts" Matrix (int) to screen. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.

{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;



    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                std::cout<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                std::cout<< g << " ";
            }


        std::cout<< std::endl;
    }
    return 0;
}



int MatrixCout (std::vector <std::vector <short int>> & B, char g = ' ')
// Вывод матрицы (short int) на экран через пробелы. Возвращает -1, если матрица не содержит строк/ столбцов
// Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
// "Couts" Matrix (short int) to screen. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.

{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;



    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                std::cout<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                std::cout<< g << " ";
            }


        std::cout<< std::endl;
    }
    return 0;
}



int MatrixCout (std::vector <std::vector <bool>> & B, char g = ' ')
// Вывод матрицы (bool) на экран через пробелы (в формате 1 или 0). Возвращает -1, если матрица не содержит строк/ столбцов
// Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
// "Couts" Matrix (bool) to screen as "1" or "0". Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.

{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;



    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                std::cout<< (short int)B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                std::cout<< g << " ";
            }


        std::cout<< std::endl;
    }
    return 0;
}


int MatrixCout (std::vector <std::vector <long long int>> & B, char g = ' ')
// Вывод матрицы (long long int) на экран через пробелы. Возвращает -1, если матрица не содержит строк/ столбцов
// Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
// "Couts" Matrix (long long int) to screen. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.

{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;



    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                std::cout<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                std::cout<< g << " ";
            }


        std::cout<< std::endl;
    }
    return 0;
}


int MatrixCout (std::vector <std::vector <double>> & B, unsigned int prec = 4, char g = ' ', bool scientifique = false)
// Вывод матрицы (double) на экран через пробелы. Возвращает -1, если матрица не содержит строк/ столбцов
// Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
// Вывод чисел проводится с заданной точностью prec, если bool scientifique == false. Если bool scientifique == true, вывод производится в экспоненциальной форме.
// "Couts" Matrix (double) to screen. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    if (!scientifique)
   {
    std::cout.precision(prec);

    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                std::cout<< std::fixed<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                std::cout<< g << " ";
            }


        std::cout<< std::endl;
    }

    }


    if (scientifique)
    {


        for (unsigned int row = 0; (row< NLines); row++)
        {

            //for (unsigned int column = 0; column < NColumns; column++)
            for (unsigned int column = 0; column < B[row].size(); column++)
                {
                    std::cout<< std::scientific << B [row] [column]<< " ";
                }

            std::cout.unsetf(std::ios::scientific);

            for (unsigned int column = B[row].size(); column < NColumns; column++)
                {
                    std::cout<< g << " ";
                }


            std::cout<< std::endl;
        }

    }


    return 0;
}


int MatrixCout (std::vector <std::vector <long double>> & B, unsigned int prec = 4, char g = ' ', bool scientifique = false)
// Вывод матрицы (long double) на экран через пробелы. Возвращает -1, если матрица не содержит строк/ столбцов
// Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
// Вывод чисел проводится с заданной точностью prec, если bool scientifique == false. Если bool scientifique == true, вывод производится в экспоненциальной форме.
// "Couts" Matrix (long double) to screen. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    if (!scientifique)
   {
    std::cout.precision(prec);

    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                std::cout<< std::fixed<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                std::cout<< g << " ";
            }


        std::cout<< std::endl;
    }

    }


    if (scientifique)
    {


        for (unsigned int row = 0; (row< NLines); row++)
        {

            //for (unsigned int column = 0; column < NColumns; column++)
            for (unsigned int column = 0; column < B[row].size(); column++)
                {
                    std::cout<< std::scientific<< B [row] [column]<< " ";
                }

            std::cout.unsetf(std::ios::scientific);

            for (unsigned int column = B[row].size(); column < NColumns; column++)
                {
                    std::cout<< g << " ";
                }


            std::cout<< std::endl;
        }

    }


    return 0;
}


int MatrixFout (std::vector <std::vector <double>> & B, std::ofstream & fout, unsigned int prec = 4, char g = ' ', bool scientifique = false)
// Вывод матрицы (double) в файл через пробелы. Возвращает -1, если матрица не содержит строк/ столбцов
// Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
// Вывод чисел проводится с заданной точностью prec, если bool scientifique == false. Если bool scientifique == true, вывод производится в экспоненциальной форме.
// "Fouts" Matrix (double) to file. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    if (!scientifique)
    {
    fout.precision(prec);

    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< std::fixed<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }
    }


    if (scientifique)
    {


    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< std::scientific<< B [row] [column]<< " ";
            }

        fout.unsetf(std::ios::scientific);
        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }


    }



    return 0;
}


int MatrixFout (std::vector <std::vector <long double>> & B, std::ofstream & fout, unsigned int prec = 4, char g = ' ', bool scientifique = false)
// Вывод матрицы (long double) в файл через пробелы. Возвращает -1, если матрица не содержит строк/ столбцов
// Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
// Вывод чисел проводится с заданной точностью prec, если bool scientifique == false. Если bool scientifique == true, вывод производится в экспоненциальной форме.
// "Fouts" Matrix (long double) to file. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    if (!scientifique)
    {
    fout.precision(prec);

    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< std::fixed<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }
    }


    if (scientifique)
    {


    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< std::scientific<< B [row] [column]<< " ";
            }

        fout.unsetf(std::ios::scientific);
        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }


    }



    return 0;
}



int MatrixFout (std::vector <std::vector <int>> & B, std::ofstream & fout, char g = ' ')
// Вывод матрицы (int) в файл через пробелы. Возвращает -1, если матрица не содержит строк/ столбцов
// Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
// "Fouts" Matrix (int) to file. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }
    return 0;
}


int MatrixFout (std::vector <std::vector <short int>> & B, std::ofstream & fout, char g = ' ')
// Вывод матрицы (short int) в файл через пробелы. Возвращает -1, если матрица не содержит строк/ столбцов
// Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
// "Fouts" Matrix (short int) to file. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }
    return 0;
}


int MatrixFout (std::vector <std::vector <bool>> & B, std::ofstream & fout, char g = ' ')
// Вывод матрицы (bool) в файл через пробелы (в формате 1 или 0). Возвращает -1, если матрица не содержит строк/ столбцов
// Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
// "Fouts" Matrix (bool) to file as "1" or "0". Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< (short int) B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }
    return 0;
}


int MatrixFout (std::vector <std::vector <long long int>> & B, std::ofstream & fout, char g = ' ')
// Вывод матрицы (long long int) в файл через пробелы. Возвращает -1, если матрица не содержит строк/ столбцов
// Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
// "Fouts" Matrix (long long int) to file. Returns -1 if the Matrix is empty.
// The Matrix may have lines of different length. In this case the "missing" values to the end for the "shorter lines" are filled with the char g.
{

    int NLines, NColumns;
    NLines = B.size();
    if (NLines==0) return -1;
    NColumns = B[0].size();

    for (int i=0;i<NLines; i++)
        if (B[i].size()>NColumns) NColumns=B[i].size();

    if (NColumns==0) return -1;


    for (unsigned int row = 0; (row< NLines); row++)
    {

        //for (unsigned int column = 0; column < NColumns; column++)
        for (unsigned int column = 0; column < B[row].size(); column++)
            {
                fout<< B [row] [column]<< " ";
            }

        for (unsigned int column = B[row].size(); column < NColumns; column++)
            {
                fout<< g << " ";
            }


        fout<< std::endl;
    }
    return 0;
}


int FindIn (const std::vector <int> &D, int a, int step = 1, int start = 0)
{
// Возвращает индекс первого найденного элемента (int), совпадающего с искомым (a), поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - возвращаем -1. Если переданное значение step <1, то step присваивается значение 1. Если переданное значение start <0, то start присваивается значение 1.
// Returns index in vector (int) of the first element = a. Search starts from index "start" with step = "step". If no such element found the function returns 0. If step<1 step will be set as 1. If start<0 start will be set as 0.


    if (step <1) step = 1; if (start <0) start = 0;
    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if (D[y] == a) return y;
    }
    return -1;
}


int FindIn (const std::vector <long long int> &D, long long int a, int step = 1, int start = 0)
{
// Возвращает индекс первого найденного элемента (long long int), совпадающего с искомым (a), поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - возвращаем -1. Если переданное значение step <1, то step присваивается значение 1. Если переданное значение start <0, то start присваивается значение 1.
// Returns index in vector (long long int) of the first element = a. Search starts from index "start" with step = "step". If no such element found the function returns 0. If step<1 step will be set as 1. If start<0 start will be set as 0.

    if (step <1) step = 1; if (start <0) start = 0;
    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if (D[y] == a) return y;
    }
    return -1;
}


int FindIn (const std::vector <double> &D, double a, int step = 1, int start = 0)
{
// Возвращает индекс первого найденного элемента (double), совпадающего с искомым (a), поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - возвращаем -1. Если переданное значение step <1, то step присваивается значение 1. Если переданное значение start <0, то start присваивается значение 1.
// Да, прямое сравнение чисел double не совсем корректно и это нужно принимать во внимание, но в ряде случаев функция может быть полезна.
// Для сравнения с заданной точностью см. вариант функции ниже.
// Returns index in vector (double) of the first element = a. Search starts from index "start" with step = "step". If no such element found the function returns 0. If step<1 step will be set as 1. If start<0 start will be set as 0.
// Yes, operation like (a==b) may be not correct for doubles. But this function may be considered as an useful one in some cases.
//  The following version of the function finds the first element, that differs from "a" less than "d".

    if (step <1) step = 1; if (start <0) start = 0;
    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if ((D[y]-a)==0.0) return y;
    }
    return -1;
}



int FindIn (const std::vector <double> &D, double a, double d, int step = 1, int start = 0)
{
// Возвращает индекс первого найденного элемента (double), совпадающего с искомым (a) с точностью до d, поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - возвращает -1. Если переданное значение step <1, то step присваивается значение 1. Если переданное значение start <0, то start присваивается значение 1.
// Returns index in vector (double) of the first element, that differs from "a" less than nonnegative double "d".
// Search starts from index "start" with step = "step". If no such element found the function returns 0. If step<1 step will be set as 1. If start<0 start will be set as 0.

    if (step <1) step = 1; if (start <0) start = 0;
    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if ( (std::abs(D[y] - a))<d) return y;
    }
    return -1;
}


int FindIn (const std::vector <long double> &D, long double a, int step = 1, int start = 0)
{
// Возвращает индекс первого найденного элемента (long double), совпадающего с искомым (a), поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - возвращает -1. Если переданное значение step <1, то step присваивается значение 1. Если переданное значение start <0, то start присваивается значение 1.
// Да, прямое сравнение чисел long double не совсем корректно и это нужно принимать во внимание, но в ряде случаев функция может быть полезна. Для сравнения с заданной точностью см. вариант функции ниже.
// Returns index in vector (long double) of the first element = a. Search starts from index "start" with step = "step". If no such element found the function returns 0. If step<1 step will be set as 1. If start<0 start will be set as 0.
// Yes, operation like (a==b) may be not correct for doubles. But this function may be considered as an useful one in some cases. The following version of the function finds the first element, that differs from "a" less than "d".

    if (step <1) step = 1; if (start <0) start = 0;
    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if ((D[y]-a)==0.0) return y;
    }
    return -1;
}


int FindIn (const std::vector <long double> &D, long double a, long double d, int step = 1, int start = 0)
{
// Возвращает индекс первого найденного элемента (long double), совпадающего с искомым (a) с точностью до d, поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - возвращаем -1. Если переданное значение step <1, то step присваивается значение 1. Если переданное значение start <0, то start присваивается значение 1.
// Returns index in vector (long double) of the first element, that differs from "a" less than nonnegative long double "d".
// Search starts from index "start" with step = "step". If no such element found the function returns 0. If step<1 step will be set as 1. If start<0 start will be set as 0.

    if (step <1) step = 1; if (start <0) start = 0;
    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if ( (std::abs(D[y] - a))<d) return y;
    }
    return -1;
}



int FindIn (const std::vector <std::string> &D, std::string a, int step = 1, int start = 0)
{
// Возвращает индекс первого найденного элемента (string), совпадающего с искомым (a), поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - возвращаем -1. Если переданное значение step <1, то step присваивается значение 1. Если переданное значение start <0, то start присваивается значение 1.
// Returns index in vector (string) of the first element = a. Search starts from index "start" with step = "step". If no such element found the function returns 0. If step<1 step will be set as 1. If start<0 start will be set as 0.

    if (step <1) step = 1; if (start <0) start = 0;
    for (unsigned int y = start; y<D.size(); y=y+step)
    {
        if (D[y] == a) return y;
    }
    return -1;
}


int VectorCout (const std::vector <int> &P)
// Вывод вектора (int) на экран через пробелы
// "Couts" vector (int) to screen. Returns -1 if the vector is empty

{

    if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        std::cout<< P[i]<<" ";
    std::cout<< std::endl;

    return 0;
}


int VectorCout (const std::vector <unsigned int> &P)
// Вывод вектора (unsigned int) на экран через пробелы
// "Couts" vector (unsigned int) to screen. Returns -1 if the vector is empty

{

    if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        std::cout<< P[i]<<" ";
    std::cout<< std::endl;

    return 0;
}


int VectorFout (const std::vector <int> &P, std::ofstream &fout)
// Вывод вектора (int) в файл через пробелы. Возвращает -1, если вектор - пустой
// "Fouts" vector (int) to file. Returns -1 if the vector is empty
{

     if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        fout<< P[i]<<" ";
    fout<< std::endl;
    return 0;
}


int VectorCout (const std::vector <short int> &P)
// Вывод вектора (short int) на экран через пробелы
// "Couts" vector (short int) to screen. Returns -1 if the vector is empty

{

    if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        std::cout<< P[i]<<" ";
    std::cout<< std::endl;

    return 0;
}


int VectorFout (const std::vector <short int> &P, std::ofstream &fout)
// Вывод вектора (short int) в файл через пробелы. Возвращает -1, если вектор - пустой
// "Fouts" vector (short int) to file. Returns -1 if the vector is empty
{

     if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        fout<< P[i]<<" ";
    fout<< std::endl;
    return 0;
}


int VectorCout (const std::vector <unsigned short int> &P)
// Вывод вектора (unsigned short int) на экран через пробелы
// "Couts" vector (unsigned short int) to screen. Returns -1 if the vector is empty

{

    if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        std::cout<< P[i]<<" ";
    std::cout<< std::endl;

    return 0;
}


int VectorFout (const std::vector <unsigned short int> &P, std::ofstream &fout)
// Вывод вектора (unsigned short int) в файл через пробелы. Возвращает -1, если вектор - пустой
// "Fouts" vector (unsigned short int) to file. Returns -1 if the vector is empty
{

     if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        fout<< P[i]<<" ";
    fout<< std::endl;
    return 0;
}

int VectorCout (const std::vector <bool> &P)
// Вывод вектора (bool) на экран через пробелы
// "Couts" vector (bool) to screen. Returns -1 if the vector is empty

{

    if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        std::cout<< P[i]<<" ";
    std::cout<< std::endl;

    return 0;
}


int VectorFout (const std::vector <bool> &P, std::ofstream &fout)
// Вывод вектора (bool) в файл через пробелы. Возвращает -1, если вектор - пустой
// "Fouts" vector (bool) to file. Returns -1 if the vector is empty
{

     if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        fout<< P[i]<<" ";
    fout<< std::endl;
    return 0;
}

int VectorFout (const std::vector <unsigned int> &P, std::ofstream &fout)
// Вывод вектора (unsigned int) в файл через пробелы. Возвращает -1, если вектор - пустой
// "Fouts" vector (unsigned int) to file. Returns -1 if the vector is empty
{

     if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        fout<< P[i]<<" ";
    fout<< std::endl;
    return 0;
}

int VectorCout (const std::vector <long long int> &P)
// Вывод вектора (long long int) на экран через пробелы
// "Couts" vector (long long int) to screen. Returns -1 if the vector is empty

{

    if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        std::cout<< P[i]<<" ";
    std::cout<< std::endl;

    return 0;
}

int VectorFout (const std::vector <long long int> &P, std::ofstream &fout)
// Вывод вектора (long long int) в файл через пробелы. Возвращает -1, если вектор - пустой
// "Fouts" vector (long long int) to file. Returns -1 if the vector is empty
{

     if (P.size()==0) return -1;

    for (int i=0; i<P.size();i++)
        fout<< P[i]<<" ";
    fout<< std::endl;
    return 0;
}




int VectorCout (const std::vector <double> &P, unsigned int prec = 4, bool scientifique = false)
// Вывод вектора (double) на экран через пробелы. Возвращает -1, если вектор - пустой
// Вывод чисел проводится с заданной точностью prec, если bool scientifique == false. Если bool scientifique == true, вывод производится в экспоненциальной форме.
// "Couts" vector (double) to screen. Returns -1 if the vector is empty
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{
    if (P.size()==0) return -1;

    if (!scientifique)
    {

    std::cout.precision(prec);
    for (int i=0; i<P.size();i++)
        std::cout<< std::fixed<< P[i]<<" ";
    }

    if (scientifique)
    {


    for (int i=0; i<P.size();i++)
        std::cout<< std::scientific<< P[i]<<" ";

    std::cout.unsetf(std::ios::scientific);

    }


    std::cout<< std::endl;
    return 0;
}

int VectorFout (const std::vector <double> &P, std::ofstream &fout, unsigned int prec = 4, bool scientifique = false)
// Вывод вектора (double) в файл через пробелы. Возвращает -1, если вектор - пустой
// Вывод чисел проводится с заданной точностью prec, если bool scientifique == false. Если bool scientifique == true, вывод производится в экспоненциальной форме.
// "Fouts" vector (double) to file. Returns -1 if the vector is empty
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{

    if (P.size()==0) return -1;

    if (!scientifique)
    {
    fout.precision(prec);
    for (int i=0; i<P.size();i++)
        fout<< std::fixed<< P[i]<<" ";
    }

    if (scientifique)
    {


    for (int i=0; i<P.size();i++)
        fout<< std::scientific<< P[i]<<" ";

    fout.unsetf(std::ios::scientific);
    }

    fout<< std::endl;
    return 0;
}




int VectorCout (const std::vector <long double> &P, unsigned int prec = 4, bool scientifique = false)
// Вывод вектора (long double) на экран через пробелы. Возвращает -1, если вектор - пустой
// Вывод чисел проводится с заданной точностью prec, если bool scientifique == false. Если bool scientifique == true, вывод производится в экспоненциальной форме.
// "Couts" vector (long double) to screen. Returns -1 if the vector is empty
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{
    if (P.size()==0) return -1;

    if (!scientifique)
    {

    std::cout.precision(prec);
    for (int i=0; i<P.size();i++)
        std::cout<< std::fixed<< P[i]<<" ";
    }

    if (scientifique)
    {


    for (int i=0; i<P.size();i++)
        std::cout<< std::scientific<< P[i]<<" ";

    std::cout.unsetf(std::ios::scientific);
    }

    std::cout<< std::endl;
    return 0;
}

int VectorFout (const std::vector <long double> &P, std::ofstream &fout, unsigned int prec = 4, bool scientifique = false)
// Вывод вектора (long double) в файл через пробелы. Возвращает -1, если вектор - пустой
// Вывод чисел проводится с заданной точностью prec, если bool scientifique == false. Если bool scientifique == true, вывод производится в экспоненциальной форме.
// "Fouts" vector (long double) to file. Returns -1 if the vector is empty
// If bool scientifique == false, the precision will be set as prec; if bool scientifique == true, scientific notation will be applied.
{

    if (P.size()==0) return -1;

    if (!scientifique)
    {
    fout.precision(prec);
    for (int i=0; i<P.size();i++)
        fout<< std::fixed<< P[i]<<" ";
    }

    if (scientifique)
    {


    for (int i=0; i<P.size();i++)
        fout<< std::scientific<< P[i]<<" ";


    fout.unsetf(std::ios::scientific);
    }

    fout<< std::endl;
    return 0;
}




int VectorCout (const std::vector <std::string> & P)
// Вывод вектора (string) через Enter на экран. Возвращает -1, если вектор - пустой
// "Couts" vector (string) to screen. Returns -1 if the vector is empty
{
    if (P.size()==0) return -1;


    for (int i=0; i<P.size();i++)
        std::cout<< P[i]<<std::endl;
    std::cout<< std::endl;
    return 0;
}

int VectorFout (const std::vector <std::string> & P, std::ofstream &fout)
// Вывод вектора (string) через Enter в файл. Возвращает -1, если вектор - пустой
// "Fouts" vector (string) to file. Returns -1 if the vector is empty
{
    if (P.size()==0) return -1;


    for (int i=0; i<P.size();i++)
        fout<< P[i]<<std::endl;
    fout<< std::endl;
    return 0;
}




int PairVectorCout (const std::pair < std::vector<int>, std::vector<double>> & P, unsigned int prec = 4, bool scientifique = false)
// Модификация функции VectorCout (см. выше).
// Modification of the function VectorCout (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.


{

    if ((P.first).size()==0) return -1;
    if ((P.second).size()==0) return -1;
    if (  (P.first).size()!=((P.second).size())*2 ) return -1;

    if (!scientifique)
    {
    std::cout.precision(prec);

    for (int i=0; i<(P.second).size();i++)
    {
        std::cout<< (P.first)[2*i]<<" ";
        std::cout<< (P.first)[2*i+1]<<" ";
        std::cout<< std::fixed<<(P.second)[i]<<" ";

    }
    std::cout<< std::endl;

    }

    if (scientifique)
        {

                for (int i=0; i<(P.second).size();i++)
                {
                    std::cout<< (P.first)[2*i]<<" ";
                    std::cout<< (P.first)[2*i+1]<<" ";
                    std::cout<< std::scientific<<(P.second)[i]<<" ";
                    std::cout.unsetf(std::ios::scientific);

                }


                std::cout<< std::endl;


        }



    return 0;
}

int PairVectorFout (const std::pair < std::vector<int>, std::vector<double>> & P, std::ofstream &fout, unsigned int prec = 4, bool scientifique = false)
// Модификация функции VectorFout (см. выше).
// Modification of the function VectorFout (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.

{

    if ((P.first).size()==0) return -1;
    if ((P.second).size()==0) return -1;
    if (  (P.first).size()!=((P.second).size())*2 ) return -1;

    if (!scientifique)
    {
    fout.precision(prec);

    for (int i=0; i<(P.second).size();i++)
    {
        fout<< (P.first)[2*i]<<" ";
        fout<< (P.first)[2*i+1]<<" ";
        fout<< std::fixed<<(P.second)[i]<<" ";

    }
    fout<< std::endl;

    }

    if (scientifique)
        {

                for (int i=0; i<(P.second).size();i++)
                {
                    fout<< (P.first)[2*i]<<" ";
                    fout<< (P.first)[2*i+1]<<" ";
                    fout<< std::scientific<<(P.second)[i]<<" ";
                    fout.unsetf(std::ios::scientific);

                }


                fout<< std::endl;


        }



    return 0;
}




int GraphCout (const std::vector <int> &P, const bool weighted)
// Вывод графа, заданного вектором смежности, на экран: каждое ребро выводится в новой строке. Граф - невзвешенный, либо веса ребер целочисленны.
// "Couts" a graph that is set by Adjacency vector A to screen: one edge in one line. Parameter "weighted" sets if the graph A is weighted or no.
// Returns -1 if input data is not correct. Otherwise returns 0.

{

    if (P.size()==0) return -1; // checking for input data correctness
    if ( (P.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

    for (int i=0; i<P.size();i=i+2+weighted)
    {
        std::cout<< P[i]<<' '<<P[i+1];
        if (weighted) std::cout<<' '<<P[i+2];
        std::cout<<std::endl;
    }
    std::cout<< std::endl;

    return 0;
}


int GraphFout (const std::vector <int> &P, const bool weighted, std::ofstream &fout)
// Вывод графа, заданного вектором смежности, в файл: каждое ребро выводится в новой строке. Граф - невзвешенный, либо веса ребер целочисленны.
// "Fouts" a graph that is set by Adjacency vector A to file: one edge in one line. Parameter "weighted" sets if the graph A is weighted or no.
// Returns -1 if input data is not correct. Otherwise returns 0.

{

    if ( (P.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

    if (P.size()==0) return -1;  // checking for input data correctness

    for (int i=0; i<P.size();i=i+2+weighted)
    {
        fout<< P[i]<<' '<<P[i+1];
        if (weighted) fout<<' '<<P[i+2];
        fout<< std::endl;
    }
    fout<< std::endl;

    return 0;
}



int GraphCout (const std::pair < std::vector<int>, std::vector<double>> & P, unsigned int prec = 4, bool scientifique = false)
// Модификация функции GraphCout (см. выше) для взвешенных графов с нецелочисленными весами ребер.
// Modification of the function GraphCout (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.


{

    if ((P.first).size()==0) return -1;
    if ((P.second).size()==0) return -1;
    if (  (P.first).size()!=((P.second).size())*2 ) return -1;

    if (!scientifique)
    {
    std::cout.precision(prec);

    for (int i=0; i<(P.second).size();i++)
    {
        std::cout<< (P.first)[2*i]<<" ";
        std::cout<< (P.first)[2*i+1]<<" ";
        std::cout<< std::fixed<<(P.second)[i]<<" ";
        std::cout<< std::endl;
    }
    std::cout<< std::endl;

    }

    if (scientifique)
        {

                for (int i=0; i<(P.second).size();i++)
                {
                    std::cout<< (P.first)[2*i]<<" ";
                    std::cout<< (P.first)[2*i+1]<<" ";
                    std::cout<< std::scientific<<(P.second)[i]<<" ";
                    std::cout.unsetf(std::ios::scientific);
                    std::cout<< std::endl;
                }


                std::cout<< std::endl;


        }



    return 0;
}


int GraphFout (const std::pair < std::vector<int>, std::vector<double>> & P, std::ofstream &fout, unsigned int prec = 4, bool scientifique = false)
// Модификация функции GraphFout (см. выше) для взвешенных графов с нецелочисленными весами ребер.
// Modification of the function GraphFout (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.


{

    if ((P.first).size()==0) return -1;
    if ((P.second).size()==0) return -1;
    if (  (P.first).size()!=((P.second).size())*2 ) return -1;

    if (!scientifique)
    {
    fout.precision(prec);

    for (int i=0; i<(P.second).size();i++)
    {
        fout<< (P.first)[2*i]<<" ";
        fout<< (P.first)[2*i+1]<<" ";
        fout<< std::fixed<<(P.second)[i]<<" ";
        fout<< std::endl;
    }
    fout<< std::endl;

    }

    if (scientifique)
        {

                for (int i=0; i<(P.second).size();i++)
                {
                    fout<< (P.first)[2*i]<<" ";
                    fout<< (P.first)[2*i+1]<<" ";
                    fout<< std::scientific<<(P.second)[i]<<" ";
                    fout.unsetf(std::ios::scientific);
                    fout<< std::endl;
                }


                fout<< std::endl;


        }



    return 0;
}



int GraphCout (const std::map <std::pair < int, int> , int> &P)
// Вывод графа, заданного ассоциативным массивом смежности, на экран: каждое ребро выводится в новой строке. Веса ребер целочисленны.
// "Couts" a graph that is set by Adjacency map P to screen: one edge in one line.
// Returns -1 if input data is not correct. Otherwise returns 0.

{

    if (P.size()==0) return -1;
    for (auto it =P.begin(); it!=P.end(); it++)
    {
        std::cout<<(it->first).first<< " "<<(it->first).second<<" "<< it->second<< std::endl;

    }


    std::cout<< std::endl;

    return 0;
}

int GraphFout (const std::map <std::pair < int, int> , int> &P, std::ofstream &fout)
// Вывод графа, заданного ассоциативным массивом смежности, в файл: каждое ребро выводится в новой строке. Веса ребер целочисленны.
// "Couts" a graph that is set by Adjacency map P to file: one edge in one line.
// Returns -1 if input data is not correct. Otherwise returns 0.

{
    if (P.size()==0) return -1;
    for (auto it =P.begin(); it!=P.end(); it++)
    {
        fout<<(it->first).first<< " "<<(it->first).second<<" "<< it->second<< std::endl;

    }

    fout<< std::endl;

    return 0;
}




int GraphCout (const std::map <std::pair < int, int> , double> &P, unsigned int prec = 4, bool scientifique = false)
// Модификация функции GraphCout для заданного ассоциативным массивом смежности графа (см. выше) для случая нецелочисленных весов ребер.
// Modification of the function GraphCout for Adjacency map (see it above) for not-integer (double) weights of edges.


{

if (P.size()==0) return -1;

    if (!scientifique)
    {
    std::cout.precision(prec);

    for (auto it =P.begin(); it!=P.end(); it++)
    {
        std::cout<<(it->first).first<< " "<<(it->first).second<<" ";
        std::cout<< std::fixed<<it->second;
        std::cout<< std::endl;
    }
    std::cout<< std::endl;

    }

    if (scientifique)
        {

                for (auto it =P.begin(); it!=P.end(); it++)
                {
                    std::cout<<(it->first).first<< " "<<(it->first).second<<" ";
                    std::cout<< std::scientific<<it->second;
                    std::cout.unsetf(std::ios::scientific);
                    std::cout<< std::endl;
                }
                std::cout<< std::endl;
        }

    return 0;
}


int GraphFout (const std::map <std::pair < int, int> , double> &P, std::ofstream &fout, unsigned int prec = 4, bool scientifique = false)
// Модификация функции GraphFout для заданного ассоциативным массивом смежности графа (см. выше) для случая нецелочисленных весов ребер.
// Modification of the function GraphFout for Adjacency map (see it above) for not-integer (double) weights of edges.


{

if (P.size()==0) return -1;

    if (!scientifique)
    {
    fout.precision(prec);

    for (auto it =P.begin(); it!=P.end(); it++)
    {
        fout<<(it->first).first<< " "<<(it->first).second<<" ";
        fout<< std::fixed<<it->second;
        fout<< std::endl;
    }
    fout<< std::endl;

    }

    if (scientifique)
        {

                for (auto it =P.begin(); it!=P.end(); it++)
                {
                    fout<<(it->first).first<< " "<<(it->first).second<<" ";
                    fout<< std::scientific<<it->second;
                    fout.unsetf(std::ios::scientific);
                    fout<< std::endl;
                }
                fout<< std::endl;
        }

    return 0;
}




int GraphCout (const std::map <std::pair < int, int> , std::vector<int> > &P, bool in_line=false)
// Вывод графа, заданного "мега-мапом", на экран: каждое ребро выводится в новой строке. Веса ребер целочисленны.
// Параметр in_line задает, выводить ли все значения вектора-значения в 1 строку после ключа, или же каждое значение вектора выводится после ключа в новой строке.
// Мега-мап представляет собой ассоциативный массив смежности, предназначенный для хранения графов с множественными петлями и множественными ребрами.
// При этом ключом является пара чисел, задающих вершины ребер графа между ними, а значением - вектор весов для всех ребер между этими вершинами.
// "Couts" a graph that is set by Adjacency mega-map P to screen: one edge in one line.
// Adjacency mega-map is an extended version of Adjacency map (and it is built basing on std::map too) for containing graphs that have multiply loops and multiply edges.
// In doing so, the key value of the map is a pair of integers that sets edge(s) between them and the mapped value is a vector that contains weights of all edges between these vertices.
// Returns -1 if input data is not correct. Otherwise returns 0.

{

    if (P.size()==0) return -1;
    for (auto it =P.begin(); it!=P.end(); it++)
        if ((it->second).size()==0) return -1;


    for (auto it =P.begin(); it!=P.end(); it++)
    {
        if (!in_line)
            for (int j=0; j<(it->second).size(); j++)
            {
                std::cout<<(it->first).first<< " "<<(it->first).second<<" "<< it->second[j]<< std::endl;

            }
        if (in_line)

            {
                std::cout<<(it->first).first<< " "<<(it->first).second<<" ";
                for (int j=0; j<(it->second).size(); j++)
                     std::cout<< it->second[j]<<" ";
                std::cout<< std::endl;

            }
    }

    std::cout<< std::endl;

    return 0;
}

int GraphFout (const std::map <std::pair < int, int> , std::vector<int> > &P, std::ofstream &fout, bool in_line=false)
// Вывод графа, заданного "мега-мапом", в файл: каждое ребро выводится в новой строке. Веса ребер целочисленны.
// Параметр in_line задает, выводить ли все значения вектора-значения в 1 строку после ключа, или же каждое значение из вектора выводится после ключа в новой строке.
// Мега-мап представляет собой ассоциативный массив смежности, предназначенный для хранения графов с множественными петлями и множественными ребрами.
// При этом ключом является пара чисел, задающих вершины ребер графа между ними, а значением - вектор весов для всех ребер между этими вершинами.
// "Fouts" a graph that is set by Adjacency mega-map P to file: one edge in one line.
// Adjacency mega-map is an extended version of Adjacency map (and it is built basing on std::map too) for containing graphs that have multiply loops and multiply edges.
// In doing so, the key value of the map is a pair of integers that sets edge(s) between them and the mapped value is a vector that contains weights of all edges between these vertices.
// Returns -1 if input data is not correct. Otherwise returns 0.

{
    if (P.size()==0) return -1;
    for (auto it =P.begin(); it!=P.end(); it++)
        if ((it->second).size()==0) return -1;

    for (auto it =P.begin(); it!=P.end(); it++)
    {
        if (!in_line)
            for (int j=0; j<(it->second).size(); j++)
            {
                fout<<(it->first).first<< " "<<(it->first).second<<" "<< it->second[j]<< std::endl;

            }
        if (in_line)

            {
                fout<<(it->first).first<< " "<<(it->first).second<<" ";
                for (int j=0; j<(it->second).size(); j++)
                     fout<< it->second[j]<<" ";
                fout<< std::endl;

            }
    }

    fout<< std::endl;

    return 0;
}




int GraphCout (const std::map <std::pair < int, int> , std::vector<double> > &P, bool in_line=false, unsigned int prec = 4, bool scientifique = false)
// Модификация функции GraphCout для заданного "мега-мапом" (см. выше) для случая нецелочисленных весов ребер.
// Modification of the function GraphCout for mega-map (see it above) for not-integer (double) weights of edges.


{

if (P.size()==0) return -1;

for (auto it =P.begin(); it!=P.end(); it++)
    if ((it->second).size()==0) return -1;

if (!in_line)
{

    if (!scientifique)
    {
    std::cout.precision(prec);

    for (auto it =P.begin(); it!=P.end(); it++)
        for (int j=0; j<(it->second).size(); j++)
    {
        std::cout<<(it->first).first<< " "<<(it->first).second<<" ";
        std::cout<< std::fixed<<it->second[j];
        std::cout<< std::endl;
    }
    std::cout<< std::endl;

    }

    if (scientifique)
        {

                for (auto it =P.begin(); it!=P.end(); it++)
                    for (int j=0; j<(it->second).size(); j++)
                {
                    std::cout<<(it->first).first<< " "<<(it->first).second<<" ";
                    std::cout<< std::scientific<<it->second[j];
                    std::cout.unsetf(std::ios::scientific);
                    std::cout<< std::endl;
                }
                std::cout<< std::endl;
        }
}


if (in_line)
{

    if (!scientifique)
    {
    std::cout.precision(prec);

    for (auto it =P.begin(); it!=P.end(); it++)

    {
        std::cout<<(it->first).first<< " "<<(it->first).second<<" ";
        for (int j=0; j<(it->second).size(); j++)
            std::cout<< std::fixed<<it->second[j]<< " ";
        std::cout<< std::endl;
    }
    std::cout<< std::endl;

    }

    if (scientifique)
        {

                for (auto it =P.begin(); it!=P.end(); it++)

                {
                    std::cout<<(it->first).first<< " "<<(it->first).second<<" ";
                    for (int j=0; j<(it->second).size(); j++)
                        std::cout<< std::scientific<<it->second[j]<< " ";
                    std::cout.unsetf(std::ios::scientific);
                    std::cout<< std::endl;
                }
                std::cout<< std::endl;
        }
}

    return 0;
}


int GraphFout (const std::map <std::pair < int, int> , std::vector <double> > &P, std::ofstream &fout, bool in_line=false, unsigned int prec = 4, bool scientifique = false)
// Модификация функции GraphFout для заданного "мега-мапом" (см. выше) для случая нецелочисленных весов ребер.
// Modification of the function GraphFout for mega-map (see it above) for not-integer (double) weights of edges.


{

if (P.size()==0) return -1;

for (auto it =P.begin(); it!=P.end(); it++)
    if ((it->second).size()==0) return -1;

if (!in_line)
{

    if (!scientifique)
    {
    fout.precision(prec);

    for (auto it =P.begin(); it!=P.end(); it++)
        for (int j=0; j<(it->second).size(); j++)
    {
        fout<<(it->first).first<< " "<<(it->first).second<<" ";
        fout<< std::fixed<<it->second[j];
        fout<< std::endl;
    }
    fout<< std::endl;

    }

    if (scientifique)
        {

                for (auto it =P.begin(); it!=P.end(); it++)
                    for (int j=0; j<(it->second).size(); j++)
                {
                    fout<<(it->first).first<< " "<<(it->first).second<<" ";
                    fout<< std::scientific<<it->second[j];
                    fout.unsetf(std::ios::scientific);
                    fout<< std::endl;
                }
                fout<< std::endl;
        }
}


if (in_line)
{

    if (!scientifique)
    {
    fout.precision(prec);

    for (auto it =P.begin(); it!=P.end(); it++)

    {
        fout<<(it->first).first<< " "<<(it->first).second<<" ";
        for (int j=0; j<(it->second).size(); j++)
            fout<< std::fixed<<it->second[j]<< " ";
        fout<< std::endl;
    }
    fout<< std::endl;

    }

    if (scientifique)
        {

                for (auto it =P.begin(); it!=P.end(); it++)

                {
                    fout<<(it->first).first<< " "<<(it->first).second<<" ";
                    for (int j=0; j<(it->second).size(); j++)
                        fout<< std::scientific<<it->second[j]<< " ";
                    fout.unsetf(std::ios::scientific);
                    fout<< std::endl;
                }
                fout<< std::endl;
        }
}
return 0;
}


struct PairIntHash  // for unordered_set and unordered_map
{
    std::size_t operator()(const std::pair<int, int>& obj) const
    {
        std::hash<int> hasher;


        return hasher(obj.first) ^ hasher(obj.second);
    }
};


template < typename TSW>
int SwapInVector (std::vector <TSW> & A1, unsigned int f, unsigned int l)
{
    // swaps 2 elements in vector. Returns -1 if some index out of vector's range or vector is empty
    // Замена элементов в векторе, возвращает -1 если хоть один из запрашиваемых индексов выходит за размер вектора либо если вектор пустой


    if ((A1.size()==0) || (f>=A1.size()) || (l>=A1.size())) return -1;

    TSW t = A1[f];
    A1[f] = A1[l];
    A1[l] = t;
    return 0;

}



int GraphVerticesNumbersCompress (std::vector <int> & P, const bool weighted)
// Renumbering of vertices of the graph P (set by Adjacency vector P) to make the sequence of numbers of vertices as a row of not-negative integers with no blanks.
// Перенумеровывает вершина графа, заданного вектором смежности P, таким образом, чтобы все номера вершин составляли ряд неотрицательных целых чисел без пропусков.
// Параметр weighted задает, является ли граф взвешенным.

{
    if (P.size()==0) return -1; // checking for input data correctness
    if ( (P.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

    std::set<int> Numbers;
    Numbers.clear();
    for (int i=0; i<P.size();i=i+2+weighted)
    {
        Numbers.insert(P[i]);
        Numbers.insert(P[i+1]);
    }

    std::unordered_map <int, int> V; V.clear();
    int q=0;
    for (auto i=Numbers.begin(); i!=Numbers.end();i++)
    {
        V.insert(std::pair<int, int>(*i, q));
        q++;
    }


    for (int i=0; i<P.size();i=i+2+weighted)
    {
        P[i] = V[P[i]];
        P[i+1] = V[P[i+1]];
    }

    return 0;

}



int HmDist (const std::string &s1, const std::string &s2)
{
    // Counts Hamming Distance; returns -1 if any string is empty or they have different length.
    // Считает Hamming Distance, возвращает -1 если строки разной длины либо хоть одна пустая.

    if ((s1.length()==0) || (s2.length()==0) || (s1.length()!=s2.length())) return -1;
    int q = 0;
    for (unsigned int i=0; i<s1.length(); i++)
    {if (s1[i] != s2[i]) q++;}
    return q;
}

int RComplDNA (const std::string& s, std::string & sr)
{
    // generates reverse complement of string s as string sr, returns -1 and empty string sr if string s is empty or it is not DNA

     sr = s;

     if (s.length()==0) return -1;

     for (unsigned int i = 0; i<s.length(); i++)
     {
      if (s [s.length()-i-1] == 'A') {sr [i]  = 'T'; continue;}
      if (s [s.length()-i-1] == 'T') {sr [i]  = 'A'; continue;}
      if (s [s.length()-i-1] == 'G') {sr [i]  = 'C'; continue;}
      if (s [s.length()-i-1] == 'C') {sr [i]  = 'G'; continue;}

      sr.clear();
      return -1;
     }

    return 0;
}


int RComplRNA (const std::string& s, std::string & sr)
{
    // generates reverse complement of string s as string sr, returns -1 and empty string sr if string s is empty or it is not RNA

     sr = s;

     if (s.length()==0) return -1;

     for (unsigned int i = 0; i<s.length(); i++)
     {
      if (s [s.length()-i-1] == 'A') {sr [i]  = 'U'; continue;}
      if (s [s.length()-i-1] == 'U') {sr [i]  = 'A'; continue;}
      if (s [s.length()-i-1] == 'G') {sr [i]  = 'C'; continue;}
      if (s [s.length()-i-1] == 'C') {sr [i]  = 'G'; continue;}

      sr.clear();
      return -1;
     }

    return 0;
}


std::string rp (const std::string& s)
{
    // generates reverse complement of DNA without any checking of input data correctness

     std::string sr = s;
     for (unsigned int i = 0; i<s.length(); i++)
     {
      if (s [s.length()-i-1] == 'A') sr [i]  = 'T';
      if (s [s.length()-i-1] == 'T') sr [i]  = 'A';
      if (s [s.length()-i-1] == 'G') sr [i]  = 'C';
      if (s [s.length()-i-1] == 'C') sr [i]  = 'G';
     }
    return sr;
}


std::string rpr (const std::string& s)
{
    // generates reverse complement of RNA without any checking of input data correctness

     std::string sr = s;
     for (unsigned int i = 0; i<s.length(); i++)
     {
      if (s [s.length()-i-1] == 'A') sr [i]  = 'U';
      if (s [s.length()-i-1] == 'U') sr [i]  = 'A';
      if (s [s.length()-i-1] == 'G') sr [i]  = 'C';
      if (s [s.length()-i-1] == 'C') sr [i]  = 'G';
     }
    return sr;
}



double gcDRNA (const std::string &s)
{

    // Counts DNA/RNA GC-content; in case any symbol not DNA/RNA-nucleotide or string s is empty returns -1.0.

    if (s.length()==0) return -1.0;

    int count = 0;

    for (int i = 0; i< s.length(); i++)
    {
        if ((s[i]=='G') || (s[i]=='C')) {count++; continue;}
        if ((s[i]=='A') || (s[i]=='T') || (s[i]=='U')) {continue;}
        return -1.0;
    }


    return 1.0*count/s.length();
}


int RNAfromDNA (const std::string &s, std::string & sr)
{
     // generates RNA from DNA, returns -1 and empty string sr if the input string s is empty or it is not DNA

    if (s.length()==0) {sr.clear(); return -1;}
    sr = s;
    for (int i = 0; i<s.length(); i++)
    {
        if (sr [i] == 'T') {sr [i]  = 'U'; continue;}
        if (sr [i] == 'A') {continue;}
        if (sr [i] == 'G') {continue;}
        if (sr [i] == 'C') {continue;}

        sr.clear();
        return -1;
    }

return 0;

}


int DNAfromRNA (const std::string &s, std::string & sr)
{
     // generates DNA from RNA, returns -1 and empty string sr if the input string s is empty or it is not RNA

    if (s.length()==0) {sr.clear(); return -1;}
    sr = s;
    for (int i = 0; i<s.length(); i++)
    {
        if (sr [i] == 'U') {sr [i]  = 'T'; continue;}
        if (sr [i] == 'A') {continue;}
        if (sr [i] == 'G') {continue;}
        if (sr [i] == 'C') {continue;}

        sr.clear();
        return -1;
    }

return 0;

}


std::string RNAg (const std::string &s)
{
// generates RNA from DNA without checking of data correctness

    std::string sr = s;
    for (int i = 0; i<s.length(); i++)
        {
        sr [i]= s [i];
        if (sr [i] == 'T') sr [i]  = 'U';
    }

return sr;
}


std::string DNAg (const std::string &s)
{
// generates DNA from RNA without checking of data correctness

    std::string sr = s;
    for (int i = 0; i<s.length(); i++)
        {
        sr [i]= s [i];
        if (sr [i] == 'U') sr [i]  = 'T';
    }

return sr;
}



std::string StrToCircular (const std::string& s, int tail = INT_MAX)
// Находит и возвращает кратчайшую "круговую" ("скрученную в кольцо") строку для заданной (т.е. с максимальным "нахлестом" конца строки на начало).
// Для строк длиной менее 3 символов возвращает ее же (считается, что в этом случае "нахлест" невозможен.
// Возможно задать параметр tail - величнину максимального "нахлеста". Значения tail<=0 в расчет не принимаются.

//  Returns a circular string of minimal length of a string s; if length of s <3 returns s itself.
//  One may set "tail" i.e. maximal overlap "tail-to-beginning" of the string s (nonpositive values of "tail" will be ignored).


{
    if (s.length()<3) return s;
    if (tail<=0) tail = INT_MAX;

    int N = s.length()/2;
    if (tail<s.length()/2) N=tail;

    std::string sr = s;
    for (int i = N; i>0; i--)
        if (s.substr(0, i) == s.substr(s.length() - i, i))
        {
            sr = s.substr(0, s.length() - i);
            break;
        }

    return sr;
}



int TandemRepeatsFinding (const std::string &s, std::vector <int> &Result, int MaxWordLength = 4, int limit = 5)

// Функция находит все тандемные повторы в строке s, сформированные j-мерами длинной от 1 по MaxWordLength символов и имеющие длину не менее limit
// MaxWordLength должно быть в границах от 2 по 6. limit должен быть больше MaxWordLength (иначе limit будет присвоено значение MaxWordLength+1).
// Результат возвращается в векторе Result, где на четных позициях, отсчитываемых с нуля - позиции начала тандемного повтора в s (символы в s также нумеруются с нуля), а на нечетных - длина повтора
// Возвращает 0 в случае успеха. В случае некорректных данных (длина s < MaxWordLength, MaxWordLength не в диапазоне [2; 6]) возвращает пустой Result и -1.

// Finds all tandem repeats in the string s as follows:
// the repeat has its lenght >= limits, the repeat should be formed by j-mers: j in [1; MaxWordLength], MaxWordLength in [2; 6]
// limit should be more than MaxWordLength (if no the limit's value will be set as MaxWordLength+1)
// Returns 0 and vector Result: every even position of Result contains the starting position of tandem repeat in the s (0-based indexing)
// and every odd position of Result contain the lenghts of the repeat that have its starting position as previous element in the Result.
// Returns -1 and empty Result if input data is incorrect.


{
    Result.clear();
    if (limit <= MaxWordLength ) limit = MaxWordLength+1;
    if ((MaxWordLength <2) || (MaxWordLength >6) ) return -1;
    if (s.length()<MaxWordLength) return -1;


    std::string Alph = "ACGT";
    int WordLenght;
    int AlphLenght = Alph.length();

    std::string SA = "A";
    std::string SC = "C";
    std::string SG = "G";
    std::string ST = "T";

    for (int q=0; q<MaxWordLength; q++)
    {
        SA = SA + "A";
        SC = SC + "C";
        ST = ST + "T";
        SG = SG + "G";
    }

    std::string TempS;

    char out [10];   // an auxiliary array to make j-mers

    std::vector <int> l; // an auxiliary array to form j-mers (to do so let's do 4-digit numbers: one digit corresponds to one and only one symbol from the string Alph)

    std::vector <int> P; // an auxiliary array to contain starting positions of j-mers in the string s
    int y, t;
    int f=-1;
    int count;
    int b, e;




    // First of all lets see all j-mers: j in [2; MaxWordLength], but except those are formed by only one and the same symbol (i.e. except those like "AAAA", "TTT", etc)

    for (int j=MaxWordLength; j>1; j--)  // let's generate j-mers: j in [2; MaxWordLength]
    {

        SA.pop_back(); // j-mers that are formed
        SC.pop_back();  // by only one repeating symbol
        SG.pop_back();  // (i.e. j-mers like "AAAA", "CC", "TTT, etc)
        ST.pop_back(); // will be ignored here.


        WordLenght = j;
        long long int nn = (long long int) (pow (double(AlphLenght), WordLenght)); //nn - total number of j-mers

        l.clear();
        l.resize(j, 0);

        for (int g=0; g<WordLenght; g++)
        {

            out [g] = Alph [0];  // setting starting j-mer

        }


        for (long long int ii=0; ii<nn; ii++)
        {
             TempS = "";


            for (int u=0; u< WordLenght; u++)
            {

                TempS= TempS + out [u]; //forming the next j-mer
            }

            // we have TempS as j-mer now


            if ((TempS==SA) || (TempS==SC) || (TempS==SG) || (TempS==ST) ) goto label1;  // if j-mer is formed by only one repeating symbol - it is not for working with it here

            P.clear();
            y=s.find(TempS, 0);
            while (y!=-1) // We' ll write to P every starting positions of the j-mer as a substring of the string s
            {
                P.push_back(y);
                y = s.find(TempS, y+1);

            }


            count = WordLenght; //count will contain the lenght of tandem repeat
            for (int q=1; q<P.size(); q++)
            {
                if (P[q]-P[q-1]==WordLenght)  //if so - the tandem repeat continues
                {
                    count = count + WordLenght;
                    t=P[q];
                    continue;
                }

                if (count>= limit) // if the tandem repeat has its lenght >= limit (as limits is the minimal lenght of repeats to be found)
                {
                    b = t+WordLenght-count; //the starting position in the string s of the repeat
                    e = count; // and its lenght

                    // cheking if the repeat is contained in any already found or it contains any of them itself
                    f=1;
                    for (int w=0; w<Result.size(); w=w+2)
                    {
                        if ( (Result[w]<=b)&& ((Result[w]+Result[w+1])>=(e+b))  )
                        {f=-1; break;} // it is contained in some one found before

                        if ( (Result[w]>=b)&& ((Result[w]+Result[w+1])<=(e+b))  ) // in this case we eliminate the one contained in the new found repeat
                        {Result.erase(Result.begin()+w); Result.erase(Result.begin()+w);}

                    }

                    if (f==1)
                    {
                    Result.push_back(t+WordLenght-count); // writing to P the starting pos
                    Result.push_back(count); // and the lenght of the new repeat found
                    }



                }

                count = WordLenght;
            }

            if (count>= limit) // another iteration for the last repeat in the s
            {
                b = t+WordLenght-count;
                e = count;
                f=1;
                for (int w=0; w<Result.size(); w=w+2)
                {
                    if ( (Result[w]<=b)&& ((Result[w]+Result[w+1])>=(e+b))  )
                    {f=-1; break;}

                    if ( (Result[w]>=b)&& ((Result[w]+Result[w+1])<=(e+b))  )
                    {Result.erase(Result.begin()+w); Result.erase(Result.begin()+w);}

                }



                if (f==1)
                {
                Result.push_back(t+WordLenght-count);
                Result.push_back(count);
                }
            }




    label1: ;
        l [WordLenght-1]++;  //увеличение на 1 кода последней буквы // the digit that corresponds to the last symbol of j-mer is to be increased

        if (l [WordLenght-1] == AlphLenght) // if so - we must recalculate the senior digits too
         {
           int r = WordLenght-1;

           while (r>0)
             {l [r] = 0;
              r--;
              l [r] ++;
              if (l[r] < AlphLenght) break;
             }
         }

        for (int t = 0; t<WordLenght; t++)
              out [t] = Alph [(l[t])];


        }

    }  // End of observing all j-mers: j in [2; MaxWordLength], but except those are formed by only one and the same symbol (i.e. except those like "AAAA", "TTT", etc)


    // Now lets find substrings formed by only one repeating symbol and that have their lenght not less than "limits"
    // The algorithm is like above, but we are looking for substrings formed by by only one repeating symbol.
    //In doing so we count their lenght in the "count" and if (count>= limit) - we have found another one repeat


    count =1;

    for (int q=1; q<s.length(); q++)
    {

        if (s[q]==s[q-1])
        {
            count++;
            t=q;
            continue;
        }

        if (count>= limit)
        {
            Result.push_back(t+1-count);
            Result.push_back(count);
        }

    count=1;
    }

    if (count>= limit)
    {
        Result.push_back(t+WordLenght-count);
        Result.push_back(count);
    }

    return 0;
}




void GMapCodonRNA (std::map <std::string, std::string> & MapCodon)
{
    //Generates codon table for RNA in the map MapCodon ("$" means stop codon).
    // MapCodon format: Codon -> Amino acid.


    MapCodon.clear();

    MapCodon =
    {
        {"UUU", "F"},
        {"CUU", "L"},
        {"AUU", "I"},
        {"GUU", "V"},
        {"UUC", "F"},
        {"CUC", "L"},
        {"AUC", "I"},
        {"GUC", "V"},
        {"UUA", "L"},
        {"CUA", "L"},
        {"AUA", "I"},
        {"GUA", "V"},
        {"UUG", "L"},
        {"CUG", "L"},
        {"AUG", "M"},
        {"GUG", "V"},
        {"UCU", "S"},
        {"CCU", "P"},
        {"ACU", "T"},
        {"GCU", "A"},
        {"UCC", "S"},
        {"CCC", "P"},
        {"ACC", "T"},
        {"GCC", "A"},
        {"UCA", "S"},
        {"CCA", "P"},
        {"ACA", "T"},
        {"GCA", "A"},
        {"UCG", "S"},
        {"CCG", "P"},
        {"ACG", "T"},
        {"GCG", "A"},
        {"UAU", "Y"},
        {"CAU", "H"},
        {"AAU", "N"},
        {"GAU", "D"},
        {"UAC", "Y"},
        {"CAC", "H"},
        {"AAC", "N"},
        {"GAC", "D"},
        {"UAA", "$"},
        {"CAA", "Q"},
        {"AAA", "K"},
        {"GAA", "E"},
        {"UAG", "$"},
        {"CAG", "Q"},
        {"AAG", "K"},
        {"GAG", "E"},
        {"UGU", "C"},
        {"CGU", "R"},
        {"AGU", "S"},
        {"GGU", "G"},
        {"UGC", "C"},
        {"CGC", "R"},
        {"AGC", "S"},
        {"GGC", "G"},
        {"UGA", "$"},
        {"CGA", "R"},
        {"AGA", "R"},
        {"GGA", "G"},
        {"UGG", "W"},
        {"CGG", "R"},
        {"AGG", "R"},
        {"GGG", "G"}
    };

}


void GMapCodonRNA_A (std::map <std::string, std::vector<std::string>> & MapCodon)
//Generates codon table for RNA in the map MapCodon ("$" means stop codon).
// MapCodon format: Amino acid -> vector of relevant codons.
{

    MapCodon.clear();

    MapCodon =
        {
            {"F", {"UUU", "UUC"}},
            {"L", {"CUU", "CUC", "CUA", "CUG", "UUG", "UUA"}},
            {"I", {"AUU", "AUC", "AUA"}},
            {"V", {"GUU", "GUC", "GUA", "GUG"}},
            {"M", {"AUG"}},
            {"S", {"UCU", "UCC", "UCA", "UCG", "AGU", "AGC"}},
            {"P", {"CCU", "CCC", "CCA", "CCG"}},
            {"T", {"ACU", "ACC", "ACA", "ACG"}},
            {"A", {"GCU", "GCC", "GCA", "GCG"}},
            {"Y", {"UAU", "UAC"}},
            {"H", {"CAU", "CAC"}},
            {"N", {"AAU", "AAC"}},
            {"D", {"GAU", "GAC"}},
            {"$", {"UAA", "UAG", "UGA"}},
            {"Q", {"CAA", "CAG"}},
            {"K", {"AAA", "AAG"}},
            {"E", {"GAA", "GAG"}},
            {"C", {"UGU", "UGC"}},
            {"R", {"CGU", "CGC", "CGA", "AGA", "CGG", "AGG"}},
            {"G", {"GGU", "GGC", "GGA", "GGG"}},
            {"W", {"UGG"}},
         };


}


void GMapMonoisotopicMassTableLD (std::map <char, long double> & MassTable)
{
    //Generates Monoisotopic mass table in the map (long double)

    MassTable.clear();


MassTable =
  {
    {'A', 71.03711},
    {'C', 103.00919},
    {'D', 115.02694},
    {'E', 129.04259},
    {'F', 147.06841},
    {'G', 57.02146},
    {'H', 137.05891},
    {'I', 113.08406},
    {'K', 128.09496},
    {'L', 113.08406},
    {'M', 131.04049},
    {'N', 114.04293},
    {'P', 97.05276},
    {'Q', 128.05858},
    {'R', 156.10111},
    {'S', 87.03203},
    {'T', 101.04768},
    {'V', 99.06841},
    {'W', 186.07931},
    {'Y', 163.06333}

  };
}



int GPFM (std::vector <std::string> &s, std::vector <std::vector <int>> & B, const std::string &Alph)
{

    // Генерирует позиционную матрицу частот B по набору исходных строк s и алфавиту Alph (содержит последовательность символов алфавита);
    // Последовательность строк в матрице B соответствует последовательности символов в строке Alph (т.е. последовательности символов алфавита).
    // в случае если в наборе менее 2х строк или они имеют неодинаковую длину или в алфавите менее 2 букв или хоть одна из строк содержит хоть один символ не из алфавита,
    // или же если алфавит содержит дублирующиеся символы - возвращается -1  и пустая матрица B (в случае успеха возвращается 0).

    // Generates position frequency matrix (PFM) B upon an array of strings s and given Alphabet (Alphabet is set via string Alph that contains the sequence of its symbols);
    // Ordering of the rows in B corresponds to sequence of symbols in Alph.
    // If s contains 1 or 0 items or strings have not equal length or even the only string contains symbol that not belongs to Alphabet
    // or if there are any identical symbols in the Alphabet - returns -1 and empty B.



    B.clear();
    if ((s.size()<=1) || (Alph.length()<2)) return -1; // checking that s contains more than 2 stings and Alph consists of >=2 symbols.


    int lstring = (s[0]).length();
    int lvector = s.size();


    for (int i=1; i<s.size(); i++)  // checking that all strings in s have equal length
        if (s[i].length()!=lstring)
        {
            return -1;
        }

    std::set <char> T; // проверка что нет дублирующихся символов в алфавите
    T.clear(); // Testing if there are any identical symbols in the Alphabet
    for  (int y=0; y<Alph.length(); y++)
    {
        T.insert(Alph[y]);
        if ((T.size()-1)!=y)
            return -1;

    }
    T.clear();

    MatrixSet (B, Alph.length(), lstring, 0);

    for (int i = 0; i<lstring; i++)
    {
        for (int j = 0; j<lvector; j++)
        {
            for  (int y=0; y<Alph.length(); y++)
                 if (((s[j])[i]) == Alph[y]) {B[y][i]++; goto l1;}



                B.clear(); // Если хоть один символ не из алфавита - очищаем матрицу и возвращаем -1
                return -1; // even one symbol doesn't belong to Alph - matrix B to be cleared and -1 to return

            l1:;
        }

    }

    return 0;

}



int GPPM (const std::vector <std::string> &s, std::vector <std::vector <long double>> & B, const std::string &Alph, long double z = 0.0, long double d = 2.0)
{

// Генерирует позиционную матрицу вероятностей B по набору исходных строк s и алфавиту Alph (содержит последовательность символов алфавита);
// Последовательность строк в матрице B соответствует последовательности символов в строке Alph (т.е. последовательности символов алфавита).
// в случае если в набор пустой или же строки в нем имеют неодинаковую длину или в алфавите менее 2 букв или хоть одна из строк содержит хоть один символ не из алфавита,
// или же если алфавит содержит дублирующиеся символы - возвращается -1  и пустая матрица B (в случае успеха возвращается 0 и заполненная B).
// z - параметр для сглаживания (pseudocount): используется формула (Ns+z)/(N+d*z)

// Generates a position probability matrix (PPM) B upon an array of strings s and given Alphabet (Alphabet is set via string Alph that contains the sequence of its symbols);
// Ordering of the rows in B corresponds to sequence of symbols in Alph.
// If s contains 0 items or its strings have not equal length or even the only string contains symbol that not belongs to Alphabet or if there are any identical symbols in the Alphabet - returns -1 and empty B. If success returns 0 and generated B.
    // z is a pseudocount parameter: (Ns+z)/(N+d*z) is used



    B.clear();
    if ((s.size()<1) || (Alph.length()<2)) return -1; // checking that s contains at least 1 sting and Alph consists of >=2 symbols.


    int lstring = (s[0]).length();
    int lvector = s.size();


    for (int i=1; i<s.size(); i++)  // checking that all strings in s have equal length
        if (s[i].length()!=lstring)
        {
            return -1;
        }

    std::set <char> T; // проверка что нет дублирующихся символов в алфавите
    T.clear(); // Testing if there are any identical symbols in the Alphabet
    for  (int y=0; y<Alph.length(); y++)
    {
        T.insert(Alph[y]);
        if ((T.size()-1)!=y)
            return -1;

    }
    T.clear();



    MatrixSet (B, Alph.length(), lstring, z/(s.size()*1.0+d*z));




    for (int i = 0; i<lstring; i++)
    {
        for (int j = 0; j<lvector; j++)
        {
            for  (int y=0; y<Alph.length(); y++)
                if (((s[j])[i]) == Alph[y]) {B[y][i]=B[y][i]+1.0/(s.size()*1.0+d*z); goto l1;}



                B.clear(); // Если хоть один символ не из алфавита - очищаем матрицу и возвращаем -1
                return -1; // even one symbol doesn't belong to Alph - matrix B to be cleared and -1 to return

            l1:;
        }

    }




    return 0;

}



double PDist (const std::string& s1, const std::string& s2) // counts p-distance without checking of the input data correctness
{
    double r;
    int q = 0;
    for (unsigned int i=0; i<s1.length(); i++)
    {if (s1[i] != s2[i]) q++;}
    r = double(q)/s1.length();
    return r;
}


int GDistanceMatrix (std::vector <std::string> &s, std::vector <std::vector <double>> & B)
{
// Генерирует матрицу расстояний "B" по набору исходных строк s; в случае если в наборе менее 2х строк или они имеют неодинаковую длину - возвращается -1 (в случае успеха - 0).
// Generates DistanceMatrix "B" upon array of strings s; if s contains 1 or 0 items or strings have not equal length returns -1 and empty B.


    B.clear();
    if (s.size()<=1) return -1; // checking that s contains more than 2 stings

    int lstring = (s[0]).length();
    int lvector = s.size();


    for (int i=1; i<s.size(); i++)  // checking that all strings in s have equal length
        if (s[i].length()!=lstring)
        {
            return -1;
        }


    MatrixSet (B, lvector, lvector, 0);

    for (int i = 0; i<lvector; i++)
    for (int j = 0; j<lvector; j++)
    {
        B [i][j] = PDist(s[i], s[j]);
    }

    return 0;
}


int EditDist (const std::string &s1, const std::string &s2)
// Рассчитывает редакционное расстояние (расстояние Левенштейна) мeжду строками, принимает на вход даже пустые. Цена каждой операции = 1
// Computes Edit Distance (Levenshtein distance) between two strings (strings may be empty too).

{
int n = s1.length()+1;
int m = s2.length()+1;
if ((n==1)&&(m==1)) return 0;

if (n==1) return (m-1);
if (m==1) return (n-1);



if ((n<32000)&&(m<32000))

{
    std::vector <std::vector <short int>> B (n);  // Generating pre-matrix for computing distance filled by zeros.
    for (unsigned int row = 0; (row< n); row++)
    {
        B [row].resize(m);
        for (unsigned int column = 0; (column < m); column++)
        {
            B [row] [column] = 0;

        }

    }



    // Filling the matrix
    short int w=1;
    for (short int i = 0; (i< n); i++)
        for (short int j = 0; (j< m); j++)
            if (j==0) B[i][j] = i;
            else if (i==0) B[i][j] = j;
            else
            {
                w = 1;
                if (s1[i-1] == s2[j-1])   // нужны элементы строк i, j по порядку, но т.к. нумеруем с нуля символы строк - поправка на -1
                //Note that symbols of strings have 0-based indexing. So we have "-1 - correction" here.
                    w = 0;
                B[i][j] = std::min (1+B[i-1][j], 1+B[i][j-1]);
                if ((w+B[i-1][j-1]) < B[i][j]) B[i][j] = (w+B[i-1][j-1]);
            }


    return (int)(B[n-1][m-1]);

}


std::vector <std::vector <int>> B (n);  // Generating pre-matrix for computing distance filled by zeros.
for (unsigned int row = 0; (row< n); row++)
{
    B [row].resize(m);
    for (unsigned int column = 0; (column < m); column++)
    {
        B [row] [column] = 0;

    }

}



// Filling the matrix
int w=1;
for (unsigned int i = 0; (i< n); i++)
    for (unsigned int j = 0; (j< m); j++)
        if (j==0) B[i][j] = i;
        else if (i==0) B[i][j] = j;
        else
        {
            w = 1;
            if (s1[i-1] == s2[j-1])   // нужны элементы строк i, j по порядку, но т.к. нумеруем с нуля символы строк - поправка на -1
            //Note that symbols of strings have 0-based indexing. So we have "-1 - correction" here.
                w = 0;
            B[i][j] = std::min (1+B[i-1][j], 1+B[i][j-1]);
            if ((w+B[i-1][j-1]) < B[i][j]) B[i][j] = (w+B[i-1][j-1]);
        }


return B[n-1][m-1];

}


int EditDistA (const std::string &s1, const std::string &s2, std::string &sr1, std::string &sr2)
// Расширенная версия функции EditDist (см. выше). Возвращает также Edit Distance Alignment строк s1 и s2 как строки sr1 и sr2 (если несколько вариантов возможны - один из возможных).
// Extended version of the function EditDist (see it above). Returns also Edit Distance Alignment of s1 and s2 as sr1 and sr2 (one possible version if many exists).

{

    sr1.clear();
    sr2.clear();

int n = s1.length()+1;
int m = s2.length()+1;

if ((n==1)&&(m==1)) return 0;

if (n==1) return (m-1);
if (m==1) return (n-1);


if ((n<32000)&&(m<32000))
{
    std::vector <std::vector <short int>> B (n);  // Generating pre-matrix for computing distance filled by zeros.
    for (unsigned int row = 0; (row< n); row++)
    {
        B [row].resize(m);
        for (unsigned int column = 0; (column < m); column++)
        {
            B [row] [column] = 0;

        }

    }



    // Filling the matrix
    short int w=1;
    for (short int i = 0; (i< n); i++)
        for (short int j = 0; (j< m); j++)
            if (j==0) B[i][j] = i;
            else if (i==0) B[i][j] = j;
            else
            {
                w = 1;
                if (s1[i-1] == s2[j-1])   // нужны элементы строк i, j по порядку, но т.к. нумеруем с нуля символы строк - поправка на -1
                //Note that symbols of strings have 0-based indexing. So we have "-1 - correction" here.
                    w = 0;
                B[i][j] = std::min (1+B[i-1][j], 1+B[i][j-1]);
                if ((w+B[i-1][j-1]) < B[i][j]) B[i][j] = (w+B[i-1][j-1]);
            }



    // построение результата
    // let' s construct sr1 and sr2


    short int count0 = n-1;
    short int count1 = m-1;

    short int t, t0, t1,t2;

    while ((count0>0) && (count1>0) )
    {
        t = B[count0][count1];
        t2 = B[count0-1][count1-1];
        t0 = B[count0-1][count1];
        t1 = B[count0][count1-1];

        if ((t2<=t1) && (t2<=t0))
        {
            sr1 = s1[count0-1] + sr1;
            sr2 = s2[count1-1] + sr2;
            count0--;
            count1--;
            continue;
        }

        if ((t1<=t0) && (t1<=t2))
        {
            sr1 = "-" + sr1;
            sr2 = s2[count1-1] + sr2;
            count1--;
            continue;
        }

        if ((t0<=t2) && (t0<=t1))
        {
            sr2 = "-" + sr2;
            sr1 = s1[count0-1] + sr1;
            count0--;
            continue;
        }

    }

    while (count0>0)
    {
        sr2 = "-" + sr2;
        sr1 = s1[count0-1] + sr1;
        count0--;
    }

    while (count1>0)
    {
        sr1 = "-" + sr1;
        sr2 = s2[count1-1] + sr2;
        count1--;
    }



    return (int)(B[n-1][m-1]);
}



std::vector <std::vector <int>> B (n);  // Generating pre-matrix for computing distance filled by zeros.
for (unsigned int row = 0; (row< n); row++)
{
    B [row].resize(m);
    for (unsigned int column = 0; (column < m); column++)
    {
        B [row] [column] = 0;

    }

}



// Filling the matrix
int w=1;
for (unsigned int i = 0; (i< n); i++)
    for (unsigned int j = 0; (j< m); j++)
        if (j==0) B[i][j] = i;
        else if (i==0) B[i][j] = j;
        else
        {
            w = 1;
            if (s1[i-1] == s2[j-1])   // нужны элементы строк i, j по порядку, но т.к. нумеруем с нуля символы строк - поправка на -1
            //Note that symbols of strings have 0-based indexing. So we have "-1 - correction" here.
                w = 0;
            B[i][j] = std::min (1+B[i-1][j], 1+B[i][j-1]);
            if ((w+B[i-1][j-1]) < B[i][j]) B[i][j] = (w+B[i-1][j-1]);
        }



// построение результата
// let' s construct sr1 and sr2


int count0 = n-1;
int count1 = m-1;

int t, t0, t1,t2;

while ((count0>0) && (count1>0) )
{
    t = B[count0][count1];
    t2 = B[count0-1][count1-1];
    t0 = B[count0-1][count1];
    t1 = B[count0][count1-1];

    if ((t2<=t1) && (t2<=t0))
    {
        sr1 = s1[count0-1] + sr1;
        sr2 = s2[count1-1] + sr2;
        count0--;
        count1--;
        continue;
    }

    if ((t1<=t0) && (t1<=t2))
    {
        sr1 = "-" + sr1;
        sr2 = s2[count1-1] + sr2;
        count1--;
        continue;
    }

    if ((t0<=t2) && (t0<=t1))
    {
        sr2 = "-" + sr2;
        sr1 = s1[count0-1] + sr1;
        count0--;
        continue;
    }

}

while (count0>0)
{
    sr2 = "-" + sr2;
    sr1 = s1[count0-1] + sr1;
    count0--;
}

while (count1>0)
{
    sr1 = "-" + sr1;
    sr2 = s2[count1-1] + sr2;
    count1--;
}



return B[n-1][m-1];

}


std::string CIGAR1 (const std::string &S0, const std:: string & S2, int npos = 0)
// Формирует строку CIGAR по результату "прикладывания" строки S2 к строке S0 с позиции npos;
// в случае некорректных данных (длина какой-л. строки равна 0, начальная позиция отрицательна или приложенная S2 "выезжает" за границу S0 - возвращает пустую строку
// Generates CIGAR-string as a result of "fitting" of the string S2 to s0 (strarting position == npos).
// If any data is incorrect returns empty string.



{

    std::string Result ="";

    std::string r ="";

    if (npos <0) return Result;
    if (S0.length()==0) return Result;
    if (S2.length()==0) return Result;

    if ((npos + S2.length())>S0.length()) return Result;

    std::string S1 = S0.substr(npos, S2.length());




        for (int y=0;y<S1.length();y++)
      {
            if (S1[y]==S2[y])
            {r = r+"M";continue;}

            if (S1[y]=='-')
            {r = r+"I";
                continue;}
            if (S2[y]=='-')
            {r = r+"D"; continue;}

            if (S1[y]!=S2[y])
                r = r+"X";
      }



    int c;
    for (int i=0; i<r.size();i++)
    {
        c=0;
        for (int j = i;j<r.size(); j++)
        {
            if (r[j]!=r[i]) break;
            c++;
        }
        Result = Result + std::to_string(c) + r[i];
        i = i+c-1;
    }

    return Result;
}



int ConsStringQ1 (std::vector <std::string> &DataS, std::vector<std::string> &QDataS, std::string &TempS, std::string &QTempS, const int method = 1, const std::string &Alph = "ACGT", const int Phred=33)
// Generates a consensus string upon std::vector <std::string> DataS as an input collection of strings and QDataS as their quality.
// The result will be as TempS as consensus string and QTempS as its quality string.
// If multiply consensus strings exist returns the one of them.
// The parameter "Alph" set an alphabet, by default Alph = "ACGT" (other symbols are not considered for forming the consensus string).
// The parameter "Phred" sets the quality scale (by default as Phred33).
// There are 4 methods to construct the consensus string (set by the parameter "method"):
// 0 - default - the symbol that has the maximal average probability (quality) for a given position in consensus string will be chosen. It will have the same quality.
// 1 - the symbol that has the maximal sum of probability (quality) for a given position in consensus string will be chosen. it will have the quality = sum of probability (quality) of this char / number of times that the char occurs at given position.
// 2 - the symbol that has the maximal sum of probability (quality) for a given position in consensus string will be chosen. it will have the max quality (probability) of this char at given position.
// 3 - the symbol that has the maximal probability (quality) for a given position in consensus string will be chosen. It will have the same quality.
// One may set QDataS as empty: in this case quality will considered as "some equal" for every symbol at every position.
// So in order to find a consensus string upon a given collection without quality one may choose method №1 or №2 and empty QDataS.
// If no symbol of the Alph has been found at a given position - the ' ' will be set there both in the consensus string TempS and in quality string QTempS.
// If any input data is incorrect returns -1 and empty TempS and QTempS, otherwise returns 0.

// Формирует консенсусную строку (если возможно несколько вариантов такой строки - то один из них) согласно набру строк DataS с соотвествующим качеством (строки, задающие качество даны в QDataS на соотвествующих позициях).
// Результат - консенсусная строка TempS и соотвествующая ей строка качества QTempS. В случае успеха возвращается 0, в случае некорректных вводных данных - -1 и пустые указанные строки.
// Параметр "Alph" задает алфавит: только эти символы учитываются при формировании консенсуса.
// Параметр "Phred" задает шкалу качества (по умолчанию - Phred33).
// Предусмотрены 4 метода формирования консенсусной строки:
// 0 - по умолчанию - символы на каждой данной позиции выбираются согласно максимальной средней вероятности (качеству), качество присваивается то же.
// 1 - символы на каждой данной позиции выбираются согласно максимальной суммарной вероятности (качеству), качество присваивается как среднее по данному символу.
// 2 - то же, но качество присваивается как максимальное по данному символу на данной позиции.
// 4 - выбор символа (и присвоение ему качества) осуществляется исходя из максимального качества (вероятности) символа на данной позиции.
// Если передать пустой QDataS, то предполагается, что качество везде "какое-то одинаковое", строка QTempS возвращается пустой. Т.обр., для определения консенсусной строки согласно лишь частоте
// появления символов достаточно выбрать метод = 1 или 2 и пустой QTempS.
// Если ни одного символа из алфавита на данной позиции не найдено - ставится ' ' и качество по данной позиции задается как ' '.




{


    TempS = "";
    QTempS = "";

    if (DataS.size()==0) return -1;

    if (Phred<33) return -1;
    if (method<0) return -1;
    if (method>3) return -1;
    if (Alph.length()<2) return -1;

    int lstring = DataS[0].length();
    int lvector = DataS.size();
    int f=0;

        if (QDataS.size()==0)
        {
            for (int i=0; i<DataS[0].size(); i++)
                TempS = TempS + '^';
            f=1;
            for (int i=0; i<DataS.size(); i++)
                QDataS.push_back(TempS);

        }

    TempS.clear();

    for (int i=0; i<DataS.size(); i++)
    {
        if (DataS[i].length()!=DataS[0].length())
        {

            if (TempS.length()>0) QDataS.clear();
            return -1;
        }
        if (QDataS[i].length()!=DataS[0].length())
        {

            if (TempS.length()>0) QDataS.clear();
            return -1;
        }
    }





    std::vector <std::vector <long double>> B;
    B.clear();
    std::vector <std::vector <long double>> M;
    M.clear();
    std::vector <std::vector <int>> C;
    C.clear();

    char t;
    long double qt, qt1, qt2;



    MatrixSet (B, Alph.length(), lstring, 0.0);
    MatrixSet (C, Alph.length(), lstring, 0);
    MatrixSet (M, Alph.length(), lstring, 0.0);

    for (int ii = 0; ii<lstring; ii++)
    {
    for (int j = 0; j<lvector; j++)
    {
        for  (int c=0; c<Alph.length(); c++)
             if (((DataS[j])[ii]) == Alph[c])
             {

                 B[c][ii]=B[c][ii]+ 1.0-pow (10.0, -0.1*((int)(QDataS[j][ii])-Phred)  );
                 C[c][ii]++;
                 if (M[c][ii]<1.0-pow (10.0, -0.1*((int)(QDataS[j][ii])-Phred)  ) ) M[c][ii] = 1.0-pow (10.0, -0.1*((int)(QDataS[j][ii])-Phred)  );
             }

    }

    }

    if (method == 0)
    {
    for (int c = 0; c<Alph.length(); c++)
    {
        for (int ii = 0; ii<lstring; ii++)
        {
            if (C[c][ii]!=0) B[c][ii] = B[c][ii] / C[c][ii];

        }
    }
    }


    if (method == 3)
    {
    for (int c = 0; c<Alph.length(); c++)
    {
        for (int ii = 0; ii<lstring; ii++)
        {
            B[c][ii] = M[c][ii];

        }
    }
    }


    TempS = "";
    QTempS = "";



    for (int ii = 0; ii<lstring; ii++)
    {
        t = Alph[0];
        qt=B[0][ii];

        qt1=0.0;
        qt2 = M[0][ii];
        if (C[0][ii]!=0) qt1 = B[0][ii]/C[0][ii];

         if (C[0][ii]==0) t = ' ';

        for (int c = 1; c<Alph.length(); c++)
            if (B[c][ii]>qt)
            {
                qt = B[c][ii];
                qt2 = M[c][ii];
                if (C[c][ii]!=0) qt1 = B[c][ii]/C[c][ii];
                t = Alph[c];
            }
        TempS.push_back(t);

       if (method==1) qt = qt1;
        if (method==2) qt = qt2;

        if (t!=' ') QTempS.push_back((char)(Phred-10*log10(1.0-qt)));
        if (t==' ') QTempS.push_back(' ');


    }

    if (f==1) {QDataS.clear(); QTempS.clear();}
    return 0;
    }


int ConsStringQ2 (std::vector <std::string> &DataS, std::vector<std::string> &QDataS, std::string &TempS, std::string &QTempS, const int method = 1, const std::string &Alph = "ACGT", const char tr = '^', const int Phred=33)
// Модификация функции ConsStringQ1 (см. выше) для целей учета всех вариантов консенсусной строки.
// В консенсусной строке позиции разделяются символом tr (по умолчанию = '^'), при этом на каждой позиции может быть несколько символов из алфавита, если с т.зр. критерия выбора они равновероятны.
// Modification of ConsStringQ1 (see it above) for all the version of consensus string. For that every position may have >= 1 symbols (if different symbols may be chosen for this position).
// The positions are separated by the symbol tr (by default is set as '^').

{
    TempS = "";
    QTempS = "";

    if (DataS.size()==0) return -1;

    if (Phred<33) return -1;
    if (method<0) return -1;
    if (method>3) return -1;
    if (Alph.length()<2) return -1;
    if (Alph.find(tr)!=-1) return -1;


    int lstring = DataS[0].length();
    int lvector = DataS.size();
    int f=0;

        if (QDataS.size()==0)
        {
            for (int i=0; i<DataS[0].size(); i++)
                TempS = TempS + '^';
            f=1;
            for (int i=0; i<DataS.size(); i++)
                QDataS.push_back(TempS);

        }

    TempS.clear();

    for (int i=0; i<DataS.size(); i++)
    {
        if (DataS[i].length()!=DataS[0].length())
        {

            if (TempS.length()>0) QDataS.clear();
            return -1;
        }
        if (QDataS[i].length()!=DataS[0].length())
        {

            if (TempS.length()>0) QDataS.clear();
            return -1;
        }
    }





    std::vector <std::vector <long double>> B;
    B.clear();
    std::vector <std::vector <long double>> M;
    M.clear();
    std::vector <std::vector <int>> C;
    C.clear();

    char t;
    long double qt, qt1, qt2;



    MatrixSet (B, Alph.length(), lstring, 0.0);
    MatrixSet (C, Alph.length(), lstring, 0);
    MatrixSet (M, Alph.length(), lstring, 0.0);

    for (int ii = 0; ii<lstring; ii++)
    {
        for (int j = 0; j<lvector; j++)
        {
            for  (int c=0; c<Alph.length(); c++)
                 if (((DataS[j])[ii]) == Alph[c])
                 {

                     B[c][ii]=B[c][ii]+ 1.0-pow (10.0, -0.1*((int)(QDataS[j][ii])-Phred)  );
                     C[c][ii]++;
                     if (M[c][ii]<1.0-pow (10.0, -0.1*((int)(QDataS[j][ii])-Phred)  ) ) M[c][ii] = 1.0-pow (10.0, -0.1*((int)(QDataS[j][ii])-Phred)  );
                 }

        }

    }

    if (method == 0)
    {
    for (int c = 0; c<Alph.length(); c++)
    {
        for (int ii = 0; ii<lstring; ii++)
        {
            if (C[c][ii]!=0) B[c][ii] = B[c][ii] / C[c][ii];

        }
    }
    }



    if (method == 3)
    {
    for (int c = 0; c<Alph.length(); c++)
    {
        for (int ii = 0; ii<lstring; ii++)
        {
            B[c][ii] = M[c][ii];

        }
    }
    }

    TempS = "";
    QTempS = "";



    std::vector <long double> P (lstring, 0);



    for (int ii = 0; ii<lstring; ii++)
    {

        for (int c = 0; c<Alph.length(); c++)
            if (B[c][ii]>P[ii])
            {
                P[ii]=B[c][ii];

            }



    }


    for (int ii = 0; ii<lstring; ii++)
    {
        TempS.push_back(tr);
        QTempS.push_back(tr);

        if (P[ii]==0.0) {TempS.push_back(' ');QTempS.push_back(' '); continue;}


        for (int c = 0; c<Alph.length(); c++)
            if (P[ii]==B[c][ii])
            {


                qt = B[c][ii];
                qt2 = M[c][ii];
                if (C[c][ii]!=0) qt1 = B[c][ii]/C[c][ii];
                t = Alph[c];

                if (method==1) qt = qt1;
                 if (method==2) qt = qt2;



                 TempS.push_back(t);

                 QTempS.push_back((char)(Phred-10*log10(1.0-qt)));


            }



    }

    TempS.push_back(tr);
    QTempS.push_back(tr);

    if (f==1) {QDataS.clear(); QTempS.clear();}
    return 0;
    }


int JoinOverlapStrings (std::multimap <long long int, std::string> & Locuses, std::map <long long int, std::string> & JoinedLocuses, const bool Aggregate = false, const bool NoQuality = false, const int method = 0, const std::string &Alph = "ACGT", const int Phred=33)
// Функция, которая принимает на вход Locuses, содержащий набор подстрок из некоторой неизвестной строки, в формате: стартовая позиция в неизвестной строке -> сама (под)строка,
// и объединяет пересекающиеся строки (результат записывается в JoinedLocuses в том же формате).
// Области пересечений строятся как консенсусные строки:
// - с помощью функции ConsStringQ1, если необходим какой-либо один из приемлемых вариантов (bool Aggregate = false), или с помощью ConsStringQ2, если необходимы все варианты (bool Aggregate = true) (подробнее см описания данных функций),
// - с выбранным методом построения консенсусной строки (0 - 3, подробнее о методах также  см. описания ConsStringQ1 и ConsStringQ2),
// - с учетом качества (NoQuality=false) или нет (NoQuality=true); при учете качества считается, что первая половина каждой строки в Locuses содержит собственно саму строку, а вторая половина - строку, задающую ее качество.
// - Параметр качества задается по шкале Phred с помощью соответствующего параметра.
// - Алфавит задается параметром Alph, так что при формировании консенсусных строк будут учитываться только символы из данного алфавита.
// Таким образом, если необходимо просто соединить все пересекающиеся строки в нектором наборе без учета качества, необходимо задать NoQuality = true, задать алфавит и в Locuses разместить саму коллекцию объединяемых строк.
// В случае NoQuality = true будет всегда использоваться метод №1
// Например, коллекция вида  0->ACGT, 1->TGTA, 1->TT, 10->TT, 11->TCA в этом случае объединится как 0->ATGTA, 10->TTC.

// The function joins overlapping strings from Locuses (contain substrings of the unknown string as pairs: start position -> string) and writes the resulting collection of the joined strings to JoinedLocuses (has the same format).
// The overlaps are to constructed as consensus strings:
// - using ConsStringQ1 (if any one version of result needed, set bool Aggregate = false for it) or using ConsStringQ2 (if all the version needed, set bool Aggregate = true for it), see info on ConsStringQ1 and ConsStringQ2 for details.
// - using the chosen method of consensus generating (set by parameter "method", see info on ConsStringQ1 and ConsStringQ2 for details).
// - taking into account quality (NoQuality=false, scale is set by parameter "Phred") or no (NoQuality=true).
//   NOTE that if we take quality into account (NoQuality=false) it is expected that the first half of every string in Locuses means the string to be joined itself, and the other half – its quality.
// - the Alphabet should be set by the string Alph. In doing so, only symbols of the Alph will be taken into account for consensus string generation.
// If NoQuality = true method #1 will be used always.
// So, if we need to join collection 0->ACGT, 1->TGTA, 1->TT, 10->TT, 11->TCA in any way without any additional info,
// we should set NoQuality = true, Aggregate = false, and have the result: 0->ATGTA, 10->TTC.


{
    JoinedLocuses.clear();
    if (Locuses.size()==0) return -1;
    if (Phred<33) return -1;
    if (method<0) return -1;
    if (method>3) return -1;


    auto it1 = Locuses.begin();
    if (Locuses.size()==1) {JoinedLocuses.insert(std::pair<long long int, std::string>(it1->first, it1->second) ); return 0;}


    int t;

    int mx = -1;

    long long int y = 1;
    auto it2 = it1;
    it2++;

    std::vector <long long int> Pos;
    Pos.clear();
    Pos.push_back(0);

    std::vector<std::vector <long long int>> AllPos;
    AllPos.clear();

    while (it2!=Locuses.end())
    {
        if ( (it1->first + it1->second.length()/2) > mx) mx = (it1->first + it1->second.length()/2);

        if ( (it2->first)<=mx)

        {
            Pos.push_back(y);

            y++;

            it2++;

            it1++;

            if (it2==Locuses.end())
            {
                AllPos.push_back(Pos);
                Pos.clear();
             }
            continue;

        }

        else

        {
            AllPos.push_back(Pos);
            Pos.clear();

            it1=it2;
            it2++;



            Pos.push_back(y);
            y++;


            mx=-1;

            if (it2==Locuses.end())
            {
                AllPos.push_back(Pos);
                Pos.clear();
             }

            continue;

        }


    }

    std::vector <std::string> DataS;
    DataS.clear();
    std::string TempS="";


    std::vector <std::string> QDataS;
    QDataS.clear();
    std::string QTempS="";


    for (int i=0; i<AllPos.size(); i++)
    {
    DataS.clear();
    QDataS.clear();
    mx=0;
    for (int j=0; j<AllPos[i].size(); j++)
    {
        it1 = Locuses.begin();
        for (int e = 0; e<AllPos[i][j]; e++)
            it1++;
        if (j==0) y = it1->first;

        TempS=it1->second.substr(0, it1->second.length()/2);
        QTempS=it1->second.substr(it1->second.length()/2, it1->second.length()/2);

        if (NoQuality)
        {
            TempS = TempS + QTempS;
            QTempS = QTempS + QTempS;
        }


        for (int g=1; g<=(it1->first-y); g++)
        {
            TempS="-"+TempS;
            QTempS=" "+QTempS;
        }
        if (TempS.length()>mx) mx = TempS.length();
        DataS.push_back(TempS);
        QDataS.push_back(QTempS);

    }



    for (int r = 0; r<DataS.size(); r++)
    {
        if (DataS[r].length()<mx)
        {
            t = (mx-DataS[r].length());
            for (int g=1; g<=t; g++)
            {
                DataS[r]=DataS[r]+"-";
                QDataS[r]=QDataS[r]+" ";
             }
        }
    }



        if (NoQuality) QDataS.clear();

        if (Aggregate)        ConsStringQ2(DataS, QDataS, TempS, QTempS, method*(!NoQuality)+NoQuality, Alph);
        if (!Aggregate)        ConsStringQ1(DataS, QDataS, TempS, QTempS, method*(!NoQuality)+NoQuality, Alph);


        JoinedLocuses.insert(std::pair<long long int, std::string>(y, TempS+QTempS) );


                TempS.clear();
                QTempS.clear();

}


return 0;
}





long double ProfileProbableMer (const std::string &s, int n, const std::vector <std::vector <long double>> & B, std::vector <std::string> & DataS, long double d = 0.0000001, std::string Alph = "ACGT")

// Finds all most probable n-mer of the given string s upon position probability matrix B and Alphabet Alph.
// Returns their probability and all these n-mers contained in DataS.
// If any data incorrect returns empty DataS and -1.0.
// d sets precision for doubles comparison.

// Находит все наиболее вероятные n-меры в строке s исходя из позиционной матрицы вероятностей B и возвращает их в векторе DataS. Возвращает значение соответствующей вероятности.
// Если данные некорректны, возвращает пустой DataS и -1.0
// Параметр d задает точность при расчете вероятностей.

{

        DataS.clear();

        if (n>s.length()) return -1.0;
        if (n<1) return -1.0;
        if (d<0.0) return -1.0;
        if (s=="") return -1.0;
        for (int y=0; y<s.length(); y++)
            if (Alph.find(s[y])==-1) return -1.0;

        if (Alph.size()==0) return -1.0;
        if (B.size()!=Alph.size()) return -1.0;




        for (int z=0; z<B.size(); z++)
        {
            if (B[z].size()!=n) return -1.0;
            for (int x=0; x<n; x++)
                if (B[z][x]<0.0) return -1.0;
        }





        long double p = 0.0; // for probability of the most probable n-mer
        long double tp = 0.0; // for probability of n-mer in s

        std::string ts="";



        for (int y = 0; y< s.length()-n+1; y++)
        {
            ts = s.substr(y, n);
            tp = 1.0;


            for (int x = 0; x<ts.size(); x++)
                tp = tp*B[ Alph.find(ts[x])] [x];




            if ((tp-p)>=d)
            {
                p=tp;
                DataS.clear();
                DataS.push_back(ts);
                continue;
            }

            if (std::abs(tp-p)<d)
            {
               DataS.push_back(ts);

            }


        }


        return p;
}



void EDistForFindMR (const std::string &s1, const std::string &s2, const int D, const int L, int l, int b, std::set <std::pair <int, int>> &Result)

// Вспомогательная функция для FindMutatedRepeatsED (см. ниже, приводится следующей).
// An auxiliary function for FindMutatedRepeatsED, see its info for details (below, the following one).

{
int n = s1.length()+1;
int m = s2.length()+1;



std::vector <std::vector <int>> B (n);  // Generating pre-matrix for computing edit distance. It is filled by zeros by default.
MatrixSet(B, n, m, 0);



// Filling the matrix
int w=1;
for (unsigned int i = 0; (i< n); i++)
    for (unsigned int j = 0; (j< m); j++)
        if (j==0) B[i][j] = i;
        else if (i==0) B[i][j] = j;
        else
        {
            w = 1;
            if (s1[i-1] == s2[j-1])   // нужны элементы строк i, j по порядку, но т.к. нумеруем с нуля символы строк - поправка на -1
            //Note that symbols of strings have 0-based indexing. So we have "-1 - correction" here.
                w = 0;
            B[i][j] = std::min (1+B[i-1][j], 1+B[i][j-1]);
            if ((w+B[i-1][j-1]) < B[i][j]) B[i][j] = (w+B[i-1][j-1]);
        }


int c1 = n-1;
int c2 = m-1;

while (l>=L-D)
{
    if (B[c1][c2]<=D) // The matrix B contains Edit Distance between s2 and not only s1, but for all prefixes of s1 too (the previous row at the same coloumn for the substring formed by deleting the last symbol etc).
    {


        Result.insert(std::pair<int, int>(b-1, l)); // So if Edit Distance <=D and the length of prefix not less than L-D, this prefix is the one of required. So let's insert its data to Result.

    }
    l--;
    c1--;

}


}



int FindMutatedRepeatsED (std::string &StrShort, std::string &StrLong, int D, std::set <std::pair <int, int>> &Result)
// Функция находит все подстроки для строки StrLong, редакционное расстояние которых до StrShort не превышает D. При этом принимается, что "штраф" за пропуск и несовпадение символов  = 1.
// Результат возвращается в set <std::pair <int, int>> Result, где первое число в паре - номер позиции начала подстроки в StrLong (счет позиций идет с 0), а второе - длина подстроки (пары не отсортированы).
// Если исходные данные некорректны - возвращается -1 и пустой Result;, в случае успеха возвращается 0.
// Идея реализованного алгоритма:
// (1) Найти все начала таких подстрок в StrLong.
// Для этого обе строки реверсируются, затем StrShort "выравнивается" на StrLong по обычным правилам для нахождения редакционного расстояния, но с тем отличием,
// что суммарный начальный пропуск по StrLong не "штрафуется" (начать можно с любой позиции в длинной строке без "штрафа"). Найденные начальные позиции нумеруются с 1. Затем строки реверсируются обратно.
// (2) Для каждой позиции вычисляется максимально возможная длина искомой подстроки, которая не может быть более длины StrShort плюс D, и при этом не может выходить за границу StrLong.
// Пояснение. Длины искомых подстрок не могут отличаться от длины StrShort более чем на D в ту и другую сторону, т.к. редакционное расстояние не превышает D, а цена пропуска = 1.
// (3) Если такая максимально возможная длина есть и составляет не менее длины StrShort минус D, то для соотвествующей подстроки (обозначим как TempS) и StrShort осуществляем стандартный Edit Distance Alignment с помощью вспомогательной функции EDistForFindMR.
// И в выстраиваемой для этих целей матрице будут значения Edit Distance не только между StrShort и TempS, но и (!) укороченным с конца подстрокам TempS (для этого берем значения в матрице не только по последней строке (TempS "откладывается" вниз), но и по предшествующим.
// Если для каждого такого префикса строки TempS (при условии, что его длина удовлетворяет пояснению к шагу (2)) значение Edit Distance не превышает D - фиксируем в set Result его начальную позицию (в нумерации от 0) и длину.
// Функция возвращает 0 и заполненный Result в случае успеха и -1 и пустой Result в случае некорректности исходных данных (любая из строк пуста или StrShort длиннее StrLong или длина StrShort не превосходит D)


// The function finds all the substrings of a string StrLong, that have Edit Distance to a string StrShort <= D. Gap and mistmatch penalties are set as "1" here.
// If dataset is correct returns 0 and set <std::pair <int, int>> Result, that contains pairs of integers: first one is a start position of a required substring in StrLong (0-based indexing)  and the second one is its length.
// If dataset is not correct (any string is empty of StrShort is longer than StrLong or StrShort's length <= D) returns -1 and empty Result.
// The algorithm idea is:
// (1) to find all start positions of such substrings. To do so we should reverse both strings and then do Edit Distance Alignment but with no gap penalty at the beginning: The required substring may start at every position of the longer string so here are no penalty fo gapping at start.
// (2) For each start position the maximal possible length for the required substring (<= StrShort.length+D, but within StrLong).
// Note that the required substrings may have length <= StrShort.length+D and >= StrShort.length-D because gap penalty = 1.
// (3) If such maximal possible length meets this condition, let a string TempS be a substring of StrLong of this length (TempS starts from relevant start position in StrLong).
// And then let's do Edit Distance Alignment between TempS and StrShort in order to find prefixes of TempS, that require the statement of problem to be solved here.


{
    Result.clear();

    if (StrShort.length()>StrLong.length()) return -1; // Приверка корректности исходных данных  // checking for input tata correctness
    if ((StrShort.length()==0) || (StrLong.length()==0))return -1; // Приверка корректности исходных данных  // checking for input tata correctness
    if (D<0) return -1; // Приверка корректности исходных данных  // checking for input tata correctness
    if (StrShort.length()<=D) return -1; // Приверка корректности исходных данных  // checking for input tata correctness


    std::string TempS = "";


    const int gapP = -1; //gap penalty
    const int mismP = -1; //mismatch penalty

std::set <int>StartPositions; //Here the start positions of required substrings of StrLong will be contained (their numbering starts from "1" for this set).
// Здесь будем хранить номера начал искомых строк (здесь допущение: символы в строке нумеруются с 1)




int L = StrShort.length();
StartPositions.clear();


//Preparing a matrix for alignment
unsigned int n = StrShort.length()+1;
unsigned int m = StrLong.length()+1;

std::vector <std::vector <int>> B (n);


int count0;
int count1;

int w;
int mt, dt, in;



MatrixSet(B, n, m, 0);


  for (unsigned int i = 0; (i< n); i++)  // Поправка: начать можно с любой позиции в длинной строке без "штрафа"
      B[i][0] = i*gapP;                  // The required substring may start at every position of the longer string so here are no penalty fo gapping at start

  // End of preparing a matrix for alignment

  reverse(StrShort.begin(),StrShort.end()); // Переворачиваем строки, чтобы найти все начальные позиции искомых подстрок в StrLong
reverse(StrLong.begin(),StrLong.end()); // the strings should be reversed now in order to find all start positions of required substrings of StrLong

for (unsigned int i = 1; (i< n); i++)
    for (unsigned int j = 1; (j< m); j++)

        {
            w=mismP;
            if(StrShort[i-1] == StrLong[j-1]) w=0;
            mt = B[i-1][j-1] + w;
            dt = B[i-1][j] + gapP;
            in = B[i][j-1] + gapP;

            B[i][j] = mt;
            if (B[i][j]<std::max(dt, in)) B[i][j] = std::max(dt, in);
        }

reverse(StrShort.begin(),StrShort.end());  // теперь переворачиваем строки назад
reverse(StrLong.begin(),StrLong.end()); // now the strings are reversed back


for (int i=0;i<m;i++)
    if(B[n-1][i]*(-1)<=D) // Условие того, что в данной точке будет начало одной или нескольких искомых подстрок (с поправкой на реверс)
                          // This means that here will be the beginning for one or more required substrings (reverse adjusted)
    {
        StartPositions.insert(StrLong.length()-i+1);  // Computing the starting position ("1"-based indexing)

    }


int l;




for (auto it = StartPositions.begin(); it!=StartPositions.end(); it++)
    // Для каждой найденной точки начала подстврок вычисляем l - максимально возможную длину искомой подстроки, которая не может быть более длины короткой строки плюс D, и при этом не может выходить за границу длинной строки.
    // Let's compute "l" for every starting position. "l" means the maximal possible length for the required substring (<= StrShort.length+D, but within StrLong).
{

    l=-1;
    if ((*it+L+D-1)<=StrLong.length()) l=L+D;
    else if (*it+L-D-1<=StrLong.length()) l=StrLong.length()-*it+1;



    if (l>0) // If so - lets do Edit Distance Alignment between TempS and StrShort in order to find prefixes of TempS, that require the statement of problem to be solved by the function FindMutatedRepeatsED.
    {
        TempS = StrLong.substr(*it-1, l);
        EDistForFindMR(TempS, StrShort, D, L, l, *it, Result);
    }


}


return 0;

}


int SuffixTreeMake (const std::string &DataS, std::vector <int> & Tree, int b=1)
// Suffix Tree constructing upon a string DataS. If DataS is empty returns -1, if success returns 0.
// Suffix Tree will be contained in the vector Tree, every edge as quartet of integers:
// number of tne start-vertex of edge, number of end-vertex of edge, starting position of substring in DataS, the length of this substring.
// "b" sets the number to start numerating of vertices of suffix tree.
// Построение сууфиксного дерева Tree по строке DataS. Возвращает -1, если длина строки <1, в случае успеха вернет 0.
// Суффиксное дерево возвращается в виде вектора Tree, представленного в виде квартетов чисел:
// номер вершины-начала ребра, номер вершины-конец ребра, стартовая позиция подстроки в строке DataS, ее (подстроки) длина.
// параметр b задает, с какого номера будут нумероваться вершины в суффиксном дереве.

{
    Tree.clear(); // Here Suffix Tree will be contained.
    // Здесь будет само дерево

    if (DataS.length()<1) return -1; // Function works only for non-empty strings.


    std::string TempS = DataS;

    Tree.reserve(4*DataS.length());

    Tree.push_back(b);
    Tree.push_back(b+1);
    Tree.push_back(0);
    Tree.push_back(DataS.length());

    int last = b+1; //последняя добавленная вершина
    int ind=b; //с которого прикладываем
    int l=0;
    int count=0;
    int sink=-1;
    int f=0;

    for (int i=1; i<DataS.length(); i++)
    {

        TempS=DataS.substr(i, DataS.length()-i);

        count=0; // сколько символов уже отсчитали по TempS
        ind=b;
        l=0; // сколько символов отсчитали от очередного узла ind
        sink=-1;


        l2:;
        f=0;

        for (int j=0; j<Tree.size(); j=j+4)
        {
            l1: ;
            if (count>=TempS.length())
                break;


            if ((Tree[j]==ind)&&(TempS[count])==DataS[l+Tree[j+2]])
            {
                f=1;
                if(l<Tree[j+3])
                {
                    l++;
                    count++;
                    sink = Tree[j+1];

                }

                if(l>=Tree[j+3])
                {
                    ind = Tree[j+1];
                    sink=-1;
                    l=0;
                    goto l2;
                }

                goto l1;

            }

            if (f==1) break;

        }


        if (count==0)
        {
            Tree.push_back(b);
            Tree.push_back(last+1);
            last++;
            Tree.push_back(i);
            Tree.push_back(TempS.length());

        }

        if ((count>0)&&(count<=TempS.length()))
        {
            if (sink==-1)
            {

                Tree.push_back(ind);
                Tree.push_back(last+1);
                last++;
                Tree.push_back(i+count);
                Tree.push_back(TempS.length()-count);

            }
            if (sink!=-1)
            {

                for (int j=0; j<Tree.size(); j=j+4)
                     if ((Tree[j]==ind)&& (Tree[j+1]==sink))
                     {
                         Tree.push_back(ind);
                         Tree.push_back(last+1);
                         last++;
                         Tree.push_back(Tree[j+2]);
                         Tree.push_back(l);

                         Tree.push_back(last);
                         Tree.push_back(sink);

                         Tree.push_back(Tree[j+2]+l);
                         Tree.push_back(Tree[j+3]-l);


                         Tree[j] = last;
                         Tree[j+1] = last+1;
                         last++;
                         Tree[j+2] = i+count;
                         Tree[3+j] = TempS.length()-count;

                     }
             }

        }

    }


   return 0;
}




int CoutSuffixTree (const std::vector <int> & Tree, const std::string DataS, bool tree=true, bool strings = true)
// "Couts" the suffix tree set by Tree (its format see at SuffixTreeMake' s description). The string itself is set by DataS.
// No checking of input data correctness is here.
// If "tree" = true couts every 4 numbers  that set each edge of the tree in line.
// If "strings" = true couts every substring that relevant to each edge in line.

// Выводит на экран суффиксное дерево, заданное вектором числе в порядке, указанном в описании функции SuffixTreeMake. Сама строка задается DataS. Проверка корректности исходных данных не проводится.
// Если "tree" = true, выводит по каждому ребру квартет чисел, его задающих (каждый квартет - вновой строке).
// Если "strings" = true, выводит по каждому ребру соотвествующую ему подстроку из строки DataS

{
    if (Tree.size()%4 != 0) return -1;

    for (int i=0; i<Tree.size(); i=i+4)
    {
        if (tree==true)
            std::cout<<Tree[i]<<" "<<Tree[i+1]<<" "<<Tree[i+2]<<" "<<Tree[i+3]<<std::endl;
        if (strings==true)
            std::cout<<DataS.substr(Tree[i+2], Tree[i+3])<<std::endl;

    }
    return 0;
}


int FoutSuffixTree (const std::vector <int> & Tree, const std::string DataS, std::ofstream &fout, bool tree=true, bool strings = true)
// "Fouts" the suffix tree set by Tree (its format see at SuffixTreeMake' s description). The string itself is set by DataS.
// No checking of input data correctness is here.
// If "tree" = true couts every 4 numbers  that set each edge of the tree in line.
// If "strings" = true couts every substring that relevant to each edge in line.

// Выводит в файл суффиксное дерево, заданное вектором числе в порядке, указанном в описании функции SuffixTreeMake. Сама строка задается DataS. Проверка корректности исходных данных не проводится.
// Если "tree" = true, выводит по каждому ребру квартет чисел, его задающих (каждый квартет - вновой строке).
// Если "strings" = true, выводит по каждому ребру соотвествующую ему подстроку из строки DataS

{
    if (Tree.size()%4 != 0) return -1;

    for (int i=0; i<Tree.size(); i=i+4)
    {
        if (tree==true)
            fout<<Tree[i]<<" "<<Tree[i+1]<<" "<<Tree[i+2]<<" "<<Tree[i+3]<<std::endl;
        if (strings==true)
            fout<<DataS.substr(Tree[i+2], Tree[i+3])<<std::endl;
    }
    return 0;
}


int PartitionOfNumber (std::vector <std::vector <int>> &B, int n)
// Генерирует разбиения числа на слагаемые для чисел больше 0 (иначе вернет -1). Результат генерируется в векторе векторов B.
//Generates partitions of int n (i.e. representing n as a sum of positive integers) in B. If n<=0 returns empty B and "-1"

{
    B.clear();

    if (n<=0) return -1;
    int t,y;
    std::vector <int> T (n, 1);

    while (true)
    {
        B.push_back(T);

        if (T[0]==n) break;
        if (T.size()==1) break;
        t=T[T.size()-2];
        for (int i=T.size()-2; i>=0; i--)
        {
            if (T[i]>t) {y=i+1; break;}

            y=i;
        }




        T[y]++;
        T[T.size()-1]--;
        if (T[T.size()-1]==0) T.pop_back();

        t=T.size();
        for (int z= y+1; z<t; z++)
        {
            if (T[z]==1) continue;
            T[z]--;
            T.push_back(1);
            z--;
        }


    }

    return 0;
}


int PartitionOfNumberL (std::vector <std::vector <int>> &B, int n, int l=-1)
// Генерирует разбиения числа на слагаемые для чисел больше 0 (иначе вернет -1). Результат генерируется в векторе векторов B. Расширенная версия:
// можно задать длину разбиения l. Если l>0, то возвращаются только разбиения длиной l. При этом более короткие разбиения "добиваются справа" нулями.
//Generates partitions of int n (i.e. representing n as a sum of positive integers) in B. Extended version: one may set l>0 as a length of patritions (i.e. number of summands).
// In this case "0" will be added to the end of the shorter partitions. If n<=0 returns empty B and "-1"


{
    B.clear();

    if (n<=0) return -1;
    int t,y;
    std::vector <int> T (n, 1); // starting partition has only ones as summands

    if (l<=0) l=n;  // If l<=0 (as set by default) partitions will have n summands

    while (true)
    {


        if (T.size()<=l)  // Testing if the length of patrition is <=l
            B.push_back(T); // and adding it if it is
        if (T.size()<l) // adding zeros if needed
            for (int e=0; e<l-T.size(); e++)
                B[B.size()-1].push_back(0);


        if (T[0]==n) break; // the last partition is the number n itself
        //if (T.size()==1) break;
        t=T[T.size()-2];
        for (int i=T.size()-2; i>=0; i--)
        {
            if (T[i]>t) {y=i+1; break;}

            y=i;
        }




        T[y]++; // transferring 1 to this summand (y-summand)
        T[T.size()-1]--; //from this summand
        if (T[T.size()-1]==0) T.pop_back();  // deleting it if became 0

        t=T.size();
        for (int z= y+1; z<t; z++) // now representing all the summands after y-summand as a sum of ones only
        {
            if (T[z]==1) continue;
            T[z]--;
            T.push_back(1);
            z--;
        }


    }

    return 0;
}



bool CompStrDLO (const std::string & s1, const std::string & s2)  //Comparing function for arranging an array (vector) of strings in descending length order / Компаратор для сортировки строк по убыванию длин
{

  return s1.length() > s2.length();

}


std::string ShortSuperstringGr (std::vector <std::string> DataS)
// Generates shortest superstring of an array (vector) of strings DataS via implementing greedy algorithm. In doing so, every string that is a substring of any another one of DataS is to be excluded.
// DataS is copied (not linked) here as it will be changed here.
// Returns empty string if DataS is empty or all strings of DataS are empty.
// Применен "жадный алгоритм" поиска наименьшей надстроки. При этом из рассмотрения исключаются строки, являющиеся подстроками других строк DataS.
// Исходные данные DataS копируются, а не привязываются по ссылке, т.к. DataS будет изменяться в процессе работы функции
// Возвращается пустая строка, если DataS - пустой или содержит только пустые строки.


{

    if (DataS.size()==0) return "";

    for (int y=0; y<DataS.size(); y++)  // deleting empty strings
    {
        if (DataS[y]=="")
        {
         DataS.erase(DataS.begin()+y);
         y--;
        }
    }

    if (DataS.size()==0) return "";
    if (DataS.size()==1) return DataS[0];

    std::sort (DataS.begin(), DataS.end(), CompStrDLO);


    for (int z=0; z<DataS.size()-1;z++)      // deleting every string that is a substring of any another one
        {
            for (int zz=z+1; zz<DataS.size();zz++)
                if (DataS[z].find(DataS[zz])!=-1)
                {
                    DataS.erase(DataS.begin()+zz);
                    zz--;
                }
        }


    if (DataS.size()==1) return DataS[0];


    std::vector <std::vector <int>> Arrow;   // A matrix to contain overlap value between strings i and j
    Arrow.clear();
    MatrixSet (Arrow, DataS.size(), DataS.size(), 0); // Заготовка матрицы величин "перекрытий" между строками i и j

    // и ее заполнение величинами перекрытий: конца строки i и начала строки j
    // Filling the matrix Arrow with overlap value of end of i th and begin of j-th strings

    int npos=0;
    int l1, l2;

       for (unsigned int i = 0; (i<DataS.size()); i++)
            for (unsigned int j = 0; (j<DataS.size()); j++)
            {
                l1 = DataS[i].length() ;
                l2 = DataS[j].length() ;
                npos=0;
                if (l1 > l2) npos = (l1-l2);

                if (npos==0)
                {
                     for (int y=0; y<l1; y++)
                        if ((DataS[i].substr(y, l1-y) == DataS[j].substr(0, l1-y)) && (i!=j))
                        {Arrow [i] [j] = (l1-y); break;}

                }

                if (npos>0)
                {
                     for (int y=0; y<l2; y++)
                        if ((DataS[i].substr(npos+y, l1-y-npos) == DataS[j].substr(0, l1-y-npos)) && (i!=j))
                        {Arrow [i] [j] = (l1-y-npos); break;}

                }

            }
       //конец создания заполненной матрицы перекрытий
       //end of Arrow filling


        std::string Result = ""; //here result string will be
        std::string TempS;

       int mx = -1;
       int b, e;

       for (int t = 0; t<DataS.size()-1; t++)
       {
           TempS.clear();

           mx = 0;
           for (unsigned int i = 0; (i<DataS.size()); i++)    // ищем максимум mx в 2-мерном массиве и его индексы b & e
                for (unsigned int j = 0; (j<DataS.size()); j++)  // searching for maximum of mx (i.e. overlap value), for such maximum indexes of overlapping strings in DataS will be b and e.
                    if ((i!=j) && (Arrow [i] [j] >= mx)) {mx = Arrow [i] [j]; b = i; e=j;}


           TempS = DataS[b].substr(0, DataS[b].length() - mx) + DataS[e]; //это - склейка соотвествующих строк /Glueing of overlapping strings

           DataS[b] = TempS; //теперь ее пишем вместо b-й строки, дальше перестроим наш двумерный массив / and this new glued string shold be write instead of b-th string

           for (unsigned int ii = 0; (ii<DataS.size()); ii++)
                Arrow [ii] [e] = -1;  //"обнуляем" столбец e - в строку e слева не войдет больше ни одна строка / switching off e-th coloumn


           for (unsigned int jjj = 0; (jjj<DataS.size()); jjj++)
                {Arrow [b] [jjj] = Arrow [e] [jjj];  //строку  e - в строку b, строку e обнулить (теперь выходит все из b) / copying row e to b, switching off e-th row
                Arrow [e] [jjj] = -1;}

       }

       Result = TempS;

       return Result;

}





int TrieMake (std::vector <std::string> &DataS, std::vector <int> & Trie)
// Trie constructing upon vector of strings DataS
// Построение префиксного дерева Trie по массиву строк DataS

{
    Trie.clear(); // Here Trie will be contained as a number of triplets of integers (a = Trie [3i], b = Trie [3i+1], c = Trie [3i+2], i = 0, 1, ...). Each triplet means an edge a->b marked with symbol (char) c. Vertices in the Tree are numerated starting with "1".
    // Здесь будет само дерево в виде набора триплетов чисел. Первые два задают ребро графа, а третье - соотвествующий символ (букву). Вершины графа нумеруются с 1.

    if (DataS.size()<2) return -1; // Function works for at least 2 strings


    std::string TempS = "";

    sort (DataS.begin(), DataS.end(), CompStrDLO);

    int last = 0;
    int ind, l;


    for (int i=0;i<DataS[0].length();i++)   // формирование графа по 1 строке / Pushing to Trie the first (the longest) string from dataset
     {
         Trie.push_back(i+1);
         Trie.push_back(i+2);
         Trie.push_back( (int)DataS[0][i]  );
         last = (i+2);  // сохраняем номер последней (наибольшей) вершины / number of the very last vertex added (i.e. the maximal vertex number at any time)
     }





     for (int j=1;j<DataS.size();j++)  // добавляем остальные строки  / Pushing all the rest strings to Trie
     {


         TempS = DataS[j];
         ind = 1; // the number of vertex from which we are searching Trie for symbols matching (when matching is found "ind" will be the number of relevant sinr-vertex)/ с которой вершины ищем совпадающие символы (начинаем всегда с первой, затем, после добавления, берем вершину-сток из соответствующего ребра)
         l = 0; // counter of added symbols of every string being processed / счетчик добавленных символов по очередной строке

         lq: ;

         for (int q = 0; q<Trie.size(); q=q+3)  // searching Trie for symbols matching
         {
             if ((Trie[q]==ind)&&(Trie[q+2]==TempS[l]))
             {
                 ind = Trie[q+1];
                 l++;
                 if (l>=TempS.length()) // if the number of already added symbols = string's length, this means its adding to Trie is completed
                     goto lj;
                 goto lq; // if no - let us observe Trie from begining after adding another symbol

             }

         }

         for (int w = l; w<TempS.length(); w++) // if we haven't add all symbols of adding string at the previous step (searching Trie for symbols matching) - lets add the rest now
         {
             Trie.push_back(ind);
             Trie.push_back(last+1);
             ind = last+1;
             last = ind;
             Trie.push_back( (int)TempS[w]);

         }



         lj: ;
     }

   return 0;
}



void Num (std::string & Numbers, std::vector <double> & A)
{
    // перегон строки с числами <double> в массив (вектор) А
    // converts string of numbers <double> (separated by spaces) to a vector of numbers

    A.clear();

    int q = 0;  // удаление лишних пробелов если есть / deletind doubled spaces
    while (Numbers.find ("  ", q) != -1)
    {
        q = Numbers.find ("  ", q);
        Numbers.erase(q, 1);
    }

    while (Numbers[0] == ' ')  // deleting spaces from the very beginning (string must start from a number)
    {Numbers.erase(0, 1);}


    while (Numbers[Numbers.length()-1] == ' ')  // deleting spaces from the end
    {Numbers.erase((Numbers.length()-1), 1);}


    std::string TempS = "";
    int b=0; //начало каждого числа в строке  / The start position of a number
    int e=0; // конец числа в строке / the end position
    double r;  //сюда писать само число / a variable to contain a number
    while (Numbers.find (" ", b) != -1)  //число - до следующего пробела
    {
        e = Numbers.find (" ", b)-1;
        TempS = Numbers.substr(b, e-b+1);
         r = atof(TempS.c_str());
         A.push_back(r);

        b = e+2;
        TempS.clear();
    }

    TempS = Numbers.substr(b, Numbers.length()-b);  // еще одна итерация - от последнего пробела до конца строки / the last iteration - up to the string's end
    r = atof(TempS.c_str());
    A.push_back(r);
    TempS.clear();
}


void Num (std::string & Numbers, std::vector <long double> & A)
{
    // перегон строки с числами <long double> в массив (вектор) А
    // converts string of numbers <long double> (separated by spaces) to a vector of numbers

    A.clear();

    int q = 0;  // удаление лишних пробелов если есть / deletind doubled spaces
    while (Numbers.find ("  ", q) != -1)
    {
        q = Numbers.find ("  ", q);
        Numbers.erase(q, 1);
    }

    while (Numbers[0] == ' ')  // deleting spaces from the very beginning (string must start from a number)
    {Numbers.erase(0, 1);}


    while (Numbers[Numbers.length()-1] == ' ')  // deleting spaces from the end
    {Numbers.erase((Numbers.length()-1), 1);}


    std::string TempS = "";
    int b=0; //начало каждого числа в строке  / The start position of a number
    int e=0; // конец числа в строке / the end position
    long double r;  //сюда писать само число / a variable to contain a number
    while (Numbers.find (" ", b) != -1)  //число - до следующего пробела
    {
        e = Numbers.find (" ", b)-1;
        TempS = Numbers.substr(b, e-b+1);
         r = atof(TempS.c_str());
         A.push_back(r);

        b = e+2;
        TempS.clear();
    }

    TempS = Numbers.substr(b, Numbers.length()-b);  // еще одна итерация - от последнего пробела до конца строки / the last iteration - up to the string's end
    r = atof(TempS.c_str());
    A.push_back(r);
    TempS.clear();
}

void Num (std::string & Numbers, std::vector <int> & A)
{
    // перегон строки с числами int в массив (вектор) А
    // converts string of numbers <int> (separated by spaces) to a vector of numbers


    A.clear();

    int q = 0;  // удаление лишних пробелов / deleting doubled spaces
    while (Numbers.find ("  ", q) != -1)
    {
        q = Numbers.find ("  ", q);
        Numbers.erase(q, 1);
    }

    while (Numbers[0] == ' ')  // deleting spaces from the very beginning (string must start from a number)
    {Numbers.erase(0, 1);}


    while (Numbers[Numbers.length()-1] == ' ')  // deleting spaces from the end
    {Numbers.erase((Numbers.length()-1), 1);}

    std::string TempS = "";
    int b=0; //начало каждого числа в строке  / The start position of a number
    int e=0; // конец числа в строке / the end position
    int r;  //сюда писать само число / a variable to contain a number
    while (Numbers.find (" ", b) != -1)  //число - до следующего пробела
    {
        e = Numbers.find (" ", b)-1;
        TempS = Numbers.substr(b, e-b+1);
         r = atoi(TempS.c_str());
         A.push_back(r);

        b = e+2;
        TempS.clear();
    }

    TempS = Numbers.substr(b, Numbers.length()-b);  // еще одна итерация - от последнего пробела до конца строки / the last iteration - up to the string's end
    r = atoi(TempS.c_str());
    A.push_back(r);
    TempS.clear();
}



void Num (std::string & Numbers, std::vector <long long int> & A)
{
    // перегон строки с числами long long int в массив (вектор) А
    // converts string of numbers <long long int> (separated by spaces) to a vector of numbers


    A.clear();

    int q = 0;  // удаление лишних пробелов / deleting doubled spaces
    while (Numbers.find ("  ", q) != -1)
    {
        q = Numbers.find ("  ", q);
        Numbers.erase(q, 1);
    }

    while (Numbers[0] == ' ')  // deleting spaces from the very beginning (string must start from a number)
    {Numbers.erase(0, 1);}


    while (Numbers[Numbers.length()-1] == ' ')  // deleting spaces from the end
    {Numbers.erase((Numbers.length()-1), 1);}

    std::string TempS = "";
    int b=0; //начало каждого числа в строке  / The start position of a number
    int e=0; // конец числа в строке / the end position
    long long int r;  //сюда писать само число / a variable to contain a number
    while (Numbers.find (" ", b) != -1)  //число - до следующего пробела
    {
        e = Numbers.find (" ", b)-1;
        TempS = Numbers.substr(b, e-b+1);
         r = atoi(TempS.c_str());
         A.push_back(r);

        b = e+2;
        TempS.clear();
    }

    TempS = Numbers.substr(b, Numbers.length()-b);  // еще одна итерация - от последнего пробела до конца строки / the last iteration - up to the string's end
    r = atoi(TempS.c_str());
    A.push_back(r);
    TempS.clear();
}



void Num (std::string & Numbers, std::vector <short int> & A)
{
    // перегон строки с числами short int в массив (вектор) А
    // converts string of numbers <short int> (separated by spaces) to a vector of numbers


    A.clear();

    int q = 0;  // удаление лишних пробелов / deleting doubled spaces
    while (Numbers.find ("  ", q) != -1)
    {
        q = Numbers.find ("  ", q);
        Numbers.erase(q, 1);
    }

    while (Numbers[0] == ' ')  // deleting spaces from the very beginning (string must start from a number)
    {Numbers.erase(0, 1);}


    while (Numbers[Numbers.length()-1] == ' ')  // deleting spaces from the end
    {Numbers.erase((Numbers.length()-1), 1);}

    std::string TempS = "";
    int b=0; //начало каждого числа в строке  / The start position of a number
    int e=0; // конец числа в строке / the end position
    short int r;  //сюда писать само число / a variable to contain a number
    while (Numbers.find (" ", b) != -1)  //число - до следующего пробела
    {
        e = Numbers.find (" ", b)-1;
        TempS = Numbers.substr(b, e-b+1);
         r = atoi(TempS.c_str());
         A.push_back(r);

        b = e+2;
        TempS.clear();
    }

    TempS = Numbers.substr(b, Numbers.length()-b);  // еще одна итерация - от последнего пробела до конца строки / the last iteration - up to the string's end
    r = atoi(TempS.c_str());
    A.push_back(r);
    TempS.clear();
}


int Num (std::string & Numbers, int &a1,int &a2, double &a3)
// Вспомогательная функция: перегон строки, содержащей 3 числа, разделенных пробелами (пара целых, задающих вершины ребра и одного double) соответственно в int a1,int a2, double a3. Числа должны быть разделены пробелами, а более ничего строка содержать не должна.
// Возвращает -1 если выявлена ошибка исходных данных (нет 3х "кандидатов в числа").
// При этом проверка на то, что конвертируемая в число подстрока содержит лишь цифры и десятичный разделитель, в данной версии функции НЕ проводится.
// Converts a string to 3 numbers (2 integers and 1 double; they should be separated by spaces in the string and the string should not contain any other symbols) to int &1,int a2, double a3.
// Returns -1 if input data is incorrect (no 3 "candidates to numbers" are found).
// But note that here is NO checking if a substring to be converted to a number contains digits and decimal point only.


{

    int q = 0;  // удаление лишних пробелов если есть / deletind doubled spaces
    while (Numbers.find ("  ", q) != -1)
    {
        q = Numbers.find ("  ", q);
        Numbers.erase(q, 1);
    }

    while (Numbers[0] == ' ')  // deleting spaces from the very beginning (string must start from a number)
    {Numbers.erase(0, 1);}


    while (Numbers[Numbers.length()-1] == ' ')  // deleting spaces from the end
    {Numbers.erase((Numbers.length()-1), 1);}


    std::string TempS = "";
    int b=0; //начало каждого числа в строке  / The start position of a number
    int e=0; // конец числа в строке / the end position

    e = Numbers.find (" ", b)-1; //reading the first int - i.e. the first vertex of an edge
    if (e<0) return -1;
    TempS = Numbers.substr(b, e-b+1);

    a1 = atoi(TempS.c_str());
    b = e+2;TempS.clear();


    e = Numbers.find (" ", b)-1; //reading the second int - i.e. the second vertex of an edge
    if (e<0) return -1;
    TempS = Numbers.substr(b, e-b+1);

    a2 = atoi(TempS.c_str());
    b = e+2;TempS.clear();


    if (b>=Numbers.length()) return -1; // in this case string does not contain the 3th number

    e = Numbers.find (" ", b)-1;

    if (e<0) //There are no more " "
    {
        TempS = Numbers.substr(b, Numbers.length()-b);
        a3 = atof(TempS.c_str());
    }


    return 0;
}


void Num (std::string & Numbers, std::vector <std::string> & A)
{
// Modification of "Num"-functions (see them above) for strings.
// Converts string that consists of some strings (separated by spaces) to a vector of strings
// Модификация функций семейства Num (см. выше) для строк: Перегон строки со строками, разделенными пробелами, в массив (вектор) строк А.


    A.clear();

    int q = 0;  // deleting doubled spaces
    while (Numbers.find ("  ", q) != -1)
    {
        q = Numbers.find ("  ", q);
        Numbers.erase(q, 1);
    }

    while (Numbers[0] == ' ')  // deleting spaces from the very beginning
    {Numbers.erase(0, 1);}


    while (Numbers[Numbers.length()-1] == ' ')  // deleting spaces from the end
    {Numbers.erase((Numbers.length()-1), 1);}

    std::string TempS = "";
    int b=0; // The start position of a string
    int e=0; // the end position

    while (Numbers.find (" ", b) != -1)  //строка - до следующего пробела
    {
        e = Numbers.find (" ", b)-1;
        TempS = Numbers.substr(b, e-b+1);

         A.push_back(TempS);

        b = e+2;
        TempS.clear();
    }

    TempS = Numbers.substr(b, Numbers.length()-b);  // еще одна итерация - от последнего пробела до конца строки / the last iteration - up to the string's end

    A.push_back(TempS);
    TempS.clear();
}


int ScoreStringMatrix (const std::vector <std::string> &s)
// Returnes a score (i.e. total number of mismatches) upon vector of strings s. If input data is incorrect returns 0.
// Возвращает суммарное количество всех несовпадений символов по каждой позиции по набору строк s. Если данные некорректны вернет -1.

{
    if (s.size()==0) return -1;
    if (s[0].length()==0) return -1;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i].length()!=s[0].length()) return -1;
    }

    int r = 0;
    for (int j=0; j<s[0].length();j++)
        for (int i=0; i<s.size(); i++)
            for (int x= i; x<s.size(); x++)
                if (s[x][j]!=s[i][j])
                    r++;

    return r;


}


int UWGraphRead (std::ifstream & fin, std::vector <int> & A)
// Чтение невзвешенного графа в вектор смежности.
// Назовем вектором смежности для взвешенного графа упорядоченный набор (массив) четного кол-ва чисел (а[2i], a[2i+1],... / i нумеруется c 0 /),
// где каждая пара чисел а[2i], a[2i+1] задает ребро графа между вершинами а[2i] и a[2i+1] ("список ребер в строку").
// Данный формат не содержит информации, является ли граф ориентированным или нет (возможны оба варианта). При использовании формата для орграфа считается, что ребро направлено из а[2i] в a[2i+1].
// Предполагается считывание из файла, содержащего список ребер (каждое ребро - отдельная строка)
// Возвращает -1 и пустой вектор A, если полученный вектор смежности пустой или же при считывании очередного ребра считано не 2 элемента (числа)

// Reads Edge list to "Adjacency vector" of unweighted graph. Let "Adjacency vector" of unweighted graph be a data structure,
// that contains array of integers such as а[2i], a[2i+1],... / 0-basing indexing in array /.
// So such array contains even number of elements. Every pair а[2i], a[2i+1] means an edge between vertex а[2i] and а[2i+1] (~ "Edge list as one String").
// This format don't identify the graph as directed or undirected (both cases may be). If the graph is considered as directed, its edges should be considered as а[2i] -> a[2i+1].
// Input file should be in edge list format, every edge in new line.
// Returns -1 and empty "Adjacency vector" A if any line contains number of elements that !=2.


{
    std::string TempS = "";
    A.clear();
    std::vector <int> B1;

    while (!fin.eof())
    {
        B1.clear();
        getline (fin, TempS);
        if (TempS.length()!=0)
        {
             Num(TempS, B1);
             if (B1.size()!=2) {A.clear(); return -1;}
             A.push_back(B1[0]);
             A.push_back(B1[1]);
        }
    }

    if (A.size()==0) return -1;

    return 0;
}




int WGraphRead (std::ifstream & fin, std::vector <int> & A)
// Чтение взвешенного графа в вектор смежности. Назовем вектором смежности для взвешенного графа упорядоченный набор (массив) чисел (а[3i], a[3i+1], a[3i+2],... / i нумеруется c 0 /), где каждая тройка чисел а[3i], a[3i+1] задает ребро графа между вершинами а[3i] и a[3i+1], а a[3i+2] есть вес этого ребра, ("список ребер в строку").
// Рассматриваемый формат не содержит информации, является граф ориентированным или нет (возможны оба варианта). При использовании формата для орграфа считается, что ребро направлено из а[3i] в a[3i+1].
// Данная структура данных занимает меньше памяти, чем матрица смежности, и может быть удобна для решения ряда задач.
// Предполагается считывание из файла, содержащего список смежности (каждое ребро - отдельная строка)
// Возвращает -1 и пустой вектор A, , если полученный вектор смежности пустой или же при считывании очередного ребра считано не 3 элемента (числа)

// Reads Edges list to "Adjacency vector" of weighted graph. Let "Adjacency vector" of weighted graph be a data structure, that contains array of integers such as а[3i], a[3i+1], a[3i+2],... / 0-basing indexing in array /.
// So such array contains 3n number of elements. Every pair а[3i], a[3i+1] means an edge between vertex а[3i] and а[3i+1] with weight a[3i+2]("Edge list as one String").
// This format don't identify the graph as directed or undirected (both cases may be). If the graph is considered as directed, its edges should be considered as а[3i] -> a[3i+1].
// Input file should be in edge list format, every edge in new line.
// Returns -1 and empty "Adjacency vector" A if any line contains number of elements of any line that !=3.


{
    std::string TempS = "";
    A.clear();
    std::vector <int> B1;

    while (!fin.eof())
    {
        B1.clear();
        getline (fin, TempS);
        if (TempS.length()!=0)
        {
             Num(TempS, B1);
             if (B1.size()!=3) {A.clear(); return -1;}
             A.push_back(B1[0]);
             A.push_back(B1[1]);
             A.push_back(B1[2]);
        }
    }

    if (A.size()==0) return -1;

    return 0;
}




int WGraphRead (std::ifstream & fin, std::pair < std::vector<int>, std::vector<double>> & A)
// Модификация функции WGraphRead (см. выше) для случая нецелочисленных весов ребер (double).
// Чтение проводится в пару векторов pair < std::vector<int>, std::vector<double>> & A, где первый вектор является вектором смежности считываемого графа без указания весов,
// а второй вектор содержит соотвествующие веса. Соотвественно для ребра задаваемого парой вершин под индексами 2*i, 2*i+1 первого вектора вес будет равен элементу под индексом i второго вектора.

// Modification of the function WGraphRead (see it above) for not-integer (double) weihgts of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weigths are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.


{
    std::string TempS = "";
    (A.first).clear();
    (A.second).clear();

   int a1, a2;
   double a3;


    while (!fin.eof())
    {
        getline (fin, TempS);
        if (TempS.length()!=0)
        {
             if (Num(TempS, a1, a2, a3)==-1)
             {
                 (A.first).clear();
                 (A.second).clear();
                 return -1;
             }

             if (Num(TempS, a1, a2, a3)==0)
             {
                (A.first).push_back(a1);
                (A.first).push_back(a2);
                (A.second).push_back(a3);


             }
        }
    }

    if ((A.first).size()==0) return -1;

    return 0;
}





int RangeVGraph (const std::vector <int> & A, int & mx, int & mn, const bool weighted, bool IgnoreWeighted = false)
//Finds max (i.e. mx) and min (i.e. mn) value of numbers that assigned to vertices
// Graph must be set as "Adjacency vector", bool "weighted" sets if the graph is weighted or no.
// If (IgnoreWeighted = true) the function looks at every element in A without any dataset checking
{

    mn = INT_MAX;
    mx = INT_MIN;

    if (A.size()==0) return -1;

    if (IgnoreWeighted == false)
    {
    if ( (A.size())%(2+weighted)!=0 ) return -1;

    for (int q=0; q<A.size()-1-weighted; q= q+2+weighted)
    {
        if (A[q]>mx) mx = A[q];
        if (A[q+1]>mx) mx = A[q+1];

        if (A[q]<mn) mn = A[q];
        if (A[q+1]<mn) mn = A[q+1];
    }

    }

    if (IgnoreWeighted == true)
    {
        for (int q=0; q<A.size(); q++)
        {
            if (A[q]>mx) mx = A[q];
            if (A[q]<mn) mn = A[q];
        }

    }

    return 0;
}




int RenumVGraph (std::vector <int> & A, const int d, const bool weighted, bool IgnoreWeighted = false)
//Renumerates vertices adding d-parameter (d may be non-negative or negative) / Перенумеровывавает вершины графа: прибавляет величину d (может быть положительной и отрицательной)
// Graph must be set as "Adjacency vector", bool "weighted" sets if the graph is weighted or no.
// If (IgnoreWeighted = true) the function adds d to every element in A without any dataset checking


{

    if (A.size()==0) return -1;

    if (IgnoreWeighted == false)
    {
        if ( (A.size())%(2+weighted)!=0 ) return -1;

        for (int q=0; q<A.size()-1-weighted; q= q+2+weighted)
        {
            A[q] = A[q]+d;
            A[q+1] = A[q+1]+d;
        }
    }

    if (IgnoreWeighted == true)
    {
        for (int q=0; q<A.size(); q++)
        {
            A[q] = A[q]+d;

        }

    }



    return 0;
}





int AdjVector2AdjMatrix (std::vector <int> & A, std::vector <std::vector <int>> &B, const bool weighted, const bool directed)
//Converts "Adjacency vector" to "Adjacency matrix".
// bool "weighted" sets if the graph is weighted or no. bool "directed" sets if the graph is directed or no.
// In case of multiple edges for a weighted graph only the last edge will be written to Adjacency matrix, others will be lost.
// Loops for undirected unweighted graph counts as 2 edges
// In this function zero-value of any item of Adjacency matrix means no edge both for unweighted and weighted graph

{

    B.clear();
    if (A.size()==0) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1;

    int mx, mn;

    RangeVGraph (A, mx, mn, weighted);

    if (mn<0) return -1;

    MatrixSet(B, mx+1, mx+1, 0);

    for (int q=0; q<A.size()-1-weighted; q= q+2+weighted)
    {
        if ( (weighted==false) && (directed==true) ) B[(A[q])][(A[q+1])]++;
        if ( (weighted==true) && (directed==true) ) B[(A[q])][(A[q+1])]= A[q+2];

        if ( (weighted==false) && (directed==false) ) {B[(A[q])][(A[q+1])]++; B[(A[q+1])][(A[q])]++;}
        if ( (weighted==true) && (directed==false) ) {B[(A[q])][(A[q+1])]= A[q+2]; B[(A[q+1])][(A[q])]= A[q+2];}

    }
    return 0;
}



int AdjVector2AdjMatrix (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <std::vector <double>> &B, const bool directed)
// Modification of the function AdjVector2AdjMatrx (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.
// Note that undirected graph may have only zeros lower than the Main diagonal of its Adjacency matrix here

{
    B.clear();
    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;

    int mx, mn;

    RangeVGraph (A.first, mx, mn, false);

    if (mn<0) return -1;

    MatrixSet(B, mx+1, mx+1, 0.0);

    for (unsigned int q=0; q<(A.second).size(); q++)
    {
        if ( directed==true ) B[((A.first)[2*q])][((A.first)[2*q+1])]= (A.second)[q];

        if (directed==false)
        {
            if ((A.first)[2*q]<=(A.first)[2*q+1]) B[(A.first)[2*q]][(A.first)[2*q+1]]= (A.second)[q];
            if ((A.first)[2*q]>(A.first)[2*q+1])  B[(A.first)[2*q+1]][(A.first)[2*q]]= (A.second)[q];
        }

    }

    return 0;
}



int AdjMatrix2AdjVector (std::vector <int> & A, const std::vector <std::vector <int>> &B, const bool weighted, const bool directed)
// Converts "Adjacency matrix" to "Adjacency vector".
// bool "weighted" sets if the graph is weighted or no. bool "directed" sets if the graph is directed or no.
// For a weighted graph here are no multiple edges.
// Loops for an undirected unweighted graph counts as 2 edges
// For an undirected graph the data that is lower than the Main diagonal of the matrix B is ignored
// In this function zero-value of any item of Adjacency matrix means "no such edge" both for unweighted and weighted graph


{

    A.clear();
    if (B.size()==0) return -1;

    for (int y=0; y<B.size(); y++)  // lets test: if the matrix B is a "square"
        if (B.size()!=B[y].size()) return -1; // тест на квадратность


    int t;
    int c = 0;

    for (int i=0; i<B.size(); i++)
    {
        if (directed==false) c = i;
        for (int j=c; j<B.size(); j++) // for undirected graph lets see only not lower than Main diagonal
        {
            t = B[i][j];
            if (t==0) continue;

            if ( (weighted==false)&&(directed==true)  )
            {
                if (t<0) {A.clear(); return -1;}

                for (int x = 0; x<t; x++)
                {
                    A.push_back(i);
                    A.push_back(j);
                }
            }

            if ( (weighted==true)&&(directed==true)  )
            {
                    A.push_back(i);
                    A.push_back(j);
                    A.push_back(t);
            }


            if ( (weighted==false)&&(directed==false)  )
            {
                if (t<0) {A.clear(); return -1;}

                if ((i==j) && ((t%2)!=0) )  {A.clear(); return -1;} // Loops for undirected unweighted graph counts as 2 edges
                if ((i==j)) t = t/2;



                for (int x = 0; x<(t); x++)
                {
                    A.push_back(i);
                    A.push_back(j);
                }

            }

            if ( (weighted==true)&&(directed==false)  )
            {
                A.push_back(i);
                A.push_back(j);
                A.push_back(t);
            }


        }

    }

    return 0;
}



int AdjMatrix2AdjVector (std::pair < std::vector<int>, std::vector<double>> & A, const std::vector <std::vector <double>> &B, const bool directed)
// Modification of the function AdjMatrix2AdjVector (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.
// For an undirected graph the data that is lower than the Main diagonal of the matrix B is ignored

{

    (A.first).clear();
    (A.second).clear();

    if (B.size()==0) return -1;

    for (unsigned int y=0; y<B.size(); y++)  // lets test: if the matrix B is a "square"
        if (B.size()!=B[y].size()) return -1; // тест на квадратность


    double t;
    int c = 0;

    for (int i=0; i<B.size(); i++)
    {
        if (directed==false) c = i;
        for (int j=c; j<B.size(); j++) // for undirected graph lets see only not lower than Main diagonal
        {
            t = B[i][j];
            if (t==0.0) continue;


            if (directed==true)
            {
                    (A.first).push_back(i);
                    (A.first).push_back(j);
                    (A.second).push_back(t);
            }


            if (directed==false)
            {

                (A.first).push_back(i);
                (A.first).push_back(j);
                (A.second).push_back(t);
            }
        }
    }

    return 0;
}



int AdjVectorToAdjMap (const std::vector <int> &A, std::map <std::pair < int, int> , int> &G2, const bool weighted, const bool directed = true)
// Converts Adjacency vector A to Adjacency map G2. Multiple edges will be joined together.
// Parameter "weighted" sets if the graph A is weighted or no. Weights may be only integers. If A is unweighted we consider that every edge have its weight = 1.
// Parameter "directed" sets if the graph A is directed or no. For undirected graph numers of nodes of every edge will be written to G2 in increasing order.
// Returns -1 if input data is not correct. Otherwise returns 0.
// Конвертирует Вектор смежности A в ассоциативный массив смежности G2. Множественные ребра будут объединены с суммарным весом. Для невзвешенного графа считаем вес всех ребер = 1.
// Возвращает -1 в случае некорректности исходных данных.
// Параметр weighted задает, является ли граф взвешенным (Истина) или нет. Параметр directed задает, является ли граф ориентированным (Истина) или нет.
// Для неориентированных графов номера вершин каждого ребра будут записаны в G2 порядке возрастания.


{
    G2.clear();
    if (A.size()==0) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

    std::pair < int, int> C;
    std::pair < std::pair < int, int>, int> D;

    if (weighted)
    {
    for (int i=0; i<A.size(); i=i+3)
    {
        if (directed) C = std::make_pair(A[i], A[i+1]);
        if (!directed) C = std::make_pair(std::min(A[i], A[i+1]), std::max(A[i], A[i+1]));
        D = std::make_pair(C, A[i+2]);

        if (G2.find(C)!=G2.end())
        {G2[C] = G2[C]+A[i+2]; continue;}

        if (G2.find(C)==G2.end())
        {G2.insert(D); continue;}


    }

    }

    if (!weighted)
    {
    for (int i=0; i<A.size(); i=i+2)
    {
        if (directed) C = std::make_pair(A[i], A[i+1]);
        if (!directed) C = std::make_pair(std::min(A[i], A[i+1]), std::max(A[i], A[i+1]));
        D = std::make_pair(C, 1);

        if (G2.find(C)!=G2.end())
        {G2[C] = G2[C]+1; continue;}

        if (G2.find(C)==G2.end())
        {G2.insert(D); continue;}

    }

    }

    return 0;

}




int AdjVectorToAdjMap (const std::pair < std::vector<int>, std::vector<double>> & A, std::map <std::pair < int, int> , double> &G2, const bool directed = true)
// Converts Adjacency vector A to Adjacency map G2. Multiple edges will be joined together.
// Parameter "directed" sets if the graph A is directed or no. For undirected graph numbers of nodes of every edge will be written to G2 in increasing order.
// Returns -1 if input data is not correct. Otherwise returns 0.
// Конвертирует Вектор смежности A в ассоциативный массив смежности G2. Множественные ребра будут объединены с суммарным весом.
// Параметр directed задает, является ли граф ориентированным (Истина) или нет. Для неориентированных графов номера вершин каждого ребра будут записаны в G2 порядке возрастания.
// Возвращает -1 в случае некорректности исходных данных.

{
    G2.clear();

    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;


    std::pair < int, int> C;
    std::pair < std::pair < int, int>, double> D;


    for (int i=0; i<(A.second).size(); i++)
    {
        if (directed) C = std::make_pair((A.first)[i*2], (A.first)[2*i+1]);
        if (!directed) C = std::make_pair( std::min((A.first)[i*2], (A.first)[2*i+1]), std::max((A.first)[i*2], (A.first)[2*i+1]));

        D = std::make_pair(C, (A.second)[i]);

        if (G2.find(C)!=G2.end())
        {G2[C] = G2[C]+(A.second)[i]; continue;}

        if (G2.find(C)==G2.end())
        {G2.insert(D); continue;}

    }



    return 0;

}



int AdjMapToAdjVector (std::vector <int> &A, const std::map <std::pair < int, int> , int> &G1)
// Converts Adjacency map G1 to Adjacency vector A. A is considered as weighted, all weights are integers.
// Returns -1 if input data is not correct. Otherwise returns 0.
// Конвертирует Ассоциативный массив смежности G1 в вектор смежности А (только во взвешенный, веса целочисленны).
// Возвращает -1 в случае некорректности исходных данных.



{
    A.clear();
    if (G1.size()==0) return -1;
    for (auto it =G1.begin(); it!=G1.end(); it++)
    {
        A.push_back(  (it->first).first);
        A.push_back(  (it->first).second);
        A.push_back  (it->second);

    }

    return 0;
}



int AdjMapToAdjVector (std::pair < std::vector<int>, std::vector<double>> & A, const std::map <std::pair < int, int> , double> &G1)
// Converts Adjacency map G1 to Adjacency vector A. A is considered as weighted, all weights are double.
// Returns -1 if input data is not correct. Otherwise returns 0.
// Конвертирует Ассоциативный массив смежности G1 в вектор смежности А (только во взвешенный, веса имеют тип double).
// Возвращает -1 в случае некорректности исходных данных.


{
    (A.first).clear();
    (A.second).clear();
    if (G1.size()==0) return -1;
    for (auto it =G1.begin(); it!=G1.end(); it++)
    {
        (A.first).push_back(  (it->first).first);
        (A.first).push_back(  (it->first).second);
        (A.second).push_back  (it->second);

    }

    return 0;
}


int AdjVectorToAdjMegaMap (const std::vector <int> &A, std::map <std::pair < int, int> , std::vector<int> > &G2, const bool weighted, const bool directed = true)
// Converts Adjacency vector A to Adjacency mega-map G2.
// Adjacency mega-map is an extended version of Adjacency map (and it is built basing on std::map too) for containing graphs that have multiply loops and multiply edges.
// In doing so, the key value of the map is a pair of integers that sets edge(s) between them and the mapped value is a vector that contains weights of all edges between these vertices.
// Parameter "weighted" sets if the graph A is weighted or no. Weights may be only integers. If A is unweighted we consider that every edge have its weight = 1.
// Parameter "directed" sets if the graph A is directed or no. For undirected graph numers of nodes of every edge will be written to G2 in increasing order.
// Returns -1 if input data is not correct. Otherwise returns 0.
// Конвертирует Вектор смежности A в ассоциативный "мега-мап" G2. Для невзвешенного графа считаем вес всех ребер = 1.
// Мега-мап представляет собой ассоциативный массив смежности, предназначенный для хранения графов с множественными петлями и множественными ребрами.
// При этом ключом является пара чисел, задающих вершины ребер графа между ними, а значением - вектор весов для всех ребер между этими вершинами.
// Возвращает -1 в случае некорректности исходных данных.
// Параметр weighted задает, является ли граф взвешенным (Истина) или нет.
// Параметр directed задает, является ли граф ориентированным (Истина) или нет. Для неориентированных графов номера вершин каждого ребра будут записаны в G2 порядке возрастания.


{
    G2.clear();
    if (A.size()==0) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

    std::pair < int, int> C;
    std::vector <int> D;
    D.clear();

    if (weighted)
    {
    for (int i=0; i<A.size(); i=i+3)
    {

        if (directed) C = std::make_pair(A[i], A[i+1]);
        if (!directed) C = std::make_pair(std::min(A[i], A[i+1]), std::max(A[i], A[i+1]));

        if (G2.find(C)!=G2.end())
        {G2[C].push_back(A[i+2]); continue;}

        if (G2.find(C)==G2.end())
        {G2.insert(std::make_pair(C, D)); G2[C].push_back(A[i+2]); continue;}


    }

    }

    if (!weighted)
    {
    for (int i=0; i<A.size(); i=i+2)
    {

        if (directed) C = std::make_pair(A[i], A[i+1]);
        if (!directed) C = std::make_pair(std::min(A[i], A[i+1]), std::max(A[i], A[i+1]));

        if (G2.find(C)!=G2.end())
        {G2[C].push_back(1); continue;}

        if (G2.find(C)==G2.end())
        {G2.insert(std::make_pair(C, D)); G2[C].push_back(1); continue;}

    }

    }

    return 0;

}




int AdjVectorToAdjMegaMap (const std::pair < std::vector<int>, std::vector<double>> & A, std::map <std::pair < int, int> , std::vector<double> > &G2, const bool directed = true)
// Модификация функции AdjVectorToAdjMegaMap (см. выше) для случая нецелочисленных весов ребер графа.
// Modification of the function AdjVectorToAdjMegaMap (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.


{
    G2.clear();

    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;


    std::pair < int, int> C;
    std::vector <double> D;
    D.clear();


    for (int i=0; i<(A.second).size(); i++)
    {
        if (directed) C = std::make_pair((A.first)[i*2], (A.first)[2*i+1]);
        if (!directed) C = std::make_pair  (std::min((A.first)[i*2], (A.first)[2*i+1]), std::max((A.first)[i*2], (A.first)[2*i+1]));

        if (G2.find(C)!=G2.end())
        {G2[C].push_back((A.second)[i]); continue;}

        if (G2.find(C)==G2.end())
        {G2.insert(std::make_pair(C, D)); G2[C].push_back((A.second)[i]); continue;}

    }



    return 0;

}



int AdjMegaMapToAdjVector (std::vector <int> &A, const std::map <std::pair < int, int> , std::vector <int> > &G1)
// Converts Adjacency mega-map G1 to Adjacency vector A. A is considered as weighted, all weights are integers.
// Adjacency mega-map is an extended version of Adjacency map (and it is built basing on std::map too) for containing graphs that have multiply loops and multiply edges.
// In doing so, the key value of the map is a pair of integers that sets edge(s) between them and the mapped value is a vector that contains weights of all edges between these vertices.
// Returns -1 if input data is not correct. Otherwise returns 0.
// Конвертирует "мега-мап" G1 в вектор смежности А (только во взвешенный, веса целочисленны).
// Мега-мап представляет собой ассоциативный массив смежности, предназначенный для хранения графов с множественными петлями и множественными ребрами.
// При этом ключом является пара чисел, задающих вершины ребер графа между ними, а значением - вектор весов для всех ребер между этими вершинами.
// Возвращает -1 в случае некорректности исходных данных.



{
    A.clear();
    if (G1.size()==0) return -1;
    for (auto it =G1.begin(); it!=G1.end(); it++)
        if ((it->second).size()==0) return -1;

    for (auto it =G1.begin(); it!=G1.end(); it++)
        for (int j=0; j<(it->second).size(); j++)
    {
        A.push_back(  (it->first).first);
        A.push_back(  (it->first).second);
        A.push_back  ((it->second)[j]);

    }

    return 0;
}



int AdjMegaMapToAdjVector (std::pair < std::vector<int>, std::vector<double>> & A, const std::map <std::pair < int, int> , std::vector<double> > &G1)
// Модификация функции AdjMegaMapToAdjVector (см. выше) для случая нецелочисленных весов ребер графа.
// Modification of the function AdjVectorToAdjMegaMap (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.


{
    (A.first).clear();
    (A.second).clear();
    if (G1.size()==0) return -1;

    for (auto it =G1.begin(); it!=G1.end(); it++)
        if ((it->second).size()==0) return -1;

    for (auto it =G1.begin(); it!=G1.end(); it++)
        for (int j=0; j<(it->second).size(); j++)
    {
        (A.first).push_back(  (it->first).first);
        (A.first).push_back(  (it->first).second);
        (A.second).push_back  ((it->second)[j]);

    }

    return 0;
}



int CheckUnvisit (std::vector <int> & Visited) // Вспомогательная функция для поиска первой непомеченной вершины в графе
// An auxiliary function that finds the first unmarked vertex in the graph (0 means unmarked)

{
    int b = -1;

    for (unsigned int w = 0; w<Visited.size(); w++)
        if (Visited[w] ==0)   // ищем номер первой необойденной вершины
        {b=w; break;}

    return b;
}




void EcycleDGraph (int t, std::vector <int> & R, const int V, std::vector <std::vector<int>> &B)
// Вспомогательная функция для поиска Эйлерова цикла в ОРИЕНТИРОВАННОМ графе, где он заведомо существует, нет изолированных вершин и нумерация вершин идет с 1.
// B - матрица смежности, содержащая кол-во ребер между вершинами, V - максимальный номер вершины

// An auxiliary function that finds Eulerian cycle in the DIRECTED graph without without checking of input data correctness
//(i.e. (1) the graph includes Eulerian cycle, (2) its vertices numbers start from "1", (3) the graph doesn't contain any isolated vertices).
// B is the Adjacency matrix, containing the number of edges between the vertices. V is the max number assigned to vertices.



{

    int f = 1;

    while (f!=0)  // Строим начиная с вершины за номером t путь и вычеркиваем пройденные ребра // Building up the path from vertex № t
    {

        for (int i = 1; i<(V+1); i++)
        {
            if (B[t][i]>=1)
            {

            R.push_back(t);
            B [t][i]--; // ребро вычеркнули // deleting edge
            t = i; // дальше ищем со следующей вершины // tet's continue from the end vertex of the deleted edge
            goto l1;
            }

        }
        f = 0;

        l1: ;



    }

    std::vector <int> T;
    T.clear();

    if (R.size()!=0)  // а теперь ищем замкнутые циклы ("пузыри"), относящиеся к какой-либо вершине из уже построенного в R пути. И так рукуррентно ("пузырь" может содержать еще "пузырь" и т.д.)
        // Now we should search for cycles related to every vertex of the path in the vector R recurrently.

    {

    for (unsigned int j = 0; j<R.size(); j++)
    {
        T.clear();
        EcycleDGraph (R[j], T, V, B);

        if (T.size()!=0)  // И если такой "пузырь" есть // And if we have found such cycle
        {
        T.push_back(R[j]); // lets finish the cycle by pushing back R[j] - it is both its begin and its end.
        for (unsigned int w = (j+1); w<R.size(); w++) // And then lets add to it the rest of the path. So we have in T the Path with cycle related to R[j]-vertex added.
            T.push_back(R[w]); // Дополним его значением R[j] (это его и начало и конец) и затем присовокупим остаток пути из R. Это и будет изначальный путь, в который вставили путь по "пузырю" из вершины R[j]


        R.resize(j); // Теперь обновим сам R. Обрежем все, что дальше вершины R[j] и добавим вместо этого тоткорректированный путь из T
        for (unsigned int e = 0; e<T.size(); e++) // Now it is time to update R. Lets cut all that is further than R[j] and add updated path from T (it contains cycle related to R[j]-vertex now)
            R.push_back(T[e]);
        T.clear();

        }


    }

    }

}





int EPathDGraph (std::vector <int> & A, std::vector <int> & R, const bool weighted, std::vector <int> & Isolated)
// Поиск Эйлерова пути либо Эйлерова цикла в ОРИЕНТИРОВАННОМ графе. Принимает на вход вектор смежности графа с указанием, взвешенный ли граф, а также заготовку R для найденного пути (цикла) и Isolated для изолированных вершин.
// При этом не считается изолированной вершина, имеющая лишь петли.
// Возвращает заполненные R и Isolated (если есть путь либо цикл, при этом возвращаемые значения соответственно 2 и 1) и пустые вектора и -1, если их не найдено.
// Эйлеров путь/ цикл ищется на всем графе, либо на единственной компоненте связности, при условии что прочие вершины - изолированные.
// Может работать с ориентированными графами с дублирующими ребрами и с множественными петлями. Нумерация вершин может осуществляться любыми целыми числами, в т.ч. отрицательными. При этом считается, что граф содержит все вершины, соответствующие всем числам от min (1, минимальный заданный номер вершины) по максимальный заданный номер вершины включительно.
// В процессе работы граф приводится к виду, чтобы вершины нумеровались начиная с 1. По окончанию работы исходная нумерация восстанавливается.

// Finding Eulerian Cycle or Path in directed graph (weighted or non-weighted) that may contain multiple edges and multiple loops.
// Returns Path/ Cycle as R, isolated vertices as Isolated. Returns value "1" if Eulerian cycle has been found or value "2" if Eulerian path has been found or "-1" together with empty R and Isolates if no cycle/ path found.
// If any vertex has loops only, such a vertex is not considered as an isolated one.
// Vertices may be numbered in different ways (they may be marked by both negative and non-negative integers). In doing so, we set that the graph contains vertices marked by all the integers from min (1, minimal number assigned to vertices) to maximal number assigned to vertices inclusive.
// In order to implement the function vertices may be renumbered to get started from "1"; after search is completed, the vertices will be assigned their original numbers.


{
    R.clear(); // здесь будет искомый цикл/ путь // vector for Eulerian cycle/ path
    Isolated.clear(); // Здесь будут храниться найденные изолированные вершины // vector for isolated vertices.


    if (A.size()==0) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

    int V; // здесь будет максимальный номер вершины // the max number of assigned to vertices
    int E = A.size()/(2+weighted); // the total number of edges in the graph


    int mn;
    RangeVGraph (A, V, mn, weighted);

    if (mn<1)  // Приведение вектора к нумерованию вершин с 1 // renumbering vertices to start from 1.
    {
        RenumVGraph (A, (1-mn), weighted);
        V = V+(1-mn);
    }

    std::vector <int> Visited (V+1, 0); // нулевой элемент использовать не будем: нумеруются вершины с 1
    Visited [0] = 1;

    std::vector <int> Vin(V+1, 0); //для подсчета входящих и исходящих в вершину
    std::vector <int> Vout (V+1, 0); // for counting in-edges and out-edges

    for (int q=0; q<A.size()-1-weighted; q= q+2+weighted)
    {
        Vin[(A[q+1])]++;
        Vout[(A[q])]++;
    }

    int t1, t2;
    int c=0;
    int c0=0;
    int c2=0;
    int c1=0;

    for (int a = 1; a<=V; a++)
    {
        if ((Vin [a]==0) && (Vout [a]==0) ) {Visited [a]=2;Isolated.push_back(a);c0++;continue;} // такая вершина - изолированная // such a vertex is isolated
        if (Vin [a]==Vout [a]) {c++; continue;} // у такой входы = выходам, считаем их //such a vertex has the number of in-edges = the number of out-edges. Lets count these vertices.
        if ((Vin [a]-Vout [a])==1) {c2++; t2 = a; continue;} // у такой на 1 больше входов, считаем их и запоминаем последнюю/ // such a vertex has the number of in-edges - the number of out-edges = 1. Lets count them and remember the last one.
        if ((Vin [a]-Vout [a])==-1) {c1++; t1 = a; continue;} // а у такой - выходов, считаем их и запоминаем последнюю// such a vertex has the number of in-edges - the number of out-edges = -1. Lets count them and remember the last one.


    }


    std::vector <std::vector <int>> B;
    MatrixSet(B, V+1, V+1, 0);


    for (unsigned int x = 0; x<A.size()-1-weighted; x = x+2+weighted)  // Формируем матрицу смежности B, содержащую ко-во ребер даже для взвешенных графов
        // Forming Adjacency matrix and filling it with the number of edges between vertices.
    {
        B[(A[x])][(A[x+1])]++;

    }

    int t = CheckUnvisit(Visited); // начнем искать путь/цикл с любой неизолированной вершины // Lets start search from any non-isolated vertex
    sort (Isolated.begin(), Isolated.end());

    if ( ((c+c0)==V) && (c>=1) )  //In this case we may have a Cycle
    {
        EcycleDGraph(t, R, V, B); // Формируем цикл // find the cycle
        if (mn<1) // и если надо перенумеровываем вершины назад если необходимо // Renumbering all the vertices back if needed
        {
            RenumVGraph (A, (-1+mn), weighted);
            RenumVGraph (R, (-1+mn), false, true);
            RenumVGraph (Isolated, (-1+mn), false, true);
        }
        R.push_back(R[0]); // в цикле начало = концу

        if ((R.size()-1)!=E) {Isolated.clear(); R.clear(); return -1;} // all the edges must be in R, the total number of edges = E

        return 1;  //This means "Found Eulerian cycle"
    }


    if (((c+c0+c1+c2)==V) && (c1==1) && (c2==1)) // необходимое условие наличия пути // in this case we may have Path
    {

        B[t2][t1]++; // добавим недостающее до цикла ребро // adding edge in order to complete path to cycle
        EcycleDGraph(t1, R, V, B);  // find the cycle

        R.push_back(R[0]);

        for (int i = 0; i<(R.size()-1); i++)  // rearranging cycle to path
            if ((R[i] == t2) && (R[i+1] == t1))
            {
                R.pop_back();
                for (int q = (i+1);q<R.size();q++)
                {    R.insert(R.begin(), R[R.size()-1]); R.pop_back();}

            }


        if (mn<1) // Renumbering all the vertices back if needed
        {

            RenumVGraph (A, (-1+mn), weighted);
            RenumVGraph (R, (-1+mn), false, true);
            RenumVGraph (Isolated, (-1+mn), false, true);

        }

        if ((R.size()-1)!=E) {Isolated.clear(); R.clear(); return -1;} // all the edges must be in R, the total number of edges = E

        return 2; // This means "Found Eulerian path"

    }


    Isolated.clear();
    R.clear();
    if (mn<1) // Renumbering all the vertices back if needed
    {

        RenumVGraph (A, (-1+mn), weighted);

    }

    return -1;
}


int EPathDGraph (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <int> & R, std::vector <int> & Isolated)
// Модификация функции EPathDGraph (см. выше) для случая нецелочисленных весов ребер (double).
// Modification of the function EPathDGraph (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.


{
    R.clear(); // здесь будет искомый цикл/ путь // vector for Eulerian cycle/ path
    Isolated.clear(); // Здесь будут храниться найденные изолированные вершины // vector for isolated vertices.

    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;

    return EPathDGraph (A.first, R, false, Isolated);

}




int GenRandomUWGraph (std::vector <int> &P, int v, int e, int b=0)
// Вспомогательная функция для генерации случайного невзвешенного графа в векторе смежности P
// An auxiliary function that generates a random unweighted graph P (set by Adjacency vector P)
// e means the number of edges, v means the number of vertices, b means the minimal number to be assigned to vertex

{
    P.clear();
    if ((v<=0) || (e<=0) || (b<0) ) return -1;

    srand(time(0));

    for (unsigned int i=0; i<2*e; i++)
    {
        P.push_back(b+rand() % v);

    }

    return 0;
}


int MakeSubgraphSetOfVertices (const std::vector <int>&A, std::vector <int>&Subgraph, const std::set <int> &Vertices, const bool weighted)
// Функция для выделения подграфа Subgraph из графа A, такого что все вершины искомого подграфа задаются set <int> Vertices.
// Граф A задается вектором смежности A, веса - целочисленны или граф невзвешенный.
// параметр weighted задает, является ли граф взвешенным.

// The function makes a subgraph Subgraph from the graph A as follows: we take only vertices from the set <int> Vertices.
// Graph A is set by Adjacency vector A. It may be weighted or no (set by "weighted"), weights may be integers only.


{
    Subgraph.clear();
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

        for (int i=0; i<A.size();i=i+2+weighted)
        {

            if (Vertices.find(A[i])!=Vertices.end())
            {

                if (Vertices.find(A[i+1])!=Vertices.end())
                {

                    Subgraph.push_back(A[i]);
                    Subgraph.push_back(A[i+1]);
                    if (weighted)
                        Subgraph.push_back(A[i+2]);
                }
            }
        }


        return 0;

}


int MakeSubgraphSetOfVertices (const std::vector <int>&A, std::vector <int>&Subgraph, const std::unordered_set <int> &Vertices, const bool weighted)
// Функция для выделения подграфа Subraph из графа A, такого что все вершины искомого подграфа задаются unordered_set <int> Vertices.
// Граф A задается вектором смежности A, веса - целочисленны или граф невзвешенный.
// параметр weighted задает, является ли граф взвешенным.

// The function makes a subgraph Subgraph from the graph A as follows: we take only vertices from the unordered_set <int> Vertices.
// Graph A is set by Adjacency vector A. It may be weighted or no (set by "weighted"), weights may be integers only.

{
    Subgraph.clear();
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

        for (int i=0; i<A.size();i=i+2+weighted)
        {
            if (Vertices.find(A[i])!=Vertices.end())
                if (Vertices.find(A[i+1])!=Vertices.end())
                {
                    Subgraph.push_back(A[i]);
                    Subgraph.push_back(A[i+1]);
                    if (weighted)
                        Subgraph.push_back(A[i+2]);
                }

        }

        return 0;

}



int MakeSubgraphSetOfVertices (const std::pair < std::vector<int>, std::vector<double>> & A, std::pair < std::vector<int>, std::vector<double>> &Subgraph, const std::set <int> &Vertices)
// Модификация функции MakeSubgraphSetOfVertices (см.выше) для случая нецелочисленных весов ребер.
// Modification of the function MakeSubgraphSetOfVertices (see it above) for not-integer (double) weights of edges of a graph.
{
   (Subgraph.first).clear();
   (Subgraph.second).clear();

    if (  (A.first).size()!=((A.second).size())*2 ) return -1;

    for (int i=0; i<A.first.size();i=i+2)
    {
        if (Vertices.find(A.first[i])!=Vertices.end())
            if (Vertices.find(A.first[i+1])!=Vertices.end())
            {
                (Subgraph.first).push_back(A.first[i]);
                (Subgraph.first).push_back(A.first[i+1]);
                (Subgraph.second).push_back(A.second[i/2]);
            }

    }
     return 0;

}


int MakeSubgraphSetOfVertices (const std::pair < std::vector<int>, std::vector<double>> & A, std::pair < std::vector<int>, std::vector<double>> &Subgraph, const std::unordered_set <int> &Vertices)
// Модификация функции MakeSubgraphSetOfVertices(см. выше) для случая нецелочисленных весов ребер для unordered_set
// Modification of the function MakeSubgraphSetOfVertices (see it above) for not-integer (double) weights of edges of a graph and unordered_set Vertices.
{
   (Subgraph.first).clear();
   (Subgraph.second).clear();

    if (  (A.first).size()!=((A.second).size())*2 ) return -1;

    for (int i=0; i<A.first.size();i=i+2)
    {
        if (Vertices.find(A.first[i])!=Vertices.end())
            if (Vertices.find(A.first[i+1])!=Vertices.end())
            {
                (Subgraph.first).push_back(A.first[i]);
                (Subgraph.first).push_back(A.first[i+1]);
                (Subgraph.second).push_back(A.second[i/2]);
            }

    }
     return 0;

}


int AdjVectorEdgesMultiplicity (const std::vector <int> &A, std::map <std::pair < int, int> , int> &G2, const bool weighted, bool directed = true)
// Counts multiplicity of edges of a graph that is set by Adjacency vector A.
// Parameter "weighted" sets if the graph A is weighted or no. Weights may be only integers. If A is unweighted we consider that every edge have its weight = 1.
// Parameter "directed" sets if the graph A is directed or no.
// For a DIRECTED graph the result will be formed in the map G2 as follows:
// key is the pair of integers corresponding to the source and the sink vertices of an edge, and the value is its multiplicity.
// For example "G2[std::pair <int, int>(1, 2)] = 3" means that directed edge 1->2 has its multiplicity = 3.
// For UNDIRECTED graph G2 will contain edge multiplicity for both keys std::pair <int, int> (vertex1, vertex 2) and std::pair <int, int> (vertex2, vertex 1).
// For example for undirected graph will be so: "G2[std::pair <int, int>(1, 2)] = G2[std::pair <int, int>(2, 1)] = 3".
// Returns -1 and empty G2 if input data is not correct. Otherwise returns 0.
// Возвращает кратность ребер графа, заданного вектором смежности А, в ассоциативном массиве смежности G2.
// Параметр weighted задает, является ли граф взвешенным (Истина) или нет.
// Параметр directed задает, является ли граф ориентированным (Истина) или нет.
// К примеру, для ориентированного графа "G2[std::pair <int, int>(1, 2)] = 3" означает, что направленное ребро 1->2 имеет кратность = 3.
// Для неориентированного будут храниться одинаковые значения для пар вершин (vertex1, vertex 2) и (vertex2, vertex 1).
// Т.е. для неориентированного графа будет верной подобная запись: G2[std::pair <int, int>(1, 2)] = G2[std::pair <int, int>(2, 1)] = 3
// Возвращает -1 и пустой G2 в случае некорректности исходных данных. Если успех - вернет 0.



{
    G2.clear();
    if (A.size()==0) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

    std::pair < int, int> C;
    std::pair < std::pair < int, int>, int> D;


    std::pair < int, int> C1;
    std::pair < std::pair < int, int>, int> D1;

    if (directed)
    {
    for (int i=0; i<A.size(); i=i+2+weighted)
    {
        C = std::make_pair(A[i], A[i+1]);
        D = std::make_pair(C, 1);

        if (G2.find(C)!=G2.end())
        {G2[C] = G2[C]+1; continue;}

        if (G2.find(C)==G2.end())
        {G2.insert(D); continue;}

    }
    }

    if (!directed)
    {
    for (int i=0; i<A.size(); i=i+2+weighted)
    {
        C = std::make_pair(A[i], A[i+1]);
        D = std::make_pair(C, 1);

        C1 = std::make_pair(A[i+1], A[i]);
        D1 = std::make_pair(C1, 1);

        if (G2.find(C)!=G2.end())
        {G2[C] = G2[C]+1; G2[C1] = G2[C1]+1; continue;}

        if (G2.find(C)==G2.end())
        {G2.insert(D); G2.insert(D1); continue;}

    }
    }


    return 0;

}



int AdjVectorEdgesMultiplicity (const std::pair < std::vector<int>, std::vector<double>> & A, std::map <std::pair < int, int> , int> &G2, bool directed = true)
// Modification of the function AdjVectorEdgesMultiplicity (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.
// Returns -1 and empty G2 if input data is not correct. Otherwise returns 0.
// Модификация AdjVectorEdgesMultiplicity (см. выше) для случая графа с нецелочисленными весами ребер.

{
    G2.clear();

    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;

    return AdjVectorEdgesMultiplicity (A.first, G2, false, directed);

}



int AdjVectorEdgesMultiplicity (const std::vector <int> &A, std::unordered_map <std::pair < int, int> , int, PairIntHash> &G2, const bool weighted, bool directed = true)
// Modification to return result in unordered_map
// Модификация AdjVectorEdgesMultiplicity (см. выше) для возврата результата в unordered_map.


{
    G2.clear();
    if (A.size()==0) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

    std::pair < int, int> C;
    std::pair < std::pair < int, int>, int> D;


    std::pair < int, int> C1;
    std::pair < std::pair < int, int>, int> D1;

    if (directed)
    {
    for (int i=0; i<A.size(); i=i+2+weighted)
    {
        C = std::make_pair(A[i], A[i+1]);
        D = std::make_pair(C, 1);

        if (G2.find(C)!=G2.end())
        {G2[C] = G2[C]+1; continue;}

        if (G2.find(C)==G2.end())
        {G2.insert(D); continue;}

    }
    }

    if (!directed)
    {
    for (int i=0; i<A.size(); i=i+2+weighted)
    {
        C = std::make_pair(A[i], A[i+1]);
        D = std::make_pair(C, 1);

        C1 = std::make_pair(A[i+1], A[i]);
        D1 = std::make_pair(C1, 1);

        if (G2.find(C)!=G2.end())
        {G2[C] = G2[C]+1; G2[C1] = G2[C1]+1; continue;}

        if (G2.find(C)==G2.end())
        {G2.insert(D); G2.insert(D1); continue;}

    }
    }


    return 0;

}



int AdjVectorEdgesMultiplicity (const std::pair < std::vector<int>, std::vector<double>> & A, std::unordered_map <std::pair < int, int> , int, PairIntHash> &G2, bool directed = true)
// Modification to return result in unordered_map
// Модификация AdjVectorEdgesMultiplicity (см. выше) для возврата результата в unordered_map.

{
    G2.clear();

    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;

    return AdjVectorEdgesMultiplicity (A.first, G2, false, directed);

}


int DFSSCC1 (const std::vector <int> & A, const int b, std::vector <int> & Visited, std::vector <int> & order, const bool weighted)

//Вспомогательная функция для упорядочивания вершин орграфа для поиска сильносвязных его компонент
// An auxiliary function to order vertices of a graph for the function SCCGraph_Vertices



{

    Visited [b] = 1;  // b - the vertex to start with. Vertex is to become grey when starting working with it
    int f;


    for (unsigned int r = 0; r<A.size(); r=r+2+weighted)
    {


        if ( (A[r+1]==b) && (A[r]==b) ) continue; // Если петля - идем дальше //if a loop found - let's continue, loop will be ignored




        if ( (A[r+1]==b) && (Visited [ (A[r]) ] == 0) )  // нашли непосещенную? непосещенная = 0  //found a non-visited vertex
        {
           Visited[(A[r])] = 1;


           f=DFSSCC1 (A, (A[r]), Visited, order, weighted);


        }


    }

    order.push_back(b);
    Visited [b] = 2;  // отработали и перекрасили в черный (=2) // now the vertex is to become black (=2)

return 0;
}



int NeighborJoiningUndirectedGraph (const std::vector <std::vector <int>> B, std::pair < std::vector<int>, std::vector<double>> &A)
// Конструирует дерево (неориентированный граф) методом присоединения ближайшего соседа на основе матрицы дистанций B, результат - дерево - возвращается в векторе смежности A. Нумерация вершин графа ведется с 1.
// Возвращает 0 в случае успеха; в случае некорректных данных (пустая или не квадратная  или содержащая отрицательные элементы матрица B), вернет -1.
// Generates a tree (undirected graph) using Neighbor Joining method (as an Adjacency vector A, 1-based indexing of vertices) upon a distance matrix B.
// If any data incorrect (B has zero lines (i.e. empty) or has negative values or is not a square matrix) returns empty A and -1. If success returns 0.



{
    A.first.clear();
    A.second.clear();
    if (B.size()==0) return -1;
    for (int q=0;q<B.size();q++)
        if ((B.size()!=B[q].size())) return -1;

    int y = B.size();


    std::vector <std::vector <double>> D; D.clear();
    std::vector <double> B1; B1.clear();

    MatrixSet(D,y+1,y+1,0.0);

    for (int a = 0; a<D.size(); a++) // занесение в заголовки строк и столбцов номеров соответствующих вершин графа
        // strings&columns numbers will be in headers (i.e. in 0-labeled string and columns of D)
    {
        D[0][a] = a*1.0;
        D[a][0] = a*1.0;

    }

    for (int i = 0; i<B.size(); i++)
        for (int j = 0; j<B.size(); j++)
        // writting B to D
    {
        if (B[i][j]<0) return -1;


            D[i+1][j+1] = 1.0*B[i][j];


    }


    std::vector <std::vector <double>> Q; //Q-matrix will be here

    MatrixSet(Q,y+1,y+1,0.0);
    double z1, z2;
    double tz1, tz2;
    int ti, tj;
    double mn = std::numeric_limits<double>::max();
    int countv = y+1;
    int n=y;
    for (int q=0; q<(n-1); q++)
    {

        if (D.size()==3)
        {
            z2 = D[1][2];
            A.first.push_back((int)D[0][1]);
            A.first.push_back((int)D[0][2]);
            A.second.push_back(z2);

            break;

        }

        mn = std::numeric_limits<double>::max();
        MatrixSet(Q,y+1,y+1,0.0);
        for (int i=1; i<(y+1); i++)
            for (int j=1; j<(y+1); j++)
            {
                if (i==j) continue;
                z1=0.0; z2=0.0;
                for (int ii=1;ii<=y;ii++)
                {

                    z1 = z1+D[i][ii];
                    z2 = z2+D[j][ii];
                }

                Q[i][j] = (y-2.0)*D[i][j]-z1-z2;
                if (Q[i][j]<mn)
                {mn=Q[i][j];
                    ti=i;
                    tj=j;
                    tz1=z1; tz2=z2;}

            }
        // сделали Q-матрицу Q-matrix is done




               A.first.push_back((int)D[0][ti]);
               A.first.push_back(countv);
               A.second.push_back(0.5*D[ti][tj]+0.5*(tz1-tz2)/(y-2));



               A.first.push_back((int)D[0][tj]);
               A.first.push_back(countv);
               A.second.push_back(D[ti][tj] - 0.5*D[ti][tj]-0.5*(tz1-tz2)/(y-2));


               z1 = D[ti][tj];


               D[0][ti]=countv;
               D[ti][0]=countv;

                   for (int x2 = 1;x2<(y+1);x2++)
                       {

                            D[x2][ti] = 0.5*(-1.0*z1+D[ti][x2]+D[tj][x2]);
                            D[ti][x2] = D[x2][ti];
                       }


                   for (int x2 = 0;x2<(y+1);x2++)
                       {

                            D[x2].erase(D[x2].begin()+tj);
                       }
                   D.erase(D.begin()+tj);


                countv++;
               y--;



    }

return 0;


}


int UPGMA_UndirectedGraph (const std::vector <std::vector <int>> B, std::pair < std::vector<int>, std::vector<double>> &A)
// Конструирует дерево (неориентированный граф) методом UPGMA на основе матрицы дистанций B, результат - дерево - возвращается в векторе смежности A. Нумерация вершин графа ведется с 1.
// Возвращает 0 в случае успеха; в случае некорректных данных (пустая или не квадратная  или содержащая отрицательные элементы матрица B), вернет -1.
// Generates a tree (undirected graph) using UPGMA method (as an Adjacency vector A, 1-based indexing of vertices) upon a distance matrix B.
// If any data incorrect (B has zero lines (i.e. empty) or has negative values or is not a square matrix) returns empty A and -1. If success returns 0.



{
    A.first.clear();
    A.second.clear();
    if (B.size()==0) return -1;
    for (int q=0;q<B.size();q++)
        if ((B.size()!=B[q].size())) return -1;

    int y = B.size();


    std::vector <std::vector <double>> D; D.clear();
    std::vector <double> B1; B1.clear();

    MatrixSet(D,y+1,y+1,0.0);

    for (int a = 0; a<D.size(); a++) // занесение в заголовки строк и столбцов номеров соответствующих вершин графа
        // strings&columns numbers will be in headers (i.e. in 0-labeled string and columns of D)
    {
        D[0][a] = a*1.0;
        D[a][0] = a*1.0;

    }

    for (int i = 0; i<B.size(); i++)
        for (int j = 0; j<B.size(); j++)
        // writing B to D
    {
        if (B[i][j]<0) return -1;


            D[i+1][j+1] = 1.0*B[i][j];


    }


    std::map <double, double> R; // остаточные расстояния от вершины до низа // the remaining distance to the bottom of the tree
    R.clear();

    for (int q = 0; q<y; q++)
        R.insert(std::pair<double, double>((q+1)*1.0, 0.0));




    std::map <double, double> N; // кол-во элементов в кластере под вершиной // the number of elements in the cluster lower the vertex
    N.clear();

    for (int q = 0; q<y; q++)
        N.insert(std::pair<double, double>((q+1)*1.0, 1.0));




    int count = 0;
    double mn = std::numeric_limits<double>::max();
    int ii, jj;
    int countv = y+1;
    double t;

    while (count!=(y-1))
    {
        mn = std::numeric_limits<double>::max();
        for (int w = 1; w<D.size(); w++) // поиск самых близких вершин ii и jj
          {
            for (int e = w+1; e<D.size(); e++)
            {
                if ((D[w][e] >0.0)&& (D[w][e] <mn))
                {
                    ii=w;
                    jj = e;
                    mn = D[w][e];

                }

            }
          }




        for (int w = 1; w<D.size(); w++) //пересчет //recalculating
        {

            if (D[ii][w]>0.0)
            {
                t = (D[ii][w]*N[D[ii][0]*1.0]+D[jj][w]*N[D[jj][0]*1.0])/(N[D[ii][0]*1.0]+N[D[jj][0]*1.0]);
                D[ii][w] = t;

                D[w][ii] = D[ii][w];


            }

            D[jj][w] = -1.0;
            D[w][jj] = D[jj][w];

        }



        A.first.push_back(countv);
        A.first.push_back((int)D[ii][0]);
        A.second.push_back(mn*0.5-1.0*R[D[ii][0]]);

        A.first.push_back(countv);
        A.first.push_back((int)D[jj][0]);
        A.second.push_back(mn*0.5-1.0*R[D[jj][0]]);

        R.insert(std::pair<double, double>(countv*1.0, mn*0.5));
        t = (N[D[ii][0]*1.0]+N[D[jj][0]*1.0]);
        N.insert(std::pair<double, double>(countv*1.0, t));

        D[0][ii] = countv;
        D[ii][0] = countv;

        countv++;
        count++;
    }


return 0;

}



int NeighborJoiningUndirectedGraph (const std::vector <std::vector <double>> B, std::pair < std::vector<int>, std::vector<double>> &A)
// Модификация функции для нецелочисленной матрицы дистанций B.
// Modification for distance matrix B of doubles.

{
    A.first.clear();
    A.second.clear();
    if (B.size()==0) return -1;
    for (int q=0;q<B.size();q++)
        if ((B.size()!=B[q].size())) return -1;

    int y = B.size();


    std::vector <std::vector <double>> D; D.clear();
    std::vector <double> B1; B1.clear();

    MatrixSet(D,y+1,y+1,0.0);

    for (int a = 0; a<D.size(); a++) // занесение в заголовки строк и столбцов номеров соответствующих вершин графа
        // strings&columns numbers will be in headers (i.e. in 0-labeled string and columns of D)
    {
        D[0][a] = a*1.0;
        D[a][0] = a*1.0;

    }

    for (int i = 0; i<B.size(); i++)
        for (int j = 0; j<B.size(); j++)
        // writing B to D
    {
        if (B[i][j]<0) return -1;


            D[i+1][j+1] = 1.0*B[i][j];


    }


    std::vector <std::vector <double>> Q; //Q-matrix will be here

    MatrixSet(Q,y+1,y+1,0.0);
    double z1, z2;
    double tz1, tz2;
    int ti, tj;
    double mn = std::numeric_limits<double>::max();
    int countv = y+1;
    int n=y;
    for (int q=0; q<(n-1); q++)
    {

        if (D.size()==3)
        {
            z2 = D[1][2];
            A.first.push_back((int)D[0][1]);
            A.first.push_back((int)D[0][2]);
            A.second.push_back(z2);

            break;

        }

        mn = std::numeric_limits<double>::max();
        MatrixSet(Q,y+1,y+1,0.0);
        for (int i=1; i<(y+1); i++)
            for (int j=1; j<(y+1); j++)
            {
                if (i==j) continue;
                z1=0.0; z2=0.0;
                for (int ii=1;ii<=y;ii++)
                {

                    z1 = z1+D[i][ii];
                    z2 = z2+D[j][ii];
                }

                Q[i][j] = (y-2.0)*D[i][j]-z1-z2;
                if (Q[i][j]<mn)
                {mn=Q[i][j];
                    ti=i;
                    tj=j;
                    tz1=z1; tz2=z2;}

            }
        // сделали Q-матрицу Q-matrix is done




               A.first.push_back((int)D[0][ti]);
               A.first.push_back(countv);
               A.second.push_back(0.5*D[ti][tj]+0.5*(tz1-tz2)/(y-2));



               A.first.push_back((int)D[0][tj]);
               A.first.push_back(countv);
               A.second.push_back(D[ti][tj] - 0.5*D[ti][tj]-0.5*(tz1-tz2)/(y-2));


               z1 = D[ti][tj];


               D[0][ti]=countv;
               D[ti][0]=countv;

                   for (int x2 = 1;x2<(y+1);x2++)
                       {

                            D[x2][ti] = 0.5*(-1.0*z1+D[ti][x2]+D[tj][x2]);
                            D[ti][x2] = D[x2][ti];
                       }


                   for (int x2 = 0;x2<(y+1);x2++)
                       {

                            D[x2].erase(D[x2].begin()+tj);
                       }
                   D.erase(D.begin()+tj);


                countv++;
               y--;



    }

return 0;


}


int UPGMA_UndirectedGraph (const std::vector <std::vector <double>> B, std::pair < std::vector<int>, std::vector<double>> &A)
// Модификация функции для нецелочисленной матрицы дистанций B.
// Modification for distance matrix B of doubles.

{
    A.first.clear();
    A.second.clear();
    if (B.size()==0) return -1;
    for (int q=0;q<B.size();q++)
        if ((B.size()!=B[q].size())) return -1;

    int y = B.size();


    std::vector <std::vector <double>> D; D.clear();
    std::vector <double> B1; B1.clear();

    MatrixSet(D,y+1,y+1,0.0);

    for (int a = 0; a<D.size(); a++) // занесение в заголовки строк и столбцов номеров соответствующих вершин графа
        // strings&columns numbers will be in headers (i.e. in 0-labeled string and columns of D)
    {
        D[0][a] = a*1.0;
        D[a][0] = a*1.0;

    }

    for (int i = 0; i<B.size(); i++)
        for (int j = 0; j<B.size(); j++)
        // writing B to D
    {
        if (B[i][j]<0) return -1;


            D[i+1][j+1] = 1.0*B[i][j];


    }


    std::map <double, double> R; // остаточные расстояния от вершины до низа // the remaining distance to the bottom of the tree
    R.clear();

    for (int q = 0; q<y; q++)
        R.insert(std::pair<double, double>((q+1)*1.0, 0.0));




    std::map <double, double> N; // кол-во элементов в кластере под вершиной // the number of elements in the cluster lower the vertex
    N.clear();

    for (int q = 0; q<y; q++)
        N.insert(std::pair<double, double>((q+1)*1.0, 1.0));




    int count = 0;
    double mn = std::numeric_limits<double>::max();
    int ii, jj;
    int countv = y+1;
    double t;

    while (count!=(y-1))
    {
        mn = std::numeric_limits<double>::max();
        for (int w = 1; w<D.size(); w++) // поиск самых близких вершин ii и jj
          {
            for (int e = w+1; e<D.size(); e++)
            {
                if ((D[w][e] >0.0)&& (D[w][e] <mn))
                {
                    ii=w;
                    jj = e;
                    mn = D[w][e];

                }

            }
          }




        for (int w = 1; w<D.size(); w++) //пересчет //recalculating
        {

            if (D[ii][w]>0.0)
            {
                t = (D[ii][w]*N[D[ii][0]*1.0]+D[jj][w]*N[D[jj][0]*1.0])/(N[D[ii][0]*1.0]+N[D[jj][0]*1.0]);
                D[ii][w] = t;

                D[w][ii] = D[ii][w];


            }

            D[jj][w] = -1.0;
            D[w][jj] = D[jj][w];

        }



        A.first.push_back(countv);
        A.first.push_back((int)D[ii][0]);
        A.second.push_back(mn*0.5-1.0*R[D[ii][0]]);

        A.first.push_back(countv);
        A.first.push_back((int)D[jj][0]);
        A.second.push_back(mn*0.5-1.0*R[D[jj][0]]);

        R.insert(std::pair<double, double>(countv*1.0, mn*0.5));
        t = (N[D[ii][0]*1.0]+N[D[jj][0]*1.0]);
        N.insert(std::pair<double, double>(countv*1.0, t));

        D[0][ii] = countv;
        D[ii][0] = countv;

        countv++;
        count++;
    }

return 0;


}





int DFSSCC2 (const std::vector <int> & A, const int b, std::vector <int> & Visited, std::vector <int> & order,std::set <int> & R, const bool weighted)

//Вспомогательная функция для поиска вершин очередной сильно связной компоненты для SCCGraph_Vertices
// An auxiliary function to find vertices of a graph for a strongly connected component (for the function SCCGraph_Vertices).

{

    Visited [b] = 1;  // b - the vertex to start with. Vertex is to become grey when starting working with it
    int f;

    R.insert(b);

    for (unsigned int r = 0; r<A.size(); r=r+2+weighted)
    {


        if ( (A[r]==b) && (A[r+1]==b) ) continue; // Если петля - идем дальше //if a loop found - let's continue, loop will be ignored




        if ( (A[r]==b) && (Visited [ (A[r+1]) ] == 0) )  // нашли непосещенную? непосещенная = 0  //found a non-visited vertex
        {
           Visited[(A[r])] = 1;


           f=DFSSCC2 (A, (A[r+1]), Visited, order, R, weighted);


        }


    }


    Visited [b] = 2;  // отработали и перекрасили в черный (=2) // now the vertex is to become black (=2)

return 0;
}


int SCCGraph_Vertices (std::vector <int> & A, std::vector <std::set <int>> & G, const bool weighted, int mn = 0, int V = INT_MIN)
// Функция для нахождения наборов вершин по всем компонентам сильной связности (области сильной связности) ориентированного графа, заданного вектором смежности А. Параметр weighted задает, является ли граф взвешенным.
// Также на вход подается номер наибольшей вершины V (если не передан, рассчитывается самостоятельно как номер наибольшей вершины в ребрах) и номер минимальной вершины (по умолчанию = 0).
// В случае успеха возвращает число сильно связанных компонент. Возвращает и заполненный вектор G, каждый элемент которого - набор вершин очередной компоненты связности.
// В случае некорректных входных данных возвращает -1 и пустой G.

// The function finds collection of vertices for each strongly connected component of the directed graph, that is set by an Adjacency vector A.
// These collections are to be contained in vector G, i.e. G[i] contains a collection of vertices of the i-th strongly connected component.
// Input data: Adjacency vector A, the maximum vertex number V (V may be not set, in this case it will be the maximum vertex number of Adjacency vector A),
// the minimum vertex number mn (== 0 by default), bool weighted, that sets if the graph is weighted.
// If input data is incorrect the function returns "-1" and empty G.

{
    G.clear();

    if (A.size()==0) return -1;
    if (mn<0) return -1;
    if ((V<0)&&(V != INT_MIN)) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness


    int mn1, mx;
    RangeVGraph (A, mx, mn1, weighted);


    if ( (mn1<0) || (mn1<mn) )  // // checking for input data correctness.
    {
        return -1;
    }


    if (mx>V) V = mx; // здесь будет максимальный номер вершины // the max number of assigned to vertices



    std::vector <int> order;
    order.clear();

    std::set <int> R;
    R.clear();


    std::vector <int> Visited (V+1, 0); // to mark visited vertices

    for (int y=0; y<mn; y++) // to mark the nummrers that are less than mn
        Visited[y] = 1;



    int b=CheckUnvisit(Visited);  // вершина откуда идет поиск  // let's start from here

    int f;

    while (CheckUnvisit(Visited)!=-1)
    {
        b=CheckUnvisit(Visited);  // берем первую же непосещенную вершину  // vertex not visited yet
        f=DFSSCC1 (A, b, Visited, order, weighted);
    }

  std::reverse (order.begin(),order.end());



    for (int i=mn; i<Visited.size(); i++)
        Visited[i] = 0;




    for (int y=0; y<order.size(); y++)
    {
        if (Visited[order[y]]!=0) continue;
        b=order[y];
        R.clear();
        DFSSCC2 (A, b, Visited, order, R, weighted);

        //if (R.size()>1)
            G.push_back(R);
    }


  return G.size();


}


int CCGraph_Vertices (std::vector <int> & A, std::vector <std::set <int>> & R, const bool weighted, int mn = 0, int V = INT_MIN)
// Функция для нахождения наборов вершин по всем компонентам связности неориентированного (области связности) графа, заданного вектором смежности А. Параметр weighted задает, является ли граф взвешенным.
// Также на вход подается номер наибольшей вершины V (если не передан, рассчитывается самостоятельно как номер наибольшей вершины в ребрах) и номер минимальной вершины (по умолчанию = 0).
// В случае успеха возвращает число связанных компонент. Возвращает и заполненный вектор R, каждый элемент которого - набор вершин очередной компоненты связности.
// В случае некорректных входных данных возвращает -1 и пустой R.

// The function finds collection of vertices for each connected component of the undirected graph, that is set by an Adjacency vector A.
// These collections are to be contained in vector R, i.e. R[i] contains a collection of vertices of the i-th connected component.
// Input data: Adjacency vector A, the maximum vertex number V (V may be not set, in this case it will be the maximum vertex number of Adjacency vector A),
// the minimum vertex number mn (== 0 by default), bool weighted, that sets if the graph is weighted.
// If input data is incorrect the function returns "-1" and empty R.


{
    R.clear();

    if (A.size()==0) return -1;
    if (mn<0) return -1;
    if ((V<0)&&(V != INT_MIN)) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness


    int mn1, mx;
    RangeVGraph (A, mx, mn1, weighted);


    if ( (mn1<0) || (mn1<mn) )  // // checking for input data correctness.
    {
        return -1;
    }


    if (mx>V) V = mx; // здесь будет максимальный номер вершины // the max number of assigned to vertices


    std::set <int> G; // temp set to contain another component found
    G.clear();


    std::vector <int> Visited (V+1, 0); // to mark visited vertices

    for (int y=0; y<mn; y++) // to mark the nummrers that are less than mn
        Visited[y] = 1;


    int b=CheckUnvisit(Visited);  // вершина откуда идет поиск // let's start from the vertex b

    std::stack <int> Q;

while (CheckUnvisit(Visited)!=-1)
{
    b=CheckUnvisit(Visited);  // let's found an unvisited vertex
    G.clear();
    G.insert(b);
    Q.push(b);  // This vertex -> to stack



    while (!Q.empty())
    {
        b= Q.top();  // берем последнюю вершину из очереди
        Q.pop();  // убрать ее из очереди
        Visited[b] = 1;  // она посещена  // now the vertex is ti be marked as "visited"


        for (unsigned int r = 0; r<A.size(); r=r+2+weighted)
        {
            if ( (A[r]==b) && (Visited [ (A[r+1]) ] == 0) )  // 2-way checking for every edge as the graph A is undirected
            {
                Q.push(A[r+1]);
               Visited[(A[r+1])] = 1;
               G.insert(A[r+1]);


            }

            if ( (A[r+1]==b) && (Visited [ (A[r]) ] == 0) )  // 2 проверки т.к. ребра двусторонние
            {
                Q.push(A[r]);
                Visited[(A[r])] = 1;

                G.insert(A[r]);

            }




        }



    }

    R.push_back(G);
    G.clear();


}


return R.size();

}







int DFSTS (const std::vector <int> & A, const int b, std::vector <int> & Visited, std::vector <int> & order, const bool weighted)
// Вспомогательная функция для функции TSortHP. Проверки исходных данных не проводится, вершины в ориентированном орграфе, заданном вектором смежности A, д.б. нумерованы с 1.
// Граф может содержать петли (игнорируются).
// В процессе обхода раскрашиваем вершины в массиве Visited: 0 - непосещенная (белая), 1 - посещена, но не отработана (серая), 2 - отработана (черная).
// weighted - истина, если взвешенный граф, иначе - ложь.
// Если найден цикл - возвращает 1 и пустой order.

// An auxiliary function for the function TSortHP. Works without any checking of input data correctness. Vertices in the input directed graph (it is set by the Adjacency vector A) are to be numbered starting from 1.
// The graph may contain loops (they will be ignored).
// During building topological sorting we shall colour vertices (using vector Visited): 0 = unvisited (white), 1 = visited, but not still finished yet (grey), 2 = finished (black).
// Bool "weighted" should be set as "true" for weighted graph, "false" for unweighted.
// If the graph contains cycle - returns 1 and empty "order".



{

    Visited [b] = 1;  // b - the vertex to start with. Vertex is to become grey when starting working with it
    int f;


    for (unsigned int r = 0; r+1+weighted<=A.size(); r=r+2+weighted)
    {


        if ( (A[r]==b) && (A[r+1]==b) ) continue; // Если петля - идем дальше //if a loop found - let's continue, loop will be ignored

        if ( (A[r]==b) && (Visited [ (A[r+1]) ] == 1) )  // in this case a cycle is found
        {
            order.clear();
            return 1;
        }


        if ( (A[r]==b) && (Visited [ (A[r+1]) ] == 0) )  // нашли непосещенную? непосещенная = 0  //found a non-visited vertex
        {
           Visited[(A[r+1])] = 1;
           f=DFSTS (A, (A[r+1]), Visited, order, weighted);
            if (f==1)
            {
                order.clear();
                return 1;
            }

        }


    }

    order.push_back(b);
    Visited [b] = 2;  // отработали и перекрасили в черный (=2) // now the vertex is to become black (=2)

return 0;
}


int CycleToPath (std::vector <int> Cycle, std::vector<int> &Path)
// Функция "вставляет" цикл Cycle в путь Path с первого значения из Path, которое встречается в Cycle.
// В случае успеха вернет 0. В случае неуспеха или некорректных исходных данных вернет -1.

// The function integrate cycle Cycle to the path Path (starting vertex will be the first from Cycle that may be found in Path)
// Returns 0 if success. Returns -1 if it is impossible or input data are incorrect

{
    int f = -1;
    if (Cycle.size()==0) return f;
    if (Cycle[0]!=Cycle[Cycle.size()-1]) return f;
    if (Path.size()==0) return f;

    int t, d;
    for (int j=0; j<Cycle.size(); j++)
    {
        t = FindIn(Path, Cycle[j]);
        if (t==-1) continue;
        f = 0;
        Path.insert( Path.begin()+1+t, Cycle.begin()+j+1, Cycle.end()-1 );

        d = Cycle.size()-j-2;
        Cycle.resize(j+1);

        Path.insert( Path.begin()+1+t+d, Cycle.begin(), Cycle.end() );
    }

    return f;
}



int TSortHP (std::vector <int> & A, std::vector <int> & R, std::vector <int> & order, std::vector <int> & Isolated, const bool weighted, const bool OnlyTS = false)
// Функция для топологической сортировки в орграфе. Также в случае наличия топологической сортировки (и при условии OnlyTS = false) ищет Гамильтонов путь и перечень изолированных вершин. При этом не считается изолированной вершина, имеющая лишь петли.
// Функция НЕ является функцией поиска именно Гамильтонова пути, он ищется ТОЛЬКО в случае наличия топологической сортировки.
// Принимает на вход вектор смежности графа A с указанием, взвешенный ли граф (параметр weighted), а также заготовку R для Гамильтонова пути, order для топологической сортировки, Isolated для перечня изолированных вершин.
// Может работать с ориентированными графами с дублирующими ребрами и с множественными петлями (петли будут игнорироваться).
// Нумерация вершин может осуществляться любыми целыми числами, в т.ч. отрицательными. При этом считается, что граф содержит все вершины, соответствующие всем числам от min (1, минимальный заданный номер вершины) по максимальный заданный номер вершины включительно.
// В процессе работы граф приводится к виду, чтобы вершины нумеровались начиная с 1. По окончанию работы исходная нумерация восстанавливается.
// Если OnlyTS == false (нормальная работа функции):
// Возвращает 0, если найдены и топологическая сортировка, и Гамильтонов путь.
// Возвращает -1 и пустые R, order, Isolated, если в графе найден цикл.
// Возвращает 1 и пустой R, если есть топологическая сортировка, а Гамильтонова пути нет.
// Если параметр OnlyTS == true, то ищется только топологическая сортировка (данный режим предусмотрен для ускорения работы). Возвращает 0, если она найдена и -1 если нет. Гамильтонов путь и изолированные вершины не возвращаются (R и Isolated будут пусты в любом случае).

// The function finds topological sorting of directed graph (returned as vector "order").
// ONLY IF topological sorting exists AND OnlyTS == false the function also checks for Hamiltonian path (returned as vector R) and list of Isolated vertices (returned as vector Isolated).
// The graph is set by Adjacency vector A, may be weighted or no (bool weighted).
// The graph may contain loops (they will be ignored).
// If any vertex has loops only, such a vertex is not considered as an isolated one.
// The graph may contain multiple edges.
// Vertices may be numbered in different ways (they may be marked by both negative and non-negative integers). In doing so, we set that the graph contains vertices marked by all the integers from min (1, minimal number assigned to vertices) to maximal number assigned to vertices inclusive.
// In order to implement the function vertices may be renumbered to get started from "1"; after search is completed, the vertices will be assigned their original numbers.
// So if OnlyTS == false:
// the function returns 0 if both topological sorting and Hamiltonian path found.
// the function returns -1 and empty Isolated, order, R if the graph contains cycle.
// the function returns 1 if topological sorting found and, upon that, Hamiltonian path doesn't exist.
// If OnlyTS == true, both R and Isolated will be returned empty (to make this function faster). The function returns 0 if topological sorting is found and -1 otherwise.



{
    R.clear(); order.clear(); Isolated.clear();



    if (A.size()==0) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

    int Vg; // здесь будет максимальный номер вершины // the max number of assigned to vertices
    int E = A.size()/(2+weighted); // the total number of edges in the graph


    int mn;
    RangeVGraph (A, Vg, mn, weighted);

    if (mn<1)  // Приведение вектора к нумерованию вершин с 1 // renumbering vertices to start from 1.
    {
        RenumVGraph (A, (1-mn), weighted);
        Vg = Vg+(1-mn);
    }

    if (!OnlyTS)
    {
    std::vector <int> Vin(Vg+1, 0); //для подсчета входящих и исходящих в вершину
    std::vector <int> Vout (Vg+1, 0); // for counting in-edges and out-edges


    // Поиск изолированных
    // Let's find isolated vertices

    for (int q=0; q<A.size()-1-weighted; q= q+2+weighted)
    {
        Vin[(A[q+1])]++;
        Vout[(A[q])]++;
    }


    for (int a = 1; a<=Vg; a++)
        if ((Vin [a]==0) && (Vout [a]==0) ) Isolated.push_back(a);

    if (mn<1) // Renumbering all the vertices back if needed
    {

        RenumVGraph (Isolated, (-1+mn), false, true);

    }

    // Конец поиска изолированных // end of finding isolated vertices
    }

    std::vector <int> Visited (Vg+1, 0); // нулевой элемент использовать не будем: нумеруются вершины с 1  // all vertices are to be numbered starting from 1
    Visited [0] = 1;
    int b=CheckUnvisit(Visited);  // вершина откуда идет поиск  // let's start from here

    int f;

    while (CheckUnvisit(Visited)!=-1)
    {
        b=CheckUnvisit(Visited);  // берем первую же непосещенную вершину  // vertex not visited yet



         f=DFSTS (A, b, Visited, order, weighted);
         if (f==1)
         {
             R.clear();
             Isolated.clear();

             if (mn<1) // Renumbering all the vertices back if needed
             {

                 RenumVGraph (A, (-1+mn), weighted);

             }

             return -1; // cycle is found
         }

    }

    reverse (order.begin(),order.end());  // в массиве order - результат топологической сортировки  // order contains topological sorting


    if (!OnlyTS)
    {

    std::vector < std::vector <int> > B;
    MatrixSet(B, Vg+1, Vg+1, 0);


    for (unsigned int x = 0; x<A.size()-1-weighted; x = x+2+weighted)  // Формируем матрицу смежности B, содержащую ко-во ребер даже для взвешенных графов
        // Forming Adjacency matrix and filling it with the number of edges between vertices.
    {
        if (A[x]!=A[x+1]) B[(A[x])][(A[x+1])]++;

    }



    int y = 1;

    if (order.size()==1) y=-1;


    for (unsigned int z = 0; z<(order.size()-1); z++)
    {
        if (B[(order[z])][(order[z+1])] < 1)
        {y=-1;break;}

    }




        if (y==-1)
        {
            R.clear();
                if (mn<1) // Renumbering all the vertices back if needed
                {

                    RenumVGraph (A, (-1+mn), weighted);

                    RenumVGraph (order, (-1+mn), false, true);

                }
                return 1; // means no Hamiltonian Path found, only Topological Sorting returned

        }
        else
        {

            for (unsigned int i=0; i<order.size(); i++)
            {R.push_back(order [i]);

            }
        }

    }


            if (mn<1) // Renumbering all the vertices back if needed
            {

                RenumVGraph (A, (-1+mn), weighted);
                RenumVGraph (R, (-1+mn), false, true);
                RenumVGraph (order, (-1+mn), false, true);

            }

        return 0; // means both Hamiltonian Path and Topological Sorting returned
}




int TSortHP (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <int> & R, std::vector <int> & order, std::vector <int> & Isolated, const bool OnlyTS = false)
// Модификация функции TSortHP (см. выше) для случая нецелочисленных весов ребер (double).
// Modification of the function TSortHP (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.


{
    R.clear(); order.clear(); Isolated.clear();
    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;

    return TSortHP (A.first, R, order, Isolated, false, OnlyTS);

}




int DistanceBFA (std::vector <int> &A, std::vector <long long int> & D, const int b, std::vector <int> & Prev, const bool weighted, int V = INT_MIN)
{

    // Рассчитывает расстояния от заданной вершины b до всех прочих в орграфе (используется метод поиска в ширину).
    // Возвращается 1 в случае успеха (вектор D содержит кратчайшие расстояния от вершины b до вершины i, а вектор Prev - индекс вершин-предков в таком пути).
    // По умолчанию вектор D содержит значения LLONG_MAX, а вектор Prev - "-1".
    // Если в ходе работы обнаружен цикл негативного веса, то функция возвращает -1 и пустые вектора D и Prev.
    // На входе д.б. граф, заданный вектором смежности A (считается, что вершины нумеруются с 0), номер исходной вершины b и флаг, является ли граф взвешенным (const bool weighted). Для невзвешенных считается, что каждое ребро имеет вес = 1.
    // Также на вход подается номер наибольшей вершины V (если не передан, рассчитывается самостоятельно как номер наибольшей вершины в ребрах)
    // Функция работает со взвешенными и с невзвешенными графами, причем они могут содержать петли и множественные ребра. Ребра могут иметь как неотрицательный (в т.ч. и нулевой), так и отрицательный вес.

    // The function counts the shortest distances from the vertex b to all vertices in the graph (these distances are to be contained in vector D, i.e. D[i] means the shortest distance from b to I).
    // By default vector D is filled with LLONG_MAX.
    // Vector Prev is intended to contain the number of the previous vertex for every vertex in such shortest paths ("-1" value is set by default and means "this vertex doesn't included in any such path").
    // The Breadth-first search method is used here.
    // The input graph should be directed, both weighted or unweighted (in case of unweighted graph we consider every edge's weight as "1".) The graph may have loops and multiple edges.
    // Input data: Adjacency vector A (it is supposed that vertices are numbered starting from 0) and the maximum vertex number V (V may be not set, in this case it will be the maximum vertex number of Adjacency vector A)
    // The edges may have weight of 0, >0, <0.
    // In case we found a negative weight cycle as well as input data is incorrect the function returns "-1" and empty D and Prev.


    D.clear();
    Prev.clear();

    if (A.size()==0) return -1;

    if ((V<0)&&(V != INT_MIN)) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness




    int E = A.size()/(2+weighted); // the total number of edges in the graph


    int mn, mx;
    RangeVGraph (A, mx, mn, weighted);


    if (mn<0)  // // checking for input data correctness.
    {
        return -1;
    }


    if (mx>V) V = mx; // здесь будет максимальный номер вершины // the max number of assigned to vertices

    if ((b<0) || (b>V))  // // checking for input data correctness: number of the vertex b must be in range [0, V].
    {
        return -1;
    }

    D.resize(V+1, LLONG_MAX); // По умолчанию расстояния равны + бесконечность // The default distance values is LLONG_MAX for every vertex


    Prev.resize(V+1, -1); // по умолчанию "предка" нет. // The previous vartexes are not set by default (i.e. =-1 for every vertex)


    std::queue <int> Q; //вектор очереди


   D[b] = 0; //дистанция от первой вершины до себя = 0 // the distance from starting vertex to itself = 0

   Q.push (b);

    unsigned int j;
    int i;
    long long int count = 0;
    long long int c = (long long int)(V*E);




    while (!(Q.empty()))
    {
        j = 0;// индекс пробега по вектору смежности A // indexes of beginning-vertices of edges in A
        i = Q.front(); // номер очередной вершины из очереди к рассмотрению (добавляем в конец, достаем с начала) // number of vertex to continue from

        while (j<=A.size()-2-weighted) // lets look through A
        {

            if (weighted)
            {
                // for a weighted graph:

                if (  (A[j]==i) &&  (A[j+1]==i) &&  (A[j+2]<0) )  {D.clear(); Prev.clear(); return -1;} // i.e. we have found a negative weight loop

                if (  (A[j]==i) && ((D[ (A[j+1] )] == LLONG_MAX) || (D[ (A[j+1]) ] > (D[ i ]+ (long long int)(A[j+2]) ) ))  )
                // we should recount distance if we have found non-visited vertex or we may reduce its distance from vertex b.

                {
                    Q.push(A[j+1]);  //эту j+1 вершину - в очередь // in this casr we should push such vertex to quenue Q
                    count++;
                    D[(A[j+1])] = D[(i)]+(long long int)(A[j+2]); // по ней посчитаем дистанцию // and recount its distance from b

                    Prev [(A[j+1])] = i;// и предка // and reset its previous vertex too
                }

            }

            if (!weighted)
            {
            // для невзвешенного все аналогично, но считаем что вес каждого ребра =1
            // for an unweighted graph lets put every edge has distance =1.


                if (  (A[j]==i) && ((D[ (A[j+1] )] == LLONG_MAX) || (D[ (A[j+1]) ] > (D[ i ]+1) ))  )
                //если нашли вершину i и следующая за ней (за номером j+1 в векторе А): (1) не исходная (от которой считаем, равная b),
                // и (2) дистанция до нее равна LLONG_MAX (там еще не были) либо больше дистанции до i, увеличенной на A[j+1] (путь через i + последнее ребро из i)
                // we should recount distance if we have found non-visited vertex or we may reduce its distance from vertex b.

                {
                    Q.push(A[j+1]);  //эту j+1 вершину - в очередь // in this casr we should push such vertex to quenue Q
                    count++;
                    D[(A[j+1])] = D[(i)]+1; // по ней посчитаем дистанцию // and recount its distance from b

                    Prev [(A[j+1])] = i;// и предка // and reset its previous vertex too
                }

            }

            j = j+2+weighted;
        }

        Q.pop();

        if (count > (c)) //Значит, мы наткнулись на цикл отрицательного веса // This means we found a negative weight cycle
        {
            D.clear();
            Prev.clear();

            return -1;
        }

    }




    return 0;
}



int DistanceBFA (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <long double> & D, const int b, std::vector <int> & Prev, int V = INT_MIN)
// Модификация функции DistanceBFA (см. выше) для случая нецелочисленных весов ребер (double).
// Modification of the function DistanceBFA (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.

{
    D.clear();
    Prev.clear();
    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;



    if ((V<0)&&(V != INT_MIN)) return -1;





    int E = (A.first).size()/(2); // the total number of edges in the graph


    int mn, mx;
    RangeVGraph (A.first, mx, mn, false);


    if (mn<0)  // // checking for input data correctness.
    {
        return -1;
    }


    if (mx>V) V = mx; // здесь будет максимальный номер вершины // the max number of assigned to vertices

    if ((b<0) || (b>V))  // // checking for input data correctness: number of the vertex b must be in range [0, V].
    {
        return -1;
    }

    D.resize(V+1, INFINITY); // По умолчанию расстояния равны + бесконечность // The default distance values is INFINITY for every vertex


    Prev.resize(V+1, -1); // по умолчанию "предка" нет. // The previous vartexes are not set by default (i.e. =-1 for every vertex)


    std::queue <int> Q; //вектор очереди


   D[b] = 0.0; //дистанция от первой вершины до себя = 0 // the distance from starting vertex to itself = 0

   Q.push (b);

    unsigned int j;
    int i;
    long long int count = 0;
    long long int c = (long long int)(V*E);




    while (!(Q.empty()))
    {
        j = 0;// индекс пробега по вектору смежности A // indexes of beginning-vertices of edges in A
        i = Q.front(); // номер очередной вершины из очереди к рассмотрению (добавляем в конец, достаем с начала) // number of vertex to continue from

        while (j<A.second.size()) // lets look through A
        {


                if (  ( (A.first)[2*j]==i) &&  ( (A.first)[2*j+1]==i) &&  ( (A.second)[j]<0) )  {D.clear(); Prev.clear(); return -1;} // i.e. we have found a negative weight loop

                if (  ( (A.first)[2*j]==i) && ( (D[ (A.first)[2*j+1] ] == INFINITY) || (D[ (A.first)[2*j+1] ] > (D[ i ]+ (long double)((A.second)[j]) ) )  ) )
                // we should recount distance if we have found non-visited vertex or we may reduce its distance from vertex b.

                {
                    Q.push((A.first)[2*j+1]);  //эту вершину - в очередь // in this casr we should push such vertex to quenue Q
                    count++;
                    D[ (A.first)[2*j+1] ] = D[ i ]+ (long double)((A.second)[j]); // по ней посчитаем дистанцию // and recount its distance from b

                    Prev [ (A.first)[2*j+1] ] = i;// и предка // and reset its previous vertex too
                }

            j = j+1;
        }

        Q.pop();

        if (count > (c)) //Значит, мы наткнулись на цикл отрицательного веса // This means we found a negative weight cycle
        {
            D.clear();
            Prev.clear();

            return -1;
        }

    }

    return 0;
}



int DistanceBFA (std::vector <int> &A, std::vector <long long int> & D, const int b, const bool weighted, int V = INT_MIN)
{
    // Модификация функции DistanceBFA (см. выше): нет поиска массива предков и вместо поиска в ширину применен алгоритм Беллмана — Форда.
    // Рассчитывает расстояния от заданной вершины b до всех прочих в орграфе.
    // Возвращается 1 в случае успеха (вектор D содержит кратчайшие расстояния от вершины b до вершины i).
    // По умолчанию вектор D содержит значения LLONG_MAX, а вектор Prev - "-1".
    // Если в ходе работы обнаружен цикл негативного веса, то функция возвращает -1 и пустой вектор D.
    // На входе д.б. граф, заданный вектором смежности A (считается, что вершины нумеруются с 0), номер исходной вершины b и флаг, является ли граф взвешенным (const bool weighted). Для невзвешенных считается, что каждое ребро имеет вес = 1.
    // Также на вход подается номер наибольшей вершины V (если не передан, рассчитывается самостоятельно как номер наибольшей вершины в ребрах)
    // Функция работает со взвешенными и с невзвешенными графами, причем они могут содержать петли и множественные ребра. Ребра могут иметь как неотрицательный (в т.ч. и нулевой), так и отрицательный вес.

    // Modification of the function DistanceBFA (used Bellman–Ford algorithm instead of Breadth-First Search and here is no search for previous vertices for every vertex in such shortest paths).
    // The function counts the shortest distances from the vertex b to all vertices in the graph (these distances are to be contained in vector D, i.e. D[i] means the shortest distance from b to I).
    // By default vector D is filled with LLONG_MAX.
    // The Bellman–Ford algorithm is used here.
    // The input graph should be directed, both weighted or unweighted (in case of unweighted graph we consider every edge's weight as "1".) The graph may have loops and multiple edges.
    // Input data: Adjacency vector A (it is supposed that vertices are numbered starting from 0) and the maximum vertex number V (V may be not set, in this case it will be the maximum vertex number of Adjacency vector A)
    // The edges may have weight of 0, >0, <0.
    // In case we found a negative weight cycle as well as input data is incorrect the function returns "-1" and empty D.


    D.clear();

    if (A.size()==0) return -1;

    if ((V<0)&&(V != INT_MIN)) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness


     int mn, mx;
    RangeVGraph (A, mx, mn, weighted);


    if (mn<0)  // // checking for input data correctness.
    {
        return -1;
    }


    if (mx>V) V = mx; // здесь будет максимальный номер вершины // the max number of assigned to vertices

    if ((b<0) || (b>V))  // // checking for input data correctness: number of the vertex b must be in range [0, V].
    {
        return -1;
    }

    D.resize(V+1, LLONG_MAX); // По умолчанию расстояния равны + бесконечность // The default distance values is LLONG_MAX for every vertex





   D[b] = 0; //дистанция от первой вершины до себя = 0 // the distance from starting vertex to itself = 0

   int f=0;
   for (int i=mn; i<=mx; i++)
   {
       f=0;
       for (int j=0; j<A.size(); j=j+2+weighted) // lets look through A
       {
           if (D[A[j]]== LLONG_MAX) continue;
           if (weighted)
               if ( D[A[j+1]] > D[A[j]] + (long long int)(A[j+2]))
                {
                   D[A[j+1]] = D[A[j]] + (long long int)(A[j+2]);
                   f=1;
                }

           if (!weighted)
               if ( D[A[j+1]] > D[A[j]] + (long long int)(1))
                {
                   D[A[j+1]] = D[A[j]] + (long long int)(1);
                   f=1;
                }

        }

       if (f==0)
       {break;}

       if (i==mx)
           {f=-1; break;}

   }



    if (f==-1)
    {
        D.clear();
        return -1;
    }

    return 0;
}



int DistanceBFA (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <long double> & D, const int b, int V = INT_MIN)
// Модификация функции DistanceBFA (вместо поиска в ширину применен алгоритм Беллмана — Форда для нецелочисленных весов ребер (double)), массив предков не строится.
// Modification of the function DistanceBFA (used Bellman–Ford algorithm instead of Breadth-First Search and here is no search for previous vertices for every vertex in such shortest paths) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.

{
    D.clear();

    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;



    if ((V<0)&&(V != INT_MIN)) return -1;



    int mn, mx;
    RangeVGraph (A.first, mx, mn, false);


    if (mn<0)  // // checking for input data correctness.
    {
        return -1;
    }


    if (mx>V) V = mx; // здесь будет максимальный номер вершины // the max number of assigned to vertices

    if ((b<0) || (b>V))  // // checking for input data correctness: number of the vertex b must be in range [0, V].
    {
        return -1;
    }


    D.resize(V+1, INFINITY); // По умолчанию расстояния равны + бесконечность // The default distance values is INFINITY for every vertex


   D[b] = 0.0; //дистанция от первой вершины до себя = 0 // the distance from starting vertex to itself = 0


   int f=0;
   for (int i=mn; i<=mx; i++)
   {
       f=0;
       for (int j=0; j<A.second.size(); j++) // lets look through A
       {
           if (D[A.first[2*j]]== INFINITY) continue;


           if ( D[A.first[2*j+1]] > D[A.first[2*j]] + (long double)((A.second)[j]) )
                {
                   D[A.first[2*j+1]] = D[A.first[j*2]] + (long double)((A.second)[j]);
                   f=1;
                }

       }



       if (f==0)
       {break;}

       if (i==mx)
           {f=-1; break;}

   }



    if (f==-1)
    {
        D.clear();
        return -1;
    }

    return 0;
}




int DFS_for_NBPaths (const std::vector <int> & A, const bool w, const int b, const int bconst, std::vector <int> & Visited, std::vector <int> & Path)
// An auxiliary function for NBPaths (see it below): DFS for finding isolated cycles
// Вспомогательная функция для NBPaths (см. ниже): обход в глубину графа для поиска изолированных циклов


{
    int f = -1;  // f==-1 means that we have no cycle // флаг что нету цикла
    Visited [b] = 1;


   for (unsigned int r = 0; r<=A.size(); r=r+2+w)
    {

        if ( (A[r]==b) && (Visited [ (A[r+1]) ] == 1) && ((A[r+1])==bconst)  )  // если нашли посещенную, и это - исходная (bconst)
        {                                                                       // if we have found the initial vertex (labeled as "bconst")
           f = 1;  // we have a cycle
           Path.push_back(A[r+1]);
           break;
        }



        if ( (A[r]==b) && (Visited [ (A[r+1]) ] == 0) )  // нашли непосещенную? непосещенная = 0, идем глубже
        {                                                // if we have found an unvisited vertex - let's go deeper
           Visited[(A[r+1])] = 1;
           Path.push_back(A[r+1]);
           f = DFS_for_NBPaths (A, w, (A[r+1]), bconst, Visited, Path);
           if (f==1) break; // если снизу передан успех - его передать наверх  // if we have found a cycle at any step - let's

        }



    }


    return f; //возвращается, что есть цикл, если он обнаружен
}



void Circuit_for_NBPaths (const std::vector <int> & A, const bool w, int V, std::vector <std::vector<int> >&Paths, std::vector <int> & Visited)
// An auxiliary function for NBPaths (see it below): finding isolated cycles
// Вспомогательная функция для NBPaths (см. ниже) для поиска изолированных циклов

{


std::vector <int> Path;
Path.clear();
int t;


    Path.clear();
    Path.push_back(V);

    t=DFS_for_NBPaths (A, w, V, V, Visited, Path); // Let's look for a cycle for the vertice V
    if (t==1)
    {
                Paths.push_back(Path);
    }



}


int NBPaths (std::vector <int> & A, bool w, std::vector <std::vector<int> >&Paths, bool directed = true)
// Finds all maximal non-branching Paths in a graph, that is set by Adjacency vector A.
// Parameter "w" sets if A is a weighted graph or no. Parameter "directed" sets if A is a weighted graph or no.
// The result will be in std::vector <std::vector<int> > Paths. If input data is incorrect returns -1 and empty Paths. If input data is correct returns 0.
// Vertices may be numbered in different ways (they may be marked by both negative and non-negative integers). In order to implement the function vertices may be renumbered to get started from "1"; after search is completed, the vertices will be assigned their original numbers.
// The input graph A may have multiple edges (multiple edges will be considered as non branching paths) and multiple loops (any loop will considered as a non branching path).

// Функция для поиска всех максимально длинных неразветвляющихся путей в графе, заданном вектором смежности А. Параметр w задает, является ли граф взвешенным, или нет.
// Параметр directed - является ли граф ориентированным.
// Результат возвращается в std::vector <std::vector<int> > Paths.
// Возвращает -1 и пустой Paths в случае некорректности исходных данных. В случае успеха вернет 0.
// Может работать с графами, вершины которых заданы любыми целыми числами, в т.ч. - отрицательными.
// Может работать с графами множественными ребрами и множественными петлями (каждое множественное ребро и каждая петля рассматриваются как отдельный путь).


{
    Paths.clear();
    if (A.size()==0) return -1;


    if ( (A.size())%(2+w)!=0 ) return -1; // checking for input data correctness

    int mn, mx;
    RangeVGraph (A, mx, mn, w);

    if (mn<1)  // Приведение вектора к нумерованию вершин с 1 // renumbering vertices to start from 1.
    {
        RenumVGraph (A, (1-mn), w);

    }





    int m = -1; //здесь будет номер максимальной вершины, число вершин  // The maximal vertex number will be set as "m".
    for (int a = 0; a<A.size(); a=(a+2+w))
    {
        if (A[a]>m) m=A[a];
        if (A[a+1]>m) m=A[a+1];
    }

    std::vector <int> Leafs; // Здесь будут вершины разветвления
    Leafs.clear();           // Here the branching vertices will be

    std::vector <int> Vin(m+1, 0); //для подсчета входящих и исходящих в вершину, чтобы определить листья и вершины разветвения.
    std::vector <int> Vout (m+1, 0); // Let's count in and out edges for every vertex in order to find branching vertices

    std::vector <int> EdgeVisited (A.size()/(2+w), -1);



    for (int a = 0; a<A.size(); a=(a+2+w))
    {

        Vin[(A[a+1])]++;
        Vout[(A[a])]++;



    }



    for (int q = 1; q<=m; q++)  // searching for branching vertices
        if ((Vin[q]!=1) || (Vout[q]!=1))
    {        Leafs.push_back(q); // вставляем номер

    }







    std::vector <int> Path;
    Path.clear();
    int u;

    for (int i = 0; i<Leafs.size(); i++)
    {
         l1: u = Leafs[i];
        Path.clear();
        Path.push_back(u);

        l2: for (int j = 0; j<A.size(); j=j+2+w)
        {



            if ((EdgeVisited[j/(2+w)]==-1) && (A[j]==u)) // нашли непосещенное ребро, начинающееся с вершины u
                                                        // if we have found an another unvisited edge starting frov the vertex u

            {
                EdgeVisited[j/(2+w)]=1;//теперь оно посещенное  // now this edge is visited



                Path.push_back(A[j+1]); // в путь - следующую вершину // adding to Path another vertex
                if (FindIn(Leafs, A[j+1])!=-1)  // и если это - вершина разветвления - вывести путь, и наверх - дальше искать пути из вершины u
                {                               // And if it is a branching vertex - ths path is built, let's find another one starting from the vertex u

                    Paths.push_back(Path);

                    goto l1;
                }

                 if (FindIn(Leafs, A[j+1])==-1) // а иначе - ищем дальше с найденой вершины неразветвления // and if no - lets continue path building from the non-branching vertex we have found
                 {
                     u = A[j+1];
                     goto l2;
                 }

            }



        }

    }



    std::vector <int> Visited (m+1, 0);


    for (int i=0; i<EdgeVisited.size(); i++)
    {
        if (EdgeVisited[i]== 1)
        {
            Visited[(A[i*(2+w)])]=1;
            Visited[(A[i*(2+w)+1])]=1;
        }
    }





    int m1 = FindIn(Visited, 0, 1, 1);
    while (m1!=-1)
    {
    Circuit_for_NBPaths(A, w, m1, Paths, Visited); // а теперь - изолированные циклы; // now let's find isolated cycles
    m1 = FindIn(Visited, 0, 1, 1);
    }


    if ((!directed) && (Paths.size()>1)) // if the Graph is undirected - let's glue together paths that have the same begin-vertex and/ or end-vertex and if such vertices are not branching ones
    {


        int f1, f2, l1, l2;

        for (int i=0; i<Paths.size()-1;i++)
        {
            if (Paths[i].size()<2) continue;
            if (Paths[i][0]==Paths[i][Paths[i].size()-1]) continue;

            for (int j=1+i; j<Paths.size();j++)
                {

                    if (Paths[j].size()<2) continue;

                    if (Paths[j][0]==Paths[j][Paths[j].size()-1]) continue;



                    f1 = Paths[i][0];

                    f2 = Paths[j][0];

                    l1 = Paths[i][Paths[i].size()-1];

                    l2 = Paths[j][Paths[j].size()-1];


                    if ((l1 == f2) && (Vin[l1]+Vout[l1]==2))
                    {
                        for (int x=1; x<Paths[j].size(); x++)
                            Paths[i].push_back(Paths[j][x]);
                        Paths[j].clear();
                        j=i;
                        continue;
                    }

                    if ((l1 == l2)&&(Vin[l1]+Vout[l1]==2))
                    {

                        reverse(Paths[j].begin(), Paths[j].end());
                        for (int x=1; x<Paths[j].size(); x++)
                            Paths[i].push_back(Paths[j][x]);
                        Paths[j].clear();
                        j=i;
                        continue;
                    }


                    if ((l2 == f1)&&(Vin[l2]+Vout[l2]==2))
                    {
                       reverse(Paths[i].begin(), Paths[i].end());
                       reverse(Paths[j].begin(), Paths[j].end());

                       for (int x=1; x<Paths[j].size(); x++)
                           Paths[i].push_back(Paths[j][x]);
                       Paths[j].clear();
                       j=i;
                       continue;
                    }



                    if ((f2 == f1)&&(Vin[f1]+Vout[f1]==2))
                    {
                        reverse(Paths[i].begin(), Paths[i].end());

                        for (int x=1; x<Paths[j].size(); x++)
                            Paths[i].push_back(Paths[j][x]);
                        Paths[j].clear();
                        j=i;
                        continue;
                    }

                }
            }




        for (int i=0; i<Paths.size();i++)
        {
            if (Paths[i].size()==0)
            {
                Paths.erase(Paths.begin()+i);
                i--;
            }
        }


    }



    if (mn<1)  // Приведение вектора к нумерованию вершин с 1 // renumbering vertices to start from 1.
    {
        RenumVGraph (A, (mn-1), w);
        for (int i = 0; i<Paths.size(); i++)
            RenumVGraph (Paths[i], (mn-1), w, true);

    }



return 0;


}



int NBPaths (std::pair < std::vector<int>, std::vector<double>> & P, std::vector <std::vector<int> >&Paths, bool directed = true)
// Модификация функции NBPaths (см. выше) для случая нецелочисленного веса ребер.
// Modification of the function NBPaths (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.




{
    Paths.clear();
    if ((P.first).size()==0) return -1;
    if ((P.second).size()==0) return -1;
    if (  (P.first).size()!=((P.second).size())*2 ) return -1;



    return NBPaths (P.first, false, Paths, directed);

}



long long int MaxFlowGraph (std::vector <int> A, const bool weighted, int b, int e, std::vector <std::vector<int> >&Paths, std::vector <int> &Flows, std::vector < std::pair < int, int> > &MinCut)
// Функция для поиска максимального потока в графе из вершины b в вершину e; граф задается вектором смежности А;
// параметр weighted определяет, является ли граф взвешенным (если взвешенный - "Истина", при этом веса ребер здесь могут быть лишь целыми положительными).
// Может работать с множественными ребрами (рассматриваются как одно "объединенное" ребро с суммарным весом) и с множественными петлями (петли игнорируются).
// Вершины графа должны быть неотрицательны, веса ребер - только положительны
// Возвращает: (1) величину максимального потока, (2) заполненный вектор путей Paths, слагающих максимальный поток (один из возможных вариантов построения Paths, если их может быть несколько),
// (3) соответствующие этим путям значения потоков в векторе Flows, (4) перечень ребер минимального разреза графа в векторе MinCut (каждое ребро задано парой вершин).
//  В случае некорректных исходных данных или отсутствия пути из b в e возвращает -1 и пустые Paths, Flows, MinCut.


// Finds maximal flow from vertex b to vertex e in the graph A (set by Adjacency vector A).
// Parameter "weighted" sets if A is a weighted graph or no. All vertices of A should have only non-negative marks.
// For a weighted graph edges should have only positive values.
// Graph A may have multiple edges (multiple edges will be considered as one joined edge that have its weight = sum of the weights of all joined edges) and multiple loops (loops will be ignored).
// Returnes: maximal flow value and 3 vectors: vector Paths (contains all the paths of the maximal flow network (one of the possible solutions if >1 solutions exist))
// vector Flows (contains values of a flow for a index-relevant Path (i.e. Flows[0] for Paths [0], etc)),
// vector MinCut (contains the max-flow min-cut as an array of edges: every edge is set as a pair of its vertices).
// If input data is incorrect or there are no path from b to e returns -1 and empty Paths and Flows.



{

    long long int Result=0;// здесь будет результат // Here a result will be
    Paths.clear(); // здесь будут пути, слагающие макспоток
    Flows.clear(); // а здесь  - соответствующие им величины подпотоков, слагающие общий поток из b в е
    MinCut.clear(); // А здесь будет минимальный разрез

    if (A.size()==0) return -1;

    if ((b<0) || (e<0))  return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness

    int mn, mx;
    RangeVGraph (A, mx, mn, false, true);
    if (mn<0) return -1; // все вершины и веса д.б. неотрицательны // all vertices should have non-negative marks. All weights shouldn't be negative too.



    if (FindIn(A, b, (2+weighted), 0) == -1) return -1; // Проверка что вершины b (как исток) и e (как сток) есть в графе
    if (FindIn(A, e, (2+weighted), 1) == -1) return -1; // Checking for vertex b (as source) and vertex e (as sink) both are in the graph

    if (weighted)
        if (FindIn(A, 0, (2+weighted), 2) != -1) return -1; // weighted graph should not have zero-valued edges



    std::map <std::pair < int, int> , int> G2;
    G2.clear();


    if (AdjVectorToAdjMap (A, G2, weighted)==-1) return -1;


    int l=INT_MAX;
    int x;
    std::pair < int, int> C;


    std::vector <long long int> D; D.clear();
    std::vector <int> Prev; Prev.clear();
    std::vector <int> Path; Path.clear();

    int d = DistanceBFA (A, D, b, Prev, weighted);
    if (D[e]==LLONG_MAX) return -1; // в этом случае е недостижима из b // In this case we have no path from b to e.


    while (d!=-1)
    {
        if (D[e]==LLONG_MAX) break; // в этом случае е недостижима из b  // In this case we have no path from b to e.
        if (D.size()<=e) break; // в этом случае е недостижима из b  // In this case we have no path from b to e.

        // строим путь из b в е
        // Let's build path from b to e.

        Path.clear();
        x = e;


        while (x!=-1)
        {
            Path.push_back(x);
            if (x==b)
            {

                break;
            }

            x = Prev[x];

        }

        std::reverse(std::begin(Path), std::end(Path));

        // построили путь из b в е
        // We have a path from b to e.

        l=INT_MAX;
        for (int q=0; q<Path.size()-1; q++)  // ищем ребро с самой низкой пропускной способностью и записываем пропускную способноость в l
        {                                    // looking for an edge with the minimal non-zero weight in the Path
            C = std::make_pair(Path[q], Path[q+1]);
            if ((l>G2[C])&&(G2[C]>0))
            {l = G2[C]; }

        }





        for (int q=0; q<Path.size()-1; q++)  // Вычитаем l по всему найденному пути // recalculating weights of all edges of the Path
        {
           C = std::make_pair(Path[q], Path[q+1]);
            G2[C] = G2[C]-l;
            if (G2[C]==0)
            {
                G2.erase(G2.find(C));
                MinCut.push_back(C);
            }

        }


        Result=Result+l;
        Flows.push_back(l);
        Paths.push_back(Path);

        AdjMapToAdjVector (A, G2);


        d = DistanceBFA (A, D, b, Prev, weighted);
    }



for (int y=0; y<MinCut.size(); y++)
{

    if ((D[(MinCut[y].first)]==LLONG_MAX) || (MinCut[y].first>=D.size())) {MinCut.erase(MinCut.begin()+y); y--; }

}


    return Result;
}


long double MaxFlowGraph (std::pair < std::vector<int>, std::vector<double>> A, int b, int e, std::vector <std::vector<int> >&Paths, std::vector <double> &Flows, std::vector < std::pair < int, int> > &MinCut)
// Модификация функции MaxFlowGraph (см. выше) для случая нецелочисленных весов ребер (double).
// Modification of the function MaxFlowGraph (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.



{

    long double Result=0.0;// здесь будет результат  // Here a result will be
    Paths.clear(); // здесь будут пути, слагающие макспоток
    Flows.clear(); // а здесь  - соответствующие им величины подпотоков, слагающие общий поток из b в е
    MinCut.clear(); // А здесь будет минимальный разрез
    if ((b<0) || (e<0))  return -1;


    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;


    int mn, mx;
    RangeVGraph (A.first, mx, mn, false, true);
    if (mn<0) return -1; // все вершины д.б. неотрицательны  // all vertices should have non-negative marks.



    if (FindIn(A.first, b, 2, 0) == -1) return -1; // Проверка что вершины b (как исток) и e (как сток) есть в графе
    if (FindIn(A.first, e, 2, 1) == -1) return -1; // Checking for vertex b (as source) and vertex e (as sink) both are in the graph


    for (unsigned int q=0; q<A.second.size(); q++)
        if (A.second[q]<=0.0) return -1; // weighted graph should not have subzero-valued edges




    std::map <std::pair < int, int> , double> G2;
    G2.clear();


    if (AdjVectorToAdjMap (A, G2)==-1) return -1;


    double l=INFINITY;
    int x;
    std::pair < int, int> C;


    std::vector <long double> D; D.clear();
    std::vector <int> Prev; Prev.clear();
    std::vector <int> Path; Path.clear();

    int d = DistanceBFA (A, D, b, Prev);
    if (D[e]==INFINITY) return -1; // в этом случае е недостижима из b  // In this case we have no path from b to e.


    while (d!=-1)
    {
        if (D[e]==INFINITY) break; // в этом случае е недостижима из b  // In this case we have no path from b to e.
        if (D.size()<=e) break; // в этом случае е недостижима из b  // In this case we have no path from b to e.

        // строим путь из b в е
        // Let's build path from b to e.

        Path.clear();
        x = e;


        while (x!=-1)
        {
            Path.push_back(x);
            if (x==b)
            {

                break;
            }

            x = Prev[x];

        }
        // построили путь из b в е
         // We have a path from b to e.

        std::reverse(std::begin(Path), std::end(Path));





        l=INFINITY;
        for (int q=0; q<Path.size()-1; q++)  // ищем ребро с самой низкой пропускной способностью и записываем пропускную способноость в l
        {                                    // looking for an edge with the minimal non-zero weight in the Path
            C = std::make_pair(Path[q], Path[q+1]);
            if ((l>G2[C])&&(G2[C]>0.0))
            {l = G2[C]; }

        }





        for (int q=0; q<Path.size()-1; q++)  // Вычитаем l по всему найденному пути  // recalculating weights of all edges of the Path
        {
           C = std::make_pair(Path[q], Path[q+1]);
            G2[C] = G2[C]-l;
            if (G2[C]==0.0)

            {
                G2.erase(G2.find(C));
                MinCut.push_back(C);
            }

        }


        Result=Result+l;
        Flows.push_back(l);
        Paths.push_back(Path);

        AdjMapToAdjVector (A, G2);


        d = DistanceBFA (A, D, b, Prev);
    }



    for (int y=0; y<MinCut.size(); y++)
    {


        if ((D[(MinCut[y].first)]==INFINITY) || (MinCut[y].first>=D.size())) {MinCut.erase(MinCut.begin()+y); y--; }

    }

    return Result;
}



void DFSAllPathsDGraph (std::vector <int>&A, std::vector <int> &Visited, const int &b, const int &e, const bool weighted, std::set <std::vector <int>> & GPath, std::vector <int> &Path)
// An auxiliary function for AllPathsDGraph (see it below)
// Вспомогательная функция для AllPathsDGraph (см. ниже)
{
    Path.push_back(b);
    Visited [b]=1;

    for (int i=0; i<A.size(); i = i+2+ weighted)
    {


        if( (A[i]==b) && (A[i+1]==e))
        {
            Path.push_back(e);

            GPath.insert(Path);


            Path.pop_back();
            continue;
        }




        if( (A[i]==b) && (Visited [A[i+1]]==0) )
        {
            //Visited [A[i+1]]=1;
            DFSAllPathsDGraph (A, Visited, A[i+1], e, weighted, GPath, Path);
            Visited [A[i+1]]=0;
        }

    }

    Path.pop_back();
}




int AllPathsDGraph (std::vector <int>&A, const int &b, const int &e, const bool weighted, std::set <std::vector <int>> & GPath)
// An experimental function to find all paths from the vertex b to the vertex e of directed graph that is set by Adjacency vector A. May be too slow or have some mistakes.
// A may be weighted or no (set by weighted).
// Returns 0 and set of paths found in GPath, if input data are incorrect returns -1 and empty GPath.
// Экспериментальная функция для поиска всех путей в ориентированном графе из вершины b в вершину e. Может работать неточно и долго.
// Граф задается вектором смежности A. weighted задает, взвешенный ли он.
// Возвращает 0 и найденные пути в GPath, в случае некорректных исходных данных вернет пустой GPath и -1.

{
    GPath.clear();
    if (A.size()==0) return -1;
    if ((A.size()%(2+weighted))!=0) return -1;

    std::vector <int> Path;
    Path.clear();

    int mn, mx;

    RangeVGraph(A, mx, mn, weighted);

    std::vector <int> Visited (mx+1, 0);


    DFSAllPathsDGraph (A, Visited, b, e, weighted, GPath, Path);

    return 0;

}

int DFS_for_Cycles (const std::vector <int> & A, const bool w, const int b, const int bconst, std::vector <int> & Visited, std::vector <int> & Path, std::set <std::vector <int>> &GPath, int &mn, const bool &directed)
// An auxiliary function for Cycles_in_Graph (see it below): DFS for finding cycles
// Вспомогательная функция для Circles_in_Graph (см. ниже): обход в глубину графа


{

    if (directed)
    {

    Visited [b] = 1;
    Path.push_back(b+mn*(mn<0) );


   for (unsigned int r = 0; r<A.size(); r=r+2+w)
    {

        if ( (A[r]==b) && ((A[r+1])==bconst) && (b!=bconst) )  // если нашли исходную (bconst)
        {                                                                       // if we have found the initial vertex (labeled as "bconst")

           Path.push_back(A[r+1]+mn*(mn<0));


           GPath.insert(Path);
            Path.pop_back();


            continue;
        }



        if ( (A[r]==b) && (Visited [ (A[r+1]) ] == 0)  && ((A[r+1])!=bconst) )  // нашли непосещенную? непосещенная = 0, идем глубже
        {                                                // if we have found an unvisited vertex - let's go deeper
           Visited[(A[r+1])] = 1;


           DFS_for_Cycles (A, w, A[r+1], bconst, Visited, Path, GPath, mn, directed);
           Visited[(A[r+1])] = 0;
           Path.pop_back();


           Visited [bconst] = 1;
        }


   }


}

    if (!directed)
    {

    Visited [b] = 1;
    Path.push_back(b+mn*(mn<0) );



   for (unsigned int r = 0; r<A.size(); r=r+2+w)
    {

        if ( (A[r]==b) && ((A[r+1])==bconst) && (b!=bconst) )  // если нашли исходную (bconst)
        {                                                                       // if we have found the initial vertex (labeled as "bconst")


            Path.push_back(A[r+1]+mn*(mn<0));



            if ((Path.size()>3)&& (GPath.find(Path)==GPath.end()))
            {
                std::reverse(std::begin(Path),std::end(Path));
                GPath.insert(Path);
                std::reverse(std::begin(Path),std::end(Path));
            }

            Path.pop_back();



            continue;
        }

        if ( (A[r+1]==b) && ((A[r])==bconst) && (b!=bconst) )  // если нашли исходную (bconst)
        {                                                                       // if we have found the initial vertex (labeled as "bconst")


            Path.push_back(A[r]+mn*(mn<0));



           if ((Path.size()>3)&& (GPath.find(Path)==GPath.end()))
           {
               std::reverse(std::begin(Path),std::end(Path));
               GPath.insert(Path);
               std::reverse(std::begin(Path),std::end(Path));
           }

            Path.pop_back();



            continue;
        }



        if ( (A[r]==b) && (Visited [ (A[r+1]) ] == 0)  && ((A[r+1])!=bconst) )  // нашли непосещенную? непосещенная = 0, идем глубже
        {                                                // if we have found an unvisited vertex - let's go deeper
           Visited[(A[r+1])] = 1;



           DFS_for_Cycles (A, w, A[r+1], bconst, Visited, Path, GPath, mn, directed);
           Visited[(A[r+1])] = 0;
           Path.pop_back();



           Visited [bconst] = 1;
           continue;
        }


        if ( (A[r+1]==b) && (Visited [ (A[r]) ] == 0)  && ((A[r])!=bconst) )  // нашли непосещенную? непосещенная = 0, идем глубже
        {                                                // if we have found an unvisited vertex - let's go deeper
           Visited[(A[r])] = 1;



           DFS_for_Cycles (A, w, A[r], bconst, Visited, Path, GPath, mn, directed);
           Visited[(A[r])] = 0;
           Path.pop_back();



           Visited [bconst] = 1;
           continue;
        }

   }


}


    return 0;
}



int Cycles_in_Graph (std::vector <int> & A, const bool w, std::set <std::vector<int> >&Paths, std::set <int> &StartV, const bool directed = true)
// An experimental function to find simple cycles in graph that is set by Adjacency vector A. May be too slow or have some mistakes.
// A may be weighted or no (set by w) and directed or no (set be directed).
// If StartV is not empty, the function searches only for cycles that contain any vertex in StartV.
// Returns the number of cycles found and set of cycles themselves in Paths, if input data are incorrect returns -1 and empty Paths.
// Экспериментальная функция для поиска простых циклов в графе. Может работать неточно и долго.
// Если множество StartV непустое, ищет циклы только через эти вершины.
// Граф задается вектором смежности A. w задает, взвешенный ли он, а directed - ориентированный ли он.
// Возвращает кол-во найденных циклов и сами найденные циклы в Paths, в случае некорректных исходных данных вернет пустой Paths и -1.

{
    Paths.clear();
    if (A.size()==0) return -1;
    if ( (A.size())%(2+w)!=0 ) return -1; // checking for input data correctness

    int mn, mx;

    bool f = (StartV.size()==0);

    RangeVGraph(A, mx, mn, w);

    if (mn<0)  // Приведение вектора к нумерованию вершин с 0 // renumbering vertices to start from 0.
    {
        RenumVGraph (A, (0-mn), w);
        mx = mx+(0-mn);


    }



    std::vector <int> Path;

    Path.clear();

    std::map <std::pair < int, int> , int> G2;

    if (!directed)  // если неориентированный граф - добавляем кратные ребра как циклы
    {
        AdjVectorEdgesMultiplicity (A, G2, w, false);
        for (int i=0; i<A.size(); i = i+2+w)
        {
            if ((G2[std::pair<int, int>(A[i], A[i+1])]>=2) && (A[i]!=A[i+1]))
                if ( ((StartV.find(A[i] + mn*(mn<0)) != StartV.end()) && (StartV.find(A[i+1] + mn*(mn<0)) != StartV.end()) && (!f)) || (f) )
                    Paths.insert({  std::min(A[i], A[i+1])+mn*(mn<0), std::max(A[i], A[i+1])+mn*(mn<0), std::min(A[i], A[i+1])+mn*(mn<0) });
        }
        G2.clear();

    }



    for (int i=0; i<A.size(); i = i+2+w)  // В любом случае добавляем петли
    {
        if (A[i]==A[i+1])
            if ( ((StartV.find(A[i] + mn*(mn<0)) != StartV.end()) && (StartV.find(A[i+1] + mn*(mn<0)) != StartV.end()) && (!f)) || (f) )
                Paths.insert({A[i]+mn*(mn<0), A[i+1]+mn*(mn<0)});


    }



    std::vector <int> Vin(mx+1, 0); //для подсчета входящих и исходящих в вершину
    std::vector <int> Vout (mx+1, 0); // for counting in-edges and out-edges

    for (int q=0; q<A.size()-1-w; q= q+2+w)
    {
        Vin[(A[q+1])]++;
        Vout[(A[q])]++;
        if (!directed)
        {
            Vout[(A[q+1])]++;
            Vin[(A[q])]++;
        }


    }



   std::vector <int> Visited (mx+1, 0);

    std::vector <std::vector<int> >P;
    P.clear();



    if (f)
    {
        NBPaths (A, w, P, directed);



        for (int j=0; j<P.size(); j++)
        {
            if (Vin[P[j][0]]*Vout[P[j][0]]!=0)
                StartV.insert(P[j][0]);
            if (Vin[P[j][P[j].size()-1]]*Vout[P[j][P[j].size()-1]]!=0)
                StartV.insert(P[j][P[j].size()-1]);
        }

    }

        for (auto it = StartV.begin(); it!=StartV.end(); it++)
        {
            Path.clear();
            DFS_for_Cycles (A, w, *it-mn*(mn<0), *it-mn*(mn<0), Visited, Path, Paths, mn, directed);
            Visited [*it-mn*(mn<0)] = 2;
        }




    if (mn<0)  // Обратное переименование вершин если необходимо // renumbering vertices back it needed.
    {
        RenumVGraph (A, (mn), w);


    }

return Paths.size();

}



template < typename TMEE>
int MatrixEraseElement (std::vector <std::vector <TMEE>> & B, const int &j)
{
    // Удаление элемента j из матрицы B, матрица может содержать элементы произвольных типов.
    // Нумерация элементов - с нуля. если матрица пустая или элемент в ней не содержится (задан слишком большой его номер) - выдаст -1, если успех - 0.
    // Строки матрицы могут быть, в принципе, не равны друг другу по днине

    // Erasing an element #j from matrix B (0-based indexing)
    // If input data are incorrect return -1. If success returns 1
    // NB Matrix B may have rows of different lenght.

     if (B.size()<=j) return -1;
     if (j<0) return -1;
     for (int w=0;w<B.size();w++)
     {
         if (B[w].size()<=j) return -1;
     }

     B.erase(B.begin()+j)    ;
     for (int w=0;w<B.size();w++)
     {
         B[w].erase(B[w].begin()+j);
     }

    return 0;
}

int UWGraphFromWGraph (const std::vector <int> &P1, std::vector <int> &P2)
// Construct unweighted graph P2 upon weighted graph P1 (only edges without their weights are to be included to P2).
// P1 and P2 are set by adjacency vector.
// If success returns 0. If input data incorrect returns -1 and empty P2
// Конструирует невзвешенный граф Р2 из взвешенного Р2 (копируются ребра без весов). Вектора заданы векторами смежности.
// Если успех - возвращает 0, если исходные данные некорректны - вернет -1 и пустой Р2.
{
P2.clear();

if (P1.size()%3!=0) return -1;

for (int q=0; q<P1.size();q=q+3)
{
    P2.push_back(P1[q]);
    P2.push_back(P1[q+1]);
}

return 0;

}


int WGraphFromUWGraph (const std::vector <int> &P1, std::vector <int> &P2)
// Construct weighted graph P2 upon unweighted graph P1 (let the weight of every edge is = 1).
// P1 and P2 are set by adjacency vector.
// If success returns 0. If input data incorrect returns -1 and empty P2
// Конструирует взвешенный граф Р2 из невзвешенного Р2 (считается, что вес любого ребра =1). Вектора заданы векторами смежности.
// Если успех - возвращает 0, если исходные данные некорректны - вернет -1 и пустой Р2.
{
P2.clear();

if (P1.size()%2!=0) return -1;

for (int q=0; q<P1.size();q=q+2)
{
    P2.push_back(P1[q]);
    P2.push_back(P1[q+1]);
    P2.push_back(1);
}

return 0;

}


int PathFromPrev (std::vector <int> &Path, const std::vector <int> &Prev, const int b, const int e, const bool ignoreb = false)
// Вспомогательная функция. Конструирует путь Path в графе от вершины b до e согласно массиву предков Prev. Prev [i] содержит номер вершины-предка для вершины i, либо -1, если предка нет.
// Путь собирается "от конца", т.е. от вершины е. Если bool ignoreb = false, то ищется путь строго от b до е. Иначе - началом пути также может быть некоторая вершина, не имеющая предка.
// Если входные данные некорректны, вернет -1 и пустой Path. В случае успеха вернет 0.

// An auxiliary function. Constructs path Path in some graph from vertex b to vertex e upon an array of Prev.
// Prev [i] contains the number of the previous vertex of the vertex i in the Path or -1 if vertex i has no previous vertex.
// Returns -1 and empty Path if input data are incorrect. If success returns 0.
// If bool ignoreb = false the function looks for path from b to e exactly.
// Otherwise it may also return a path starting from some vertex with no previous one, if only such path may be constructed to the vertex e (from-end-to begin construction is implemented).



{
Path.clear();

if (b<0) return -1;
if (e<0) return -1;

if (b>=Prev.size()) return -1;
if (e>=Prev.size()) return -1;


if (b==e)
{
    Path.push_back(e);
    return 0;
}

int x = e;
while(x>=0)
{

    Path.push_back(x);
    x = Prev[x];
    if (x==b)
    {
        Path.push_back(x);
        break;
    }
}

std::reverse(Path.begin(), Path.end());
if (!ignoreb)
    if (Path[0]!=b)
        Path.clear();

return 0;

}



int SubGraphsInscribed (std::vector <int> A, std::vector <int> B, std::set<std::vector <int>> & Result, const bool directed = true)
// The function finds all inscribed subgraphs in unweighted graph A that are isomorphic to unweighted graph B.
// "Inscribed" means here that
// (1) this subgraph is "glued" to other parts of A only by edges that connected to its vertices that are begin/ end ones of any max-length non-branching path of this subgraph
// and/ or
// (2) graph A may have some other connected components.
// i.e. for graph B = {0->2, 10->2, 2->3, 3->4, 4->5, 4->6} we will find only A1 = {0->2, 1->2, 2->3, 3->4, 4->5, 4->6} as inscribed isomorphic subgraph of A = {0->2, 7->1, 1->2, 2->3, 3->4, 4->5, 4->6}.
// But if we add edge 3->8 to A (in this case A = {3->8, 0->2, 7->1, 1->2, 2->3, 3->4, 4->5, 4->6}), we couldn't find any inscribed isomorphic to B subgraph of A.
// A is set by an Adjacency vector.
// B is set an Adjacency vector.
// Both A and B are unweighted.
// Bool "directed" sets if A and B are directed graphs or no.
// Result: a set for containing all subgraphs of A found (set by Adjacency vectors), i.e. this set to contain results.
// The function returnes the number of different subgraphs of A that are isomorphic to B and subgraphs themselves in Result; if input data are incorrect returns -1 and empty Result.
// A and B may have >=1 connected components; also A and B may have multiply edges.

// Функция находит все "вписанные" подграфы графа A, изоморфные графу B.
// «Вписанным» подграфом графа A здесь называется такой его подграф, который может быть «приклеен» к другим частям графа A только за счет ребер,
// инцидентных лишь граничным вершинам его (подграфа) неразветвляющихся путей максимальной длины (при этом граф A может содержать и иные компоненты связности).
// Т.е. для графа B = {0->2, 10->2, 2->3, 3->4, 4->5, 4->6} будет найден изоморфный ему подграф A1, "вписанный" в граф A = {0->2, 7->1, 1->2, 2->3, 3->4, 4->5, 4->6}, и этот подграф A1 = {0->2, 1->2, 2->3, 3->4, 4->5, 4->6},
// однако если в граф A добавить ребро 3->8 (A = {3->8, 0->2, 7->1, 1->2, 2->3, 3->4, 4->5, 4->6}), то функция не найдет в A изоморфных B "вписанных" подграфов.
// A и B д.б. невзвешеными, задаются векторами смежности, могут быть ориентированными (bool directed = true) и нет.
// Может работать с графами, содержащими несколько несвязных компонет, а также с графами с множественными ребрами. При работе с множественными ребрами из А выбираются те, что имеют кратность не менее, чем соотвествующие им в В

{


    Result.clear();


    // checking of input data correctness


    if (A.size()==0) return -1;
    if (B.size()==0) return -1;
    if (B.size()>A.size()) return -1;
    if ((A.size()%2)==1) return -1;
    if ((B.size()%2)==1) return -1;


    // ancillary vars

     int mn, m, r, temp, t, t1;

     int c=0, f2, f1, f3=0;


     int mnb, mb;

     // end of ancillary vars

      const bool w = false; // we consider only unweighted graps here

     RangeVGraph (A, m, mn, w); // all vertices should have non-negative numbers assigned
     if (mn<0) return -1;

     RangeVGraph (B, mb, mnb, w);  // all vertices should have non-negative numbers assigned
     if (mnb<0) return -1;



    // end of checking of input data correctness

     bool eq = false;
     if (A.size()==B.size()) eq = true;  // in this case we are testing if B is isomorphic to A


    if (!directed)  // Normalizing an undirected graph: every edge should have their vertices in increasing (non-decreasing) order
    {
        for (int i=0; i<A.size(); i=i+2+w)
        {
            if (A[i]>A[i+1]) SwapInVector(A, i, i+1);
        }
        for (int i=0; i<B.size(); i=i+2+w)
        {
            if (B[i]>B[i+1]) SwapInVector(B, i, i+1);
        }
    }



    std::unordered_map <std::pair < int, int> , int, PairIntHash> MultEdgesA; // для кратности ребер
    std::unordered_map <std::pair < int, int> , int, PairIntHash> MultEdgesB; // to contain multiplicity of edges of the graphs A and B
    MultEdgesA.clear();
    MultEdgesB.clear();

    AdjVectorEdgesMultiplicity (A, MultEdgesA, w, true);
    AdjVectorEdgesMultiplicity (B, MultEdgesB, w, true);


A.clear();
B.clear();

for (auto it = MultEdgesA.begin(); it!=MultEdgesA.end(); it++) //  оставляем всем ребрам кратности 1
{

    {
        A.push_back((it->first).first);
        A.push_back((it->first).second);
    }

}

for (auto it = MultEdgesB.begin(); it!=MultEdgesB.end(); it++)  // some preparing of A and B: every edge will be with multiplicity = 1 for some operations
{

    {
        B.push_back((it->first).first);
        B.push_back((it->first).second);
    }

}






    std::vector <int> VinA; //для подсчета входящих и исходящих в вершину, чтобы определить листья и вершины разветвения.
    std::vector <int> VoutA; // Let's count in and out edges for every vertex in order to find branching vertices

    std::vector <int> VinB; //для подсчета входящих и исходящих в вершину, чтобы определить листья и вершины разветвения.
    std::vector <int> VoutB; // Let's count in and out edges for every vertex in order to find branching vertices


    std::unordered_set <std::pair<int, int>, PairIntHash> A1; // an ancillary set

    std::unordered_set <int> V1;  // an ancillary set
    V1.clear();


    std::vector <std::vector<int> >PathsA; // Here all max-lenght non-branching paths of A will be
    std::vector <std::vector<int> >PathsA1;  // an ancillary vector

   std::vector <std::vector<int> >PathsB;  //Here all max-lenght non-branching paths of B will be


   std::vector <std::vector<int>> NPaths (PathsB.size()); // здесь по каждому путь в PathsB будет набор триплетов: номер соотвествующего пути в PathsA, стартовая позиция в нем и его длина

   std::vector <long long int> D; //an ancillary unit
   std::vector <int> Prev; //an ancillary unit
   std::vector <std::vector<long long int>> DA; // to contain the shortest paths between verticec in A
   std::vector <std::vector <long long int>> DB;  // to contain the shortests paths between verticec in A

   DA.clear();
   DB.clear();

   D.clear();


   std::vector <int> E; // // an ancillary unit
   E.clear();






        std::vector <int> lr; // вектор разрядов для некоторых вычислений (см. ниже)

        std::vector <int> lrmax; // вектор порговых значений у разрядов


         std::set <int> VertPathsACircles; // Вершины путей из PathsA, которые - кольца - для умножения простых колец
         int PathsASizeWithNoCircles;


    lprorez1:;


    RangeVGraph (A, m, mn, w);






    VinA.clear();
    VinA.resize(m+1, 0);



    VoutA.clear();
    VoutA.resize(m+1, 0);








        A1.clear();


    for (int a = 0; a<A.size(); a=(a+2+w))
    {

        if (directed)
        {
        VinA[(A[a+1])]++;
        VoutA[(A[a])]++;
        }
        if (!directed)
        {
        VinA[(A[a+1])]++;
        VinA[(A[a])]++;
        }

    }






    PathsA.clear();

   NBPaths (A, w, PathsA, directed); // let's find all max-lenght non-branching paths of A




   RangeVGraph (B, mb, mnb, w);




  NBPaths (B, w, PathsB, directed);  // let's find all max-lenght non-branching paths of A


   VinB.clear();
   VinB.resize(mb+1, 0);



   VoutB.clear();
   VoutB.resize(mb+1, 0);




   for (int a = 0; a<B.size(); a=(a+2+w))
   {

       if (directed)
       {
       VinB[(B[a+1])]++;
       VoutB[(B[a])]++;
       }
       if (!directed)
       {
       VinB[(B[a+1])]++;
       VinB[(B[a])]++;
       }

   }







   //***********




   // Умножение колец в А

   // all circles of NB-paths of A will be multiplied as follows: all vertices should be as the starting in the path


  VertPathsACircles.clear();

  PathsASizeWithNoCircles = PathsA.size();


  temp= PathsA.size();

//  if (!eq)
  {

   for (int j=0; j<PathsASizeWithNoCircles; j++)
   {

       if (PathsA[j].size()<=2) continue;



  if ( (PathsA[j][0] == PathsA[j][PathsA[j].size()-1]))
    {





       E=PathsA[j];

        for (int x=1; x<PathsA[j].size()-1; x++)
        {
            E.push_back(E[1]);
            E.erase(E.begin());
            PathsA.push_back(E);



         }

          E.clear();


      }



   }

   // Конец Умножение колец в А
   // end of multiplying of circles
}





//***************

   temp = PathsA.size();


   // start of Stage II "NB-paths matching"

   NPaths.clear();
   NPaths.resize(PathsB.size()); // здесь по каждому путь в PathsB будет набор триплетов: номер соотвествующего пути в PathsA, стартовая позиция в нем и его длина
   // NPaths[j]  will contain "probably relevant" NB-paths from A to j-th NB-path of B as 3 numbers: number of NB-path of A in PathsA, starting position in it from the beginning and its lenght.


   for (int j=0; j<PathsB.size(); j++)
       NPaths[j].clear();

   t1 = PathsA.size();
   if (!eq)
   {



       for (int j=0; j<PathsB.size(); j++)   // сбор внутренних путей  //  //considering internal paths of PathsB.
       {

           if ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) continue; //не рассматривать пока концевые
           if ( (VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1) continue; //не рассматривать пока концевые

           if ( (PathsB[j][0] == PathsB[j][PathsB[j].size()-1]) && ((VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==2) ) continue; // не рассматривать пока простые кольца


           for (int i=0; i<PathsASizeWithNoCircles; i++)  // не рассматриваем разрезы колец
           {


                if (  ( (PathsB[j][0] == PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) ) || ( (PathsB[j][0] != PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) ))
                    if ( (VinB[(PathsB[j][0])]<= VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]<= VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]<= VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]<= VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )
                        {
                            NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

                            NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                            NPaths[j].push_back(PathsA[i].size()); // его длина  // lenght


                            //***
                            for (int x=1; x<PathsA[i].size(); x++)
                            {
                                if (directed)
                                    A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                                if (!directed)
                                    A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                            }

                        }


                if ((!directed) && (PathsB[j][0] != PathsB[j][PathsB[j].size()-1])&& (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]))
                {

                    E=PathsA[i];
                    reverse (PathsA[i].begin(), PathsA[i].end());



                    if (  ( (PathsB[j][0] == PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) ) || ( (PathsB[j][0] != PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) ))
                        if ( (VinB[(PathsB[j][0])]<= VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]<= VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]<= VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]<= VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )
                            {
                                reverse (E.begin(), E.end());
                                PathsA.push_back(E);
                                NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                                NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                                NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                                //***
                                for (int x=1; x<PathsA[i].size(); x++)
                                {
                                        A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                                }

                           }

                    E.clear();

                    reverse (PathsA[i].begin(), PathsA[i].end());

                }
           }
       }




   for (int j=0; j<PathsB.size(); j++)   // сбор концевых путей //considering in/out rays of PathsB
   {


       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)) continue; //палки не смотрим

       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])>1)) goto l1;
       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])>1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)) goto l1;

       continue;



       l1: for (int i=0; i<PathsASizeWithNoCircles; i++)  // разрезы колец не смотрим
       {





           if ( (VinB[(PathsB[j][0])]<= VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]<= VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]<= VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]<= VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()<=PathsA[i].size()) )
            {


                if ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)
                {

                    NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA
                    NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                    NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                    //***
                    for (int x=1; x<PathsA[i].size(); x++)
                    {
                        if (directed)
                            A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                        if (!directed)
                            A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                    }


                }

                if ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1)
                {


                    NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA
                    NPaths[j].push_back(PathsA[i].size()-PathsB[j].size());  // стартовая позиция в нем  //statring posiyion in it
                    NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght

                    //***
                    for (int x=1; x<PathsA[i].size(); x++)
                    {
                        if (directed)
                            A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                        if (!directed)
                            A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                    }

                 }


            }


           if (!directed)
           {

               E=PathsA[i];
               reverse (PathsA[i].begin(), PathsA[i].end());

               if ( (VinB[(PathsB[j][0])]<= VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]<= VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]<= VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]<= VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()<=PathsA[i].size()) )
                {


                    if ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)
                    {
                        reverse (E.begin(), E.end());
                        PathsA.push_back(E);

                        NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                        NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                        NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                        //***
                        for (int x=1; x<PathsA[i].size(); x++)
                        {
                            A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                        }
                    }

                    if ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1)
                    {
                        reverse (E.begin(), E.end());
                        PathsA.push_back(E);

                        NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA
                        NPaths[j].push_back(PathsA[i].size()-PathsB[j].size());  // стартовая позиция в нем  //statring posiyion in it
                        NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght

                        //***
                        for (int x=1; x<PathsA[i].size(); x++)
                        {
                             A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                        }

                     }
                }
               E.clear();
               reverse (PathsA[i].begin(), PathsA[i].end());
           }

      }

   }


   for (int j=0; j<PathsB.size(); j++)   // сбор простых цепей  // considering chains of PathsB
   {

       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)) goto l11;


       continue;


       l11: for (int i=0; i<t1; i++)
       {

          if ( (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) && (PathsB[j].size()<=(PathsA[i].size()-1)) ) // если вписываем в кольцо

           {

               for (int z=0; z<=PathsA[i].size()-1-PathsB[j].size(); z++)

               {
                   NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

                   NPaths[j].push_back(z); // стартовая позиция в нем  //statring posiyion in it

                   NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght



                   //***
                   for (int x=1; x<PathsA[i].size(); x++)
                   {
                       if (directed)
                           A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                       if (!directed)
                           A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                   }



               if (!directed)
               {
                   E = PathsA[i];
                   reverse(E.begin(), E.end());
                   PathsA.push_back(E);
                   for (int z=0; z<=PathsA[i].size()-1-PathsB[j].size(); z++)

                   {
                       NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                       NPaths[j].push_back(z); // стартовая позиция в нем  //statring posiyion in it

                       NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght
                   }

               }

               }
           }



           if ( (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) && (PathsB[j].size()<=PathsA[i].size()) )  // Нашли: не кольцо, не меньшей длины


            {
                for (int z=0; z<=PathsA[i].size()-PathsB[j].size(); z++)

                {
                    NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

                    NPaths[j].push_back(z); // стартовая позиция в нем  //statring posiyion in it

                    NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght



                    //***
                    for (int x=1; x<PathsA[i].size(); x++)
                    {
                        if (directed)
                            A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                        if (!directed)
                            A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                    }



                if (!directed)
                {
                    E = PathsA[i];
                    reverse(E.begin(), E.end());
                    PathsA.push_back(E);
                    for (int z=0; z<=PathsA[i].size()-PathsB[j].size(); z++)
                    {
                         NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                         NPaths[j].push_back(z); // стартовая позиция в нем  //statring posiyion in it

                         NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght
                    }

                }
                }
            }

       }


    }

   for (int j=0; j<PathsB.size(); j++)   // сбор простых "колец" - в любые кольца
   {

       if( (PathsB[j][0] != PathsB[j][PathsB[j].size()-1]))    continue;  // смотрим только кольца


     //  if ((VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])!=2) continue; // простые



       for (int i=0; i<t1; i++)  // разрезы колец не смотрим, включаем как одно вхождение-совпадение, по 1 разу
       {


           if ( (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) && (PathsB[j].size()==PathsA[i].size()) ) // если нашли кольцо  такой же длины
           {
               NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

               NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
               NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght




               //***
               for (int x=1; x<PathsA[i].size(); x++)
               {
                   if (directed)
                       A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                   if (!directed)
                       A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
               }


               if (!directed)
               {
                   E = PathsA[i];
                   reverse(E.begin(), E.end());
                   PathsA.push_back(E);

                   NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA
                   NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                   NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght

               }
           }

       }
    }

    }



   if (eq)
   {



       for (int j=0; j<PathsB.size(); j++)   // сбор внутренних путей  //  //considering internal paths of PathsB.
       {

           if ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) continue; //не рассматривать пока концевые
           if ( (VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1) continue; //не рассматривать пока концевые

           if ( (PathsB[j][0] == PathsB[j][PathsB[j].size()-1]) && ((VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==2) ) continue; // не рассматривать пока простые кольца


           for (int i=0; i<PathsASizeWithNoCircles; i++)  // не рассматриваем разрезы колец
           {


                if (  ( (PathsB[j][0] == PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) ) || ( (PathsB[j][0] != PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) ))
                    if ( (VinB[(PathsB[j][0])]== VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]== VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]== VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]== VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )

                        {
                            NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

                            NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                            NPaths[j].push_back(PathsA[i].size()); // его длина  // lenght


                            //***
                            for (int x=1; x<PathsA[i].size(); x++)
                            {
                                if (directed)
                                    A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                                if (!directed)
                                    A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                            }

                        }


                if ((!directed) && (PathsB[j][0] != PathsB[j][PathsB[j].size()-1])&& (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]))
                {

                    E=PathsA[i];
                    reverse (PathsA[i].begin(), PathsA[i].end());



                    if (  ( (PathsB[j][0] == PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) ) || ( (PathsB[j][0] != PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) ))
                        if ( (VinB[(PathsB[j][0])]== VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]== VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]== VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]== VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )

                            {
                                reverse (E.begin(), E.end());
                                PathsA.push_back(E);
                                NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                                NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                                NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                                //***
                                for (int x=1; x<PathsA[i].size(); x++)
                                {
                                        A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                                }

                           }

                    E.clear();

                    reverse (PathsA[i].begin(), PathsA[i].end());

                }
           }
       }



   for (int j=0; j<PathsB.size(); j++)   // сбор концевых путей //considering in/out rays of PathsB
   {


       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)) continue; //палки не смотрим

       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])>1)) goto l1eq;
       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])>1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)) goto l1eq;

       continue;



       l1eq: for (int i=0; i<PathsASizeWithNoCircles; i++)  // разрезы колец не смотрим
       {





        //if ( (VinB[(PathsB[j][0])]<= VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]<= VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]<= VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]<= VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )
        if ( (VinB[(PathsB[j][0])]== VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]== VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]== VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]== VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )

            {


                if ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)
                {


                    NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA
                    NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                    NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                    //***
                    for (int x=1; x<PathsA[i].size(); x++)
                    {
                        if (directed)
                            A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                        if (!directed)
                            A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                    }


                }

                if ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1)
                {


                    NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA
                    NPaths[j].push_back(PathsA[i].size()-PathsB[j].size());  // стартовая позиция в нем  //statring posiyion in it
                    NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght

                    //***
                    for (int x=1; x<PathsA[i].size(); x++)
                    {
                        if (directed)
                            A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                        if (!directed)
                            A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                    }

                 }


            }


           if (!directed)
           {

            E=PathsA[i];
            reverse (PathsA[i].begin(), PathsA[i].end());

            //if ( (VinB[(PathsB[j][0])]<= VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]<= VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]<= VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]<= VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )
            if ( (VinB[(PathsB[j][0])]== VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]== VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]== VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]== VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )

                {


                    if ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)
                    {
                        reverse (E.begin(), E.end());
                        PathsA.push_back(E);

                        NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                        NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                        NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                        //***
                        for (int x=1; x<PathsA[i].size(); x++)
                        {
                            A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                        }
                    }

                    if ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1)
                    {
                        reverse (E.begin(), E.end());
                        PathsA.push_back(E);

                        NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA
                        NPaths[j].push_back(PathsA[i].size()-PathsB[j].size());  // стартовая позиция в нем  //statring posiyion in it
                        NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght

                        //***
                        for (int x=1; x<PathsA[i].size(); x++)
                        {
                             A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                        }

                     }
                }
               E.clear();
               reverse (PathsA[i].begin(), PathsA[i].end());
           }


      }

   }


   for (int j=0; j<PathsB.size(); j++)   // сбор простых цепей  // considering chains of PathsB
   {

       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)) goto l11eq;


       continue;


       l11eq: for (int i=0; i<t1; i++)
       {


       if( ( (VinA[(PathsA[i][0])]+VoutA[PathsA[i][0]])==1) && ((VinA[(PathsA[i][PathsA[i].size()-1])]+VoutA[PathsA[i][PathsA[i].size()-1]])==1))
          if ( (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) && (PathsB[j].size()==PathsA[i].size()) )  // Нашли: не кольцо, равной длины

             {
                for (int z=0; z<=PathsA[i].size()-PathsB[j].size(); z++)

                {
                    NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

                    NPaths[j].push_back(z); // стартовая позиция в нем  //statring posiyion in it

                    NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght



                    //***
                    for (int x=1; x<PathsA[i].size(); x++)
                    {
                        if (directed)
                            A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                        if (!directed)
                            A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                    }

                    if (!directed)
                    {
                        E = PathsA[i];
                        reverse(E.begin(), E.end());
                        PathsA.push_back(E);
                        for (int z=0; z<=PathsA[i].size()-PathsB[j].size(); z++)
                        {
                             NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                             NPaths[j].push_back(z); // стартовая позиция в нем  //statring posiyion in it

                             NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght
                        }

                    }

                }
             }

       }


    }

   for (int j=0; j<PathsB.size(); j++)   // сбор простых циклов - в любые циклы // considering  simple cycles of PathsB
   {

       if( (PathsB[j][0] != PathsB[j][PathsB[j].size()-1]))    continue;  // смотрим только кольца


       if ((VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])!=2) continue; // простые



       for (int i=0; i<t1; i++)  //
       {


           if ( (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) && (PathsB[j].size()==PathsA[i].size()) && ((VinA[(PathsA[i][0])]+VoutA[PathsA[i][0]])==2) ) // если простое нашли кольцо  такой же длины
           {
               NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

               NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
               NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght




               //***
               for (int x=1; x<PathsA[i].size(); x++)
               {
                   if (directed)
                       A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                   if (!directed)
                       A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
               }

               if (!directed)
               {
                   E = PathsA[i];
                   reverse(E.begin(), E.end());
                   PathsA.push_back(E);

                   NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA
                   NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                   NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght

               }


           }

       }
   }


    }



   for (int i=0; i<NPaths.size(); i++)
   {

       if (NPaths[i].size()==0)
       {   // если для какого-то пути из B нет аналогов в A
        return 0;
       }
   }


// "pre-Thinning of data"

   //if ((directed)&&(A1.size()<A.size()/2))
   if (A1.size()<A.size()/2)
   {

       A.clear();
       for (auto it1=A1.begin(); it1!=A1.end(); it1++)
       {
           A.push_back((*it1).first);
           A.push_back((*it1).second);
       }


       A1.clear();

       goto lprorez1;
   }

// end of "pre-Thinning of data"



   D.clear();
//   DA.clear();
//   DB.clear();

   if ((DA.size()==0)||(DB.size()==0))
   {

       temp=A.size();
       if (!directed)
       {
           E=A;
           std::reverse(E.begin(), E.end());
           A.reserve(A.size()+E.size());
           A.insert(A.end(), E.begin(), E.end());
           E.clear();
       }


       for (int i=0; i<=m; i++)
       {
           //DistanceBFA (A, D, i, Prev, false);
           DistanceBFA (A, D, i, false);
           DA.push_back(D);
       }


       temp=B.size();
       if (!directed)
       {
           E=B;
           std::reverse(E.begin(), E.end());
           B.reserve(B.size()+E.size());
           B.insert(B.end(), E.begin(), E.end());
           E.clear();
       }


       for (int i=0; i<=mb; i++)
       {
           //DistanceBFA (B, D, i, Prev, false);
           DistanceBFA (B, D, i, false);
           DB.push_back(D);
       }



       temp=A.size()/2;
       if (!directed)
           A.resize(temp);
       temp=B.size()/2;
       if (!directed)
           B.resize(temp);
    }


            temp=0;



            for (int i=0; i<NPaths.size(); i++)
              {

                  if (NPaths[i].size()==0)
                  {
                      return 0;
                      temp=-1;   // если для какого-то пути из B нет аналогов в A

                  }
              }

            // end of Stage II "NB-paths matching"


            // start of Stage III "Thinning of data"

             if (temp!=-1)


              {

                c=INT_MAX;
                for (int i=0; i<NPaths.size(); i++)
                    if (NPaths[i].size()<c)
                    {c= NPaths[i].size();
                        t=i;
                    }


                f2=0;
                for (int i=0; i<NPaths.size(); i++)
                {
                    if (i==t) continue;

                    for (int y=0; y<NPaths[i].size(); y=y+3)
                    {
                        f1=1;
                        for (int g=0; g<NPaths[t].size(); g=g+3)
                        {
                            if (          ((  (DA[PathsA[NPaths[t][g]][NPaths[t][g+1]]][PathsA[NPaths[i][y]][NPaths[i][y+1]]]  ) <=  DB[PathsB[t][0]][PathsB[i][0]]) && (  (DA[PathsA[NPaths[i][y]][NPaths[i][y+1]]][PathsA[NPaths[t][g]][NPaths[t][g+1]]]  ) <=  DB[PathsB[i][0]][PathsB[t][0]]) )   &&   ((  (DA[PathsA[NPaths[t][g]][NPaths[t][g+1]+PathsB[t].size()-1]][PathsA[NPaths[i][y]][NPaths[i][y+1]+PathsB[i].size()-1]]  ) <=  DB[PathsB[t][PathsB[t].size()-1]][PathsB[i][PathsB[i].size()-1]]) && (  (DA[PathsA[NPaths[i][y]][NPaths[i][y+1]+PathsB[i].size()-1]][PathsA[NPaths[t][g]][NPaths[t][g+1]+PathsB[t].size()-1]]  ) <=  DB[PathsB[i][PathsB[i].size()-1]][PathsB[t][PathsB[t].size()-1]]) )     )
                            {
                                f1=0;
                                break;
                            }

                        }

                        if (f1==1)
                        {
                            f2=1;

                            if (y!=NPaths[i].size()-3)
                            {
                                SwapInVector(NPaths[i], y, NPaths[i].size()-3);
                                SwapInVector(NPaths[i], y+1, NPaths[i].size()-2);
                                SwapInVector(NPaths[i], y+2, NPaths[i].size()-1);
                            }
                            NPaths[i].pop_back();
                            NPaths[i].pop_back();
                            NPaths[i].pop_back();
                            y=y-3;

//                            NPaths[i].erase(NPaths[i].begin()+y);
//                            NPaths[i].erase(NPaths[i].begin()+y);
//                            NPaths[i].erase(NPaths[i].begin()+y);
//                            y=y-3;

                        }

                    }

                  }

                //***


                for (int tt=0; tt<NPaths.size(); tt++)
                {


                    if (NPaths[tt].size()==0)
                    {
                        temp=-1;
                        break;
                    }

                    for (int i=0; i<NPaths.size(); i++)
                    {

                        if (NPaths[i].size()==0)
                        {
                            temp=-1;
                            break;
                        }
                        if (i==tt) continue;

                        for (int y=0; y<NPaths[i].size(); y=y+3)
                        {
                            f1=1;
                            for (int g=0; g<NPaths[tt].size(); g=g+3)
                            {
                                if (          ((  (DA[PathsA[NPaths[tt][g]][NPaths[tt][g+1]]][PathsA[NPaths[i][y]][NPaths[i][y+1]]]  ) <=  DB[PathsB[tt][0]][PathsB[i][0]]) && (  (DA[PathsA[NPaths[i][y]][NPaths[i][y+1]]][PathsA[NPaths[tt][g]][NPaths[tt][g+1]]]  ) <=  DB[PathsB[i][0]][PathsB[tt][0]]) )   &&   ((  (DA[PathsA[NPaths[tt][g]][NPaths[tt][g+1]+PathsB[tt].size()-1]][PathsA[NPaths[i][y]][NPaths[i][y+1]+PathsB[i].size()-1]]  ) <=  DB[PathsB[tt][PathsB[tt].size()-1]][PathsB[i][PathsB[i].size()-1]]) && (  (DA[PathsA[NPaths[i][y]][NPaths[i][y+1]+PathsB[i].size()-1]][PathsA[NPaths[tt][g]][NPaths[tt][g+1]+PathsB[tt].size()-1]]  ) <=  DB[PathsB[i][PathsB[i].size()-1]][PathsB[tt][PathsB[tt].size()-1]]) )     )
                                {
                                    f1=0;
                                    break;
                                }

                            }

                            if (f1==1)
                            {
                                f2=1;

                                if (y!=NPaths[i].size()-3)
                                {
                                    SwapInVector(NPaths[i], y, NPaths[i].size()-3);
                                    SwapInVector(NPaths[i], y+1, NPaths[i].size()-2);
                                    SwapInVector(NPaths[i], y+2, NPaths[i].size()-1);
                                }
                                NPaths[i].pop_back();
                                NPaths[i].pop_back();
                                NPaths[i].pop_back();
                                y=y-3;

//                                NPaths[i].erase(NPaths[i].begin()+y);
//                                NPaths[i].erase(NPaths[i].begin()+y);
//                                NPaths[i].erase(NPaths[i].begin()+y);
//                                y=y-3;

                            }

                        }

                        if (NPaths[i].size()==0)
                        {
                            temp=-1;
                            break;
                        }

                      }
                    if (temp==-1) break;
                }

                //***

                for (int i=0; i<NPaths.size(); i++)
                {

                    if (NPaths[i].size()==0)
                    {
                        temp=-1;
                        break;
                    }

                    for (int y=0; y<NPaths[i].size(); y=y+3)
                    {

                        if (  ( (PathsB[i][0]==PathsB[i][PathsB[i].size()-1]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]]!= PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]) ) || ( (PathsB[i][0]!=PathsB[i][PathsB[i].size()-1]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]]== PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]) ) )

                        {
                            f2=1;

                            if (y!=NPaths[i].size()-3)
                            {
                                SwapInVector(NPaths[i], y, NPaths[i].size()-3);
                                SwapInVector(NPaths[i], y+1, NPaths[i].size()-2);
                                SwapInVector(NPaths[i], y+2, NPaths[i].size()-1);
                            }
                            NPaths[i].pop_back();
                            NPaths[i].pop_back();
                            NPaths[i].pop_back();
                            y=y-3;

//                            NPaths[i].erase(NPaths[i].begin()+y);
//                            NPaths[i].erase(NPaths[i].begin()+y);
//                            NPaths[i].erase(NPaths[i].begin()+y);
//                            y=y-3;

                        }

                        if (NPaths[i].size()==0)
                        {
                            temp=-1;
                            break;
                        }

                    }


                    if (NPaths[i].size()==0)
                    {
                        temp=-1;
                        break;
                    }

                  }





                for (int tt=0; tt<NPaths.size(); tt++)
                {


                    if (NPaths[tt].size()==0)
                    {
                        temp=-1;
                        break;
                    }

                    for (int i=0; i<NPaths.size(); i++)
                    {

                        if (NPaths[i].size()==0)
                        {
                            temp=-1;
                            break;
                        }
                        if (i==tt) continue;


                        for (int y=0; y<NPaths[i].size(); y=y+3)
                        {
                            f1=1;

                            //1
                            for (int g=0; g<NPaths[tt].size(); g=g+3)
                            {
                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1.1

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.1.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**

                                            {
                                                f1=0;
                                                break;
                                            }


                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1.2

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))


                                            //1.2.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**

                                            {
                                                f1=0;
                                                break;
                                            }


                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1/3

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/3/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**

                                            {
                                                f1=0;
                                                break;
                                            }

                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1/4

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/4/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**

                                            {
                                                f1=0;
                                                break;
                                            }




                                //2
                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1.1

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.1.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }



                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1.2

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.2.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }


                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                     if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1/3

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/3/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }

                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1/4

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/4/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }










                                //3
                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1.1

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.1.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }


                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1.2

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.2.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**



                                            {
                                                f1=0;
                                                break;
                                            }


                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1/3

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/3/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**



                                            {
                                                f1=0;
                                                break;
                                            }


                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1/4

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/4/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }







                                //4
                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1.1

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.1.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }

                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1.2

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.2.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }

                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                   if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1/3

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/3/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**



                                            {
                                                f1=0;
                                                break;
                                            }

                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1/4

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/4/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }



                            }

                            if (f1==1)
                            {
                                f2=1;

                                if (y!=NPaths[i].size()-3)
                                {
                                    SwapInVector(NPaths[i], y, NPaths[i].size()-3);
                                    SwapInVector(NPaths[i], y+1, NPaths[i].size()-2);
                                    SwapInVector(NPaths[i], y+2, NPaths[i].size()-1);
                                }
                                NPaths[i].pop_back();
                                NPaths[i].pop_back();
                                NPaths[i].pop_back();
                                y=y-3;

//                                NPaths[i].erase(NPaths[i].begin()+y);
//                                NPaths[i].erase(NPaths[i].begin()+y);
//                                NPaths[i].erase(NPaths[i].begin()+y);
//                                y=y-3;

                            }

                        }

                        if (NPaths[i].size()==0)
                        {
                            temp=-1;
                            break;
                        }

                      }
                    if (temp==-1) break;
                }








                //***







                if ((f2==1)&&(A.size()!=f3)&&(temp!=-1))
                {
                    V1.clear();

                    for (int i=0; i<NPaths.size(); i++)
                        for (int j=0; j<NPaths[i].size(); j=j+3)
                            V1.insert(NPaths[i][j]);

                    if (PathsA.size()!=V1.size())
                    {

                    PathsA1.clear();
                     for (auto i=V1.begin(); i!=V1.end(); i++)
                         PathsA1.push_back(PathsA[*i]);




                     PathsA.clear();
                     PathsA=PathsA1;
                     A.clear();
                     A1.clear();

                     for (int i=0; i<PathsA.size(); i++)

                         for (int x=1; x<PathsA[i].size(); x++)
                         {
                             if (directed)
                                 A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                             if (!directed)
                                 A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                         }


                     for (auto it1=A1.begin(); it1!=A1.end(); it1++)
                     {
                         A.push_back((*it1).first);
                         A.push_back((*it1).second);
                     }

                     f3=A.size();

                     goto lprorez1;
                     }
                }




            }





                for (int i=0; i<NPaths.size(); i++)
                {

                    if (NPaths[i].size()==0)
                    {temp=-1;   // если для какого-то пути из B нет аналогов в A
                        return 0;

                    }
                }



// end of Stage III "Thinning of data"

                // start of Stage IV "Finnishing"


                c=0;

              int WordLenght= PathsB.size();

                  std::vector <int> l (PathsB.size()); // вектор разрядов

              std::vector <int> lmax (PathsB.size()); // вектор порговых значений у разрядов

              for (int g=0; g<PathsB.size(); g++)
              {
                  l [g] = 0;

                  lmax [g] = NPaths[g].size()/3-1;


              }

            l[l.size()-1]--;









            Result.clear(); // здесь будут найденные подграфы
            std::vector <int> G0; //Эталонный граф в нужном порядке согласно вектору неразветвляющихся путей
            G0.clear();
            std::vector <int> G1; //Выстраиваемый граф в нужном порядке согласно вектору неразветвляющихся путей
            G1.clear();  //Выстраиваемый граф в нужном порядке согласно вектору неразветвляющихся путей
            G0.clear(); //Эталонный граф в нужном порядке согласно вектору неразветвляющихся путей







            std::vector <int> Scale0;  // Шкала для матрицы смежности 1
            Scale0.clear();


            std::vector<std::vector <bool>> B1; //заготовки для матриц смежности


            MatrixSet(B1, mb+1-mnb, mb+1-mnb, 0);

            std::vector <int> IndexPermB;  // Номера вершин графа B в шкале Scale0
            IndexPermB.clear();
            IndexPermB.resize(mb+1, -1);


            for (int q1=0; q1<PathsB.size(); q1++)
            {
                if (IndexPermB[PathsB[q1][0]]==-1)
                {
                    Scale0.push_back(PathsB[q1][0]);
                    IndexPermB[PathsB[q1][0]] = Scale0.size()-1;
                }

                for (int q2=0; q2<PathsB[q1].size()-1; q2++)
                {
                    G0.push_back(PathsB[q1][q2]);
                    G0.push_back(PathsB[q1][q2+1]);

                    if (IndexPermB[PathsB[q1][q2+1]]==-1)
                    {
                        Scale0.push_back(PathsB[q1][q2+1]);
                        IndexPermB[PathsB[q1][q2+1]] = Scale0.size()-1;
                    }

                    B1  [IndexPermB[PathsB[q1][q2]]] [IndexPermB[PathsB[q1][q2+1]]]=1;
                    if (!directed) B1 [IndexPermB[PathsB[q1][q2+1]]] [IndexPermB[PathsB[q1][q2]]] = B1  [IndexPermB[PathsB[q1][q2]]] [IndexPermB[PathsB[q1][q2+1]]];

                }

            }




            std::vector <int> G3;  // To write multiply edges
            G3.clear();


             std::set<std::pair <int, int>> G1ALL3; // Служебный - для исключения из результата взаимотождественных подграфов
             G1ALL3.clear();

             std::unordered_set<std::pair <int, int>, PairIntHash> Y;
             Y.clear();






             int *IndexPermA = new int[m+1]; // Выделение памяти для массива






              while (true) //***
              {

                if (temp==-1) break;   // если для какого-то пути из B нет аналогов в A

              l [WordLenght-1]++;  //увеличение на 1 номера последнего разряда

              if (l [WordLenght-1] > lmax [WordLenght-1])
               {
                 r = WordLenght-1;

                 while (r>0)
                   {l [r] = 0;
                    r--;
                    l [r] ++;
                    if (l[r] <= lmax [r]) break;
                   }
               }





                Y.clear();  // In order not to consider combination of path-candidates if any path-candidate is represented in this combination more than once.
                                for (int y=0; y<NPaths.size();y++)
                                {
                                    c = 3*l[y];
                                    if (eq == false)
                                        Y.insert(std::pair <int, int> (NPaths[y][c], NPaths[y][c+1]));

                                    if (eq == true)
                                        Y.insert(std::pair <int, int> (NPaths[y][c], 0));

                                    if (Y.size()!=(y+1))
                                    {
                                        if (l==lmax) goto l3;

                                        for (int x=NPaths.size()-1; x>y;x--)
                                            l[x]=lmax[x];

                                        goto l3;

                                    }

                                }


                  G1.clear();
                  G1.reserve(G0.size());

                  t=0;

                  for (int i = 0; i <= m; i++)
                      IndexPermA[i] = -1;


                 for (int y=0; y<NPaths.size();y++)
                     {
                        c = 3*l[y];
                        if (IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]]]==-1)
                           {
                              t++;
                              IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]]] = t-1;
                           }


                        for (int x=0; x<NPaths[y][c+2]-1;x++)
                            {
                               G1.push_back(PathsA[NPaths[y][c]][NPaths[y][c+1]+x]);
                               G1.push_back(PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]);


                                if (IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]]==-1)
                                {
                                     t++;
                                     IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]] = t-1;
                                }

                                if (B1  [IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x]]] [IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]]]!=1)
                                {
                                     //goto l3;
                                     if (l==lmax) goto l3;
                                     for (int x=NPaths.size()-1; x>y;x--)
                                         l[x]=lmax[x];
                                      goto l3;
                                 }

                                if (directed)
                                    if (MultEdgesA[std::pair <int, int>(G1[G1.size()-2], G1[G1.size()-1]) ] < MultEdgesB[std::pair <int, int>(G0[G1.size()-2], G0[G1.size()-1]) ])
                                    {
                                        //goto l3;
                                        if (l==lmax) goto l3;

                                        for (int x=NPaths.size()-1; x>y;x--)
                                            l[x]=lmax[x];

                                        goto l3;
                                    }



                                if (!directed)
                                    if (MultEdgesA[std::pair <int, int>(std::min(G1[G1.size()-2], G1[G1.size()-1]), std::max(G1[G1.size()-2], G1[G1.size()-1])) ] < MultEdgesB[std::pair <int, int>(std::min(G0[G1.size()-2], G0[G1.size()-1]), std::max(G0[G1.size()-2], G0[G1.size()-1])) ])
                                    {
                                        //goto l3;
                                        if (l==lmax) goto l3;

                                        for (int x=NPaths.size()-1; x>y;x--)
                                            l[x]=lmax[x];

                                        goto l3;
                                    }
                              }

                       }


                if (G1.size()!=G0.size()) goto l3;
                G3.clear();


                for (int x=0; x<G0.size(); x=x+2)  // Проверка соответствия кратности множественных ребер
                {
                    if (directed)
                    {
                        if (MultEdgesA[std::pair <int, int>(G1[x], G1[x+1]) ] < MultEdgesB[std::pair <int, int>(G0[x], G0[x+1]) ])
                        {

                            goto l3;
                        }

                        for (int x1=1; x1<MultEdgesB[std::pair <int, int>(G0[x], G0[x+1]) ]; x1++)   // to remember in G3 edges having their multiplicity >1
                        {
                            G3.push_back(G1[x]);
                            G3.push_back(G1[x+1]);
                        }


                    }

                    if (!directed)
                    {
                        if (MultEdgesA[std::pair <int, int>(std::min(G1[x], G1[x+1]), std::max(G1[x], G1[x+1])) ] < MultEdgesB[std::pair <int, int>(std::min(G0[x], G0[x+1]), std::max(G0[x], G0[x+1])) ])
                        {

                            goto l3;
                        }

                        for (int x1=1; x1<MultEdgesB[std::pair <int, int>(std::min(G0[x], G0[x+1]), std::max(G0[x], G0[x+1])) ]; x1++) // to remember in G3 edges having their multiplicity >1
                        {
                            G3.push_back(std::min(G1[x],G1[x+1]));
                            G3.push_back(std::max(G1[x],G1[x+1]));
                        }


                    }

                }




                if (!directed)
                {
                    for (int i=0; i<G1.size(); i=i+2)
                    {
                        if (G1[i]>G1[i+1]) SwapInVector(G1, i, i+1);
                    }

                }




                // we should have no equal graphs in our answer so we should eliminate those have the same edges in different order (except one of them)
                    G1ALL3.clear();
                    for (int q=0; q<G1.size(); q=q+2)
                        G1ALL3.insert(std::pair<int, int> (G1[q],G1[q+1]));
                    G1.clear();

                    for (auto it3=G1ALL3.begin(); it3!=G1ALL3.end(); it3++)
                    {
                        G1.push_back((*it3).first);
                        G1.push_back((*it3).second);
                    }

                    G1ALL3.clear();

                    // end of eliminating


                if (G3.size()!=0)  // to add edges having their multiplicity >1
                    G1.insert(G1.end(), G3.begin(), G3.end());

                G3.clear();

                Result.insert(G1);


                l3: if (l==lmax)
                {
                    delete [] IndexPermA; // очистка памяти
                    break;
                }
                if ((eq==true) && (Result.size()==1))
                {
                    delete [] IndexPermA; // очистка памяти
                    break;
                }

              }





     return Result.size();


}


struct VectorIntHash  // for unordered_set of vector <int>
{

    int operator()(const std::vector<int>& obj) const
    {

        int r=0;

        for (int i=0; i<obj.size();i++)
        {
            if ((i%2)==0)
                r=r+obj[i];

            if ((i%2)==1)
                r=r-obj[i];

        }

        return r;

    }
};

int SubGraphsInscribed (std::vector <int> A, std::vector <int> B, std::unordered_set<std::vector <int>, VectorIntHash> & Result, bool directed = true, bool InscribedOnly = true, const bool PreThinning=true)

// The extended experimental version of the function SubGraphsInscribed above.
// This extention/ modifacation is done by working with all edges of the input graphs instead of working with non-branching paths.
// If InscribedOnly == false the function finds all (not only inscribed) subgraphs of unweighted graph A that are isomorphic to unweighted graph B.
// If InscribedOnly == true the function looks for "inscribed" ones only.
// PreThinning is an additional parameter that sets should the function skip stage PreThinning of input data or no.
// As working time both of the function as a whole and its stages is rather depends on input data sometimes one may try to play with this parameter.

// Расширенный экспериментальный вариант функции SubGraphsInscribed - позволяет находить все подграфы графа A, изоморфные графу B, а не только "вписанные".
// Для этого нужно задать параметр InscribedOnly = 0. Если InscribedOnly == 1, то поиск идет быстрее, но только по "вписанным" подграфам.
// Адаптация осуществлена заменой рассмотрения non-branching paths на ребра рассматриваемых графов с сохранением методологии.
// Параметр PreThinning определяет, нужно ли производить предварительное "прореживание". Вспомогательный параметр для оптимизации времени работы,
// т.к. скорость прохождения различных этапов алгоритма, как и самого алгоритма, сильно зависит от исходных данных.

{

     Result.clear(); // здесь будут найденные подграфы

     const bool w = false; // we consider only unweighted graps here

    // GraphVerticesNumbersCompress (B, w);

    int b0size=B.size();


    // checking of input data correctness


    if (A.size()==0) return -1;
    if (B.size()==0) return -1;
    if (B.size()>A.size()) return -1;
    if ((A.size()%2)==1) return -1;
    if ((B.size()%2)==1) return -1;



    // ancillary vars

     int mn, m, r, temp, t, t1;

     int c=0, f2, f1, f3=0;


     int mnb, mb;

     // end of ancillary vars


     RangeVGraph (A, m, mn, w); // all vertices should have non-negative numbers assigned
     if (mn<0) return -1;

     RangeVGraph (B, mb, mnb, w);  // all vertices should have non-negative numbers assigned
     if (mnb<0) return -1;



     std::vector <int> G0; //Эталонный граф в нужном порядке согласно вектору неразветвляющихся путей
     G0.clear();
     std::vector <int> G1; //Выстраиваемый граф в нужном порядке согласно вектору неразветвляющихся путей
     G1.clear();  //Выстраиваемый граф в нужном порядке согласно вектору неразветвляющихся путей
     G0.clear(); //Эталонный граф в нужном порядке согласно вектору неразветвляющихся путей

     std::vector <int> G3; //
     G3.clear();  //
     G3=B;

     std::vector <int> Scale0;  // Шкала для матрицы смежности 1
     Scale0.clear();



    // end of checking of input data correctness

     bool eq = false;
     if (A.size()==B.size()) eq = true;  // in this case we are testing if B is isomorphic to A

     if (eq)
         InscribedOnly = true;


     std::unordered_map <std::pair < int, int> , int, PairIntHash> MultEdgesA; // для кратности ребер
     std::unordered_map <std::pair < int, int> , int, PairIntHash> MultEdgesB; // to contain multiplicity of edges of the graphs A and B
     MultEdgesA.clear();
     MultEdgesB.clear();



     if (!directed)  // Normalizing an undirected graph: every edge should have their vertices in increasing (non-decreasing) order
     {
         for (int i=0; i<A.size(); i=i+2+w)
         {
             if (A[i]>A[i+1]) SwapInVector(A, i, i+1);
         }
         for (int i=0; i<B.size(); i=i+2+w)
         {
             if (B[i]>B[i+1]) SwapInVector(B, i, i+1);
         }
     }





    AdjVectorEdgesMultiplicity (A, MultEdgesA, w, true);
    AdjVectorEdgesMultiplicity (B, MultEdgesB, w, true);


A.clear();
B.clear();

for (auto it = MultEdgesA.begin(); it!=MultEdgesA.end(); it++) //  оставляем всем ребрам кратности 1
{

    {
        A.push_back((it->first).first);
        A.push_back((it->first).second);
    }

}

for (auto it = MultEdgesB.begin(); it!=MultEdgesB.end(); it++)  // some preparing of A and B: every edge will be with multiplicity = 1 for some operations
{

    {
        B.push_back((it->first).first);
        B.push_back((it->first).second);
    }

}


    std::vector <int> VinA; //для подсчета входящих и исходящих в вершину, чтобы определить листья и вершины разветвения.
    std::vector <int> VoutA; // Let's count in and out edges for every vertex in order to find branching vertices

    std::vector <int> VinB; //для подсчета входящих и исходящих в вершину, чтобы определить листья и вершины разветвения.
    std::vector <int> VoutB; // Let's count in and out edges for every vertex in order to find branching vertices


    std::unordered_set <std::pair<int, int>, PairIntHash> A1; // an ancillary set

    std::unordered_set <int> V1;  // an ancillary set
    V1.clear();


    std::vector <std::vector<int> >PathsA; // Here all max-lenght non-branching paths of A will be
    std::vector <std::vector<int> >PathsA1;  // an ancillary vector

   std::vector <std::vector<int> >PathsB;  //Here all max-lenght non-branching paths of B will be


   std::vector <std::vector<int>> NPaths (PathsB.size()); // здесь по каждому путь в PathsB будет набор триплетов: номер соотвествующего пути в PathsA, стартовая позиция в нем и его длина

   std::vector <long long int> D; //an ancillary unit
   std::vector <int> Prev; //an ancillary unit
   std::vector <std::vector<long long int>> DA; // to contain the shortest paths between verticec in A
   std::vector <std::vector <long long int>> DB;  // to contain the shortests paths between verticec in A

   DA.clear();
   DB.clear();

   D.clear();


   std::vector <int> E; // // an ancillary unit
   E.clear();






        std::vector <int> lr; // вектор разрядов для некоторых вычислений (см. ниже)

        std::vector <int> lrmax; // вектор порговых значений у разрядов


         std::set <int> VertPathsACircles; // Вершины путей из PathsA, которые - кольца - для умножения простых колец
         int PathsASizeWithNoCircles;


    lprorez1:;


    RangeVGraph (A, m, mn, w);


    VinA.clear();
    VinA.resize(m+1, 0);

    VoutA.clear();
    VoutA.resize(m+1, 0);




        A1.clear();


    for (int a = 0; a<A.size(); a=(a+2+w))
    {

        if (directed)
        {
        VinA[(A[a+1])]++;
        VoutA[(A[a])]++;
        }
        if (!directed)
        {
        VinA[(A[a+1])]++;
        VinA[(A[a])]++;
        }

    }



    PathsA.clear();

    if (InscribedOnly == true)
        NBPaths (A, w, PathsA, directed); // let's find all max-lenght non-branching paths of A


     if (InscribedOnly == false)
     {
         for (int a = 0; a<A.size(); a=(a+2+w))
         {
             PathsA.push_back({A[a], A[a+1]});
             if (!directed)
                 PathsA.push_back({A[a+1],A[a]});

         }
     }


   RangeVGraph (B, mb, mnb, w);


    PathsB.clear();
    if (InscribedOnly == true)
        NBPaths (B, w, PathsB, directed);  // let's find all max-lenght non-branching paths of B




    if (InscribedOnly == false)
    {
        for (int a = 0; a<B.size(); a=(a+2+w))
        {
            PathsB.push_back({B[a], B[a+1]});
        }

    }

   VinB.clear();
   VinB.resize(mb+1, 0);



   VoutB.clear();
   VoutB.resize(mb+1, 0);




   for (int a = 0; a<B.size(); a=(a+2+w))
   {

       if (directed)
       {
       VinB[(B[a+1])]++;
       VoutB[(B[a])]++;
       }
       if (!directed)
       {
       VinB[(B[a+1])]++;
       VinB[(B[a])]++;
       }

   }




   //***********




   // Умножение колец в А

   // all circles of NB-paths of A will be multiplied as follows: all vertices should be as the starting in the path


  VertPathsACircles.clear();

  PathsASizeWithNoCircles = PathsA.size();


  temp= PathsA.size();

//  if (!eq)
  {

   for (int j=0; j<PathsASizeWithNoCircles; j++)
   {

       if (InscribedOnly == false) break;

       if (PathsA[j].size()<=2) continue;



  if ( (PathsA[j][0] == PathsA[j][PathsA[j].size()-1]))
    {

       E=PathsA[j];

        for (int x=1; x<PathsA[j].size()-1; x++)
        {
            E.push_back(E[1]);
            E.erase(E.begin());
            PathsA.push_back(E);
         }

          E.clear();

      }

   }

   // Конец Умножение колец в А
   // end of multiplying of circles
}




//***************

   temp = PathsA.size();


   // start of Stage II "NB-paths matching"

   NPaths.clear();
   NPaths.resize(PathsB.size()); // здесь по каждому путь в PathsB будет набор триплетов: номер соотвествующего пути в PathsA, стартовая позиция в нем и его длина
   // NPaths[j]  will contain "probably relevant" NB-paths from A to j-th NB-path of B as 3 numbers: number of NB-path of A in PathsA, starting position in it from the beginning and its lenght.


   for (int j=0; j<PathsB.size(); j++)
       NPaths[j].clear();

   t1 = PathsA.size();
   if (!eq)
   {



       for (int j=0; j<PathsB.size(); j++)   // сбор внутренних путей  //  //considering internal paths of PathsB.
       {

           if ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) continue; //не рассматривать пока концевые
           if ( (VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1) continue; //не рассматривать пока концевые

           if ( (PathsB[j][0] == PathsB[j][PathsB[j].size()-1]) && ((VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==2) ) continue; // не рассматривать пока простые кольца



           for (int i=0; i<PathsASizeWithNoCircles; i++)  // не рассматриваем разрезы колец
           {


               if (PathsB[j].size()!=PathsA[i].size())
                   continue;


                if (  ( (PathsB[j][0] == PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) ) || ( (PathsB[j][0] != PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) ))
                    if ( (VinB[(PathsB[j][0])]<= VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]<= VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]<= VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]<= VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )
                        {
                        f2=0;
                        for (int a=1; a<PathsB[j].size(); a++)
                        {
                            if (directed)
                                if (MultEdgesA[std::pair <int, int>(PathsA[i][a-1], PathsA[i][a]) ] < MultEdgesB[std::pair <int, int>(PathsB[j][a-1], PathsB[j][a])])
                                 {f2=1; break;}

                            if (!directed)
                                 if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][a-1], PathsA[i][a]), std::max(PathsA[i][a-1], PathsA[i][a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                                  {f2=1; break;}

                        }

                        if (f2==0)
                           {
                                NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

                                NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                                NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                            if (PreThinning)
                                for (int x=1; x<PathsA[i].size(); x++)
                                {
                                    if (directed)
                                        A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                                    if (!directed)
                                        A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                                }
                            }

                        }


                if ((!directed) && (PathsB[j][0] != PathsB[j][PathsB[j].size()-1])&& (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) &&(InscribedOnly == true))
                //if ((!directed) && (PathsB[j][0] != PathsB[j][PathsB[j].size()-1])&& (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) )
                {

                    E=PathsA[i];
                    reverse (PathsA[i].begin(), PathsA[i].end());


                    if (  ( (PathsB[j][0] == PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) ) || ( (PathsB[j][0] != PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) ))
                        if ( (VinB[(PathsB[j][0])]<= VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]<= VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]<= VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]<= VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )
                            {

                            f2=0;
                            for (int a=1; a<PathsB[j].size(); a++)
                            {
                                     if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][a-1], PathsA[i][a]), std::max(PathsA[i][a-1], PathsA[i][a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                                     {f2=1; break;}
                            }

                            if (f2==0)
                            {

                                reverse (E.begin(), E.end());
                                PathsA.push_back(E);
                                NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                                NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                                NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                             if (PreThinning)
                                for (int x=1; x<PathsA[i].size(); x++)
                                {
                                        A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                                }
                            }

                           }

                    E.clear();

                    reverse (PathsA[i].begin(), PathsA[i].end());

                }
           }
       }




   for (int j=0; j<PathsB.size(); j++)   // сбор концевых путей //considering in/out rays of PathsB
   {


       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)) continue; //палки не смотрим

       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])>1)) goto l1;
       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])>1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)) goto l1;

       continue;



       l1: for (int i=0; i<PathsASizeWithNoCircles; i++)  // разрезы колец не смотрим
       {


           if ( (VinB[(PathsB[j][0])]<= VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]<= VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]<= VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]<= VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()<=PathsA[i].size()) )
            {


                if ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)
                {

                    f2=0;
                    for (int a=1; a<PathsB[j].size(); a++)
                    {
                        if (directed)
                            if (MultEdgesA[std::pair <int, int>(PathsA[i][a-1], PathsA[i][a]) ] < MultEdgesB[std::pair <int, int>(PathsB[j][a-1], PathsB[j][a])])
                             {f2=1; break;}

                        if (!directed)
                             if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][a-1], PathsA[i][a]), std::max(PathsA[i][a-1], PathsA[i][a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                              {f2=1; break;}

                    }

                    if (f2==0)
                    {

                        NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA
                        NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                        NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                    if (PreThinning)
                        for (int x=1; x<PathsA[i].size(); x++)
                        {
                            if (directed)
                                A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                            if (!directed)
                                A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                        }
                    }

                }

                if ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1)
                {
                    f2=0;
                    for (int a=1; a<PathsB[j].size(); a++)
                    {
                        if (directed)
                            if (MultEdgesA[std::pair <int, int>(PathsA[i][PathsA[i].size()-PathsB[j].size()+a-1], PathsA[i][PathsA[i].size()-PathsB[j].size()+a]) ] < MultEdgesB[std::pair <int, int>(PathsB[j][a-1], PathsB[j][a])])
                             {f2=1; break;}

                        if (!directed)
                             if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][PathsA[i].size()-PathsB[j].size()+a-1], PathsA[i][PathsA[i].size()-PathsB[j].size()+a]), std::max(PathsA[i][PathsA[i].size()-PathsB[j].size()+a-1], PathsA[i][PathsA[i].size()-PathsB[j].size()+a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                              {f2=1; break;}

                    }

                    if (f2==0)
                    {

                        NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA
                        NPaths[j].push_back(PathsA[i].size()-PathsB[j].size());  // стартовая позиция в нем  //statring posiyion in it
                        NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght

                     if (PreThinning)
                        for (int x=1; x<PathsA[i].size(); x++)
                        {
                            if (directed)
                                A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                            if (!directed)
                                A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                        }

                    }
                 }


            }


           if ((!directed)&&(InscribedOnly == true))
           //if ((!directed))
           {

               E=PathsA[i];
               reverse (PathsA[i].begin(), PathsA[i].end());

               if ( (VinB[(PathsB[j][0])]<= VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]<= VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]<= VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]<= VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()<=PathsA[i].size()) )
                {


                    if ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)
                    {
                        f2=0;
                        for (int a=1; a<PathsB[j].size(); a++)
                        {
                            if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][a-1], PathsA[i][a]), std::max(PathsA[i][a-1], PathsA[i][a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                                  {f2=1; break;}

                        }

                        if (f2==0)
                        {
                            reverse (E.begin(), E.end());
                            PathsA.push_back(E);

                            NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                            NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                            NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                         if (PreThinning)
                            for (int x=1; x<PathsA[i].size(); x++)
                            {
                                A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                            }
                        }
                    }

                    if ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1)
                    {

                        f2=0;
                        for (int a=1; a<PathsB[j].size(); a++)
                        {
                            if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][PathsA[i].size()-PathsB[j].size()+a-1], PathsA[i][PathsA[i].size()-PathsB[j].size()+a]), std::max(PathsA[i][PathsA[i].size()-PathsB[j].size()+a-1], PathsA[i][PathsA[i].size()-PathsB[j].size()+a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                                  {f2=1; break;}

                        }

                        if (f2==0)
                        {

                            reverse (E.begin(), E.end());
                            PathsA.push_back(E);

                            NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA
                            NPaths[j].push_back(PathsA[i].size()-PathsB[j].size());  // стартовая позиция в нем  //statring posiyion in it
                            NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght

                         if (PreThinning)
                            for (int x=1; x<PathsA[i].size(); x++)
                            {
                                 A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                            }
                        }

                     }
                }
               E.clear();
               reverse (PathsA[i].begin(), PathsA[i].end());
           }

      }

   }


   for (int j=0; j<PathsB.size(); j++)   // сбор простых цепей  // considering chains of PathsB
   {

       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)) goto l11;


       continue;


       l11: for (int i=0; i<t1; i++)
       {

          if ( (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) && (PathsB[j].size()<=(PathsA[i].size()-1)) && (InscribedOnly == true)) // если вписываем в кольцо
            //if ( (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) && (PathsB[j].size()<=(PathsA[i].size()-1)) ) // если вписываем в кольцо
           {

               for (int z=0; z<=PathsA[i].size()-1-PathsB[j].size(); z++)

               {
                   f2=0;
                   for (int a=1; a<PathsB[j].size(); a++)
                   {
                       if (directed)
                           if (MultEdgesA[std::pair <int, int>(PathsA[i][z+a-1], PathsA[i][z+a]) ] < MultEdgesB[std::pair <int, int>(PathsB[j][a-1], PathsB[j][a])])
                            {f2=1; break;}

                       if (!directed)
                            if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][z+a-1], PathsA[i][z+a]), std::max(PathsA[i][z+a-1], PathsA[i][z+a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                             {f2=1; break;}

                   }

                   if (f2==0)
                  {

                       NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

                       NPaths[j].push_back(z); // стартовая позиция в нем  //statring posiyion in it

                       NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght



                    if (PreThinning)
                       for (int x=1; x<PathsA[i].size(); x++)
                       {
                           if (directed)
                               A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                           if (!directed)
                               A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                       }
                   }
               }



               if ((!directed)&&(InscribedOnly == true))
               //if ((!directed))
               {

                   E = PathsA[i];
                   reverse(E.begin(), E.end());
                   for (int z=0; z<=PathsA[i].size()-1-PathsB[j].size(); z++)

                   {
                       f2=0;
                       for (int a=1; a<PathsB[j].size(); a++)
                       {

                           if (MultEdgesA[std::pair <int, int>( std::min(E[z+a-1], E[z+a]), std::max(E[z+a-1], E[z+a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                                {f2=1; break;}

                       }

                       if (f2==0)
                       {
                           PathsA.push_back(E);

                           NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                           NPaths[j].push_back(z); // стартовая позиция в нем  //statring posiyion in it

                           NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                           if (PreThinning)
                              for (int x=1; x<PathsA[i].size(); x++)
                              {
                                  if (directed)
                                      A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                                  if (!directed)
                                      A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                              }
                       }

                   }

               }


           }



           if ( (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) && (PathsB[j].size()<=PathsA[i].size()) )  // Нашли: не кольцо, не меньшей длины


            {
                for (int z=0; z<=PathsA[i].size()-PathsB[j].size(); z++)

                {
                    f2=0;
                    for (int a=1; a<PathsB[j].size(); a++)
                    {
                        if (directed)
                            if (MultEdgesA[std::pair <int, int>(PathsA[i][z+a-1], PathsA[i][z+a]) ] < MultEdgesB[std::pair <int, int>(PathsB[j][a-1], PathsB[j][a])])
                             {f2=1; break;}

                        if (!directed)
                             if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][z+a-1], PathsA[i][z+a]), std::max(PathsA[i][z+a-1], PathsA[i][z+a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                              {f2=1; break;}

                    }

                    if (f2==0)
                    {

                        NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

                        NPaths[j].push_back(z); // стартовая позиция в нем  //statring posiyion in it

                        NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght



                    if (PreThinning)
                        for (int x=1; x<PathsA[i].size(); x++)
                        {
                            if (directed)
                                A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                            if (!directed)
                                A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                        }
                    }
                }


                if ((!directed)&&(InscribedOnly == true))
                //if ((!directed))
                {
                    E = PathsA[i];
                    reverse(E.begin(), E.end());
                    for (int z=0; z<=PathsA[i].size()-PathsB[j].size(); z++)
                    {
                        f2=0;
                        for (int a=1; a<PathsB[j].size(); a++)
                        {
                             if (MultEdgesA[std::pair <int, int>( std::min(E[z+a-1], E[z+a]), std::max(E[z+a-1], E[z+a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                                  {f2=1; break;}

                        }

                        if (f2==0)
                        {

                         PathsA.push_back(E);


                         NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                         NPaths[j].push_back(z); // стартовая позиция в нем  //statring posiyion in it

                         NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                         if (PreThinning)
                            for (int x=1; x<PathsA[i].size(); x++)
                            {
                                if (directed)
                                    A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                                if (!directed)
                                    A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                            }
                        }


                    }

                }
              }
            }

         }

   for (int j=0; j<PathsB.size(); j++)   // сбор циклов (колец)
   {


       if( (PathsB[j][0] != PathsB[j][PathsB[j].size()-1]))    continue;  // смотрим только кольца



       for (int i=0; i<t1; i++)  // разрезы колец не смотрим, включаем как одно вхождение-совпадение, по 1 разу
       {


           if ( (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) && (PathsB[j].size()==PathsA[i].size()) ) // если нашли кольцо  такой же длины
           {
               f2=0;
               for (int a=1; a<PathsB[j].size(); a++)
               {
                   if (directed)
                       if (MultEdgesA[std::pair <int, int>(PathsA[i][a-1], PathsA[i][a]) ] < MultEdgesB[std::pair <int, int>(PathsB[j][a-1], PathsB[j][a])])
                        {f2=1; break;}

                   if (!directed)
                        if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][a-1], PathsA[i][a]), std::max(PathsA[i][a-1], PathsA[i][a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                         {f2=1; break;}

               }

               if (f2==0)
               {

                   NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

                   NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                   NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


               if (PreThinning)
                   for (int x=1; x<PathsA[i].size(); x++)
                   {
                       if (directed)
                           A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                       if (!directed)
                           A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                   }
               }


               //if (!directed)
               if ((!directed)&&(InscribedOnly == true))
               {
                   E = PathsA[i];
                   reverse(E.begin(), E.end());
                   f2=0;
                   for (int a=1; a<PathsB[j].size(); a++)
                   {
                            if (MultEdgesA[std::pair <int, int>( std::min(E[a-1], E[a]), std::max(E[a-1], E[a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                             {f2=1; break;}

                   }

                   if (f2==0)
                   {
                        PathsA.push_back(E);
                       NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA
                       NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                       NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght

                       if (PreThinning)
                          for (int x=1; x<PathsA[i].size(); x++)
                          {
                              if (directed)
                                  A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                              if (!directed)
                                  A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                          }
                   }

               }
           }

       }
    }

    }








   if (eq)  //  ========================================
   {



       for (int j=0; j<PathsB.size(); j++)   // сбор внутренних путей  //  //considering internal paths of PathsB.
       {

           if ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) continue; //не рассматривать пока концевые
           if ( (VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1) continue; //не рассматривать пока концевые

           if ( (PathsB[j][0] == PathsB[j][PathsB[j].size()-1]) && ((VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==2) ) continue; // не рассматривать пока простые кольца


           for (int i=0; i<PathsASizeWithNoCircles; i++)  // не рассматриваем разрезы колец
           {
               if (PathsB[j].size()!=PathsA[i].size())
                   continue;

                if (  ( (PathsB[j][0] == PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) ) || ( (PathsB[j][0] != PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) ))
                    if ( (VinB[(PathsB[j][0])]== VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]== VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]== VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]== VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )

                    {
                    f2=0;
                    for (int a=1; a<PathsB[j].size(); a++)
                    {
                        if (directed)
                            if (MultEdgesA[std::pair <int, int>(PathsA[i][a-1], PathsA[i][a]) ] < MultEdgesB[std::pair <int, int>(PathsB[j][a-1], PathsB[j][a])])
                             {f2=1; break;}

                        if (!directed)
                             if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][a-1], PathsA[i][a]), std::max(PathsA[i][a-1], PathsA[i][a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                              {f2=1; break;}

                    }

                    if (f2==0)
                       {
                            NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

                            NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                            NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                         if (PreThinning)
                            for (int x=1; x<PathsA[i].size(); x++)
                            {
                                if (directed)
                                    A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                                if (!directed)
                                    A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                            }
                        }

                    }



                if ((!directed) && (PathsB[j][0] != PathsB[j][PathsB[j].size()-1])&& (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]))
                {

                    E=PathsA[i];
                    reverse (PathsA[i].begin(), PathsA[i].end());



                    if (  ( (PathsB[j][0] == PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) ) || ( (PathsB[j][0] != PathsB[j][PathsB[j].size()-1]) && (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) ))
                        if ( (VinB[(PathsB[j][0])]== VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]== VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]== VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]== VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )
                        {

                            f2=0;
                            for (int a=1; a<PathsB[j].size(); a++)
                            {
                                     if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][a-1], PathsA[i][a]), std::max(PathsA[i][a-1], PathsA[i][a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                                     {f2=1; break;}
                            }

                            if (f2==0)
                            {

                                reverse (E.begin(), E.end());
                                PathsA.push_back(E);
                                NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                                NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                                NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                             if (PreThinning)
                                for (int x=1; x<PathsA[i].size(); x++)
                                {
                                        A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                                }
                            }

                       }

                    E.clear();

                    reverse (PathsA[i].begin(), PathsA[i].end());

                }
           }
       }



   for (int j=0; j<PathsB.size(); j++)   // сбор концевых путей //considering in/out rays of PathsB
   {


       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)) continue; //палки не смотрим

       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])>1)) goto l1eq;
       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])>1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)) goto l1eq;

       continue;



       l1eq: for (int i=0; i<PathsASizeWithNoCircles; i++)  // разрезы колец не смотрим
       {

           if (PathsB[j].size()!=PathsA[i].size())
               continue;


            if ( (VinB[(PathsB[j][0])]== VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]== VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]== VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]== VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )

            {


                if ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)
                {

                    f2=0;
                    for (int a=1; a<PathsB[j].size(); a++)
                    {
                        if (directed)
                            if (MultEdgesA[std::pair <int, int>(PathsA[i][a-1], PathsA[i][a]) ] < MultEdgesB[std::pair <int, int>(PathsB[j][a-1], PathsB[j][a])])
                             {f2=1; break;}

                        if (!directed)
                             if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][a-1], PathsA[i][a]), std::max(PathsA[i][a-1], PathsA[i][a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                              {f2=1; break;}

                    }

                    if (f2==0)
                    {

                        NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA
                        NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                        NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                     if (PreThinning)
                        for (int x=1; x<PathsA[i].size(); x++)
                        {
                            if (directed)
                                A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                            if (!directed)
                                A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                        }
                    }

                }


                if ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1)
                {
                    f2=0;
                    for (int a=1; a<PathsB[j].size(); a++)
                    {
                        if (directed)
                            if (MultEdgesA[std::pair <int, int>(PathsA[i][PathsA[i].size()-PathsB[j].size()+a-1], PathsA[i][PathsA[i].size()-PathsB[j].size()+a]) ] < MultEdgesB[std::pair <int, int>(PathsB[j][a-1], PathsB[j][a])])
                             {f2=1; break;}

                        if (!directed)
                             if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][PathsA[i].size()-PathsB[j].size()+a-1], PathsA[i][PathsA[i].size()-PathsB[j].size()+a]), std::max(PathsA[i][PathsA[i].size()-PathsB[j].size()+a-1], PathsA[i][PathsA[i].size()-PathsB[j].size()+a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                              {f2=1; break;}

                    }

                    if (f2==0)
                    {

                        NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA
                        NPaths[j].push_back(PathsA[i].size()-PathsB[j].size());  // стартовая позиция в нем  //statring posiyion in it
                        NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght

                     if (PreThinning)
                        for (int x=1; x<PathsA[i].size(); x++)
                        {
                            if (directed)
                                A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                            if (!directed)
                                A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                        }

                    }
                 }


            }


           if (!directed)
           {

            E=PathsA[i];
            reverse (PathsA[i].begin(), PathsA[i].end());

            if ( (VinB[(PathsB[j][0])]== VinA[(PathsA[i][0])]) && (VinB[(PathsB[j][PathsB[j].size()-1])]== VinA[(PathsA[i][PathsA[i].size()-1])])&& (VoutB[(PathsB[j][0])]== VoutA[(PathsA[i][0])]) && (VoutB[(PathsB[j][PathsB[j].size()-1])]== VoutA[(PathsA[i][PathsA[i].size()-1])]) && (PathsB[j].size()==PathsA[i].size()) )

                {


                    if ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)
                    {
                        f2=0;
                        for (int a=1; a<PathsB[j].size(); a++)
                        {
                            if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][a-1], PathsA[i][a]), std::max(PathsA[i][a-1], PathsA[i][a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                                  {f2=1; break;}

                        }

                        if (f2==0)
                        {
                            reverse (E.begin(), E.end());
                            PathsA.push_back(E);

                            NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                            NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                            NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                          if (PreThinning)
                            for (int x=1; x<PathsA[i].size(); x++)
                            {
                                A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                            }
                        }
                    }


                    if ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1)

                    {

                        f2=0;
                        for (int a=1; a<PathsB[j].size(); a++)
                        {
                            if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][PathsA[i].size()-PathsB[j].size()+a-1], PathsA[i][PathsA[i].size()-PathsB[j].size()+a]), std::max(PathsA[i][PathsA[i].size()-PathsB[j].size()+a-1], PathsA[i][PathsA[i].size()-PathsB[j].size()+a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                                  {f2=1; break;}

                        }

                        if (f2==0)
                        {

                            reverse (E.begin(), E.end());
                            PathsA.push_back(E);

                            NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA
                            NPaths[j].push_back(PathsA[i].size()-PathsB[j].size());  // стартовая позиция в нем  //statring posiyion in it
                            NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght

                         if (PreThinning)
                            for (int x=1; x<PathsA[i].size(); x++)
                            {
                                 A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                            }
                        }

                     }


                }
               E.clear();
               reverse (PathsA[i].begin(), PathsA[i].end());
           }


      }

   }


   for (int j=0; j<PathsB.size(); j++)   // сбор простых цепей  // considering chains of PathsB
   {

       if( ( (VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])==1) && ((VinB[(PathsB[j][PathsB[j].size()-1])]+VoutB[PathsB[j][PathsB[j].size()-1]])==1)) goto l11eq;


       continue;


       l11eq: for (int i=0; i<t1; i++)
       {

           if (PathsB[j].size()!=PathsA[i].size())
               continue;


       if( ( (VinA[(PathsA[i][0])]+VoutA[PathsA[i][0]])==1) && ((VinA[(PathsA[i][PathsA[i].size()-1])]+VoutA[PathsA[i][PathsA[i].size()-1]])==1))
          if ( (PathsA[i][0] != PathsA[i][PathsA[i].size()-1]) && (PathsB[j].size()==PathsA[i].size()) )  // Нашли: не кольцо, равной длины

          {
              for (int z=0; z<=PathsA[i].size()-PathsB[j].size(); z++)

              {
                  f2=0;
                  for (int a=1; a<PathsB[j].size(); a++)
                  {
                      if (directed)
                          if (MultEdgesA[std::pair <int, int>(PathsA[i][z+a-1], PathsA[i][z+a]) ] < MultEdgesB[std::pair <int, int>(PathsB[j][a-1], PathsB[j][a])])
                           {f2=1; break;}

                      if (!directed)
                           if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][z+a-1], PathsA[i][z+a]), std::max(PathsA[i][z+a-1], PathsA[i][z+a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                            {f2=1; break;}

                  }

                  if (f2==0)
                  {

                      NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

                      NPaths[j].push_back(z); // стартовая позиция в нем  //statring posiyion in it

                      NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght



                   if (PreThinning)
                      for (int x=1; x<PathsA[i].size(); x++)
                      {
                          if (directed)
                              A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                          if (!directed)
                              A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                      }
                  }
              }


              if (!directed)
              {
                  E = PathsA[i];
                  reverse(E.begin(), E.end());
                  for (int z=0; z<=PathsA[i].size()-PathsB[j].size(); z++)
                  {
                      f2=0;
                      for (int a=1; a<PathsB[j].size(); a++)
                      {
                           if (MultEdgesA[std::pair <int, int>( std::min(E[z+a-1], E[z+a]), std::max(E[z+a-1], E[z+a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                                {f2=1; break;}

                      }

                      if (f2==0)
                      {
                          PathsA.push_back(E);
                       NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA

                       NPaths[j].push_back(z); // стартовая позиция в нем  //statring posiyion in it

                       NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght




                       if (PreThinning)
                          for (int x=1; x<PathsA[i].size(); x++)
                          {
                              if (directed)
                                  A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                              if (!directed)
                                  A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                          }
                      }
                  }
              }
            }

       }


    }

   for (int j=0; j<PathsB.size(); j++)   // сбор простых циклов - в любые циклы // considering  simple cycles of PathsB
   {

       if( (PathsB[j][0] != PathsB[j][PathsB[j].size()-1]))    continue;  // смотрим только кольца


       if ((VinB[(PathsB[j][0])]+VoutB[PathsB[j][0]])!=2) continue; // простые



       for (int i=0; i<t1; i++)  //
       {
           if (PathsB[j].size()!=PathsA[i].size())
               continue;


           if ( (PathsA[i][0] == PathsA[i][PathsA[i].size()-1]) && (PathsB[j].size()==PathsA[i].size()) && ((VinA[(PathsA[i][0])]+VoutA[PathsA[i][0]])==2) ) // если простое нашли кольцо  такой же длины

           {
               f2=0;
               for (int a=1; a<PathsB[j].size(); a++)
               {
                   if (directed)
                       if (MultEdgesA[std::pair <int, int>(PathsA[i][a-1], PathsA[i][a]) ] < MultEdgesB[std::pair <int, int>(PathsB[j][a-1], PathsB[j][a])])
                        {f2=1; break;}

                   if (!directed)
                        if (MultEdgesA[std::pair <int, int>( std::min(PathsA[i][a-1], PathsA[i][a]), std::max(PathsA[i][a-1], PathsA[i][a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                         {f2=1; break;}

               }

               if (f2==0)
               {

                   NPaths[j].push_back(i);  // номер пути  //  number of path of PathsA

                   NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                   NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght


                if (PreThinning)
                   for (int x=1; x<PathsA[i].size(); x++)
                   {
                       if (directed)
                           A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                       if (!directed)
                           A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                   }
               }


               if (!directed)
               {
                   E = PathsA[i];
                   reverse(E.begin(), E.end());
                   f2=0;
                   for (int a=1; a<PathsB[j].size(); a++)
                   {

                            if (MultEdgesA[std::pair <int, int>( std::min(E[a-1], E[a]), std::max(E[a-1], E[a])) ] < MultEdgesB[std::pair <int, int>( std::min(PathsB[j][a-1], PathsB[j][a]), std::max(PathsB[j][a-1], PathsB[j][a]))])
                             {f2=1; break;}

                   }

                   if (f2==0)
                   {
                        PathsA.push_back(E);
                       NPaths[j].push_back(PathsA.size()-1);  // номер пути  //  number of path of PathsA
                       NPaths[j].push_back(0); // стартовая позиция в нем  //statring posiyion in it
                       NPaths[j].push_back(PathsB[j].size()); // его длина  // lenght

                       if (PreThinning)
                          for (int x=1; x<PathsA[i].size(); x++)
                          {
                              if (directed)
                                  A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                              if (!directed)
                                  A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                          }
                   }

               }
           }


       }
   }


    }


   for (int i=0; i<NPaths.size(); i++)
   {

       if (NPaths[i].size()==0)
       {   // если для какого-то пути из B нет аналогов в A
        return 0;
       }
   }




// "pre-Thinning of data"

if (PreThinning)
{
  if ((A1.size()<A.size()/2) )
   {

       A.clear();
       for (auto it1=A1.begin(); it1!=A1.end(); it1++)
       {
           A.push_back((*it1).first);
           A.push_back((*it1).second);
       }


       A1.clear();

       goto lprorez1;
   }
}

// end of "pre-Thinning of data"



   D.clear();

   if ((DA.size()==0)||(DB.size()==0))
   {

       temp=A.size();
       if (!directed)
       {
           E=A;
           std::reverse(E.begin(), E.end());
           A.reserve(A.size()+E.size());
           A.insert(A.end(), E.begin(), E.end());
           E.clear();
       }


       for (int i=0; i<=m; i++)
       {
           DistanceBFA (A, D, i, false);
           DA.push_back(D);
       }


       temp=B.size();
       if (!directed)
       {
           E=B;
           std::reverse(E.begin(), E.end());
           B.reserve(B.size()+E.size());
           B.insert(B.end(), E.begin(), E.end());
           E.clear();
       }


       for (int i=0; i<=mb; i++)
       {
           DistanceBFA (B, D, i, false);
           DB.push_back(D);
       }



       temp=A.size()/2;
       if (!directed)
           A.resize(temp);
       temp=B.size()/2;
       if (!directed)
           B.resize(temp);
    }


            temp=0;



            for (int i=0; i<NPaths.size(); i++)
              {

                  if (NPaths[i].size()==0)
                  {
                      return 0;
                      temp=-1;   // если для какого-то пути из B нет аналогов в A

                  }
              }

            // end of Stage II "NB-paths matching"


            // start of Stage III "Thinning of data"

             if (temp!=-1)


              {

                c=INT_MAX;
                for (int i=0; i<NPaths.size(); i++)
                    if (NPaths[i].size()<c)
                    {c= NPaths[i].size();
                        t=i;
                    }


                f2=0;
                for (int i=0; i<NPaths.size(); i++)
                {
                    if (i==t) continue;

                    for (int y=0; y<NPaths[i].size(); y=y+3)
                    {
                        f1=1;
                        for (int g=0; g<NPaths[t].size(); g=g+3)
                        {
                            if (          ((  (DA[PathsA[NPaths[t][g]][NPaths[t][g+1]]][PathsA[NPaths[i][y]][NPaths[i][y+1]]]  ) <=  DB[PathsB[t][0]][PathsB[i][0]]) && (  (DA[PathsA[NPaths[i][y]][NPaths[i][y+1]]][PathsA[NPaths[t][g]][NPaths[t][g+1]]]  ) <=  DB[PathsB[i][0]][PathsB[t][0]]) )   &&   ((  (DA[PathsA[NPaths[t][g]][NPaths[t][g+1]+PathsB[t].size()-1]][PathsA[NPaths[i][y]][NPaths[i][y+1]+PathsB[i].size()-1]]  ) <=  DB[PathsB[t][PathsB[t].size()-1]][PathsB[i][PathsB[i].size()-1]]) && (  (DA[PathsA[NPaths[i][y]][NPaths[i][y+1]+PathsB[i].size()-1]][PathsA[NPaths[t][g]][NPaths[t][g+1]+PathsB[t].size()-1]]  ) <=  DB[PathsB[i][PathsB[i].size()-1]][PathsB[t][PathsB[t].size()-1]]) )     )
                            {
                                f1=0;
                                break;
                            }

                        }

                        if (f1==1)
                        {
                            f2=1;

                            if (y!=NPaths[i].size()-3)
                            {
                                SwapInVector(NPaths[i], y, NPaths[i].size()-3);
                                SwapInVector(NPaths[i], y+1, NPaths[i].size()-2);
                                SwapInVector(NPaths[i], y+2, NPaths[i].size()-1);
                            }
                            NPaths[i].pop_back();
                            NPaths[i].pop_back();
                            NPaths[i].pop_back();
                            y=y-3;


                        }

                    }

                  }

                //***


                for (int tt=0; tt<NPaths.size(); tt++)
                {


                    if (NPaths[tt].size()==0)
                    {
                        temp=-1;
                        break;
                    }

                    for (int i=0; i<NPaths.size(); i++)
                    {

                        if (NPaths[i].size()==0)
                        {
                            temp=-1;
                            break;
                        }
                        if (i==tt) continue;

                        for (int y=0; y<NPaths[i].size(); y=y+3)
                        {
                            f1=1;
                            for (int g=0; g<NPaths[tt].size(); g=g+3)
                            {
                                if (          ((  (DA[PathsA[NPaths[tt][g]][NPaths[tt][g+1]]][PathsA[NPaths[i][y]][NPaths[i][y+1]]]  ) <=  DB[PathsB[tt][0]][PathsB[i][0]]) && (  (DA[PathsA[NPaths[i][y]][NPaths[i][y+1]]][PathsA[NPaths[tt][g]][NPaths[tt][g+1]]]  ) <=  DB[PathsB[i][0]][PathsB[tt][0]]) )   &&   ((  (DA[PathsA[NPaths[tt][g]][NPaths[tt][g+1]+PathsB[tt].size()-1]][PathsA[NPaths[i][y]][NPaths[i][y+1]+PathsB[i].size()-1]]  ) <=  DB[PathsB[tt][PathsB[tt].size()-1]][PathsB[i][PathsB[i].size()-1]]) && (  (DA[PathsA[NPaths[i][y]][NPaths[i][y+1]+PathsB[i].size()-1]][PathsA[NPaths[tt][g]][NPaths[tt][g+1]+PathsB[tt].size()-1]]  ) <=  DB[PathsB[i][PathsB[i].size()-1]][PathsB[tt][PathsB[tt].size()-1]]) )     )
                                {
                                    f1=0;
                                    break;
                                }

                            }

                            if (f1==1)
                            {
                                f2=1;

                                if (y!=NPaths[i].size()-3)
                                {
                                    SwapInVector(NPaths[i], y, NPaths[i].size()-3);
                                    SwapInVector(NPaths[i], y+1, NPaths[i].size()-2);
                                    SwapInVector(NPaths[i], y+2, NPaths[i].size()-1);
                                }
                                NPaths[i].pop_back();
                                NPaths[i].pop_back();
                                NPaths[i].pop_back();
                                y=y-3;


                            }

                        }

                        if (NPaths[i].size()==0)
                        {
                            temp=-1;
                            break;
                        }

                      }
                    if (temp==-1) break;
                }

                //***

                for (int i=0; i<NPaths.size(); i++)
                {

                    if (NPaths[i].size()==0)
                    {
                        temp=-1;
                        break;
                    }

                    for (int y=0; y<NPaths[i].size(); y=y+3)
                    {

                        if (  ( (PathsB[i][0]==PathsB[i][PathsB[i].size()-1]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]]!= PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]) ) || ( (PathsB[i][0]!=PathsB[i][PathsB[i].size()-1]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]]== PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]) ) )

                        {
                            f2=1;

                            if (y!=NPaths[i].size()-3)
                            {
                                SwapInVector(NPaths[i], y, NPaths[i].size()-3);
                                SwapInVector(NPaths[i], y+1, NPaths[i].size()-2);
                                SwapInVector(NPaths[i], y+2, NPaths[i].size()-1);
                            }
                            NPaths[i].pop_back();
                            NPaths[i].pop_back();
                            NPaths[i].pop_back();
                            y=y-3;


                        }

                        if (NPaths[i].size()==0)
                        {
                            temp=-1;
                            break;
                        }

                    }


                    if (NPaths[i].size()==0)
                    {
                        temp=-1;
                        break;
                    }

                  }





                for (int tt=0; tt<NPaths.size(); tt++)
                {


                    if (NPaths[tt].size()==0)
                    {
                        temp=-1;
                        break;
                    }

                    for (int i=0; i<NPaths.size(); i++)
                    {

                        if (NPaths[i].size()==0)
                        {
                            temp=-1;
                            break;
                        }
                        if (i==tt) continue;


                        for (int y=0; y<NPaths[i].size(); y=y+3)
                        {
                            f1=1;

                            //1
                            for (int g=0; g<NPaths[tt].size(); g=g+3)
                            {
                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1.1

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.1.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**

                                            {
                                                f1=0;
                                                break;
                                            }


                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1.2

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))


                                            //1.2.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**

                                            {
                                                f1=0;
                                                break;
                                            }


                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1/3

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/3/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**

                                            {
                                                f1=0;
                                                break;
                                            }

                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1/4

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/4/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**

                                            {
                                                f1=0;
                                                break;
                                            }




                                //2
                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1.1

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.1.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }



                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1.2

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.2.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }


                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                     if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1/3

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/3/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }

                                if ( (PathsB[i][0]==PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1/4

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/4/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }










                                //3
                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1.1

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.1.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }


                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1.2

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.2.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**



                                            {
                                                f1=0;
                                                break;
                                            }


                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1/3

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/3/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**



                                            {
                                                f1=0;
                                                break;
                                            }


                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]==PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1/4

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/4/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }







                                //4
                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1.1

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.1.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }

                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]==PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1.2

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1.2.1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }

                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                   if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]==PathsB[i][PathsB[i].size()-1]) )  //** 1/3

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/3/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]==PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**



                                            {
                                                f1=0;
                                                break;
                                            }

                                if ( (PathsB[i][0]!=PathsB[tt][0])&&(PathsB[tt][PathsB[tt].size()-1]!=PathsB[i][PathsB[i].size()-1]) )

                                    if ( (PathsB[i][0]!=PathsB[tt][PathsB[tt].size()-1])&&(PathsB[tt][0]!=PathsB[i][PathsB[i].size()-1]) )  //** 1/4

                                        if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]))

                                            //1/4/1
                                            if ((PathsA[NPaths[i][y]][NPaths[i][y+1]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]-1+NPaths[tt][g+2]]) && (PathsA[NPaths[i][y]][NPaths[i][y+1]-1+NPaths[i][y+2]]!=PathsA[NPaths[tt][g]][NPaths[tt][g+1]]))  //**


                                            {
                                                f1=0;
                                                break;
                                            }



                            }

                            if (f1==1)
                            {
                                f2=1;

                                if (y!=NPaths[i].size()-3)
                                {
                                    SwapInVector(NPaths[i], y, NPaths[i].size()-3);
                                    SwapInVector(NPaths[i], y+1, NPaths[i].size()-2);
                                    SwapInVector(NPaths[i], y+2, NPaths[i].size()-1);
                                }
                                NPaths[i].pop_back();
                                NPaths[i].pop_back();
                                NPaths[i].pop_back();
                                y=y-3;


                            }

                        }

                        if (NPaths[i].size()==0)
                        {
                            temp=-1;
                            break;
                        }

                      }
                    if (temp==-1) break;
                }








                //***






        if (PreThinning)
              {
                if ((f2==1)&&(A.size()!=f3)&&(temp!=-1))  //&&(InscribedOnly==1)
                {
                    V1.clear();

                    for (int i=0; i<NPaths.size(); i++)
                        for (int j=0; j<NPaths[i].size(); j=j+3)
                            V1.insert(NPaths[i][j]);

                    if (PathsA.size()!=V1.size())
                    {

                    PathsA1.clear();
                     for (auto i=V1.begin(); i!=V1.end(); i++)
                         PathsA1.push_back(PathsA[*i]);




                     PathsA.clear();
                     PathsA=PathsA1;
                     A.clear();
                     A1.clear();

                     for (int i=0; i<PathsA.size(); i++)

                         for (int x=1; x<PathsA[i].size(); x++)
                         {
                             if (directed)
                                 A1.insert(std::pair<int, int>(PathsA[i][x-1],PathsA[i][x]) );

                             if (!directed)
                                 A1.insert(std::pair<int, int>(std::min(PathsA[i][x-1],PathsA[i][x]), std::max(PathsA[i][x-1],PathsA[i][x])));
                         }


                     for (auto it1=A1.begin(); it1!=A1.end(); it1++)
                     {
                         A.push_back((*it1).first);
                         A.push_back((*it1).second);
                     }

                     f3=A.size();

                     goto lprorez1;
                     }
                }

             }


            }





                for (int i=0; i<NPaths.size(); i++)
                {

                    if (NPaths[i].size()==0)
                    {temp=-1;   // если для какого-то пути из B нет аналогов в A
                        return 0;

                    }

//                    cout<<"i="<<i<<" ";
//                    VectorCout(NPaths[i]);

                }



// end of Stage III "Thinning of data"

                // start of Stage IV "Finnishing"


                c=0;

              int WordLenght= PathsB.size();

                  std::vector <int> l (PathsB.size()); // вектор разрядов

              std::vector <int> lmax (PathsB.size()); // вектор порговых значений у разрядов

              for (int g=0; g<PathsB.size(); g++)
              {
                  l [g] = 0;

                  lmax [g] = NPaths[g].size()/3-1;


              }

            l[l.size()-1]--;



            std::vector<std::vector <bool>> B1; //заготовки для матриц смежности


            MatrixSet(B1, mb+1-mnb, mb+1-mnb, 0);



            std::vector <int> IndexPermB;  // Номера вершин графа B в шкале Scale0
            IndexPermB.clear();
            IndexPermB.resize(mb+1, -1);


            for (int q1=0; q1<PathsB.size(); q1++)
            {
                if (IndexPermB[PathsB[q1][0]]==-1)
                {
                    Scale0.push_back(PathsB[q1][0]);
                    IndexPermB[PathsB[q1][0]] = Scale0.size()-1;
                }

                for (int q2=0; q2<PathsB[q1].size()-1; q2++)
                {
                    G0.push_back(PathsB[q1][q2]);
                    G0.push_back(PathsB[q1][q2+1]);

                    if (IndexPermB[PathsB[q1][q2+1]]==-1)
                    {
                        Scale0.push_back(PathsB[q1][q2+1]);
                        IndexPermB[PathsB[q1][q2+1]] = Scale0.size()-1;
                    }

                    B1  [IndexPermB[PathsB[q1][q2]]] [IndexPermB[PathsB[q1][q2+1]]]=1;
                    if (!directed) B1 [IndexPermB[PathsB[q1][q2+1]]] [IndexPermB[PathsB[q1][q2]]] = B1  [IndexPermB[PathsB[q1][q2]]] [IndexPermB[PathsB[q1][q2+1]]];

                }

            }





             //std::set<std::pair <int, int>> G1ALL3; // Служебный - для исключения из результата взаимотождественных подграфов
             std::multiset<std::pair <int, int>> G1ALL3; // Служебный - для исключения из результата взаимотождественных подграфов
             // std::unordered_set<std::pair <int, int>, PairIntHash> G1ALL3;
             G1ALL3.clear();

             std::unordered_set<std::pair <int, int>, PairIntHash> Y;
             Y.clear();

             std::unordered_set<int> Y1;
             Y1.clear();




             int *IndexPermA = new int[m+1]; // Выделение памяти для массива


//             VectorCout(lmax);
//             system("pause");
             G1=G0;
             std::vector<std::vector <bool>> B10; //заготовки для матриц смежности
            // B10=B1;



              while (true) //***
              {

                if (temp==-1) break;   // если для какого-то пути из B нет аналогов в A

              l [WordLenght-1]++;  //увеличение на 1 номера последнего разряда

              if (l [WordLenght-1] > lmax [WordLenght-1])
               {
                 r = WordLenght-1;

                 while (r>0)
                   {l [r] = 0;
                    r--;
                    l [r] ++;
                    if (l[r] <= lmax [r]) break;
                   }
               }


                Y1.clear();
                Y.clear();  // In order not to consider combination of path-candidates if any path-candidate is represented in this combination more than once.

                if (!((eq == true) || (InscribedOnly == false)))
                    for (int y=0; y<NPaths.size();y++)
                                {
                                    c = 3*l[y];
                                    Y.insert(std::pair <int, int> (NPaths[y][c], NPaths[y][c+1]));

                                    if (Y.size()!=(y+1))
                                    {
                                        if (l==lmax) goto l3;

                                        for (int x=NPaths.size()-1; x>y;x--)
                                            l[x]=lmax[x];

                                        goto l3;

                                    }

                                }

                if ((eq == true) || (InscribedOnly == false))
                    for (int y=0; y<NPaths.size();y++)
                                {
                                    c = 3*l[y];

                                    if ((eq)||(directed))
                                        Y1.insert(NPaths[y][c]);

                                    if ((InscribedOnly == false)&&(!directed))
                                    {
                                        if (((NPaths[y][c])%2)==0)
                                            Y1.insert(NPaths[y][c]);
                                        if (((NPaths[y][c])%2)==1)
                                            Y1.insert(NPaths[y][c]-1);

                                    }

                                    if (Y1.size()!=(y+1))
                                    {
                                        if (l==lmax) goto l3;

                                        for (int x=NPaths.size()-1; x>y;x--)
                                            l[x]=lmax[x];

                                        goto l3;

                                    }

                                }



                f1=0;

                  t=0;

                  //G1.clear();

                  for (int i = 0; i <= m; i++)
                      IndexPermA[i] = -1;



       //          B1=B10; //

                  Y.clear();

                 for (int y=0; y<NPaths.size();y++)
                     {
                        c = 3*l[y];
                        if (IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]]]==-1)
                           {
                              t++;
                              IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]]] = t-1;
                           }



                        //for (int x=0; x<NPaths[y][c+2]-1;x++)
                        for (int x=0; x<(PathsB[y].size()-1);x++)
                            {


                               G1[f1]=(PathsA[NPaths[y][c]][NPaths[y][c+1]+x]);
                               G1[f1+1]=(PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]);
                               f1=f1+2;

//                            G1.push_back(PathsA[NPaths[y][c]][NPaths[y][c+1]+x]);
//                            G1.push_back(PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]);

                            if (directed)
                                Y.insert(std::pair <int, int> (PathsA[NPaths[y][c]][NPaths[y][c+1]+x], PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]));
                            if (!directed)
                                Y.insert(std::pair <int, int> (std::min(PathsA[NPaths[y][c]][NPaths[y][c+1]+x], PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]), std::max(PathsA[NPaths[y][c]][NPaths[y][c+1]+x], PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1])));

//                            if (Y.size()!=G1.size()/2)
//                            {

//                                if (l==lmax) goto l3;
//                                for (int x1=NPaths.size()-1; x1>y;x1--)
//                                    l[x1]=lmax[x1];
//                                 goto l3;

//                            }

                            if (Y.size()!=f1/2)
                            {

                                if (l==lmax) goto l3;
                                for (int x1=NPaths.size()-1; x1>y;x1--)
                                    l[x1]=lmax[x1];
                                 goto l3;

                            }


                                if (IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]]==-1)
                                {
                                     t++;
                                     IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]] = t-1;
                                }

                                if (IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x]]>=B1.size())
                                {

                                    if (l==lmax) goto l3;
                                    for (int x1=NPaths.size()-1; x1>y;x1--)
                                        l[x1]=lmax[x1];
                                     goto l3;

                                }

                                if (IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]]>=B1.size())
                                {

                                    if (l==lmax) goto l3;
                                    for (int x1=NPaths.size()-1; x1>y;x1--)
                                        l[x1]=lmax[x1];
                                     goto l3;

                                }

                                if (B1  [IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x]]] [IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]]]!=1)
                                {

                                    if (l==lmax) goto l3;
                                    for (int x1=NPaths.size()-1; x1>y;x1--)
                                        l[x1]=lmax[x1];
                                     goto l3;
                                 }


//                                if (B1  [IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x]]] [IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]]]!=1)
//                                {

//                                     if (l==lmax) goto l3;
//                                     for (int x1=NPaths.size()-1; x1>y;x1--)
//                                         l[x1]=lmax[x1];
//                                      goto l3;
//                                 }

//                                B1  [IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x]]] [IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]]]=0;
//                                if (!directed)
//                                    B1[IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x+1]]][IndexPermA[PathsA[NPaths[y][c]][NPaths[y][c+1]+x]]]=0;



                              }

                       }

                 if (G0.size()!=f1)
                     goto l3;

//                 if (G0.size()!=G1.size())
//                     goto l3;


                if (!directed)
                {
                    for (int i=0; i<G1.size(); i=i+2)
                    {
                        if (G1[i]>G1[i+1]) SwapInVector(G1, i, i+1);
                    }

                }


                // we should have no equal graphs in our answer so we should eliminate those that have the same edges in different order (except one of them)

                G1ALL3.clear();

                if (directed)
                    for (int q=0; q<G0.size(); q=q+2)
                        for (int a=0; a<MultEdgesB[std::pair <int, int>(G0[q], G0[q+1]) ]; a++)
                            G1ALL3.insert(std::pair<int, int> (G1[q],G1[q+1]));
                if (!directed)
                    for (int q=0; q<G0.size(); q=q+2)
                        for (int a=0; a<MultEdgesB[std::pair <int, int>(std::min(G0[q], G0[q+1]), std::max(G0[q], G0[q+1])) ]; a++)
                            G1ALL3.insert(std::pair<int, int> (G1[q],G1[q+1]));


                   f3=0;
                    for (auto it3=G1ALL3.begin(); it3!=G1ALL3.end(); it3++)
                        {
                            G3[f3]=(*it3).first;
                            G3[f3+1]=(*it3).second;
                            f3=f3+2;
                        }
               if (b0size!=f3)
                   goto l3;




//                    G3.clear();
//                     for (auto it3=G1ALL3.begin(); it3!=G1ALL3.end(); it3++)
//                         {
//                             G3.push_back((*it3).first);
//                             G3.push_back((*it3).second);
//                         }



                if (G3.size()!=b0size)
                 goto l3;


               Result.insert(G3);



                l3: if (l==lmax)
                {
                    delete [] IndexPermA; // очистка памяти
                    break;
                }
                if ((eq==true) && (Result.size()==1))
                {
                    delete [] IndexPermA; // очистка памяти
                    break;
                }

              }

     return Result.size();
}




int DistanceTS (std::vector <int> &A, std::vector <long long int> & D, const int b, std::vector <int> & Prev, const bool weighted, int V = INT_MIN)
{

// Рассчитывает расстояния от заданной вершины b до всех прочих в орграфе. Метод работает быстрее, чем DistanceBFA за счет предварительной топологической сортировки орграфа.
// Однако метод неприменим для орграфов, содержащих любой цикл кроме петель,  в т.ч. - множественных (петли будут игнорироваться).
// Возвращается 1 в случае успеха (вектор D содержит кратчайшие расстояния от вершины b до вершины i, а вектор Prev - индекс вершин-предков в таком пути).
// По умолчанию вектор D содержит значения LLONG_MAX, а вектор Prev - "-1".
// Если был обнаружен цикл - возвращается -1 и пустые вектора D и Prev.
// На входе д.б. граф, заданный вектором смежности A (считается, что вершины нумеруются с 0), номер исходной вершины и флаг, является ли граф взвешенным.
// Для невзвешенных графов считается, что каждое ребро имеет вес = 1. Для взвешенных - длины ребер должны быть строго меньше INT_MAX.
// Также на вход подается номер наибольшей вершины V (если не передан, рассчитывается самостоятельно как номер наибольшей вершины в ребрах)
// Функция работает со взвешенными и с невзвешенными графами, причем они могут содержать петли и множественные ребра.
// Ребра могут иметь как неотрицательный (в т.ч. и нулевой), так и отрицательный вес.

// The function counts the shortest distances from the vertex b to all vertices in the graph (these distances are to be contained in vector D, i.e. D[i] means the shortest distance from b to i).
// By default vector D is filled with LLONG_MAX.
// In doing so, vector Prev is intended to contain the number of the previvous vertex for every vertex in such shortest paths ("-1" value is set by default and means "this vertex doesn't included in any such path").
// This function seems to be faster than DistanceBFA, but DistanceTS works only with graphs containing no cycles (except loops, multiply loops).
// The input graph should be directed, both weighted or unweighted (in this case we consider every edge's weight as "1".) The graph may have loops and multiple edges.
// Input data: Adjacency vector A (it is supposed that vertices are numbered starting from 0) and the maximum vertex number V (V may be not set, in this case it will be the maximum vertex number of Adjacency vector A)
// The edges of a weighted graph may have weight of 0, >0, <0, but only less than INT_MAX (<INT_MAX).
// In case we found a cycle as well as input data is incorrect the function returns "-1" and empty D and Prev.



    D.clear();
    Prev.clear();

    if (A.size()==0) return -1;

    if ((V<0)&&(V != INT_MIN)) return -1;
    if ( (A.size())%(2+weighted)!=0 ) return -1; // checking for input data correctness



    int mn, mx;
    RangeVGraph (A, mx, mn, weighted);


    if (mn<0)  // // checking for input data correctness.
    {
        return -1;
    }


    if (mx>V) V = mx; // здесь будет максимальный номер вершины // the max number of assigned to vertices

    if ((b<0) || (b>V))  // // checking for input data correctness: number of the vertex b must be in range [0, V].
    {
        return -1;
    }

    D.resize(V+1, LLONG_MAX); // По умолчанию расстояния равны + бесконечность // The default distance values is LLONG_MAX for every vertex


    Prev.resize(V+1, -1); // по умолчанию "предка" нет. // The previous vertices are not set by default (i.e. =-1 for every vertex)



    std::vector <int> order; // здесь будет храниться топологическая сортировка вершин
    order.clear();

    std::vector <int> R; // An auxiliary vector for the function TSortHP as such parameter is required, the vector should stay empty
    R.clear();

    std::vector <int> I; //  An auxiliary vector for the function TSortHP as such parameter is required, the vector should stay empty
    I.clear();

    int t=TSortHP (A, R, order, I, weighted, true);



    if (t==-1)  // if there are no topological sorting (i.e. the graph contains cycle except any loops) this function can't work.
    {
        D.clear();
        Prev.clear();
        return -1;
    }


    if (mn!=0) order.insert(order.begin(), 0); // if vertices are numbrered starting not from 0 - let's add 0

    if (V>mx)   //adding to "order" vertices that have number more than maximal in A and <= V
        for (int ff = (mx+1); ff<=V; ff++)
             order.insert(order.begin(), ff);


    int bb;

    for (int i = 0; i< order.size(); i++)   // поиск нового номера вершины начала поиска
    {

        if (order[i]==b) {bb = i; break;}

    }


    D[order[bb]] = 0; //дистанция от первой вершины до себя = 0

    std::vector <std::vector <int>> B (V+1);

    MatrixSet(B, V+1, V+1, INT_MAX);    // Создание заготовки матирицы B в виде 2-хмерного массива (из векторов)


    for (unsigned int x = 0; x<=(A.size()-(2+weighted)); x = x+2+weighted)
    {
        if (weighted)
        {
            if ( (A[x]!=A[x+1]) && ( B[(A[x])][(A[x+1])] > A[x+2] ) ) B[(A[x])][(A[x+1])] = A[x+2];  // в матрицу смежности вставляем длину кратчайшего ребра
        }

        if (!weighted)
        {
            if (A[x]!=A[x+1]) B[(A[x])][(A[x+1])] = 1;  // в матрицу смежности вставляем длину ребра
        }
    }

    // Конец заполнения матрицы смежности



    for (int b = bb; b<V; b++)              // бежим по матрице смежности от искомой вершины к большим номерам и пересчитываем дистанцию
        for (int j = b+1; j<=V; j++)
        {


            if (D[order[b]]==LLONG_MAX) continue; //если вершина b недостижима из исходной, нечего от нее расстояния пересчитывать // We should recalculate distances only from vertices that are accessible from vertex b as initial one.

            if ( (B[order[b]][order[j]]!=INT_MAX) && ((D[order[j]]==LLONG_MAX) || (D[order[j]]>(D[order[b]]+(long long int)(B[order[b]][order[j]]) ) ) ) )   {D[order[j]]=(D[order[b]]+ (long long int)(B[order[b]][order[j]]) ); Prev[order[j]]= order[b];}

        }



    return 0;
}


int DistanceTS (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <long double> & D, const int b, std::vector <int> & Prev, int V = INT_MIN)
// Модификация функции DistanceTS (см. выше) для случая нецелочисленных весов ребер (double).
// Modification of the function DistanceTS (see it above) for not-integer (double) weights of edges of a graph.
// Graph is represented here as a pair of 2 vectors. The first one is an "Adjacency vector" without weights. But weights are set in the second one.
// So an edge that is set by the pair of vertices indexed as 2*i, 2*i+1 in the first vector has its weight set as i-th element in the second one.



{
    D.clear();
    Prev.clear();
    if ((A.first).size()==0) return -1;
    if ((A.second).size()==0) return -1;
    if (  (A.first).size()!=((A.second).size())*2 ) return -1;

    if ((V<0)&&(V != INT_MIN)) return -1;



    int mn, mx;
   RangeVGraph (A.first, mx, mn, false);


    if (mn<0)  // // checking for input data correctness.
    {
        return -1;
    }


    if (mx>V) V = mx; // здесь будет максимальный номер вершины // the max number of assigned to vertices

    if ((b<0) || (b>V))  // // checking for input data correctness: number of the vertex b must be in range [0, V].
    {
        return -1;
    }

    D.resize(V+1, INFINITY); // По умолчанию расстояния равны + бесконечность // The default distance values is INFINITY for every vertex


    Prev.resize(V+1, -1); // по умолчанию "предка" нет. // The previous vertices are not set by default (i.e. =-1 for every vertex)



    std::vector <int> order; // здесь будет храниться топологическая сортировка вершин
    order.clear();

    std::vector <int> R; // An auxiliary vector for the function TSortHP as such parameter is required, the vector should stay empty
    R.clear();

    std::vector <int> I; //  An auxiliary vector for the function TSortHP as such parameter is required, the vector should stay empty
    I.clear();

    int t=TSortHP (A.first, R, order, I, false, true);



    if (t==-1)  // if there are no topological sorting (i.e. the graph contains cycle except any loops) this function can't work.
    {
        D.clear();
        Prev.clear();
        return -1;
    }


    if (mn!=0) order.insert(order.begin(), 0); // if vertices are numbrered starting not from 0 - let's add 0

    if (V>mx)   //adding to "order" vertices that have number more than maximal in A and <= V
        for (int ff = (mx+1); ff<=V; ff++)
             order.insert(order.begin(), ff);


    int bb;

    for (int i = 0; i< order.size(); i++)   // поиск нового номера вершины начала поиска
    {

        if (order[i]==b) {bb = i; break;}

    }


    D[order[bb]] = 0.0; //дистанция от первой вершины до себя = 0

    std::vector <std::vector <double>> B (V+1);

    MatrixSet(B, V+1, V+1, INFINITY);    // Создание заготовки матирицы B в виде 2-хмерного массива (из векторов)


    for (unsigned int x = 0; x<=((A.first).size()-(2)); x = x+2)
    {

            if ( ((A.first)[x]!=(A.first)[x+1]) && ( B[((A.first)[x])][((A.first)[x+1])] > (A.second)[x/2] ) ) B[(A.first)[x]][(A.first)[x+1]] = (A.second)[x/2];  // в матрицу смежности вставляем длину кратчайшего ребра
   }

    // Конец заполнения матрицы смежности



    for (int b = bb; b<V; b++)              // бежим по матрице смежности от искомой вершины к большим номерам и пересчитываем дистанцию
        for (int j = b+1; j<=V; j++)
        {


            if (D[order[b]]==INFINITY) continue; //We should recalculate distances only from vertices that are accessible from vertex b as initial one.

            if ( (B[order[b]][order[j]]!=INFINITY) && ((D[order[j]]==INFINITY) || (D[order[j]]>(D[order[b]]+(long double)(B[order[b]][order[j]]) ) ) ) )   {D[order[j]]=(D[order[b]]+ (long double)(B[order[b]][order[j]]) ); Prev[order[j]]= order[b];}

        }



    return 0;
}


std::string GenerateAlphabet (const std::vector <std::string> &DataS)
// Generates an alphabet upon the given vector of strings DataS. Symbols will be ordered under ASCII.
// Формирует алфавит из символов, входящих в набор строк DataS. Порядок символов в алфавите задается ASCII.

{
    if (DataS.size()==0) return "";
    std::string TempS="";

    std::set <char> T;
    T.clear();
    for (int q = 0; q< DataS.size();q++)
        for (int w = 0; w< DataS[q].length();w++)
            T.insert(DataS[q][w]);

    for (auto it=T.begin(); it!=T.end(); it++)
        TempS.push_back(*it);

    return TempS;
}

std::string GenerateAlphabet (const std::string &DataS)
// Generates an alphabet upon the given string DataS. Symbols will be ordered under ASCII.
// Формирует алфавит из символов, входящих в строку DataS. Порядок символов в алфавите задается ASCII.

{
    if (DataS.length()==0) return "";
    std::string TempS="";

    std::set <char> T;
    T.clear();

        for (int w = 0; w< DataS.length();w++)
            T.insert(DataS[w]);

    for (auto it=T.begin(); it!=T.end(); it++)
        TempS.push_back(*it);

    return TempS;
}



int MedianString (const int WordLenght, const std::vector <std::string> & DataS, std::vector <std::string> & MedianS, std::string Alph = "ACGT")

// Finds all median strings (having length = WordLenght) upon given array of strings in the vector DataS and given Alphabet set by the string Alph.
// Returns distance between found median string(s) annd the pattern (i.e. DataS), all found median strings will contained in the vector MedianS.
// If any data incorrect returns empty MedianS and -1.


// Находит все "медианные" строки заданной длины WordLenght исходя из набора исходных строк в вексторе DataS.
// Возвращает значение дистанции от найденных медианных строк и набора исходных строк DataS. Сами медианные строки будут в MedianS.
// Если данные некорректны, возвращает пустой MedianS и -1.


{

        MedianS.clear();
        if (WordLenght<1) return -1;
        if (DataS.size()==0) return -1;
        if (Alph.length()<2) return -1;


        for (int q = 0; q< DataS.size();q++)
        {

            if (WordLenght>DataS[q].length()) return -1;



            for (int y=0; y<DataS[q].length(); y++)
                if (Alph.find(DataS[q][y])==-1) return -1;

        }

        std::set <char> T; // проверка что нет дублирующихся символов в алфавите
        T.clear(); // Testing if there are any identical symbols in the Alphabet
        for  (int y=0; y<Alph.length(); y++)
        {
            T.insert(Alph[y]);
            if ((T.size()-1)!=y)
                return -1;

        }
        T.clear();



        int AlphLenght = Alph.length();


        std::string out ="";

       std::string out_terminate ="";

        std::vector <int> l (WordLenght);
        for (int g=0; g<WordLenght; g++)
        {l [g] = 0;


        out.push_back(Alph [0]);
        out_terminate.push_back(Alph [Alph.size()-1]);

        }


    int t = 0;
    std::string ts = "";

    int d = 0;
    int dr = INT_MAX;



    while (true)
    {
        d = 0;

        ts=out;

    for (int q = 0; q< DataS.size();q++)
    {
        t = INT_MAX;

        for (int w = 0; w< DataS[q].length()-WordLenght+1;w++)
        {
            if (HmDist(ts, DataS[q].substr(w, WordLenght))<t)
                  t = HmDist(ts, DataS[q].substr(w, WordLenght));

        }
        d = d+t;

    }



    if (d==dr)
    {
        MedianS.push_back(ts);
    }


    if (d<dr)
    {
        dr = d;
        MedianS.clear();
        MedianS.push_back(ts);
    }


    if (out==out_terminate) break;

    l [WordLenght-1]++;  //увеличение на 1 кода последней буквы

    if (l [WordLenght-1] == AlphLenght)
     {
       int r = WordLenght-1;

       while (r>0)
         {l [r] = 0;
          r--;
          l [r] ++;
          if (l[r] < AlphLenght) break;
         }
     }


    for (int t = 0; t<WordLenght; t++)
          out [t] = Alph [(l[t])];

    }



        return dr;
}



#endif
