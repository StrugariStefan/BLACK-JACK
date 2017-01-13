# BLACK-JACK
proiect IP
Succes

  Meniul principal contine cele 3 optiuni "Start" , "Reguli" si "Exit" . 
  "Start" incepe jocul .
  Urmatoarea decizie a player-ului consta in alegerea unui jucator nou , jucator caruia i se va aloca 1000 de credite , sau jucator deja existent in "memoria" jocului , primind numarul de credite memorat dupa terminarea unei sesiuni anterioare de joc a jucatorului respectiv . Dupa finalizarea acestui pas jucatorul intra in jocul propriu zis cu numarul corespunzator de credite .    Fiecare mana incepe cu plasarea pariului : jucatorul scrie de la tastatura suma dorita (0 < pariu <= credite) .
   Si jucatorul si dealer-ul primesc cate doua carti , una dintre cartile dealer-ului fiind "ascunsa" . In cazul in care cartea care nu este ascunsa a dealer-ului este as ('A') , jucatorul are posibilitatea de a face un "side bet" si anume "insurance bet" , acest bet valorand jumatate din pariul initial . 
  Urmatoarea decizie consta in alegerea uneia din urmatoarele optiuni : "Hit" , "Stand" , "Double down"(Op. conditionata) , "Split"(Op. conditionata) si "Surrender" .
  "Hit" va adauga o carte jucatorului :daca suma cartilor depaseste 21 , jocul va fi directionat catre meniu de sfarsit al mainii , altfel catre meniul anterior care , de data aceasta , nu va contine optiunile conditionate si nici optiunea "Surrender" .
  "Stand" reprezinta dorinta jucatorului de a ramane cu cartile pe care le detine , fara primirea unei alte carti de joc , si implica directionarea jocului catre meniu de sfarsit al mainii .
  "Double down" dubleaza pariul initial si adauga o singura carte la cartile jucatorului , ajungand ulterior la meniul de sfarsit . Aceasta optiune este posibila daca suma cartilor jucatorului este 9,10 sau 11 . 
  "Split" imparte mana jucatorului in doua maini independete una de cealalta , in care jucatorul face decizii asemanatoare cazului stas (respectiv "Hit" , "Stand" si "Double down") pentru fiecare dintre cele doua maini . Si de aceasta data pariul se dubleaza .
  "Surrender" ofera posibilitatea jucatorului de a renunta si , ca urmare , returneaza jucatorului jumatate din suma pariata , ajungand astfel la meniul de sfarsit al mainii .
  In cadrul meniului de sfarsit , jucatorul poate sa continue jocul sau sa se opreasca . Daca continua , atunci este directionat catre inceputul urmatoarei maini . Daca se opreste , numarul creditelor ramase va fi memorat impreuna cu numele acestuia si directionat catre meniul principal .
  "Reguli" afiseaza regulile dupa care se joaca jocul blackjack .
  "Exit" inchide jocul (mai exact , functia main returneaza 0) .
  Precizari:
  Fiecare optiune a jucatorului este identificata de o cifra . Jucatorul trebuie sa tasteze cifra corespunzatoare deciziei dorite de acesta ori de cate ori este pus in situatia unei alegeri . In cazul tastarii unor caractere care nu corespund , jocul "stagneaza" pana in momentul alegerii unei variante care face parte din multimea optiunilor disponibile .
  In cazul in care dublarea/marirea pariurilor implica depasirea numarului de credite atunci optiunile care duc la dublarea/marirea pariului nu sunt disponibile .
  In cazul in care jucatorul doreste sa aleaga un jucator nou , jucatorul este atentionat daca numele pe care il alege exista deja , acesta fiind nevoit sa schimbe acest nume .
  In cazul in care jucatorul doreste sa aleaga un jucator deja existent , jucatorul este atentionat daca numele pe care il alege nu exista in "memoria" jocului , acesta fiind nevoit sa schimbe numele ales .


