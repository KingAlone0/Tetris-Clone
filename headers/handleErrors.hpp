#ifndef handleErrors_HPP
#define handleErrors_HPP

#include <string>
#include <vector>
#include "renderWindow.hpp"
#include <thread>



namespace err
{
    void handleErrors(RenderWindow* window);

    struct ErrorMessage {
        type m_degree;
        bool m_message_alive = true;
        bool m_anim = true;
        bool m_fade_out = false;
        sf::RectangleShape m_rect;
        sf::Clock m_clock;


        static void addError();
        void Update();
        void DeleteSelf();
        static std::vector<ErrorMessage*> errors;

        private:
        ErrorMessage(type degree);
        ErrorMessage();
    };
}

#endif

