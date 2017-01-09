#include "CartideJoc.h"
#include <cstdlib>
#include <ctime>

using namespace std;

const int nrcartipachet=52;

class pachetdecarti{
public:
    pachetdecarti();
    void amestecare();
    carte dacarte();
private:
    carte *pachet;
    int carteacurenta;
};

pachetdecarti::pachetdecarti()
{
    char inima[2],romb[2],cruce[2],frunza[2];
    cruce[0]=5;
    cruce[1]=0;
    inima[0]=3;
    inima[1]=0;
    frunza[0]=6;
    frunza[1]=0;
    romb[0]=4;
    romb[1]=0;
    string numar[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    string suita[]={cruce,inima,frunza,romb};
    pachet=new carte[nrcartipachet];
    carteacurenta=0;
    int i;
    for(i=0;i<=nrcartipachet-1;i++)
    {
        pachet[i]=carte(numar[i%13],suita[i/13]);
        if(i%13<=8)
            pachet[i].valoarecarte=i%13+1;
        else
            pachet[i].valoarecarte=10;
    }
}

void pachetdecarti::amestecare()
{
    int i,j;
    carteacurenta=0;
    for(i=0;i<=nrcartipachet-1;i++)
    {
        j=(rand()+time(0))%nrcartipachet;
        carte aux;
        aux=pachet[i];
        pachet[i]=pachet[j];
        pachet[j]=aux;
    }
}

carte pachetdecarti::dacarte()
{
    if(carteacurenta>nrcartipachet)
        amestecare();
    if(carteacurenta<nrcartipachet)
        return (pachet[carteacurenta++]);
    return (pachet[0]);
}
