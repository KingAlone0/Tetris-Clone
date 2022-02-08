#ifndef SOUND_HPP
#define SOUND_HPP
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "options.hpp"

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
    static void setVolume(float value);
    static bool OST_isPlaying();

    private:
    SoundTrack();
    static float m_volume;
    static std::string getPath(Sounds sound);
    // NOTE: Create a string class maybe. 
    static sf::Music ost;
    static float ost_volume;
    static bool loop;
    static bool stop;

    friend void Options(RenderWindow& window);
};


#endif 

