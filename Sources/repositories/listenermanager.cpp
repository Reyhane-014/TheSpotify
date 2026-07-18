#include "listenermanager.h"
#include "datamanager.h"
#include <algorithm>

ListenerManager::ListenerManager()
{
    loadFromFile();
}

void ListenerManager::reload()
{
    loadFromFile();
}

void ListenerManager::loadFromFile()
{
    DataManager* dm = DataManager::getInstance();
    listeners = dm->loadListeners();
}

void ListenerManager::saveToFile()
{
    DataManager* dm = DataManager::getInstance();
    dm->saveListeners(listeners);
}

int ListenerManager::storeListener(const Listener& listener)
{
    for (int i = 0; i < (int)listeners.size(); i++) {
        if (listeners[i].getId() == listener.getId()) {
            listeners[i] = listener;
            saveToFile();
            return listeners[i].getId();
        }
    }
    listeners.push_back(listener);
    saveToFile();
    return listener.getId();
}

bool ListenerManager::deleteListener(int id)
{
    for (int i = 0; i < (int)listeners.size(); i++) {
        if (listeners[i].getId() == id) {
            listeners.erase(listeners.begin() + i);
            saveToFile();
            return true;
        }
    }
    return false;
}

std::optional<Listener> ListenerManager::fetchListener(int id) const
{
    for (int i = 0; i < (int)listeners.size(); i++) {
        if (listeners[i].getId() == id) {
            return listeners[i];
        }
    }
    return std::nullopt;
}

std::optional<Listener> ListenerManager::fetchListenerByUsername(const std::string& username) const
{
    for (int i = 0; i < (int)listeners.size(); i++) {
        if (listeners[i].getUsername() == username) {
            return listeners[i];
        }
    }
    return std::nullopt;
}

std::vector<Listener> ListenerManager::getAllListeners() const
{
    return listeners;
}