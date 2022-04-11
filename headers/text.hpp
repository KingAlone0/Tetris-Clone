#ifndef TEXT_HPP
#define TEXT_HPP
#include "UI.hpp"
#include <string>

class Text : public UI
{
    private:
    void setSprite();
    public:
    Text();
    Text(const std::string name);
    V2 getPosition() const;
    void setPosition(float x, float y);
    void setPosition(V2);
    
    void setDistance(uint8_t distance);
    uint8_t getDistance() const;
    V2 getTSize() const;
    
    virtual void Update(RenderWindow* window);

    private:
    sf::Sprite m_sprite;
    std::string m_text;
    sf::Texture m_font;
    uint8_t m_size;
    V2 m_pos;
    uint8_t m_distance; // Distance between the letters.
    V4 m_rect;
    V2 m_transformable;
    int test_size = 0;


    // OVERLOADERS    
    public:
    Text& operator=(const Text& n)
    {
        this->m_sprite = n.m_sprite;
        this->m_text = n.m_text;
        this->m_font = n.m_font;
        this->m_size = n.m_size;
        this->m_pos = n.m_pos;
        this->m_distance = n.m_distance;
        this->test_size = n.test_size;
        if (!n.m_text.empty()) {
            this->setSprite();
        }
        return *this;

    }
};


#endif

