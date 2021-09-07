#include "ChordData.h"

#include <vector>
#include <string>

void ChordData::addChordToList(vector<int> _chord, string chordName) {
    vector<Note> chordVector; 
    for(int i = 0; i < chordLength; i++) {
        chordVector.push_back(Note(_chord[i]));
    }  
    Chord chord = Chord(chordVector);
    defaultChordList[chordName] = chord;
}

void ChordData::addDefaultChords() {
    //OPEN CHORDS
    addChordToList({-1,0,2,2,2,0}, "AM");
    addChordToList({-1,0,2,2,1,0}, "Am");
    addChordToList({-1,3,2,0,1,0}, "CM");
    addChordToList({-1,-1,0,2,3,2}, "DM");
    addChordToList({-1,-1,0,2,3,1}, "Dm");
    addChordToList({0,2,2,1,0,0}, "EM");
    addChordToList({0,2,2,0,0,0}, "Em");
    addChordToList({-1,-1,3,2,1,1}, "FM");
    addChordToList({3,2,0,0,3,3}, "GM");
    addChordToList({3,1,0,0,3,3}, "Gm");

    //BARRE CHORDS
    //Major 6-string
    addChordToList({1,3,3,2,1,1},"FMBar-6");
    addChordToList({2,4,4,3,2,2},"F#MBar-6");
    addChordToList({3,5,5,4,3,3},"GMBar-6");
    addChordToList({4,6,6,5,4,4},"G#MBar-6");
    addChordToList({5,7,7,6,5,5},"AMBar-6");
    addChordToList({6,8,8,7,6,6},"A#MBar-6");
    addChordToList({7,9,9,8,7,7},"BMBar-6");
    addChordToList({8,10,10,9,8,8},"CMBar-6");
    addChordToList({9,11,11,10,9,9},"C#MBar-6");
    addChordToList({10,12,12,11,10,10},"DMBar-6");
    addChordToList({11,13,13,12,11,11},"D#MBar-6");
    addChordToList({12,14,14,13,12,12},"EMBar-6");
    //Minor 6-string
    addChordToList({1,3,3,1,1,1},"FmBar-6");
    addChordToList({2,4,4,2,2,2},"F#mBar-6");
    addChordToList({3,5,5,3,3,3},"GmBar-6");
    addChordToList({4,6,6,4,4,4},"G#mBar-6");
    addChordToList({5,7,7,5,5,5},"AmBar-6");
    addChordToList({6,8,8,6,6,6},"A#mBar-6");
    addChordToList({7,9,9,7,7,7},"BmBar-6");
    addChordToList({8,10,10,8,8,8},"CmBar-6");
    addChordToList({9,11,11,9,9,9},"C#mBar-6");
    addChordToList({10,12,12,10,10,10},"DmBar-6");
    addChordToList({11,13,13,11,11,11},"D#mBar-6");
    addChordToList({12,14,14,12,12,12},"EmBar-6");
    //Major 5-string
    addChordToList({-1,1,3,3,3,1}, "A#MBar-5");
    addChordToList({-1,2,4,4,4,2}, "BMBar-5");
    addChordToList({-1,3,5,5,5,3}, "CMBar-5");
    addChordToList({-1,4,6,6,6,4}, "C#MBar-5");
    addChordToList({-1,5,7,7,7,5}, "DMBar-5");
    addChordToList({-1,6,8,8,8,6}, "D#MBar-5");
    addChordToList({-1,7,9,9,9,7}, "EMBar-5");
    addChordToList({-1,8,10,10,10,8}, "FMBar-5");
    addChordToList({-1,9,11,11,11,9}, "F#MBar-5");
    addChordToList({-1,10,12,12,12,10}, "GMBar-5");
    addChordToList({-1,11,13,13,13,11}, "G#MBar-5");
    addChordToList({-1,12,14,14,14,12}, "AMBar-5");
    //Minor 5-string
    addChordToList({-1,1,3,3,2,1}, "A#mBar-5");
    addChordToList({-1,2,4,4,3,2}, "BmBar-5");
    addChordToList({-1,3,5,5,4,3}, "CmBar-5");
    addChordToList({-1,4,6,6,5,4}, "C#mBar-5");
    addChordToList({-1,5,7,7,6,5}, "DmBar-5");
    addChordToList({-1,6,8,8,7,6}, "D#mBar-5");
    addChordToList({-1,7,9,9,8,7}, "EmBar-5");
    addChordToList({-1,8,10,10,9,8}, "FmBar-5");
    addChordToList({-1,9,11,11,10,9}, "F#mBar-5");
    addChordToList({-1,10,12,12,11,10}, "GmBar-5");
    addChordToList({-1,11,13,13,12,11}, "G#mBar-5");
    addChordToList({-1,12,14,14,13,12}, "AmBar-5");
}