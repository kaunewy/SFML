#define _USE_MATH_DEFINES
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>


using namespace std;
using namespace sf;



void Demo()
{
    RenderWindow _window(VideoMode({ 200, 200 }), "SFML works!");


    RectangleShape _shape({ 150.0F,50.0F });
    _shape.setFillColor(Color::Magenta);

    while (_window.isOpen())
    {
        while (const optional _event = _window.pollEvent())
        {
            if (_event->is<Event::Closed>())
                _window.close();
        }

        _window.clear();
        _window.draw(_shape);
        _window.display();
    }
}




void UpdateTileIndex(unsigned int& _tileIndex, const Keyboard::Key& _currentKey, const unsigned int _velocity)
{
    static unsigned int _time = 0;
    static Keyboard::Key _lastKey = Keyboard::Key::Unknown;

    if (_lastKey != _currentKey)
    {
        _lastKey = _currentKey;
        _tileIndex = 0;
    }
    else
    {
        if (++_time % _velocity == 0)
        {
            ++_tileIndex %= 4;
        }
    }
}

void UpdateTexture(RectangleShape& _shape, const unsigned int _number, unsigned int& _tileIndex, const int _pixelCount, const Vector2i& _tileSize, const bool _isWalking, const Keyboard::Key& _key)
{
    UpdateTileIndex(_tileIndex, _key, _isWalking ? 7 : 3);
    _shape.setTextureRect(IntRect(Vector2i(_tileIndex * _pixelCount, _number * _pixelCount), _tileSize));
}

int main()
{
    RenderWindow _mainWindow;
    _mainWindow.create(VideoMode(Vector2u(500, 500)), "", State::Windowed);




    RectangleShape _rect = RectangleShape({ 64.0F,64.0F });
    _rect.setOrigin(Vector2(_rect.getSize().x / 2, _rect.getSize().y / 2));
    bool _isWalking = true;
    const int _pixelCount = 64;
    const Vector2i& _tileSize = Vector2i(_pixelCount, _pixelCount);
    unsigned int _tileIndex = 0;
    Texture _texture = Texture("Assets/Textures/Sacha.png");
    _rect.setTexture(&_texture);
    _rect.setTextureRect(IntRect(Vector2i(0, 0), _tileSize));
    Clock _clock;
    Time _elapsedTime = _clock.getElapsedTime();

    Font _font = Font("Assets/Fonts/millya_collins/MillyaCollins.otf");
    Text _text = Text(_font, "avale moi");
    _text.setString("UwU suce moi");


    string _tabText[4] = { "feur", "ratio", "j'aime", "pas" };
    Font _fontTab[2] = { Font("Assets/Fonts/millya_collins/MillyaCollins.otf"), Font("Assets/Fonts/SuperBasic.ttf") };
    int _index = 0;
    int _indexFont = 0;

    while (_mainWindow.isOpen())
    {
        _elapsedTime = _clock.restart();
        while (const optional _event = _mainWindow.pollEvent())
        {
            if (_event->is<Event::Closed>())
            {
                _mainWindow.close();
            }

            /*else if(_event->is<Event::FocusGained>())
            {
                cout << "bite" << endl;
            }

            else if (_event->is<Event::FocusLost>())
            {
                cout << "avale" << endl;
            }*/

            else if (_event->is<Event::MouseLeft>())
            {
                cout << "Mouse Left" << endl;
            }

            /*else if (const Event::KeyPressed* _key = _event->getIf<Event::KeyPressed>())
            {
                if (_key->code == Keyboard::Key::Escape)
                {
                    _mainWindow.close();
                }
            }*/



            else if (const Event::KeyPressed* _key = _event->getIf<Event::KeyPressed>())
            {
                int _factorY = _key->code == Keyboard::Key::Z ? -10 : _key->code == Keyboard::Key::S ? 10 : 0;
                int _factorX = _key->code == Keyboard::Key::Q ? -10 : _key->code == Keyboard::Key::D ? 10 : 0;

                if (_key->code == Keyboard::Key::A)
                {
                    _rect.rotate(radians(float(11 * M_PI / 6)));
                }
                else if (_key->code == Keyboard::Key::S)
                {
                    UpdateTexture(_rect, 0, _tileIndex, _pixelCount, _tileSize, _isWalking, Keyboard::Key::S);
                }
                else if (_key->code == Keyboard::Key::Z)
                {
                    UpdateTexture(_rect, 3, _tileIndex, _pixelCount, _tileSize, _isWalking, Keyboard::Key::Z);
                }
                else if (_key->code == Keyboard::Key::D)
                {
                    UpdateTexture(_rect, 2, _tileIndex, _pixelCount, _tileSize, _isWalking, Keyboard::Key::D);
                }
                else if (_key->code == Keyboard::Key::Q)
                {
                    UpdateTexture(_rect, 1, _tileIndex, _pixelCount, _tileSize, _isWalking, Keyboard::Key::Q);
                }

                else if (_key->code == Keyboard::Key::Space)
                {
                    _text.setString(_tabText[++_index % 4]);
                }

                else if (_key->code == Keyboard::Key::LControl)
                {
                    _text.setFont(_fontTab[++_indexFont % 2]);
                }

                if (_key->code == Keyboard::Key::LShift)
                {
                    _isWalking = !_isWalking;
                }
                _rect.move(Vector2f(float(_factorX), float(_factorY)) * _elapsedTime.asSeconds() * (_isWalking ? 100.0F : 1000.0F));
            }

            else if (const Event::MouseWheelScrolled* _wheel = _event->getIf<Event::MouseWheelScrolled>())
            {
                if (_wheel->wheel == Mouse::Wheel::Vertical)
                {
                    const unsigned int _wheelSpeed = static_cast<unsigned int>(5 * _wheel->delta);
                    _mainWindow.setSize(_mainWindow.getSize() + Vector2u(_wheelSpeed, _wheelSpeed));
                }
            }

            else if (_event->is<Event::FocusGained>())
            {
                _mainWindow.setMouseCursorVisible(false);
            }

            else if (_event->is<Event::FocusLost>())
            {
                _mainWindow.setMouseCursorVisible(true);
            }

            else if (_event->is < Event::MouseEntered>())
            {
                Mouse::setPosition({ 250,250 }, _mainWindow);
            }
            else if (_event->is < Event::MouseLeft>())
            {
                Mouse::setPosition({ 0,0 });
            }

        }
        _mainWindow.clear(Color::Red);
        _mainWindow.draw(_text);
        _mainWindow.display();
    }

    return 0;
}