#pragma once

#include "tipos.h"

class MallaTriangulo
{
public:
	MallaTriangulo();
	MallaTriangulo(int _radio);
	~MallaTriangulo();
	
	void modificarVertice(PVec3 cero, int index);
	
	PVec3 obtenerVertice(int index);
	
	void draw();
	void drawTex();

protected:
	int radio;
	int angulo;
	PVec3 vertices[3], normales[3];
	PVec3 centro;
	CTex2 coordenadasTextura[3];
	Color4 color;

	void activar();
	void desactivar();
};

