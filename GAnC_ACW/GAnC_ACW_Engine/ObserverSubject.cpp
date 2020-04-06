#include "ObserverSubject.h"

ObserverSubject::ObserverSubject()
{

}

ObserverSubject::~ObserverSubject()
{

}

void ObserverSubject::AddObserver(std::string msg, Observer* observer)
{
	// Create container for return value of insert
	std::pair<MessageListenerMapIterator, bool> check;

	// Attempt to insert a new pairing of msg and a new vector
	check = subscribedObservers.insert
	(
		std::pair <std::string, std::vector<Observer*>>
		(
			msg,
			std::vector<Observer*>()
			)
	);

	// Key already exists
	if (!check.second)
	{
		// Get the vector from the iterator
		std::vector<Observer*>& temp = check.first->second;

		// Drop observer into vector
		temp.emplace_back(observer);
	}
	// No key exists
	else
	{
		// Create a new pair, with the desired message and an empty vector of type Observer*
		check = subscribedObservers.emplace(std::pair<std::string, std::vector<Observer*>>(msg, std::vector<Observer*>()));

		// Create a temporary accessible reference to the vector
		std::vector<Observer*>& temp = check.first->second;

		// Drop observer into vector
		temp.emplace_back(observer);
	}
}

void ObserverSubject::RemoveObserver(std::string msg, Observer* observer)
{
	MessageListenerMapIterator subsIt = subscribedObservers.find(msg);

	if (subsIt != subscribedObservers.end())
	{
		std::vector<Observer*>& temp = subsIt->second;
		for (ObserverListIterator obsIt = temp.begin(); obsIt != temp.end(); obsIt++)
		{
			if (*obsIt == observer)
			{
				temp.erase(obsIt);
			}
		}
	}
}