#pragma once

#include "tipos.h"

class MallaTriangulo
{
public:
	MallaTriangulo();
	MallaTriangulo(int radio);
	~MallaTriangulo();
	void modificarVertice(PVec3 cero, int index);
	PVec3 obtenerVertice(int index);
	PVec3 vertices[3], normales[3];

	void draw();

protected:
	void activar();
	void desactivar();
};

