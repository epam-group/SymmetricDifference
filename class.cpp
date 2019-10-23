#include <iostream>
#include <conio>
#include <string.h>
 
using namespace std;
//объявление класса "Множество":
template <class T>
class set
{
        private:
                T *a;
                int max_size;
                int size;
        public:
                //Конструкторы:
                set(int maxim);
                set(set <T> &x);
 
                //Деструктор:
                ~set();
 
                void add(T x);//добавление эл-та в мнохество
                void del(T x);//удаление эл-та из множества
                bool check_in(T x);//проверка вхождения эл-та в множество
                void output();//Вывод множества на экран
                set<T> operator= (const set <T> &s);//операция: присвоение одного множества другому
                set<T> operator* (const set <T> &s2);//операция: пересечение двух множеств
                set<T> operator+ (const set <T> &s2);//операция: объединение двух множеств
                set<T> operator- (set <T> s2);//операция: разность двух множеств
                friend bool operator== (set <T> s1, set <T> s2);//операция: сравнение двух множеств
};
 
string rus(char s[ ]);
void menu();
 
void main()
{
        setlocale(LC_ALL,"Russian");
        cout<<"Добро пожаловать в программу!"<<endl;
        menu();
}
 
 
void menu()
{
       char n;
       char choose;
       int max_1, max_2;
       cout<<"Введите максимальный размер первого множества: ";
       cin>>max_1;
       cout<<"Введите максимальный размер второго множества: ";
       cin>>max_2;
       set <int> set1(max_1);
       set <int> set2(max_2);
       set <int> set3(max_1+max_2);
       set <int> seta(max_1+max_2);
       set <int> setb(max_1+max_2);
 
       int x;
       do {
                cout<<'\n'
                        <<"Меню:"
                        <<'\n'<<"1. Добавление эл-та в множество"
                        <<'\n'<<"2. Удаление эл-та из множества"
                        <<'\n'<<"3. Проверка вхождения эл-та в множество"
                        <<'\n'<<"4. Присвоение одного множества другому"
                        <<'\n'<<"5. Пересечение двух множеств"
                        <<'\n'<<"6. Объединение двух множеств"
                        <<'\n'<<"7. Разность двух множеств"
                        <<'\n'<<"8. Симметрическая разность двух множеств"
                        <<'\n'<<"0. Выход"
                        <<'\n'<<"<";
                cin>>n;
                system("cls");
                switch(n)
                {
 
                case '1':cout<<"Выберете множество для добавления (1 или 2): ";
                                cin>>choose;
                                
                                if(choose=='1')
                                { 
                                        for (int i=0; i<max_1; i++)
                                        {
                                        cout<<"Введите э-т: ";
                                        cin>>x;
                                        set1.add(x);
                                        }
                                        cout<<"Получившееся множество 1"<<endl;
                                        set1.output();
                                        cout<<" "<<endl;
                                }
                                if(choose=='2')
                                {
                                        for (int i=0; i<max_2; i++)
                                        {
                                        cout<<"Введите э-т: ";
                                        cin>>x;
                                        set2.add(x);
                                        }
                                        cout<<"Получившееся множество 2"<<endl;
                                        set2.output();
                                        cout<<" "<<endl;
                                }
 
                                break;
                        case '2':cout<<"Выберете множество для удаления(1 или 2)"; //!!!
                                cin>>choose;
                                cout<<"Введите величину эл-та";
                                cin>>x;
                                if(choose=='1')
                                        set1.del(x);
 
                                if(choose=='2')
                                        set2.del(x);
                                break;
                        case '3':cout<<"Выберете множество для проверки(1 или 2)";
                                cin>>choose;
                                cout<<"Введите величину эл-та";
                                cin>>x;
                                if(choose=='1')
                                {
                                        if(set1.check_in(x))
                                                cout<<"Элемент содержится в данном множестве";
                                        else
                                                cout<<"Элемент не содержится в данном множестве";
                                }
                                if(choose=='2')
                                {
                                        if(set2.check_in(x))
                                                cout<<"Элемент содержится в данном множестве";
                                        else
                                                cout<<"Элемент не содержится в данном множестве";
                                        }
                                 break;
                        case '4':cout<<"Выберете в какое множество копировать(1 или 2)";
                                 cin>>choose;
                                 if(choose=='1')
                                         set1=set2;
                                 if(choose=='2')
                                         set2=set1;
                                 break;
                        case '5':set3=set1*set2;
                                 cout<<"Исходное множество 1"<<endl;
                                 set1.output();
                                 cout<<"Исходное множество 2"<<endl;
                                 set2.output();
                                 cout<<"Получившееся множество 3"<<endl;
                                 set3.output();
                                 cout<<" "<<endl;
                                 break;
                        case '6':set3=set1+set2;
                                 cout<<"Исходное множество 1"<<endl;
                                 set1.output();
                                 cout<<"Исходное множество 2"<<endl;
                                 set2.output();
                                 cout<<"Получившееся множество 3"<<endl;
                                 set3.output();
                                 cout<<" "<<endl;
                                 break;
                        case '7':cout<<"Выберете вычитаемое(1 или 2): ";
                                cin>>choose;
                                if(choose=='1')
                                        set3=set1-set2;
                                if(choose=='2')
                                        set3=set2-set1;
                                 
                                 cout<<"Исходное множество 1"<<endl;
                                 set1.output();
                                 cout<<"Исходное множество 2"<<endl;
                                 set2.output();
                                 cout<<"Получившееся множество 3"<<endl;
                                 set3.output();
                                 cout<<" "<<endl;
                                break;
 
                        case '8':
                                 seta=set1*set2;
                                 setb=set2*set1;
                                 set3=seta+setb;
 
                                 cout<<"Исходное множество 1"<<endl;
                                 set1.output();
                                 cout<<"Исходное множество 2"<<endl;
                                 set2.output();
                                 cout<<"Получившееся множество 3"<<endl;
                                 set3.output();
                                 cout<<" "<<endl;
                                break;
                        case '0':return;
                        default :cout<<"Действие не выбрано";
                }
           }
        while(true);
}
 
template <class T>
void set<T> ::add(T x)
{
        if(size<max_size)
        {
                if(!check_in(x))
                {
                        a[size]=x;
                        size+=1;
                        cout<<"Добавление прошло успешно"<<endl;
                }
                else
                {
                        cout<<"Добавление невозможно!!!"<<endl; 
                        cout<< "Одинаковые элементы содержаться в множестве только один раз!!!"<<endl;
                }
        }
        else
        {
                cout<<"Добавление невозможно"<<endl;
                cout<< "Размер множества не соответствует количеству элементов!!!"<<endl;
        }
}
 
 
template <class T>
void set <T>::del(T x)
{
        bool ok;
        ok=false;
        if(size!=0)
        {
                for(int i=0;i<size;i++)
                {
                        if(a[i]==x)
                        {
                                for(int j=i;j<size;j++)
                                {
                                        a[j]=a[j+1];
                                }
                                size-=1;
                                ok=true;;
                        }
 
                }
                if(ok)
                        cout<<"Удаление прошло успешно";
        }
        else
                cout<<"Удаление невозможно";
}
 
 
template <class T>
bool set <T>::check_in(T x)
{
        for(int i=0;i<size;i++)
                if(a[i]==x)
                        return true;
        return false;
}
 
 
 
template <class T>
void set<T>::output()
{
    if (max_size == 0)
    {
        cout << "{}";
        return;
    }
    cout << "{" << mass[0];
    for (int i = 1; i<max_size; i++)
        cout << ", " << mass[i];
    cout << "}" << endl;
 
}
 
 
 
template <class T>
set<T> set<T>:: operator* (const set <T> &s2)
{
        int k;
        k=0;
        set <T> s3(max_size);
        s3.size=0;
        for(int i=0;i<size;i++)
                for(int j=0;j<s2.size;j++)
                        if(s2.a[j]==a[i])
                        {
                                s3.a[k]=a[i];
                                k++;
                                s3.size+=1;
                        }
        return s3;
}
 
 
template <class T>
set<T> set<T>::operator+ (const set <T> &s2)
{
    Array <Ar> s3(size + s2.size);
    for (int i = 0; i < size; i++)
    {
        s3.mass[i] = mass[i];
    }
    for (int i = 0; i < s2.size; i++)
    {
        s3.check_in(s2.mass[i]);
 
        s3.mass[size + i] = s2.mass[i];
 
    }
    return s3;
}
 
 
template <class T>
set<T> set<T>::operator- (set <T> s2)
{
        set <T> s3(s2);
        for(int i=0;i<size;i++)
                for(int j=0;j<s2.size;j++)
                        if(a[i]==s2.a[j])
                                for(int k=i;k<s3.size;k++)
                                {
                                        s3.a[i]=s3.a[i+1];
                                        size-=1;
                                }
        return s2;                        
}
 
template <class T>
set<T> set<T>:: operator= (const set <T> &s)
{
        if(this==&s)
                return *this;
        if(max_size!=s.max_size)
        {
                delete []a;
                a=new T[s.max_size];
                size=0;
                max_size=s.max_size;
        }
        for(int i=0;i<max_size;i++)
        {
                a[i]=s.a[i];
        }
        size=s.size;
        return *this;
}
 
 
 
template <class T>
bool operator== (set <T> s1, set <T> s2)
{
        bool ok;
        ok=false;
        for(int i=0;i<s1.size;i++)
        {
                for(int j=0;j<s2.size;j++)
                        if(a[i]==a[j])
                                ok=true;
        }
        return ok;
}
 
 
 
template <class T>
set<T>:: set(int maxim)
{
        a=new T[maxim];
        for(int i=0;i<maxim;i++)
                a[i]=0;
        max_size=maxim;
        size=0;
}
 
 
template <class T>
set<T>::set(set<T> &x)
{
        max_size=x.max_size;
        a=new T[max_size];
        for(int i=0;i<max_size;i++)
                a[i]=x.a[i];
}
 
 
template <class T>
set<T>::~set()
{
        delete []a;
}