#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <ctime>
#include <conio.h>
#include <cmath>

using namespace std;

// -1_07------------------------------------

//char *cat(const char *left, const char *right)
//{
//    size_t left_size  = strlen(left);
//    size_t right_size = strlen(right);

//    char *res = new char[left_size + right_size + 1];

//    for (size_t i = 0; i < left_size; ++i)
//    {
//        res[i] = left[i];
//    }

//    for (size_t i = 0; i < right_size; ++i)
//    {
//        res[i + left_size] = right[i];
//    }

//    res[left_size + right_size] = '\0';

//    return res;
//}

//int main()
//{
//    char foo[] = "HI";
//    char space[] = " ";
//    char bar[] = "THERE!";

//    char *res = cat(foo, space);
//    res = cat(res, bar);

//    cout << res << endl;

//    delete[] res;

//    return 0;
//}

// -1_08------------------------------------

//int main()
//{
//    char str[80];
//    size_t ascii_matches[256]{0};

//    cout << "Enter your string: ";
//    cin.getline(str, 80);

//    for (size_t i = 0; i < strlen(str); ++i)
//    {
//        ascii_matches[(int)str[i]]++;
//    }

//    for (size_t i = 0; i < 256; ++i)
//    {
//        if(ascii_matches[i])
//        {
//            cout << "'" << (char)i << "' occurs " << ascii_matches[i] << " times." << endl;
//        }
//    }

//    return 0;
//}

// -1_09------------------------------------

//int main()
//{
//    char str[80];
//    char pattern[] = "abcdefgh123456-0";

//    cout << "Enter your string: \n";
//    cin.getline(str, 256);

//    for (size_t i = 0; i < strlen(str); ++i)
//    {
//        for (size_t j = 0; j < strlen(pattern); ++j)
//        {
//            if(str[i] == pattern[j])
//            {
//                str[i] = pattern[(j + 5) % strlen(pattern)];
//                break;
//            }
//        }
//    }

//    cout << "\nEncrypted string: \n" << str << endl;

//    return 0;
//}

// -1_10------------------------------------

//int main()
//{
//    char str[] = "aaa  bbb cccc ddd    eee ff g ";
//    size_t letters = 0;

//    cout << str << endl << endl;

//    for (size_t i = 0; i < strlen(str); ++i)
//    {
//        if (str[i] != ' ')
//        {
//            letters++;
//        }

//        if (str[i + 1] == ' ' || str[i + 1] == '\0')
//        {
//            str[i - (letters - 1)] = toupper(str[i - (letters - 1)]);
//            letters = 0;
//        }
//    }

//    cout << str << endl;

//    return 0;
//}

// -1_11------------------------------------

//int main()
//{
//    char str[] = "aaa bbb ccc ddd eee fff gg";
//    int letters = 0;

//    cout << str << endl << endl;

//    for (int i = 0; i < strlen(str); ++i)
//    {
//        if(str[i] != ' ')
//        {
//            ++letters;
//        }

//        if(str[i + 1] == ' ' || str[i + 1] == '\0')
//        {
//            str[i - (letters - 1)] = '\n';
//            letters = 0;
//        }
//    }

//    char *p1 = str, *p2 = str;

//    while(*p1 != '\0')
//    {
//        if(*(p1++) != '\n')
//        {
//            *p2++ = *(p1 - 1);
//        }
//    }

//    *p2 = '\0';

//    cout << str << endl;

//    return 0;
//}

// -1_12------------------------------------

//void SwapOdds(int& arr, size_t size)
//{
//    int* p_Arr = &arr;

//    for (int i = 0; i + 1 < size; ++i)
//    {
//        if(!(i % 2))
//        {
//            swap(p_Arr[i], p_Arr[i + 1]);
//        }
//    }
//}

//int main()
//{
//    size_t size = 12;
//    int* arr = new int[size];

//    for (int i = 0; i < size; ++i)
//    {
//        arr[i] = i;
//        cout << arr[i] << ' ';
//    }

//    cout << endl;

//    SwapOdds(*arr, size);

//    for (int i = 0; i < size; ++i)
//    {
//        cout << arr[i] << ' ';
//    }

//    cout << endl;

//    delete[] arr;

//    return 0;
//}

// -1_13------------------------------------

//int main()
//{
//    srand(size_t(time(0)));

//    size_t arr[50];
//    size_t* pArr = arr;

//    for (int i = 0; i < 100; ++i)
//    {
//        if (i & 1)
//        {
//            *pArr = i;
//            cout << *pArr << ' ';
//            pArr++;
//        }
//    }

//    cout << endl << endl;

//    //This causes the original array changing. A little conflict with the task.
//    for (int i = 0; i < 50; ++i)
//    {
//        swap(arr[i], arr[rand() % 50]);
//    }

//    for (int i = 0; i < 50; ++i)
//    {
//        cout << arr[i] << ' ';
//    }

//    return 0;
//}

// -1_14------------------------------------

//int* MakeUniques(int min, int max, size_t count)
//{
//    if(count > max)
//    {
//        throw 9000;
//    }

//    int* arr = new int[count];

//    for (size_t i = 0; i < count; ++i)
//    {
//        arr[i] = min + rand() % (max - min);

//        for (size_t j = 0; j < count; ++j)
//        {
//            if(j == i || arr[i] != arr[j])
//            {
//                continue;
//            }
//            else
//            {
//                --i;
//                break;
//            }
//        }
//    }
//    return arr;
//}

//char* GeneratePW
//(
//    size_t size,
//    const char* pattern = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
//                          "abcdefghijklmnopqrstuvwxyz"
//                          "0123456789"
//                          "_"
//)
//{
//    char* res = new char[size + 1];

//    for (size_t i = 0; i < size; ++i)
//        res[i] = pattern[rand() % strlen(pattern)];

//    //Security requirements
//    int* unique_indices = MakeUniques(0, size, 3);

//    const char security_parts[3] = { char(65 + rand() % 26),
//                                     char(97 + rand() % 26),
//                                     char(48 + rand() % 10) };

//    for (int i = 0; i < 3; ++i)
//    {
//        res[unique_indices[i]] = security_parts[i];
//    }

//    res[size] = '\0';

//    delete[] unique_indices;
//    return res;
//}

//int main()
//{
//    srand((unsigned int)time(0));

//    size_t size = 8;

//    do
//    {
//        system("cls");
//        cout << "Press any key to generate a password (Esc to exit):\n";

//        char* pw = GeneratePW(size);

//        for (size_t i = 0; i < size; ++i)
//        {
//            cout << pw[i];
//        }
//        cout << endl;

//        delete[] pw;
//    } while(getch() != 27);

//    return 0;
//}

// -1_15------------------------------------

//void Rotate(int**& arr, size_t n, size_t m)
//{
//    int** rotated = new int*[m];

//    for (size_t i = 0; i < m; ++i)
//    {
//        rotated[i] = new int[n];
//    }

//    for (size_t i = 0; i < n; ++i)
//    {
//        for (size_t j = 0; j < m; ++j)
//        {
//            rotated[j][n - 1 - i] = arr[i][j];
//        }
//    }

//    for (size_t i = 0; i < n; ++i)
//    {
//        delete[] arr[i];
//    }
//    delete[] arr;

//    arr = rotated;
//}

//int main()
//{
//    size_t n, m;

//    do
//    {
//        system("cls");
//        cout << "Enter the number of  lines  (0 < n <= 100): ";
//        cin >> n;

//        cout << "Enter the number of columns (0 < m <= 100): ";
//        cin >> m;
//    }
//    while (n > 100 || m > 100);

//    int** arr = new int*[n];
//    for (size_t i = 0; i < n; ++i)
//    {
//        arr[i] = new int[m];
//    }

//    cout << "OK. Now enter array members:" << endl;

//    for (size_t i = 0; i < n; ++i)
//    {
//        for (size_t j = 0; j < m; ++j)
//        {
//            cout << "[" << i << "][" << j << "]: ";
//            cin >> arr[i][j];{}
//        }
//    }

//    cout << endl << "Origin array:" << endl;

//    for (size_t i = 0; i < n; ++i)
//    {
//        for (size_t j = 0; j < m; ++j)
//        {
//            cout.width(5);
//            cout << arr[i][j];
//        }
//        cout << endl;
//    }

//    Rotate(arr, n, m);

//    cout << endl << "Rotated array:" << endl;

//    for (size_t i = 0; i < m; ++i)
//    {
//        for (size_t j = 0; j < n; ++j)
//        {
//            cout.width(5);
//            cout << arr[i][j];
//        }
//        cout << endl;
//    }

//    for (size_t i = 0; i < m; ++i)
//    {
//        delete[] arr[i];
//    }
//    delete[] arr;

//    return 0;
//}

// -1_16------------------------------------

//double DetOf3x3Array(int** arr)
//{
//   return ( arr[0][0]*(arr[1][1]*arr[2][2] - arr[1][2]*arr[2][1]) +
//            arr[0][1]*(arr[1][2]*arr[2][0] - arr[1][0]*arr[2][2]) +
//            arr[0][2]*(arr[1][0]*arr[2][1] - arr[1][1]*arr[2][0]));
//}

//int main()
//{
//    srand((unsigned int)time(0));

//    int** arr = new int* [3];

//    for (int i = 0; i < 3; ++i)
//    {
//        arr[i] = new int[3];
//        for (int j = 0; j < 3; ++j)
//        {
//            arr[i][j] = -10 + rand() % 21;
//        }
//    }

//    for (int i = 0; i < 3; ++i)
//    {
//        if (i == 1)
//        {
//            cout << "det |";
//        }
//        else
//        {
//            cout << "    |";
//        }

//        for (int j = 0; j < 3; ++j)
//        {
//            cout.width(3);
//            cout << arr[i][j] << ' ';
//        }

//        if (i == 1)
//        {
//            cout << "| = " << DetOf3x3Array(arr) << endl;
//        }
//        else
//        {
//            cout << "|" << endl;
//        }
//    }

//    for (int i = 0; i < 3; ++i)
//    {
//        delete[] arr[i];
//    }

//    delete[] arr;

//    return 0;
//}

// -1_17------------------------------------

//typedef vector<vector<double>> matrix;

//void InitRndMatrix(matrix& mtrx, int min, int max)
//{
//    for (size_t i = 0; i < mtrx.size(); ++i)
//    {
//        for (size_t j = 0; j < mtrx[0].size(); ++j)
//        {
//            if (min == 0 && max == 0)
//            {
//                mtrx[i][j] = 0;
//                continue;
//            }
//            mtrx[i][j] = min + rand() % (max - min);
//        }
//    }
//}

//matrix CreateCustomMatrix()
//{
//    size_t lines, columns;

//    cout << "Enter a number of  lines  of the new matrix: ";
//    cin >> lines;

//    if(!lines) throw "!lines";

//    cout << "Enter a number of columns of the new matrix: ";
//    cin >> columns;

//    if(!columns) throw "!columns";

//    matrix out(lines, vector<double>(columns));

//    cout << "OK. Enter matrix elements: " << endl;

//    for (size_t i = 0; i < lines; ++i)
//    {
//        for (size_t j = 0; j < columns; ++j)
//        {
//            cout << "["<< i << "][" << j << "]: ";
//            cin >> out[i][j];
//        }
//        cout << endl;
//    }

//    return out;
//}

//void PrintMatrix(const matrix& mtrx)
//{
//    for (size_t i = 0; i < mtrx.size(); ++i)
//    {
//        for (size_t j = 0; j < mtrx[0].size(); ++j)
//        {
//            cout.width(5);
//            cout << mtrx[i][j] << ' ';
//        }
//        cout << endl;
//    }
//}

//matrix MultiplicateMatrices(const matrix& first_matrix, const matrix& second_matrix)
//{
//    if (first_matrix[0].size() != second_matrix.size())
//        throw "first_matrix[0].size() != second_matrix.size()";

//    matrix res(first_matrix.size(), vector<double>(second_matrix[0].size()));
//    InitRndMatrix(res, 0, 0);

//    for (size_t i = 0; i < res.size(); i++)
//    {
//        for (size_t j = 0; j < res[0].size(); j++)
//        {
//            for (size_t k = 0; k < first_matrix[0].size(); k++)
//            {
//                res[i][j] += first_matrix[i][k] * second_matrix[k][j];
//            }
//        }
//    }

//    return res;
//}

//int main()
//{
////    srand(size_t(time(0)));

////    matrix first_matrix(2, vector<double>(4));
////    matrix second_matrix(4, vector<double>(2));

////    InitRndMatrix(first_matrix, -10, 10);
////    InitRndMatrix(second_matrix, -10, 10);

//    matrix first_matrix = CreateCustomMatrix(), second_matrix = CreateCustomMatrix();

//    cout << "First matrix: " << endl;
//    PrintMatrix(first_matrix);
//    cout << endl;

//    cout << "Second matrix: " << endl;
//    PrintMatrix(second_matrix);
//    cout << endl;

//    cout << "Result of multiplication: " << endl;
//    PrintMatrix(MultiplicateMatrices(first_matrix, second_matrix));

//    return 0;
//}

// -1_18------------------------------------

//typedef struct
//{
//    char name[20];
//    unsigned short age;
//    unsigned int salary;
//} professor;

//typedef struct
//{
//    char name[20];
//    unsigned short age;
//    float gpa;
//    professor* supervisor;
//} student;

//void InitFaculty(student* group, size_t group_size,
//               professor* supervisors, size_t department_size,
//               const char** f_names, const char** s_names)
//{
//    //Academic department initialization
//    for (size_t i = 0; i < department_size; ++i)
//    {
//        *supervisors[i].name = '\0';
//        strcat(supervisors[i].name, f_names[rand() % 8]);
//        strcat(supervisors[i].name, " ");
//        strcat(supervisors[i].name, s_names[rand() % 8]);

//        supervisors[i].age = rand() % 30 + 32;
//        supervisors[i].salary = (rand() % 50 + 11) * 100;
//    }

//    //Group initialization
//    for (size_t i = 0; i < group_size; ++i)
//    {
//        *group[i].name = '\0';
//        strcat(group[i].name, f_names[rand() % 8]);
//        strcat(group[i].name, " ");
//        strcat(group[i].name, s_names[rand() % 8]);

//        group[i].age = rand() % 17 + 17;
//        group[i].gpa = rand() % 101;

//        group[i].supervisor = &supervisors[rand() % department_size];
//    }
//}

//void PrintGroupFullInfo(student* group, size_t group_size)
//{
//    for (size_t i = 0; i < group_size; ++i)
//    {
//        cout << i + 1 << ". " << left;
//        cout.width(25);
//        cout << group[i].name << group[i].age << " y. o.,";
//        cout << " GPA: ";
//        cout.width(3);
//        cout << right << group[i].gpa;
//        cout << ". Supervisor: " << group[i].supervisor->name << "." << endl;
//    }
//    cout << endl;
//}

//int main()
//{
//    srand(size_t(time(0)));

//    static const char* f_names[] =
//    {"Bob", "Bill", "Javier", "Ian", "Rudolphi", "Uther", "Jason", "Peter"};

//    static const char* s_names[] =
//    {"Heinz", "Guatebusto", "Bowie", "Bobson", "Trump", "McArthur", "Cooper", "Lee"};

//    size_t group_size = 8;
//    size_t department_size = 3;
//    float mean_gpa = 0;

//    student* group = new student[group_size];
//    professor* department = new professor[department_size];

//    InitFaculty(group, group_size, department, department_size, f_names, s_names);
//    PrintGroupFullInfo(group, group_size);

//    cout << "Mean GPA of group is ";

//    for (size_t i = 0; i < group_size; ++i)
//    {
//        mean_gpa += group[i].gpa;
//    }

//    mean_gpa /= group_size;
//    cout.precision(5);
//    cout << mean_gpa << endl;

//    student worst = group[0];
//    student best = group[0];

//    for (size_t i = 0; i < group_size - 1; ++i)
//    {
//        if(group[i + 1].gpa < worst.gpa)
//        {
//            worst = group[i + 1];
//        }

//        if(group[i + 1].gpa > best.gpa)
//        {
//            best = group[i + 1];
//        }
//    }

//    cout << "The best student is " << best.name << " with " << best.gpa << "." << endl;
//    cout << "The worst student is " << worst.name << " with " << worst.gpa << "." << endl << endl;

//    size_t counter = 0;
//    cout << "Students whose supervisors are older than 50:" << endl;

//    for (size_t i = 0; i < group_size; ++i)
//    {

//        if(group[i].supervisor->age >= 50)
//        {
//            cout << ++counter << ". ";
//            cout.width(24);
//            cout << left << group[i].name;
//            cout << " (" << group[i].supervisor->name << " is "
//                 << group[i].supervisor->age << " y. o.)." << endl;
//        }
//    }

//    if(!counter)
//    {
//        cout << " are not existing!";
//    }

//    cout << endl;

//    for (int i = 0; i < 8; ++i)
//    {
//        delete f_names[i];
//        delete s_names[i];
//    }

//    delete[] group;
//    delete[] department;

//    return 0;
//}

// -1_19------------------------------------

//template<typename T>
//void Map(vector<T>& container, void (*func)(T&))
//{
//    for (size_t i = 0; i < container.size(); ++i)
//    {
//        func(container[i]);
//    }
//}

//template<typename T>
//void Filter(vector<T>& container, bool (*pred)(T))
//{
//    vector<T> res_container(container.size());
//    size_t rc_index = 0;

//    for (size_t i = 0; i < container.size(); ++i)
//    {
//        if(pred(container[i]))
//        {
//            res_container[rc_index++] = container[i];
//        }
//        else continue;
//    }
//    res_container.resize(rc_index);
//    container = res_container;
//}

//template<typename T>
//void Reduce(vector<T>& container, T (*action)(T, T))
//{
//    for (size_t i = 1; i < container.size(); ++i)
//    {
//        container[0] = action(container[0], container[i]);
//    }

//    container.resize(1);
//}

//template<typename T>
//void PrintArray(T arr)
//{
//    for (size_t i = 0; i < arr.size(); ++i)
//    {
//        cout.width(3);
//        cout << arr[i] << " ";
//    }
//    cout << endl << endl;
//}

//template<typename T>
//void Incr(T& a)
//{
//    ++a;
//}

//template<typename T>
//void Pow2(T& a)
//{
//    a *= a;
//}

//template<typename T>
//bool IsOdd(T a)
//{
//    return !((int)a % 2);
//}

//template<typename T>
//T Sum(T a, T b)
//{
//    return a + b;
//}

//int main()
//{
//    vector<int> arr(15);

//    for (size_t i = 0; i < arr.size(); ++i)
//    {
//        arr[i] = i + 1;
//    }

//    cout << "Base array: " << endl;
//    PrintArray(arr);

//    Map(arr, Incr);
//    cout << "Mapped with incrementing: " << endl;
//    PrintArray(arr);

//    Map(arr, Pow2);
//    cout << "Mapped with powering to 2: " << endl;
//    PrintArray(arr);

//    Filter(arr, IsOdd);
//    cout << "Filtered by odds: " << endl;
//    PrintArray(arr);

//    Reduce(arr, Sum);
//    cout << "Reduced with summing: " << endl;
//    PrintArray(arr);

//    return 0;
//}

