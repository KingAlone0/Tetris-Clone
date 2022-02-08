#include "configs.hpp"
#include <iostream>

Defaults::Defaults()
{
    initialize_default();
}

void Defaults::setTexture(const std::string& path)
{
    if (!m_texture.loadFromFile(path)) {
        m_valid = false;
    } else {
        m_valid = true;
    }
    std::cout << "Has changed texture" << std::endl;
}

void Defaults::setMinoTexture(const std::string& path)
{
    if (!m_mino_texture.loadFromFile(path)) {
        m_valid = false;
    } else {
        m_valid = true;
    }

}

sf::Texture Defaults::Texture() const
{
    if (!m_valid) {
        // Return a error, or something here.
    }
    return m_texture;
}

sf::Texture Defaults::MinoTexture() const
{
    if (!m_valid) {
        // Return a error, or something here.
    }
    return m_mino_texture;
}

void Defaults::initialize_default()
{
    // Initialize Defaultss values of the 
    if (!m_valid) {
        if (!m_texture.loadFromFile("../textures/sprite-sheets.png")) {
            m_valid = false;
        }
    }

    if (!m_mino_texture.loadFromFile("../textures/textures_mino.png")) {
        m_valid = false;
    }
}

