[English](README.MD) | Русский

[Сведения о документе](#сведения-о-документе)  
[Функции CBioInfCpp.h и их предназначение](#функции-cbioinfcpph-и-их-предназначение)  
[Функции ввода-вывода](#функции-ввода-вывода)  
[Функции работы со строками](#функции-работы-со-строками)  
[Функции работы с графами](#функции-работы-с-графами)  
[Вспомогательные функции](#вспомогательные-функции)  

# Сведения о документе

Настоящий документ содержит общее описание CBioInfCpp.h и содержащихся в нем функций. 

Документы CBioInfCpp.h, About_CBioInfCpp.rtf, About_CBioInfCpp.pdf (все указанные 
файлы размещены в настоящем каталоге) составляют собой одно произведение, которое 
распространяется на условиях лицензии Creative Commons Attribution 4.0 International 
Public License (сокращенно - CC BY, гиперссылка на текст лицензии: 
https://creativecommons.org/licenses/by/4.0/legalcode.ru). 

Автор CBioInfCpp.h, About_CBioInfCpp.rtf, About_CBioInfCpp.pdf – Черноухов Сергей 
(chernouhov@rambler.ru) 

***
**Апробирование**

2021: 

Функция SubGraphsInscribed применена после переработки в проекте https://graphonline.ru/ (https://github.com/UnickSoft/GraphOffline, https://github.com/UnickSoft/graphonline) для проверки изоморфности графов и поиска подграфа по образцу.
***

# Функции CBioInfCpp.h и их предназначение

CBioInfCpp.h содержит ряд функций, которые могут быть полезны как при решении 
различных задач в области биоинформатики, так и других задач, связанных с работой 
со строками и графами. 

Все функции объявлены и полностью определены в файле CBioInfCpp.h. При этом в 
данном файле также объявляется включение библиотек iostream, fstream, string, vector, set, algorithm, queue, map, cmath, stack, limits.h, cstdlib, ctime, float.h, unordered_map, unordered_set, utility, functional, необходимых 
для корректной работы всех функций.  Да, наверное, такой подход и не является 
каноническим, но он позволяет быстро начать работу (достаточно лишь включить 
CBioInfCpp.h в свою программу с помощью include). 

При работе с графами применены структуры данных «Вектор смежности» и «Ассоциативный массив смежности» - см. раздел “Функции работы с графами / Working with graphs”.

PS Настоящая версия CBioInfCpp.h содержит не так много функций. Однако автор 
будет рад, если эта она получит дальнейшее развитие.  

# Функции ввода-вывода

`int FastaRead (std::ifstream & fin, std::vector < std::string> & IndexS,
std::vector < std::string> & DataS)`

Чтение строк FASTA из файла. Возвращает 0, если кол-во индексов строк равно 
кол-ву самих строк, самая первая строка является индексом (не начинается с ">")
 и в процессе считывания не встретились 2 индекса подряд. Иначе вернет -1.    
**IndexS**:  Сюда будут записываться индексы (обозначения) строк  
**DataS**: Сюда будут записываться сами строки
***
`void StringsRead (std::ifstream & fin, std::vector <std::string> & DataS)`

Читает все строки из файла в вектор **DataS**.
***
`int MatrixCout (std::vector <std::vector <double>> & B, unsigned int prec = 4,
char g = ' ', bool scientifique = false)`

Вывод матрицы (double) на экран через пробелы. Возвращает -1, если матрица 
не содержит строк/ столбцов.
 
Если строки матрицы разной длины, то "остатки" длины до максимальной при 
выводе заполняются символом **g**.

Вывод чисел проводится с заданной точностью prec, если **bool scientifique == false**.
 
Если **bool scientifique == true**, вывод производится в экспоненциальной форме.
***
`int MatrixCout (std::vector <std::vector <long double>> & B, unsigned int prec =
4, char g = ' ', bool scientifique = false)`

Вывод матрицы (long double) на экран через пробелы. Возвращает -1, если матрица 
не содержит строк/ столбцов.

Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе 
заполняются символом **g**.

Вывод чисел проводится с заданной точностью prec, если **bool scientifique == false**. 

Если **bool scientifique == true**, вывод производится в экспоненциальной форме. 
***
`int MatrixFout (std::vector <std::vector <double>> & B, std::ofstream & fout,
unsigned int prec = 4, char g = ' ', bool scientifique = false)`

Вывод матрицы (double) в файл через пробелы. Возвращает -1, если матрица не содержит строк/ 
столбцов.

Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе
заполняются символом **g**.

Вывод чисел проводится с заданной точностью prec, если **bool scientifique == false**. 

Если **bool scientifique == true**, вывод производится в экспоненциальной форме. 
***
`int MatrixFout (std::vector <std::vector <long double>> & B, std::ofstream & fout,
unsigned int prec = 4, char g = ' ', bool scientifique = false)`

Вывод матрицы (long double) в файл через пробелы. Возвращает -1, если матрица 
не содержит строк/ столбцов.

Если строки матрицы разной длины, то "остатки" длины до максимальной при 
выводе заполняются символом **g**.

Вывод чисел проводится с заданной точностью prec, если **bool scientifique == false**. 

Если **bool scientifique == true**, вывод производится в экспоненциальной форме.  
***
`template < typename TMC>`

`int MatrixCout (std::vector <std::vector <TMC>> & B, char g = ' ')`
 
Обобщение функции: ввод матрицы (элементов стандартных типов TMC) на экран через пробелы. Возвращает -1, если матрица не содержит строк/ столбцов

Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
***
`template < typename TMF>`

`int MatrixFout (std::vector <std::vector <TMF>> & B, std::ofstream & fout, char g = ' ')`

Обобщение функции: ввод матрицы (элементов стандартных типов TMF) в файл через пробелы. Возвращает -1, если матрица не содержит строк/ столбцов

Если строки матрицы разной длины, то "остатки" длины до максимальной при выводе заполняются символом g
***
`int VectorCout (const std::vector <double> &P, unsigned int prec = 4, bool
scientifique = false)`

Вывод вектора (double) на экран через пробелы. Возвращает -1, если вектор - пустой.

Вывод чисел проводится с заданной точностью prec, если **bool scientifique == false**. 

Если **bool scientifique == true**, вывод производится в экспоненциальной форме. 

***
`int VectorFout (const std::vector <double> &P, std::ofstream &fout, unsigned int
prec = 4, bool scientifique = false)`

Вывод вектора (double) в файл через пробелы. Возвращает -1, если вектор - пустой.

Вывод чисел проводится с заданной точностью prec, если **bool scientifique == false**. 

Если **bool scientifique == true**, вывод производится в экспоненциальной форме. 
***
`int VectorCout (const std::vector <long double> &P, unsigned int prec = 4, bool
scientifique = false)`

Вывод вектора (long double) на экран через пробелы. Возвращает -1, если вектор - пустой.

Вывод чисел проводится с заданной точностью prec, если **bool scientifique == false**. 

Если **bool scientifique == true**, вывод производится в экспоненциальной форме. 
***
`int VectorFout (const std::vector <long double> &P, std::ofstream &fout, unsigned
int prec = 4, bool scientifique = false)`

Вывод вектора (long double) в файл через пробелы. Возвращает -1, если вектор - пустой.

Вывод чисел проводится с заданной точностью prec, если **bool scientifique == false**. 

Если **bool scientifique == true**, вывод производится в экспоненциальной форме. 

***
`int VectorCout (const std::vector <std::string> &P)`

Вывод вектора (string) через Enter на экран. Возвращает -1, если вектор - пустой.
***
`int VectorFout (const std::vector <std::string> &P, std::ofstream &fout)`

Вывод вектора (string) через Enter в файл. Возвращает -1, если вектор - пустой.
***
`template < typename TVC>`

`int VectorCout (const TVC &P)`

Обобщение функции: вывод вектора/ списка/ и др. итерируемых контейнеров, содержащих элементы стандартных типов, на экран через пробелы
***
`template < typename TVF>`

`int VectorFout (const TVF &P, std::ofstream &fout)`

Обобщение функции: вывод вектора/ списка/ и др. итерируемых контейнеров, содержащих элементы стандартных типов, в файл через пробелы
***
`int PairVectorCout (const std::pair < std::vector<int>, std::vector<double>> & P, 
unsigned int prec = 4, bool scientifique = false)`

Модификация функции VectorCout (см. выше) для случая нецелочисленных длин ребер в графе.
***
`int PairVectorFout (const std::pair < std::vector<int>, std::vector<double>> & P, 
std::ofstream &fout, unsigned int prec = 4, bool scientifique = false)`

Модификация функции VectorFout (см. выше) для случая нецелочисленных длин ребер в графе.
***
`int GraphCout (const std::vector <int> &P, const bool weighted)`

Вывод графа, заданного вектором смежности, на экран: каждое ребро выводится в новой строке. 
Граф - невзвешенный либо веса его ребер целочисленны.
***
`int GraphFout (const std::vector <int> &P, const bool weighted, std::ofstream &fout)`

Вывод графа, заданного вектором смежности, в файл: каждое ребро выводится в новой строке. 
Граф - невзвешенный либо веса его ребер целочисленны.
***
`int GraphCout (const std::pair < std::vector<int>, std::vector<double>> & P, unsigned int prec = 4, bool scientifique = false)`

Модификация функции GraphCout (см. выше) для взвешенных графов с нецелочисленными весами ребер.
***
`int GraphFout (const std::pair < std::vector<int>, std::vector<double>> & P, std::ofstream &fout, 
unsigned int prec = 4, bool scientifique = false)`

Модификация функции GraphFout (см. выше) для взвешенных графов с нецелочисленными весами ребер.
***
`int GraphCout (const std::map <std::pair < int, int> , int> &P)`

Вывод графа, заданного ассоциативным массивом смежности, на экран: каждое ребро выводится в новой строке. 
Веса ребер целочисленны.
***
`int GraphFout (const std::map <std::pair < int, int> , int> &P, std::ofstream &fout)`

Вывод графа, заданного ассоциативным массивом смежности, в файл: каждое ребро выводится в новой строке. Веса ребер целочисленны.
***
`int GraphCout (const std::map <std::pair < int, int> , double> &P, unsigned int prec = 4, bool scientifique = false)`

Модификация функции GraphCout для заданного ассоциативным массивом смежности графа (см. выше) 
для случая нецелочисленных весов ребер.
***
`int GraphFout (const std::map <std::pair < int, int> , double> &P, std::ofstream &fout, unsigned int prec = 4, bool scientifique = false)`

Модификация функции GraphFout для заданного ассоциативным массивом смежности графа (см. выше) 
для случая нецелочисленных весов ребер.
***
`int GraphCout (const std::map <std::pair < int, int> , std::vector<int> > &P, bool in_line=false)`

Вывод графа, заданного "мега-мапом", на экран. Веса ребер целочисленны.

Мега-мап представляет собой ассоциативный массив смежности, предназначенный для хранения графов с множественными петлями и множественными ребрами.

При этом ключом является пара чисел, задающих вершины ребер графа между ними, а значением - вектор весов для всех ребер между этими вершинами.

Параметр in_line задает, выводить ли все значения вектора-значения в 1 строку после ключа, или же каждое значение вектора выводится после ключа в новой строке.
***
`int GraphFout (const std::map <std::pair < int, int> , std::vector<int> > &P, std::ofstream &fout, bool in_line=false)`

Вывод графа, заданного "мега-мапом", в файл. Веса ребер целочисленны.

Мега-мап представляет собой ассоциативный массив смежности, предназначенный для хранения графов с множественными петлями и множественными ребрами.

При этом ключом является пара чисел, задающих вершины ребер графа между ними, а значением - вектор весов для всех ребер между этими вершинами.

Параметр in_line задает, выводить ли все значения вектора-значения в 1 строку после ключа, или же каждое значение вектора выводится после ключа в новой строке.
***
`int GraphCout (const std::map <std::pair < int, int> , std::vector<double> > &P, bool in_line=false, unsigned int prec = 4, bool scientifique = false)`

Модификация функции GraphCout для заданного "мега-мапом" (см. выше) для случая нецелочисленных весов ребер.
***
`int GraphFout (const std::map <std::pair < int, int> , std::vector <double> > &P, std::ofstream &fout, bool in_line=false, unsigned int prec = 4, bool scientifique = false)`

Модификация функции GraphFout для заданного "мега-мапом" (см. выше) для случая нецелочисленных весов ребер.
***
`int CoutSuffixTree (const std::vector <int> & Tree, const std::string DataS, bool tree=true, bool strings = true)`

Выводит на экран суффиксное дерево, заданное вектором числе в порядке, указанном в описании функции SuffixTreeMake. Сама строка задается DataS. Проверка корректности исходных данных не проводится.

Если "tree" = true, выводит по каждому ребру квартет чисел, его задающих (каждый квартет - вновой строке).
Если "strings" = true, выводит по каждому ребру соотвествующую ему подстроку из строки DataS.
***
`int FoutSuffixTree (const std::vector <int> & Tree, const std::string DataS, std::ofstream &fout, bool tree=true, bool strings = true)`

Выводит в файл суффиксное дерево, заданное вектором числе в порядке, указанном в описании функции SuffixTreeMake. Сама строка задается DataS. Проверка корректности исходных данных не проводится.

Если "tree" = true, выводит по каждому ребру квартет чисел, его задающих (каждый квартет - вновой строке).
Если "strings" = true, выводит по каждому ребру соотвествующую ему подстроку из строки Data.
***

# Функции работы со строками 
`int HmDist (const std::string &s1, const std::string &s2)`

Считает Hamming Distance, возвращает -1 если строки разной длины либо хоть одна пустая.
***
`int RComplDNA (const std::string& s, std::string & sr)`

Generates reverse complement of string s as string sr, returns -1 and empty
string sr if string s is empty or it is not DNA
***
`int RComplRNA (const std::string& s, std::string & sr)`

Generates reverse complement of string s as string sr, returns -1 and empty string
sr if string s is empty or it is not RNA
***
`std::string rp (const std::string& s)`

Generates reverse complement of DNA without any checking of input data
correctness
***
`std::string rpr (const std::string& s)`

Generates reverse complement of RNA without any checking of input data
correctness
***
`double gcDRNA (const std::string &s)`

Counts DNA/RNA GC-content; in case any symbol not DNA/RNA-nucleotide or string
s is empty returns -1.0.
***
`int RNAfromDNA (const std::string &s, std::string & sr)`

Generates RNA from DNA, returns -1 and empty string sr if the input string s is
empty or it is not DNA
***
`int DNAfromRNA (const std::string &s, std::string & sr)`

Generates DNA from RNA, returns -1 and empty string sr if the input string s is
empty or it is not RNA
***
`std::string RNAg (const std::string &s)`

Generates RNA from DNA without any checking of input data correctness
***
`std::string DNAg (const std::string &s)`

Generates DNA from RNA without checking of data correctness
***
`std::string StrToCircular (const std::string& s, int tail = INT_MAX)`

Находит и возвращает кратчайшую "круговую" ("скрученную в кольцо") строку для заданной 
(т.е. с максимальным "нахлестом" конца строки на начало).
Для строк длиной менее 3 символов возвращает ее же (считается, что в этом случае "нахлест" невозможен.
Возможно задать параметр tail - величину максимального "нахлеста". Значения tail<=0 в расчет не принимаются.
***
`int TandemRepeatsFinding (const std::string &s, std::vector <int> &Result, int MaxWordLength = 4, int limit = 5)`

Функция находит все тандемные повторы в строке s, сформированные j-мерами длиной от 1 до MaxWordLength символов включительно 
и имеющие длину не менее limit.
MaxWordLength должно быть в границах от 2 по 6. 
limit должен быть больше MaxWordLength (иначе limit будет присвоено значение MaxWordLength+1).
Результат возвращается в векторе Result, где на четных позициях, отсчитываемых с нуля - позиции начала тандемного повтора
в s (символы в s также нумеруются с нуля), а на нечетных - длина повтора
Возвращает 0 в случае успеха. В случае некорректных данных (длина s < MaxWordLength, MaxWordLength не в диапазоне [2; 6]) возвращает пустой Result и -1.
***
`void GMapCodonRNA (std::map < std::string, std::string> & MapCodon)`

Generates codon table for RNA in the map **MapCodon** ("$" means stop codon).
MapCodon format: Codon -> Amino acid.
***
`void GMapCodonRNA_A (std::map <std::string, std::vector<std::string>> & MapCodon)`

Generates codon table for RNA in the map **MapCodon** ("$" means stop codon).
MapCodon format: Amino acid -> vector of relevant codons.
***
`void GMapMonoisotopicMassTableLD (std::map <char, long double> & MassTable)`

Generates Monoisotopic mass table in the map (long double)
***
`int GPFM (std::vector <std::string> &s, std::vector <std::vector <int>> & B, const
std::string &Alph)`

Генерирует позиционную матрицу частот B по набору исходных строк s и алфавиту 
Alph (содержит последовательность символов алфавита);

Последовательность строк в матрице B соответствует последовательности символов 
в строке Alph (т.е. последовательности символов алфавита). 
 
В случае если в наборе менее 2х строк или они имеют неодинаковую длину или 
в алфавите менее 2 букв или хоть одна из строк содержит хоть один символ не 
из алфавита,

или же если алфавит содержит дублирующиеся символы - возвращается -1 
и пустая матрица B (в случае успеха возвращается 0). 
***
`int GPPM (const std::vector <std::string> &s, std::vector <std::vector <long double>> & B, const std::string &Alph, long double z = 0.0, long double d = 2.0)`

Генерирует позиционную матрицу вероятностей B по набору исходных строк s и алфавиту Alph (содержит последовательность символов алфавита);

Последовательность строк в матрице B соответствует последовательности символов в строке Alph (т.е. последовательности символов алфавита).

В случае если в набор пустой или же строки в нем имеют неодинаковую длину или в алфавите менее 2 букв или хоть одна из строк содержит хоть один символ не из алфавита, или же если алфавит содержит дублирующиеся символы - возвращается -1  и пустая матрица B (в случае успеха возвращается 0 и заполненная B).

z и d - параметры для сглаживания (pseudocount): используется формула (Ns+z)/(N+d*z).
***
`double PDist (const std::string& s1, const std::string& s2)`

Counts p-distance without checking of the input data correctness
***
`int GDistanceMatrix (std::vector <std::string> &s, std::vector <std::vector
<double>> & B)`

Генерирует матрицу расстояний "B" по набору исходных строк s; 
в случае если в наборе менее 2х строк или они имеют неодинаковую длину, то возвращается -1 (в случае успеха - 0).
***
`int ConsStringQ1 (std::vector <std::string> &DataS, std::vector<std::string> &QDataS, std::string &TempS, 
std::string &QTempS, const int method = 1, const std::string &Alph = "ACGT", const int Phred=33)`

Формирует консенсусную строку (если возможно несколько вариантов такой строки - то один из них) согласно набру строк DataS с соотвествующим качеством (строки, задающие качество даны в QDataS на соответствующих позициях).

Результат - консенсусная строка TempS и соотвествующая ей строка качества QTempS. В случае успеха возвращается 0, в случае некорректных вводных данных - -1 и пустые указанные строки.

Параметр "Alph" задает алфавит: только эти символы учитываются при формировании консенсуса.

Параметр "Phred" задает шкалу качества (по умолчанию - Phred33).

Предусмотрены 4 метода формирования консенсусной строки:
0 - по умолчанию - символы на каждой данной позиции выбираются согласно максимальной средней вероятности (качеству), качество присваивается то же.
1 - символы на каждой данной позиции выбираются согласно максимальной суммарной вероятности (качеству), качество присваивается как среднее по данному символу.
2 - то же, но качество присваивается как максимальное по данному символу на данной позиции.
4 - выбор символа (и присвоение ему качества) осуществляется исходя из максимального качества (вероятности) символа на данной позиции.

Если передать пустой QDataS, то предполагается, что качество везде "какое-то одинаковое", строка QTempS возвращается пустой. 
Т.обр., для определения консенсусной строки согласно лишь частоте появления символов достаточно выбрать метод = 1 или 2 и пустой QTempS.

Если ни одного символа из алфавита на данной позиции не найдено - ставится ' ' и качество по данной позиции задается как ' '.
***
`int ConsStringQ2 (std::vector <std::string> &DataS, std::vector<std::string> &QDataS, std::string &TempS, 
std::string &QTempS, const int method = 1, const std::string &Alph = "ACGT", const char tr = '^', const int Phred=33)`

Модификация функции ConsStringQ1 (см. выше) для целей учета всех вариантов консенсусной строки.
В консенсусной строке позиции разделяются символом tr (по умолчанию = '^'), 
при этом на каждой позиции может быть несколько символов из алфавита, если с т.зр. критерия выбора они равновероятны.
***
`int EditDist (const std::string &s1, const std::string &s2)`

Рассчитывает редакционное расстояние (расстояние Левенштейна) 
между строками, принимает на вход даже пустые. Цена каждой операции = 1.
***
`int JoinOverlapStrings (std::multimap <long long int, std::string> & Locuses, std::map <long long int, std::string> & JoinedLocuses, const bool Aggregate = false, const bool NoQuality = false, const int method = 0, const std::string &Alph = "ACGT", const int Phred=33)`

Функция, которая принимает на вход Locuses, содержащий набор подстрок из некоторой неизвестной строки, в формате: стартовая позиция в неизвестной строке -> сама (под)строка, и объединяет пересекающиеся строки (результат записывается в JoinedLocuses в том же формате).

Области пересечений строятся как консенсусные строки:
 - с помощью функции ConsStringQ1, если необходим какой-либо один из приемлемых вариантов (bool Aggregate = false), или с помощью ConsStringQ2, если необходимы все варианты (bool Aggregate = true) (подробнее см описания данных функций),
 - с выбранным методом построения консенсусной строки (0 - 3, подробнее о методах также  см. описания ConsStringQ1 и ConsStringQ2),
 - - с учетом качества (NoQuality=false) или нет (NoQuality=true); при учете качества считается, что первая половина каждой строки в Locuses содержит собственно саму строку, а вторая половина - строку, задающую ее качество.
 - Параметр качества задается по шкале Phred с помощью соответствующего параметра.
 - Алфавит задается параметром Alph, так что при формировании консенсусных строк будут учитываться только символы из данного алфавита.

Таким образом, если необходимо просто соединить все пересекающиеся строки в некотором наборе без учета качества, необходимо задать NoQuality = true, задать алфавит и в Locuses разместить саму коллекцию объединяемых строк.

В случае NoQuality = true будет всегда использоваться метод №1

Например, коллекция вида  0->ACGT, 1->TGTA, 1->TT, 10->TT, 11->TCA в этом случае объединится как 0->ATGTA, 10->TTC.
***
`long double ProfileProbableMer (const std::string &s, int n, const std::vector <std::vector <long double>> & B, std::vector <std::string> & DataS, long double d = 0.0000001, std::string Alph = "ACGT")`

Находит все наиболее вероятные n-меры в строке s исходя из позиционной матрицы вероятностей B и возвращает их в векторе DataS. Возвращает значение соответствующей вероятности.

Если данные некорректны, возвращает пустой DataS и -1.0

Параметр d задает точность при расчете вероятностей.
***
`int MedianString (const int WordLenght, const std::vector <std::string> & DataS, std::vector <std::string> & MedianS, std::string Alph = "ACGT")`

Находит все "медианные" строки заданной длины WordLenght исходя из набора исходных строк в вексторе DataS.

Возвращает значение дистанции от найденных медианных строк и набора исходных строк DataS. Сами медианные строки будут в MedianS.

Если данные некорректны, возвращает пустой MedianS и -1.
***
`int EditDist (const std::string &s1, const std::string &s2)`

Рассчитывает редакционное расстояние (расстояние Левенштейна) 
между строками, принимает на вход даже пустые. Цена каждой операции = 1.
***
`int EditDistA (const std::string &s1, const std::string &s2, std::string &sr1, std::string &sr2)`

Расширенная версия функции EditDist (см. выше). 
Возвращает также Edit Distance Alignment строк s1 и s2 как строки sr1 и sr2 
(если несколько вариантов возможны - один из возможных).
***
`void EDistForFindMR (const std::string &s1, const std::string &s2, const int D,
const int L, int l, int b, std::set <std::pair <int, int>> &Result)`

Вспомогательная функция для FindMutatedRepeatsED (см. ниже, приводится следующей). 
***
`int FindMutatedRepeatsED (const std::string &strShort, const std::string &strLong, int D,
std::set <std::pair <int, int>> &Result)`

Функция находит все подстроки для строки strLong, редакционное расстояние 
которых до strShort не превышает D. При этом принимается, что "штраф" за 
пропуск и несовпадение символов  = 1. 

Результат возвращается в set <std::pair <int, int>> Result, где первое число 
в паре - номер позиции начала подстроки в StrLong (счет позиций идет с 0), 
а второе - длина подстроки (пары не отсортированы). 

Если исходные данные некорректны - возвращается -1 и пустой Result;, 
в случае успеха возвращается 0. 
Идея реализованного алгоритма: 
1. Найти все начала таких подстрок в strLong. 
Для этого обе строки реверсируются, затем StrShort "выравнивается" на 
strLong по обычным правилам для нахождения редакционного расстояния, но с тем отличием, 
что суммарный начальный пропуск по strLong не "штрафуется" (начать можно с любой 
позиции в длинной строке без "штрафа"). Найденные начальные позиции нумеруются с 1. 
Затем строки реверсируются обратно. 
2. Для каждой позиции вычисляется максимально возможная длина искомой подстроки, 
которая не может быть более длины StrShort плюс D, и при этом не может выходить
 за границу strLong.  
Пояснение. Длины искомых подстрок не могут отличаться от длины strShort более 
чем на D в ту и другую сторону, т.к. редакционное расстояние не превышает D, 
а цена пропуска = 1. 
3. Если такая максимально возможная длина есть и составляет не менее длины 
strShort минус D, то для соотвествующей подстроки (обозначим как TempS) и 
strShort осуществляем стандартный Edit Distance Alignment с помощью вспомогательной 
функции EDistForFindMR. 

И в выстраиваемой для этих целей матрице будут значения Edit Distance не 
только между strShort и TempS, но и (!) укороченным с конца подстрокам TempS 
(для этого берем значения в матрице не только по последней строке (TempS 
"откладывается" вниз), но и по предшествующим. 

Если для каждого такого префикса строки TempS (при условии, что его длина
удовлетворяет пояснению к шагу (2)) значение Edit Distance не превышает 
D - фиксируем в set Result его начальную позицию (в нумерации от 0) и длину. 
 
Функция возвращает 0 и заполненный Result в случае успеха и -1 и пустой Result 
в случае некорректности исходных данных (любая из строк пуста или strShort 
длиннее StrLong или длина strShort не превосходит D).
***
`bool CompStrDLO (const std::string & s1, const std::string & s2)`

Компаратор для сортировки строк по убыванию длин.
***
`int SuffixTreeMake (const std::string &DataS, std::vector <int> & Tree, int b=1)`

Построение суффиксного дерева Tree по строке DataS. Возвращает -1, если длина строки <1, в случае успеха вернет 0.

Суффиксное дерево возвращается в виде вектора Tree, представленного в виде квартетов чисел:
номер вершины-начала ребра, номер вершины-конец ребра, стартовая позиция подстроки в строке DataS, ее (подстроки) длина.

Параметр b задает, с какого номера будут нумероваться вершины в суффиксном дереве.

***
`std::string ShortSuperstringGr (std::vector <std::string> DataS)`

Применен "жадный алгоритм" поиска наименьшей надстроки. При этом из рассмотрения 
исключаются строки, являющиеся подстроками других строк DataS. 

Исходные данные DataS копируются, а не привязываются по ссылке, т.к. DataS 
будет изменяться в процессе работы функции.

Возвращается пустая строка, если DataS - пустой или содержит только пустые строки.
***
`int TrieMake (std::vector <std::string> &DataS, std::vector <int> & Trie)`

Построение префиксного дерева Trie по массиву строк DataS 

Trie: Здесь будет само дерево в виде набора триплетов чисел. Первые два задают 
ребро графа, а третье - соответствующий символ (букву). Вершины графа нумеруются с 1.
***
`void Num (std::string & Numbers, std::vector <double> & A)`

Перегон строки с числами <double> в массив (вектор) А
***
`void Num (std::string & Numbers, std::vector <long double> & A)`

Перегон строки с числами <long double> в массив (вектор) А
***
`void Num (std::string & Numbers, std::vector <int> & A)`

Перегон строки с числами int в массив (вектор) А
***
`void Num (std::string & Numbers, std::vector <long long int> & A)`

Перегон строки с числами long long int в массив (вектор) А
***
`int Num (std::string & Numbers, int &a1,int &a2, double &a3)`

Перегон строки, содержащей 3 числа, разделенных пробелами (пары целых и одного double) 
соответственно в int a1,int a2, double a3. Числа должны быть разделены пробелами, 
а более ничего строка содержать не должна. 

Возвращает -1 если выявлена ошибка исходных данных (нет 3х "кандидатов в числа"). 

При этом проверка на то, что конвертируемая в число подстрока содержит лишь цифры 
и десятичный разделитель, в данной версии функции НЕ проводится.
***
`void Num (std::string & Numbers, std::vector <std::string> & A)`

Модификация функций семейства Num (см. выше) для строк: 
перегон строки со строками, разделенными пробелами, в массив (вектор) строк А.
***

# Функции работы с графами

При работе с графами здесь используется такая структура данных как «Вектор смежности». 

### Невзвешенный граф 

Назовем вектором смежности для взвешенного графа упорядоченный набор (массив) четного кол-ва 
чисел (а[2i], a[2i+1],..., где i нумеруется c 0), где каждая пара чисел а[2i], a[2i+1] 
задает ребро графа между вершинами а[2i] и a[2i+1] ("список ребер в строку"). Данный 
формат не содержит информации, является ли граф ориентированным или нет (возможны оба
варианта). При использовании формата для орграфа считается, что ребро направлено из 
а[2i] в a[2i+1]. 

### Взвешенный граф: целочисленные веса ребер 
Назовем вектором смежности для взвешенного графа упорядоченный набор (массив) чисел 
(а[3i], a[3i+1], a[3i+2],..., где i нумеруется c 0), где каждая тройка чисел а[3i], 
a[3i+1] задает ребро графа между вершинами а[3i] и a[3i+1], а a[3i+2] есть вес этого
 ребра, ("список ребер в строку"). Данный формат не содержит информации, является 
 граф ориентированным или нет возможны оба варианта). При использовании формата 
 для орграфа считается, что ребро направлено из а[3i] в a[3i+1]. 

### Взвешенный граф: нецелочисленные веса ребер (double) 
Ввиду того, что в одном массиве (векторе) нельзя хранить разнородные элементы,
предложена следующая реализация. Граф хранится в паре векторов (std::pair < std::vector<int>, 
std::vector<double>>) где первый вектор является вектором смежности графа без указания
весов, а второй вектор содержит соответствующие веса. Таким образом, для ребра, 
задаваемого парой вершин под индексами 2\*i, 2\*i+1 первого вектора, вес будет равен 
элементу под индексом i второго вектора. 

Структура данных «Вектор смежности» достаточно компактна, занимает меньше памяти,
чем матрица смежности (для разреженных графов), относительно просто реализуется  
и может быть удобна для решения ряда задач. 

При этом: 
- Вершины графа могут быть промаркированы и отрицательными числами.  
При этом в ряде функций происходит приведение номеров вершин к неотрицательным либо 
положительным при реализации функции (ответ же выдается в исходных, неприведенных 
номерах вершин). 
- Графы могут содержать множественные ребра и множественные петли. 

Дополнение. Для обеспечения более быстрого доступа к значению веса ребра в графе, с лета 2019 года в CBioInfCpp также используется модификация Вектора смежности – **Ассоциативный массив смежности**, реализованный на базе контейнера Map. При этом ключом является пара целых чисел int, задающих номера вершин, а значением – вес ребра между ними: int либо double. 
При использовании «классического» **Ассоциативного массива смежности** минусом является невозможность хранения множественных ребер. Для решения этой задачи может использоваться **«расширенный ассоциативный массив смежности»** (т. наз. **«мега-мап»**: здесь ключом также является пара чисел, задающих номера соединяемых ребром(-ами) вершин, а значением - вектор весов для всех ребер между этими вершинами – int или double).


***  
`int UWGraphRead (std::ifstream & fin, std::vector <int> & A)`

Чтение невзвешенного графа в вектор смежности A. 
Назовем вектором смежности для взвешенного графа упорядоченный набор (массив) 
четного кол-ва чисел (а[2i], a[2i+1],... / i нумеруется c 0 /),  
где каждая пара чисел а[2i], a[2i+1] задает ребро графа между вершинами 
а[2i] и a[2i+1] ("список ребер в строку"). 

Данный формат не содержит информации, является ли граф ориентированным 
или нет (возможны оба варианта). При использовании формата для орграфа 
считается, что ребро направлено из а[2i] в a[2i+1]. 

Предполагается считывание из файла, содержащего список ребер (каждое ребро 
- отдельная строка).

Возвращает -1 и пустой вектор A, если полученный вектор смежности пустой 
или же при считывании очередного ребра считано не 2 элемента (числа). 
***
`int WGraphRead (std::ifstream & fin, std::vector <int> & A)`

Чтение взвешенного графа в вектор смежности. Назовем вектором смежности 
для взвешенного графа упорядоченный набор (массив) чисел (а[3i], a[3i+1], 
a[3i+2],... / i нумеруется c 0 /), где каждая тройка чисел а[3i], a[3i+1] 
задает ребро графа между вершинами а[3i] и a[3i+1], а a[3i+2] есть вес
этого ребра, ("список ребер в строку"). 

Рассматриваемый формат не содержит информации, является граф ориентированным 
или нет (возможны оба варианта). При использовании формата для орграфа 
считается, что ребро направлено из а[3i] в a[3i+1]. 

Данная структура данных занимает меньше памяти, чем матрица смежности,
и может быть удобна для решения ряда задач. 
 
Предполагается считывание из файла, содержащего список смежности (каждое 
ребро - отдельная строка).

Возвращает -1, если полученный вектор смежности пустой или же при считывании 
очередного ребра считано не 3 элемента (числа).
***
`int WGraphRead (std::ifstream & fin, std::pair < std::vector<int>,
std::vector<double>> & A)`

Модификация функции WGraphRead (см. выше) для случая нецелочисленных весов 
ребер (double). 

Чтение проводится в пару векторов std::pair < std::vector<int>, 
std::vector<double>> & A, где первый вектор является вектором смежности 
считываемого графа без указания весов,  
а второй вектор содержит соотвествующие веса. Соотвественно для ребра 
задаваемого парой вершин под индексами 2\*i, 2\*i+1 первого вектора вес будет 
равен элементу под индексом i второго вектора. 
***
`int RangeVGraph (std::vector <int> & A, int & mx, int & mn, const bool weighted,
bool IgnoreWeighted = false)`

Finds max (i.e. mx) and min (i.e. mn) value of numbers that assigned to vertices

Graph must be set as "Adjacency vector", bool "weighted" sets if the graph is
weighted or no.

If (IgnoreWeighted = true) the function looks at every element in A without any
dataset checking
***
`int RenumVGraph (std::vector <int> & A, const int d, const bool weighted, bool
IgnoreWeighted = false)`

Перенумеровывавает вершины графа: прибавляет величину d (может быть положительной и отрицательной).
***
`int AdjVector2AdjMatrix (std::vector <int> & A, std::vector <std::vector <int>>
&B, const bool weighted, const bool directed)`

Converts "Adjacency vector" A to "Adjacency matrix" B. 

bool "weighted" sets if the graph is weighted or no. 
bool "directed" sets if the graph is directed or no.

In case of multiple edges for a weighted graph only the last edge will be
written to Adjacency matrix, others will be lost.

Loops for undirected unweighted graph counts as 2 edges

In this function zero-value of any item of Adjacency matrix means no edge both
for unweighted and weighted graph

Returns 0 if success. Returns -1 and empty B if no.
***
`int AdjVector2AdjMatrix (std::pair < std::vector<int>, std::vector<double>> & A,
std::vector <std::vector <double>> &B, const bool directed)`

Modification of the function AdjVector2AdjMatrx (see it above) for not-integer
(double) weights of edges of a graph.

Graph is represented here as a pair of 2 vectors. The first one is an
"Adjacency vector" without weights. But weights are set in the second one.

So an edge that is set by the pair of vertices indexed as 2\*i, 2\*i+1 in the
first vector has its weight set as i-th element in the second one.

Note that undirected graph may have only zeros lower than the Main diagonal of
its Adjacency matrix here
***
`int AdjMatrix2AdjVector (std::vector <int> & A, std::vector <std::vector <int>>
&B, const bool weighted, const bool directed)`

Converts "Adjacency matrix" B to "Adjacency vector" A.

bool "weighted" sets if the graph is weighted or no. bool "directed" sets if
the graph is directed or no.

For a weighted graph here are no multiple edges.

Loops for an undirected unweighted graph counts as 2 edges (so if the Main
diagonal of the matrix B contain any odd number for such graph the function will
return -1)

For an undirected graph the data that is lower than the Main diagonal of the
matrix B is ignored

In this function zero-value of any item of Adjacency matrix means "no such
edge" both for unweighted and weighted graph

Returns 0 if success. Returns -1 and empty A if no.
***
`int AdjMatrix2AdjVector (std::pair < std::vector<int>, std::vector<double>> & A,
const std::vector <std::vector <double>> &B, const bool directed)`

Modification of the function AdjMatrix2AdjVector (see it above) for not-integer
(double) weights of edges of a graph.

Graph is represented here as a pair of 2 vectors. The first one is an
"Adjacency vector" without weights. But weights are set in the second one.

So an edge that is set by the pair of vertices indexed as 2\*i, 2\*i+1 in the
first vector has its weight set as i-th element in the second one.

For an undirected graph the data that is lower than the Main diagonal of the
matrix B is ignored
***
`int AdjVectorToAdjMap (const std::vector <int> &A, std::map <std::pair < int, int> , int> &G2, const bool weighted, const bool directed = true)`

Конвертирует Вектор смежности A в ассоциативный массив смежности G2. Множественные ребра будут объединены с суммарным весом. 
Для невзвешенного графа считаем вес всех ребер = 1.
Возвращает -1 в случае некорректности исходных данных.
Параметр weighted задает, является ли граф взвешенным (Истина) или нет.
Параметр directed задает, является ли граф ориентированным (Истина) или нет. Для неориентированных графов номера вершин каждого ребра будут записаны в G2 порядке возрастания.
***
`int AdjVectorToAdjMap (const std::pair < std::vector<int>, std::vector<double>> & A, std::map <std::pair < int, int> , double> &G2, const bool directed = true)`

Конвертирует Вектор смежности A в ассоциативный массив смежности G2. Множественные ребра будут объединены с суммарным весом.
Параметр directed задает, является ли граф ориентированным (Истина) или нет. Для неориентированных графов номера вершин каждого ребра будут записаны в G2 порядке возрастания.
Возвращает -1 в случае некорректности исходных данных.
***
`int AdjMapToAdjVector (std::vector <int> &A, const std::map <std::pair < int, int> , int> &G1)`

Конвертирует Ассоциативный массив смежности G1 в вектор смежности А (только во взвешенный, веса целочисленны).
Возвращает -1 в случае некорректности исходных данных.
***
`int AdjMapToAdjVector (std::pair < std::vector<int>, std::vector<double>> & A, const std::map <std::pair < int, int> , double> &G1)`

Конвертирует Ассоциативный массив смежности G1 в вектор смежности А (только во взвешенный, веса имеют тип double).
Возвращает -1 в случае некорректности исходных данных.
***
`int AdjVectorToAdjMegaMap (const std::vector <int> &A, std::map <std::pair < int, int> , std::vector<int> > &G2, const bool weighted, const bool directed = true)`

Конвертирует Вектор смежности A в ассоциативный "мега-мап" G2. Для невзвешенного графа считаем вес всех ребер = 1.

Мега-мап представляет собой ассоциативный массив смежности, предназначенный для хранения графов с множественными петлями и множественными ребрами.

При этом ключом является пара чисел, задающих вершины ребер графа между ними, а значением - вектор весов для всех ребер между этими вершинами.

Возвращает -1 в случае некорректности исходных данных.

Параметр weighted задает, является ли граф взвешенным (Истина) или нет.

Параметр directed задает, является ли граф ориентированным (Истина) или нет. Для неориентированных графов номера вершин каждого ребра будут записаны в G2 порядке возрастания.
***
`int AdjVectorToAdjMegaMap (const std::pair < std::vector<int>, std::vector<double>> & A, std::map <std::pair < int, int> , std::vector<double> > &G2, const bool directed = true)`

Модификация функции AdjVectorToAdjMegaMap (см. выше) для случая нецелочисленных весов ребер графа.
***
`int AdjMegaMapToAdjVector (std::vector <int> &A, const std::map <std::pair < int, int> , std::vector <int> > &G1)`

Конвертирует "мега-мап" G1 в вектор смежности А (только во взвешенный, веса целочисленны).

Мега-мап представляет собой ассоциативный массив смежности, предназначенный для хранения графов с множественными петлями и множественными ребрами.

При этом ключом является пара чисел, задающих вершины ребер графа между ними, а значением - вектор весов для всех ребер между этими вершинами.

Возвращает -1 в случае некорректности исходных данных.
***
`int AdjMegaMapToAdjVector (std::pair < std::vector<int>, std::vector<double>> & A, const std::map <std::pair < int, int> , std::vector<double> > &G1)`

Модификация функции AdjMegaMapToAdjVector (см. выше) для случая нецелочисленных весов ребер графа.
***
`int CheckUnvisit (vector <int> & Visited)`

Вспомогательная функция для поиска первой непомеченной вершины в графе.
***
`void EcycleDGraph (int t, std::vector <int> & R, const int V, std::vector
<std::vector<int>> &B)`

Вспомогательная функция для поиска Эйлерова цикла в ОРИЕНТИРОВАННОМ графе, 
где он заведомо существует, нет изолированных вершин и нумерация вершин идет с 1. 

B - матрица смежности, содержащая кол-во ребер между вершинами,
 V - максимальный номер вершины.
***
`int EPathDGraph (std::vector <int> & A, std::vector <int> & R, const bool
weighted, std::vector <int> & Isolated)`

Поиск Эйлерова пути либо Эйлерова цикла в ОРИЕНТИРОВАННОМ графе. Принимает на 
вход вектор смежности графа с указанием, взвешенный ли граф, а также заготовку 
R для найденного пути (цикла) и Isolated для изолированных вершин. 

При этом не считается изолированной вершина, имеющая лишь петли. 

Возвращает заполненные R и Isolated (если есть путь либо цикл, при 
этом возвращаемые значения соответственно 2 и 1) и пустые вектора и -1, 
если их не найдено. 

Эйлеров путь/ цикл ищется на всем графе, либо на единственной компоненте 
связности, при условии что прочие вершины - изолированные. 

Может работать с ориентированными графами с дублирующими ребрами и с 
множественными петлями. Нумерация вершин может осуществляться любыми 
целыми числами, в т.ч. отрицательными. При этом считается, что граф 
содержит все вершины, соответствующие всем числам от min (1, минимальный 
заданный номер вершины) по максимальный заданный номер вершины включительно. 

В процессе работы граф приводится к виду, чтобы вершины нумеровались начиная 
с 1. По окончанию работы исходная нумерация восстанавливается. 
***
`int EPathDGraph (std::pair < std::vector<int>, std::vector<double>> & A,
std::vector <int> & R, std::vector <int> & Isolated)`

Модификация функции EPathDGraph (см. выше) для случая нецелочисленных 
весов ребер (double).
***
`int DistanceBFA (std::vector <long long int> &A, std::vector <int> & D, const int
b, std::vector <int> & Prev, const bool weighted, int V = INT_MIN)`

Рассчитывает расстояния от заданной вершины b до всех прочих в орграфе 
(используется метод поиска в ширину). 

Возвращается 1 в случае успеха (вектор D содержит кратчайшие расстояния 
от вершины b до вершины i, а вектор Prev - индекс вершин-предков в таком
пути). 

По умолчанию вектор D содержит значения LLONG_MAX, а вектор Prev - "-1". 

Если в ходе работы обнаружен цикл негативного веса, то функция возвращает -1
и пустые вектора D и Prev. 
 
На входе д.б. граф, заданный вектором смежности A (считается, что вершины
нумеруются с 0), номер исходной вершины b и флаг, является ли граф взвешенным 
(const bool weighted). Для невзвешенных считается, что каждое ребро имеет вес = 1. 

Также на вход подается номер наибольшей вершины V (если не передан, 
рассчитывается самостоятельно как номер наибольшей вершины в ребрах).

Функция работает со взвешенными и с невзвешенными графами, причем они могут 
содержать петли и множественные ребра. Ребра могут иметь как неотрицательный 
(в т.ч. и нулевой), так и отрицательный вес. 
***
`int DistanceBFA (std::pair < std::vector<int>, std::vector<double>> & A,
std::vector <long double> & D, const int b, std::vector <int> & Prev, int V =
INT_MIN)`

Модификация функции DistanceBFA (см. выше) для случая нецелочисленных весов ребер (double).
***
`int DistanceBFA (std::vector <int> &A, std::vector <long long int> & D, const int b, const bool weighted, int V = INT_MIN)`


Модификация функции DistanceBFA (см. выше): нет поиска массива предков и вместо поиска в ширину применен алгоритм Беллмана — Форда.

Рассчитывает расстояния от заданной вершины b до всех прочих в орграфе.

Возвращается 1 в случае успеха (вектор D содержит кратчайшие расстояния от вершины b до вершины i).

По умолчанию вектор D содержит значения LLONG_MAX, а вектор Prev - "-1".

Если в ходе работы обнаружен цикл негативного веса, то функция возвращает -1 и пустой вектор D.

На входе д.б. граф, заданный вектором смежности A (считается, что вершины нумеруются с 0), номер исходной вершины b и флаг, является ли граф взвешенным (const bool weighted). Для невзвешенных считается, что каждое ребро имеет вес = 1.

Также на вход подается номер наибольшей вершины V (если не передан, рассчитывается самостоятельно как номер наибольшей вершины в ребрах)

Функция работает со взвешенными и с невзвешенными графами, причем они могут содержать петли и множественные ребра. Ребра могут иметь как неотрицательный (в т.ч. и нулевой), так и отрицательный вес.
***
`int DistanceBFA (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <long double> & D, const int b, int V = INT_MIN)`

Модификация функции DistanceBFA (вместо поиска в ширину применен алгоритм Беллмана — Форда для нецелочисленных весов ребер (double)), массив предков не строится. 
***
`int DFSTS (const std::vector <int> & A, const int b, std::vector <int> & Visited,
std::vector <int> & order, const bool weighted)`

Вспомогательная функция для функции TSortHP. Проверки исходных данных не проводится, 
вершины в ориентированном орграфе, заданном вектором смежности A, д.б. нумерованы с 1.

Граф может содержать петли (игнорируются). 

В процессе обхода раскрашиваем вершины в массиве Visited: 0 - непосещенная (белая), 
1 - посещена, но не отработана (серая), 2 - отработана (черная). 

weighted - истина, если взвешенный граф, иначе - ложь. 

Если найден цикл - возвращает 1 и пустой order. 
***
`int CycleToPath (std::vector <int> Cycle, std::vector<int> &Path)`

Функция "вставляет" цикл Cycle в путь Path с первого значения из Path, которое встречается в Cycle.
В случае успеха вернет 0. В случае неуспеха или некорректных исходных данных вернет -1.
***
`int TSortHP (std::vector <int> & A, std::vector <int> & R, std::vector <int> &
order, std::vector <int> & Isolated, const bool weighted, const bool OnlyTS =
false)`

Функция для топологической сортировки в орграфе. Также в случае наличия 
топологической сортировки (и при условии OnlyTS = false) ищет Гамильтонов путь 
и перечень изолированных вершин. При этом не считается изолированной вершина,
имеющая лишь петли. 
 
Функция НЕ является функцией поиска именно Гамильтонова пути, он ищется ТОЛЬКО 
в случае наличия топологической сортировки. 

Принимает на вход вектор смежности графа A с указанием, взвешенный ли граф 
(параметр weighted), а также заготовку R для Гамильтонова пути, order для 
топологической сортировки, Isolated для перечня изолированных вершин. 

Может работать с ориентированными графами с дублирующими ребрами и с 
множественными петлями (петли будут игнорироваться). 

Нумерация вершин может осуществляться любыми целыми числами, в т.ч. отрицательными. 
При этом считается, что граф содержит все вершины, соответствующие всем 
числам от min (1, минимальный заданный номер вершины) по максимальный заданный 
номер вершины включительно. 

В процессе работы граф приводится к виду, чтобы вершины нумеровались начиная 
с 1. По окончанию работы исходная нумерация восстанавливается. 

Если OnlyTS == false (нормальная работа функции):   
Возвращает 0, если найдены и топологическая сортировка, и Гамильтонов путь.   
Возвращает -1 и пустые R, order, Isolated, если в графе найден цикл.  
Возвращает 1 и пустой R, если есть топологическая сортировка, а Гамильтонова пути нет.  

Если параметр OnlyTS == true, то ищется только топологическая сортировка 
данный режим предусмотрен для ускорения работы). Возвращает 0, если она 
найдена и -1 если нет. Гамильтонов путь и изолированные вершины не возвращаются 
(R и Isolated будут пусты в любом случае). 
***
`int TSortHP (std::pair < std::vector<int>, std::vector<double>> & A, std::vector
<int> & R, std::vector <int> & order, std::vector <int> & Isolated, const bool
OnlyTS = false)`

Модификация функции TSortHP (см. выше) для случая нецелочисленных весов ребер (double). 
***
`int DFS_for_NBPaths (const std::vector <int> & A, const bool w, const int b, const int bconst, std::vector <int> & Visited, std::vector <int> & Path)`

Вспомогательная функция для NBPaths (см. ниже): обход в глубину графа для поиска изолированных циклов. 
***
`void Circuit_for_NBPaths (const std::vector <int> & A, const bool w, int V, std::vector <std::vector<int> >&Paths, 
std::vector <int> & Visited)`

Вспомогательная функция для NBPaths (см. ниже) для поиска изолированных циклов. 
***
`int NBPaths (std::vector <int> & A, bool w, std::vector <std::vector<int> >&Paths, bool directed = true)`

Функция для поиска всех максимально длинных неразветвляющихся путей в графе, заданном вектором смежности А. 

Параметр w задает, является ли граф взвешенным, или нет.

Параметр directed - является ли граф ориентированным.

Результат возвращается в std::vector <std::vector<int> > Paths.

Возвращает -1 и пустой Paths в случае некорректности исходных данных. В случае успеха вернет 0.

Может работать с графами, вершины которых заданы любыми целыми числами, в т.ч. - отрицательными.

Может работать с графами множественными ребрами и множественными петлями (каждое множественное ребро и каждая петля рассматриваются как отдельный путь).
***
`long long int MaxFlowGraph (std::vector <int> A, const bool weighted, int b, int e, std::vector <std::vector<int> >&Paths, std::vector <int> &Flows, std::vector < std::pair < int, int> > &MinCut)`

Функция для поиска максимального потока в графе из вершины b в вершину e; граф задается вектором смежности А;
Параметр weighted определяет, является ли граф взвешенным (если взвешенный - "Истина", при этом веса ребер здесь могут быть лишь
целыми положительными).

Может работать с множественными ребрами (рассматриваются как одно "объединенное" ребро с суммарным весом) и с множественными
петлями (петли игнорируются).
Вершины графа должны быть неотрицательны, веса ребер - только положительны

Возвращает: (1) величину максимального потока, (2) заполненный вектор путей Paths, слагающих максимальный поток 
(один из возможных вариантов построения Paths, если их может быть несколько),
(3) соответствующие этим путям значения потоков в векторе Flows, 
(4) перечень ребер минимального разреза графа в векторе MinCut (каждое ребро задано парой вершин).
В случае некорректных исходных данных или отсутствия пути из b в e или же отсутствия любой из этих вершин в графе возвращает -1 и пустые Paths, Flows, MinCut.
***
`long double MaxFlowGraph (std::pair < std::vector<int>, std::vector<double>> A, int b, int e, std::vector <std::vector<int> >&Paths, std::vector <double> &Flows, std::vector < std::pair < int, int> > &MinCut)`

Модификация функции MaxFlowGraph (см. выше) для случая нецелочисленных весов ребер (double). 
***
`int SubGraphsInscribed (std::vector <int> A, std::vector <int> B, std::unordered_set<std::vector <int>, VectorIntHash> & Result, bool directed = true, bool InscribedOnly = true, const bool PreThinning=true, const unsigned int HowManySubgraphs = 0)`

Функция изначально находила все "вписанные" подграфы графа A, изоморфные графу B.

«Вписанным» подграфом графа A здесь называется такой его подграф, который может быть «приклеен» к другим частям графа A только за счет ребер,
инцидентных лишь граничным вершинам его (подграфа) неразветвляющихся путей максимальной длины (при этом граф A может содержать и иные компоненты связности).

Т.е. для графа B = {0->2, 10->2, 2->3, 3->4, 4->5, 4->6} будет найден изоморфный ему подграф A1, "вписанный" в граф A = {0->2, 7->1, 1->2, 2->3, 3->4, 4->5, 4->6}, и этот подграф A1 = {0->2, 1->2, 2->3, 3->4, 4->5, 4->6},
однако если в граф A добавить ребро 3->8 (A = {3->8, 0->2, 7->1, 1->2, 2->3, 3->4, 4->5, 4->6}), то функция не найдет в A изоморфных B "вписанных" подграфов.

Графы A и B д.б. невзвешеными, задаются векторами смежности, могут быть ориентированными (bool directed = true) и нет.

С декабря 2020 функция позволяет находить все подграфы графа A, изоморфные графу B, а не только "вписанные".
Для этого нужно задать параметр InscribedOnly = 0. Если InscribedOnly == 1, то поиск идет быстрее, но только по "вписанным" подграфам.
Адаптация осуществлена дополнением возможности рассмотрения всех ребер рассматриваемых графов (до этого рассматривались только non-branching paths).

Функция может работать с графами, содержащими несколько несвязных компонет, а также с графами с множественными ребрами.
При работе с множественными ребрами из А выбираются те, что имеют кратность не менее, чем соотвествующие им в В

Параметр PreThinning определяет, нужно ли производить предварительное "прореживание". Вспомогательный параметр для оптимизации времени работы,
т.к. скорость прохождения различных этапов алгоритма, как и самого алгоритма, сильно зависит от исходных данных.
Параметр HowManySubgraphs задает верхний предел кол-ва подграфов, которое нужно найти. Если HowManySubgraphs == 0, то производится поиск всех возможных подграфов.
***
int SubGraphsInscribed (std::vector <int> A, std::vector <int> B, std::set<std::vector <int>> & Result, bool directed = true, bool InscribedOnly = true, const bool PreThinning=true, const unsigned int HowManySubgraphs = 0)`

Версия функции SubGraphsInscribed: результаты будут в set Result. Работает несколько дольше. 
***
`template < typename Tf>`

`int SubGraphsInscribedM (std::vector <int> A, std::vector <int> B, std::set<std::vector <int>> & Result, bool directed = true, bool InscribedOnly = true, const bool PreThinning=true, const unsigned int HowManySubgraphs = 0, std::map<int, Tf> Af={}, std::map<int, Tf> Bf={})`

Экспериментальная версия функции SubGraphsInscribed: Вершины графов A и B могут иметь метки (заданы в std::map<int, Tf> Af для A и в std::map<int, Tf> Bf для B).

Вершины будут считаться изоморфными если они либо (1) обе не имеют меток, либо (2) обе имеют метки, причем равные.

Случай наличия в Af либо Bf ключа, не совпадвющего с номером какой-либо вершины в А или В рассматривается как некорректные исходные данные (возвращает -1).
***
`int DistanceTS (std::vector <int> &A, std::vector <long long int> & D, const int
b, std::vector <int> & Prev, const bool weighted, int V = INT_MIN)`

Рассчитывает расстояния от заданной вершины b до всех прочих в орграфе. 
Метод работает быстрее, чем DistanceBFA за счет предварительной топологической 
сортировки орграфа. 

Однако метод неприменим для орграфов, содержащих любой цикл кроме петель,  
в т.ч. - множественных (петли будут игнорироваться). 

Возвращается 1 в случае успеха (вектор D содержит кратчайшие расстояния 
от вершины b до вершины i, а вектор Prev - индекс вершин-предков в таком пути).

По умолчанию вектор D содержит значения LLONG_MAX, а вектор Prev - "-1". 

Если был обнаружен цикл - возвращается -1 и пустые вектора D и Prev. 

На входе д.б. граф, заданный вектором смежности A (считается, что вершины 
нумеруются с 0), номер исходной вершины и флаг, является ли граф взвешенным. 

Для невзвешенных графов считается, что каждое ребро имеет вес = 1. 
Для взвешенных - длины ребер должны быть строго меньше INT_MAX. 

Также на вход подается номер наибольшей вершины V (если не передан, рассчитывается 
самостоятельно как номер наибольшей вершины в ребрах).

Функция работает со взвешенными и с невзвешенными графами, причем они могут 
содержать петли и множественные ребра. 

Ребра могут иметь как неотрицательный (в т.ч. и нулевой), так и отрицательный вес. 
***
`int DistanceTS (std::pair < std::vector<int>, std::vector<double>> & A,
std::vector <long double> & D, const int b, std::vector <int> & Prev, int V =
INT_MIN)`

Модификация функции DistanceTS (см. выше) для случая нецелочисленных весов ребер (double).
***
`int DistanceTS (std::vector <int> &A, std::vector <long long int> & D, const int b, const bool weighted, int V = INT_MIN)`

Модификация функции DistanceTS (см. выше) - не рассчитывается массив "предков"
***
`int DistanceTS (std::vector <int> &A, std::vector <int> & D, const int b, std::vector <int> & Prev, const bool weighted, int V = INT_MIN)`

Модификация функции DistanceTS (см. выше) - расстояния в int.
***
`int DistanceTS (std::vector <int> &A, std::vector <int> & D, const int b, const bool weighted, int V = INT_MIN)`

Модификация функции DistanceTS (см. выше) - расстояния в int и не рассчитывается массив "предков".
***
`int DistanceTS (std::pair < std::vector<int>, std::vector<double>> & A, std::vector <long double> & D, const int b, int V = INT_MIN)`

Модификация функции DistanceTS (см. выше) для случая нецелочисленных весов ребер (double) и без поиска массива "предков". 
***
`int MakeSubgraphSetOfVertices (const std::vector <int>&A, std::vector <int>&Subgraph, const std::set <int> &Vertices, const bool weighted)`

Функция для выделения подграфа Subgraph из графа A, такого что все вершины искомого подграфа задаются set <int> Vertices.
Граф A задается вектором смежности A, веса - целочисленны или граф невзвешенный. Параметр weighted задает, является ли граф взвешенным.
***
`int MakeSubgraphSetOfVertices (const std::vector <int>&A, std::vector <int>&Subgraph, const std::unordered_set <int> &Vertices, const bool weighted)`

Функция для выделения подграфа Subraph из графа A, такого что все вершины искомого подграфа задаются unordered_set <int> Vertices.
Граф A задается вектором смежности A, веса - целочисленны или граф невзвешенный. Параметр weighted задает, является ли граф взвешенным.
***
 `int MakeSubgraphSetOfVertices (const std::pair < std::vector<int>, std::vector<double>> & A, std::pair < std::vector<int>, std::vector<double>> &Subgraph, const std::set <int> &Vertices)`

Модификация функции MakeSubgraphSetOfVertices (см.выше) для случая нецелочисленных весов ребер.
***
 `int MakeSubgraphSetOfVertices (const std::pair < std::vector<int>, std::vector<double>> & A, std::pair < std::vector<int>, std::vector<double>> &Subgraph, const std::unordered_set <int> &Vertices)`

Модификация функции MakeSubgraphSetOfVertices(см. выше) для случая нецелочисленных весов ребер для unordered_set
***
`int AdjVectorEdgesMultiplicity (const std::vector <int> &A, std::map <std::pair < int, int> , int> &G2, const bool weighted, bool directed = true)`

Возвращает кратность ребер графа, заданного вектором смежности А, в ассоциативном массиве смежности G2.

Параметр weighted задает, является ли граф взвешенным (Истина) или нет.

Параметр directed задает, является ли граф ориентированным (Истина) или нет.

К примеру, для ориентированного графа "G2[std::pair <int, int>(1, 2)] = 3" означает, что направленное ребро 1->2 имеет кратность = 3.

Для неориентированного будут храниться одинаковые значения для пар вершин (vertex1, vertex 2) и (vertex2, vertex 1).

Т.е. для неориентированного графа будет верной подобная запись: G2[std::pair <int, int>(1, 2)] = G2[std::pair <int, int>(2, 1)] = 3

Возвращает -1 и пустой G2 в случае некорректности исходных данных. Если успех - вернет 0.
***
`int AdjVectorEdgesMultiplicity (const std::pair < std::vector<int>, std::vector<double>> & A, std::map <std::pair < int, int> , int> &G2, bool directed = true)`

Модификация AdjVectorEdgesMultiplicity (см. выше) для случая графа с нецелочисленными весами ребер.
***
`int DFSSCC1 (const std::vector <int> & A, const int b, std::vector <int> & Visited, std::vector <int> & order, const bool weighted)`

Вспомогательная функция для упорядочивания вершин орграфа для поиска сильносвязных его компонент
***
`int DFSSCC2 (const std::vector <int> & A, const int b, std::vector <int> & Visited, std::vector <int> & order,std::set <int> & R, const bool weighted)`

Вспомогательная функция для поиска вершин очередной сильно связной компоненты для SCCGraph_Vertices
***
`int NeighborJoiningUndirectedGraph (const std::vector <std::vector <int>> B, std::pair < std::vector<int>, std::vector<double>> &A)`

Конструирует дерево (неориентированный граф) методом присоединения ближайшего соседа на основе матрицы дистанций B, результат - дерево - возвращается в векторе смежности A. Нумерация вершин графа ведется с 1.

Возвращает 0 в случае успеха; в случае некорректных данных (пустая или не квадратная  или содержащая отрицательные элементы матрица B), вернет -1.
***
`int UPGMA_UndirectedGraph (const std::vector <std::vector <int>> B, std::pair < std::vector<int>, std::vector<double>> &A)`

Конструирует дерево (неориентированный граф) методом UPGMA на основе матрицы дистанций B, результат - дерево - возвращается в векторе смежности A. Нумерация вершин графа ведется с 1.

Возвращает 0 в случае успеха; в случае некорректных данных (пустая или не квадратная  или содержащая отрицательные элементы матрица B), вернет -1.
***
`int NeighborJoiningUndirectedGraph (const std::vector <std::vector <double>> B, std::pair < std::vector<int>, std::vector<double>> &A)`

Модификация функции для нецелочисленной матрицы дистанций B.
***
`int UPGMA_UndirectedGraph (const std::vector <std::vector <double>> B, std::pair < std::vector<int>, std::vector<double>> &A)`

Модификация функции для нецелочисленной матрицы дистанций B.
***
`void DFSAllPathsDGraph (std::vector <int>&A, std::vector <int> &Visited, const int &b, const int &e, const bool weighted, std::set <std::vector <int>> & GPath, std::vector <int> &Path)`

Вспомогательная функция для AllPathsDGraph (см. ниже)
***
`int AllPathsDGraph (std::vector <int>&A, const int &b, const int &e, const bool weighted, std::set <std::vector <int>> & GPath)`

Экспериментальная функция для поиска всех путей в ориентированном графе из вершины b в вершину e. Может работать неточно и долго.

Граф задается вектором смежности A. weighted задает, взвешенный ли он.

Возвращает 0 и найденные пути в GPath, в случае некорректных исходных данных вернет пустой GPath и -1.
***
`int DFS_for_Cycles (const std::vector <int> & A, const bool w, const int b, const int bconst, std::vector <int> & Visited, std::vector <int> & Path, std::set <std::vector <int>> &GPath, int &mn, const bool &directed)`

Вспомогательная функция для Cycles_in_Graph (см. ниже): обход в глубину графа.
***
`int Cycles_in_Graph (std::vector <int> & A, const bool w, std::set <std::vector<int> >&Paths, std::set <int> &StartV, const bool directed = true)`

Экспериментальная функция для поиска простых циклов в графе. Может работать неточно и долго.

Если множество StartV непустое, ищет циклы только через эти вершины.

Граф задается вектором смежности A. w задает, взвешенный ли он, а directed - ориентированный ли он.

Возвращает кол-во найденных циклов и сами найденные циклы в Paths, в случае некорректных исходных данных вернет пустой Paths и -1.
***
`int SCCGraph_Vertices (std::vector <int> & A, std::vector <std::set <int>> & G, const bool weighted, int mn = 0, int V = INT_MIN)`

Функция для нахождения наборов вершин по всем компонентам сильной связности (т.е. областей сильной связности) ориентированного графа, заданного вектором смежности А. Параметр weighted задает, является ли граф взвешенным.

Также на вход подается номер наибольшей вершины V (если не передан, рассчитывается самостоятельно как номер наибольшей вершины в ребрах) и номер минимальной вершины (по умолчанию = 0).

В случае успеха возвращает число сильно связанных компонент. Возвращает и заполненный вектор G, каждый элемент которого - набор вершин очередной компоненты связности.

В случае некорректных входных данных возвращает -1 и пустой G.
***
`int CCGraph_Vertices (std::vector <int> & A, std::vector <std::set <int>> & R, const bool weighted, int mn = 0, int V = INT_MIN)`

Функция для нахождения наборов вершин по всем компонентам связности (т.е. областей связности) неориентированного графа, заданного вектором смежности А. Параметр weighted задает, является ли граф взвешенным.

Также на вход подается номер наибольшей вершины V (если не передан, рассчитывается самостоятельно как номер наибольшей вершины в ребрах) и номер минимальной вершины (по умолчанию = 0).

В случае успеха возвращает число связанных компонент. Возвращает и заполненный вектор R, каждый элемент которого - набор вершин очередной компоненты связности.

В случае некорректных входных данных возвращает -1 и пустой R.


# Вспомогательные функции

`int MatrixSet (std::vector <std::vector <double>> & B, const int NLines, const int
NColumns, const double i)`

Создает матрицу NLines х NColumns и заполняет значением i (double). 
Возвращает -1 если число строк или столбцов неположительно.
***
`int MatrixSet (std::vector <std::vector <long double>> & B, const int NLines,
const int NColumns, const long double i)`

Создает матрицу NLines х NColumns и заполняет значением i (long double). 
Возвращает -1 если число строк или столбцов неположительно.
***
`int MatrixSet (std::vector <std::vector <int>> & B, const int NLines, const int
NColumns, const int i)`

Создает матрицу NLines х NColumns и заполняет значением i (int). 
Возвращает -1 если число строк или столбцов неположительно.
***
`int MatrixSet (std::vector <std::vector <long long int>> & B, const int NLines,
const int NColumns, const long long int i)`

Создает матрицу NLines х NColumns и заполняет значением i (long long int). 
Возвращает -1 если число строк или столбцов неположительно. 
***
`int FindIn (std::vector <int> &D, int a, int step = 1, int start
= 0)`

Возвращает индекс первого найденного элемента (int), совпадающего с искомым (a), 
поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента, то возвращаем -1.
Если переданное значение step <1, то step присваивается значение 1. 
Если переданное значение start <0, то start присваивается значение 0.
***
`int FindIn (std::vector <long long int> &D, long long int a, int step =
1, int start = 0)`

Возвращает индекс первого найденного элемента (long long int), совпадающего с искомым (a), 
поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента, то возвращаем -1. 
Если переданное значение step <1, то step присваивается значение 1. 
Если переданное значение start <0, то start присваивается значение 0.
***
`int FindIn (std::vector <double> &D, double a, int step = 1, int
start = 0)`

Возвращает индекс первого найденного элемента (double), совпадающего с искомым (a), 
поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - 
возвращаем -1. 
Если переданное значение step <1, то step присваивается значение 1. 
Если переданное значение start <0, то start присваивается значение 0.

Да, прямое сравнение чисел double не совсем корректно и это нужно принимать во 
внимание, но в ряде случаев функция может быть полезна.  
 
Для сравнения с заданной точностью см. вариант функции ниже. 
***
`int FindIn (std::vector <double> &D, double a, double d, int step = 1,
int start = 0)`

Возвращает индекс первого найденного элемента (double), совпадающего с искомым (a) 
с точностью до d, поиск ведется с позиции start, шаг поиска = step, если не нашли 
такого элемента - возвращает -1.
Если переданное значение step <1, то step присваивается значение 1. 
Если переданное значение start <0, то start присваивается значение 0.
***
`int FindIn (std::vector <long double> &D, long double a, int step = 1,
int start = 0)`

Возвращает индекс первого найденного элемента (long double), совпадающего с искомым (a), 
поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - 
возвращает -1. 
Если переданное значение step <1, то step присваивается значение 1. 
Если переданное значение start <0, то start присваивается значение 0.

Да, прямое сравнение чисел long double не совсем корректно и это нужно принимать
во внимание, но в ряде случаев функция может быть полезна. 
Для сравнения с заданной точностью см. вариант функции ниже.
***
`int FindIn (std::vector <long double> &D, long double a, long double d, 
int step = 1, int start = 0)`

Возвращает индекс первого найденного элемента (long double), совпадающего с искомым (a) 
с точностью до d, поиск ведется с позиции start, шаг поиска = step, если не 
нашли такого элемента - возвращаем -1. 
Если переданное значение step <1, то step присваивается значение 1. 
Если переданное значение start <0, то start присваивается значение 0.
***
`int FindIn (std::vector <string> &D, std::string a, int step = 1,
int start = 0)`

Возвращает индекс первого найденного элемента (string), совпадающего с искомым (a), 
поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - возвращаем -1. 
Если переданное значение step <1, то step присваивается значение 1. 
Если переданное значение start <0, то start присваивается значение 0.
***
`template < typename TSW>`

`int SwapInVector (std::vector <TSW> & A1, unsigned int f, unsigned int l)`

Замена элементов в векторе A1. Возвращает -1 если хоть один из запрашиваемых индексов 
выходит за размер вектора либо если вектор пустой.
***
`int GraphVerticesNumbersCompress (std::vector <int> & P, const bool weighted)`

Перенумеровывает вершина графа, заданного вектором смежности P, таким образом, чтобы все номера вершин составляли ряд неотрицательных целых чисел без пропусков. Параметр weighted задает, является ли граф взвешенным.
***
`std::string CIGAR1 (const std::string &S0, const std:: string & S2, int npos = 0)`

Формирует строку CIGAR по результату "прикладывания" строки S2 к строке S0 с позиции npos;
в случае некорректных данных (длина какой-либо строки равна 0, начальная позиция отрицательна 
или приложенная S2 "выезжает" за границу S0 - возвращает пустую строку.
***
`int ScoreStringMatrix (const std::vector <std::string> &s)`

Возвращает суммарное количество всех несовпадений символов по каждой позиции по набору строк s. 
Если данные некорректны вернет -1.
***
`int GenRandomUWGraph (std::vector <int> &P, int v, int e, int b=0)`

Вспомогательная функция для генерации случайного невзвешенного графа в виде вектора смежности P
***
`int PartitionOfNumber (std::vector <std::vector <int>> &B, int n)`

Генерирует разбиения числа на слагаемые для чисел больше 0 (иначе вернет -1). 
Результат генерируется в векторе векторов B. 
***
`int PartitionOfNumberL (std::vector < std::vector <int>> &B, int n, int l=-1)`

Генерирует разбиения числа на слагаемые для чисел больше 0 (иначе вернет -1). 
Результат генерируется в векторе векторов B. Расширенная версия: 

можно задать длину разбиения l. Если l>0, то возвращаются только разбиения длиной l. 
При этом более короткие разбиения "добиваются справа" нулями. 
***
`std::string GenerateAlphabet (const std::vector <std::string> &DataS)`

Формирует алфавит из символов, входящих в набор строк DataS. Порядок символов в алфавите задается ASCII. 
***
`std::string GenerateAlphabet (const std::string &DataS)`

Формирует алфавит из символов, входящих в строку DataS. Порядок символов в алфавите задается ASCII. 
***
`int PathFromPrev (std::vector <int> &Path, const std::vector <int> &Prev, const int b, const int e, const bool ignoreb = false)`

Вспомогательная функция. Конструирует путь Path в графе от вершины b до e согласно массиву предков Prev. Prev [i] содержит номер вершины-предка для вершины i, либо -1, если предка нет.

Путь собирается "от конца", т.е. от вершины е. Если bool ignoreb = false, то ищется путь строго от b до е. Иначе - началом пути также может быть некоторая вершина, не имеющая предка.

Если входные данные некорректны, вернет -1 и пустой Path. В случае успеха вернет 0.
***
`void UWGraphFromPrev (std::vector<int>&B, const std::vector<int>&Prev)`
Генерирует граф В в виде вектора смежности по массиву "предков" Prev.
В Prev на позиции i стоит номер вершины-предка для вершины i.
***
`int PrevFromGraph (const std::vector<int>&A, const bool w, std::vector<int>&Prev)`
Генерирует "массив предков" Prev по графу, заданному вектором смежности А. w задает, является ли он взвешенным.
Если данные некорректны, вернет -1 и пустой Prev.

В Prev на позиции i стоит номер вершины-предка для вершины i.

Прим. Проверки, имеется ли у каждой вершины только 1 "предок", не производится. Если несколько - в Prev будет только одна из них.
***
`int DegreesVerticesOfGraph (const std::vector<int>&A, const bool w, const bool directed, std::vector<int>&VinA, std::vector<int>&VoutA)`
Генерирует - по графу А (задан вектором смежности, w задает, является ли он взвешенным) - массивы степеней вершин:
по входящим VinA и исходящим VoutA из них ребрам.
Если данные некорректны, вернет -1 и пустые VinA и VoutA.
directed задает, является ли граф ориентированным.
По неориентированным графам степени считаются в VinA.
*** 
`int WGraphFromUWGraph (const std::vector <int> &P1, std::vector <int> &P2)`

Конструирует взвешенный граф Р2 из невзвешенного Р2 (считается, что вес любого ребра =1). Вектора заданы векторами смежности.
Если успех - возвращает 0, если исходные данные некорректны - вернет -1 и пустой Р2.
***
`int UWGraphFromWGraph (const std::vector <int> &P1, std::vector <int> &P2)`

Конструирует невзвешенный граф Р2 из взвешенного Р2 (копируются ребра без весов). Вектора заданы векторами смежности.
Если успех - возвращает 0, если исходные данные некорректны - вернет -1 и пустой Р2.
***
`template < typename TMEE>`

`int MatrixEraseElement (std::vector <std::vector <TMEE>> & B, const int &j)`

Удаление элемента j из матрицы B, матрица может содержать элементы произвольных типов.
Нумерация элементов - с нуля. если матрица пустая или элемент в ней не содержится (задан слишком большой его номер) - выдаст -1, если успех - 0.
Строки матрицы могут быть, в принципе, не равны друг другу по длине
***
