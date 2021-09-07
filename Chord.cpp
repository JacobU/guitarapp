#include "Chord.h"

void Chord::changeNote(int newFret, int stringNum) {
    //Note that the string numbers start from 0.
    //Lowest string = 0, Highest string = 5
    chord[stringNum] = Note(newFret);
}

vector<Note> Chord::getChord() const {
    return chord;
}

Chord::Chord() {
    for(int i = 0; i < chordLength; i++) {
        chord.push_back(Note());
    }
}

Chord::Chord(vector<Note> _chord) {
    for(int i = 0; i < chordLength; i++) {
        chord.push_back(_chord[i]);
    } 
}

ostream& operator<< (ostream& os, const Chord& _chord){
    vector<Note> chordToOuput = _chord.getChord();
    string output;
    output.append("[");
    for(int i = 0; i < 6; i++) {
        if(i < 5){
            string temp = to_string(chordToOuput[i].getFret());
            output.append(temp);
            output.append(",");
        } else { 
            string temp = to_string(chordToOuput[i].getFret());
            output.append(temp);
        }
    }
    output.append("]");
    os << output;
	return os;
}
