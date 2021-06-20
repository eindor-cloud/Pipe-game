#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Menu.h"
#include "../include/All_animation/Textures.h" 

//----------------------------------------------------------------------------
Menu::Menu(RenderWindow& window, char& p, char& p2, float& g) : m_window(window),m_selection(user_selection(p,p2,g))
{
    m_background.setTexture(Textures::instance().get_Textures(MENU_BACKGROUND));
}
//----------------------------------------------------------------------------
bool Menu::showMenu()
{
    while (m_window.isOpen())
    {
        m_window.clear();
        m_window.draw(m_background);
        for (auto& x : m_options)
        {
            m_window.draw(get<0>(x));
        }

        m_window.display();
        if (auto event = sf::Event{}; m_window.waitEvent(event)) {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased:
            {
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });

                switch (event.mouseButton.button)
                {
                case sf::Mouse::Button::Left:
                    handleClick(location, m_window);
                    if (m_close_curr) return false;
                    if (m_close_all)return true;
                    break;
                default: break;
                }
                break;

            }
            case sf::Event::MouseMoved:
            {
                auto location = m_window.mapPixelToCoords(
                    { event.mouseMove.x, event.mouseMove.y });
                handleHover(location);
                break;
            }
            default: break;
            }
        }
    }
    return false;
}
//----------------------------------------------------------------------------
void Menu::handleClick(const sf::Vector2f& location, RenderWindow& window)
{
    for (auto &x : m_options)
    {
        if (get<0>(x).getGlobalBounds().contains(location))
            if (get<1>(x).get()->execute())
            {
                if (dynamic_cast<Next*>(get<1>(x).get()))
                    m_close_all = true;
                else m_close_curr = true;
            }
            
    }
}
//----------------------------------------------------------------------------
void Menu::handleHover(const sf::Vector2f& location)
{
    for (auto& x : m_options)
    {
        if (get<0>(x).getGlobalBounds().contains(location))
            get<0>(x).setTexture(*get<2>(x)[1]);
        else get<0>(x).setTexture(*get<2>(x)[0]);
      
    }
}
//----------------------------------------------------------------------------