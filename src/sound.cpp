#include "sound.hpp"

float SoundTrack::m_volume = 50.f;
float SoundTrack::ost_volume = 50.f;
sf::Music SoundTrack::ost;
bool SoundTrack::loop = true;
bool SoundTrack::stop = false;

SoundTrack::SoundTrack()
{
}

void SoundTrack::play(Sounds sound)
{
    sf::Music msc;
    sf::Clock clock;
    if (!msc.openFromFile(SoundTrack::getPath(sound)))
            return; // TODO: return Error here instead.
    msc.setVolume(m_volume);
    msc.play();
    while(msc.getStatus() == sf::SoundSource::Status::Playing) { // Wait until the song end
    }
    msc.stop();
}

void SoundTrack::playOST()
{
    if (!ost.openFromFile(SoundTrack::getPath(Sounds::OST)))
        return; // TODO: return Error here instead.
    stop = false;
    ost.setVolume(ost_volume);
    ost.play();
    while (ost.getStatus() == sf::SoundSource::Status::Playing) { // Wait.
        if (ost.getVolume() != ost_volume) {
            ost.setVolume(ost_volume);
        }
    }

    if (stop && !loop) {
        ost.stop();
    } else {
        playOST();
    }
}
void SoundTrack::stopOST()
{
    ost.stop();
    stop = true;
    std::this_thread::sleep_for(std::chrono::milliseconds(3));
    // Give time to get out of the thread who is playing the OST.
}

void SoundTrack::setVolume(float value)
{
    SoundTrack::ost_volume = value;
    ost.setVolume(value);
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
