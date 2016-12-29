#ifndef Veque_hpp
#define Veque_hpp

#include <SFML/Graphics.hpp>

#include <cstring>

#define alocsize 10 // Ilość automatycznego alokowanego miejsca

class Veque
{
    int num;

    int aloc;

protected:
    sf::Sprite **sprite;                                            // Funkcja pobiera wskaźniki na elementy,
                                                                    // więc nie mogą zostać usunięte bez wiedzy wektora :p

public:
    Veque():num(0), aloc(0),                                        // Konstruktor ;)
    sprite(nullptr){}

    ~Veque(){clear();}                                              // Destruktor ;(

    void reserve(int _num = alocsize);                              // Rezerwuje _num zmiennych

    int capacity();                                                 // Zwraca ilość elementów które można jeszcze dodać
                                                                    // bez ponownej alokacji pamięci

    void move(int what, int where = -1, int _num = 1);              // Przenosi _num elementów z jednego miejsca w drugie
                                                                    // -1 == num - 1

    void push(sf::Sprite *_sprite = new sf::Sprite, int to = -1);   // Dodawanie nowego obiektu,
                                                                    // Domyślnie na koniec
                                                                    // Ogólnie push_back i insert w jednym :p

    int size();                                                     // Zwraca ilość elementów w tablicy

    sf::Sprite *get(int _num = -1);                                 // Zwraca wskaźnik na obiekt o podanym numerze od 0 do size()
                                                                    // Domyślnie końcowy

    void copy(int what = -1, int where = -1);                       // Kopiuje element do wybranego miejsca
                                                                    // Użycie copy() skopiuje ostatni Sprite i doda go na koniec

    void erase(int from = -1, int _num = 1);                        // Usuwa _num wartości zaczynając od from włącznie,
                                                                    // jeśli sie da usuwa także objekt,
                                                                    // zsuwa elementy położone wyżej
                                                                    // Użycie erase() usunie jeden ostatni element

    void clear();                                                   // Usuwa elementy i Czyści tablicę

    void draw(sf::RenderWindow &window);                            // I wreszcie metoda dla której to wszystko robie XD
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

#undef alokacja

#endif // Veque_hpp
















