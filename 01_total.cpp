#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <ctime>
#include <conio.h>
#include <cmath>

using namespace std;

// -1_07------------------------------------

//char *cat(char *left, char *right)
//{
//    size_t left_size  = strlen(left);
//    size_t right_size = strlen(right);

//    char *res = new char[left_size + right_size + 1];

//    for (int i = 0; i < left_size; ++i)
//    {
//        res[i] = left[i];
//    }

//    for (int i = 0; i < right_size; ++i)
//    {
//        res[i + left_size] = right[i];
//    }

//    res[left_size + right_size] = '\0';

//    return res;
//}

//int main(int argv, char* argc[])
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

//int CharFreq(char *str, char c)
//{
//    int count = 0;
//    for(int i = 0; i < strlen(str); ++i)
//    {
//        if(str[i] == c)
//        {
//            ++count;
//        }
//    }
//    return count;
//}

//int main(int argv, char* argc[])
//{
//    char str[80], penalty_buff[80];

//    cout << "Enter your string: ";
//    cin.getline(str, 255);

//    for (int i = 0; i < strlen(str); ++i)
//    {
//        if(CharFreq(penalty_buff, str[i]))
//        {
//            penalty_buff[i] = '\n';
//            continue;
//        }

//        cout << "Character '"
//             << str[i]
//             << "' occurs "
//             << CharFreq(str, str[i])
//             << " times."
//             << endl;

//        penalty_buff[i] = str[i];
//    }

//    return 0;
//}

// -1_09------------------------------------

//int main(int argv, char* argc[])
//{
//    char str[80];
//    char pattern[] = "abcdefgh123456-0";

//    cout << "Enter your string: \n";
//    cin.getline(str, 256);

//    for (int i = 0; i < strlen(str); ++i)
//    {
//        for (int j = 0; j < strlen(pattern); ++j)
//        {
//            if(str[i] == pattern[j])
//            {
//                str[i] = pattern[(j + 5 >= strlen(pattern) ? (j + 5) % strlen(pattern) : j + 5)];
//                break;
//            }
//        }
//    }

//    cout << "\nEncrypted string: \n" << str << endl;

//    return 0;
//}

// -1_10------------------------------------

//int main(int argv, char* argc[])
//{
//    char str[] = "aaa bbb cccc ddd eee ff g";
//    size_t letters = 0;

//    cout << str << endl << endl;

//    for (int i = 0; i < strlen(str); ++i)
//    {
//        if(str[i] != ' ')
//        {
//            ++letters;
//        }

//        if(str[i + 1] == ' ' || str[i + 1] == '\0')
//        {
//            str[i - (letters - 1)] -= 32;
//            letters = 0;
//        }
//    }

//    cout << str << endl;

//    return 0;
//}

// -1_11------------------------------------

//int main(int argv, char* argc[])
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

//int main(int argv, char* argc[])
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

//bool Contains(int* arr, size_t size, int value)
//{
//    for (int i = 0; i < size; ++i)
//    {
//        if (arr[i] == value)
//        {
//            return true;
//        }
//    }
//    return false;
//}

//int main(int argv, char* argc[])
//{
//    const size_t size = 50;
//    int arr[size], penalty_arr[size]{ 0 };
//    int* ppa = penalty_arr;

//    srand((unsigned int)time(0));

//    for (int i = 0; i < size * 2; ++i)
//    {
//        if (i % 2)
//        {
//            arr[i / 2] = i;
//            cout << arr[i / 2] << ' ';
//        }
//    }

//    cout << endl << endl;

//    while (Contains(penalty_arr, size, 0))
//    {
//        int temp = rand() % size;

//        if (!Contains(penalty_arr, size, arr[temp]))
//        {
//            cout << arr[temp] << ' ';
//            *ppa++ = arr[temp];
//        }
//        else continue;
//    }

//    cout << endl;

//    return 0;
//}

// -1_14------------------------------------

////count <= max, of course
//int* MakeUniques(int min, int max, size_t count)
//{
//    if(count > max)
//    {
//        exit(1);
//    }

//    int* arr = new int[count];

//    for (int i = 0; i < count; ++i)
//    {
//        arr[i] = min + rand() % (max - min);

//        for (int j = 0; j < count; ++j)
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

//    for (int i = 0; i < size; ++i)
//        res[i] = pattern[rand() % strlen(pattern)];

//    //Security requirements
//    int* unique_indices = MakeUniques(0, size, 3);

//    res[unique_indices[0]] = 65 + rand() % 26;
//    res[unique_indices[1]] = 97 + rand() % 26;
//    res[unique_indices[2]] = 48 + rand() % 10;

//    res[size] = '\0';

//    return res;
//}

//int main(int argv, char* argc[])
//{
//    srand((unsigned int)time(0));

//    size_t size = 8;

//    do
//    {
//        system("cls");
//        cout << "Press any key to generate a password (Esc to exit):\n";

//        char* pw = GeneratePW(size);
//        //Using strlen(pw) as a loop limit causes extending of GeneratePW() return value.
//        //confused a little
//        for (int i = 0; i < size; ++i)
//        {
//            cout << pw[i];
//        }

//        cout << endl;
//    } while(getch() != 27);

//    return 0;
//}


// -1_16------------------------------------

//double DetOf3x3Array(int** arr)
//{
//   return ( arr[0][0]*(arr[1][1]*arr[2][2] - arr[1][2]*arr[2][1]) +
//            arr[0][1]*(arr[1][2]*arr[2][0] - arr[1][0]*arr[2][2]) +
//            arr[0][2]*(arr[1][0]*arr[2][1] - arr[1][1]*arr[2][0]));
//}

//int main(int argc, char *argv[])
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
//               char** f_names, char** s_names)
//{
//    //Academic department initialization
//    for (int i = 0; i < department_size; ++i)
//    {
//        *supervisors[i].name = '\0';
//        strcat(supervisors[i].name, f_names[rand() % 8]);
//        strcat(supervisors[i].name, " ");
//        strcat(supervisors[i].name, s_names[rand() % 8]);

//        supervisors[i].age = rand() % 30 + 32;
//        supervisors[i].salary = (rand() % 50 + 11) * 100;
//    }

//    //Group initialization
//    for (int i = 0; i < group_size; ++i)
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
//    for (int i = 0; i < group_size; ++i)
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


//int main(int argc, char *argv[])
//{
//    srand(size_t(time(0)));

//    char** f_names = new char*[8];
//    f_names[0] = new char[4]{"Bob"};
//    f_names[1] = new char[5]{"Bill"};
//    f_names[2] = new char[7]{"Javier"};
//    f_names[3] = new char[8]{"Matumba"};
//    f_names[4] = new char[9]{"Rudolphi"};
//    f_names[5] = new char[6]{"Uther"};
//    f_names[6] = new char[6]{"Jason"};
//    f_names[7] = new char[6]{"Peter"};

//    char** s_names = new char*[8];
//    s_names[0] = new char[6]{"Heinz"};
//    s_names[1] = new char[11]{"Guatebusto"};
//    s_names[2] = new char[6]{"Bowie"};
//    s_names[3] = new char[7]{"Bobson"};
//    s_names[4] = new char[6]{"Trump"};
//    s_names[5] = new char[9]{"McArthur"};
//    s_names[6] = new char[7]{"Cooper"};
//    s_names[7] = new char[6]{"Lee"};

//    size_t group_size = 8;
//    size_t department_size = 3;
//    float mean_gpa = 0;

//    student* group = new student[group_size];
//    professor* department = new professor[department_size];

//    InitFaculty(group, group_size, department, department_size, f_names, s_names);
//    PrintGroupFullInfo(group, group_size);

//    cout << "Mean GPA of group is ";

//    for (int i = 0; i < group_size; ++i)
//    {
//        mean_gpa += group[i].gpa;
//    }

//    mean_gpa /= group_size;
//    cout.precision(5);
//    cout << mean_gpa << endl;

//    student worst = group[0];
//    student best = group[0];

//    for (int i = 0; i < group_size - 1; ++i)
//    {
//        worst = group[i + 1].gpa < worst.gpa ? group[i + 1] : worst;
//        best = group[i + 1].gpa > best.gpa ? group[i + 1]: best;

//    }

//    cout << "The best student is " << best.name << " with " << best.gpa << "." << endl;
//    cout << "The worst student is " << worst.name << " with " << worst.gpa << "." << endl << endl;

//    size_t counter = 0;
//    cout << "Students whose supervisors are older than 50:" << endl;

//    for (int i = 0; i < group_size; ++i)
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

//    delete[] f_names;
//    delete[] s_names;
//    delete[] group;
//    delete[] department;

//    return 0;
//}

// -1_19------------------------------------

//template<typename T>
//void Map(vector<T>& container, void (*func)(T&))
//{
//    for (int i = 0; i < container.size(); ++i)
//    {
//        func(container[i]);
//    }
//}

//template<typename T>
//void Filter(vector<T>& container, bool (*pred)(T))
//{
//    vector<T> res_container(container.size());
//    size_t rc_index = 0;
//    for (int i = 0; i < container.size(); ++i) {
//        if(pred(container[i]))
//        {
//            res_container[rc_index++] = container[i];
//        }
//        else
//            continue;
//    }
//    res_container.resize(rc_index);
//    container = res_container;
//}

//template<typename T>
//void Reduce(vector<T>& container, T (*action)(T, T))
//{
//    size_t newsize = container.size();

//    while(newsize != 1)
//    {
//        container[0] = action(container[0], container[1]);
//        for (int i = 1; i < newsize - 1; ++i)
//        {
//            container[i] = container[i + 1];
//        }
//        newsize--;
//    }

//    container.resize(1);
//}

//template<typename T>
//void PrintArray(T arr)
//{
//    for (int i = 0; i < arr.size(); ++i)
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

//int main(int argv, char* argc[])
//{
//    vector<int> arr(15);

//    for (int i = 0; i < arr.size(); ++i)
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
