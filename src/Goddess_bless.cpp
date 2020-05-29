#include "SFML/Graphics.hpp"
#include "end.hpp"
#include "life.hpp"
#include "mas.hpp"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
using namespace std;
using namespace sf;

class sprite_class {
private:
    Texture texture_t;
    Sprite sprite_t;

public:
    void init_sprite(
            int x,
            int y,
            int width,
            int height,
            int pos_x,
            int pos_y,
            int num_anim,
            string name)
    {
        texture_t.loadFromFile(name);
        sprite_t.setTexture(texture_t);
        sprite_t.setTextureRect(IntRect(x * num_anim, y, width, height));
        sprite_t.setPosition(pos_x, pos_y);
    }
    void set_anim_frame(int x, int y, int width, int height, int num_anim)
    {
        sprite_t.setTextureRect(IntRect(x * num_anim, y, width, height));
    }
    void init_sprite(int pos_x, int pos_y, string name)
    {
        texture_t.loadFromFile(name);
        sprite_t.setTexture(texture_t);
        sprite_t.setPosition(pos_x, pos_y);
    }
    void sprite_draw(RenderWindow& window)
    {
        window.draw(sprite_t);
    }
    void set_pos(int pos_x, int pos_y)
    {
        sprite_t.setPosition(pos_x, pos_y);
    }
};

class text_class {
private:
    Text text_t;

public:
    void init_text(
            const wstring& str, int font_size, Font& font, int pos_x, int pos_y)
    {
        text_t.setFont(font);
        text_t.setCharacterSize(font_size);
        text_t.setString(str);
        text_t.setPosition(pos_x, pos_y);
    }
    void set_text(const string str, RenderWindow& window)
    {
        text_t.setString(str);
        window.draw(text_t);
    }
    void text_draw(RenderWindow& window)
    {
        window.draw(text_t);
    }
};
void set_text_arr(
        const string str1,
        const string str2,
        const string str3,
        const string str4,
        RenderWindow& window,
        text_class text_box[])
{
    text_box[0].set_text(str1, window);
    text_box[1].set_text(str2, window);
    text_box[2].set_text(str3, window);
    text_box[3].set_text(str4, window);
}
bool check_mouse(
        RenderWindow& window, int startX, int startY, int n, int tilesize)
{
    if (Mouse::getPosition(window).x >= startX
        && sf::Mouse::getPosition(window).y >= startY
        && sf::Mouse::getPosition(window).y <= ((n)*tilesize + startY)
        && sf::Mouse::getPosition(window).x <= ((n)*tilesize + startX))
        return 1;
    return 0;
}
void goddess_set_anim(
        int num_anim,
        sprite_class& goddess,
        text_class* text_box,
        RenderWindow& window)
{
    switch (num_anim) {
    case 2:
        set_text_arr(
                "Greatings Anon!",
                "I am the computer Goddess",
                "And I give you this world.",
                "Give him a life!",
                window,
                text_box);
        break;
    case 3:
        goddess.set_anim_frame(522, 0, 522, 919, 0);
        set_text_arr(
                "Life is wonderful, isn't it? ^^",
                "",
                "",
                "",
                window,
                text_box);
        break;
    case 4:
        goddess.set_anim_frame(522, 0, 700, 919, 4);
        set_text_arr(
                "Destroy your whole life?",
                "How cruel ...",
                "",
                "",
                window,
                text_box);
        break;
    case 5:
        goddess.set_anim_frame(522, 0, 522, 919, 0);
        set_text_arr(
                "It looks like your life does",
                "success!~",
                "",
                "",
                window,
                text_box);
        break;
    case 6:
        goddess.set_anim_frame(522, 0, 522, 919, 2);
        set_text_arr("Sugoi, desu (>w<)", "", "", "", window, text_box);
        break;
    case 7:
        goddess.set_anim_frame(522, 0, 522, 919, 3);
        set_text_arr(
                "It looks like you gave the world",
                "too little life...",
                "",
                "",
                window,
                text_box);
        break;
    case 8:
        goddess.set_anim_frame(522, 0, 522, 919, 3);
        set_text_arr(
                "The stagnation of the world",
                "is the same as death...",
                "",
                "",
                window,
                text_box);
        break;
    case 9:
        goddess.set_anim_frame(522, 0, 522, 919, 1);
        set_text_arr(
                "Enter - start, S - stop, Space - rand",
                "Q - line, R - reset",
                "Right - +size Left - -size",
                "Up - +speed, Down - -speed",
                window,
                text_box);
        break;
    case 10:
        goddess.set_anim_frame(522, 0, 522, 919, 0);
        set_text_arr(
                "More or less, it does not matter",
                "",
                "",
                "",
                window,
                text_box);
        break;
    case 11:
        goddess.set_anim_frame(522, 0, 522, 919, 0);
        set_text_arr(
                "Wow, this may take some time", "", "", "", window, text_box);
        break;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    bool isMove = false, world_started = 0;
    int n = 400, day_num = 0, coord_num = 10, delay_t = 50000, startX = 700,
        startY = 50, tilesize = 16, num_scene = 2;
    int pos_j, pos_i;
    string* coord_world;
    coord_world = new string[coord_num];
    int** world;
    world = new int*[n];
    int** world_after;
    world_after = new int*[n];
    null_compare_coord(coord_world, coord_num);
    for (int i = 0; i < n; i++) {
        world[i] = new int[n];
        world_after[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            world[i][j] = 0;
            world_after[i][j] = 0;
        }
    }
    n = 50;
    sprite_class fon, goddess, planet, box, day_box, yan;
    fon.init_sprite(0, 0, "./sprite/fon.png");
    planet.init_sprite(startX - 182, startY - 185, "./sprite/planet.png");
    box.init_sprite(10, 410, "./sprite/box.png");
    day_box.init_sprite(0, 0, "./sprite/day.png");
    goddess.init_sprite(522, 0, 522, 919, 0, -19, 1, "./sprite/nep.png");
    Font font;
    font.loadFromFile("./font/font.ttf");
    text_class text_box[4], textsp, day_num_text, num_text;
    for (int i = 0; i < 4; i++) {
        text_box[i].init_text(L"", 30, font, 88, 660 + 45 * i);
    }
    textsp.init_text(L"", 30, font, 98, 560);
    day_num_text.init_text(L"", 32, font, 110, 32);
    num_text.init_text(L"", 32, font, 35, 32);
    RenderWindow window(VideoMode(1600, 900), "Goddess bless this PC");
    window.clear(Color::White);
    RectangleShape rectangle(Vector2f(tilesize, tilesize));
    RectangleShape rectangle_life(Vector2f(tilesize, tilesize));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (world[i][j] == 0) {
                rectangle.setFillColor(Color::Transparent);
                rectangle.setOutlineColor(Color::Black);
                rectangle.setOutlineThickness(1);
            }
            if (world[i][j] == 1) {
                rectangle_life.setFillColor(Color::Green);
            }
        }
    }
    while (window.isOpen()) {
        switch (num_scene) {
            Event event;
        case 1:
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();
                if (event.type == Event::MouseButtonPressed) {
                    if (check_mouse(window, startX, startY, n, tilesize))
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            isMove = true;
                        }
                }
                if (event.type == Event::MouseButtonPressed) {
                    if (check_mouse(window, startX, startY, n, tilesize)) {
                        if (event.mouseButton.button == sf::Mouse::Right) {
                            Vector2i pixelPos = Mouse::getPosition(window);
                            pos_j = (pixelPos.x - startX) / tilesize;
                            pos_i = (pixelPos.y - startY) / tilesize;
                            if (pos_j < n && pos_i < n)
                                world[pos_i][pos_j] = 0;
                        }
                    } else {
                        Vector2i pixelPos = Mouse::getPosition(window);
                        if (pixelPos.x <= 600)
                            goddess_set_anim(9, goddess, text_box, window);
                    }
                }
                if (event.type == Event::MouseButtonReleased)
                    if (event.mouseButton.button == sf::Mouse::Left)
                        isMove = false;
                if (isMove) {
                    Vector2i pixelPos = Mouse::getPosition(window);
                    if (check_mouse(window, startX, startY, n, tilesize)) {
                        pos_j = (pixelPos.x - startX) / tilesize;
                        pos_i = (pixelPos.y - startY) / tilesize;
                        if (pos_j < n && pos_i < n)
                            world[pos_i][pos_j] = 1;
                        goddess_set_anim(3, goddess, text_box, window);
                        day_num = 0;
                    }
                }
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::S) {
                        world_started = 0;
                    }
                    if (event.key.code == sf::Keyboard::Return) {
                        if (!world_started)
                            world_started = 1;
                        goddess.set_anim_frame(522, 0, 522, 919, 0);
                        day_num = 0;
                    }
                    if (event.key.code == Keyboard::R) {
                        goddess_set_anim(4, goddess, text_box, window);
                        null_mas(world, n);
                        day_num = 0;
                        world_started = 0;
                    }
                    if (event.key.code == Keyboard::Space) {
                        rand_mas(world, n);
                        day_num = 0;
                    }
                    if (event.key.code == Keyboard::Up) {
                        delay_t += 10000;
                    }
                    if (event.key.code == Keyboard::Down) {
                        if (delay_t >= 10000)
                            delay_t -= 10000;
                    }
                    if (event.key.code == Keyboard::Right
                        || event.key.code == Keyboard::Left) {
                        if (event.key.code == Keyboard::Left) {
                            if (n != 6) {
                                n /= 2;
                                tilesize *= 2;
                            }
                        } else {
                            if (tilesize != 2) {
                                n *= 2;
                                tilesize /= 2;
                            }
                        }
                        if (tilesize <= 4) {
                            goddess_set_anim(11, goddess, text_box, window);
                            rectangle.setOutlineThickness(0);
                        } else {
                            goddess_set_anim(10, goddess, text_box, window);
                            rectangle.setOutlineThickness(1);
                        }
                        day_num = 0;
                        world_started = 0;
                        rectangle.setSize(Vector2f(tilesize, tilesize));
                        rectangle_life.setSize(Vector2f(tilesize, tilesize));
                        null_compare_coord(coord_world, coord_num);
                    }
                    if (event.key.code == Keyboard::Q) {
                        for (int i = 0; i < n; i++) {
                            world[n / 2][i] = 1;
                        }
                        day_num = 0;
                    }
                }
            }
            fon.sprite_draw(window);
            planet.sprite_draw(window);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    rectangle_life.setPosition(
                            j * tilesize + startX, i * tilesize + startY);
                    if (world[i][j] == 1) {
                        rectangle_life.setFillColor(Color(173, 255, 47));
                    } else {
                        rectangle_life.setFillColor(Color::Transparent);
                        rectangle.setPosition(
                                j * tilesize + startX, i * tilesize + startY);
                    }
                    window.draw(rectangle_life);
                    window.draw(rectangle);
                }
            }
            window.draw(rectangle);
            if (world_started) {
                day(world, world_after, n);
                if (day_num <= 30) {
                    goddess_set_anim(5, goddess, text_box, window);
                }
                if (day_num > 100) {
                    goddess_set_anim(6, goddess, text_box, window);
                }
                day_num++;
                get_coordinates(
                        world_after, coord_world[day_num % (coord_num)], n);
                if (compare_coordinates(coord_world, coord_num)) {
                    if (check_null_world(world, n))
                        goddess_set_anim(7, goddess, text_box, window);
                    else
                        goddess_set_anim(8, goddess, text_box, window);
                    world_started = 0;
                    day_num--;
                    null_compare_coord(coord_world, coord_num);
                }
                copy_mas(world, world_after, n);
                null_mas(world_after, n);
                usleep(delay_t);
            }
            goddess.sprite_draw(window);
            box.sprite_draw(window);
            day_box.sprite_draw(window);
            num_text.set_text("Day: ", window);
            day_num_text.set_text(to_string(day_num), window);
            for (int i = 0; i < 4; i++) {
                text_box[i].text_draw(window);
            }
            textsp.set_text("Goddess", window);
            window.display();
            break;
        case 2:
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();
            }
            fon.sprite_draw(window);
            planet.sprite_draw(window);
            goddess.sprite_draw(window);
            box.sprite_draw(window);
            textsp.set_text("Goddess", window);
            goddess_set_anim(1, goddess, text_box, window);
            window.display();
            goddess_set_anim(2, goddess, text_box, window);
            fon.sprite_draw(window);
            planet.sprite_draw(window);
            goddess.sprite_draw(window);
            box.sprite_draw(window);
            textsp.set_text("Goddess", window);
            num_scene = 1;
            window.display();
            break;
        }
    }
    return 0;
}
