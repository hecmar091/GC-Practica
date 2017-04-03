//#pragma once
#ifndef _H_escena_H_
#define _H_escena_H_

#include "tipos.h"
#include "MallaTriangulo.h"
#include "TriAnimado.h"
#include "PiramideTri.h"
#include "Textura.h"
#include "Rectangulo.h"

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
	Escena() : ejes(200), triangulo(50), trianguloAnimado(), piramide(50, 90), rectangulo(100, 50), estado(RECORTAR) {};
	~Escena();
	void init();
	void draw();
	void resize(int nuevoAncho, int nuevoAlto);
	void update(double angulo);
	void setEstado(EEstado nuevoEstado) { estado = nuevoEstado; };
	void initTriAnimado(){ trianguloAnimado.set(triangulo); trianguloAnimado.set(0, 0, 100); trianguloAnimado.set(ancho, alto); };
	void initDiabolo(){ piramideAnimada = PiramideTri(trianguloAnimado, 92); };
	void rotarTriangulo(){ if (estado == RECORTAR) triangulo.rotar(); };
	void motion(double x, double y);
protected:
	Ejes ejes;
	MallaTriangulo triangulo;
	TriAnimado trianguloAnimado;
	PiramideTri piramide;
	PiramideTri piramideAnimada;
	Textura textura;
	Rectangulo rectangulo;

	int ancho;
	int alto;
	EEstado estado;
};

//-------------------------------------------------------------------------

#endif  // _H_escena_H_
