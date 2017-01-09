#include <iostream>
#include <string>

using namespace std;

class carte{
public:
    carte(string numarcarte,string suitacarte);
    string afisare() const;
    carte();
    int valoarecarte;
private:
    string numar;
    string suita;
};

carte::carte()
{

}

carte::carte(string numarcarte,string suitacarte)
{
    numar=numarcarte;
    suita=suitacarte;
}

string carte::afisare() const
{
    return (numar+suita);
}
