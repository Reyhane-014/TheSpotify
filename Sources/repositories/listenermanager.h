#ifndef LISTENERMANAGER_H
#define LISTENERMANAGER_H

#include "../entities/listener.h"
#include <vector>
#include <optional>

class ListenerManager
{
private:
    std::vector<Listener> listeners;

public:
    ListenerManager();

    int storeListener(const Listener& listener);
    bool deleteListener(int id);
    std::optional<Listener> fetchListener(int id) const;
    std::optional<Listener> fetchListenerByUsername(const std::string& username) const;
    std::vector<Listener> getAllListeners() const;
    void updateLikedSongs(int listenerId, int songId, bool liked);
    bool isSongLikedByListener(int listenerId, int songId) const;
};

#endif