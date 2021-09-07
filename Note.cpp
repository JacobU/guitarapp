/*
 Note.cpp
 */


#include "Note.h"
#include <string>
using namespace std;

Note::Note(){
	Note::fret = -1;
	//Note::hammer_on = false;
	//Note::pull_off = false;
	//Note::slide = false;
	Note::feat = no_feature;

}

Note::Note(int _fret){
	Note::fret = _fret;
	Note::feat = no_feature;
	//Note::hammer_on = false;
	//Note::pull_off = false;
	//Note::slide = false;
}

Note::Note(int _fret, feature f){/*
	if(_hammer_on + _pull_off + _slide > 1){
		throw NoteException("Only one of the bool properties may be set to true");
	}
	Note::fret = _fret;
	Note::hammer_on = _hammer_on;
	Note::pull_off = _pull_off;
	Note::slide = _slide;*/

	Note::fret = _fret;
	Note::feat = f;

}


int Note::getFret() const{
	return Note::fret;
}

void Note::setFret(const int _fret){
	//To DO excption for illegal -1 -> 24
	if(_fret < -1 || fret > 25){
		throw NoteException("Valid fret range from -1 to 25");
	}
	Note::fret = _fret;

}

feature Note::getFeature() const{
	return Note::feat;
}

void Note::setFeature(const feature f){
	Note::feat = f;
}

void Note::cleanNote() {
	Note::setFret(-1);
	Note::setFeature(no_feature);
}
/*
void Note::setHammer_on(const bool _hammer_on){
	Note::hammer_on = _hammer_on;
}

bool Note::getHammer_on() const{
	return Note::hammer_on;
}

void Note::setPull_off(const bool _pull_off){
	Note::pull_off = _pull_off;
}
bool Note::getPull_off() const{
	return Note::pull_off;
}

void Note::setSlide(const bool _slide){
	Note::slide = _slide;
}
bool Note::getSlide() const{
	return Note::slide;
}

*/

ostream& operator<< (ostream& os, const Note& note){
	string str_rep = to_string(note.getFret());
	string str_rep2;

	feature f = note.getFeature();

	switch(f)
	{
	case no_feature: str_rep2 = ""; break;
	case hammer_on: str_rep2 = "h"; break;
	case pull_off: str_rep2 = "p"; break;
	case slide: str_rep2 = "s"; break;
	case palm_mute: str_rep2 = "m"; break;
	case harmonic: str_rep2 = "<"; break;
	case dead_note: str_rep2 = "d"; break;
	case bend: str_rep2 = "b"; break;
	case tap: str_rep2 = "t"; break;
	case trill: str_rep2 = "r"; break;
	case artificial_harmonic: str_rep2 = "a";break;
	}

	os << str_rep << str_rep2;
	return os;
}


NoteException::NoteException(const string& message): message(message) {}
string& NoteException::what() { return message; }
