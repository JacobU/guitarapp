/*
What are song txt file should look like:

Title: string
Numbars: int
                        //this will not really be a line space... just for clarity
Bar: int                //this repesents the start of the 1st bar
Divisions: int
-1,-1,-1,-1,-1,-1,-1,-1 //this CSL represents the 1st string
-1,2,-1,-1,-1,-1,-1,-1  //this CSL represents the 2nd string
...                     //etc

Bar: int 
Divisions: int          //this represents the start of the 2nd bar

...
...
                        //etc, etc


Bar:1,8
*/
#pragma once

#include "Song.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Save {
    public:
        Save(Song _song, string _filename);
        
        //Probably move these to private after testing
        void writeSong();
        void writeBar(const Bar& _bar, ofstream& tabFile);
        void writeNote(const Note& _note, ofstream& tabFile);
        
        void writeTitle(ofstream& tabFile);
        void writeNumBars(ofstream& tabFile);
        //Additional helper functions
        void writeBarNumber(int barNumber, ofstream& tabFile);
        void writeEnd(ofstream& tabFile);

    private:
        int numBars;
        string title;
        string filename;
        Song song;
};

class SaveException {
	public:
		SaveException(const string& message);
		string& what();
	private:
		string message;
};