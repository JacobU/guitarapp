#include "Song.h"
using namespace std;

// accept one bar and push into the song vector
Song::Song() {
	//Create default song with 8 bars.
	timeSignature = 4; 
	for(int i = 0; i < defaultNumBars; i++) {
		song.push_back(Bar());
	}
}

Song::Song(int timeSig) {
	if(timeSig != 3 && timeSig !=4) throw SongException("Time signature must be either 3/4 or 4/4");
	timeSignature = timeSig;
	switch (timeSig)
	{
	case 3:
		for(int i = 0; i < defaultNumBars; i++) {
			song.push_back(Bar(3));
		}
		break;
	case 4:
		for(int i = 0; i < defaultNumBars; i++) {
			song.push_back(Bar());
		}
	default:
		break;
	}
}

Song::Song(int timeSig, int _numBars) {
	//Create song with variable number bars.
	timeSignature = timeSig;
	numBars = _numBars;
	for(int i = 0; i < numBars; i++) {
		song.push_back(Bar());
	}
}

Song& Song::operator=(const Song& right) {
	defaultNumBars = right.defaultNumBars;
	timeSignature = right.timeSignature;
	title = right.title;
	song = right.song;
	return *this;
}

void Song::addTitle(string _title) {
	title = _title;
}

string Song::getTitle() {
	return title;
}

vector<Bar> Song::getSong() const {
	return song;
}

Bar Song::getBar(int barNumber) const {
	return song[barNumber];
}

void Song::setBar(const int barNumber, Bar *bar){
	//calls assignment operator in bar. make sure to override
	cout << " the last note" << bar->barNotes[5][3] << endl;
	song[barNumber] = *bar;
	cout << " the last note for real" << song[barNumber].barNotes[5][3] << endl;

}

int Song::getNumberOfBars() const {
	return song.size();
}

Bar Song::getCustomBar(int fretValue, int timeSig) {
	Bar bar(timeSig);
	for(int i = 0; i < bar.getNumStrings(); i++) {
		for(int j = 0; j < bar.getDiv(); j++) {
			bar.barNotes[i][j].setFret(fretValue);
		}
	}
	return bar;
}

void Song::cleanBars(int barNumber, int numBars) {
	//Check for exceptions
	if(barNumber < 0 || barNumber >= getNumberOfBars()) throw SongException("Cannot clean bars that are out of range.");
	else if(numBars < 0) throw SongException("Cannot clean a negative number of bars.");
	else if(barNumber + numBars >= getNumberOfBars()) numBars = getNumberOfBars() - barNumber;	

	//Run through the numBars and clean them
	for(int i = 0; i < numBars; i++) {
		song[barNumber].cleanBar();
	}
}

void Song::deleteBars(int barNumber, int numBars) {
	//Check for exceptions
	if(barNumber < 0 || barNumber >= getNumberOfBars()) throw SongException("Cannot delete bars that are out of range.");
	else if(numBars < 0) throw SongException("Cannot delete a negative number of bars.");
	else if(barNumber + numBars >= getNumberOfBars()) numBars = getNumberOfBars() - barNumber;

	song.erase(song.begin()+barNumber, song.begin()+barNumber+numBars);
}

void Song::addBarsBefore(int barNumber, int numBars) {
	auto it = song.insert(song.begin() + barNumber - 1, numBars, Bar(timeSignature));
}

void Song::addBarsAfter(int barNumber, int numBars) {
	auto it = song.insert(song.begin() + barNumber, numBars, Bar(timeSignature));
}

void Song::addBarsAtEnd(int numBars) {
	auto it = song.insert(song.end(), numBars, Bar(timeSignature));
}

vector<Bar> Song::copyBars(int barNumber, int numBars) {
	
	if(barNumber < 0 || barNumber >= getNumberOfBars()) throw SongException("Cannot copy bars that are out of range.");
	else if(numBars < 0) throw SongException("Cannot copy a negative number of bars.");
	else if(barNumber + numBars >= getNumberOfBars()) numBars = getNumberOfBars() - barNumber;
	
	vector<Bar> temp;
	for(int i = 0; i < numBars; i++) {
		temp.push_back(song[barNumber + i]);
	}
	return temp;
} 

void Song::pasteBars(int barNumber, vector<Bar> & barsToPaste) {
	
	int numBars = barsToPaste.size();
	if(barNumber < 0 || barNumber >= getNumberOfBars()) throw SongException("You do not have enough space to paste these bars.");
	else if(numBars < 0) throw SongException("Cannot paste a negative number of bars.");
	else if(barNumber + numBars >= getNumberOfBars()) numBars = getNumberOfBars() - barNumber;
	
	for(int i = 0; i < numBars; i++) {
		song[barNumber + i] = barsToPaste[i];
	}
}

void Song::pasteBar(int barNumber, Bar& bar) {
	if(barNumber < 0 || barNumber >= getNumberOfBars()) throw SongException("You do not have enough space to paste these bars.");
	//cout << song[barNumber] << endl;
	song[barNumber] = bar;
	//cout << song[barNumber] << endl;
}

ostream& operator<<(ostream& os, const Song& p) {
	for(int i = 0; i < p.getNumberOfBars(); i++) {
		os << p.getBar(i) << endl;
	}
	return os;
}

SongException::SongException(const string& message) : message(message) {}
string& SongException::what() {return message;}
