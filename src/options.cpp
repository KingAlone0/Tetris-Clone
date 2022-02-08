#include "options.hpp"
#include "configs.hpp"

void Options(RenderWindow& window)
{
	sf::RectangleShape background(sf::Vector2f(window.window.getSize()));
	background.setFillColor(sf::Color(HEXCOLOR(0x252525FF)));
    // TODO:  Need to create a Dialog box to change the texture and make a save file to save/load configs	
    Slider slider_vol(16.f, 32.f, 100.f, 10.f);
    slider_vol.setValueTo(&SoundTrack::ost_volume, 100);
    CheckBox check(16.f, 50.f);

	Button change_texture(V2(232.f, 216.f), sf::IntRect(0.f, 26.f, 32.f, 16.f), 4, .2f, sf::IntRect(0.f, 239.f, 9.f, 9.f));

    {
        std::function<void()> fncPtr = [] () { selectTexturePath(); };
        change_texture.setOnReleasedFunction(fncPtr);
    }
	
	bool quit = false;
	while (!quit)
	{
		window.draw(background);
		
		sf::Event event;
		while (window.window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				quit = true;
				window.close();
			}
		}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            return;
        }
		slider_vol.Update(&window);
        check.Update(&window);
        change_texture.Update(&window);
        // SoundTrack::setVolume(slider_vol.getValue() * 10);
		
		window.display();
		window.clear();
	}
	
}

void selectTexturePath()
{
    HRESULT hr = CoInitializeEx(
            NULL,
            COINIT_APARTMENTTHREADED |
            COINIT_DISABLE_OLE1DDE);

    if (SUCCEEDED(hr))
    {
        IFileOpenDialog *pFileOpen;

        hr = CoCreateInstance(
                CLSID_FileOpenDialog,
                NULL,
                CLSCTX_ALL,
                IID_IFileOpenDialog,
                reinterpret_cast<void**>(&pFileOpen));

        if (SUCCEEDED(hr))
        {
            hr = pFileOpen->Show(NULL);

            if (SUCCEEDED(hr))
            {
                IShellItem *pItem;
                hr = pFileOpen->GetResult(&pItem);

                if (SUCCEEDED(hr)) 
                {
                    PWSTR w_path;

                    hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &w_path);
                    std::wstring w_str = w_path;
                    std::string testA(w_str.begin(), w_str.end());
                    Defaults::Get().setTexture(testA);
                    // TODO: Need to update the texture who already been loaded when change the Default::texture
                }

            }
        }
    }
}

