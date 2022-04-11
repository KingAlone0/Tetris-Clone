#include "configs.hpp"
#include <iostream>

Defaults::Defaults()
{
    initialize_default();
}

void Defaults::setTexture(const std::string& path)
{
    m_texture_path = path;
    if (!m_texture.loadFromFile(m_texture_path)) {
        m_valid = false;
    } else {
        m_valid = true;
    }
    std::cout << m_texture_path << std::endl;
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

sf::Texture Defaults::IconTexture() const
{
    if (!m_valid) {
        // Return a error, or something here.
    }
    return m_mino_texture;
}

sf::IntRect Defaults::ButtonDefault() const
{
    return m_button_place;
}

float Defaults::Volume() const
{
    return m_ost_volume;
}

void Defaults::initialize_default()
{
    m_texture_path = "../textures/sprite-sheets.png";
    m_mino_texture_path = "../textures/textures_mino.png"; 
    // Initialize Defaultss values of the 
    if (!m_valid) {
        if (!m_texture.loadFromFile(m_texture_path)) {
            m_valid = false;
        }
    }

    if (!m_mino_texture.loadFromFile(m_mino_texture_path)) {
        m_valid = false;
    }

    m_ost_volume = 0.5f;
    m_DAS = 0.2f;

    m_button_place = sf::IntRect(0.f, 26.f, 32.f, 16.f);
}

void Defaults::saveAsConfig()
{ 
    std::fstream configs;
    configs.open("../config.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
    if (!configs.is_open()) {
        // Could not load the config.txt file
        return; // TODO return error
    }
    configs.seekg(0); 
    m_ost_volume = SoundTrack::ost_volume / 100;
    m_effect_volume = SoundTrack::m_volume / 100;

    configs << "// Configurations of Tetris by AloneTheKing(Jonas Gomes)\n\n" <<
               "Texture_Path: " << m_texture_path << "\n" <<
               "Mino_Texture: " << m_mino_texture_path << "\n\n" <<
               "DAS: " << m_DAS << "\n" << "OST_Volume: " << m_ost_volume << "\n" <<
               "Effect_Volume: " << m_effect_volume << "\n";
    configs.close();
}

void Defaults::loadConfig()
{
    FILE *check;
    if (check = fopen("../config.txt", "r")) {
        std::fstream configs;
        configs.open("../config.txt");
        if (configs.is_open()) {
            std::string line;
            
            while (std::getline(configs, line)) 
            {
                if (line.find("Texture_Path:") != std::string::npos) {
                    size_t beg = line.find_first_of(' ');
                    setTexture(line.substr(++beg));

                } else if (line.find("Mino_Texture:") != std::string::npos) {
                    size_t beg = line.find_first_of(' ');
                    setMinoTexture(line.substr(++beg));
                } else if (line.find("DAS:") != std::string::npos) {
                    size_t beg = line.find_first_of(' ');
                    m_DAS = std::stof(line.substr(++beg));
                    std::cout << m_DAS << std::endl;
                } else if (line.find("OST_Volume:")!= std::string::npos) {
                    size_t beg = line.find_first_of(' ');
                    m_ost_volume = std::stof(line.substr(++beg));
                } else if (line.find("Effect_Volume:") != std::string::npos) {
                    size_t beg = line.find_first_of(' ');
                    m_effect_volume = std::stof(line.substr(++beg));
                }
            }

        }
    } else {
        // TODO: return err
        // has no config.txt file to load
    }
}
