#ifndef Veque_hpp
#define Veque_hpp

#define alocsize 10

class Veque
{
    int num;                                    // Ilość elementów ;P

    int aloc;                                   // Ilość zarezerwowanego miejsca

protected:
    sf::Sprite **sprite;                        // Funkcja pobiera wskaźniki na elementy,
                                                // więc nie mogą zostać usuniête bez wiedzy wektora :p

public:
    Veque():num(0), aloc(0),                    // Konstruktor ;)
    sprite(nullptr){}

    ~Veque(){clear();}                          // Destruktor ;(

    void reserve(int _num);                     // Rezerwuje miejsce domyślnie 10 (do zmiany w define)

    int capacity();                             // Zwraca ilość elementów które można jeszcze dodać
                                                // bez ponownej alokacji pamięci

    void move(int what, int where, int _num);   // Przenosi _num elementów z jednego miejsca w drugie
                                                // Domyślnie na koniec i domyślnie 1

    void push(sf::Sprite *_sprite, int to);     // Dodawanie nowego obiektu, obie opcje opcjonalnie,
                                                // Domyślnie na koniec
                                                // Ogólnie push_back i insert w jednym :p

    int size();                                 // Zwraca ilość elementów w tablicy

    sf::Sprite *get(int _num);                  // Zwraca wskaźnik na obiekt o podanym numerze od 0 do size()
                                                // Domyślnie końcowy

    void copy(int what, int where);             // Kopiuje element do wybranego miejsca
                                                // Domyślnie na koniec

    void erase(int from, int _num);             // Usuwa _num wartości zaczynając od from włącznie,
                                                // jeśli sie da usuwa także objekt,
                                                // zsuwa elementy położone wyżej
                                                // obie wartości opcjonalnie,
                                                // wtedy usuwa tylko jeden element od końca

    void clear();                               // Usuwa elementy i Czyści tablicę

    void draw(sf::RenderWindow &window);        // I wreszcie metoda dla której to wszystko robie XD
                                                // Rysuje wszystkie sprajty od 0 do size()

    // Opis do reszty pierdół których nie ma :p

    // Iterator a idź mi z tym XD
    // Funkcji działających z kontenerami nie ma bo prawdopodobnie jeden wystarczy :p
    // Funkcja  begin       get(0)
    // Funkcja  front       get(0)
    // Funkcja  end         get(size())
    // Funkcja  rbegin      get(size() - 1)
    // Funkcja  empty       size() == 0
    // Funkcja  pop_back    erase()
};

void Veque::reserve(int _num = alocsize)
{
    if(_num <= 0) return;

    aloc += _num;

    sf::Sprite **qubby = (sf::Sprite**)memcpy(new sf::Sprite*[aloc], sprite, num * sizeof(sf::Sprite*));

    delete[] sprite;
    sprite = qubby;
}

int Veque::capacity()
{
    return aloc - num;
}

void Veque::move(int what, int where = -1, int _num = 1)
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

void Veque::push(sf::Sprite *_sprite = new sf::Sprite, int to = -1)
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

sf::Sprite *Veque::get(int _num = -1)
{
    if(_num < -1 || _num > aloc - 1)
        return nullptr;
    else if(_num == -1)
        return sprite[num - 1];
    else
        return sprite[_num];
}

void Veque::copy(int what = -1, int where = -1)
{
    if(where < -1 || where >  aloc - 1 ||
       what < -1 || what >  aloc - 1) return;

    if(what == -1) what = num - 1;

    sf::Sprite *qubby = new sf::Sprite;
    *qubby = *sprite[what];
    push(qubby, where);
}

void Veque::erase(int from = -1, int _num = 1)
{
    if(from == -1) from = num - 1;
    if(from < 0 || _num < 1 || from + _num > aloc) return;

    return;

    for(int i = from; i < _num + from; ++i)
        delete sprite[i];

    if(from + _num > num)
        num -= from + _num - num;
    else
        num -= _num;

    aloc -= _num;

    sf::Sprite **qubby = (sf::Sprite**)memcpy(new sf::Sprite*[aloc], sprite, (from - 1) * sizeof(sf::Sprite*));
    memcpy(qubby + from, sprite + from + _num, (aloc - from) * sizeof(sf::Sprite*));

    delete[] sprite;

    sprite = qubby;

    sf::sleep(sf::seconds(5));
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

#undef alokacja

#endif // Veque_hpp
















