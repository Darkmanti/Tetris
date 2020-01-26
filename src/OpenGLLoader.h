#pragma once

#include "glcorearb.h"
#include "wgl.h"
#include "wglext.h"

#define OPENGL_FUNC_COUNT 345

HGLRC hRC;
HDC hDC;

union GLFuncTable
{
	void* func[OPENGL_FUNC_COUNT];
	struct
	{
		// 1.0
		PFNGLCULLFACEPROC                               _glCullFace;
		PFNGLFRONTFACEPROC                              _glFrontFace;
		PFNGLHINTPROC                                   _glHint;
		PFNGLLINEWIDTHPROC                              _glLineWidth;
		PFNGLPOINTSIZEPROC                              _glPointSize;
		PFNGLPOLYGONMODEPROC                            _glPolygonMode;
		PFNGLSCISSORPROC                                _glScissor;
		PFNGLTEXPARAMETERFPROC                          _glTexParameterf;
		PFNGLTEXPARAMETERFVPROC                         _glTexParameterfv;
		PFNGLTEXPARAMETERIPROC                          _glTexParameteri;
		PFNGLTEXPARAMETERIVPROC                         _glTexParameteriv;
		PFNGLTEXIMAGE1DPROC                             _glTexImage1D;
		PFNGLTEXIMAGE2DPROC                             _glTexImage2D;
		PFNGLDRAWBUFFERPROC                             _glDrawBuffer;
		PFNGLCLEARPROC                                  _glClear;
		PFNGLCLEARCOLORPROC                             _glClearColor;
		PFNGLCLEARSTENCILPROC                           _glClearStencil;
		PFNGLCLEARDEPTHPROC                             _glClearDepth;
		PFNGLSTENCILMASKPROC                            _glStencilMask;
		PFNGLCOLORMASKPROC                              _glColorMask;
		PFNGLDEPTHMASKPROC                              _glDepthMask;
		PFNGLDISABLEPROC                                _glDisable;
		PFNGLENABLEPROC                                 _glEnable;
		PFNGLFINISHPROC                                 _glFinish;
		PFNGLFLUSHPROC                                  _glFlush;
		PFNGLBLENDFUNCPROC                              _glBlendFunc;
		PFNGLLOGICOPPROC                                _glLogicOp;
		PFNGLSTENCILFUNCPROC                            _glStencilFunc;
		PFNGLSTENCILOPPROC                              _glStencilOp;
		PFNGLDEPTHFUNCPROC                              _glDepthFunc;
		PFNGLPIXELSTOREFPROC                            _glPixelStoref;
		PFNGLPIXELSTOREIPROC                            _glPixelStorei;
		PFNGLREADBUFFERPROC                             _glReadBuffer;
		PFNGLREADPIXELSPROC                             _glReadPixels;
		PFNGLGETBOOLEANVPROC                            _glGetBooleanv;
		PFNGLGETDOUBLEVPROC                             _glGetDoublev;
		PFNGLGETERRORPROC                               _glGetError;
		PFNGLGETFLOATVPROC                              _glGetFloatv;
		PFNGLGETINTEGERVPROC                            _glGetIntegerv;
		PFNGLGETSTRINGPROC                              _glGetString;
		PFNGLGETTEXIMAGEPROC                            _glGetTexImage;
		PFNGLGETTEXPARAMETERFVPROC                      _glGetTexParameterfv;
		PFNGLGETTEXPARAMETERIVPROC                      _glGetTexParameteriv;
		PFNGLGETTEXLEVELPARAMETERFVPROC                 _glGetTexLevelParameterfv;
		PFNGLGETTEXLEVELPARAMETERIVPROC                 _glGetTexLevelParameteriv;
		PFNGLISENABLEDPROC                              _glIsEnabled;
		PFNGLDEPTHRANGEPROC                             _glDepthRange;
		PFNGLVIEWPORTPROC                               _glViewport;
		// 1.1
		PFNGLDRAWARRAYSPROC                             _glDrawArrays;
		PFNGLDRAWELEMENTSPROC                           _glDrawElements;
		PFNGLGETPOINTERVPROC                            _glGetPointerv;
		PFNGLPOLYGONOFFSETPROC                          _glPolygonOffset;
		PFNGLCOPYTEXIMAGE1DPROC                         _glCopyTexImage1D;
		PFNGLCOPYTEXIMAGE2DPROC                         _glCopyTexImage2D;
		PFNGLCOPYTEXSUBIMAGE1DPROC                      _glCopyTexSubImage1D;
		PFNGLCOPYTEXSUBIMAGE2DPROC                      _glCopyTexSubImage2D;
		PFNGLTEXSUBIMAGE1DPROC                          _glTexSubImage1D;
		PFNGLTEXSUBIMAGE2DPROC                          _glTexSubImage2D;
		PFNGLBINDTEXTUREPROC                            _glBindTexture;
		PFNGLDELETETEXTURESPROC                         _glDeleteTextures;
		PFNGLGENTEXTURESPROC                            _glGenTextures;
		PFNGLISTEXTUREPROC                              _glIsTexture;
		// 1.2
		PFNGLDRAWRANGEELEMENTSPROC                      _glDrawRangeElements;
		PFNGLTEXIMAGE3DPROC                             _glTexImage3D;
		PFNGLTEXSUBIMAGE3DPROC                          _glTexSubImage3D;
		PFNGLCOPYTEXSUBIMAGE3DPROC                      _glCopyTexSubImage3D;
		// 1.3
		PFNGLACTIVETEXTUREPROC                          _glActiveTexture;
		PFNGLSAMPLECOVERAGEPROC                         _glSampleCoverage;
		PFNGLCOMPRESSEDTEXIMAGE3DPROC                   _glCompressedTexImage3D;
		PFNGLCOMPRESSEDTEXIMAGE2DPROC                   _glCompressedTexImage2D;
		PFNGLCOMPRESSEDTEXIMAGE1DPROC                   _glCompressedTexImage1D;
		PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC                _glCompressedTexSubImage3D;
		PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC                _glCompressedTexSubImage2D;
		PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC                _glCompressedTexSubImage1D;
		PFNGLGETCOMPRESSEDTEXIMAGEPROC                  _glGetCompressedTexImage;
		// 1.4
		PFNGLBLENDFUNCSEPARATEPROC                      _glBlendFuncSeparate;
		PFNGLMULTIDRAWARRAYSPROC                        _glMultiDrawArrays;
		PFNGLMULTIDRAWELEMENTSPROC                      _glMultiDrawElements;
		PFNGLPOINTPARAMETERFPROC                        _glPointParameterf;
		PFNGLPOINTPARAMETERFVPROC                       _glPointParameterfv;
		PFNGLPOINTPARAMETERIPROC                        _glPointParameteri;
		PFNGLPOINTPARAMETERIVPROC                       _glPointParameteriv;
		PFNGLBLENDCOLORPROC                             _glBlendColor;
		PFNGLBLENDEQUATIONPROC                          _glBlendEquation;
		// 1.5
		PFNGLGENQUERIESPROC                             _glGenQueries;
		PFNGLDELETEQUERIESPROC                          _glDeleteQueries;
		PFNGLISQUERYPROC                                _glIsQuery;
		PFNGLBEGINQUERYPROC                             _glBeginQuery;
		PFNGLENDQUERYPROC                               _glEndQuery;
		PFNGLGETQUERYIVPROC                             _glGetQueryiv;
		PFNGLGETQUERYOBJECTIVPROC                       _glGetQueryObjectiv;
		PFNGLGETQUERYOBJECTUIVPROC                      _glGetQueryObjectuiv;
		PFNGLBINDBUFFERPROC                             _glBindBuffer;
		PFNGLDELETEBUFFERSPROC                          _glDeleteBuffers;
		PFNGLGENBUFFERSPROC                             _glGenBuffers;
		PFNGLISBUFFERPROC                               _glIsBuffer;
		PFNGLBUFFERDATAPROC                             _glBufferData;
		PFNGLBUFFERSUBDATAPROC                          _glBufferSubData;
		PFNGLGETBUFFERSUBDATAPROC                       _glGetBufferSubData;
		PFNGLMAPBUFFERPROC                              _glMapBuffer;
		PFNGLUNMAPBUFFERPROC                            _glUnmapBuffer;
		PFNGLGETBUFFERPARAMETERIVPROC                   _glGetBufferParameteriv;
		PFNGLGETBUFFERPOINTERVPROC                      _glGetBufferPointerv;
		// 2.0
		PFNGLBLENDEQUATIONSEPARATEPROC                  _glBlendEquationSeparate;
		PFNGLDRAWBUFFERSPROC                            _glDrawBuffers;
		PFNGLSTENCILOPSEPARATEPROC                      _glStencilOpSeparate;
		PFNGLSTENCILFUNCSEPARATEPROC                    _glStencilFuncSeparate;
		PFNGLSTENCILMASKSEPARATEPROC                    _glStencilMaskSeparate;
		PFNGLATTACHSHADERPROC                           _glAttachShader;
		PFNGLBINDATTRIBLOCATIONPROC                     _glBindAttribLocation;
		PFNGLCOMPILESHADERPROC                          _glCompileShader;
		PFNGLCREATEPROGRAMPROC                          _glCreateProgram;
		PFNGLCREATESHADERPROC                           _glCreateShader;
		PFNGLDELETEPROGRAMPROC                          _glDeleteProgram;
		PFNGLDELETESHADERPROC                           _glDeleteShader;
		PFNGLDETACHSHADERPROC                           _glDetachShader;
		PFNGLDISABLEVERTEXATTRIBARRAYPROC               _glDisableVertexAttribArray;
		PFNGLENABLEVERTEXATTRIBARRAYPROC                _glEnableVertexAttribArray;
		PFNGLGETACTIVEATTRIBPROC                        _glGetActiveAttrib;
		PFNGLGETACTIVEUNIFORMPROC                       _glGetActiveUniform;
		PFNGLGETATTACHEDSHADERSPROC                     _glGetAttachedShaders;
		PFNGLGETATTRIBLOCATIONPROC                      _glGetAttribLocation;
		PFNGLGETPROGRAMIVPROC                           _glGetProgramiv;
		PFNGLGETPROGRAMINFOLOGPROC                      _glGetProgramInfoLog;
		PFNGLGETSHADERIVPROC                            _glGetShaderiv;
		PFNGLGETSHADERINFOLOGPROC                       _glGetShaderInfoLog;
		PFNGLGETSHADERSOURCEPROC                        _glGetShaderSource;
		PFNGLGETUNIFORMLOCATIONPROC                     _glGetUniformLocation;
		PFNGLGETUNIFORMFVPROC                           _glGetUniformfv;
		PFNGLGETUNIFORMIVPROC                           _glGetUniformiv;
		PFNGLGETVERTEXATTRIBDVPROC                      _glGetVertexAttribdv;
		PFNGLGETVERTEXATTRIBFVPROC                      _glGetVertexAttribfv;
		PFNGLGETVERTEXATTRIBIVPROC                      _glGetVertexAttribiv;
		PFNGLGETVERTEXATTRIBPOINTERVPROC                _glGetVertexAttribPointerv;
		PFNGLISPROGRAMPROC                              _glIsProgram;
		PFNGLISSHADERPROC                               _glIsShader;
		PFNGLLINKPROGRAMPROC                            _glLinkProgram;
		PFNGLSHADERSOURCEPROC                           _glShaderSource;
		PFNGLUSEPROGRAMPROC                             _glUseProgram;
		PFNGLUNIFORM1FPROC                              _glUniform1f;
		PFNGLUNIFORM2FPROC                              _glUniform2f;
		PFNGLUNIFORM3FPROC                              _glUniform3f;
		PFNGLUNIFORM4FPROC                              _glUniform4f;
		PFNGLUNIFORM1IPROC                              _glUniform1i;
		PFNGLUNIFORM2IPROC                              _glUniform2i;
		PFNGLUNIFORM3IPROC                              _glUniform3i;
		PFNGLUNIFORM4IPROC                              _glUniform4i;
		PFNGLUNIFORM1FVPROC                             _glUniform1fv;
		PFNGLUNIFORM2FVPROC                             _glUniform2fv;
		PFNGLUNIFORM3FVPROC                             _glUniform3fv;
		PFNGLUNIFORM4FVPROC                             _glUniform4fv;
		PFNGLUNIFORM1IVPROC                             _glUniform1iv;
		PFNGLUNIFORM2IVPROC                             _glUniform2iv;
		PFNGLUNIFORM3IVPROC                             _glUniform3iv;
		PFNGLUNIFORM4IVPROC                             _glUniform4iv;
		PFNGLUNIFORMMATRIX2FVPROC                       _glUniformMatrix2fv;
		PFNGLUNIFORMMATRIX3FVPROC                       _glUniformMatrix3fv;
		PFNGLUNIFORMMATRIX4FVPROC                       _glUniformMatrix4fv;
		PFNGLVALIDATEPROGRAMPROC                        _glValidateProgram;
		PFNGLVERTEXATTRIB1DPROC                         _glVertexAttrib1d;
		PFNGLVERTEXATTRIB1DVPROC                        _glVertexAttrib1dv;
		PFNGLVERTEXATTRIB1FPROC                         _glVertexAttrib1f;
		PFNGLVERTEXATTRIB1FVPROC                        _glVertexAttrib1fv;
		PFNGLVERTEXATTRIB1SPROC                         _glVertexAttrib1s;
		PFNGLVERTEXATTRIB1SVPROC                        _glVertexAttrib1sv;
		PFNGLVERTEXATTRIB2DPROC                         _glVertexAttrib2d;
		PFNGLVERTEXATTRIB2DVPROC                        _glVertexAttrib2dv;
		PFNGLVERTEXATTRIB2FPROC                         _glVertexAttrib2f;
		PFNGLVERTEXATTRIB2FVPROC                        _glVertexAttrib2fv;
		PFNGLVERTEXATTRIB2SPROC                         _glVertexAttrib2s;
		PFNGLVERTEXATTRIB2SVPROC                        _glVertexAttrib2sv;
		PFNGLVERTEXATTRIB3DPROC                         _glVertexAttrib3d;
		PFNGLVERTEXATTRIB3DVPROC                        _glVertexAttrib3dv;
		PFNGLVERTEXATTRIB3FPROC                         _glVertexAttrib3f;
		PFNGLVERTEXATTRIB3FVPROC                        _glVertexAttrib3fv;
		PFNGLVERTEXATTRIB3SPROC                         _glVertexAttrib3s;
		PFNGLVERTEXATTRIB3SVPROC                        _glVertexAttrib3sv;
		PFNGLVERTEXATTRIB4NBVPROC                       _glVertexAttrib4Nbv;
		PFNGLVERTEXATTRIB4NIVPROC                       _glVertexAttrib4Niv;
		PFNGLVERTEXATTRIB4NSVPROC                       _glVertexAttrib4Nsv;
		PFNGLVERTEXATTRIB4NUBPROC                       _glVertexAttrib4Nub;
		PFNGLVERTEXATTRIB4NUBVPROC                      _glVertexAttrib4Nubv;
		PFNGLVERTEXATTRIB4NUIVPROC                      _glVertexAttrib4Nuiv;
		PFNGLVERTEXATTRIB4NUSVPROC                      _glVertexAttrib4Nusv;
		PFNGLVERTEXATTRIB4BVPROC                        _glVertexAttrib4bv;
		PFNGLVERTEXATTRIB4DPROC                         _glVertexAttrib4d;
		PFNGLVERTEXATTRIB4DVPROC                        _glVertexAttrib4dv;
		PFNGLVERTEXATTRIB4FPROC                         _glVertexAttrib4f;
		PFNGLVERTEXATTRIB4FVPROC                        _glVertexAttrib4fv;
		PFNGLVERTEXATTRIB4IVPROC                        _glVertexAttrib4iv;
		PFNGLVERTEXATTRIB4SPROC                         _glVertexAttrib4s;
		PFNGLVERTEXATTRIB4SVPROC                        _glVertexAttrib4sv;
		PFNGLVERTEXATTRIB4UBVPROC                       _glVertexAttrib4ubv;
		PFNGLVERTEXATTRIB4UIVPROC                       _glVertexAttrib4uiv;
		PFNGLVERTEXATTRIB4USVPROC                       _glVertexAttrib4usv;
		PFNGLVERTEXATTRIBPOINTERPROC                    _glVertexAttribPointer;
		// 2.1
		PFNGLUNIFORMMATRIX2X3FVPROC                     _glUniformMatrix2x3fv;
		PFNGLUNIFORMMATRIX3X2FVPROC                     _glUniformMatrix3x2fv;
		PFNGLUNIFORMMATRIX2X4FVPROC                     _glUniformMatrix2x4fv;
		PFNGLUNIFORMMATRIX4X2FVPROC                     _glUniformMatrix4x2fv;
		PFNGLUNIFORMMATRIX3X4FVPROC                     _glUniformMatrix3x4fv;
		PFNGLUNIFORMMATRIX4X3FVPROC                     _glUniformMatrix4x3fv;
		// 3.0
		PFNGLCOLORMASKIPROC                             _glColorMaski;
		PFNGLGETBOOLEANI_VPROC                          _glGetBooleani_v;
		PFNGLGETINTEGERI_VPROC                          _glGetIntegeri_v;
		PFNGLENABLEIPROC                                _glEnablei;
		PFNGLDISABLEIPROC                               _glDisablei;
		PFNGLISENABLEDIPROC                             _glIsEnabledi;
		PFNGLBEGINTRANSFORMFEEDBACKPROC                 _glBeginTransformFeedback;
		PFNGLENDTRANSFORMFEEDBACKPROC                   _glEndTransformFeedback;
		PFNGLBINDBUFFERRANGEPROC                        _glBindBufferRange;
		PFNGLBINDBUFFERBASEPROC                         _glBindBufferBase;
		PFNGLTRANSFORMFEEDBACKVARYINGSPROC              _glTransformFeedbackVaryings;
		PFNGLGETTRANSFORMFEEDBACKVARYINGPROC            _glGetTransformFeedbackVarying;
		PFNGLCLAMPCOLORPROC                             _glClampColor;
		PFNGLBEGINCONDITIONALRENDERPROC                 _glBeginConditionalRender;
		PFNGLENDCONDITIONALRENDERPROC                   _glEndConditionalRender;
		PFNGLVERTEXATTRIBIPOINTERPROC                   _glVertexAttribIPointer;
		PFNGLGETVERTEXATTRIBIIVPROC                     _glGetVertexAttribIiv;
		PFNGLGETVERTEXATTRIBIUIVPROC                    _glGetVertexAttribIuiv;
		PFNGLVERTEXATTRIBI1IPROC                        _glVertexAttribI1i;
		PFNGLVERTEXATTRIBI2IPROC                        _glVertexAttribI2i;
		PFNGLVERTEXATTRIBI3IPROC                        _glVertexAttribI3i;
		PFNGLVERTEXATTRIBI4IPROC                        _glVertexAttribI4i;
		PFNGLVERTEXATTRIBI1UIPROC                       _glVertexAttribI1ui;
		PFNGLVERTEXATTRIBI2UIPROC                       _glVertexAttribI2ui;
		PFNGLVERTEXATTRIBI3UIPROC                       _glVertexAttribI3ui;
		PFNGLVERTEXATTRIBI4UIPROC                       _glVertexAttribI4ui;
		PFNGLVERTEXATTRIBI1IVPROC                       _glVertexAttribI1iv;
		PFNGLVERTEXATTRIBI2IVPROC                       _glVertexAttribI2iv;
		PFNGLVERTEXATTRIBI3IVPROC                       _glVertexAttribI3iv;
		PFNGLVERTEXATTRIBI4IVPROC                       _glVertexAttribI4iv;
		PFNGLVERTEXATTRIBI1UIVPROC                      _glVertexAttribI1uiv;
		PFNGLVERTEXATTRIBI2UIVPROC                      _glVertexAttribI2uiv;
		PFNGLVERTEXATTRIBI3UIVPROC                      _glVertexAttribI3uiv;
		PFNGLVERTEXATTRIBI4UIVPROC                      _glVertexAttribI4uiv;
		PFNGLVERTEXATTRIBI4BVPROC                       _glVertexAttribI4bv;
		PFNGLVERTEXATTRIBI4SVPROC                       _glVertexAttribI4sv;
		PFNGLVERTEXATTRIBI4UBVPROC                      _glVertexAttribI4ubv;
		PFNGLVERTEXATTRIBI4USVPROC                      _glVertexAttribI4usv;
		PFNGLGETUNIFORMUIVPROC                          _glGetUniformuiv;
		PFNGLBINDFRAGDATALOCATIONPROC                   _glBindFragDataLocation;
		PFNGLGETFRAGDATALOCATIONPROC                    _glGetFragDataLocation;
		PFNGLUNIFORM1UIPROC                             _glUniform1ui;
		PFNGLUNIFORM2UIPROC                             _glUniform2ui;
		PFNGLUNIFORM3UIPROC                             _glUniform3ui;
		PFNGLUNIFORM4UIPROC                             _glUniform4ui;
		PFNGLUNIFORM1UIVPROC                            _glUniform1uiv;
		PFNGLUNIFORM2UIVPROC                            _glUniform2uiv;
		PFNGLUNIFORM3UIVPROC                            _glUniform3uiv;
		PFNGLUNIFORM4UIVPROC                            _glUniform4uiv;
		PFNGLTEXPARAMETERIIVPROC                        _glTexParameterIiv;
		PFNGLTEXPARAMETERIUIVPROC                       _glTexParameterIuiv;
		PFNGLGETTEXPARAMETERIIVPROC                     _glGetTexParameterIiv;
		PFNGLGETTEXPARAMETERIUIVPROC                    _glGetTexParameterIuiv;
		PFNGLCLEARBUFFERIVPROC                          _glClearBufferiv;
		PFNGLCLEARBUFFERUIVPROC                         _glClearBufferuiv;
		PFNGLCLEARBUFFERFVPROC                          _glClearBufferfv;
		PFNGLCLEARBUFFERFIPROC                          _glClearBufferfi;
		PFNGLGETSTRINGIPROC                             _glGetStringi;
		PFNGLISRENDERBUFFERPROC                         _glIsRenderbuffer;
		PFNGLBINDRENDERBUFFERPROC                       _glBindRenderbuffer;
		PFNGLDELETERENDERBUFFERSPROC                    _glDeleteRenderbuffers;
		PFNGLGENRENDERBUFFERSPROC                       _glGenRenderbuffers;
		PFNGLRENDERBUFFERSTORAGEPROC                    _glRenderbufferStorage;
		PFNGLGETRENDERBUFFERPARAMETERIVPROC             _glGetRenderbufferParameteriv;
		PFNGLISFRAMEBUFFERPROC                          _glIsFramebuffer;
		PFNGLBINDFRAMEBUFFERPROC                        _glBindFramebuffer;
		PFNGLDELETEFRAMEBUFFERSPROC                     _glDeleteFramebuffers;
		PFNGLGENFRAMEBUFFERSPROC                        _glGenFramebuffers;
		PFNGLCHECKFRAMEBUFFERSTATUSPROC                 _glCheckFramebufferStatus;
		PFNGLFRAMEBUFFERTEXTURE1DPROC                   _glFramebufferTexture1D;
		PFNGLFRAMEBUFFERTEXTURE2DPROC                   _glFramebufferTexture2D;
		PFNGLFRAMEBUFFERTEXTURE3DPROC                   _glFramebufferTexture3D;
		PFNGLFRAMEBUFFERRENDERBUFFERPROC                _glFramebufferRenderbuffer;
		PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC    _glGetFramebufferAttachmentParameteriv;
		PFNGLGENERATEMIPMAPPROC                         _glGenerateMipmap;
		PFNGLBLITFRAMEBUFFERPROC                        _glBlitFramebuffer;
		PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC         _glRenderbufferStorageMultisample;
		PFNGLFRAMEBUFFERTEXTURELAYERPROC                _glFramebufferTextureLayer;
		PFNGLMAPBUFFERRANGEPROC                         _glMapBufferRange;
		PFNGLFLUSHMAPPEDBUFFERRANGEPROC                 _glFlushMappedBufferRange;
		PFNGLBINDVERTEXARRAYPROC                        _glBindVertexArray;
		PFNGLDELETEVERTEXARRAYSPROC                     _glDeleteVertexArrays;
		PFNGLGENVERTEXARRAYSPROC                        _glGenVertexArrays;
		PFNGLISVERTEXARRAYPROC                          _glIsVertexArray;
		// 3.1
		PFNGLDRAWARRAYSINSTANCEDPROC                    _glDrawArraysInstanced;
		PFNGLDRAWELEMENTSINSTANCEDPROC                  _glDrawElementsInstanced;
		PFNGLTEXBUFFERPROC                              _glTexBuffer;
		PFNGLPRIMITIVERESTARTINDEXPROC                  _glPrimitiveRestartIndex;
		PFNGLCOPYBUFFERSUBDATAPROC                      _glCopyBufferSubData;
		PFNGLGETUNIFORMINDICESPROC                      _glGetUniformIndices;
		PFNGLGETACTIVEUNIFORMSIVPROC                    _glGetActiveUniformsiv;
		PFNGLGETACTIVEUNIFORMNAMEPROC                   _glGetActiveUniformName;
		PFNGLGETUNIFORMBLOCKINDEXPROC                   _glGetUniformBlockIndex;
		PFNGLGETACTIVEUNIFORMBLOCKIVPROC                _glGetActiveUniformBlockiv;
		PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC              _glGetActiveUniformBlockName;
		PFNGLUNIFORMBLOCKBINDINGPROC                    _glUniformBlockBinding;
		// 3.2
		PFNGLDRAWELEMENTSBASEVERTEXPROC                 _glDrawElementsBaseVertex;
		PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC            _glDrawRangeElementsBaseVertex;
		PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC        _glDrawElementsInstancedBaseVertex;
		PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC            _glMultiDrawElementsBaseVertex;
		PFNGLPROVOKINGVERTEXPROC                        _glProvokingVertex;
		PFNGLFENCESYNCPROC                              _glFenceSync;
		PFNGLISSYNCPROC                                 _glIsSync;
		PFNGLDELETESYNCPROC                             _glDeleteSync;
		PFNGLCLIENTWAITSYNCPROC                         _glClientWaitSync;
		PFNGLWAITSYNCPROC                               _glWaitSync;
		PFNGLGETINTEGER64VPROC                          _glGetInteger64v;
		PFNGLGETSYNCIVPROC                              _glGetSynciv;
		PFNGLGETINTEGER64I_VPROC                        _glGetInteger64i_v;
		PFNGLGETBUFFERPARAMETERI64VPROC                 _glGetBufferParameteri64v;
		PFNGLFRAMEBUFFERTEXTUREPROC                     _glFramebufferTexture;
		PFNGLTEXIMAGE2DMULTISAMPLEPROC                  _glTexImage2DMultisample;
		PFNGLTEXIMAGE3DMULTISAMPLEPROC                  _glTexImage3DMultisample;
		PFNGLGETMULTISAMPLEFVPROC                       _glGetMultisamplefv;
		PFNGLSAMPLEMASKIPROC                            _glSampleMaski;
		// 3.3
		PFNGLBINDFRAGDATALOCATIONINDEXEDPROC            _glBindFragDataLocationIndexed;
		PFNGLGETFRAGDATAINDEXPROC                       _glGetFragDataIndex;
		PFNGLGENSAMPLERSPROC                            _glGenSamplers;
		PFNGLDELETESAMPLERSPROC                         _glDeleteSamplers;
		PFNGLISSAMPLERPROC                              _glIsSampler;
		PFNGLBINDSAMPLERPROC                            _glBindSampler;
		PFNGLSAMPLERPARAMETERIPROC                      _glSamplerParameteri;
		PFNGLSAMPLERPARAMETERIVPROC                     _glSamplerParameteriv;
		PFNGLSAMPLERPARAMETERFPROC                      _glSamplerParameterf;
		PFNGLSAMPLERPARAMETERFVPROC                     _glSamplerParameterfv;
		PFNGLSAMPLERPARAMETERIIVPROC                    _glSamplerParameterIiv;
		PFNGLSAMPLERPARAMETERIUIVPROC                   _glSamplerParameterIuiv;
		PFNGLGETSAMPLERPARAMETERIVPROC                  _glGetSamplerParameteriv;
		PFNGLGETSAMPLERPARAMETERIIVPROC                 _glGetSamplerParameterIiv;
		PFNGLGETSAMPLERPARAMETERFVPROC                  _glGetSamplerParameterfv;
		PFNGLGETSAMPLERPARAMETERIUIVPROC                _glGetSamplerParameterIuiv;
		PFNGLQUERYCOUNTERPROC                           _glQueryCounter;
		PFNGLGETQUERYOBJECTI64VPROC                     _glGetQueryObjecti64v;
		PFNGLGETQUERYOBJECTUI64VPROC                    _glGetQueryObjectui64v;
		PFNGLVERTEXATTRIBDIVISORPROC                    _glVertexAttribDivisor;
		PFNGLVERTEXATTRIBP1UIPROC                       _glVertexAttribP1ui;
		PFNGLVERTEXATTRIBP1UIVPROC                      _glVertexAttribP1uiv;
		PFNGLVERTEXATTRIBP2UIPROC                       _glVertexAttribP2ui;
		PFNGLVERTEXATTRIBP2UIVPROC                      _glVertexAttribP2uiv;
		PFNGLVERTEXATTRIBP3UIPROC                       _glVertexAttribP3ui;
		PFNGLVERTEXATTRIBP3UIVPROC                      _glVertexAttribP3uiv;
		PFNGLVERTEXATTRIBP4UIPROC                       _glVertexAttribP4ui;
		PFNGLVERTEXATTRIBP4UIVPROC                      _glVertexAttribP4uiv;
		// GL_ARB_shader_subroutine of GL4.0
#if 0
		PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC           _glGetSubroutineUniformLocation;
		PFNGLGETSUBROUTINEINDEXPROC                     _glGetSubroutineIndex;
		PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC           _glGetActiveSubroutineUniformiv;
		PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC         _glGetActiveSubroutineUniformName;
		PFNGLGETACTIVESUBROUTINENAMEPROC                _glGetActiveSubroutineName;
		PFNGLUNIFORMSUBROUTINESUIVPROC                  _glUniformSubroutinesuiv;
		PFNGLGETUNIFORMSUBROUTINEUIVPROC                _glGetUniformSubroutineuiv;
		PFNGLGETPROGRAMSTAGEIVPROC                      _glGetProgramStageivARB;

		// 4.2
		PFNGLTEXSTORAGE3DPROC                           _glTexStorage3D;
		// 4.5
		PFNGLCREATEBUFFERSPROC                          _glCreateBuffers;
		PFNGLNAMEDBUFFERDATAPROC                        _glNamedBufferData;
		PFNGLMAPNAMEDBUFFERPROC                         _glMapNamedBuffer;
		PFNGLUNMAPNAMEDBUFFERPROC                       _glUnmapNamedBuffer;
#endif
	};
};

#define glCullFace								funcTable._glCullFace
#define glFrontFace								funcTable._glFrontFace
#define glHint									funcTable._glHint
#define glLineWidth								funcTable._glLineWidth
#define glPointSize								funcTable._glPointSize
#define glPolygonMode							funcTable._glPolygonMode
#define glScissor								funcTable._glScissor
#define glTexParameterf							funcTable._glTexParameterf
#define glTexParameterfv						funcTable._glTexParameterfv
#define glTexParameteri							funcTable._glTexParameteri
#define glTexParameteriv						funcTable._glTexParameteriv
#define glTexImage1D							funcTable._glTexImage1D
#define glTexImage2D							funcTable._glTexImage2D
#define glDrawBuffer							funcTable._glDrawBuffer
#define glClear									funcTable._glClear
#define glClearColor							funcTable._glClearColor
#define glClearStencil							funcTable._glClearStencil
#define glClearDepth							funcTable._glClearDepth
#define glStencilMask							funcTable._glStencilMask
#define glColorMask								funcTable._glColorMask
#define glDepthMask								funcTable._glDepthMask
#define glDisable								funcTable._glDisable
#define glEnable								funcTable._glEnable
#define glFinish								funcTable._glFinish
#define glFlush									funcTable._glFlush
#define glBlendFunc								funcTable._glBlendFunc
#define glLogicOp								funcTable._glLogicOp
#define glStencilFunc							funcTable._glStencilFunc
#define glStencilOp								funcTable._glStencilOp
#define glDepthFunc								funcTable._glDepthFunc
#define glPixelStoref							funcTable._glPixelStoref
#define glPixelStorei							funcTable._glPixelStorei
#define glReadBuffer							funcTable._glReadBuffer
#define glReadPixels							funcTable._glReadPixels
#define glGetBooleanv							funcTable._glGetBooleanv
#define glGetDoublev							funcTable._glGetDoublev
#define glGetError								funcTable._glGetError
#define glGetFloatv								funcTable._glGetFloatv
#define glGetIntegerv							funcTable._glGetIntegerv
#define glGetString								funcTable._glGetString
#define glGetTexImage							funcTable._glGetTexImage
#define glGetTexParameterfv						funcTable._glGetTexParameterfv
#define glGetTexParameteriv						funcTable._glGetTexParameteriv
#define glGetTexLevelParameterfv				funcTable._glGetTexLevelParameterfv
#define glGetTexLevelParameteriv				funcTable._glGetTexLevelParameteriv
#define glIsEnabled								funcTable._glIsEnabled
#define glDepthRange							funcTable._glDepthRange
#define glViewport								funcTable._glViewport
#define glDrawArrays							funcTable._glDrawArrays
#define glDrawElements							funcTable._glDrawElements
#define glGetPointerv							funcTable._glGetPointerv
#define glPolygonOffset							funcTable._glPolygonOffset
#define glCopyTexImage1D						funcTable._glCopyTexImage1D
#define glCopyTexImage2D						funcTable._glCopyTexImage2D
#define glCopyTexSubImage1D						funcTable._glCopyTexSubImage1D
#define glCopyTexSubImage2D						funcTable._glCopyTexSubImage2D
#define glTexSubImage1D							funcTable._glTexSubImage1D
#define glTexSubImage2D							funcTable._glTexSubImage2D
#define glBindTexture							funcTable._glBindTexture
#define glDeleteTextures						funcTable._glDeleteTextures
#define glGenTextures							funcTable._glGenTextures
#define glIsTexture								funcTable._glIsTexture
#define glDrawRangeElements						funcTable._glDrawRangeElements
#define glTexImage3D							funcTable._glTexImage3D
#define glTexSubImage3D							funcTable._glTexSubImage3D
#define glCopyTexSubImage3D						funcTable._glCopyTexSubImage3D
#define glActiveTexture							funcTable._glActiveTexture
#define glSampleCoverage						funcTable._glSampleCoverage
#define glCompressedTexImage3D					funcTable._glCompressedTexImage3D
#define glCompressedTexImage2D					funcTable._glCompressedTexImage2D
#define glCompressedTexImage1D					funcTable._glCompressedTexImage1D
#define glCompressedTexSubImage3D				funcTable._glCompressedTexSubImage3D
#define glCompressedTexSubImage2D				funcTable._glCompressedTexSubImage2D
#define glCompressedTexSubImage1D				funcTable._glCompressedTexSubImage1D
#define glGetCompressedTexImage					funcTable._glGetCompressedTexImage
#define glBlendFuncSeparate						funcTable._glBlendFuncSeparate
#define glMultiDrawArrays						funcTable._glMultiDrawArrays
#define glMultiDrawElements						funcTable._glMultiDrawElements
#define glPointParameterf						funcTable._glPointParameterf
#define glPointParameterfv						funcTable._glPointParameterfv
#define glPointParameteri						funcTable._glPointParameteri
#define glPointParameteriv						funcTable._glPointParameteriv
#define glBlendColor							funcTable._glBlendColor
#define glBlendEquation							funcTable._glBlendEquation
#define glGenQueries							funcTable._glGenQueries
#define glDeleteQueries							funcTable._glDeleteQueries
#define glIsQuery								funcTable._glIsQuery
#define glBeginQuery							funcTable._glBeginQuery
#define glEndQuery								funcTable._glEndQuery
#define glGetQueryiv							funcTable._glGetQueryiv
#define glGetQueryObjectiv						funcTable._glGetQueryObjectiv
#define glGetQueryObjectuiv						funcTable._glGetQueryObjectuiv
#define glBindBuffer							funcTable._glBindBuffer
#define glDeleteBuffers							funcTable._glDeleteBuffers
#define glGenBuffers							funcTable._glGenBuffers
#define glIsBuffer								funcTable._glIsBuffer
#define glBufferData							funcTable._glBufferData
#define glBufferSubData							funcTable._glBufferSubData
#define glGetBufferSubData						funcTable._glGetBufferSubData
#define glMapBuffer								funcTable._glMapBuffer
#define glUnmapBuffer							funcTable._glUnmapBuffer
#define glGetBufferParameteriv					funcTable._glGetBufferParameteriv
#define glGetBufferPointerv						funcTable._glGetBufferPointerv
#define glBlendEquationSeparate					funcTable._glBlendEquationSeparate
#define glDrawBuffers							funcTable._glDrawBuffers
#define glStencilOpSeparate						funcTable._glStencilOpSeparate
#define glStencilFuncSeparate					funcTable._glStencilFuncSeparate
#define glStencilMaskSeparate					funcTable._glStencilMaskSeparate
#define glAttachShader							funcTable._glAttachShader
#define glBindAttribLocation					funcTable._glBindAttribLocation
#define glCompileShader							funcTable._glCompileShader
#define glCreateProgram							funcTable._glCreateProgram
#define glCreateShader							funcTable._glCreateShader
#define glDeleteProgram							funcTable._glDeleteProgram
#define glDeleteShader							funcTable._glDeleteShader
#define glDetachShader							funcTable._glDetachShader
#define glDisableVertexAttribArray				funcTable._glDisableVertexAttribArray
#define glEnableVertexAttribArray				funcTable._glEnableVertexAttribArray
#define glGetActiveAttrib						funcTable._glGetActiveAttrib
#define glGetActiveUniform						funcTable._glGetActiveUniform
#define glGetAttachedShaders					funcTable._glGetAttachedShaders
#define glGetAttribLocation						funcTable._glGetAttribLocation
#define glGetProgramiv							funcTable._glGetProgramiv
#define glGetProgramInfoLog						funcTable._glGetProgramInfoLog
#define glGetShaderiv							funcTable._glGetShaderiv
#define glGetShaderInfoLog						funcTable._glGetShaderInfoLog
#define glGetShaderSource						funcTable._glGetShaderSource
#define glGetUniformLocation					funcTable._glGetUniformLocation
#define glGetUniformfv							funcTable._glGetUniformfv
#define glGetUniformiv							funcTable._glGetUniformiv
#define glGetVertexAttribdv						funcTable._glGetVertexAttribdv
#define glGetVertexAttribfv						funcTable._glGetVertexAttribfv
#define glGetVertexAttribiv						funcTable._glGetVertexAttribiv
#define glGetVertexAttribPointerv				funcTable._glGetVertexAttribPointerv
#define glIsProgram								funcTable._glIsProgram
#define glIsShader								funcTable._glIsShader
#define glLinkProgram							funcTable._glLinkProgram
#define glShaderSource							funcTable._glShaderSource
#define glUseProgram							funcTable._glUseProgram
#define glUniform1f								funcTable._glUniform1f
#define glUniform2f								funcTable._glUniform2f
#define glUniform3f								funcTable._glUniform3f
#define glUniform4f								funcTable._glUniform4f
#define glUniform1i								funcTable._glUniform1i
#define glUniform2i								funcTable._glUniform2i
#define glUniform3i								funcTable._glUniform3i
#define glUniform4i								funcTable._glUniform4i
#define glUniform1fv							funcTable._glUniform1fv
#define glUniform2fv							funcTable._glUniform2fv
#define glUniform3fv							funcTable._glUniform3fv
#define glUniform4fv							funcTable._glUniform4fv
#define glUniform1iv							funcTable._glUniform1iv
#define glUniform2iv							funcTable._glUniform2iv
#define glUniform3iv							funcTable._glUniform3iv
#define glUniform4iv							funcTable._glUniform4iv
#define glUniformMatrix2fv						funcTable._glUniformMatrix2fv
#define glUniformMatrix3fv						funcTable._glUniformMatrix3fv
#define glUniformMatrix4fv						funcTable._glUniformMatrix4fv
#define glValidateProgram						funcTable._glValidateProgram
#define glVertexAttrib1d						funcTable._glVertexAttrib1d
#define glVertexAttrib1dv						funcTable._glVertexAttrib1dv
#define glVertexAttrib1f						funcTable._glVertexAttrib1f
#define glVertexAttrib1fv						funcTable._glVertexAttrib1fv
#define glVertexAttrib1s						funcTable._glVertexAttrib1s
#define glVertexAttrib1sv						funcTable._glVertexAttrib1sv
#define glVertexAttrib2d						funcTable._glVertexAttrib2d
#define glVertexAttrib2dv						funcTable._glVertexAttrib2dv
#define glVertexAttrib2f						funcTable._glVertexAttrib2f
#define glVertexAttrib2fv						funcTable._glVertexAttrib2fv
#define glVertexAttrib2s						funcTable._glVertexAttrib2s
#define glVertexAttrib2sv						funcTable._glVertexAttrib2sv
#define glVertexAttrib3d						funcTable._glVertexAttrib3d
#define glVertexAttrib3dv						funcTable._glVertexAttrib3dv
#define glVertexAttrib3f						funcTable._glVertexAttrib3f
#define glVertexAttrib3fv						funcTable._glVertexAttrib3fv
#define glVertexAttrib3s						funcTable._glVertexAttrib3s
#define glVertexAttrib3sv						funcTable._glVertexAttrib3sv
#define glVertexAttrib4Nbv						funcTable._glVertexAttrib4Nbv
#define glVertexAttrib4Niv						funcTable._glVertexAttrib4Niv
#define glVertexAttrib4Nsv						funcTable._glVertexAttrib4Nsv
#define glVertexAttrib4Nub						funcTable._glVertexAttrib4Nub
#define glVertexAttrib4Nubv						funcTable._glVertexAttrib4Nubv
#define glVertexAttrib4Nuiv						funcTable._glVertexAttrib4Nuiv
#define glVertexAttrib4Nusv						funcTable._glVertexAttrib4Nusv
#define glVertexAttrib4bv						funcTable._glVertexAttrib4bv
#define glVertexAttrib4d						funcTable._glVertexAttrib4d
#define glVertexAttrib4dv						funcTable._glVertexAttrib4dv
#define glVertexAttrib4f						funcTable._glVertexAttrib4f
#define glVertexAttrib4fv						funcTable._glVertexAttrib4fv
#define glVertexAttrib4iv						funcTable._glVertexAttrib4iv
#define glVertexAttrib4s						funcTable._glVertexAttrib4s
#define glVertexAttrib4sv						funcTable._glVertexAttrib4sv
#define glVertexAttrib4ubv						funcTable._glVertexAttrib4ubv
#define glVertexAttrib4uiv						funcTable._glVertexAttrib4uiv
#define glVertexAttrib4usv						funcTable._glVertexAttrib4usv
#define glVertexAttribPointer					funcTable._glVertexAttribPointer
#define glUniformMatrix2x3fv					funcTable._glUniformMatrix2x3fv
#define glUniformMatrix3x2fv					funcTable._glUniformMatrix3x2fv
#define glUniformMatrix2x4fv					funcTable._glUniformMatrix2x4fv
#define glUniformMatrix4x2fv					funcTable._glUniformMatrix4x2fv
#define glUniformMatrix3x4fv					funcTable._glUniformMatrix3x4fv
#define glUniformMatrix4x3fv					funcTable._glUniformMatrix4x3fv
#define glColorMaski							funcTable._glColorMaski
#define glGetBooleani_v							funcTable._glGetBooleani_v
#define glGetIntegeri_v							funcTable._glGetIntegeri_v
#define glEnablei								funcTable._glEnablei
#define glDisablei								funcTable._glDisablei
#define glIsEnabledi							funcTable._glIsEnabledi
#define glBeginTransformFeedback				funcTable._glBeginTransformFeedback
#define glEndTransformFeedback					funcTable._glEndTransformFeedback
#define glBindBufferRange						funcTable._glBindBufferRange
#define glBindBufferBase						funcTable._glBindBufferBase
#define glTransformFeedbackVaryings				funcTable._glTransformFeedbackVaryings
#define glGetTransformFeedbackVarying			funcTable._glGetTransformFeedbackVarying
#define glClampColor							funcTable._glClampColor
#define glBeginConditionalRender				funcTable._glBeginConditionalRender
#define glEndConditionalRender					funcTable._glEndConditionalRender
#define glVertexAttribIPointer					funcTable._glVertexAttribIPointer
#define glGetVertexAttribIiv					funcTable._glGetVertexAttribIiv
#define glGetVertexAttribIuiv					funcTable._glGetVertexAttribIuiv
#define glVertexAttribI1i						funcTable._glVertexAttribI1i
#define glVertexAttribI2i						funcTable._glVertexAttribI2i
#define glVertexAttribI3i						funcTable._glVertexAttribI3i
#define glVertexAttribI4i						funcTable._glVertexAttribI4i
#define glVertexAttribI1ui						funcTable._glVertexAttribI1ui
#define glVertexAttribI2ui						funcTable._glVertexAttribI2ui
#define glVertexAttribI3ui						funcTable._glVertexAttribI3ui
#define glVertexAttribI4ui						funcTable._glVertexAttribI4ui
#define glVertexAttribI1iv						funcTable._glVertexAttribI1iv
#define glVertexAttribI2iv						funcTable._glVertexAttribI2iv
#define glVertexAttribI3iv						funcTable._glVertexAttribI3iv
#define glVertexAttribI4iv						funcTable._glVertexAttribI4iv
#define glVertexAttribI1uiv						funcTable._glVertexAttribI1uiv
#define glVertexAttribI2uiv						funcTable._glVertexAttribI2uiv
#define glVertexAttribI3uiv						funcTable._glVertexAttribI3uiv
#define glVertexAttribI4uiv						funcTable._glVertexAttribI4uiv
#define glVertexAttribI4bv						funcTable._glVertexAttribI4bv
#define glVertexAttribI4sv						funcTable._glVertexAttribI4sv
#define glVertexAttribI4ubv						funcTable._glVertexAttribI4ubv
#define glVertexAttribI4usv						funcTable._glVertexAttribI4usv
#define glGetUniformuiv							funcTable._glGetUniformuiv
#define glBindFragDataLocation					funcTable._glBindFragDataLocation
#define glGetFragDataLocation					funcTable._glGetFragDataLocation
#define glUniform1ui							funcTable._glUniform1ui
#define glUniform2ui							funcTable._glUniform2ui
#define glUniform3ui							funcTable._glUniform3ui
#define glUniform4ui							funcTable._glUniform4ui
#define glUniform1uiv							funcTable._glUniform1uiv
#define glUniform2uiv							funcTable._glUniform2uiv
#define glUniform3uiv							funcTable._glUniform3uiv
#define glUniform4uiv							funcTable._glUniform4uiv
#define glTexParameterIiv						funcTable._glTexParameterIiv
#define glTexParameterIuiv						funcTable._glTexParameterIuiv
#define glGetTexParameterIiv					funcTable._glGetTexParameterIiv
#define glGetTexParameterIuiv					funcTable._glGetTexParameterIuiv
#define glClearBufferiv							funcTable._glClearBufferiv
#define glClearBufferuiv						funcTable._glClearBufferuiv
#define glClearBufferfv							funcTable._glClearBufferfv
#define glClearBufferfi							funcTable._glClearBufferfi
#define glGetStringi							funcTable._glGetStringi
#define glIsRenderbuffer						funcTable._glIsRenderbuffer
#define glBindRenderbuffer						funcTable._glBindRenderbuffer
#define glDeleteRenderbuffers					funcTable._glDeleteRenderbuffers
#define glGenRenderbuffers						funcTable._glGenRenderbuffers
#define glRenderbufferStorage					funcTable._glRenderbufferStorage
#define glGetRenderbufferParameteriv			funcTable._glGetRenderbufferParameteriv
#define glIsFramebuffer							funcTable._glIsFramebuffer
#define glBindFramebuffer						funcTable._glBindFramebuffer
#define glDeleteFramebuffers					funcTable._glDeleteFramebuffers
#define glGenFramebuffers						funcTable._glGenFramebuffers
#define glCheckFramebufferStatus				funcTable._glCheckFramebufferStatus
#define glFramebufferTexture1D					funcTable._glFramebufferTexture1D
#define glFramebufferTexture2D					funcTable._glFramebufferTexture2D
#define glFramebufferTexture3D					funcTable._glFramebufferTexture3D
#define glFramebufferRenderbuffer				funcTable._glFramebufferRenderbuffer
#define glGetFramebufferAttachmentParameteriv	funcTable._glGetFramebufferAttachmentParameteriv
#define glGenerateMipmap						funcTable._glGenerateMipmap
#define glBlitFramebuffer						funcTable._glBlitFramebuffer
#define glRenderbufferStorageMultisample		funcTable._glRenderbufferStorageMultisample
#define glFramebufferTextureLayer				funcTable._glFramebufferTextureLayer
#define glMapBufferRange						funcTable._glMapBufferRange
#define glFlushMappedBufferRange				funcTable._glFlushMappedBufferRange
#define glBindVertexArray						funcTable._glBindVertexArray
#define glDeleteVertexArrays					funcTable._glDeleteVertexArrays
#define glGenVertexArrays						funcTable._glGenVertexArrays
#define glIsVertexArray							funcTable._glIsVertexArray
#define glDrawArraysInstanced					funcTable._glDrawArraysInstanced
#define glDrawElementsInstanced					funcTable._glDrawElementsInstanced
#define glTexBuffer								funcTable._glTexBuffer
#define glPrimitiveRestartIndex					funcTable._glPrimitiveRestartIndex
#define glCopyBufferSubData						funcTable._glCopyBufferSubData
#define glGetUniformIndices						funcTable._glGetUniformIndices
#define glGetActiveUniformsiv					funcTable._glGetActiveUniformsiv
#define glGetActiveUniformName					funcTable._glGetActiveUniformName
#define glGetUniformBlockIndex					funcTable._glGetUniformBlockIndex
#define glGetActiveUniformBlockiv				funcTable._glGetActiveUniformBlockiv
#define glGetActiveUniformBlockName				funcTable._glGetActiveUniformBlockName
#define glUniformBlockBinding					funcTable._glUniformBlockBinding
#define glDrawElementsBaseVertex				funcTable._glDrawElementsBaseVertex
#define glDrawRangeElementsBaseVertex			funcTable._glDrawRangeElementsBaseVertex
#define glDrawElementsInstancedBaseVertex		funcTable._glDrawElementsInstancedBaseVertex
#define glMultiDrawElementsBaseVertex			funcTable._glMultiDrawElementsBaseVertex
#define glProvokingVertex						funcTable._glProvokingVertex
#define glFenceSync								funcTable._glFenceSync
#define glIsSync								funcTable._glIsSync
#define glDeleteSync							funcTable._glDeleteSync
#define glClientWaitSync						funcTable._glClientWaitSync
#define glWaitSync								funcTable._glWaitSync
#define glGetInteger64v							funcTable._glGetInteger64v
#define glGetSynciv								funcTable._glGetSynciv
#define glGetInteger64i_v						funcTable._glGetInteger64i_v
#define glGetBufferParameteri64v				funcTable._glGetBufferParameteri64v
#define glFramebufferTexture					funcTable._glFramebufferTexture
#define glTexImage2DMultisample					funcTable._glTexImage2DMultisample
#define glTexImage3DMultisample					funcTable._glTexImage3DMultisample
#define glGetMultisamplefv						funcTable._glGetMultisamplefv
#define glSampleMaski							funcTable._glSampleMaski
#define glBindFragDataLocationIndexed			funcTable._glBindFragDataLocationIndexed
#define glGetFragDataIndex						funcTable._glGetFragDataIndex
#define glGenSamplers							funcTable._glGenSamplers
#define glDeleteSamplers						funcTable._glDeleteSamplers
#define glIsSampler								funcTable._glIsSampler
#define glBindSampler							funcTable._glBindSampler
#define glSamplerParameteri						funcTable._glSamplerParameteri
#define glSamplerParameteriv					funcTable._glSamplerParameteriv
#define glSamplerParameterf						funcTable._glSamplerParameterf
#define glSamplerParameterfv					funcTable._glSamplerParameterfv
#define glSamplerParameterIiv					funcTable._glSamplerParameterIiv
#define glSamplerParameterIuiv					funcTable._glSamplerParameterIuiv
#define glGetSamplerParameteriv					funcTable._glGetSamplerParameteriv
#define glGetSamplerParameterIiv				funcTable._glGetSamplerParameterIiv
#define glGetSamplerParameterfv					funcTable._glGetSamplerParameterfv
#define glGetSamplerParameterIuiv				funcTable._glGetSamplerParameterIuiv
#define glQueryCounter							funcTable._glQueryCounter
#define glGetQueryObjecti64v					funcTable._glGetQueryObjecti64v
#define glGetQueryObjectui64v					funcTable._glGetQueryObjectui64v
#define glVertexAttribDivisor					funcTable._glVertexAttribDivisor
#define glVertexAttribP1ui						funcTable._glVertexAttribP1ui
#define glVertexAttribP1uiv						funcTable._glVertexAttribP1uiv
#define glVertexAttribP2ui						funcTable._glVertexAttribP2ui
#define glVertexAttribP2uiv						funcTable._glVertexAttribP2uiv
#define glVertexAttribP3ui						funcTable._glVertexAttribP3ui
#define glVertexAttribP3uiv						funcTable._glVertexAttribP3uiv
#define glVertexAttribP4ui						funcTable._glVertexAttribP4ui
#define glVertexAttribP4uiv						funcTable._glVertexAttribP4uiv

GLFuncTable LoadOpenGLFunctions();

void CreateContextOpenGL(HWND hWNDToDC);
void DeleteContextOpenGL(HWND hWNDToDC);