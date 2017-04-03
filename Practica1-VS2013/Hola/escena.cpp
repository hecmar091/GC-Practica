#include "escena.h"
#include <GL/freeglut.h>

//-------------------------------------------------------------------------

void Escena::init()
{
	// texturas
	glEnable(GL_TEXTURE_2D);
	textura.init();
	textura.load("../bmps/ray.bmp");
	// luces
}

//-------------------------------------------------------------------------

Escena::~Escena()
{
   // liberar memoria y recursos
}

//-------------------------------------------------------------------------

void Escena::draw()
{
	switch (estado)
	{
	case COLLAGE:
		break;
	case RECORTAR:
		glDisable(GL_DEPTH_TEST);
		textura.activar();
		rectangulo.draw();
		textura.desactivar();
		triangulo.draw();
		break;
	case ANIMAR:
		textura.activar();
		trianguloAnimado.drawTex();
		textura.desactivar();
		break;
	case DIABOLO:
		glDisable(GL_DEPTH_TEST);
		textura.activar();
		piramide.drawDiaboloTex();
		textura.desactivar();
		break;
	default:
		break;
	}
}

void Escena::resize(int nuevoAncho, int nuevoAlto)
{
	ancho = nuevoAncho;
	alto = nuevoAlto;

	rectangulo.set(ancho, alto);
}

void Escena::update(double angulo)
{
	if (estado == ANIMAR) trianguloAnimado.update(angulo);
}

void Escena::motion(double x, double y)
{
	if (triangulo.dentro(x, y))
	{
		triangulo.posicionar(x, y);
	}
}
//-------------------------------------------------------------------------

Ejes::Ejes(GLdouble l) {
  vertices[0].set(0, 0, 0);
  vertices[1].set(l, 0, 0);
  vertices[2].set(0, 0, 0);
  vertices[3].set(0, l, 0);
  vertices[4].set(0, 0, 0);
  vertices[5].set(0, 0, l);

  colores[0].set(1, 0, 0);
  colores[1].set(1, 0, 0);
  colores[2].set(0, 1, 0);
  colores[3].set(0, 1, 0);
  colores[4].set(0, 0, 1);
  colores[5].set(0, 0, 1);
}

//-------------------------------------------------------------------------

void Ejes::draw(){
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0, vertices);
  glEnableClientState(GL_COLOR_ARRAY);
  glColorPointer(3, GL_DOUBLE, 0, colores);

  glLineWidth(2);
  glDrawArrays(GL_LINES, 0, 6); 
  glLineWidth(1);

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}
//-------------------------------------------------------------------------



