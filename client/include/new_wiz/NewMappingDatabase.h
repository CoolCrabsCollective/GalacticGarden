//
// Created by william on 09/01/23.
//

#ifndef LD52_CLIENT_NEWMAPPINGDATABASE_H
#define LD52_CLIENT_NEWMAPPINGDATABASE_H

#include <string>
#include <map>
#include "WIZ/input/Mapping.h"


class NewMappingDatabase {
    std::map<std::string, wiz::Mapping> map;
//    static NewMappingDatabase instance;
public:
    void loadFromCSVFile(const std::string& csvDbFile);

    void loadFromCSV(const std::string& csvDbContent);

    void addMapping(const std::string& vendorId, const std::string& productId, wiz::Mapping mapping);

    void clearMappings();

    const wiz::Mapping& getMapping(const std::string& controllerName) const;

    bool hasMapping(const std::string& vendorId, const std::string& productId) const;

    static const NewMappingDatabase& getInstance();
};

#endif //LD52_CLIENT_NEWMAPPINGDATABASE_H
