#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <vector>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int main()
{
    int screen_height = 1000;
    int screen_width = 1920;
    int array_size = 200;
    bool sorted = false;
    sf::Font font;
    if (!font.loadFromFile("Limelight-Regular.ttf"))
    {
        std::cout<<"font not able to load";
    }
    std::vector<int> numbers;
    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "SFML BUBBLE SORT!");
    for (int i = 0; i < array_size; i++)
    {
        int num = rand() % 800;
        numbers.push_back(num);
        // lines.push_back(sf::RectangleShape (sf::Vector2f(num*10, 5.f)) );
        // lines[i].rotate(90.f);
        // lines[i].setPosition(5+i*10,(screen_height - (num)*screen_height*0.002));
    }
    window.setFramerateLimit(60);
    int count = 1;
    while (window.isOpen())
    {
        if (!sorted && count == 1)
        {
            window.clear();
            for (int i = 0; i < array_size; i++)
            {
                sf::RectangleShape lines(sf::Vector2f(numbers[i], 5.f));
                lines.rotate(-90.f);
                lines.setPosition(5 + i * 10, (screen_height));
                window.draw(lines);
                window.display();
            }
        sf::Text text;
        text.setFont(font);
        text.setString("Bubble sort Visualization\nRight click to Start");
        window.draw(text);
         window.display();
            count = 0;
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                if (!sorted)
                {
                    for (int i = 0; i < array_size - 1; i++)
                    {

                        for (int j = 0; j < array_size - i - 1; j++)
                        {
                            if (numbers[j] > numbers[j + 1])
                            {
                                swap(&numbers[j], &numbers[j + 1]);
                            }
                        }
                        for (int l = 0; l < array_size; l++)
                        {
                            sf::RectangleShape lines(sf::Vector2f(numbers[l], 5.f));
                            if (l == i)
                            {
                                lines.setFillColor(sf::Color(0, 0, 255));
                            }
                            if (l > i)
                            {
                                lines.setFillColor(sf::Color(191, 38, 38));
                            }
                            if (l < i)
                            {
                                lines.setFillColor(sf::Color(50, 168, 102));
                            }

                            lines.rotate(-90.f);
                            lines.setPosition(5 + l * 10, (screen_height));
                            window.draw(lines);
                        }
                        window.display();
                        window.clear();
                    }
                    // window.clear();
                   // std::cout << "sorted" << sorted;
                    sorted = true;
                }
            }
        }
    }

    return 0;
}
