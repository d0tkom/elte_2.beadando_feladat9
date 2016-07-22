#include "seqinfile.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

SeqInFile::SeqInFile(const string &fname)
{
    x.open(fname.c_str());
    if(x.fail()){
        cout << "Fajlnyitasi hiba!\n";
        exit(1);
    }
}

//A fuggveny beolvassa a sorokat egy fajbol adott ertekeknek.
//A belepesi es kilepesi idoket percek osszegekent menti el.
//
void SeqInFile::read()
{
    string str;
    getline(x,str);
    if ( !x.fail()) {
        st = norm;
        istringstream is(str);
        string temp;
        is >> temp;
        e.enter = atoi(temp.substr(0,2).c_str())*60;
        e.enter += atoi(temp.substr(3,5).c_str());
        is >> e.name;
        is >> e.id;
        is >> temp;
        if ( !is.fail()) {
            e.leave = atoi(temp.substr(0,2).c_str())*60;
            e.leave += atoi(temp.substr(3,5).c_str());
        }
        else {
            e.leave = -1;
        }

    } else st = abnorm;
}


