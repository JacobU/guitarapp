#pragma once

#include "Bar.h"

#include<vector>
#include<string>
#include<iostream>


using namespace std;

class Song {
	public:
		Song();
		Song(int timeSig);
		Song(int timeSig,int _numBars);
		//~Song();
		Song& operator=(const Song& right);

		void addTitle(string _title);
		string getTitle();

		vector<Bar> getSong() const;
		Bar getBar(int barNumber) const;
		void setBar(const int barNumber, Bar *bar);
		int getNumberOfBars() const;

		/*
		Use this bar in order to unit test Song
		Insert a fretValue that you want all notes in the bar to have
		*/
		Bar getCustomBar(int fretValue, int timeSig);

		/*
		Clean bar removes all notes from the bar (Note()::fret -> -1), but keeps the bar
		Exceptions are the same as deleteBar()
		*/
		void cleanBars(int barNumber, int numBars);
		/*
		Throw exception if: 
		- barNumber + numBars is greater than the total number of bars
		- barNumber is greater than the total number of bars
		If the number of bars the user attemps to delete is greater than the total number of bars,
		the function simply deletes as many as is possible
		*/
		void deleteBars(int barNumber, int numBars);
		void addBarsBefore(int barNumber, int numBars);
		void addBarsAfter(int barNumber, int numBars);
		void addBarsAtEnd(int numBars);
	
		vector<Bar> copyBars(int barNumber, int numBars);
		/*
		We have to decide whether pasteBars simple pastes over the top of another bar,
		or whether it pastes in between bars (leaving the rest of the song untouched)
		Currently I have implemented the easier version, which is just pasting on top of other bars.
		*/
		void pasteBars(int barNumber, vector<Bar> & barsToPaste);
		void pasteBar(int barNumber, Bar& bar);

	private:
		vector<Bar> song;
		int defaultNumBars = 8;
		int numBars;
		int timeSignature;
		string title;
};

ostream& operator<<(ostream& os, const Song& s);

class SongException {
	public:
		SongException(const string& message);
		string& what();
	private:
		string message;
};
