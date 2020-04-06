#pragma once
#include <map>
#include <string>
#include <vector>

#include "Observer.h"
#include "BaseMessage.h"


typedef std::map<std::string, std::vector<Observer*> > MessageListenerMap;
typedef std::map<std::string, std::vector<Observer*> >::iterator MessageListenerMapIterator;
typedef std::vector<Observer*>::iterator ObserverListIterator;

class ObserverSubject
{
public:

	ObserverSubject();
	virtual ~ObserverSubject();

	virtual void AddObserver(std::string msg, Observer* observer);
	virtual void RemoveObserver(std::string msg, Observer* observer);

protected:
	virtual void NotifyAll(BaseMessage* msg) = 0;

private:

	// Map of observers and the messages they're subscribed to
	MessageListenerMap subscribedObservers;
};

