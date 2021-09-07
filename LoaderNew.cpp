/*
 * LoaderNew.cpp
 *
 */

#include "LoaderNew.h"
#include <map>

Loader::Loader(string _filename){
	filename = _filename;
}

void Loader::loadTitle(ifstream& inputFile, Song& song) {
    string templine;
    getline(inputFile,templine);

    vector<string> tokens;
    stringstream ss(templine);
    string intermediate;
    while(getline(ss, intermediate, ',')) { 
        tokens.push_back(intermediate);
    }
    song.addTitle(tokens[1]);
}

void Loader::loadNumBars(ifstream& inputFile) {
    string templine;
    getline(inputFile, templine);

    vector<string> tokens;
    stringstream streamLine(templine);
    string intermediate;
    while(getline(streamLine, intermediate, ',')) { 
        tokens.push_back(intermediate);
    }
    numBars = stoi(tokens[1]);
}


Bar Loader::loadBar(ifstream& inputFile) {
    
    Parser p;
    
    string templine;
    getline(inputFile, templine);

    vector<string> tokens;
    stringstream ss(templine);
    string intermediate;
    while(getline(ss, intermediate, ',')) { 
        tokens.push_back(intermediate);
    }
    int numDivs = stoi(tokens[2]);
    //Bar* bar = new Bar(numDivs);
    Bar bar(numDivs);

    for(int i = 0; i < bar.getNumStrings(); i++) {
        tokens.clear();
        getline(inputFile, templine);

        stringstream ss1(templine);        
        int count = 0;
        while(getline(ss1, intermediate, ',')) {
            tokens.push_back(intermediate);
            Note tempNote;
            if(tokens[count] != "-1") {
                tempNote = p.parse(tokens[count]);
            } 
            bar.addNote(i,count,tempNote);
            count++;
        }
    }
    return bar;
}

bool Loader::checkEnd(ifstream& inputFile) {
    string templine;
    getline(inputFile, templine);
    if(templine == "End") return true;
    return false;
}

Song Loader::loadSong() {

	ifstream inputFile;
	inputFile.open(filename);

    //Song* song = new Song(4,0);
    Song song(4,0);

    //If file read is successful
    if(inputFile.is_open()) {
        loadTitle(inputFile, song);
        loadNumBars(inputFile);

        for(int i = 0; i < numBars; i++) {
            Bar tempBar = loadBar(inputFile);
            song.addBarsAtEnd(1);
            song.pasteBar(i,tempBar);
        }
        if(checkEnd(inputFile)) cout << "Loaded correctly" << endl;
        else cout << "Loaded incorrectly" << endl;
    }
    //Otherwise exit
    else {
        cout << "Could not open file\n";
    }
    return song;
}

Loader::~Loader() {
	// TODO Auto-generated destructor stub
}


LoaderException::LoaderException(const string& message) : message(message) {}
string& LoaderException::what() {return message;}
