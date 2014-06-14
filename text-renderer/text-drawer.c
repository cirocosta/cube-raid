#include "text-drawer.h"

void TDRAWER_destroy(TDRAWER_Text * this)
{
	if (this != NULL) {
		free(this);
		this = NULL;
	}
}

void TDRAWER_draw(TDRAWER_Text * this)
{
	char * oldtext = this->text;
	if (this->text && strlen(this->text)) {
		glLoadIdentity();
		glRasterPos3f(this->position[0],
		              this->position[1],
		              this->position[2]);
		glColor4f(this->color[0],
		          this->color[1],
		          this->color[2],
		          this->color[3]);

		while (*this->text) {
			glutBitmapCharacter(this->font, *this->text);
			this->text++;
		}
		this->text = oldtext;
	}
}

TDRAWER_Text * TDRAWER_new(char * initialText)
{
	TDRAWER_Text * this = (TDRAWER_Text *) malloc(sizeof(*this));

	this->font = GLUT_BITMAP_HELVETICA_12;
	this->text = initialText;
	this->size = 1;
	this->position[0] =
		this->position[1] =
		this->position[2] = .0;
	this->color[0] =
		this->color[1] =
		this->color[2] =
		this->color[3] =  1.;

	return this;
}
