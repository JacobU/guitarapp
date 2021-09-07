#include "Note.h"
#include "Chord.h"
#include <map>

class ChordData {
    
    public:
    void addChordToList(vector<int>, string);
    void addDefaultChords();
    map<string,Chord> defaultChordList;

    private:
    const int chordLength = 6;
};

