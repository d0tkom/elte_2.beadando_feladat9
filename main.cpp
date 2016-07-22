#include <iostream>
#include "seqinfile.h"

using namespace std;

bool felt_max(string &longest, string const &fajl);
void osszegzes(string const &fajl);

//A main fuggveny bekeri az input fajl nevet,
//es felteteles maximum kereses es
//osszefuzest egy fuggvenyben kombinalva
//visszadja a legtovabb benntartozkodo
//munkavallalo nevet, es hogy kik tartozkodnak
//meg benn, nevvel es id-val.
//be: string fajl
//ki: konzolra ir


int main()
{
    string fajl;
    cout << "Fajl neve: ";
    cin >> fajl;
    cout << endl;
    cout << "Akik meg benn vannak: " << endl;

    SeqInFile t(fajl.c_str());
    bool l=false;
    int max;
    string longest;
    t.First();
    while (!t.End()) {
        Worker e = t.Current();
        if (e.leave==-1) {
            cout << e.name << " " << e.id;
            cout << endl;
        }
        if ((e.leave!=-1) && l) {
            if ( (e.leave-e.enter) > max ) {
                max = e.leave-e.enter;
                longest = e.name;
            }
        }
        else if ((e.leave!=-1) && !l) {
            l = true;
            max = e.leave-e.enter;
            longest = e.name;
        }
        t.Next();
    }
    cout << endl << "Legtovabb tartazkodott benn: " << endl << longest;

    return 0;
}

