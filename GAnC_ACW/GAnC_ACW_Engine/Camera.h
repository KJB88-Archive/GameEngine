#pragma once
#include "Vector3.h"

class Camera
{
public:

	Camera() : m_yaw(0.0f), m_pitch(0.0f), m_roll(0.0f) {};
	virtual ~Camera() {};

	//virtual void UpdateEyePosition(Vector3 eyePos) = 0;
	//virtual void UpdateLookAtPosition(Vector3 lookAt) = 0;
	//virtual void UpdateUpVector(Vector3 up) = 0;

	//virtual void Translate(Vector3 newPos) = 0;
	//virtual void Rotate(Vector3 axis, float degrees) = 0;
	//virtual void UpdateRotationMatrix(Vector3 rotationMatrix) = 0;
	//virtual void Update() = 0;

	//Vector3 GetLookAt() { return m_lookAtVec; }
	////void SetLookAt(Vector3 lookAt) { m_lookAtVec = lookAt; }
	//Vector3 GetUpVector() { return m_upVec; }
	////void SetUpVector(Vector3 upVec) { m_upVec = upVec; }
	//Vector3 GetEyePosition() { return m_eyePosVec; }
	////void SetEyePosition(Vector3 eyePos) { m_eyePosVec = eyePos; }

	//float GetYaw() { return m_yaw; }
	//void SetYaw(float yaw) { m_yaw = yaw; }
	//float GetPitch() { return m_pitch; }
	//void SetPitch(float pitch) { m_pitch = pitch; }
	//float GetRoll() { return m_roll; }
	//void SetRoll(float roll) { m_roll = roll; }

protected:

	Vector3 m_lookAtVec;
	Vector3 m_upVec;
	Vector3 m_eyePosVec;

	float m_yaw;
	float m_pitch;
	float m_roll;

};