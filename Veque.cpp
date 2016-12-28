#include "Veque.hpp"
#include <cstdio>

void Veque::reserve(int _num)
{
    if(_num <= 0) return;

    int i = aloc;

    aloc += _num;

    sf::Sprite **qubby = (sf::Sprite**)memcpy(new sf::Sprite*[aloc], sprite, num * sizeof(sf::Sprite*));

    for(; i < aloc; ++i)
        qubby[i] = nullptr;

    delete[] sprite;
    sprite = qubby;
}

int Veque::capacity()
{
    return aloc - num;
}

void Veque::move(int what, int where, int _num)
{
    if(where < -1 ||
       where >  num - 1 ||
       what < -1 ||
       _num < 1 ||
       what + _num > num ||
       what == where) return;

    if(where == -1) where = num - 1;

    sf::Sprite **qubby = (sf::Sprite**)memcpy(new sf::Sprite*[_num], sprite + what, _num * sizeof(sf::Sprite*));

    if(what < where)
        memmove(sprite + what, sprite + what + _num, (where - what) * sizeof(sf::Sprite*));
    else
        memmove(sprite + where + _num, sprite + where, (what - where) * sizeof(sf::Sprite*));

    memcpy(sprite + where, qubby, _num * sizeof(sf::Sprite*));

    delete[] qubby;
}

void Veque::push(sf::Sprite *_sprite, int to)
{
    if(aloc - num == 0) reserve();

    sprite[num] = _sprite;

    ++num;

    if(to >= 0 && to < num)
        move(num - 1, to);
}

int Veque::size()
{
    return num;
}

sf::Sprite *Veque::get(int _num)
{
    if(_num < -1 || _num > aloc - 1)
        return nullptr;
    else if(_num == -1)
        return sprite[num - 1];
    else
        return sprite[_num];
}

void Veque::copy(int what, int where)
{
    if(where < -1 || where >  aloc - 1 ||
       what < -1 || what >  aloc - 1) return;

    if(what == -1) what = num - 1;

    sf::Sprite *qubby = new sf::Sprite;
    *qubby = *sprite[what];
    push(qubby, where);
}

void Veque::erase(int from, int _num)
{
    if(from == -1) from = num - 1;
    if(from < 0 || _num < 1 || from + _num > aloc) return;

    for(int i = from; i < _num + from; ++i)
        delete sprite[i];

    if(from + _num > num)
        num -= from + _num - num;
    else
        num -= _num;

    aloc -= _num;

    sf::Sprite **qubby = (sf::Sprite**)memcpy(new sf::Sprite*[aloc], sprite, (from) * sizeof(sf::Sprite*));

    memcpy(qubby + from, sprite + from + _num, (aloc - from) * sizeof(sf::Sprite*));

    delete[] sprite;

    sprite = qubby;
}

void Veque::clear()
{
    for(int i = 0; i < num; ++i)
    {
        delete sprite[i];
    }

    delete[] sprite;

    sprite = nullptr;
    num = 0;
    aloc = 0;
}

void Veque::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < num; ++i)
        window.draw(*sprite[i]);
}


