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
    sf::Texture IconTexture() const;
    sf::IntRect ButtonDefault() const;
    float Volume() const;
    
    void saveAsConfig();
    void loadConfig();

private:
    Defaults();
    sf::Texture m_texture;
    sf::Texture m_mino_texture;
    sf::Texture icon_texture;


    std::string m_texture_path;
    std::string m_mino_texture_path;

    sf::IntRect m_button_place;

    float m_DAS;
    float m_ost_volume;
    float m_effect_volume;

    bool m_valid;

    void initialize_default();
    void setTexture(const std::string& path);
    void setMinoTexture(const std::string& path);


    friend void Options(RenderWindow&);
    friend void selectTexturePath();
};


#endif

