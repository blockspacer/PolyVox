/*******************************************************************************
Copyright (c) 2005-2009 David Williams

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution. 	
*******************************************************************************/

#ifndef __OpenGLExample_OpenGLVertexBufferObjectSupport_H__
#define __OpenGLExample_OpenGLVertexBufferObjectSupport_H__

#include "PolyVoxCore/PolyVoxForwardDeclarations.h"

#include "glew/glew.h"

struct OpenGLMesh
{
	GLulong noOfIndices;
	GLuint indexBuffer;
	GLuint vertexBuffer;
	const PolyVox::Mesh<PolyVox::MarchingCubesVertex<PolyVox::MaterialDensityPair44> >* sourceMesh;
};

OpenGLMesh BuildOpenGLMesh(const PolyVox::Mesh<PolyVox::MarchingCubesVertex<PolyVox::MaterialDensityPair44> >& mesh);
void renderRegionVertexBufferObject(const OpenGLMesh& openGLMesh, unsigned int uLodLevel);

#endif //__OpenGLExample_OpenGLVertexBufferObjectSupport_H__
