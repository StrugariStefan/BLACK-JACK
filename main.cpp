#include "ManadeBlackJack.h"
#include <fstream>
#include <cstring>

using namespace std;

fstream f("jucatori.txt");
fstream g("sumajucatori.txt");
char numeJucatori[20],nume[20];
int sumabani;
int sumab[100];
ManadeBlackJack manajucator,manadealer,primamanajucator,adouamanajucator;
int credite;
int pariu;
int pariu1,pariu2;

void afisarenormala()
{
    system("cls");
    cout<<"Credite:"<<credite<<endl;
    cout<<"Pariu:"<<pariu<<endl;
    cout<<"cartile dealerului"<<endl;
    manadealer.afisaremana();
    cout<<"cartile jucatorului"<<endl;
    manajucator.afisaremana();
}

void afisarecuocarteadealeruluiascunsa()
{
    system("cls");
    cout<<"Credite:"<<credite<<endl;
    cout<<"Pariu:"<<pariu<<endl;
    cout<<"cartile dealerului"<<endl;
    cout<<"?? "<<manadealer.cartileunuijucator[1].afisare();
    cout<<endl;
    cout<<endl;
    cout<<"cartile jucatorului"<<endl;
    manajucator.afisaremana();
}

void afisarenormalasplit()
{
    int i;
    system("cls");
    cout<<"Credite:"<<credite<<endl;
    cout<<"Pariu:"<<pariu1+pariu2<<endl;
    cout<<"cartile delerului"<<endl;
    manadealer.afisaremana();
    cout<<"cartile jucatorului"<<endl;
    for(i=0;i<=primamanajucator.nrcarti&&i<=adouamanajucator.nrcarti;i++)
        cout<<primamanajucator.cartileunuijucator[i].afisare()<<" "<<adouamanajucator.cartileunuijucator[i].afisare()<<endl;
    for(;i<=primamanajucator.nrcarti;i++)
        cout<<primamanajucator.cartileunuijucator[i].afisare()<<"   "<<endl;
    for(;i<=adouamanajucator.nrcarti;i++)
        cout<<"   "<<adouamanajucator.cartileunuijucator[i].afisare()<<endl;
    cout<<endl;
    cout<<endl;
}

void afisarecuocarteadealeruluiascunsasplit()
{
    int i;
    system("cls");
    cout<<"Credite:"<<credite<<endl;
    cout<<"Pariu:"<<pariu1+pariu2<<endl;
    cout<<"cartile dealerului"<<endl;
    cout<<"?? "<<manadealer.cartileunuijucator[1].afisare();
    cout<<endl;
    cout<<endl;
    cout<<"cartile jucatorului"<<endl;
    for(i=0;i<=primamanajucator.nrcarti&&i<=adouamanajucator.nrcarti;i++)
        cout<<primamanajucator.cartileunuijucator[i].afisare()<<" "<<adouamanajucator.cartileunuijucator[i].afisare()<<endl;
    for(;i<=primamanajucator.nrcarti;i++)
        cout<<primamanajucator.cartileunuijucator[i].afisare()<<"   "<<endl;
    for(;i<=adouamanajucator.nrcarti;i++)
        cout<<"   "<<adouamanajucator.cartileunuijucator[i].afisare()<<endl;
    cout<<endl;
    cout<<endl;
}

void manacastigata()
{
    credite+=pariu;
}

void manapierduta()
{
    credite-=pariu;
}

void blackjack()
{
    bool dublaj;
    bool split;
    bool surrender;
    credite=sumabani;
    inceputmana:
    system("cls");
    surrender=false;
    cout<<"Credite:"<<credite<<endl;
    cout<<"Plasati pariul"<<endl;
    cin>>pariu;
    if(pariu<=0||pariu>credite)
    {
        cout<<"Pariul nu este valid . Incercati din nou"<<endl;
        system("pause");
        goto inceputmana;
    }
    system("cls");
    pachet.amestecare();
    manajucator.initializaremana();
    manadealer.initializaremana();
    if(manadealer.cartileunuijucator[1].valoarecarte==10)
    {
        afisarecuocarteadealeruluiascunsa();
        if(manadealer.cartileunuijucator[0].valoarecarte==1)
        {
            if(manadealer.suma==manajucator.suma)
            {
                afisarenormala();
                cout<<"este egalitate"<<endl;
                manapierduta();
                system("pause");
            }
            else
            {
                afisarenormala();
                cout<<"ai pierdut"<<endl;
                manapierduta();
                system("pause");
            }
            goto sfarsitmana;
        }
        else
        {
            if(manajucator.suma==21)
            {
                afisarenormala();
                cout<<"BlackJack"<<endl;
                cout<<endl;
                cout<<"Ai castigat"<<endl;
                pariu=(pariu*3)/2;
                manacastigata();
                system("pause");
                goto sfarsitmana;
            }
            else
            {
                cout<<"dealerul nu are blackjack"<<endl;
                cout<<endl;
                system("pause");
                goto impartemanajucator;
            }
        }
    }
    if(manadealer.cartileunuijucator[1].valoarecarte==1)
    {
        insurance:
        afisarecuocarteadealeruluiascunsa();
        int decizie0;
        if(credite>=pariu+pariu/2)
        {
            cout<<"1.Insurence"<<endl;
            cout<<"2.Nu doresc sa fac insurence"<<endl;
            cin>>decizie0;
        }
        else
            decizie0=2;
        switch(decizie0)
        {
            case 1:
                if(manadealer.cartileunuijucator[0].valoarecarte==10)
                {
                    credite+=pariu/2;
                    if(manadealer.suma==manajucator.suma)
                    {
                        afisarenormala();
                        cout<<"este egalitate"<<endl;
                        system("pause");
                    }
                    else
                    {
                        afisarenormala();
                        cout<<"ai pierdut"<<endl;
                        manapierduta();
                        system("pause");
                    }
                    goto sfarsitmana;
                }
                else
                {
                    credite-=pariu/2;
                    cout<<"dealerul nu are blackjack"<<endl;
                    cout<<endl;
                    system("pause");
                    goto impartemanajucator;
                }
            case 2:
                if(manadealer.cartileunuijucator[0].valoarecarte==10)
                {
                    credite+=pariu/2;
                    if(manadealer.suma==manajucator.suma)
                    {
                        afisarenormala();
                        cout<<"este egalitate"<<endl;
                        system("pause");
                    }
                    else
                    {
                        afisarenormala();
                        cout<<"ai pierdut"<<endl;
                        manapierduta();
                        system("pause");
                    }
                    goto sfarsitmana;
                }
                else
                {
                    credite-=pariu/2;
                    cout<<"dealerul nu are blackjack"<<endl;
                    cout<<endl;
                    system("pause");
                    goto impartemanajucator;
                }
            default:
                cout<<"NU ati selectat una din optiunile disponibile"<<endl;
                system("pause");
                goto insurance;
        }
    }
    if(manajucator.suma==21)
    {
        afisarenormala();
        cout<<"BlackJack"<<endl;
        cout<<endl;
        cout<<"ai castigat"<<endl;
        pariu=(pariu*3)/2;
        manacastigata();
        system("pause");
        goto sfarsitmana;
    }
    impartemanajucator:
    afisarecuocarteadealeruluiascunsa();
    if(surrender==false)
    {
        cout<<"0.Surrender"<<endl;
        surrender=true;
    }
    cout<<"1.Hit"<<endl;
    cout<<"2.Stand"<<endl;
    if(manajucator.suma>=9&&manajucator.suma<=11&&pariu*2<=credite&&manajucator.nrcarti==1)
    {
        dublaj=true;
        cout<<"3.Double down"<<endl;
    }
    else
        dublaj=false;
    if(manajucator.cartileunuijucator[0].valoarecarte==manajucator.cartileunuijucator[1].valoarecarte&&pariu*2<=credite&&manajucator.nrcarti==1)
    {
        split=true;
        if(dublaj==false)
            cout<<"3.Split"<<endl;
        else
            cout<<"4.Split"<<endl;
    }
    else
        split=false;
    short decizie;
    cin>>decizie;
    if(split&&dublaj)
        switch(decizie)
        {
            case 0:
                pariu/=2;
                manapierduta();
                goto sfarsitmana;
            case 1:
                manajucator.primestecarte();
                goto verificaremanajucator;
            case 2:
                goto impartemanadealer;
            case 3:
                manajucator.primestecarte();
                pariu*=2;
                if(manajucator.suma>21)
                    manajucator.suma-=10;
                goto impartemanadealer;
            case 4:
                goto manasplit;
            default:
                cout<<"NU ati selectat una din optiunile disponibile"<<endl;
                system("pause");
                goto impartemanajucator;
    }
    else
        if(split)
            switch(decizie)
            {
                case 0:
                    pariu/=2;
                    manapierduta();
                    goto sfarsitmana;
                case 1:
                    manajucator.primestecarte();
                    goto verificaremanajucator;
                case 2:
                    goto impartemanadealer;
                case 3:
                    goto manasplit;
                default:
                    cout<<"NU ati selectat una din optiunile disponibile"<<endl;
                    system("pause");
                    goto impartemanajucator;
            }
        else
            if(dublaj)
                switch(decizie)
                {
                    case 0:
                        pariu/=2;
                        manapierduta();
                        goto sfarsitmana;
                    case 1:
                        manajucator.primestecarte();
                        goto verificaremanajucator;
                    case 2:
                        goto impartemanadealer;
                    case 3:
                        manajucator.primestecarte();
                        pariu*=2;
                        if(manajucator.suma>21)
                            manajucator.suma-=10;
                        goto impartemanadealer;
                    default:
                        cout<<"NU ati selectat una din optiunile disponibile"<<endl;
                        system("pause");
                        goto impartemanajucator;
                }
                else
                    switch(decizie)
                {
                    case 0:
                        pariu/=2;
                        manapierduta();
                        goto sfarsitmana;
                    case 1:
                        manajucator.primestecarte();
                        goto verificaremanajucator;
                    case 2:
                        goto impartemanadealer;
                    default:
                        cout<<"NU ati selectat una din optiunile disponibile"<<endl;
                        system("pause");
                        goto impartemanajucator;
                }
    verificaremanajucator:
    if(manajucator.suma>21)
    {
        if(manajucator.soft==true)
        {
            manajucator.suma-=10;
            manajucator.soft=false;
            goto impartemanajucator;
        }
        else
        {
            afisarenormala();
            cout<<"ai pierdut"<<endl;
            manapierduta();
            system("pause");
            goto sfarsitmana;
        }
    }
    else
        if(manajucator.suma==21)
            goto impartemanadealer;
        else
            goto impartemanajucator;
    impartemanadealer:
    while(manadealer.suma<17)
    {
        manadealer.primestecarte();
        if(manadealer.soft==true&&manadealer.suma>21)
        {
            manadealer.suma-=10;
            manadealer.soft=false;
        }
    }
    if(manadealer.suma>21)
    {
        afisarenormala();
        cout<<"ai castigat"<<endl;
        manacastigata();
        system("pause");
    }
    else
        if(manajucator.suma==manadealer.suma)
        {
            afisarenormala();
            cout<<"este egalitate"<<endl;
            system("pause");
        }
        else
            if(manajucator.suma<manadealer.suma)
            {
                afisarenormala();
                cout<<"ai pierdut"<<endl;
                manapierduta();
                system("pause");
            }
            else
            {
                afisarenormala();
                cout<<"ai castigat"<<endl;
                manacastigata();
                system("pause");
            }
    goto sfarsitmana;
    sfarsitmana:
    afisarenormala();
    if(credite==0)
    {
        cout<<"NU mai aveti credite"<<endl;
        credite=1000;
        system("pause");
        return;
    }
    cout<<"1.Vreau sa mai joc"<<endl;
    cout<<"2.Nu vreau sa mai joc"<<endl;
    int decizie2;
    cin>>decizie2;
    switch(decizie2)
    {
        case 1:
            goto inceputmana;
        case 2:
            return;
        default:
            cout<<"Nu ati selectata una din obtiunile disponibile , incercati din nou "<<endl;
            system("pause");
            goto sfarsitmana;
    }
    manasplit:
    primamanajucator.nrcarti=0;
    adouamanajucator.nrcarti=0;
    primamanajucator.cartileunuijucator[0]=manajucator.cartileunuijucator[0];
    adouamanajucator.cartileunuijucator[0]=manajucator.cartileunuijucator[1];
    primamanajucator.suma=primamanajucator.cartileunuijucator[0].valoarecarte;
    adouamanajucator.suma=adouamanajucator.cartileunuijucator[0].valoarecarte;
    pariu1=pariu2=pariu;
    bool mananr1=true;
    impartemanajucatorsplit:
    afisarecuocarteadealeruluiascunsasplit();
    if (mananr1)
    {
        afisarecuocarteadealeruluiascunsasplit();
        cout<<"Pentru prima mana :"<<endl;
        cout<<"1.Hit"<<endl;
        cout<<"2.Stand"<<endl;
        if((primamanajucator.suma==9||primamanajucator.suma==10)&&pariu1*2+pariu2<=credite&&primamanajucator.nrcarti==0)
        {
            cout<<"3.Double down"<<endl;
            dublaj=true;
        }
        else
            dublaj=false;
        int decizie1;
        cin>>decizie1;
        if(dublaj)
            switch(decizie1)
            {
                case 1:
                    primamanajucator.primestecarte();
                    goto verificareprimamana;
                case 2:
                    mananr1=false;
                    goto impartemanajucatorsplit;
                case 3:
                    primamanajucator.primestecarte();
                    pariu1*=2;
                    mananr1=false;
                    goto impartemanajucatorsplit;
                default:
                    cout<<"NU ati selectat una din optiunile disponibile"<<endl;
                    system("pause");
                    goto impartemanajucatorsplit;
            }
        else
            switch(decizie1)
        {
            case 1:
                primamanajucator.primestecarte();
                goto verificareprimamana;
            case 2:
                mananr1=false;
                goto impartemanajucatorsplit;
            default:
                cout<<"NU ati selectat una din optiunile disponibile"<<endl;
                system("pause");
                goto impartemanajucatorsplit;
        }
    }
    else
    {
        afisarecuocarteadealeruluiascunsasplit();
        cout<<"Pentru a doua mana :"<<endl;
        cout<<"1.Hit"<<endl;
        cout<<"2.Stand"<<endl;
        if((adouamanajucator.suma==9||adouamanajucator.suma==10)&&pariu2*2+pariu1<=credite&&adouamanajucator.nrcarti==0)
        {
            cout<<"3.Double down"<<endl;
            dublaj=true;
        }
        else
            dublaj=false;
        int decizie1;
        cin>>decizie1;
        if(dublaj)
        switch(decizie1)
        {
            case 1:
                adouamanajucator.primestecarte();
                goto verificareadouamana;
            case 2:
                goto impartemanadealersplit;
            case 3:
                adouamanajucator.primestecarte();
                pariu2*=2;
                goto impartemanadealersplit;
            default:
                cout<<"NU ati selectat una din optiunile disponibile"<<endl;
                system("pause");
                goto impartemanajucatorsplit;
        }
        else
            switch(decizie1)
        {
            case 1:
                adouamanajucator.primestecarte();
                goto verificareadouamana;
            case 2:
                goto impartemanadealersplit;
            default:
                cout<<"NU ati selectat una din optiunile disponibile"<<endl;
                system("pause");
                goto impartemanajucatorsplit;
        }
    }
    verificareprimamana:
    if(primamanajucator.suma>21)
    {
        if(primamanajucator.soft==true)
        {
            primamanajucator.suma-=10;
            primamanajucator.soft=false;
            goto impartemanajucatorsplit;
        }
        else
        {
            afisarenormalasplit();
            cout<<"Ai pierdut prima mana"<<endl;
            system("pause");
            mananr1=false;
        }
    }
    else
        if(primamanajucator.suma==21)
            mananr1=false;
    goto impartemanajucatorsplit;
    verificareadouamana:
    if(adouamanajucator.suma>21)
    {
        if(adouamanajucator.soft==true)
        {
            adouamanajucator.suma-=10;
            adouamanajucator.soft=false;
            goto impartemanajucatorsplit;
        }
        else
        {
            afisarenormalasplit();
            cout<<"Ai pierdut a doua mana"<<endl;
            system("pause");
            goto impartemanadealersplit;
        }
    }
    else
        if(adouamanajucator.suma==21)
            goto impartemanadealersplit;
        else
            goto impartemanajucatorsplit;
    impartemanadealersplit:
    if(primamanajucator.suma>21&&adouamanajucator.suma>21)
    {
        afisarenormalasplit();
        cout<<"Ai pierdut ambele maini"<<endl;
        credite=credite-pariu1-pariu2;
        system("pause");
    }
    else
    {
        while(manadealer.suma<17)
            manadealer.primestecarte();
        if(manadealer.suma<=21)
        {
        if(primamanajucator.suma<=21&&adouamanajucator.suma<=21)
        {
            if(manadealer.suma<primamanajucator.suma&&manadealer.suma<adouamanajucator.suma)
            {
                afisarenormalasplit();
                cout<<"Ai castigat ambele maini"<<endl;
                credite=credite+pariu1+pariu2;
                system("pause");
            }
            else
                if(manadealer.suma>primamanajucator.suma&&manadealer.suma>adouamanajucator.suma)
                {
                    afisarenormalasplit();
                    cout<<"Ai pierdut ambele maini"<<endl;
                    credite=credite-pariu1-pariu2;
                    system("pause");
                }
                else
                    if(manadealer.suma<primamanajucator.suma)
                    {
                        if(manadealer.suma==adouamanajucator.suma)
                        {
                            afisarenormalasplit();
                            cout<<"Ai castigat prima si egalitate la cea de a doua"<<endl;
                            credite=credite+pariu1;
                            system("pause");
                        }
                        else
                            if(manadealer.suma>adouamanajucator.suma)
                            {
                                afisarenormalasplit();
                                cout<<"Ai castigat prima si ai pierdut cea de a doua"<<endl;
                                credite=credite+pariu1-pariu2;
                                system("pause");
                            }
                    }
                    else
                        if(manadealer.suma>primamanajucator.suma)
                        {
                            if(manadealer.suma==adouamanajucator.suma)
                            {
                                afisarenormalasplit();
                                cout<<"Ai pierdut prima si egalitate la cea de a doua"<<endl;
                                credite=credite-pariu1;
                                system("pause");
                            }
                            else
                                if(manadealer.suma<adouamanajucator.suma)
                            {
                                afisarenormalasplit();
                                cout<<"Ai pierdut prima si ai castigat cea de a doua"<<endl;
                                credite=credite-pariu1+pariu2;
                                system("pause");
                            }
                        }
                        else
                        {
                            if(manadealer.suma==adouamanajucator.suma)
                            {
                                afisarenormalasplit();
                                cout<<"Ai egalitate la prima si egalitate la cea de a doua"<<endl;
                                system("pause");
                            }
                            else
                                if(manadealer.suma<adouamanajucator.suma)
                            {
                                afisarenormalasplit();
                                cout<<"Ai egalitate la prima si ai castigat cea de a doua"<<endl;
                                credite=credite+pariu2;
                                system("pause");
                            }
                            else
                            {
                                afisarenormalasplit();
                                cout<<"Ai egalitate la prima si ai pierdut cea de a doua"<<endl;
                                credite=credite-pariu2;
                                system("pause");
                            }
                        }
        }
        else
            if(primamanajucator.suma<=21)
        {
                if(manadealer.suma<primamanajucator.suma)
                {
                    afisarenormalasplit();
                    cout<<"Ai castigat prima si ai pierdut cea de a doua"<<endl;
                    credite=credite+pariu1-pariu2;
                    system("pause");
                }
                else
                    if(manadealer.suma==primamanajucator.suma)
                {
                    afisarenormalasplit();
                    cout<<"Ai egalitate la prima si ai pierdut cea de a doua"<<endl;
                    credite=credite-pariu2;
                    system("pause");
                }
                else
                {
                    afisarenormalasplit();
                    cout<<"Ai pierdut prima si ai pierdut cea de a doua"<<endl;
                    credite=credite-pariu1-pariu2;
                    system("pause");
                }
        }
        else
            if(adouamanajucator.suma<=21)
            {
            if(manadealer.suma<adouamanajucator.suma)
            {
                afisarenormalasplit();
                cout<<"Ai pierdut prima si ai castigat cea de a doua"<<endl;
                credite=credite-pariu1+pariu2;
                system("pause");
            }
            else
                if(manadealer.suma==adouamanajucator.suma)
            {
                afisarenormalasplit();
                cout<<"Ai pierdut prima si ai egalitate la cea de a doua"<<endl;
                credite=credite-pariu1;
                system("pause");
            }
            else
            {
                afisarenormalasplit();
                cout<<"Ai pierdut prima si ai pierdut cea de a doua"<<endl;
                credite=credite-pariu1-pariu2;
                system("pause");
            }
            }
        }
        else
            if(primamanajucator.suma<=21&&adouamanajucator.suma<=21)
            {
                afisarenormalasplit();
                cout<<"Ai castigat ambele maini"<<endl;
                credite=credite+pariu1+pariu2;
                system("pause");
            }
            else
                if(primamanajucator.suma<=21)
            {
                afisarenormalasplit();
                cout<<"Ai castigat prima si ai pierdut cea de a doua"<<endl;
                credite=credite+pariu1-pariu2;
                system("pause");
            }
            else
            {
                afisarenormalasplit();
                cout<<"Ai pierdut prima si ai castigat cea de a doua"<<endl;
                credite=credite-pariu1+pariu2;
                system("pause");
            }
    }
    sfarsitsplit:
    afisarenormalasplit();
    if(credite==0)
    {
        cout<<"NU mai aveti credite"<<endl;
        credite=1000;
        system("pause");
        return;
    }
    cout<<"1.Vreau sa mai joc"<<endl;
    cout<<"2.Nu vreau sa mai joc"<<endl;
    cin>>decizie2;
    switch(decizie2)
    {
        case 1:
            goto inceputmana;
        case 2:
            return;
        default:
            cout<<"NU ati selectat una din optiunile disponibile"<<endl;
            system("pause");
            goto sfarsitsplit;
    }
}

void salvaresumajucator(int k)
{
    int i;
    g.seekg(0,g.beg);
    for(i=0;i<=k-1;i++)
        g<<sumab[i]<<endl;
}

void alegerejucator()
{
    system("cls");
    int k=0;
    int decizieptnume;
    bool exista=false;
    f.seekg(0,f.end);
    int nrlinii=f.tellg();
    f.seekg(0,f.beg);
    if(nrlinii==2)
        decizieptnume=1;
    else
    {
        cout<<"1.Introduceti nume jucator nou"<<endl;
        cout<<"2.Introduceti nume jucator deja existent"<<endl;
        cin>>decizieptnume;
        cin.get();
    }
    switch(decizieptnume)
    {
        case 1:
            numenou:
            system("cls");
            cout<<"Scrieti numele jucatorului nou"<<endl;
            f.seekg(0,f.beg);
            g.seekg(0,g.beg);
            cin>>numeJucatori;
            cin.get();
            while(f>>nume)
                if(strcmp(nume,numeJucatori)==0)
                {
                    cout<<"Acest nume exista deja . Incercati din nou ."<<endl;
                    system("pause");
                    goto numenou;
                }
            f.clear();
            f.seekg(0,f.end);
            g.seekg(0,g.end);
            sumabani=1000;
            blackjack();
            f<<numeJucatori<<endl;
            g<<credite<<endl;
            return;
        case 2:
            numevechi:
            system("cls");
            char nume[20];
            k=0;
            f.seekg(0,f.beg);
            g.seekg(0,g.beg);
            cout<<"Scrieti numele jucatorului vechi"<<endl;
            cin>>nume;
            cin.get();
            while(f>>numeJucatori)
            {
                g>>sumab[k];
                if(strcmp(numeJucatori,nume)==0)
                {
                    sumabani=sumab[k];
                    blackjack();
                    sumab[k]=credite;
                    exista=true;
                }
                k++;
            }
            f.clear();
            if(exista==true)
                salvaresumajucator(k);
            else
            {
                cout<<"Numele pe care l-ati selectat nu exista . Incercati din nou "<<endl;
                system("pause");
                goto numevechi;
            }
            return;
        default:
            cout<<"NU ati selectat una din optiunile disponibile"<<endl;
            system("pause");
            alegerejucator();
    }
}

void reguli()
{
    system("cls");
    cout<<"Valoarea cartilor: cartile intre 2 si 10 au valoarea scrise pe ele, figurile au valoarea 10, asul poate fi 1 sau 11 dupa preferinta jucatorului."<<endl;

    cout<<"Derularea jocului: fiecare jucator primeste initial 2 carti ce vor fi afisate tuturor participantilor la joc. Dealer-ul (casa) va primi tot 2 carti, dintre care una cu fata in jos."<<endl;
    cout<<"Dupa impartire fiecare jucator are sansa de a avea suma cartilor 21, sau cat mai aproape dupa cum urmeaza."<<endl;

    cout<<"Decizia jucatorului: Dupa impartirea cartilor jucatorul poate alege între 4 optiuni standard: hit, stand, split, double down. La unele mese de joc, se poate apela si la optiunea surrender."<<endl;

    cout<<"HIT: mai iau o carte"<<endl;

    cout<<"STAND: nu mai iau carte"<<endl;

    cout<<"DOUBLE DOWN: dublez miza, iau doar o singura carte (se foloseste cand jucatorul este sigur ca suma finala este peste 19)"<<endl;

    cout<<"SPLIT: optiune folosita cand jucatorul are cele doua carti primite de aceeasi valoare, jucatorul formand cate o mana pe fiecare carte, cele 2 maini se joaca apoi dupa regulile standard"<<endl;

    cout<<"SURRENDER: se foloseste doar la unele mese de joc, jucatorul are posibilitatea de a se retrage dupa ce primeste cele doua carti, primind inapoi doar 1/2 din suma pariata.(se foloseste aceasta comanda in general cand jucatorul are suma cartilor primite 14 sau 15)"<<endl;

    cout<<"Decizia casei:"<<endl;

    cout<<"SOFT 17: Cand suma cartilor dealerului este sub 17, acesta trebuie sa mai traga o carte. Daca suma este 17 sau mai mare dealerul nu mai are voie la o alta carte."<<endl;

    cout<<"BLACKJACK: Daca un jucator are din impartirea cartilor suma 21 primeste de la casa (3:2)x valoarea pariului."<<endl;

    cout<<"INSURANCE: Cand casa are cartea cu fata in sus <as> atunci un jucator poate pune un insurance. Acest pariu verifica daca suma casei este de 21. Daca jucatorul castiga pariul el primeste 2x valoarea insurance-ului."<<endl;
    cout<<"Valoarea insurance-ului reprezinta jumatate din valoare pariului initial"<<endl;
}

int main()
{
    meniu:
    system("cls");
    cout<<"1.Start"<<endl;
    cout<<"2.Reguli"<<endl;
    cout<<"3.Exit"<<endl;
    int deciziedeinceput;
    cin>>deciziedeinceput;
    switch(deciziedeinceput)
    {
        case 1:
            alegerejucator();
            goto meniu;
        case 2:
            reguli();
            system("pause");
            goto meniu;
        case 3:
            return 0;
        default:
            cout<<"NU ati selectat una din optiunile disponibile"<<endl;
            system("pause");
            goto meniu;
    }
}

