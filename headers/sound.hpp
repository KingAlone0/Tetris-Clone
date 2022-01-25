#ifndef SOUND_HPP
#define SOUND_HPP
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>

enum class Sounds
{
    Drop,
    Clean,
    OST
};

class SoundTrack
{
    public:
    SoundTrack(const SoundTrack&) = delete;

    static void play(Sounds sound);
    static void playOST();
    static void stopOST();

    private:
    SoundTrack();
    static float m_volume;
    static std::string getPath(Sounds sound);

};


#endif 

