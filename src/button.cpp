#include "button.hpp"
#include <iostream>

Button::Button(V2 pos, sf::IntRect sprPlace, unsigned short int frames, float frame_rate, sf::IntRect icon_place, const std::string& _text): 
    UI(pos, sprPlace), frames(frames), frame_rate(frame_rate)
{
	anim = Animation(&spr, sprPlace, frames, frame_rate, false);
	spr.setTexture(texture);
	
	if (icon_place.width != 0) {
		icon.setTexture(texture);
		icon.setTextureRect(icon_place);
		icon.setPosition(pos.x + 4.f, pos.y + 1);
		icon.scale(2.f, 2.f);
	}
    id = ID(ID_TYPE::BUTTON);
	
	spr.setTextureRect(sprPlace);
	spr.setPosition(pos.x, pos.y);
	spr.scale(2.f, 2.f);
    setCollision(pos.x, pos.y, spr.getGlobalBounds().width, spr.getGlobalBounds().height);
    if (_text != "nil") {
        setName(_text);
    }
	c.restart();
}

Button::Button(V2 pos, unsigned short int frames, float frame_rate):
    UI(pos, Defaults::Get().ButtonDefault()), frames(frames), frame_rate(frame_rate)
{
	anim = Animation(&spr, sprPlace, frames, frame_rate, false);
	spr.setTexture(texture);
    sf::IntRect icon_place = default_value.icon_place;
	
	if (icon_place.width != 0) {
		icon.setTexture(texture);
		icon.setTextureRect(icon_place);
		icon.setPosition(pos.x + 4.f, pos.y + 1);
		icon.scale(2.f, 2.f);
	}
    id = ID(ID_TYPE::BUTTON);
	
	spr.setTextureRect(sprPlace);
	spr.setPosition(pos.x, pos.y);
	spr.scale(2.f, 2.f);
    setCollision(pos.x, pos.y, spr.getGlobalBounds().width, spr.getGlobalBounds().height);
	c.restart();

}
Button::Button(V2 pos, const std::string& _text, unsigned short int frames, float frame_rate):
    Button(pos, frames, frame_rate)
{
    setName(_text);
}

void Button::Update(RenderWindow* window)
{
    if (m_trigger && c.getElapsedTime().asSeconds() - timer.trigger.asSeconds() < 0.2f) {
        m_trigger = false;
    }
    V2 mouse_pos = window->getMousePosition();
	mouseIsOver(mouse_pos);
	buttonPressed(mouse_pos);
	window->draw(spr);
	window->draw(icon);
    m_name.Update(window);
}

void Button::mouseIsOver(V2 mousePos)
{
	if (buttonSelected(mousePos)) 
	{
		if (frames > 0) {
			anim.changeFrame(1);
		}
	}
	else {
		anim.changeFrame(0);
	}
}

bool Button::buttonPressed(V2 mousePos)
{
    if (Mouse::isActive())
    {
        if (Mouse::getID().id != id.id) {
            return false;
        }
    }
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && buttonSelected(mousePos))
	{
        if (frames > 0) {
            anim.changeFrame(2);
            icon.setPosition(spr.getPosition().x + 4.f, spr.getPosition().y + 5);
            m_name.setPosition(icon.getPosition().x + icon.getGlobalBounds().width - 8, icon.getPosition().y + 8);
            last_pressed = c.getElapsedTime().asSeconds();
			pressed = true;
            Mouse::setActive(id);
			return true;
		}
		
	}
	else if (pressed && buttonSelected(mousePos)) 
	{
		icon.setPosition(spr.getPosition().x + 4.f, spr.getPosition().y + 1);
        m_name.setPosition(icon.getPosition().x + icon.getGlobalBounds().width - 8, icon.getPosition().y + 8);
        anim.changeFrame(0);
        Mouse::setInactive();
		pressed = false;
        if (m_function) {
            onReleased();
        } else {
            m_trigger = true;
            timer.trigger = c.getElapsedTime();
        }
	}
	else if (pressed && !buttonSelected(mousePos)) 
	{
		icon.setPosition(spr.getPosition().x + 4.f, spr.getPosition().y + 1);
        m_name.setPosition(icon.getPosition().x + icon.getGlobalBounds().width - 8, icon.getPosition().y + 8);
        Mouse::setInactive();
		pressed = false;
		anim.changeFrame(0);
	}
	return false;
}

bool Button::buttonSelected(V2 mousePos)
{
    return isPointInside(mousePos);
}

void Button::setScale(float scale)
{
    spr.setScale(scale, scale);
    icon.setScale(scale, scale);
    setCollision(pos.x, pos.y, spr.getGlobalBounds().width, spr.getGlobalBounds().height);
    m_name.setPosition(icon.getPosition().x + icon.getGlobalBounds().width - 8, icon.getPosition().y + 8);
}

void Button::setName(const std::string name)
{
    m_name = Text(name);
    float max_width = spr.getPosition().x + spr.getGlobalBounds().width;
    float width = m_name.getSprite().getPosition().x + m_name.getSprite().getGlobalBounds().width;
    // it's weird

    if (max_width <= width) 
    {
        float scale = max_width / width;
        m_name.setScale(scale - 0.10f);
    }

    m_name.setPosition(icon.getPosition().x + icon.getGlobalBounds().width - 8, icon.getPosition().y + 8);
}


void Button::setOnReleasedFunction(const std::function<void()>& _fnc)
{
    m_function = true;
    onReleased = _fnc;
}

