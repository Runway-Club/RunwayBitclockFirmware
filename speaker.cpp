#include "speaker.h"

Speaker::Speaker(int pin)
{
    this->pin = pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    this->soundLibrary = vector<vector<SpeakerNote>>();
    this->ringtoneLibrary = vector<Ringtone>();

    vector<SpeakerNote> sound1 = vector<SpeakerNote>();
    sound1.push_back(SpeakerNote{200, 100});
    sound1.push_back(SpeakerNote{0, 50});
    sound1.push_back(SpeakerNote{200, 100});
    sound1.push_back(SpeakerNote{0, 50});
    sound1.push_back(SpeakerNote{200, 100});

    vector<SpeakerNote> sound2 = vector<SpeakerNote>();
    sound2.push_back(SpeakerNote{512, 100});
    sound2.push_back(SpeakerNote{0, 200});
    sound2.push_back(SpeakerNote{200, 100});
    sound2.push_back(SpeakerNote{0, 50});
    sound2.push_back(SpeakerNote{200, 100});

    this->soundLibrary.push_back(sound1);
    this->soundLibrary.push_back(sound2);

    int beats[] = {1, 2, 1, 1, 1, 1, 2};
    Ringtone *ringtone1 = new Ringtone{
        .notes = "bEGFEBA ",
        .beats = beats,
        .tempo = 200,
        .length = 7};

    this->ringtoneLibrary.push_back(*ringtone1);
}

void Speaker::addSound(vector<SpeakerNote> *sound)
{
    this->soundLibrary.push_back(*sound);
}

void Speaker::play(vector<SpeakerNote> *ringtone)
{
    // loop through the notes in the ringtone
    for (int i = 0; i < ringtone->size(); i++)
    {
        // play the note
        analogWrite(pin, ringtone->at(i).note);
        delay(ringtone->at(i).duration);
    }
    digitalWrite(pin, LOW);
}

void Speaker::playAt(int index)
{
    if (index < this->soundLibrary.size())
    {
        this->play(&this->soundLibrary.at(index));
    }
}

void Speaker::playTone(int tone, int duration)
{
    for (long i = 0; i < duration * 1000L; i += tone * 2)
    {
        digitalWrite(pin, HIGH);
        delayMicroseconds(tone);
        digitalWrite(pin, LOW);
        delayMicroseconds(tone);
    }
}

void Speaker::playNote(char note, int duration)
{
    char names[] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B'};
    // int tones[] = {1915, 1700, 1519, 1432, 1275, 1136, 1014, 956, 851, 758, 676, 638, 568, 506};
    int tones[] = {478, 425, 379, 356, 319, 284, 253, 238, 212, 189, 168, 159, 142, 126};
    // play the tone corresponding to the note name
    for (int i = 0; i < 14; i++)
    {
        if (names[i] == note)
        {
            playTone(tones[i], duration);
        }
    }
}

void Speaker::playRingtone(Ringtone *ringtone)
{
    for (int i = 0; i < ringtone->length; i++)
    {
        if (ringtone->notes[i] == ' ')
        {
            delay(ringtone->beats[i] * ringtone->tempo); // rest
        }
        else
        {
            playNote(ringtone->notes[i], ringtone->beats[i] * ringtone->tempo);
        }

        // pause between notes
        delay(ringtone->tempo / 2);
    }
}
