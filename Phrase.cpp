// Phrase class

#include "Note.h"
#include "Phrase.h"
#include "Bar.h"
#include <math.h>

using namespace std;

Phrase::Phrase() {
    divisions = 1;
    numStrings = 6;
    for(int i = 0; i < numStrings; i++) {
        vector<Note> tempVector;
        for(int j = 0; j < divisions; j++) {
            tempVector.push_back(Note());
        }
        notes.push_back(tempVector);
    }
}

Phrase::Phrase(Bar bar, int start, int length) {
    numStrings = 6;
    if ((start >= bar.getDiv()) || (start+length >= bar.getDiv())) {
        throw PhraseException("Target location not within bounds of the Phrase");
    }
    for (int i = 0; i < numStrings; i++) {
        vector<Note> tempVector;
        for (int j = 0; j < length; j++) {
            tempVector.push_back(bar.getBar()[i][j+start]);
        }
        notes.push_back(tempVector);
    }
    divisions = bar.getDiv();
}

vector<vector<Note> > Phrase::getNotes() const {
    return notes;
}
vector<vector<Note> > Phrase::getNotes(Bar bar) const {
    if (divisions < bar.getDiv()) {
        int multiplier = bar.getDiv() / divisions;
        vector<vector<Note> > newNotes;
        for (int i = 0; i < numStrings; i++) {
            vector<Note> tempVector;
            for (int j = 0; j < notes[0].size(); j++) {
                tempVector.push_back(notes[i][j]);
                if (j < notes[0].size() - 1) {
                    for (int k = 0; k < multiplier-1; k++) {
                        tempVector.push_back(Note());
                    }
                }
            }
            newNotes.push_back(tempVector);
        }
        return newNotes;
    }
    else if (divisions > bar.getDiv()) {
        int multiplier = log2(divisions / bar.getDiv());
        for (int i = 0; i < multiplier; ++i) {
            bar.increaseDiv();
        }

        return notes;
    }
    else {
        return notes;
    }
}
Note Phrase::getNote(int string, int division) const {
    if ((division >= divisions) && (string >= numStrings)) {
        throw PhraseException("Target location not within bounds of the Phrase");
    }
    return notes[string][division];
}

int Phrase::getDivisions() const {
    return divisions;
}

int Phrase::getNumStrings() const {
    return numStrings;
}

Phrase& Phrase::operator=(const Phrase& right) {
    if (this != &right) {
        divisions = right.getDivisions();
        numStrings = right.getNumStrings();
        notes = right.getNotes();
    }
    return *this;
}

ostream& operator<< (ostream& os, const Phrase& p){
    vector<vector<Note> > notes = p.getNotes();
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < notes[0].size(); j++) {
            int fret = notes[i][j].getFret();
            if (fret == -1) {
                os << "- ";
            }
            else {
                os << notes[i][j] << " ";
            }
        }
        os << endl;
    }
    return os;
}

PhraseException::PhraseException(const string& message) : message(message) {}
string& PhraseException::what() {return message;}
