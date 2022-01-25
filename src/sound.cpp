#include "sound.hpp"

float SoundTrack::m_volume = 50.f;

SoundTrack::SoundTrack()
{
}

void SoundTrack::play(Sounds sound)
{
    sf::Music msc;
    sf::Clock clock;
    if (!msc.openFromFile(SoundTrack::getPath(sound)))
            return; // TODO: return Error here instead.
    msc.setVolume(SoundTrack::m_volume);
    msc.play();
    while(msc.getStatus() == sf::SoundSource::Status::Playing) { // Wait until the song end
    }
    msc.stop();
}

std::string SoundTrack::getPath(Sounds sound)
{
    std::string str;
    switch(sound)
    {
        case Sounds::Drop:
            return std::string("../sounds/Drop.ogg");
        case Sounds::Clean:
            return std::string("../sounds/Clean.ogg");
        case Sounds::OST:
            return std::string("../sounds/OST.ogg");
        default:
            return std::string("None"); // TODO: return Error here instead.

    }
    return std::string("None");
}
