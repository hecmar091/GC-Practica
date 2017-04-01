#pragma once

#include "tipos.h"

class MallaTriangulo
{
public:
	MallaTriangulo();
	MallaTriangulo(int radio);
	~MallaTriangulo();

	PVec3 vertices[3], normales[3];

	void draw();

protected:
	void activar();
	void desactivar();
};

