#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;

//Да се дефинира класата Kvadrat во која што се чува информација за:
//
//должината на страната а на квадратот (double)

class Kvadrat{
protected:
    double length;
    void copyKvadrat(const Kvadrat &k){
        this->length=k.length;
    }
public:
    Kvadrat(){
        length=0;
    }

    Kvadrat(double length){
        this->length=length;
    }
    Kvadrat(const Kvadrat &k){
        copyKvadrat(k);
    }

    double perimetar(){
        return length*4;
    }

  double plostina(){
        return length*length;
    }

    void pecati(){
        cout<<"Length: "<<length<<" Perimeter: "<<perimetar()<<" Area: "<<plostina()<<endl;
    }


    ~Kvadrat(){}

//    должината на страната а на квадратот (double)
//    За класата да се дефинираат:
//
//    default конструктор
//            конструктор со аргументи
//    copy конструктор
//    double perimetar () што пресметува периметар на квадратот
//    double plostina () што пресметува плоштина на квадратот
//    void pecati () што печати информации за квадратот како во тест примерите
//            Да се имплементира класа Pravoagolnik што наследува од класата Kvadrat. Во неа се чуваат дополнителни информации за:

};

//проширувањето x на двете паралелни страни на квадратот (double)
//проширувањето у на другите две паралелни страни (double)


class Pravoagolnik :public Kvadrat{
private:
    double x,y;
   void copyPravoagolnik(const Pravoagolnik &p){
        this->x=p.x;
        this->y=p.y;
    }
public:
    Pravoagolnik(){
        x=0;
        y=0;
    }
    Pravoagolnik(const Kvadrat &k, double x, double y):Kvadrat(length){
        this->x=x;
        this->y=y;
    }



    //Правоаголникот всушност сега ќе има 2 страни со должина a+x и две страни со должина a+y

    double perimetar(){
       if(x==y){
           length+=x;
           return Kvadrat::perimetar();
       } else{
           return 2 * (x + length) + 2 * (y + length);
       }
   }

   double plostina(){
       if(x==y){
           length+=x;
           return Kvadrat::plostina();
       } else{
           return (x + length) * (y + length);
       }
   }

   void pecati(){
       if (x == y)
       {
           length += x;
           Kvadrat::pecati();
       }
       else
       {
           cout << "Pravoagolnik so strani: " << length + x << " i " << length + y << " ima plostina P=" << plostina()
                << " i perimetar L=" << perimetar() << endl;
       }
   }

//    Ако x и y се исти, тогаш формата не е правоаголник туку е повторно квадрат. Во тој случај pecati() се повикува исто како за квадрат.
//    При препокривање на методите во класата Pravoagolnik мора да има повик кон истоимените методи од класата Kvadrat



//    default конструктор
//            конструктор Pravoagolnik (const Kvadrat &k, double x, double y)
//    copy конструктор
//    Да се препокријат трите методи дефинирани погоре за класата Kvadrat.

};



int main()
{
    int n;
    double a, x, y;
    Kvadrat *kvadrati;
    Pravoagolnik *pravoagolnici;

    cin >> n;

    kvadrati = new Kvadrat[n];
    pravoagolnici = new Pravoagolnik[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a;

        kvadrati[i] = Kvadrat(a);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;

        pravoagolnici[i] = Pravoagolnik(kvadrati[i], x, y);
    }

    int testCase;
    cin >> testCase;

    if (testCase == 1)
    {
        cout << "===Testiranje na klasata Kvadrat===" << endl;
        for (int i = 0; i < n; i++)
            kvadrati[i].pecati();
    }
    else
    {
        cout << "===Testiranje na klasata Pravoagolnik===" << endl;
        for (int i = 0; i < n; i++)
            pravoagolnici[i].pecati();
    }
}