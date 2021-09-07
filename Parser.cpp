#include "Parser.h"
#include <string>
#include <string.h>

using namespace std;

    /*
    Note features:  
    Harmonic:       <
    Pull-off:       p
    Hammer-on:      h
    Slide:          s
    Palm mute:      m
    Dead note:      d
    Bend:           b
    Tap:            t
    Trill:          r
    Artificial harmonic: a
    */

bool Parser::checkValidInput(const string input, const int length) {
    //Valid inputs range from 1-24
    //The max length of the string is 3, so check if string is longer than 3 first
    char features[] = "<phsmdbtra";
    //Check max length
    if(length > 3) return false;
    //Copy to a char array to check
    char inputAsChar[length];  // warning: variable-length arrays not support in msvc compiler, this is only for C99 compiler
    strcpy(inputAsChar, input.c_str());
    char * test;
    switch(length) {
        case 1:
        {
            //First char must be a digit
            if(!isdigit(inputAsChar[0])) return false;
            break;
        }
        case 2:
        {
            //Must have 1 digit...could be both digits or one digit/one char
            if(!isdigit(inputAsChar[0])) return false;
            if(isdigit(inputAsChar[1])) break;
            char noteFeature2 = inputAsChar[1];
            test = strchr(features, noteFeature2);
            if(test==NULL) return false;
            break;
        }
        case 3:
        {
            //If it is length 3, first two must be digits
            if(!isdigit(inputAsChar[0]) || !isdigit(inputAsChar[1])) return false;
            char noteFeature3 = inputAsChar[2];
            test = strchr(features, noteFeature3);
            if(test==NULL) return false;
            break;
        }
        default:
            break;
    }
    return true;
}

void Parser::parserSizeOne(Note & note, const string input, const int fret) {
    note.setFret(fret);
}

void Parser::parserSizeTwo(Note & note, const string input, const int fret) {
    //Could be 2 digits || 1 digit, 1 attribute
    //For 2 digits
    if(fret > 9) {
        note.setFret(fret);
    } else {
        note.setFret(fret);
        char attribute = input[1];
        setNoteAttribute(note, attribute);
    }
}

void Parser::parserSizeThree(Note & note, const string input, const int fret) {
    //Can only be a 2 digit num, and an attribute
    note.setFret(fret);
    char attribute = input[2];
    setNoteAttribute(note, attribute);
}

void Parser::setNoteAttribute(Note & note, const char attribute) {
    switch(attribute) {
            case 'h':
                note.setFeature(hammer_on);
                break;
            case 's':
                note.setFeature(slide);
                break;
            case 'p':
                note.setFeature(pull_off); 
                break;
            case '<':
                note.setFeature(harmonic);
                break;
            case 'm':
                note.setFeature(palm_mute);
                break;
            case 'd':
                note.setFeature(dead_note);
                break;
            case 'b':
                note.setFeature(bend);
                break;
            case 't':
                note.setFeature(tap);
                break;
            case 'r':
                note.setFeature(trill);
                break;
            case 'a':
                note.setFeature(artificial_harmonic);
                break;
            default:
                break;
        }
    //HAVE TO INCLUDE THE REST OF THE NOTE ATTRIBUTES HERE
}

Note Parser::parse(const string input) {
    int length = input.length();
    Note note;

    if(checkValidInput(input,length)) 
    { 
        int fret = stoi(input);
        if(fret < 1 || fret > 24) throw ParseException("Frets range only from 1-24");
        switch(length) {
            case 1:
                parserSizeOne(note, input, fret);
                break;
            case 2:
                parserSizeTwo(note, input, fret);
                break;
            case 3:
                parserSizeThree(note, input, fret);
                break;
            default:
                break;
        }
        return note;
    } 
    else 
    {
        throw ParseException("Input is invalid");
    }
}

ParseException::ParseException(const string& message): message(message) {}
string& ParseException::what() { return message; }
