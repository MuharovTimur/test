#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(400, 800), "bubble sort");
    RectangleShape rectangle;
    Event event;

    srand(time(NULL));
    setlocale(LC_ALL, "RUSSIAN");
    int N,k;
    bool f1,f2;
    
    f1 = false;
    f2 = false;
    Time t1 = microseconds(5000000);
    Time t2 = microseconds(10000);

    cout << "Введите раззмер массива N=";
    cin >> N;

    int* M = new int[N];

    cout << "Выберите как хотите заполнить массив:1-рандом,2-самостоятельно через консоль." << endl;
    cin >> k;

    if (k == 1)
    {
        for (int i = 0; i < N; i++)
        {
            M[i] = rand() % 800+1;
        }
    }
    else
    {
        if (k == 2)
        {
            for (int i = 0; i < N; i++)
            {
                cin >> M[i] ;
            }
        }
        else
        {
            cout << "Ошибка";
        }
    }
    


    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if ((f1 == false) && (f2 == false))
        {
            window.clear(Color::Black);
            for (int i = 0; i < N; i++)
            {
                rectangle.setSize(Vector2f(2, M[i]));
                rectangle.setPosition(Vector2f(i, 800));
                rectangle.setRotation(180);
                rectangle.setFillColor(Color::Blue);
                window.draw(rectangle);
            }
            window.display();
            sleep(t1);
            f1 = true;
        }


        if ((f1 == true) && (f2 == false))
        {
            for (int i = 1; i < N; i++)
            {
                for (int j = 0; j < N - 1; j++)
                {
                    if (M[j] > M[j + 1])
                    {
                        swap(M[j], M[j + 1]);
                    }
                    window.clear(Color::Black);
                    for (int l = 0; l < N; l++)
                    {
                        rectangle.setSize(Vector2f(2, M[l]));
                        rectangle.setPosition(Vector2f(l, 800));
                        rectangle.setRotation(180);
                        rectangle.setFillColor(Color::Blue);
                        if ((l == j) || (l == j + 1))
                        {
                            rectangle.setFillColor(Color::Red);
                        }
                        window.draw(rectangle);
                    }
                    window.display();
                    sleep(t2);
                }
            }
            f2 = true;
        }

        if ((f1 == true) && (f2 == true))
        {
            window.clear(Color::Black);
            for (int i = 0; i < N; i++)
            {
                rectangle.setSize(Vector2f(2, M[i]));
                rectangle.setPosition(Vector2f(i, 800));
                rectangle.setRotation(180);
                rectangle.setFillColor(Color::Green);
                window.draw(rectangle);
            }
            window.display();
        }
    }

    delete[] M;

    return 0;
}