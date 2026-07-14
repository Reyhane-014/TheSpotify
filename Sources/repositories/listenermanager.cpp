#include "ListenerManager.h"
#include <algorithm>

ListenerManager::ListenerManager() {}

int ListenerManager::storeListener(const Listener& listener)
{
    for (int i = 0; i < (int)listeners.size(); i++) {
        if (listeners[i].getId() == listener.getId()) {
            listeners[i] = listener;
            return listeners[i].getId();
        }
    }
    listeners.push_back(listener);
    return listener.getId();
}

bool ListenerManager::deleteListener(int id)
{
    for (int i = 0; i < (int)listeners.size(); i++) {
        if (listeners[i].getId() == id) {
            listeners.erase(listeners.begin() + i);
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

void ListenerManager::updateLikedSongs(int listenerId, int songId, bool liked)
{
    for (int i = 0; i < (int)listeners.size(); i++) {
        if (listeners[i].getId() == listenerId) {
            if (liked) {
                listeners[i].likeSong(songId);
            } else {
                listeners[i].unlikeSong(songId);
            }
            break;
        }
    }
}

bool ListenerManager::isSongLikedByListener(int listenerId, int songId) const
{
    for (int i = 0; i < (int)listeners.size(); i++) {
        if (listeners[i].getId() == listenerId) {
            return listeners[i].isSongLiked(songId);
        }
    }
    return false;
}