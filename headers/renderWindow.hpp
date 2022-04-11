#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "iostream"
#include "types.hpp"
#include <thread>
#include <vector>
enum class Sounds;

namespace err {
    struct ErrorMessage;
}

class RenderWindow : public sf::RenderWindow
{
    public:
    std::string Title;
	unsigned int width;
	unsigned int height;
	private:
    std::thread* m_ost;
    static std::vector<Sounds> m_play_queue;
	
    public:
    RenderWindow(const std::string& windowTitle, unsigned int width, unsigned int height);

    V2 getMousePosition();

    void Update();
    void playOST();
    void Quit();


    static void Error(err::type);
    static void play(Sounds msc);
};

