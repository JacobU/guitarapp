/*
 * Note.h
 *
 */

#pragma once

#include <vector>
#include <string>
#include <iostream>
using namespace std;

enum feature {
		no_feature,
		hammer_on,
		pull_off,
		slide,
		palm_mute,
		harmonic,
		dead_note,
		bend,
		tap,
		trill,
		artificial_harmonic,
	};


class Note{
public:
	Note();
	Note(int);
	//Note(int,bool,bool,bool);
	Note(int, feature);


	int getFret() const;
	void setFret(const int);

	feature getFeature() const;
	void setFeature(const feature);

	void cleanNote();

	/**
	int getFret() const;
	void setFret(const int);

	void setHammer_on(const bool);
	bool getHammer_on() const;

	void setPull_off(const bool);
	bool getPull_off() const;

	void setSlide(const bool);
	bool getSlide() const;

	void setPalm_mute(const bool);
	bool getPalm_mute() const;

	void setHarmonic(const bool);
	bool getHarmonic() const;

	void setDead_note(const bool);
	bool getDead_note() const;

	void setBend(const bool);
	bool getBend() const;
	*/
private:
	int fret;

	feature feat;
	//bool hammer_on;
	//bool pull_off;
	//bool slide;
	//bool palm_mute;
	//bool harmonic;
	//bool dead_note;
	//bool bend;
	//bool tap;
	//bool trill;
	//bool artificial_harmonic;
};

//Non-member function for insertion operator overloading.
ostream& operator<< (ostream& os, const Note& frac);

class NoteException{
public:
	NoteException(const string& message);
	string& what();
private:
	string message;
};
