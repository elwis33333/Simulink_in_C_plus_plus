/**
 * \file ObiektFactory.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy ObiektFactory.
*/
#pragma once
#include <string>
#include "Obiekt.hpp"
/**
 * \class ObiektFactory
 * \brief Klasa odpowiedzialna za tworzenie obiektów danego rodzaju
 */
class ObiektFactory {
public:
    //! Tworzy i zwraca nowy czlon calkujacy.
    static Obiekt::Ptr makeCzlonCalkujacy(const std::string& name, Scalar T);
    //! Tworzy i zwraca nowy obiekt inercyjny.
    static Obiekt::Ptr makeCzlonInercyjny(const std::string& name,Scalar k, Scalar T);
     //! Tworzy i zwraca nowy obiekt oscylacyjny.
    static Obiekt::Ptr makeCzlonOscylacyjny(const std::string& name,Scalar k, Scalar T, Scalar zeta);
      //! Tworzy i zwraca nowy obiekt regulator PID.
    static Obiekt::Ptr makeCzlonPID(const std::string& name,Scalar k, Scalar Ti, Scalar Td, Scalar T);
    //! Tworzy i zwraca blok stalej
    static Obiekt::Ptr makeStala(const std::string& name, Scalar value);
    //! Tworzy i zwraca blok wypisujacy na ekran
    static Obiekt::Ptr makeScope(const std::string& name);
    /**
     * @brief Tworzy i zwraca nowy obiekt wedlug podanej nazwy.
     * @param type [in] typ obiektu do utworzenia (czlon_calkujacy, ...)
     * @param params [in] wektor parametrow
     * @return Nowy obiekt.
     */
    static Obiekt::Ptr makeObiekt(const std::string& name, const std::string& type, const std::vector<double>& params);
};
