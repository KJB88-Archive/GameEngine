#pragma once
#include "Manager.h"
#include <map>

class ObserverSubject;
class Observer;

typedef std::map<std::string, ObserverSubject*> SubjectMap;
typedef std::map<std::string, ObserverSubject*>::iterator SubjectIterator;

class SubjectManager
	: public Manager
{
public:
	SubjectManager();
	virtual ~SubjectManager();

	// Register subject with relevant messages
	static void RegisterSubject(std::string msg, ObserverSubject* subject);

	// Register observers with relevant subject
	static void RegisterObserver(std::string msg, Observer* observer);

	// Unregister observers from relevant subject
	static void UnregisterObserver(std::string msg, Observer* observer);

	// Unregister all observers from subject
	static void UnregisterAllFromSubject(ObserverSubject* subject);

private:

	static SubjectMap m_subjects;
};