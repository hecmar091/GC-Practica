#ifndef _H_Textura_H
#define _H_Textura_H

//#include <Windows.h>
//#include <gl/GL.h>
#include "PixMap24RGB.h"
#include <GL/freeglut.h>
#include <string>


class Textura{
public:
	Textura() : w(0), h(0), id(0) {};
	~Textura() { glDeleteTextures(1, &id); };
	
	void init() {
		glGenTextures(1, &id); // generar un nombre
		
		activar();
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	};

	void activar() {
		// establecer filtros
		glBindTexture(GL_TEXTURE_2D, id);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	};
	
	void desactivar() {
		glBindTexture(GL_TEXTURE_2D, 0);
	};

	bool load(const std::string & BMP_Name); // cargar y transferir a openGL
	bool load(const std::string & BMP_Name, GLubyte alpha);
	bool load(const std::string & BMP_Name, PixMap24RGB::rgb_color colorKey, GLubyte alpha);

	void save(const std::string & BMP_Name); // obtener de openGL y guardar

public:
	GLuint w, h; // dimensiones de la imagen
	GLuint id;
	PixMap24RGB pix; // identificador interno de la textura
};

#endif
