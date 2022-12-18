#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <math.h>

// #include "LinkedList.h"
#include <string>

using namespace std;
// g++ -c pr.cpp;g++ pr.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system;./sfml-app

struct Location
{
    string name;
    int cordX, cordY;
};

ostream &operator<<(ostream &os, const Location &l)
{
    os << "Name:\t" << l.name << endl
       << "Coords:\t(" << l.cordX << "," << l.cordY << ")" << endl;
    return os;
}

int distanceBetweenLocations(Location l1, Location l2)
{
    return int(pow(((pow((l2.cordX - l1.cordX), 2)) - (pow((l2.cordY - l1.cordY), 2))), 0.5));
}

void initializeVisibleNodes(Location visibleNodes[50])
{
    ifstream readfile;
    readfile.open("coordinates.txt");
    for (int i = 0; !readfile.eof() && i < 50; i++)
    {
        readfile >> visibleNodes[i].cordX;
        readfile >> visibleNodes[i].cordY;
        readfile >> visibleNodes[i].name;
        cout << "name len" << i << " : " << (visibleNodes[i].name).length() << endl;
        if (visibleNodes[i].name == "")
            break;
    }

    for (int i = 0; i < 50 && visibleNodes[i].name != ""; i++)
    {
        cout << "ID: " << i << endl
             << visibleNodes[i];
    }
    readfile.close();
}

void displayMarkers(sf::RenderWindow &window, Location visibleNodes[50])
{
    Location temp;

    sf::CircleShape marker(10.f);
    sf::Color clr(0xb33f0dff);
    marker.setFillColor(clr);

    // marker.setPosition(-10, -10);
    // window.draw(marker);

    for (int i = 0; i < 50; i++)
    {
        if (visibleNodes[i].name == "")
            break;
        // cout << "Drawing" << temp << endl;
        marker.setPosition(temp.cordX - 10, temp.cordY - 10);
        window.draw(marker);
    }
    return;
}

int click(int cordX, int cordY, Location visibleNodes[50])
{
}

int main()
{
    Location visibleNodes[50];

    initializeVisibleNodes(visibleNodes);
    // test(visibleNodes);

    sf::RenderWindow window(sf::VideoMode(869, 613), "GIKI Navigator");

    // sf::RectangleShape rectangle(sf::Vector2f(100.0f, 300.0f));
    // rectangle.setFillColor(sf::Color::Red);
    // rectangle.setPosition(320, 0);
    // rectangle.setPosition(320, 400);

    sf::Texture backGround;
    sf::Sprite sBg;
    if (!backGround.loadFromFile("Map2.png"))
        std::cout << "File not found\n";

    sBg.setTexture(backGround);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased)
                std::cout << sf::Mouse::getPosition(window).x << "," << sf::Mouse::getPosition(window).y << std::endl;
        }

        window.draw(sBg);

        // displayMarkers(window, visibleNodes);
        window.display();
    }

    return 0;
}