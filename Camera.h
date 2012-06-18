//CVector3 class and some Camera code taken from the following source
//***********************************************************************//
//																		 //
//		- "Talk to me like a 3 year old!" Programming Lessons -			 //
//                                                                       //
//		$Author:		DigiBen			DigiBen@GameTutorials.com		 //
//																		 //
//		$Program:		HeightMap6										 //
//																		 //
//		$Description:	Using shaders we show realistic-refracted water  //
//																		 //
//***********************************************************************//

#pragma once

#ifndef Camera_h
#define Camera_h

#include <windows.h>
#include <GL\glu.h>
#include <cmath>
#include "Vector.h"

class CCamera
{
public:
	// Our camera constructor
	CCamera();	

	// These are are data access functions for our camera's private data
	CVector3 position() {	return m_vPosition;		}
	CVector3 view()		{	return m_vView;			}
	CVector3 upVector() {	return m_vUpVector;		}

	void positionCamera(float positionX, float positionY, float positionZ,
			 		    float viewX,     float viewY,     float viewZ,
						float upVectorX, float upVectorY, float upVectorZ);

	//operations
	void rotateView(float angle, float X, float Y, float Z);
	void look();
	void strafe(GLfloat speed);
	void pitch(GLfloat degree);
	void turn(GLfloat degree);
	void move(GLfloat speed);

private:

	// The camera's position
	CVector3 m_vPosition;					

	// The camera's view
	CVector3 m_vView;						

	// The camera's up vector
	CVector3 m_vUpVector;		
};
#endif //Camera_h
