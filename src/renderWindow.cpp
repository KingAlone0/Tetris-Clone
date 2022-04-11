#include "renderWindow.hpp"
#include "handleErrors.hpp"
#include "sound.hpp"

std::vector<Sounds> RenderWindow::m_play_queue;

RenderWindow::RenderWindow(const std::string& windowTitle, unsigned int width, unsigned int height) : Title(windowTitle), width(width), height(height)
{
    create(sf::VideoMode(width, height), Title);
}

V2 RenderWindow::getMousePosition()
{
    return V2(mapPixelToCoords(sf::Mouse::getPosition(*this)));
}

void RenderWindow::Update()
{
    
    // if (err::ErrorMessage::errors.size() >= 1) 
    // {
    //     err::handleErrors(this);
    // }
    if (m_play_queue.size() >= 1) 
    {
        for (size_t i = 0; i < m_play_queue.size(); ++i) {
            std::thread(SoundTrack::play, m_play_queue[i]).detach();
        }
        m_play_queue.clear();
    }

    this->display();
}

void RenderWindow::playOST()
{
    if (!SoundTrack::OST_isPlaying()) {
        std::thread ost(SoundTrack::playOST);
        m_ost = &ost;
        ost.detach();
    }
}

void RenderWindow::Quit()
{
    SoundTrack::stopOST();
    if (m_ost->joinable())
        m_ost->join();
    this->close();
}


void RenderWindow::play(Sounds msc)
{
    m_play_queue.push_back(msc);
}

/*
void RenderWindow::onResize()
{
    
	if (getSize().x != width || getSize().y != height) {
		setSize(sf::Vector2u(width, height));
	}
	
	float n_width = getSize().x;
	float n_height = getSize().y;
	float aspect_ratio = (float)width / height;
	view.setSize(n_width, n_height);
	
	float ratio_w = (float)n_width / width;
	float ratio_h = (float)n_height / height;
	
	float ratio = ratio_w > ratio_h ? ratio_h : ratio_w;
	
	n_width  = (float)width * ratio;
	n_height = (float)height * ratio;
	
	if (n_width > n_height) {
		view.setSize(width, n_height);
	} else {
		view.setSize(n_width, height);
	}
	view.setCenter((float)width / 2, (float)height / 2);
	//view.setViewport(sf::FloatRect(0.f, 0.f, 1, 1));
	
	setView(view);
	
	
	m_view.setSize((float)window.getSize().x, (float)window.getSize().y);
	if ((double)window.getSize().x / window.getSize().y == aspect_ratio)  {
		view = window.getDefaultView(); // don't that, need to pick up last aspect useful
		std::cout << window.getSize().x << " : " << window.getSize().y << std::endl;
	}
	window.setView(view);
	window_size = sf::Vector2f(window.getSize());
	
}
*/
