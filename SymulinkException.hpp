/**
 * \file SymulinkException.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy SymulinkException.
*/
#pragma once
#include <exception>
/**
 * \class SymulinkException
 * \brief Klasa wyswietlajaca bledy powstale przy symulacji
 */
class SymulinkException : public std::exception {
public:
    SymulinkException(const char* msg) : _msg(msg) {}
    virtual ~SymulinkException() {}
    //! Zwroc informacje o bledzie.
    const char* what() { return _msg; }
private:
    const char* _msg;
};
