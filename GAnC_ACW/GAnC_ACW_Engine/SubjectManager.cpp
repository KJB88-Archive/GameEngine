#include "SubjectManager.h"
#include "Logger.h"

#include "ObserverSubject.h"

typedef std::pair<SubjectMap::iterator, bool> ResultPair;

SubjectManager::SubjectManager()
	: Manager("Subject")
{

}

SubjectManager::~SubjectManager()
{

}

// Register subject with relevant messages
void SubjectManager::RegisterSubject(std::string msg, ObserverSubject* subject)
{
	// Attempt to insert msg and subject into map
	ResultPair check
		= m_subjects.insert
		(
			std::pair<std::string, ObserverSubject*>
			(
				msg,
				subject
			)
		);

	// Check to see if insertion was succesful
	if (check.second)
	{
		Logger::LogToConsole("SUBJECT MANAGER: Subject added to SubjectManager.");
	}
	else
	{
		Logger::LogToConsole("SUBJECT MANAGER: Failed to add subject to SubjectManager. Msg already exists.");
	}
}

// Register observers with relevant subject
void SubjectManager::RegisterObserver(std::string msg, Observer* observer)
{
	SubjectIterator it;

	it = m_subjects.find(msg);

	it->second->AddObserver(msg, observer);
}

// Unregister observers from relevant subject
void SubjectManager::UnregisterObserver(std::string msg, Observer* observer)
{
	SubjectIterator it;

	it = m_subjects.find(msg);

	it->second->RemoveObserver(msg, observer);
}

// Unregister all observers from subject
void SubjectManager::UnregisterAllFromSubject(ObserverSubject* subject)
{
	for (SubjectIterator it = m_subjects.begin(); it != m_subjects.end(); it++)
	{
		if (it->second == subject)
		{
			m_subjects.erase(it);
		}
	}
}
