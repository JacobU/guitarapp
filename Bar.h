#pragma once

#include "Note.h"
#include "Chord.h"
#include <iostream>
#include <vector>
using namespace std;

class Bar {
	private:
		int div;
		int numStrings = 6;
		int maxDiv = 32;

	public:
		vector<vector<Note>> barNotes;
		Bar();
		Bar(const int numDiv);
		//~Bar();
		Bar& operator=(const Bar& right);

		Note getNote(int string, int division) const;
		int getDiv() const;
		vector<vector<Note>> getBar() const;
		int getNumStrings() const;
		
		void addNote(const int string, const int division, Note targetNote);
		void addChord(int division, Chord targetChord);
		void increaseDiv();
		void cleanBar();
    friend bool operator==(const Bar& b1, const Bar& b2); // Equals overload for fractions

};

ostream& operator<< (ostream&, const Bar&);

class BarException {
	public:
		BarException(const string& message);
		string& what();
	private:
		string message;
};