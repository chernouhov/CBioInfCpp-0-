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

# Функции CBioInfCpp.h и их предназначение

CBioInfCpp.h содержит ряд функций, которые могут быть полезны как при решении 
различных задач в области биоинформатики, так и других задач, связанных с работой 
со строками и графами. 

Все функции объявлены и полностью определены в файле CBioInfCpp.h. При этом в 
данном файле также объявляется включение библиотек iostream, fstream, string, 
vector, set, algorithm, queue, map, cmath, stack, limits.h, float.h, необходимых 
для корректной работы всех функций.  Да, наверное, такой подход и не является 
каноническим, но он позволяет быстро начать работу (достаточно лишь включить 
CBioInfCpp.h в свою программу с помощью include). 

При работе с графами применена структура данных «вектор смежности» - см. раздел 
“Функции работы с графами / Working with graphs”. 

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
`int MatrixCout (std::vector <std::vector <int>> & B, char g = ' ')`

Вывод матрицы (int) на экран через пробелы. Возвращает -1, если матрица не 
содержит строк/ столбцов.

Если строки матрицы разной длины, то "остатки" 
длины до максимальной при выводе заполняются символом **g**.
***
`int MatrixCout (std::vector <std::vector <long long int>> & B, char g = ' ')`

Вывод матрицы (long long int) на экран через пробелы. Возвращает -1, если 
матрица не содержит строк/ столбцов.

Если строки матрицы разной длины, то "остатки" длины до максимальной при 
выводе заполняются символом **g**.  
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
`int MatrixFout (std::vector < std::vector <int>> & B, std::ofstream & fout, char g
= ' ')`

Вывод матрицы (int) в файл через пробелы. Возвращает -1, если матрица 
не содержит строк/ столбцов.

Если строки матрицы разной длины, то "остатки" длины до максимальной 
при выводе заполняются символом **g**.
***
`int MatrixFout (std::vector < std::vector <long long int>> & B, std::ofstream &
fout, char g = ' ')`

Вывод матрицы (long long int) в файл через пробелы. Возвращает -1, если 
матрица не содержит строк/ столбцов.

Если строки матрицы разной длины, то "остатки" длины до максимальной 
при выводе заполняются символом **g**.
***
`int VectorCout (const std::vector <int> &P)`

Вывод вектора (int) на экран через пробелы
***
`int VectorFout (const std::vector <int> &P, std::ofstream &fout)`

Вывод вектора (int) в файл через пробелы. Возвращает -1, если вектор - пустой.
***
`int VectorCout (const std::vector <long long int> &P)`

Вывод вектора (long long int) на экран через пробелы.
***
`int VectorFout (const std::vector <long long int> &P, std::ofstream &fout)`

Вывод вектора (long long int) в файл через пробелы. Возвращает -1, если вектор - пустой.
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
`int PairVectorCout (const std::pair < std::vector<int>, std::vector<double>> & P,
unsigned int prec = 4)`

Модификация функции VectorCout (см. выше).
***
`int PairVectorFout (const std::pair < std::vector<int>, std::vector<double>> & P,
std::ofstream &fout, unsigned int prec = 4)`

Модификация функции VectorFout (см. выше).

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

Generates RNA from DNA without checking of data correctness
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
`double PDist (const std::string& s1, const std::string& s2)`

Counts p-distance without checking of the input data correctness
***
`int GDistanceMatrix (std::vector <std::string> &s, std::vector <std::vector
<double>> & B)`

Генерирует матрицу расстояний "B" по набору исходных строк s; 
в случае если в наборе менее 2х строк или они имеют неодинаковую длину 
- возвращается -1 (в случае успеха - 0).
***
`int EditDist (const std::string &s1, const std::string &s2)`

Рассчитывает редакционное расстояние (расстояние Левенштейна) 
между строками, принимает на вход даже пустые. Цена каждой операции = 1.
***
`void EDistForFindMR (const std::string &s1, const std::string &s2, const int D,
const int L, int l, int b, std::set <std::pair <int, int>> &Result)`

Вспомогательная функция для FindMutatedRepeatsED (см. ниже, приводится следующей). 
***
`int FindMutatedRepeatsED (std::string &StrShort, std::string &StrLong, int D,
std::set <std::pair <int, int>> &Result)`

Функция находит все подстроки для строки StrLong, редакционное расстояние 
которых до StrShort не превышает D. При этом принимается, что "штраф" за 
пропуск и несовпадение символов  = 1. 

Результат возвращается в set <std::pair <int, int>> Result, где первое число 
в паре - номер позиции начала подстроки в StrLong (счет позиций идет с 0), 
а второе - длина подстроки (пары не отсортированы). 

Если исходные данные некорректны - возвращается -1 и пустой Result;, 
в случае успеха возвращается 0. 
Идея реализованного алгоритма: 
1. Найти все начала таких подстрок в StrLong. 
Для этого обе строки реверсируются, затем StrShort "выравнивается" на 
StrLong по обычным правилам для нахождения редакционного расстояния, но с тем отличием, 
что суммарный начальный пропуск по StrLong не "штрафуется" (начать можно с любой 
позиции в длинной строке без "штрафа"). Найденные начальные позиции нумеруются с 1. 
Затем строки реверсируются обратно. 
2. Для каждой позиции вычисляется максимально возможная длина искомой подстроки, 
которая не может быть более длины StrShort плюс D, и при этом не может выходить
 за границу StrLong.  
Пояснение. Длины искомых подстрок не могут отличаться от длины StrShort более 
чем на D в ту и другую сторону, т.к. редакционное расстояние не превышает D, 
а цена пропуска = 1. 
3. Если такая максимально возможная длина есть и составляет не менее длины 
StrShort минус D, то для соотвествующей подстроки (обозначим как TempS) и 
StrShort осуществляем стандартный Edit Distance Alignment с помощью вспомогательной 
функции EDistForFindMR. 

И в выстраиваемой для этих целей матрице будут значения Edit Distance не 
только между StrShort и TempS, но и (!) укороченным с конца подстрокам TempS 
(для этого берем значения в матрице не только по последней строке (TempS 
"откладывается" вниз), но и по предшествующим. 

Если для каждого такого префикса строки TempS (при условии, что его длина
удовлетворяет пояснению к шагу (2)) значение Edit Distance не превышает 
D - фиксируем в set Result его начальную позицию (в нумерации от 0) и длину. 
 
Функция возвращает 0 и заполненный Result в случае успеха и -1 и пустой Result 
в случае некорректности исходных данных (любая из строк пуста или StrShort 
длиннее StrLong или длина StrShort не превосходит D).
***
`bool CompStrDLO (const std::string & s1, const std::string & s2)`

Компаратор для сортировки строк по убыванию длин.
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
`void Num (std::string & Numbers, std::vector <int> & A)`

Перегон строки с числами int в массив (вектор) А
***
`int Num (std::string & Numbers, int &a1,int &a2, double &a3)`

Перегон строки, содержащей 3 числа, разделенных пробелами (пары целых и одного double) 
соответственно в int a1,int a2, double a3. Числа должны быть разделены пробелами, 
а более ничего строка содержать не должна. 

Возвращает -1 если выявлена ошибка исходных данных (нет 3х "кандидатов в числа"). 

При этом проверка на то, что конвертируемая в число подстрока содержит лишь цифры 
и десятичный разделитель, в данной версии функции НЕ проводится.

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
`int FindIn (std::vector <int> &D, int a, unsigned int step = 1, unsigned int start
= 0)`

Возвращает индекс первого найденного элемента (int), совпадающего с искомым (a), 
поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента 
- возвращаем -1.
***
`int FindIn (std::vector <long long int> &D, long long int a, unsigned int step =
1, unsigned int start = 0)`

Возвращает индекс первого найденного элемента (long long int), совпадающего с искомым (a), 
поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента 
- возвращаем -1. 
***
`int FindIn (std::vector <double> &D, double a, unsigned int step = 1, unsigned int
start = 0)`

Возвращает индекс первого найденного элемента (double), совпадающего с искомым (a), 
поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - 
возвращаем -1. 

Да, прямое сравнение чисел double не совсем корректно и это нужно принимать во 
внимание, но в ряде случаев функция может быть полезна.  
 
Для сравнения с заданной точностью см. вариант функции ниже. 
***
`int FindIn (std::vector <double> &D, double a, double d, unsigned int step = 1,
unsigned int start = 0)`

Возвращает индекс первого найденного элемента (double), совпадающего с искомым (a) 
с точностью до d, поиск ведется с позиции start, шаг поиска = step, если не нашли 
такого элемента - возвращает -1.
***
`int FindIn (std::vector <long double> &D, long double a, unsigned int step = 1,
unsigned int start = 0)`

Возвращает индекс первого найденного элемента (long double), совпадающего с искомым (a), 
поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - 
возвращает -1. 

Да, прямое сравнение чисел long double не совсем корректно и это нужно принимать
во внимание, но в ряде случаев функция может быть полезна. 
Для сравнения с заданной точностью см. вариант функции ниже.
***
`int FindIn (std::vector <long double> &D, long double a, long double d, unsigned
int step = 1, unsigned int start = 0)`

Возвращает индекс первого найденного элемента (long double), совпадающего с искомым (a) 
с точностью до d, поиск ведется с позиции start, шаг поиска = step, если не 
нашли такого элемента - возвращаем -1. 
***
`int FindIn (std::vector <string> &D, std::string a, unsigned int step = 1,
unsigned int start = 0)`

Возвращает индекс первого найденного элемента (string), совпадающего с искомым (a), 
поиск ведется с позиции start, шаг поиска = step, если не нашли такого элемента - возвращаем -1. 
***
`int SwapInVector (std::vector <int> & A1, unsigned int f, unsigned int l)`

Замена элементов в векторе (int), возвращает -1 если хоть один из запрашиваемых 
индексов выходит за размер вектора либо если вектор пустой.
***
`int SwapInVector (std::vector <long long int> & A1, unsigned int f, unsigned int
l)`

Замена элементов в векторе (long long int), возвращает -1 если хоть один из 
запрашиваемых индексов выходит за размер вектора либо если вектор пустой. 
***
`int SwapInVector (std::vector <double> & A1, unsigned int f, unsigned int l)`

Замена элементов в векторе (double), возвращает -1 если хоть один из запрашиваемых 
индексов выходит за размер вектора либо если вектор пустой.
***
`int SwapInVector (std::vector <long double> & A1, unsigned int f, unsigned int l)`

Замена элементов в векторе (long double), возвращает -1 если хоть один из 
запрашиваемых индексов выходит за размер вектора либо если вектор пустой.
***
`int SwapInVector (std::vector < std::string> & A1, unsigned int f, unsigned int l)`

Замена элементов в векторе (string), возвращает -1 если хоть один из запрашиваемых 
индексов выходит за размер вектора либо если вектор пустой.
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