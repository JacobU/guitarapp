#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "Note.h"
#include "Bar.h"

using namespace std;

class Phrase{
    public:
        Phrase();
        Phrase(Bar, int, int);

        vector<vector<Note> > getNotes() const;
        vector<vector<Note> > getNotes(Bar bar) const;
        Note getNote(int string, int division) const;
        int getDivisions() const;
        int getNumStrings() const;
        Phrase& operator=(const Phrase&);
    private:
        vector<vector<Note> > notes;
        int divisions;
        int numStrings;
};

ostream& operator<< (ostream& os, const Phrase& p);

class PhraseException {
public:
    PhraseException(const string& message);
    string& what();
private:
    string message;
};