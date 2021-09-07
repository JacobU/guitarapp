#pragma once

#include "Note.h"
#include <iostream>

class Chord {
    
    private:
        int chordLength = 6;
        vector<Note> chord;

    public:
        Chord();
        Chord(vector<Note>);
        vector<Note> getChord() const;
        void changeNote(int, int);
};

//Overload the << operator for Chord
ostream& operator<< (ostream&, const Chord&);
