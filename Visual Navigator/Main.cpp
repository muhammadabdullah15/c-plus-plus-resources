#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <math.h>

// #include "LinkedList.h"
#include <string>

using namespace std;
// g++ -c pr.cpp;g++ pr.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system;./sfml-app

#define NUM_LOCATIONS 50
#define NUM_JUNCTIONS 100

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

int distanceBetweenPoints(Location l1, Location l2)
{
    // cout << l1.cordX << "," << l1.cordY << endl
    //      << l2.cordX << "," << l2.cordY << endl;
    return sqrt(pow(l1.cordX - l2.cordX, 2) + pow((l1.cordY - l2.cordY), 2));
    // return sqrt((pow((l2.cordX - l1.cordX), 2)) - (pow((l2.cordY - l1.cordY), 2)));
}

void initializeVisibleNodes(Location visibleNodes[NUM_LOCATIONS])
{
    ifstream readfile;
    readfile.open("coords_locations.txt");
    for (int i = 0; !readfile.eof() && i < NUM_LOCATIONS; i++)
    {
        readfile >> visibleNodes[i].cordX;
        readfile >> visibleNodes[i].cordY;
        readfile >> visibleNodes[i].name;
        replace(visibleNodes[i].name.begin(), visibleNodes[i].name.end(), '-', ' ');
        // cout << "name len" << i << " : " << (visibleNodes[i].name).length() << endl;
        if (visibleNodes[i].name == "")
            break;
    }

    // for (int i = 0; i < NUM_LOCATIONS && visibleNodes[i].name != ""; i++)
    // {
    //     cout << "ID: " << i << endl
    //          << visibleNodes[i];
    // }
    readfile.close();
}

void displayMarkers(sf::RenderWindow &window, Location visibleNodes[NUM_LOCATIONS])
{
    sf::CircleShape marker(10.f);
    sf::Color clr(0xb33f0dff);
    marker.setFillColor(clr);

    // marker.setPosition(-10, -10);
    // window.draw(marker);

    for (int i = 0; i < NUM_LOCATIONS && visibleNodes[i].name != ""; i++)
    {
        // if (visibleNodes[i].name == "")
        //     break;
        // // cout << "Drawing" << temp << endl;
        marker.setPosition(visibleNodes[i].cordX - 10, visibleNodes[i].cordY - 10);
        window.draw(marker);
    }
    return;
}

void addPoint(int i, Location visibleNodes[NUM_LOCATIONS])
{
    cout << visibleNodes[i] << endl;
}

void click(int cordX, int cordY, Location visibleNodes[NUM_LOCATIONS])
{
    Location temp;
    temp.cordX = cordX;
    temp.cordY = cordY;

    for (int i = 0; i < NUM_LOCATIONS && visibleNodes[i].name != ""; i++)
    {
        // cout << "id:" << i << ": " << visibleNodes[i].name << "-" << distanceBetweenPoints(visibleNodes[i], temp) << endl;
        if (distanceBetweenPoints(visibleNodes[i], temp) >= 0 && distanceBetweenPoints(visibleNodes[i], temp) <= 10)
        {
            addPoint(i, visibleNodes);
            return;
        }
    }

    return;
}

int main()
{
    Location visibleNodes[NUM_LOCATIONS];
    Location roadJunctions[NUM_JUNCTIONS];

    initializeVisibleNodes(visibleNodes);
    // test(visibleNodes);

    sf::RenderWindow window(sf::VideoMode(869, 613), "GIKI Navigator");

    sf::Texture backGround;
    sf::Sprite sBg;
    if (!backGround.loadFromFile("Map2.png"))
        std::cout << "File not found\n";

    sBg.setTexture(backGround);

    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].color = lines[1].color = sf::Color::Red;
    lines[0].position = sf::Vector2f(0, 0);
    lines[1].position = sf::Vector2f(100, 100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonReleased)
            {
                cout << "Click Location: " << sf::Mouse::getPosition(window).x << "," << sf::Mouse::getPosition(window).y << std::endl;
                // click(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, visibleNodes);
            }
        }

        window.draw(sBg);
        window.draw(lines);

        displayMarkers(window, visibleNodes);
        window.display();
    }

    return 0;
}