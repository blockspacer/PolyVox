/*******************************************************************************
Copyright (c) 2010 Matt Williams

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

#ifndef __PolyVox_TestVolume_H__
#define __PolyVox_TestVolume_H__

#include "PolyVoxCore/PolyVoxForwardDeclarations.h"

#include <QObject>

class TestVolume: public QObject
{
	Q_OBJECT

public:
	TestVolume();
	~TestVolume();
	
private slots:
	void testRawVolumeDirectAccessAllInternalForwards();
	void testRawVolumeSamplersAllInternalForwards();
	void testRawVolumeDirectAccessWithExternalForwards();
	void testRawVolumeSamplersWithExternalForwards();
	void testRawVolumeDirectAccessAllInternalBackwards();
	void testRawVolumeSamplersAllInternalBackwards();
	void testRawVolumeDirectAccessWithExternalBackwards();
	void testRawVolumeSamplersWithExternalBackwards();

	void testSimpleVolumeDirectAccessAllInternalForwards();
	void testSimpleVolumeSamplersAllInternalForwards();
	void testSimpleVolumeDirectAccessWithExternalForwards();
	void testSimpleVolumeSamplersWithExternalForwards();
	void testSimpleVolumeDirectAccessAllInternalBackwards();
	void testSimpleVolumeSamplersAllInternalBackwards();
	void testSimpleVolumeDirectAccessWithExternalBackwards();
	void testSimpleVolumeSamplersWithExternalBackwards();

	void testLargeVolumeDirectAccessAllInternalForwards();
	void testLargeVolumeSamplersAllInternalForwards();
	void testLargeVolumeDirectAccessWithExternalForwards();
	void testLargeVolumeSamplersWithExternalForwards();
	void testLargeVolumeDirectAccessAllInternalBackwards();
	void testLargeVolumeSamplersAllInternalBackwards();
	void testLargeVolumeDirectAccessWithExternalBackwards();
	void testLargeVolumeSamplersWithExternalBackwards();

private:
	PolyVox::Compressor* m_pCompressor;
	PolyVox::RawVolume<int32_t>* m_pRawVolume;
	PolyVox::SimpleVolume<int32_t>* m_pSimpleVolume;
	PolyVox::LargeVolume<int32_t>* m_pLargeVolume;
};

#endif
