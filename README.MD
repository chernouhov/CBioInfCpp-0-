[About](#about)  
[Functions and their possible use](#functions-and-their-possible-use)  
[Input-Output functions](#input-output-functions)  
[Working with strings](#working-with-strings)  
[Working with graphs](#working-with-graphs)  
[Auxiliary functions](#auxiliary-functions)  

# About 

This document contains general data on CBioInfCpp.h library.

The documents About_CBioInfCpp.pdf, CBioInfCpp.h, About_CBioInfCpp.rtf (all of
them are placed in this directory) constitute a single Work (i.e. this Work is
divided into these 3 files), and this Work is distributed under Creative Commons
Attribution 4.0 International Public License (CC BY) (hyperlink to the License:
https://creativecommons.org/licenses/by/4.0/legalcode.ru).

CBioInfCpp.h, About_CBioInfCpp.rtf, About_CBioInfCpp.pdf are written by Sergey
Chernouhov (chernouhov@rambler.ru).

# Functions and their possible use

CBioInfCpp.h contains a number of functions that may be used as in bioinformatics
as well as in other fields related to working with graphs and strings.

All the function are defined in the only file CBioInfCpp.h. Also the libraries
iostream, fstream, string, vector, set, algorithm, queue, map, cmath, stack,
limits.h, float.h are included. Yes, this way may be considered as “not the only
best”, but it allows to start immediately by writing “include CBioInfCpp.h” at the
program beginning.
The data structure "Adjacency vector" to represent a graph is used in the
CBioInfCpp (see the section “Working with graphs”).

PS The current version of CBioInfCpp.h contains not so many functions. But it would be nice if this
library grows up.

# Input-Output functions

`int FastaRead (std::ifstream & fin, std::vector < std::string> & IndexS,
std::vector < std::string> & DataS)`

Reads FASTA dataset from file. Returns 0 if the number of indexes of strings =
number of strings, the first string in dataset is index (starts with ">") and in
dataset there is no 2 indexes one-by-one without a data string in between.
Otherwise returns -1.   
**IndexS**: Here indexes of strings will be contained   
**DataS**: Here data strings will be contained
***
`void StringsRead (std::ifstream & fin, std::vector <std::string> & DataS)`

Reads all strings from file to vector **DataS**
***
`int MatrixCout (std::vector <std::vector <int>> & B, char g = ' ')`

"Couts" Matrix (int) to screen. Returns -1 if the Matrix is empty.

The Matrix may have lines of different length. In this case the "missing"
values to the end for the "shorter lines" are filled with the char **g**.
***
`int MatrixCout (std::vector <std::vector <long long int>> & B, char g = ' ')`

"Couts" Matrix (long long int) to screen. Returns -1 if the Matrix is empty.

The Matrix may have lines of different length. In this case the "missing"
values to the end for the "shorter lines" are filled with the char **g**.
***
`int MatrixCout (std::vector <std::vector <double>> & B, unsigned int prec = 4,
char g = ' ', bool scientifique = false)`

"Couts" Matrix (double) to screen. Returns -1 if the Matrix is empty.

The Matrix may have lines of different length. In this case the "missing"
values to the end for the "shorter lines" are filled with the char **g**.

If **bool scientifique == false**, the precision will be set as prec; 

if **bool scientifique == true**, scientific notation will be applied.
***
`int MatrixCout (std::vector <std::vector <long double>> & B, unsigned int prec =
4, char g = ' ', bool scientifique = false)`

"Couts" Matrix (long double) to screen. Returns -1 if the Matrix is empty.

The Matrix may have lines of different length. In this case the "missing"
values to the end for the "shorter lines" are filled with the char **g**.

If **bool scientifique == false**, the precision will be set as prec; 

if **bool scientifique == true**, scientific notation will be applied.
***
`int MatrixFout (std::vector <std::vector <double>> & B, std::ofstream & fout,
unsigned int prec = 4, char g = ' ', bool scientifique = false)`

"Fouts" Matrix (double) to file. Returns -1 if the Matrix is empty.

The Matrix may have lines of different length. In this case the "missing"
values to the end for the "shorter lines" are filled with the char **g**.

If **bool scientifique == false**, the precision will be set as prec; 

if **bool scientifique == true**, scientific notation will be applied.
***
`int MatrixFout (std::vector <std::vector <long double>> & B, std::ofstream & fout,
unsigned int prec = 4, char g = ' ', bool scientifique = false)`

"Fouts" Matrix (long double) to file. Returns -1 if the Matrix is empty.

The Matrix may have lines of different length. In this case the "missing"
values to the end for the "shorter lines" are filled with the char **g**.

If **bool scientifique == false**, the precision will be set as prec; 

if **bool scientifique == true**, scientific notation will be applied.
***
`int MatrixFout (std::vector < std::vector <int>> & B, std::ofstream & fout, char g
= ' ')`

"Fouts" Matrix (int) to file. Returns -1 if the Matrix is empty.

The Matrix may have lines of different length. In this case the "missing"
values to the end for the "shorter lines" are filled with the char **g**.
***
`int MatrixFout (std::vector < std::vector <long long int>> & B, std::ofstream &
fout, char g = ' ')`

"Fouts" Matrix (long long int) to file. Returns -1 if the Matrix is empty.

The Matrix may have lines of different length. In this case the "missing"
values to the end for the "shorter lines" are filled with the char **g**.
***
`int VectorCout (const std::vector <int> &P)`

"Couts" vector (int) to screen. Returns -1 if the vector is empty
***
`int VectorFout (const std::vector <int> &P, std::ofstream &fout)`

"Fouts" vector (int) to file. Returns -1 if the vector is empty
***
`int VectorCout (const std::vector <long long int> &P)`

"Couts" vector (long long int) to screen. Returns -1 if the vector is empty
***
`int VectorFout (const std::vector <long long int> &P, std::ofstream &fout)`

"Fouts" vector (long long int) to file. Returns -1 if the vector is empty
***
`int VectorCout (const std::vector <double> &P, unsigned int prec = 4, bool
scientifique = false)`

"Couts" vector (double) to screen. Returns -1 if the vector is empty

If **bool scientifique == false**, the precision will be set as prec; 

if **bool scientifique == true**, scientific notation will be applied.
***
`int VectorFout (const std::vector <double> &P, std::ofstream &fout, unsigned int
prec = 4, bool scientifique = false)`

"Fouts" vector (double) to file. Returns -1 if the vector is empty

If **bool scientifique == false**, the precision will be set as prec;
 
if **bool scientifique == true**, scientific notation will be applied.
***
`int VectorCout (const std::vector <long double> &P, unsigned int prec = 4, bool
scientifique = false)`

"Couts" vector (long double) to screen. Returns -1 if the vector is empty

If **bool scientifique == false**, the precision will be set as prec; 

if **bool scientifique == true**, scientific notation will be applied.
***
`int VectorFout (const std::vector <long double> &P, std::ofstream &fout, unsigned
int prec = 4, bool scientifique = false)`

"Fouts" vector (long double) to file. Returns -1 if the vector is empty

If **bool scientifique == false**, the precision will be set as prec; 
if **bool scientifique == true**, scientific notation will be applied.
***
`int VectorCout (const std::vector <std::string> &P)`

"Couts" vector (string) to screen. Returns -1 if the vector is empty
***
`int VectorFout (const std::vector <std::string> &P, std::ofstream &fout)`

"Fouts" vector (string) to file. Returns -1 if the vector is empty
***
`int PairVectorCout (const std::pair < std::vector<int>, std::vector<double>> & P,
unsigned int prec = 4)`

Modification of the function VectorCout (see it above) for not-integer (double)
weights of edges of a graph.

Graph is represented here as a pair of 2 vectors. The first one is an
"Adjacency vector" without weights. But weights are set in the second one.

So an edge that is set by the pair of vertices indexed as 2\*i, 2\*i+1 in the
first vector has its weight set as i-th element in the second one.
***
`int PairVectorFout (const std::pair < std::vector<int>, std::vector<double>> & P,
std::ofstream &fout, unsigned int prec = 4)`

Modification of the function VectorFout (see it above) for not-integer (double)
weights of edges of a graph.

Graph is represented here as a pair of 2 vectors. The first one is an
"Adjacency vector" without weights. But weights are set in the second one.

So an edge that is set by the pair of vertices indexed as 2\*i, 2\*i+1 in the
first vector has its weight set as i-th element in the second one.

# Working with strings
`int HmDist (const std::string &s1, const std::string &s2)`

Counts Hamming Distance; returns -1 if any string is empty or they have
different length.
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

Generates position frequency matrix (PFM) B upon an array of strings s and
given Alphabet (Alphabet is set via string Alph that contains the sequence of its
symbols);

Ordering of the rows in B corresponds to sequence of symbols in Alph.

If s contains 1 or 0 items or strings have not equal length or even the only
string contains symbol that not belongs to Alphabet or 
if there are any identical symbols in the Alphabet - returns -1 and empty B.
***
`double PDist (const std::string& s1, const std::string& s2)`

Counts p-distance without checking of the input data correctness
***
`int GDistanceMatrix (std::vector <std::string> &s, std::vector <std::vector
<double>> & B)`

Generates DistanceMatrix "B" upon array of strings s; if s contains 1 or 0
items or strings have not equal length returns -1 and empty B.
***
`int EditDist (const std::string &s1, const std::string &s2)`

Computes Edit Distance (Levenshtein distance) between two strings (strings may
be empty too).
***
`void EDistForFindMR (const std::string &s1, const std::string &s2, const int D,
const int L, int l, int b, std::set <std::pair <int, int>> &Result)`

An auxiliary function for FindMutatedRepeatsED, see its info for details 
(below, the following one).
***
`int FindMutatedRepeatsED (std::string &StrShort, std::string &StrLong, int D,
std::set <std::pair <int, int>> &Result)`

The function finds all the substrings of a string StrLong, that have Edit
Distance to a string StrShort <= D. Gap and mistmatch penalties are set as "1"
here.

If dataset is correct returns 0 and set <std::pair <int, int>> Result, that
contains pairs of integers: first one is a start position of a required substring
in StrLong (0-based indexing) and the second one is its length.

If dataset is not correct (any string is empty of StrShort is longer than
StrLong or StrShort's length <= D) returns -1 and empty Result.

The algorithm idea is:
1. To find all start positions of such substrings. To do so we should reverse
both strings and then do Edit Distance Alignment but with no gap penalty at the
beginning: The required substring may start at every position of the longer string
so here are no penalty fo gapping at start.
2. For each start position the maximal possible length for the required
substring (<= StrShort.length+D, but within StrLong).   
Note that the required substrings may have length <= StrShort.length+D and >=
StrShort.length-D because gap penalty = 1.
3. If such maximal possible length meets this condition, let a string TempS be
a substring of StrLong of this length (TempS starts from relevant start position
in StrLong).
4. And then let's do Edit Distance Alignment between TempS and StrShort in order
to find prefixes of TempS, that require the statement of problem to be solved
here.
***
`bool CompStrDLO (const std::string & s1, const std::string & s2)`

Comparing function for arranging an array (vector) of strings in descending
length order
***
`std::string ShortSuperstringGr (std::vector <std::string> DataS)`

Generates shortest superstring of an array (vector) of strings DataS via
implementing greedy algorithm. In doing so, every string that is a substring of
any another one of DataS is to be excluded.

DataS is copied (not linked) here as it will be changed here.

Returns empty string if DataS is empty or all strings of DataS are empty.
***
`int TrieMake (std::vector <std::string> &DataS, std::vector <int> & Trie)`

Trie constructing upon vector of strings DataS

Trie: Here the Trie will be contained as a number of triplets of integers (a =
Trie [3i], b = Trie [3i+1], c = Trie [3i+2], i = 0, 1, ...). Each triplet means an
edge a->b marked with symbol (char) c. Vertices in the Tree are numerated starting
with "1".
***
`void Num (std::string & Numbers, std::vector <double> & A)`

Converts string of numbers <double> (separated by spaces) to a vector of
numbers
***
`void Num (std::string & Numbers, std::vector <int> & A)`

Converts string of numbers <int> (separated by spaces) to a vector of numbers
***
`int Num (std::string & Numbers, int &a1,int &a2, double &a3)`

Converts a string to 3 numbers (2 integers and 1 double; they should be
separated by spaces in the string and the string should’t contain any other
symbols) to int a1,int a2, double a3.

Returns -1 if input data is incorrect (no 3 "candidates to numbers" are found).

But note that here is NO checking if a substring to be converted to a number
contains digits and decimal point only.

# Working with graphs

The "Adjacency vector" is a data structure to represent a graph is used in the
library CBioInfCpp.

### Adjacency vector of unweighted graph

Let "Adjacency vector" of unweighted graph be a data structure, that contains
array of integers such as а[2i], a[2i+1],... (0-basing indexing).

So such array contains even number of elements. Every pair а[2i], a[2i+1] means an
edge between vertex а[2i] and а[2i+1] (~ "Edge list as one String").
This format don't identify the graph as directed or undirected (both cases may
be). If the graph is considered as directed, its edges should be considered as
а[2i] -> a[2i+1].

### Adjacency vector of weighted graph: weights are integers
Let "Adjacency vector" of weighted graph (all weights are integers) be a data
structure, that contains array of integers such as а[3i], a[3i+1], a[3i+2],... (0-
basing indexing).

So such array contains 3n number of elements. Every pair а[3i], a[3i+1] means an
edge between vertex а[3i] and а[3i+1] with weight a[3i+2]("Edge list as one
String").

This format don't identify the graph as directed or undirected (both cases may
be). If the graph is considered as directed, its edges should be considered as
а[3i] -> a[3i+1].

### Adjacency vector of weighted graph: weights are doubles

As we are not able to create an array (or a vector) that contains both integers
and doubles let’s do the following. Let a graph is represented here as a pair of 2
vectors (i.e. std::pair < std::vector<int>, std::vector<double>>). The first one
is an "Adjacency vector" without weights. But weights are set in the second one.

So an edge that is set by the pair of vertices indexed as 2\*i, 2\*i+1 in the first
vector has its weight set as i-th element in the second one.

The "Adjacency vector" may be considered as another one data structure to
represent a graph. It is compact, smaller than Adjacency Matrix (for sparse
graphs), simple to implement and it may be a convenient one for some tasks and
problems solving.

By the way, vertices of a graph may be marked by both positive and non-positive
numbers here. In order to implement some function vertices may be renumbered to
get started from "0" or "1"; in doing so, the vertices will be assigned their
original numbers before the function is complete.

Also any graph may have multiple edges and multiple loops.

***  
`int UWGraphRead (std::ifstream & fin, std::vector <int> & A)`

Reads Edge list to "Adjacency vector" of unweighted graph (i.e. to vector A).
Let "Adjacency vector" of unweighted graph be a data structure, 
that contains array of integers such as а[2i], a[2i+1],... / 0-basing indexing
in array /.

So such array contains even number of elements. Every pair а[2i], a[2i+1] means
an edge between vertex а[2i] and а[2i+1] (~ "Edge list as one String").

This format don't identify the graph as directed or undirected (both cases may
be). If the graph is considered as directed, its edges should be considered as
а[2i] -> a[2i+1].

Input file should be in edge list format, every edge in new line.

Returns -1 and empty "Adjacency vector" A if any line contains number of
elements that !=2.
***
`int WGraphRead (std::ifstream & fin, std::vector <int> & A)`

Reads Edges list to "Adjacency vector" of weighted graph. Let "Adjacency
vector" of weighted graph be a data structure, that contains array of integers
such as а[3i], a[3i+1], a[3i+2],... / 0-basing indexing in array /.

So such array contains 3n number of elements. Every pair а[3i], a[3i+1] means
an edge between vertex а[3i] and а[3i+1] with weight a[3i+2]("Edge list as one
String").

This format don't identify the graph as directed or undirected (both cases may
be). If the graph is considered as directed, its edges should be considered as
а[3i] -> a[3i+1].

Input file should be in edge list format, every edge in new line.

Returns -1 and empty "Adjacency vector" A if any line contains number of
elements of any line that !=3.
***
`int WGraphRead (std::ifstream & fin, std::pair < std::vector<int>,
std::vector<double>> & A)`

Modification of the function WGraphRead (see it above) for not-integer (double)
weihgts of edges of a graph.

Graph is represented here as a pair of 2 vectors. The first one is an
"Adjacency vector" without weights. But weights are set in the second one.

So an edge that is set by the pair of vertices indexed as 2\*i, 2\*i+1 in the
first vector has its weight set as i-th element in the second one.
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

Renumerates vertices adding d-parameter (d may be non-negative or negative)

Graph must be set as "Adjacency vector", bool "weighted" sets if the graph is
weighted or no.

If (IgnoreWeighted = true) the function adds d to every element in A without
any dataset checking
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

An auxiliary function that finds the first unmarked vertex in the graph (0
means unmarked)
***
`void EcycleDGraph (int t, std::vector <int> & R, const int V, std::vector
<std::vector<int>> &B)`

An auxiliary function that finds Eulerian cycle in the DIRECTED graph without
without checking of input data correctness (i.e. (1) the graph includes Eulerian cycle,
 (2) its vertices numbers start from "1", (3) the graph doesn't contain any isolated vertices).

B is the Adjacency matrix, containing the number of edges between the vertices.
V is the max number assigned to vertices.
***
`int EPathDGraph (std::vector <int> & A, std::vector <int> & R, const bool
weighted, std::vector <int> & Isolated)`

Finding Eulerian Cycle or Path in directed graph (weighted or non-weighted)
that may contain multiple edges and multiple loops.

Returns Path/ Cycle as R, isolated vertices as Isolated. Returns value "1" if
Eulerian cycle has been found or value "2" if Eulerian path has been found or "-1"
together with empty R and Isolates if no cycle/ path found.

If any vertex has loops only, such a vertex is not considered as an isolated
one.

Vertices may be numbered in different ways (they may be marked by both negative
and non-negative integers). In doing so, we set that the graph contains vertices
marked by all the integers from min (1, minimal number assigned to vertices) to
maximal number assigned to vertices inclusive.

In order to implement the function vertices may be renumbered to get started
from "1"; after search is completed, the vertices will be assigned their original
numbers.
***
`int EPathDGraph (std::pair < std::vector<int>, std::vector<double>> & A,
std::vector <int> & R, std::vector <int> & Isolated)`

Modification of the function EPathDGraph (see it above) for not-integer
(double) weights of edges of a graph.

Graph is represented here as a pair of 2 vectors. The first one is an
"Adjacency vector" without weights. But weights are set in the second one.

So an edge that is set by the pair of vertices indexed as 2\*i, 2\*i+1 in the
first vector has its weight set as i-th element in the second one.
***
`int DistanceBFA (std::vector <long long int> &A, std::vector <int> & D, const int
b, std::vector <int> & Prev, const bool weighted, int V = INT_MIN)`

The function counts the shortest distances from the vertex b to all vertices in
the graph (these distances are to be contained in vector D, i.e. D[i] means the
shortest distance from b to I).

By default vector D is filled with LLONG_MAX.

Vector Prev is intended to contain the number of the previous vertex for every
vertex in such shortest paths ("-1" value is set by default and means "this vertex
doesn't included in any such path").

The Breadth-first search method is used here.

The input graph should be directed, both weighted or unweighted (in case of
unweighted graph we consider every edge's weight as "1".) The graph may have loops
and multiple edges.

Input data: Adjacency vector A (it is supposed that vertices are numbered
starting from 0) and the maximum vertex number V (V may be not set, in this case
it will be the maximum vertex number of Adjacency vector A)

The edges may have weight of 0, >0, <0.

In case we found a negative weight cycle as well as input data is incorrect the
function returns "-1" and empty D and Prev.
***
`int DistanceBFA (std::pair < std::vector<int>, std::vector<double>> & A,
std::vector <long double> & D, const int b, std::vector <int> & Prev, int V =
INT_MIN)`

Modification of the function DistanceBFA (see it above) for not-integer
(double) weights of edges of a graph.

Graph is represented here as a pair of 2 vectors. The first one is an
"Adjacency vector" without weights. But weights are set in the second one.

So an edge that is set by the pair of vertices indexed as 2\*i, 2\*i+1 in the
first vector has its weight set as i-th element in the second one.
***
`int DFSTS (const std::vector <int> & A, const int b, std::vector <int> & Visited,
std::vector <int> & order, const bool weighted)`

An auxiliary function for the function TSortHP. Works without any checking of
input data correctness. Vertices in the input directed graph (it is set by the
Adjacency vector A) are to be numbered starting from 1.

The graph may contain loops (they will be ignored).

During building topological sorting we shall colour vertices (using vector
Visited): 0 = unvisited (white), 1 = visited, but not still finished yet (grey), 2
= finished (black).

Bool "weighted" should be set as "true" for weighted graph, "false" for
unweighted.

If the graph contains cycle - returns 1 and empty "order".16
***
`int TSortHP (std::vector <int> & A, std::vector <int> & R, std::vector <int> &
order, std::vector <int> & Isolated, const bool weighted, const bool OnlyTS =
false)`

The function finds topological sorting of directed graph (returned as vector
"order").

ONLY IF topological sorting exists AND OnlyTS == false the function also checks
for Hamiltonian path (returned as vector R) and list of Isolated vertices
(returned as vector Isolated).

The graph is set by Adjacency vector A, may be weighted or no (bool weighted).

The graph may contain loops (they will be ignored).

If any vertex has loops only, such a vertex is not considered as an isolated
one.

The graph may contain multiple edges.

Vertices may be numbered in different ways (they may be marked by both negative
and non-negative integers). In doing so, we set that the graph contains vertices
marked by all the integers from min (1, minimal number assigned to vertices) to
maximal number assigned to vertices inclusive.

In order to implement the function vertices may be renumbered to get started
from "1"; after search is completed, the vertices will be assigned their original
numbers.

So if OnlyTS == false:
* the function returns 0 if both topological sorting and Hamiltonian path found.
* the function returns -1 and empty Isolated, order, R if the graph contains
cycle.
* the function returns 1 if topological sorting found and, upon that, Hamiltonian
path doesn't exist.

If OnlyTS == true, both R and Isolated will be returned empty (to make this
function faster). The function returns 0 if topological sorting is found and -1
otherwise.
***
`int TSortHP (std::pair < std::vector<int>, std::vector<double>> & A, std::vector
<int> & R, std::vector <int> & order, std::vector <int> & Isolated, const bool
OnlyTS = false)`

Modification of the function TSortHP (see it above) for not-integer (double)
weights of edges of a graph.

Graph is represented here as a pair of 2 vectors. The first one is an
"Adjacency vector" without weights. But weights are set in the second one.

So an edge that is set by the pair of vertices indexed as 2\*i, 2\*i+1 in the
first vector has its weight set as i-th element in the second one.
***
`int DistanceTS (std::vector <int> &A, std::vector <long long int> & D, const int
b, std::vector <int> & Prev, const bool weighted, int V = INT_MIN)`

The function counts the shortest distances from the vertex b to all vertices in
the graph (these distances are to be contained in vector D, i.e. D[i] means the
shortest distance from b to i).

By default vector D is filled with LLONG_MAX.

In doing so, vector Prev is intended to contain the number of the previvous
vertex for every vertex in such shortest paths ("-1" value is set by default and
means "this vertex doesn't included in any such path").

This function seems to be faster than DistanceBFA, but DistanceTS works only
with graphs containing no cycles (except loops, multiple loops).

The input graph should be directed, both weighted or unweighted (in this case
we consider every edge's weight as "1".) The graph may have loops and multiple
edges.

Input data: Adjacency vector A (it is supposed that vertices are numbered
starting from 0) and the maximum vertex number V (V may be not set, in this case
it will be the maximum vertex number of Adjacency vector A)

The edges of a weighted graph may have weight of 0, >0, <0, but only less than
INT_MAX (<INT_MAX).

In case we found a cycle as well as input data is incorrect the function
returns "-1" and empty D and Prev.
***
`int DistanceTS (std::pair < std::vector<int>, std::vector<double>> & A,
std::vector <long double> & D, const int b, std::vector <int> & Prev, int V =
INT_MIN)`

Modification of the function DistanceTS (see it above) for not-integer (double)
weights of edges of a graph.

Graph is represented here as a pair of 2 vectors. The first one is an
"Adjacency vector" without weights. But weights are set in the second one.

So an edge that is set by the pair of vertices indexed as 2\*i, 2\*i+1 in the
first vector has its weight set as i-th element in the second one.

# Auxiliary functions

`int MatrixSet (std::vector <std::vector <double>> & B, const int NLines, const int
NColumns, const double i)`

Sets (resets) matrix NLines x NColumns filled value "i" (double). Returns -1 if
NLines or NColumns <=0
***
`int MatrixSet (std::vector <std::vector <long double>> & B, const int NLines,
const int NColumns, const long double i)`

Sets (resets) matrix NLines x NColumns filled value "i" (long double). Returns
-1 if NLines or NColumns <=0
***
`int MatrixSet (std::vector <std::vector <int>> & B, const int NLines, const int
NColumns, const int i)`

Sets (resets) matrix NLines x NColumns filled value "i" (int). Returns -1 if
NLines or NColumns <=0
***
`int MatrixSet (std::vector <std::vector <long long int>> & B, const int NLines,
const int NColumns, const long long int i)`

Sets (resets) matrix NLines x NColumns filled value "i" (long long int).
Returns -1 if NLines or NColumns <=0
***
`int FindIn (std::vector <int> &D, int a, unsigned int step = 1, unsigned int start
= 0)`

Returns index in vector (int) of the first element = a. Search starts from
index "start" with step = "step". If no such element found the function returns 0.
***
`int FindIn (std::vector <long long int> &D, long long int a, unsigned int step =
1, unsigned int start = 0)`

Returns index in vector (long long int) of the first element = a. Search starts
from index "start" with step = "step". If no such element found the function
returns 0.
***
`int FindIn (std::vector <double> &D, double a, unsigned int step = 1, unsigned int
start = 0)`

Returns index in vector (double) of the first element = a. Search starts from
index "start" with step = "step". If no such element found the function returns 0.

Yes, operation like (a==b) may be not correct for doubles. But this function
may be considered as an useful one in some cases.

The following version of the function finds the first element, that differs
from "a" less than "d".
***
`int FindIn (std::vector <double> &D, double a, double d, unsigned int step = 1,
unsigned int start = 0)`

Returns index in vector (double) of the first element, that differs from "a"
less than nonnegative double "d".

Search starts from index "start" with step = "step". If no such element found
the function returns 0.
***
`int FindIn (std::vector <long double> &D, long double a, unsigned int step = 1,
unsigned int start = 0)`

Returns index in vector (long double) of the first element = a. Search starts
from index "start" with step = "step". If no such element found the function
returns 0.

Yes, operation like (a==b) may be not correct for doubles. But this function
may be considered as an useful one in some cases. The following version of the
function finds the first element, that differs from "a" less than "d".
***
`int FindIn (std::vector <long double> &D, long double a, long double d, unsigned
int step = 1, unsigned int start = 0)`

Returns index in vector (long double) of the first element, that differs from
"a" less than nonnegative long double "d".

Search starts from index "start" with step = "step". If no such element found
the function returns 0.
***
`int FindIn (std::vector <string> &D, std::string a, unsigned int step = 1,
unsigned int start = 0)`

Returns index in vector (string) of the first element = a. Search starts from
index "start" with step = "step". If no such element found the function returns 0.
***
`int SwapInVector (std::vector <int> & A1, unsigned int f, unsigned int l)`

Swaps 2 elements in vector (int). Returns -1 if some index out of vector's
range or vector is empty
***
`int SwapInVector (std::vector <long long int> & A1, unsigned int f, unsigned int
l)`

Swaps 2 elements in vector (long long int). Returns -1 if some index out of
vector's range or vector is empty
***
`int SwapInVector (std::vector <double> & A1, unsigned int f, unsigned int l)`

Swaps 2 elements in vector (double). Returns -1 if some index out of vector's
range or vector is empty
***
`int SwapInVector (std::vector <long double> & A1, unsigned int f, unsigned int l)`

Swaps 2 elements in vector (long double). Returns -1 if some index out of
vector's range or vector is empty
***
`int SwapInVector (std::vector < std::string> & A1, unsigned int f, unsigned int l)`

Swaps 2 elements in vector (string). Returns -1 if some index out of vector's
range or if the vector is empty
***
`int PartitionOfNumber (std::vector <std::vector <int>> &B, int n)`

Generates partitions of int n (i.e. representing n as a sum of positive
integers) in B. If n<=0 returns empty B and "-1"
***
`int PartitionOfNumberL (std::vector < std::vector <int>> &B, int n, int l=-1)`

Generates partitions of int n (i.e. representing n as a sum of positive
integers) in B. Extended version: one may set l>0 as a length of partitions (i.e.
number of summands).

In this case "0" will be added to the end of the shorter partitions. If n<=0
returns empty B and "-1"