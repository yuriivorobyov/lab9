#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>

using namespace std;

#pragma pack(push, 1)

enum Speciality { ITIS, RE, KN, KI, PZ };
string speciality_str[] = { "����������� ",
                            "��������������", "����'����� �����",
                            "����'������ ��������", "��������� ������������" };

struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int grade_pedagogy;
    union
    {
        int grade_programming;
        int grade_numerical_methods;
    };
};

#pragma pack(pop)

void Create(Students* S, const int N);
void Print(Students* S, const int N);
int Find_Students(Students* S, const int N);
void Low_mark(Students* S, const int i, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    int i{};
    cout << "������ ������� ��������: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print(S, N);
    cout << "ʳ������ ��������, ������� ��� ���� ������ 4: " << setprecision(2) << Find_Students(S, N) << endl;
    Low_mark(S, i, N);
    return 0;
}
void Create(Students* S, const int N)
{
    int speciality;
    for (int i = 0; i < N; i++)
    {
        cout << "����� ��������: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "�������: "; getline(cin, S[i].surname); cout << endl;
        cout << "����: "; cin >> S[i].course; cout << endl;
        cout << "������������(0 - �����������, 1 - ��������������, 2 - ����'����� �����,";
        cout << "\n3 - ����'������ ��������, 4 - ��������� ������������): ";
        cin >> speciality;
        cout << "������ � ������: "; cin >> S[i].grade_physics;
        cout << "������ � ����������: "; cin >> S[i].grade_math;
        S[i].speciality = (Speciality)speciality;

        switch (S[i].speciality)
        {
        case KN:
            cout << "������ � �������������: "; cin >> S[i].grade_programming;
            break;
        case ITIS:
            cout << "������ � ��������� ������: "; cin >> S[i].grade_numerical_methods;
            break;
        default:
            cout << "������ � ���������: "; cin >> S[i].grade_pedagogy;
        }
        cout << endl;
    }
}
void Print(Students* S, const int N)
{
    cout << "==============================================================================================================================" << endl;
    cout << "|  �  |  �������  |  ����  |  ������������  |  Գ����  |  ����������  |  �������������  |";
    cout << "  ������� ������  |  ���������  |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(3) << S[i].surname << setw(3);
        cout << "|" << setw(4) << S[i].course << setw(4);
        cout << "|" << setw(3) << speciality_str[S[i].speciality] << setw(3);
        cout << "|" << setw(5) << S[i].grade_physics << setw(5);
        cout << "|" << setw(7) << S[i].grade_math << setw(7);
        switch (S[i].speciality)
        {
        case KN:
            cout << "|" << setw(7) << S[i].grade_programming << setw(7);
            cout << "|" << setw(7) << "-" << setw(7);
            cout << "|" << setw(7) << "-" << setw(7) << "|";
            break;
        case ITIS:
            cout << "|" << setw(8) << "-" << setw(8);
            cout << "|" << setw(8) << S[i].grade_numerical_methods << setw(8);
            cout << "|" << setw(8) << "-" << setw(8) << "|";
            break;
        default:
            cout << "|" << setw(7) << "-" << setw(7);
            cout << "|" << setw(8) << "-" << setw(8);
            cout << "|" << setw(7) << S[i].grade_pedagogy << setw(7) << "|";
        }
        cout << endl;
    }
    cout << "=========================================================================================================================" << endl;
}
void Low_mark(Students* S, const int i, const int N)
{
    float midMark1 = 0;
    for (int i = 0; i < N; i++)
        midMark1 = (S[i].grade_physics / N);

    float midMark2 = 0;
    for (int i = 0; i < N; i++)
        midMark2 = (S[i].grade_math / N);

    float midMark3 = 0;
    for (int i = 0; i < N; i++)
        midMark3 = (S[i].grade_programming / N);

    float midMark4 = 0;
    for (int i = 0; i < N; i++)
        midMark4 = (S[i].grade_numerical_methods / N);

    float midMark5 = 0;
    for (int i = 0; i < N; i++)
        midMark5 = (S[i].grade_pedagogy / N);

    if (midMark1 < midMark2 && midMark1 < midMark3 && midMark1 < midMark4 && midMark1 < midMark5)
        cout << "������" << midMark1 << endl;

    if (midMark2 < midMark1 && midMark2 < midMark3 && midMark2 < midMark4 && midMark2 < midMark5)
        cout << "����������" << midMark2 << endl;

    if (midMark3 < midMark2 && midMark3 < midMark1 && midMark3 < midMark4 && midMark3 < midMark5)
        cout << "�������������" << midMark3 << endl;

    if (midMark4 < midMark2 && midMark4 < midMark1 && midMark4 < midMark3 && midMark4 < midMark5)
        cout << "������� ������  " << midMark4 << endl;

    if (midMark5 < midMark1 && midMark5 < midMark2 && midMark5 < midMark3 && midMark5 < midMark4)
        cout << "���������  " << midMark5 << endl;
    return;
}

int Find_Students(Students* S, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (S[i].grade_physics < 4 || S[i].grade_math < 4 || S[i].grade_programming < 4 || S[i].grade_numerical_methods < 4 || S[i].grade_pedagogy < 4)
            k++;
    return k;
}
