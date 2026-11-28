/* The demo's OpenGL emulation (C linkage; its own objects define these,
   several as empty functions taking no arguments). */
#ifndef DEMO_DUCK_GL_HPP
#define DEMO_DUCK_GL_HPP

/* the demo's OpenGL emulation (C linkage) */
extern "C" {
typedef unsigned int GLenum;
typedef float GLfloat;
void glPushMatrix(void);
void glPopMatrix(void);
void glMultMatrixf(const GLfloat *);
void glScalef(GLfloat, GLfloat, GLfloat);
void glDisable(GLenum);
void glEnable(GLenum);
void glBlendFunc(GLenum, GLenum);
void glPolygonMode(GLenum, GLenum);
void glPushAttrib(unsigned int);
void glPopAttrib(void);
void glBegin(GLenum);
void glEnd(void);
void glColor3f(GLfloat, GLfloat, GLfloat);
void glNormal3f(GLfloat, GLfloat, GLfloat);
void glVertex3f(GLfloat, GLfloat, GLfloat);
void glVertex3fv(const GLfloat *);
void glTexCoord2f(GLfloat, GLfloat);
void glTranslatef(GLfloat, GLfloat, GLfloat);
void glClearColor(GLfloat, GLfloat, GLfloat, GLfloat);
void glGenTextures(int, unsigned int *);
void glDeleteTextures(int, const unsigned int *);
int glGetError(void);
void glShadeModel(GLenum);
void glCullFace(GLenum);
void glDepthFunc(GLenum);
void glColor3ub(unsigned char, unsigned char, unsigned char);
}
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_QUADS 0x0007
#define GL_TEXTURE_2D 0x0DE1
#define GL_LIGHTING 0x0B50
#define GL_ENABLE_BIT 0x00002000

#endif
