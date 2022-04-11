#include "options.hpp"
#include "configs.hpp"

void Options(RenderWindow& window)
{
    sf::Texture bg;
    bg.loadFromFile("../textures/options-background.png");
    sf::Sprite background;
    background.setTexture(bg);
    Slider slider_vol(67.f, 32.f, 144.f, 11.f);
    slider_vol.setValueTo(&SoundTrack::ost_volume, 100);
    CheckBox mute_check(294.f, 32.f);
    CheckBox res_check[3] = { {125.f, 62.f}, {195.f, 62.f}, {265.f, 62.f} };
    CheckBox full_check(80.f, 84);

	Button change_texture(V2(509.f, 98.f), sf::IntRect(0.f, 26.f, 32.f, 16.f), 4, .2f, sf::IntRect(0.f, 239.f, 9.f, 9.f));
    Button save_button(V2(10.f, 346.f));
    Button load_button(V2(80.f, 346.f));
    change_texture.setOnReleasedFunction(selectTexturePath);
    save_button.setOnReleasedFunction([] (){ Defaults::Get().saveAsConfig(); });
    load_button.setOnReleasedFunction([] (){ Defaults::Get().loadConfig(); });
    Button quit_button(V2(509.f, 18.f));

    
	
	bool quit = false;
	while (!quit)
	{
		window.draw(background);
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				quit = true;
                window.Quit();
			}
		}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
            quit_button.hasTriggered()) {
            Mouse::setInactive();
            quit = true;
        }

		slider_vol.Update(&window);
        load_button.Update(&window);
        save_button.Update(&window);
        change_texture.Update(&window);
        for (auto i = 0; i < 3; ++i) {
            res_check[i].Update(&window);
        }
        full_check.Update(&window);
        quit_button.Update(&window);
        mute_check.Update(&window);
        if (mute_check.getPressed()) {
            SoundTrack::muteOST();
        } else {
            SoundTrack::unmuteOST();
        }
		
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

