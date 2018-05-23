#include "sound.h"

xerxes::Sound::Sound(QObject *parent) : QObject(parent)
{
    buffercheck = true;
    isFirstTime = true;
}

xerxes::Sound::~Sound()
{

}

void xerxes::Sound::VoiceOverNetwork(bool checkButton)
{
    if(!isFirstTime)
    {
        if(checkButton != buffercheck)
        {
            buffercheck = checkButton;
            if(checkButton)
            {
                system("pactl set-source-volume alsa_input.pci-0000_00_1b.0.analog-stereo 50% && pactl set-sink-volume alsa_output.pci-0000_00_1b.0.analog-stereo 0%");
            }
            else
            {
                system("pactl set-source-volume alsa_input.pci-0000_00_1b.0.analog-stereo 0% && pactl set-sink-volume alsa_output.pci-0000_00_1b.0.analog-stereo 70%");
            }
        }
    }
    else
    {
        buffercheck = checkButton;
        isFirstTime = false;
    }
}
