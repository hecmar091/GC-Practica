#pragma once

#include "tipos.h"

class MallaTriangulo
{
public:
	MallaTriangulo();
	MallaTriangulo(int radio);
	~MallaTriangulo();

	GLuint numDat;
	PVec3 *vertices, *normales;

	void draw();

protected:
	void activar();
	void desactivar();
};

