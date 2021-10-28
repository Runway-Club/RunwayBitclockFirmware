#ifndef SPEAKER_H
#define SPEAKER_H

#include <vector>
#include <Arduino.h>

using namespace std;

struct SpeakerNote
{
    int note;
    int duration;
};

struct Ringtone
{
    char *notes;
    int *beats;
    int tempo;
    int length;
};

class Speaker
{
protected:
    int pin;
    vector<vector<SpeakerNote>> soundLibrary;
    vector<Ringtone> ringtoneLibrary;

public:
    Speaker(int pin);
    void addSound(vector<SpeakerNote> *ringtone);
    void playAt(int index);
    void play(vector<SpeakerNote> *ringtone);
    void playNote(char note, int duration);
    void playTone(int tone, int duration);
    void addRingtone(Ringtone *ringtone);
    void playRingtone(Ringtone *ringtone);
    void playRingtoneAt(int index);
};

#endif
