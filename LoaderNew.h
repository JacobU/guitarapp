/*
 * Loader.h
 *
 */

#pragma once

#include "Song.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Parser.h"


class Loader {
	public:
		Loader(string _filename);
		void loadTitle(ifstream& inputFile, Song& song);
		void loadNumBars(ifstream& inputFile);
        Bar loadBar(ifstream& inputFile);		
		bool checkEnd(ifstream& inputFile);
		Song loadSong();
		virtual ~Loader();

	private:
		string filename;
		int numBars;
};


class LoaderException {
	public:
		LoaderException(const string& message);
		string& what();
	private:
		string message;
};

