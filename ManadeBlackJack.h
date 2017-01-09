#include "PachetdeCarti.h"

using namespace std;

pachetdecarti pachet;
class ManadeBlackJack{
    public:
        carte cartileunuijucator[11];
        bool soft;
        int suma;
        int nrcarti;
        void primestecarte();
        void initializaremana();
        void afisaremana();
};

void ManadeBlackJack::primestecarte()
{
    this->nrcarti++;
    this->cartileunuijucator[this->nrcarti]=pachet.dacarte();
    this->suma+=this->cartileunuijucator[this->nrcarti].valoarecarte;
    if(this->cartileunuijucator[this->nrcarti].valoarecarte==1&&this->soft==false)
    {
        this->soft=true;
        this->suma+=10;
    }
}

void ManadeBlackJack::initializaremana()
{
    this->nrcarti=1;
    this->cartileunuijucator[0]=pachet.dacarte();
    this->cartileunuijucator[1]=pachet.dacarte();
    this->suma=this->cartileunuijucator[0].valoarecarte+this->cartileunuijucator[1].valoarecarte;
    if(this->cartileunuijucator[0].valoarecarte==1||this->cartileunuijucator[1].valoarecarte==1)
    {
        this->soft=true;
        this->suma+=10;
    }
    else
        this->soft=false;
}
void ManadeBlackJack::afisaremana()
{
    int i;
    for(i=0;i<=this->nrcarti;i++)
        cout<<this->cartileunuijucator[i].afisare()<<" ";
    cout<<endl;
    cout<<endl;
}
