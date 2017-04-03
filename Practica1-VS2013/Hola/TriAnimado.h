#pragma once

#include "MallaTriangulo.h"

class TriAnimado
{
public:
	TriAnimado();
	TriAnimado(int _radio);
	TriAnimado(int _radio, double _anguloR, double _anguloRZ, double _radioR);
	~TriAnimado();

	void update(double _angulo);
	void draw();
	void drawTex();
	void set(MallaTriangulo t) { Triangulo = t; };
	void set(double _anguloR, double _anguloRZ, double _radioR) { anguloR = _anguloR; anguloRZ = _anguloRZ; radioR = _radioR; };
	void set(int ancho, int alto) { Triangulo.setCoordenadasTextura(ancho, alto); };

protected:
	MallaTriangulo Triangulo;

	double anguloR;
	double anguloRZ;
	double radioR;
};

