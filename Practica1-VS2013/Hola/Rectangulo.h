#pragma once

#include "tipos.h"

class Rectangulo
{
public:
	Rectangulo();
	Rectangulo(int _ancho, int _alto);
	~Rectangulo();

	void set(int _ancho, int _alto);
	void draw();

protected:
	int ancho;
	int alto;
	PVec3 vertices[4];
	PVec3 normal;
	Color4 color;
	CTex2 coordenadasTextura[4];
};

