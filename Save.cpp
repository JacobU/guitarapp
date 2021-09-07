#include "Save.h"
#include <stdlib.h>

using namespace std;

Save::Save(Song _song, string _filename) {
    //possible open a file with filename??
    filename = _filename;
    numBars = _song.getNumberOfBars();
    title = _song.getTitle();
    song = _song;
}

void Save::writeSong() {
    
    ofstream tabFile;
    tabFile.open(filename);
    
    writeTitle(tabFile);
    writeNumBars(tabFile);

    for(int i = 0; i < numBars; i++) {
        //Write 
        Bar tempbar = song.getBar(i);
        int numDivisions = tempbar.getDiv();
        
        writeBarNumber(i, tabFile);    
        //writeDivisions(numDivisions, tabFile);
        writeBar(tempbar, tabFile);        
    }

    writeEnd(tabFile);
}

void Save::writeBar(const Bar& bar, ofstream& tabFile) {
    if(tabFile.is_open()) {
        for(int i = 0; i < bar.getNumStrings(); i++) {
            for(int j = 0; j < bar.getDiv(); j++) {
                if(j < bar.getDiv() - 1) {
                    writeNote(bar.getNote(i,j), tabFile);
                    tabFile << ",";
                } else writeNote(bar.getNote(i,j),tabFile);
            }
            tabFile << "\n";
        }
    } else throw SaveException("File was unexpectedly closed during writing.");
}

void Save::writeNote(const Note& _note, ofstream& tabFile) {
    if(tabFile.is_open()) {
        tabFile << _note;
    } else throw SaveException("File was unexpectedly closed during writing.");
}

void Save::writeTitle(ofstream& tabFile) {
    if(tabFile.is_open()) {
        string titleOutput = "Title,";
        titleOutput.append(title);

        tabFile << titleOutput << "\n";
    } else throw SaveException("File was unexpectedly closed during writing.");
    
}

void Save::writeNumBars(ofstream& tabFile) {
    if(tabFile) {
        string numBarsOutput = "Bars,";
        string temp = to_string(song.getNumberOfBars());
        numBarsOutput.append(temp);
        
        tabFile << numBarsOutput << "\n";
    } else throw SaveException("File was unexpectedly closed during writing.");
}

void Save::writeBarNumber(int barNumber, ofstream& tabFile) {
    if(tabFile.is_open()) {
        string barDivOutput = "Bar,";
        string temp1 = to_string(barNumber);
        barDivOutput.append(temp1);
        barDivOutput.append(",");
        string temp2 = to_string(song.getBar(barNumber).getDiv());
        barDivOutput.append(temp2);

        tabFile << barDivOutput << "\n";
    } else throw SaveException("File was unexpectedly closed during writing.");
}

void Save::writeEnd(ofstream& tabFile) {
    if(tabFile.is_open()) {
        tabFile << "End";
    } else throw SaveException("File was unexpectedly closed during writing.");
}

SaveException::SaveException(const string& message) : message(message) {}
string& SaveException::what() {return message;}