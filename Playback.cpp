
#include "Playback.h"

Playback::Playback(Song s) {
    song = s;
    tempo = 0;
    playSong();
}

void Playback::playSong() {
    for (int i = 0; i < song.getNumberOfBars(); i++) {
        Bar currentBar = song.getBar(i);
        for (int j = 0; j < currentBar.getDiv(); j++) {
            Note n0 = currentBar.getNote(0, j);
            Note n1 = currentBar.getNote(0, j);
            Note n2 = currentBar.getNote(0, j);
            Note n3 = currentBar.getNote(0, j);
            Note n4 = currentBar.getNote(0, j);
            Note n5 = currentBar.getNote(0, j);

            //NEED FRAMEWORK TO PLAY .WAV FILES
            /*
             * playSound("0_" + n0.getFret() + ".wav"
             * playSound("1_" + n0.getFret() + ".wav"
             * playSound("2_" + n0.getFret() + ".wav"
             * playSound("3_" + n0.getFret() + ".wav"
             * playSound("4_" + n0.getFret() + ".wav"
             * playSound("5_" + n0.getFret() + ".wav"
             * */

        }
    }
}

int Playback::getTempo() const {
    return tempo;
}

void Playback::setTempo(const int newTempo) {
    tempo = newTempo;
}
