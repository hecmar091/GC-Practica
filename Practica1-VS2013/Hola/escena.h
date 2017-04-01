//#pragma once
#ifndef _H_escena_H_
#define _H_escena_H_

#include "tipos.h"
#include "MallaTriangulo.h"
#include "TriAnimado.h"
#include "PiramideTri.h"

//-------------------------------------------------------------------------
class Ejes {
public:
  Ejes(GLdouble l);
  ~Ejes(){};
  void draw();
public:
  PVec3 vertices[6];
  PVec3 colores[6];
};

//-------------------------------------------------------------------------

class Escena {
public:
	Escena() : ejes(200), triangulo(50), trianguloAnimado(50, 0, 0, 100.0), piramide(50, 90) {};
  ~Escena();
  void init();
  void draw();
public:
  Ejes ejes;
  MallaTriangulo triangulo;
  TriAnimado trianguloAnimado;
  PiramideTri piramide;
};

//-------------------------------------------------------------------------

#endif  // _H_escena_H_
