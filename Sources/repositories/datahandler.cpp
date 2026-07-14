#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <vector>
#include <optional>

class DataHandler
{
public:
    virtual ~DataHandler() = default;

    virtual bool addItem(int id) = 0;
    virtual bool removeItem(int id) = 0;
    virtual bool exists(int id) const = 0;
    virtual int getCount() const = 0;
};

#endif