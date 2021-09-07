
//

#include "Song.h"
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Playback{
public:
    Playback(Song s);
    int getTempo() const;
    void setTempo(const int newTempo);
    void playSong();
private:
    Song song;
    int tempo;
};