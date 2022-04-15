/*
Gra osadzona jest w średnowiecznym fantasy. Magowie uwięzili gracza - złoczyńscę w runicznym 
więzieniu. Aby kontynuwać gracz musi odcyfrować 10 run ze swojego więzienia i ustawić
je we właściwej kolejości.
*/
#include<iostream>
#include<ctime>
#include<string>
#include<sstream>
#include<random>

using namespace std;

int MaxLevel = 10; //maksymalny poziom gry
int RuneIndexs[3];
int Runes[9];
string runy[9];
int proby = 0;
char RuneA, RuneB, RuneC;
const char samogloski[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
const char spogloski[18] = {'b','c','d','f','g','h','j','k','l','m','n','p','r','s','t','w','x','z'};

int* ChooseRune(int Level){
    int RuneAIndex = (rand() % (2 * Level)) + 1;
    int RuneBIndex = (rand() % 6) + 1;
    int RuneCIndex = (rand() % (Level)) + 1;
    RuneA = spogloski[RuneAIndex-1];
    RuneB = samogloski[RuneBIndex-1];
    RuneC = spogloski[RuneCIndex-1];
    RuneIndexs[0] = RuneAIndex;
    RuneIndexs[1] = RuneBIndex;
    RuneIndexs[2] = RuneCIndex;
        //int *RuneINdexsptr = RuneIndexs;
    return RuneIndexs;
};

void PrintInstructions(int* RunesArray, int Level){
    int a = RunesArray[0];
    int b = RunesArray[1];
    int c = RunesArray[2];
    int Number = 100 * a + 10 * b + c;
    Runes[Level-1] = Number;
    ////////////////////////////////////////////////
    //cout << Number << endl;
////////////////////////////////////////////////
    int modSum = Number % (a + b + c);
    int modIl = Number % (a * b * c);
    cout << "Reszta z dzielenia Liczby odpowiadajacej tej runie przez sume cyfr tej liczby ("<< (a + b + c)<<") wynosi: " << modSum <<endl;
    cout << "Reszta z dzielenia Liczby odpowiadajacej tej runie przez iloczyn cyfr tej liczby ("<<(a*b*c)<< ") wynosi: " << modIl <<endl;
};

void MainGame(int Level)
{
    if(proby < 20)
    {
    proby++;
    if(Level == MaxLevel)
    {
        //rozgrywka, w któej trzeba ustwić wszystkie runy w odpowiedzniej kolejnośći
        sort(Runes, Runes + 9);
        string odp[9];
        int odpint[9];
        cout << "Aby zniszczyc wiezienie, musisz teraz podac wszystkie runy w kolejnosci od najmniejszej do najwiekszej" << endl;
        for (int i = 0; i < 9; i++)
        {
            cin >> odp[i];
            odpint[i] = stoi(odp[i]);
            if(Runes[i]==odpint[i]){

            }else{
            cout << "Niestety runa nie jest poprawna\n";
            cout << "" << endl;
            MainGame(Level); 
            }
        }
        cout << "Gratulacje! Udalo Ci sie uciec z wiezienia." << endl;
        exit(0);
    }
    else
    {
        char GuesA, GuesB, GuesC;
        //standardoa rozgrywka
        cout << "Otwierasz ksiazke na stronie nr " << Level;
        cout << ", gdzie znajduje sie opis runy, ktora widnieje na twoim wiezieniu:\n";
        PrintInstructions(ChooseRune(Level), Level);
        cout << samogloski << endl;
        cout << spogloski << endl;
        cin >> GuesA;
        cin >> GuesB;
        cin >> GuesC;
        
        if(GuesA == RuneA && GuesB == RuneB && GuesC == RuneC){
            cout << "gratulacje, runa jest poprawna!" << endl;
            cout << "" << endl;
            return;
        }else
        {
            cout << "Niestety runa nie jest poprawna\n";
            cout << "" << endl;
            MainGame(Level);
        }        
    }    
    }else{
        //przegrana
        cout << "Odgadywanie run zajelo Ci zbyt wile czasu. Magowie wrocili, a gdy zobaczyli co robisz, postanowili Cie usmiercic"<<endl;
        exit(0);
    }
    
};

int main()
{
    srand(time(NULL));
    int Level = 1; //aktualny poziom gry

    //wstawka na początek, wyświetlana 1 raz na początku gry
    cout << "Zostales uwizziony przez magow w runicznym wiezieniu..." << endl; 
    cout << "Wszyscy magowie odeszli sadzac, ze sie z niego nie wydostaniesz..." << endl;
    cout << "Czy maja racje? Widziales jak stawiaja to wiezienie i jestes pewien, ze udaloby ci sie je zniszczyc" << endl;
    cout << "Gdybys tylko znal runy, z ktorych powstalo...\n" << endl;

    cout << "Niespodziewanie zerwal sie wiatr i jego podmuch zrzucil z polki ksiazke, ktora wpadla do twojej klatki..." << endl;
    cout << "Bierzesz ja do reki i spostrzegasz, ze jest to podrecznik run..." << endl;
    cout << "Usmiechasz sie pod nosem. Coz za szczesliwy zbieg okolicznosci...\n" << endl;

    while(Level<=MaxLevel){
        MainGame(Level);
        cin.clear();
        cin.ignore();
        Level++;
    }
    //tu się dzieje rozgrywka

    return 0;
}

