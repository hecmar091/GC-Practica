#include "Textura.h"
#include "PixMap24RGB.h"


bool Textura::load(const std::string & BMP_Name) {
	// la textura debe estar inicializada -> escena::init()
	PixMap24RGB pixMap;
	pixMap.load_bmpBGR(BMP_Name);
	// cargar
	// carga correcta??
	w = pixMap.width();
	h = pixMap.height();
	glBindTexture(GL_TEXTURE_2D, id);
	// transferir a openGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, pixMap.map());

	return true;
}

bool Textura::load(const std::string & BMP_Name, GLubyte alpha) {
	// la textura debe estar inicializada -> escena::init()
	PixMap24RGB pixMap;
	pixMap.load_bmpBGR(BMP_Name);
	// cargar
	// carga correcta??
	w = pixMap.width();
	h = pixMap.height();
	glBindTexture(GL_TEXTURE_2D, id);
	// transferir a openGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, pixMap.map());

	return true;
}

bool Textura::load(const std::string & BMP_Name, PixMap24RGB::rgb_color colorKey, GLubyte alpha) {
	// la textura debe estar inicializada -> escena::init()
	PixMap24RGB pixMap;
	pixMap.load_bmpBGR(BMP_Name);
	// cargar
	// carga correcta??
	w = pixMap.width();
	h = pixMap.height();
	glBindTexture(GL_TEXTURE_2D, id);
	// transferir a openGL
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, pixMap.map());

	return true;
}

void Textura::save(const std::string & BMP_Name){
	//IMportanteactivar la textura si no no las ve
	PixMap24RGB pixMap;

	GLint numBytes = w * h * 4;

	unsigned char *pixels = (unsigned char*)malloc(numBytes); // allocate image data into RAM

	//obtener imagen
	glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	//crear mapa
	pixMap.create_pixmap(this->w, this->h);

	pixMap.save_bmpBGR(BMP_Name);

	free(pixels);

}
