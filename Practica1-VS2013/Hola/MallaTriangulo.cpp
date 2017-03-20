#include "MallaTriangulo.h"

MallaTriangulo::MallaTriangulo()
{
	numDat = 3;
	vertices = normales = nullptr;
}

MallaTriangulo::MallaTriangulo(int radio)
{
	numDat = 3;
	vertices = new PVec3[numDat];
	normales = new PVec3[numDat];
}


MallaTriangulo::~MallaTriangulo()
{
	delete[] vertices;
	delete[] normales;
}

void MallaTriangulo::activar(){
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glNormalPointer(GL_DOUBLE, 0, normales); // (Tipo, Offset, PtrArray)
	glVertexPointer(3, GL_DOUBLE, 0, vertices);
}

void MallaTriangulo::desactivar(){
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
}

void MallaTriangulo::draw(){
	activar(); 
	glColor4d(1.0, 0.0, 0.0, 0.0); // color red
	glDrawArrays(GL_TRIANGLES, 0, numDat); 
	desactivar();
}
