#ifndef DEFAULT_HPP
#define DEFAULT_HPP

#include <string>
#include "options.hpp"

class Defaults
{
public:
    Defaults (const Defaults&) = delete;
    static Defaults& Get()
    {
        static Defaults instance;
        return instance;
    }

    sf::Texture Texture() const;
    sf::Texture MinoTexture() const;

private:
    Defaults();
    sf::Texture m_texture;
    sf::Texture m_mino_texture;
    float _DAS;
    float volume;

    bool m_valid;

    void initialize_default();
    void setTexture(const std::string& path);
    void setMinoTexture(const std::string& path);

    friend void Options(RenderWindow&);
    friend void selectTexturePath();

};


#endif

