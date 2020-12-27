//в���� �
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

using namespace std;

#pragma pack(push, 1)

enum Speciality { IK, IT, KB, KI, PM };
string speciality_str[] = { "������������ - ����������� ������� �� �������㳿 ",
                            "����������� �������㳿", "����'������ ��������",
                            "ʳ����������", "��������� ����������" };

struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int computer_science;
};

#pragma pack(pop)

void Create(Students* S, const int N);
void  Low_mark(Students* S, const int i, const int N);
int Find_Students(Students* S, const int N);
void Print_1(Students* S, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    int i{};
    cout << "������ ������� ��������: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print_1(S, N);
    Low_mark(S, i, N);
    cout << "ʳ������ ��������, ������� ��� ���� ������ 4: " << setprecision(2) << Find_Students(S, N);

    return 0;
}
void Create(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        int speciality;
        cout << "����� ��������: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "������� ��������: "; getline(cin, S[i].surname); cout << endl;
        cout << "����: "; cin >> S[i].course; cout << endl;
        cout << "������������(1 - ������������ - ����������� ������� �� �������㳿, 2 - ����������� �������㳿, 3 - ����'������ ��������";
        cout << "\n4 - ʳ����������, 5 - ��������� ����������): ";
        cin >> speciality;
        S[i].speciality = (Speciality)speciality;
        cout << "������ � �����������: "; cin >> S[i].computer_science; cout << endl;
        cout << "������ � ������: "; cin >> S[i].grade_physics; cout << endl;
        cout << "������ � ����������: "; cin >> S[i].grade_math; cout << endl;

        cout << endl;
    }

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
        midMark3 = (S[i].computer_science / N);

    if (midMark1 < midMark2 && midMark1 < midMark3)
        cout << "������" << midMark1 << endl;
    if (midMark2 < midMark1 && midMark2 < midMark3)
        cout << "����������" << midMark2 << endl;
    if (midMark3 < midMark2 && midMark3 < midMark1)
        cout << "�����������" << midMark3 << endl;
    return;
}
void Print_1(Students* S, const int N)
{
    cout << "=========================================================================================" << endl;
    cout << "|  �  |  �������  |  ����  |  ������������  |  Գ����  |  ����������  |  �����������  |" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(4) << S[i].surname << setw(4);
        cout << "|" << setw(6) << S[i].course << setw(6);
        cout << "|" << setw(6) << speciality_str[S[i].speciality] << setw(6);
        cout << "|" << setw(6) << S[i].grade_physics << setw(6);
        cout << "|" << setw(6) << S[i].grade_math << setw(6);
        cout << "|" << setw(6) << S[i].computer_science << setw(6) << "|" << endl;
    }
    cout << "=========================================================================================" << endl << endl;
}

int Find_Students(Students* S, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (S[i].grade_physics < 4 || S[i].grade_math < 4 || S[i].computer_science < 4)
            k++;
    return k;
}