#ifndef SEQINFILE_H
#define SEQINFILE_H

#include <fstream>

using namespace std;

struct Worker{
    string name, id;
    int enter, leave;
};

enum Status{abnorm, norm};

class SeqInFile
{
    public:
        SeqInFile(const string &fname);
        void First() { read();}
        void Next()  { read();}
        Worker Current() const { return e; }
        bool End() const { return abnorm==st; }
    private:
        ifstream x;
        Worker e;
        Status st;

        void read();
};

#endif // SEQINFILE_H
