/**
 * \file Sygnal.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy Sygnal.
*/
#pragma once
#include "Types.hpp"
#include <iostream>
/**
 * \class Sygnal
 * \brief Klasa reprezentujaca sygnal laczacy dwa obiekty
 */
class Sygnal {
public:
    typedef std::shared_ptr<Sygnal> Ptr;
    Sygnal(const std::string& name, unsigned size=1) :
      _name(name),
      _size(size),
      _value(0.0, size)
    {}
    const std::string& getName() const { return _name; }
    unsigned getSize() const { return _size; }
    const Vector& getValue() const { return _value; }
    void setValue(const Vector& value) { _value = value; }
private:
    std::string _name;
    unsigned _size;
    Vector _value;
};
