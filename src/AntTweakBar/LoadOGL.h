//  ---------------------------------------------------------------------------
//
//  @file       LoadOGL.h
//  @brief      OpenGL declarations for dynamic loading
//  @author     Philippe Decaudin
//  @license    This file is part of the AntTweakBar library.
//              For conditions of distribution and use, see License.txt
//
//  note:       Private header
//
//  ---------------------------------------------------------------------------


#if !defined ANT_LOAD_OGL_INCLUDED
#define ANT_LOAD_OGL_INCLUDED

// Cinder: typedefs to avoid #including a gl.h here
#include "TwPrecomp.h"
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef int GLsizei;
#if defined( ANT_OSX )
	typedef long GLintptr;
	typedef long GLsizeiptr;
#endif
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef char GLchar;

// Cinder: this forces legacy headers to be included
#define ANT_GL_DECL(_Ret, _Fct, _Params) \
    extern "C" { typedef _Ret (APIENTRY* PFN##_Fct)_Params; } \
    namespace GL { extern PFN##_Fct _##_Fct; } \
    using GL::_##_Fct;

#if defined(ANT_WINDOWS)
#   define ANT_GL_IMPL(_Fct) \
        namespace GL { PFN##_Fct _##_Fct = (PFN##_Fct)Record(#_Fct, (PFNOpenGL*)(&_##_Fct)); }
#elif defined(ANT_UNIX) || defined(ANT_OSX)
#   define ANT_GL_IMPL(_Fct) \
        namespace GL { PFN##_Fct _##_Fct = _Fct; }
#   if !defined(APIENTRY)
#       define APIENTRY
#   endif
#endif

int LoadOpenGL();
int UnloadOpenGL();

namespace GL
{
    extern "C" { typedef void (APIENTRY* PFNOpenGL)(); }
    PFNOpenGL Record(const char *_FuncName, PFNOpenGL *_FuncPtr);

    extern "C" { typedef PFNOpenGL (APIENTRY *PFNGLGetProcAddress)(const char *); }
    extern PFNGLGetProcAddress _glGetProcAddress;
}
using GL::_glGetProcAddress;

 
ANT_GL_DECL(void, glAccum, (GLenum op, GLfloat value))
ANT_GL_DECL(void, glAlphaFunc, (GLenum func, GLclampf ref))
ANT_GL_DECL(GLboolean, glAreTexturesResident, (GLsizei n, const GLuint *textures, GLboolean *residences))
ANT_GL_DECL(void, glArrayElement, (GLint i))
ANT_GL_DECL(void, glBegin, (GLenum mode))
ANT_GL_DECL(void, glBindTexture, (GLenum target, GLuint texture))
ANT_GL_DECL(void, glBitmap, (GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap))
ANT_GL_DECL(void, glBlendFunc, (GLenum sfactor, GLenum dfactor))
ANT_GL_DECL(void, glCallList, (GLuint list))
ANT_GL_DECL(void, glCallLists, (GLsizei n, GLenum type, const GLvoid *lists))
ANT_GL_DECL(void, glClear, (GLbitfield mask))
ANT_GL_DECL(void, glClearAccum, (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha))
ANT_GL_DECL(void, glClearColor, (GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha))
ANT_GL_DECL(void, glClearDepth, (GLclampd depth))
ANT_GL_DECL(void, glClearIndex, (GLfloat c))
ANT_GL_DECL(void, glClearStencil, (GLint s))
ANT_GL_DECL(void, glClipPlane, (GLenum plane, const GLdouble *equation))
ANT_GL_DECL(void, glColor3b, (GLbyte red, GLbyte green, GLbyte blue))
ANT_GL_DECL(void, glColor3bv, (const GLbyte *v))
ANT_GL_DECL(void, glColor3d, (GLdouble red, GLdouble green, GLdouble blue))
ANT_GL_DECL(void, glColor3dv, (const GLdouble *v))
ANT_GL_DECL(void, glColor3f, (GLfloat red, GLfloat green, GLfloat blue))
ANT_GL_DECL(void, glColor3fv, (const GLfloat *v))
ANT_GL_DECL(void, glColor3i, (GLint red, GLint green, GLint blue))
ANT_GL_DECL(void, glColor3iv, (const GLint *v))
ANT_GL_DECL(void, glColor3s, (GLshort red, GLshort green, GLshort blue))
ANT_GL_DECL(void, glColor3sv, (const GLshort *v))
ANT_GL_DECL(void, glColor3ub, (GLubyte red, GLubyte green, GLubyte blue))
ANT_GL_DECL(void, glColor3ubv, (const GLubyte *v))
ANT_GL_DECL(void, glColor3ui, (GLuint red, GLuint green, GLuint blue))
ANT_GL_DECL(void, glColor3uiv, (const GLuint *v))
ANT_GL_DECL(void, glColor3us, (GLushort red, GLushort green, GLushort blue))
ANT_GL_DECL(void, glColor3usv, (const GLushort *v))
ANT_GL_DECL(void, glColor4b, (GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha))
ANT_GL_DECL(void, glColor4bv, (const GLbyte *v))
ANT_GL_DECL(void, glColor4d, (GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha))
ANT_GL_DECL(void, glColor4dv, (const GLdouble *v))
ANT_GL_DECL(void, glColor4f, (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha))
ANT_GL_DECL(void, glColor4fv, (const GLfloat *v))
ANT_GL_DECL(void, glColor4i, (GLint red, GLint green, GLint blue, GLint alpha))
ANT_GL_DECL(void, glColor4iv, (const GLint *v))
ANT_GL_DECL(void, glColor4s, (GLshort red, GLshort green, GLshort blue, GLshort alpha))
ANT_GL_DECL(void, glColor4sv, (const GLshort *v))
ANT_GL_DECL(void, glColor4ub, (GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha))
ANT_GL_DECL(void, glColor4ubv, (const GLubyte *v))
ANT_GL_DECL(void, glColor4ui, (GLuint red, GLuint green, GLuint blue, GLuint alpha))
ANT_GL_DECL(void, glColor4uiv, (const GLuint *v))
ANT_GL_DECL(void, glColor4us, (GLushort red, GLushort green, GLushort blue, GLushort alpha))
ANT_GL_DECL(void, glColor4usv, (const GLushort *v))
ANT_GL_DECL(void, glColorMask, (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha))
ANT_GL_DECL(void, glColorMaterial, (GLenum face, GLenum mode))
ANT_GL_DECL(void, glColorPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer))
ANT_GL_DECL(void, glCopyPixels, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum type))
ANT_GL_DECL(void, glCopyTexImage1D, (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border))
ANT_GL_DECL(void, glCopyTexImage2D, (GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border))
ANT_GL_DECL(void, glCopyTexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width))
ANT_GL_DECL(void, glCopyTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height))
ANT_GL_DECL(void, glCullFace, (GLenum mode))
ANT_GL_DECL(void, glDeleteLists, (GLuint list, GLsizei range))
ANT_GL_DECL(void, glDeleteTextures, (GLsizei n, const GLuint *textures))
ANT_GL_DECL(void, glDepthFunc, (GLenum func))
ANT_GL_DECL(void, glDepthMask, (GLboolean flag))
ANT_GL_DECL(void, glDepthRange, (GLclampd zNear, GLclampd zFar))
ANT_GL_DECL(void, glDisable, (GLenum cap))
ANT_GL_DECL(void, glDisableClientState, (GLenum array))
ANT_GL_DECL(void, glDrawArrays, (GLenum mode, GLint first, GLsizei count))
ANT_GL_DECL(void, glDrawBuffer, (GLenum mode))
ANT_GL_DECL(void, glDrawElements, (GLenum mode, GLsizei count, GLenum type, const GLvoid *indices))
ANT_GL_DECL(void, glDrawPixels, (GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels))
ANT_GL_DECL(void, glEdgeFlag, (GLboolean flag))
ANT_GL_DECL(void, glEdgeFlagPointer, (GLsizei stride, const void *pointer))
ANT_GL_DECL(void, glEdgeFlagv, (const GLboolean *flag))
ANT_GL_DECL(void, glEnable, (GLenum cap))
ANT_GL_DECL(void, glEnableClientState, (GLenum array))
ANT_GL_DECL(void, glEnd, (void))
ANT_GL_DECL(void, glEndList, (void))
ANT_GL_DECL(void, glEvalCoord1d, (GLdouble u))
ANT_GL_DECL(void, glEvalCoord1dv, (const GLdouble *u))
ANT_GL_DECL(void, glEvalCoord1f, (GLfloat u))
ANT_GL_DECL(void, glEvalCoord1fv, (const GLfloat *u))
ANT_GL_DECL(void, glEvalCoord2d, (GLdouble u, GLdouble v))
ANT_GL_DECL(void, glEvalCoord2dv, (const GLdouble *u))
ANT_GL_DECL(void, glEvalCoord2f, (GLfloat u, GLfloat v))
ANT_GL_DECL(void, glEvalCoord2fv, (const GLfloat *u))
ANT_GL_DECL(void, glEvalMesh1, (GLenum mode, GLint i1, GLint i2))
ANT_GL_DECL(void, glEvalMesh2, (GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2))
ANT_GL_DECL(void, glEvalPoint1, (GLint i))
ANT_GL_DECL(void, glEvalPoint2, (GLint i, GLint j))
ANT_GL_DECL(void, glFeedbackBuffer, (GLsizei size, GLenum type, GLfloat *buffer))
ANT_GL_DECL(void, glFinish, (void))
ANT_GL_DECL(void, glFlush, (void))
ANT_GL_DECL(void, glFogf, (GLenum pname, GLfloat param))
ANT_GL_DECL(void, glFogfv, (GLenum pname, const GLfloat *params))
ANT_GL_DECL(void, glFogi, (GLenum pname, GLint param))
ANT_GL_DECL(void, glFogiv, (GLenum pname, const GLint *params))
ANT_GL_DECL(void, glFrontFace, (GLenum mode))
ANT_GL_DECL(void, glFrustum, (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar))
ANT_GL_DECL(GLuint, glGenLists, (GLsizei range))
ANT_GL_DECL(void, glGenTextures, (GLsizei n, GLuint *textures))
ANT_GL_DECL(void, glGetBooleanv, (GLenum pname, GLboolean *params))
ANT_GL_DECL(void, glGetClipPlane, (GLenum plane, GLdouble *equation))
ANT_GL_DECL(void, glGetDoublev, (GLenum pname, GLdouble *params))
ANT_GL_DECL(GLenum, glGetError, (void))
ANT_GL_DECL(void, glGetFloatv, (GLenum pname, GLfloat *params))
ANT_GL_DECL(void, glGetIntegerv, (GLenum pname, GLint *params))
ANT_GL_DECL(void, glGetLightfv, (GLenum light, GLenum pname, GLfloat *params))
ANT_GL_DECL(void, glGetLightiv, (GLenum light, GLenum pname, GLint *params))
ANT_GL_DECL(void, glGetMapdv, (GLenum target, GLenum query, GLdouble *v))
ANT_GL_DECL(void, glGetMapfv, (GLenum target, GLenum query, GLfloat *v))
ANT_GL_DECL(void, glGetMapiv, (GLenum target, GLenum query, GLint *v))
ANT_GL_DECL(void, glGetMaterialfv, (GLenum face, GLenum pname, GLfloat *params))
ANT_GL_DECL(void, glGetMaterialiv, (GLenum face, GLenum pname, GLint *params))
ANT_GL_DECL(void, glGetPixelMapfv, (GLenum map, GLfloat *values))
ANT_GL_DECL(void, glGetPixelMapuiv, (GLenum map, GLuint *values))
ANT_GL_DECL(void, glGetPixelMapusv, (GLenum map, GLushort *values))
ANT_GL_DECL(void, glGetPointerv, (GLenum pname, GLvoid* *params))
ANT_GL_DECL(void, glGetPolygonStipple, (GLubyte *mask))
ANT_GL_DECL(const GLubyte *, glGetString, (GLenum name))
ANT_GL_DECL(void, glGetTexEnvfv, (GLenum target, GLenum pname, GLfloat *params))
ANT_GL_DECL(void, glGetTexEnviv, (GLenum target, GLenum pname, GLint *params))
ANT_GL_DECL(void, glGetTexGendv, (GLenum coord, GLenum pname, GLdouble *params))
ANT_GL_DECL(void, glGetTexGenfv, (GLenum coord, GLenum pname, GLfloat *params))
ANT_GL_DECL(void, glGetTexGeniv, (GLenum coord, GLenum pname, GLint *params))
ANT_GL_DECL(void, glGetTexImage, (GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels))
ANT_GL_DECL(void, glGetTexLevelParameterfv, (GLenum target, GLint level, GLenum pname, GLfloat *params))
ANT_GL_DECL(void, glGetTexLevelParameteriv, (GLenum target, GLint level, GLenum pname, GLint *params))
ANT_GL_DECL(void, glGetTexParameterfv, (GLenum target, GLenum pname, GLfloat *params))
ANT_GL_DECL(void, glGetTexParameteriv, (GLenum target, GLenum pname, GLint *params))
ANT_GL_DECL(void, glHint, (GLenum target, GLenum mode))
ANT_GL_DECL(void, glIndexMask, (GLuint mask))
ANT_GL_DECL(void, glIndexPointer, (GLenum type, GLsizei stride, const GLvoid *pointer))
ANT_GL_DECL(void, glIndexd, (GLdouble c))
ANT_GL_DECL(void, glIndexdv, (const GLdouble *c))
ANT_GL_DECL(void, glIndexf, (GLfloat c))
ANT_GL_DECL(void, glIndexfv, (const GLfloat *c))
ANT_GL_DECL(void, glIndexi, (GLint c))
ANT_GL_DECL(void, glIndexiv, (const GLint *c))
ANT_GL_DECL(void, glIndexs, (GLshort c))
ANT_GL_DECL(void, glIndexsv, (const GLshort *c))
ANT_GL_DECL(void, glIndexub, (GLubyte c))
ANT_GL_DECL(void, glIndexubv, (const GLubyte *c))
ANT_GL_DECL(void, glInitNames, (void))
ANT_GL_DECL(void, glInterleavedArrays, (GLenum format, GLsizei stride, const GLvoid *pointer))
ANT_GL_DECL(GLboolean, glIsEnabled, (GLenum cap))
ANT_GL_DECL(GLboolean, glIsList, (GLuint list))
ANT_GL_DECL(GLboolean, glIsTexture, (GLuint texture))
ANT_GL_DECL(void, glLightModelf, (GLenum pname, GLfloat param))
ANT_GL_DECL(void, glLightModelfv, (GLenum pname, const GLfloat *params))
ANT_GL_DECL(void, glLightModeli, (GLenum pname, GLint param))
ANT_GL_DECL(void, glLightModeliv, (GLenum pname, const GLint *params))
ANT_GL_DECL(void, glLightf, (GLenum light, GLenum pname, GLfloat param))
ANT_GL_DECL(void, glLightfv, (GLenum light, GLenum pname, const GLfloat *params))
ANT_GL_DECL(void, glLighti, (GLenum light, GLenum pname, GLint param))
ANT_GL_DECL(void, glLightiv, (GLenum light, GLenum pname, const GLint *params))
ANT_GL_DECL(void, glLineStipple, (GLint factor, GLushort pattern))
ANT_GL_DECL(void, glLineWidth, (GLfloat width))
ANT_GL_DECL(void, glListBase, (GLuint base))
ANT_GL_DECL(void, glLoadIdentity, (void))
ANT_GL_DECL(void, glLoadMatrixd, (const GLdouble *m))
ANT_GL_DECL(void, glLoadMatrixf, (const GLfloat *m))
ANT_GL_DECL(void, glLoadName, (GLuint name))
ANT_GL_DECL(void, glLogicOp, (GLenum opcode))
ANT_GL_DECL(void, glMap1d, (GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points))
ANT_GL_DECL(void, glMap1f, (GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points))
ANT_GL_DECL(void, glMap2d, (GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points))
ANT_GL_DECL(void, glMap2f, (GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points))
ANT_GL_DECL(void, glMapGrid1d, (GLint un, GLdouble u1, GLdouble u2))
ANT_GL_DECL(void, glMapGrid1f, (GLint un, GLfloat u1, GLfloat u2))
ANT_GL_DECL(void, glMapGrid2d, (GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2))
ANT_GL_DECL(void, glMapGrid2f, (GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2))
ANT_GL_DECL(void, glMaterialf, (GLenum face, GLenum pname, GLfloat param))
ANT_GL_DECL(void, glMaterialfv, (GLenum face, GLenum pname, const GLfloat *params))
ANT_GL_DECL(void, glMateriali, (GLenum face, GLenum pname, GLint param))
ANT_GL_DECL(void, glMaterialiv, (GLenum face, GLenum pname, const GLint *params))
ANT_GL_DECL(void, glMatrixMode, (GLenum mode))
ANT_GL_DECL(void, glMultMatrixd, (const GLdouble *m))
ANT_GL_DECL(void, glMultMatrixf, (const GLfloat *m))
ANT_GL_DECL(void, glNewList, (GLuint list, GLenum mode))
ANT_GL_DECL(void, glNormal3b, (GLbyte nx, GLbyte ny, GLbyte nz))
ANT_GL_DECL(void, glNormal3bv, (const GLbyte *v))
ANT_GL_DECL(void, glNormal3d, (GLdouble nx, GLdouble ny, GLdouble nz))
ANT_GL_DECL(void, glNormal3dv, (const GLdouble *v))
ANT_GL_DECL(void, glNormal3f, (GLfloat nx, GLfloat ny, GLfloat nz))
ANT_GL_DECL(void, glNormal3fv, (const GLfloat *v))
ANT_GL_DECL(void, glNormal3i, (GLint nx, GLint ny, GLint nz))
ANT_GL_DECL(void, glNormal3iv, (const GLint *v))
ANT_GL_DECL(void, glNormal3s, (GLshort nx, GLshort ny, GLshort nz))
ANT_GL_DECL(void, glNormal3sv, (const GLshort *v))
ANT_GL_DECL(void, glNormalPointer, (GLenum type, GLsizei stride, const GLvoid *pointer))
ANT_GL_DECL(void, glOrtho, (GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar))
ANT_GL_DECL(void, glPassThrough, (GLfloat token))
ANT_GL_DECL(void, glPixelMapfv, (GLenum map, GLsizei mapsize, const GLfloat *values))
ANT_GL_DECL(void, glPixelMapuiv, (GLenum map, GLsizei mapsize, const GLuint *values))
ANT_GL_DECL(void, glPixelMapusv, (GLenum map, GLsizei mapsize, const GLushort *values))
ANT_GL_DECL(void, glPixelStoref, (GLenum pname, GLfloat param))
ANT_GL_DECL(void, glPixelStorei, (GLenum pname, GLint param))
ANT_GL_DECL(void, glPixelTransferf, (GLenum pname, GLfloat param))
ANT_GL_DECL(void, glPixelTransferi, (GLenum pname, GLint param))
ANT_GL_DECL(void, glPixelZoom, (GLfloat xfactor, GLfloat yfactor))
ANT_GL_DECL(void, glPointSize, (GLfloat size))
ANT_GL_DECL(void, glPolygonMode, (GLenum face, GLenum mode))
ANT_GL_DECL(void, glPolygonOffset, (GLfloat factor, GLfloat units))
ANT_GL_DECL(void, glPolygonStipple, (const GLubyte *mask))
ANT_GL_DECL(void, glPopAttrib, (void))
ANT_GL_DECL(void, glPopClientAttrib, (void))
ANT_GL_DECL(void, glPopMatrix, (void))
ANT_GL_DECL(void, glPopName, (void))
ANT_GL_DECL(void, glPrioritizeTextures, (GLsizei n, const GLuint *textures, const GLclampf *priorities))
ANT_GL_DECL(void, glPushAttrib, (GLbitfield mask))
ANT_GL_DECL(void, glPushClientAttrib, (GLbitfield mask))
ANT_GL_DECL(void, glPushMatrix, (void))
ANT_GL_DECL(void, glPushName, (GLuint name))
ANT_GL_DECL(void, glRasterPos2d, (GLdouble x, GLdouble y))
ANT_GL_DECL(void, glRasterPos2dv, (const GLdouble *v))
ANT_GL_DECL(void, glRasterPos2f, (GLfloat x, GLfloat y))
ANT_GL_DECL(void, glRasterPos2fv, (const GLfloat *v))
ANT_GL_DECL(void, glRasterPos2i, (GLint x, GLint y))
ANT_GL_DECL(void, glRasterPos2iv, (const GLint *v))
ANT_GL_DECL(void, glRasterPos2s, (GLshort x, GLshort y))
ANT_GL_DECL(void, glRasterPos2sv, (const GLshort *v))
ANT_GL_DECL(void, glRasterPos3d, (GLdouble x, GLdouble y, GLdouble z))
ANT_GL_DECL(void, glRasterPos3dv, (const GLdouble *v))
ANT_GL_DECL(void, glRasterPos3f, (GLfloat x, GLfloat y, GLfloat z))
ANT_GL_DECL(void, glRasterPos3fv, (const GLfloat *v))
ANT_GL_DECL(void, glRasterPos3i, (GLint x, GLint y, GLint z))
ANT_GL_DECL(void, glRasterPos3iv, (const GLint *v))
ANT_GL_DECL(void, glRasterPos3s, (GLshort x, GLshort y, GLshort z))
ANT_GL_DECL(void, glRasterPos3sv, (const GLshort *v))
ANT_GL_DECL(void, glRasterPos4d, (GLdouble x, GLdouble y, GLdouble z, GLdouble w))
ANT_GL_DECL(void, glRasterPos4dv, (const GLdouble *v))
ANT_GL_DECL(void, glRasterPos4f, (GLfloat x, GLfloat y, GLfloat z, GLfloat w))
ANT_GL_DECL(void, glRasterPos4fv, (const GLfloat *v))
ANT_GL_DECL(void, glRasterPos4i, (GLint x, GLint y, GLint z, GLint w))
ANT_GL_DECL(void, glRasterPos4iv, (const GLint *v))
ANT_GL_DECL(void, glRasterPos4s, (GLshort x, GLshort y, GLshort z, GLshort w))
ANT_GL_DECL(void, glRasterPos4sv, (const GLshort *v))
ANT_GL_DECL(void, glReadBuffer, (GLenum mode))
ANT_GL_DECL(void, glReadPixels, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels))
ANT_GL_DECL(void, glRectd, (GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2))
ANT_GL_DECL(void, glRectdv, (const GLdouble *v1, const GLdouble *v2))
ANT_GL_DECL(void, glRectf, (GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2))
ANT_GL_DECL(void, glRectfv, (const GLfloat *v1, const GLfloat *v2))
ANT_GL_DECL(void, glRecti, (GLint x1, GLint y1, GLint x2, GLint y2))
ANT_GL_DECL(void, glRectiv, (const GLint *v1, const GLint *v2))
ANT_GL_DECL(void, glRects, (GLshort x1, GLshort y1, GLshort x2, GLshort y2))
ANT_GL_DECL(void, glRectsv, (const GLshort *v1, const GLshort *v2))
ANT_GL_DECL(GLint, glRenderMode, (GLenum mode))
ANT_GL_DECL(void, glRotated, (GLdouble angle, GLdouble x, GLdouble y, GLdouble z))
ANT_GL_DECL(void, glRotatef, (GLfloat angle, GLfloat x, GLfloat y, GLfloat z))
ANT_GL_DECL(void, glScaled, (GLdouble x, GLdouble y, GLdouble z))
ANT_GL_DECL(void, glScalef, (GLfloat x, GLfloat y, GLfloat z))
ANT_GL_DECL(void, glScissor, (GLint x, GLint y, GLsizei width, GLsizei height))
ANT_GL_DECL(void, glSelectBuffer, (GLsizei size, GLuint *buffer))
ANT_GL_DECL(void, glShadeModel, (GLenum mode))
ANT_GL_DECL(void, glStencilFunc, (GLenum func, GLint ref, GLuint mask))
ANT_GL_DECL(void, glStencilMask, (GLuint mask))
ANT_GL_DECL(void, glStencilOp, (GLenum fail, GLenum zfail, GLenum zpass))
ANT_GL_DECL(void, glTexCoord1d, (GLdouble s))
ANT_GL_DECL(void, glTexCoord1dv, (const GLdouble *v))
ANT_GL_DECL(void, glTexCoord1f, (GLfloat s))
ANT_GL_DECL(void, glTexCoord1fv, (const GLfloat *v))
ANT_GL_DECL(void, glTexCoord1i, (GLint s))
ANT_GL_DECL(void, glTexCoord1iv, (const GLint *v))
ANT_GL_DECL(void, glTexCoord1s, (GLshort s))
ANT_GL_DECL(void, glTexCoord1sv, (const GLshort *v))
ANT_GL_DECL(void, glTexCoord2d, (GLdouble s, GLdouble t))
ANT_GL_DECL(void, glTexCoord2dv, (const GLdouble *v))
ANT_GL_DECL(void, glTexCoord2f, (GLfloat s, GLfloat t))
ANT_GL_DECL(void, glTexCoord2fv, (const GLfloat *v))
ANT_GL_DECL(void, glTexCoord2i, (GLint s, GLint t))
ANT_GL_DECL(void, glTexCoord2iv, (const GLint *v))
ANT_GL_DECL(void, glTexCoord2s, (GLshort s, GLshort t))
ANT_GL_DECL(void, glTexCoord2sv, (const GLshort *v))
ANT_GL_DECL(void, glTexCoord3d, (GLdouble s, GLdouble t, GLdouble r))
ANT_GL_DECL(void, glTexCoord3dv, (const GLdouble *v))
ANT_GL_DECL(void, glTexCoord3f, (GLfloat s, GLfloat t, GLfloat r))
ANT_GL_DECL(void, glTexCoord3fv, (const GLfloat *v))
ANT_GL_DECL(void, glTexCoord3i, (GLint s, GLint t, GLint r))
ANT_GL_DECL(void, glTexCoord3iv, (const GLint *v))
ANT_GL_DECL(void, glTexCoord3s, (GLshort s, GLshort t, GLshort r))
ANT_GL_DECL(void, glTexCoord3sv, (const GLshort *v))
ANT_GL_DECL(void, glTexCoord4d, (GLdouble s, GLdouble t, GLdouble r, GLdouble q))
ANT_GL_DECL(void, glTexCoord4dv, (const GLdouble *v))
ANT_GL_DECL(void, glTexCoord4f, (GLfloat s, GLfloat t, GLfloat r, GLfloat q))
ANT_GL_DECL(void, glTexCoord4fv, (const GLfloat *v))
ANT_GL_DECL(void, glTexCoord4i, (GLint s, GLint t, GLint r, GLint q))
ANT_GL_DECL(void, glTexCoord4iv, (const GLint *v))
ANT_GL_DECL(void, glTexCoord4s, (GLshort s, GLshort t, GLshort r, GLshort q))
ANT_GL_DECL(void, glTexCoord4sv, (const GLshort *v))
ANT_GL_DECL(void, glTexCoordPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer))
ANT_GL_DECL(void, glTexEnvf, (GLenum target, GLenum pname, GLfloat param))
ANT_GL_DECL(void, glTexEnvfv, (GLenum target, GLenum pname, const GLfloat *params))
ANT_GL_DECL(void, glTexEnvi, (GLenum target, GLenum pname, GLint param))
ANT_GL_DECL(void, glTexEnviv, (GLenum target, GLenum pname, const GLint *params))
ANT_GL_DECL(void, glTexGend, (GLenum coord, GLenum pname, GLdouble param))
ANT_GL_DECL(void, glTexGendv, (GLenum coord, GLenum pname, const GLdouble *params))
ANT_GL_DECL(void, glTexGenf, (GLenum coord, GLenum pname, GLfloat param))
ANT_GL_DECL(void, glTexGenfv, (GLenum coord, GLenum pname, const GLfloat *params))
ANT_GL_DECL(void, glTexGeni, (GLenum coord, GLenum pname, GLint param))
ANT_GL_DECL(void, glTexGeniv, (GLenum coord, GLenum pname, const GLint *params))
#if defined(ANT_OSX) && (MAC_OS_X_VERSION_MAX_ALLOWED < 1070)
// Mac OSX < 10.7 redefines these OpenGL calls: glTexImage1D, glTexImage2D
ANT_GL_DECL(void, glTexImage1D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels))
ANT_GL_DECL(void, glTexImage2D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels))
#else
ANT_GL_DECL(void, glTexImage1D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels))
ANT_GL_DECL(void, glTexImage2D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels))
#endif
ANT_GL_DECL(void, glTexParameterf, (GLenum target, GLenum pname, GLfloat param))
ANT_GL_DECL(void, glTexParameterfv, (GLenum target, GLenum pname, const GLfloat *params))
ANT_GL_DECL(void, glTexParameteri, (GLenum target, GLenum pname, GLint param))
ANT_GL_DECL(void, glTexParameteriv, (GLenum target, GLenum pname, const GLint *params))
ANT_GL_DECL(void, glTexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels))
ANT_GL_DECL(void, glTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels))
ANT_GL_DECL(void, glTranslated, (GLdouble x, GLdouble y, GLdouble z))
ANT_GL_DECL(void, glTranslatef, (GLfloat x, GLfloat y, GLfloat z))
ANT_GL_DECL(void, glVertex2d, (GLdouble x, GLdouble y))
ANT_GL_DECL(void, glVertex2dv, (const GLdouble *v))
ANT_GL_DECL(void, glVertex2f, (GLfloat x, GLfloat y))
ANT_GL_DECL(void, glVertex2fv, (const GLfloat *v))
ANT_GL_DECL(void, glVertex2i, (GLint x, GLint y))
ANT_GL_DECL(void, glVertex2iv, (const GLint *v))
ANT_GL_DECL(void, glVertex2s, (GLshort x, GLshort y))
ANT_GL_DECL(void, glVertex2sv, (const GLshort *v))
ANT_GL_DECL(void, glVertex3d, (GLdouble x, GLdouble y, GLdouble z))
ANT_GL_DECL(void, glVertex3dv, (const GLdouble *v))
ANT_GL_DECL(void, glVertex3f, (GLfloat x, GLfloat y, GLfloat z))
ANT_GL_DECL(void, glVertex3fv, (const GLfloat *v))
ANT_GL_DECL(void, glVertex3i, (GLint x, GLint y, GLint z))
ANT_GL_DECL(void, glVertex3iv, (const GLint *v))
ANT_GL_DECL(void, glVertex3s, (GLshort x, GLshort y, GLshort z))
ANT_GL_DECL(void, glVertex3sv, (const GLshort *v))
ANT_GL_DECL(void, glVertex4d, (GLdouble x, GLdouble y, GLdouble z, GLdouble w))
ANT_GL_DECL(void, glVertex4dv, (const GLdouble *v))
ANT_GL_DECL(void, glVertex4f, (GLfloat x, GLfloat y, GLfloat z, GLfloat w))
ANT_GL_DECL(void, glVertex4fv, (const GLfloat *v))
ANT_GL_DECL(void, glVertex4i, (GLint x, GLint y, GLint z, GLint w))
ANT_GL_DECL(void, glVertex4iv, (const GLint *v))
ANT_GL_DECL(void, glVertex4s, (GLshort x, GLshort y, GLshort z, GLshort w))
ANT_GL_DECL(void, glVertex4sv, (const GLshort *v))
ANT_GL_DECL(void, glVertexPointer, (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer))
ANT_GL_DECL(void, glViewport, (GLint x, GLint y, GLsizei width, GLsizei height))

#ifdef ANT_WINDOWS
ANT_GL_DECL(PROC, wglGetProcAddress, (LPCSTR))
#endif                                                                                                                                                                                                                                                                                                                                                


#endif // !defined ANT_LOAD_OGL_INCLUDED
