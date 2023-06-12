//ANCUNA, HANZ JOSHUA V.
//BSCS-1C
#include <iostream>
#include <iomanip>
#include <fstream>
#define MAX 5
using namespace std;

class Student
{
private:
    string name[MAX];
    int q1[MAX],q2[MAX],q3[MAX];
    int last;
    bool isFull();
    bool isEmpty();
    int locate(string n);
    float avg(int a, int b, int c);
public:
    void initialize();
    void add(string n, int qz1, int qz2, int qz3);
    void del(string n);
    void display();
    void save();
    void load();
};

bool Student::isFull()
{
    return(last==MAX-1);
}

bool Student::isEmpty()
{
    return(last==-1);
}

int Student::locate(string n)
{
    for(int i=0;i<=last;i++)
    {
        if(name[i]==n)
            return i;
    }
    return -1;
}

void Student::initialize()
{
    last=-1;
}

float Student::avg(int a, int b, int c)
{
    return (a+b+c)/3.0;
}

void Student::add(string n, int qz1, int qz2, int qz3)
{
    if(isFull())
    {
        cout << "Array is full." << endl;
        system("pause");
    }
    else
    {
        last++;
        name[last]=n;
        q1[last]=qz1;
        q2[last]=qz2;
        q3[last]=qz3;
    }
}

void Student::del(string n)
{
    int p;
    if(isEmpty())
    {
        cout << "Array is empty." << endl;
    }
    else
    {
        p=locate(n);
        if(p<0)
        {
            cout << "Not found." << endl;
            system("pause");
        }
        else
        {
            for(int i=p;i<last;i++)
            {
                name[i]=name[i+1];
                q1[i]=q1[i+1];
                q2[i]=q2[i+1];
                q3[i]=q3[i+1];
            }
            last--;
        }
    }
}

void Student::display()
{
    int i;
    float ave;
    system("cls");
    cout << "    Name\tQuiz 1\tQuiz 2\tQuiz 3\tAverage\tRemarks" << endl;
    for(i=0;i<=last;i++)
    {
        ave=avg(q1[i],q2[i],q3[i]);
        cout<<i+1<<".) "<<name[i]<<" \t"<<q1[i]<<" \t"<<q2[i]<<" \t"<<q3[i]<<" \t"<<fixed<<setprecision(2)<<ave<<" \t";
        if(ave>=75)
        {
            cout << "PASSED" << endl;
        }
        else
        {
            cout << "FAILED" << endl;
        }
    }
    system("pause");
}

void Student::save()
{
    fstream fp;
    fp.open("bscsrec.dbf",ios::out);
    if(!fp)
    {
        cout << "File error.\n";
        system("pause");
    }
    else
    {
        for (int i=0;i<=last;i++)
        {
            fp << name[i] << endl << q1[i] << " " << q2[i] << " " << q3[i] <<endl;
        }
        fp.close();
    }
}

void Student::load()
{
    fstream fp;
    string nm;
    int qz1,qz2,qz3;
    fp.open("bscsrec.dbf",ios::in);
    if(!fp)
    {
        cout << "File error.\n";
        system("pause");
    }
    else
    {
        while(getline(fp,nm))
        {
            fp>>qz1>>qz2>>qz3;
            add(nm,qz1,qz2,qz3);
            fp.ignore();
        }
        fp.close();
    }
}

int main()
{
    Student rec;
    int choice;
    string nm;
    int a,b,c;
    rec.initialize();
    rec.load();
    while(1)
    {
        system("cls");
        cout << "\t\t\tSTUDENT RECORD OF BSCS" << endl << endl;
        cout << "\t1. Add Record" << endl;
        cout << "\t2. Delete Record" << endl;
        cout << "\t3. Display Record" << endl;
        cout << "\t4. Exit" << endl;
        cout << "\tInput choice : ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            system("cls");
            cout << "\t\t\tADD STUDENT RECORD OF BSCS" << endl << endl;
            cout << "\tInput name : ";
            cin >> nm;
            cout << "\tInput quiz 1 : ";
            cin >> a;
            cout << "\tInput quiz 2 : ";
            cin >> b;
            cout << "\tInput quiz 3 : ";
            cin >> c;
            rec.add(nm,a,b,c);
            break;
        case 2:
            system("cls");
            cout << "\t\t\tDELETE STUDENT RECORD OF BSCS" << endl << endl;
            cout << "Input name : ";
            cin >> nm;
            rec.del(nm);
            break;
        case 3:
            rec.display();
            break;
        case 4:
            rec.save();
            exit(0);
            break;
        }
    }
}
