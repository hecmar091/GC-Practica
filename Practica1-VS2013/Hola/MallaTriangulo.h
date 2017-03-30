#pragma once

#include "tipos.h"

class MallaTriangulo
{
public:
	MallaTriangulo();
	MallaTriangulo(int radio);
	MallaTriangulo(PVec3 v1, PVec3 v2, PVec3 v3);
	~MallaTriangulo();

	GLuint numDat;
	PVec3 *vertices, *normales;

	void draw();

protected:
	void activar();
	void desactivar();
};

