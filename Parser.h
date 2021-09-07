#pragma once

#include "Note.h"
#include <iostream>
#include <string>


/* The Parser class must take in a string input.
It should be able to take this string, and return a note with the correct attributes
It must be able to determine if the input is incorrect
*/
class Parser {

    private:
        bool checkValidInput(const string, const int);
        void parserSizeOne(Note&, const string, const int);
        void parserSizeTwo(Note&, const string, const int);
        void parserSizeThree(Note&, const string, const int);
        void setNoteAttribute(Note&, const char);
    public:
        Parser() {}

        Note parse(const string);
};

class ParseException{
    public:
        ParseException(const string& message);
        string& what();
    private:
        string message;
};