#include "slider.hpp"
#include <iostream>

float r_up(float val)
{
    float result = (long)(val * 100 + .5);
    return (float) result / 100;
}

Slider::Slider()
{
	
	slider = {
		.x = 16.f,
		.y = 32.f,
		.width = 100.f,
		.height = 9.f,
	};
	
	grip = {
		.x = 12.f,
		.y = 31.f,
		.width = 8.f,
		.height = 10.f,
	};
	grip.min = grip.x; // = 0.0f
	grip.max = (slider.x + slider.width); // = 1.f
	
	slider_range = slider.width;
	
	draggin_grip = false;
	createSlider();
	texture.setSmooth(false);
	createGrip();
}

Slider::Slider(float x, float y, float width, float height)
{
	slider = {
		.x = x,
		.y = y,
		.width = width,
		.height = height,
	};
	grip = {
        //.x = x - (r_up((slider.height +2) / 2) / 2),
        .x = x,
        .y = y - 1,
        .width = r_up((slider.height+2) / 2),
        .height = slider.height + 2,
        .min = grip.x,
        .max = slider.x + slider.width,
    };
	
	
	slider_range = slider.width;
	draggin_grip = false;
	createSlider();
	texture.setSmooth(false);
	createGrip();
}


Slider::Slider(float x, float y, float width, float height, uint8_t a)
{
	slider = {
		.x = x,
		.y = y,
		.width = width,
		.height = height,
	};
	grip = {
		.x = x - (grip.width / 2),
		.y = y - 1,
		.min = grip.x,
		.max = slider.x + slider.width,
	};
	
	
	slider_range = slider.width;
	draggin_grip = false;
	createSlider();
	texture.setSmooth(false);
	createGrip();
}


void Slider::createSlider()
{
	{
		sf::Image image;
		sf::Image temp;
		temp.loadFromFile("../textures/sprite-sheets.png");
		image.create(slider.width, slider.height + (grip.height - slider.height));
		image.copy(temp, 0, 0, sf::IntRect(304, 96, 4, 4));
		for (int i = 0; i < slider.width - 8; ++i) {
			image.copy(temp, 4  + i, 0, sf::IntRect(308, 96, 1, 4));
		}
		image.copy(temp, slider.width - 4, 0,sf::IntRect(320 - 4, 96, 4, 4));
		if (slider.height > 4) {
			image.copy(image, 0, slider.height, sf::IntRect(0, 0, slider.width, 1)); 
			for (int i = 1; i < slider.height; ++i) {
				image.copy(image, 0, i, sf::IntRect(0, 1, slider.width, 1));
			}
		}
		texture.loadFromImage(image);
	}
	//slider_body.scale(2.f, 2.f); // just to see change this, because changeGripPosition fuction keeps the original scale.
	slider_body.setTexture(texture);
	slider_body.setTextureRect(sf::IntRect(0, 0, (int)slider.width, (int)slider.height));
	slider_body.setPosition(sf::Vector2f(slider.x, slider.y));
	
	// createGrip(); // Grip height = (Slider.height / 16) * 2
}

void Slider::setGripSize(float width, float height) // Grip size will be based on Slider Size.
{
	grip = {
		.width = width,
		.height = height,
	};
	createGrip();
}

void Slider::createGrip()
{
	// 304 100
    // 2w x 6h
	{
		sf::Image image;
		sf::Image img;
		sf::Image temp;
		
		temp.loadFromFile("../textures/sprite-sheets.png");
		image.create(grip.width, grip.height);
        { // Upper border
            image.copy(temp, 0, 0, sf::IntRect(304, 100, 2, 2)); // Top Left 
            image.copy(temp, grip.width -2, 0, sf::IntRect(304 + 2, 100, 2, 2)); // Top Rigth
            for (int i = 1; i < grip.width -2; ++i) { // Fill upper border
                image.copy(temp, i, 0, sf::IntRect(305, 100, 1, 2));
            }
        }
        { // Down border
            image.copy(temp, 0, grip.height -2, sf::IntRect(304, 104, 2, 2)); // Down left
            image.copy(temp, grip.width -2, grip.height-2, sf::IntRect(304+2, 104, 2, 2)); //Down Right
            for (int i = 1; i < grip.width -2; ++i) { // Fill down border
                image.copy(temp, i, grip.height -2, sf::IntRect(305, 104, 1, 2));
            }
        }
        { // Body
            for (int i = 1; i < grip.height-2; ++i) {
                image.copy(image, 0, i, sf::IntRect(0, 1, grip.width, 1));
            }
        }
        img.create(slider.width, slider.height + grip.height);
		temp = texture.copyToImage();
        img.copy(temp, 0, 0);
        img.copy(image, 0, slider.height);
		

		img.saveToFile("test-texture2.png");
		texture.loadFromImage(img);
	}
	
	grip_body.setTexture(texture);
	grip_body.setTextureRect(sf::IntRect(0, slider.height, grip.width, grip.height));
	grip_body.setPosition(sf::Vector2f(grip.x, grip.y));
}

void Slider::Update(sf::RenderWindow* window)
{
	V2 mouse_pos(window->mapPixelToCoords(sf::Mouse::getPosition(*window)));
	changeGripPosition(mouse_pos);
	
	window->draw(slider_body);
	window->draw(grip_body);
}

void Slider::changeGripPosition(V2 mouse_pos)
{
	if (!draggin_grip) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			if (mouse_pos.x >= grip.x && mouse_pos.x <= grip.x + grip.width && mouse_pos.y >= grip.y && mouse_pos.y <= grip.y + grip.height) {
				draggin_grip = true;
			}
		}
	} else {
		if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			draggin_grip = false;
		} else {
			if (mouse_pos.x >= grip.min && mouse_pos.x <= grip.max){
				grip.x = mouse_pos.x - (grip.width / 2) < grip.min ? mouse_pos.x : mouse_pos.x - (grip.width / 2);
				value = (grip.x - slider.x + grip.width / 2) / slider_range;
				grip_body.setPosition(sf::Vector2f(grip.x, grip.y));
			}
		}
	}
}
