/**
 * \file Model.hpp
 * \author Piotr Burzynski
 * \date 23-01-2019
 *
* Plik zawierajacy deklaracje klasy Model. Mo¿na go porównaæ do okna programu Simulink.
*/
#pragma once
#include "Types.hpp"
#include "Sygnal.hpp"
#include "Obiekt.hpp"
#include "Sumator.hpp"
/**
 * \class Model
 * \brief Klasa skladajaca sie z sygnalow oraz obiektow odpowiednio polaczonych sygnalami
 */
class Model {
public:
  typedef std::shared_ptr<Model> Ptr;
  Model(const std::string name="model") :
    _name(name) {
  }
  virtual ~Model() {}
  void update(Scalar t, Scalar dt);
  void addSygnal(Sygnal::Ptr s);
  void addObiekt(Obiekt::Ptr o, const std::vector<std::string> inputs, const std::string& output);
private:
  struct ObiektInfo {
    std::vector<Sygnal::Ptr> inputs;
    Sygnal::Ptr output;
    Obiekt::Ptr obiekt;
  };
  std::string _name;
  std::map<std::string, Sygnal::Ptr> _sygnaly;
  std::vector<ObiektInfo> _obiekty;
};
