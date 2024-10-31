#include <iostream>
#include <string>

using namespace std;


struct Element {
    string imie;
    int priorytet;
};

class Kolejka {
protected:
    Element kolejka[10];
    short licznik = 0;
    Element bufor;


    bool czyPelna() {
        if (licznik == 10)
            return true;
        else
            return false;
    };

    bool czyPusta() {
        if (licznik == 0)
            return true;
        else
            return false;
    };
    void sort(){
        //??????
        for(int n=licznik-1; n>0; n--){
            if(kolejka[n].priorytet>kolejka[n-1].priorytet){
            bufor=kolejka[n];
            kolejka[n]=kolejka[n-1];
            kolejka[n-1]=bufor;
            }
        }
    };

public:
    bool dodajElement(Element element) {
        if (!czyPelna()) {
            kolejka[licznik] = element;
            licznik++;
            sort();                 //układanie elementów po priorytetach
            return true;
        };
        return false;
    };
    Element pobierzElement() {
        if (!czyPusta())
        {
            bufor = kolejka[0];
            for (int n = 0; n < licznik; n++)
                kolejka[n] = kolejka[n + 1];
                licznik--;
        }else{
            bufor.imie=""; bufor.priorytet=-1;
        }

    
    return bufor;
    };

    Element ktoPierwszy() {
        if (!czyPusta()) {
            return kolejka[0];
        }
        else {
            kolejka[0].imie = "";
            kolejka[0].priorytet = -1;
            return kolejka[0];
        };
    };

    void wypiszKolejke() {
        cout << "\n------- ELEMENTY KOLEJKI -------------------\n";
        for (int n = 0; n < licznik; n++) {
            cout << "{" << kolejka[n].imie << ", " << kolejka[n].priorytet << "} " ;
        }
        cout << "\n--------------------------------------------\n";
    }
};



int main() {

    Kolejka kolejka;
    short decyzja;
    Element element;
    do {
        kolejka.wypiszKolejke();
        cout << " 1 - dodaj Element\n 2 - zdejmij Element\n 3 - kto pierwszy w kolejce\n 0 - koniec \n\n?:";
        cin >> decyzja;
        if(decyzja==1){
            cout<<"Podaj imie: "; cin>>element.imie;
            cout<<"Podaj priorytet: "; cin>>element.priorytet;
            if(kolejka.dodajElement(element))
                cout<<"Element dodany\n";
                else
                cout<<"Brak miejsca\n";

        }
        if(decyzja==2){
                element=kolejka.pobierzElement();
                if(element.priorytet!=-1){
                    cout<<"Pobrany element to: {"<<element.imie<<", "<<element.priorytet<<"}\n";
                }
                else {
                    cout<<"Kolejka jest PUSTA!\n";
                }


        }
        if(decyzja==3){
                element=kolejka.ktoPierwszy();
                if(element.priorytet!=-1){
                    cout<<"Pierwszy element w kolejce to: {"<<element.imie<<", "<<element.priorytet<<"}\n";
                }
                else {
                    cout<<"Kolejka jest PUSTA!\n";
                }

        }

    } while (decyzja != 0);

    return 0;
}