#include "Bar.h"

//May still want a constructor for copy-paste i.e. full bar object.
//May want functions to interact with phrase objects

Bar::Bar() {
	div = 4;
	for(int i = 0; i < numStrings; i++) {
		vector<Note> tempVector;
		for(int j = 0; j < div; j++) {
			tempVector.push_back(Note());
		}
		barNotes.push_back(tempVector);
	}
}

Bar::Bar(int numDiv) {
	if(numDiv % 3 != 0 && numDiv % 4 != 0) throw BarException("Time signature is limit to 3/4 and 4/4");
	div = numDiv;
	for(int i = 0; i < numStrings; i++) {
		vector<Note> tempVector;
		for(int j = 0; j < div; j++) {
			tempVector.push_back(Note());
		}
		barNotes.push_back(tempVector);
	}
}

// Bar::~Bar() {

// }

Bar& Bar::operator=(const Bar& right) {
	div = right.div;
	numStrings = right.numStrings;
	maxDiv = right.maxDiv;
	barNotes = right.barNotes;
	return *this;
}

Note Bar::getNote(int string, int division) const {
	if ((division >= div) && (string >= numStrings)) {
		throw BarException("Target location not within bounds of the Bar");
	}
	return barNotes[string][division];
}	

int Bar::getDiv() const {
    return div;
}

vector<vector<Note> > Bar::getBar() const {
	return barNotes;
}

int Bar::getNumStrings() const {
	return numStrings;
}

void Bar::addNote(const int string, const int division, Note targetNote) {
	if ((division >= div) || (string >= numStrings)) {
		throw BarException("Target location not within bounds of the Bar");
	}
	barNotes[string][division] = targetNote;
}

void Bar::addChord(int division, Chord targetChord) {
	if (division > div) {
		throw BarException("Target location not within bounds of the Bar");
	}
	for(int i = 0; i < numStrings; i++) {
		barNotes[i][division] = targetChord.getChord()[i];
	}
}

void Bar::increaseDiv() {
	if(div >= 32) throw BarException("Already at the maximum number of divisions");
	int newDiv = div * 2;

	vector<vector<Note>> newBarNotes;
	for(int i = 0; i < numStrings; i++) {
		vector<Note> temp;
		for(int j = 0; j < newDiv; j++) {
			if((j % 2) == 0) temp.push_back(barNotes[i][j/2]); 
			else temp.push_back(Note());
		}
		newBarNotes.push_back(temp);
	}
	barNotes = newBarNotes;
	div = newDiv;
}

void Bar::cleanBar() {
	for(int i = 0; i < numStrings; i++) {
		for(int j = 0; j < div; j++) {
			barNotes[i][j].cleanNote();
		}
	}
}

ostream& operator<< (ostream& os, const Bar& _bar){
	
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < _bar.getDiv(); j++) {
			if(j < _bar.getDiv() - 1) os << _bar.getNote(i,j) << "\t";
			else os << _bar.getNote(i,j); 
		}
		os << endl;
	}
	return os;
}

bool operator==(const Bar& b1, const Bar& b2) {
    if (b1.getDiv() != b2.getDiv()) {
        return false;
    }
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < b1.getDiv(); j++) {
            if (b1.getNote(i, j).getFret() != b2.getNote(i, j).getFret() || b1.getNote(i, j).getFeature() != b2.getNote(i, j).getFeature()) {
                return false;
            }
        }
    }
    return true;
}

BarException::BarException(const string& message) : message(message) {}
string& BarException::what() {return message;}
