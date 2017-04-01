#pragma once

#include "MallaTriangulo.h"

class TriAnimado
{
public:
	TriAnimado();
	TriAnimado(int _radio);
	TriAnimado(int _radio, float _anguloR, float _anguloRZ, float _radioR);
	~TriAnimado();

	void update(float _angulo);
	void draw();

protected:
	MallaTriangulo Triangulo;

	float anguloR;
	float anguloRZ;
	float radioR;
};

