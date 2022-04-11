#include "handleErrors.hpp"
#include "renderWindow.hpp"

namespace err
{
    std::vector<ErrorMessage*> ErrorMessage::errors;
    
    ErrorMessage::ErrorMessage()
    {
        m_degree = type::MESSAGE;
        m_rect.setSize(sf::Vector2f(90.f, 45.f));
        m_rect.setPosition(470.f, 416.f);
        m_rect.setFillColor(sf::Color::White);
        m_clock.restart();
        errors.push_back(this);
    }

    ErrorMessage::ErrorMessage(type degree): m_degree(degree)
    {
        m_rect.setSize(sf::Vector2f(90.f, 45.f));
        m_rect.setPosition(470.f, 416.f);
        m_rect.setFillColor(sf::Color::White);
        m_clock.restart();
        errors.push_back(this);
    }
    
    void ErrorMessage::addError()
    {
        ErrorMessage* n_error = new ErrorMessage();
        errors.push_back(n_error);
    }

    void ErrorMessage::Update()
    {
        if (!m_fade_out)
        {
            if(m_anim && m_clock.getElapsedTime().asSeconds() > 0.016f && m_rect.getPosition().y >= 416.f - m_rect.getSize().y) 
            {
                m_rect.move(0.0f, -1.f);
                m_clock.restart();
            } else if (m_anim && m_rect.getPosition().y < 416.f - m_rect.getSize().y) {
                m_rect.setPosition(470.f, 416.f - m_rect.getSize().y);
                m_clock.restart();
            } else if (m_rect.getPosition().y == 416.f - m_rect.getSize().y) {
                m_anim = false;
                if (m_clock.getElapsedTime().asSeconds() >= 3) {
                    m_fade_out = true;
                } 
            }
        } else {
            if (m_rect.getPosition().y != 416 && m_clock.getElapsedTime().asSeconds() > 0.016f) {
                m_rect.move(0.0f, 1.f);
                m_clock.restart();
            } else if (m_rect.getPosition().y == 416.f) {
                m_message_alive = false;
            }
        }
    }
    
    void ErrorMessage::DeleteSelf()
    {
        delete this;
    }

    void handleErrors(RenderWindow* window)
    {
        if (ErrorMessage::errors.size() >= 1) {
            for (size_t i = 0; i < ErrorMessage::errors.size(); ++i)
            {
                window->draw(ErrorMessage::errors[i]->m_rect);
                ErrorMessage::errors[i]->Update();
                if (!ErrorMessage::errors[i]->m_message_alive)
                {
                    ErrorMessage* temp = ErrorMessage::errors[i];
                    ErrorMessage::errors.erase(ErrorMessage::errors.begin() + i);
                    // TODO: Message is crashing when close it.
                    temp->~ErrorMessage();
                    break;
                }
            }
        }
    }
}

