// provided. do not modify. do not submit.
#pragma once

#include <stdexcept>
#include <string>
#include <map>

enum City {
    HQ,
    Boston,
    Hartford,
    New_York,
    Philadelphia,
    Baltimore,
    Washington_DC,
    Pittsburgh,
    Cleveland,
    Detroit,
    Chicago,
    Indianapolis,
    Nashville,
    Atlanta,
    Houston,
    Austin,
    Dallas,
    Denver,
    Albuquerque,
    Phoenix,
    Sacramento,
    Unknown
};

/**
 * Get the string name of a City
 *
 * @param city enum City to name
 * @returns name of the City or "???" if city is unknown
 */
std::string CityToString(City city) {
    static const std::map<City, std::string> cityMap = {
        {HQ, "HQ"},
        {Boston, "Boston"},
        {Hartford, "Hartford"},
        {New_York, "New York"},
        {Philadelphia, "Philadelphia"},
        {Baltimore, "Baltimore"},
        {Washington_DC, "Washington, DC"},
        {Pittsburgh, "Pittsburgh"},
        {Cleveland, "Cleveland"},
        {Detroit, "Detroit"},
        {Chicago, "Chicago"},
        {Indianapolis, "Indianapolis"},
        {Nashville, "Nashville"},
        {Atlanta, "Atlanta"},
        {Houston, "Houston"},
        {Austin, "Austin"},
        {Dallas, "Dallas"},
        {Denver, "Denver"},
        {Albuquerque, "Albuquerque"},
        {Phoenix, "Phoenix"},
        {Sacramento, "Sacramento"},
    };
    auto it = cityMap.find(city);
    return (it != cityMap.end()) ? it->second : "???";
}

/**
 * Get enum City by string name of city
 *
 * @param name the name of the city
 * @returns enum City corresponding to string name
 *          or City::Unknown if name is unknown
 */
City StringToCity(const std::string& name) {
    static const std::map<std::string, City> cityMap = {
        {"HQ", HQ},
        {"Boston", Boston},
        {"Hartford", Hartford},
        {"New York", New_York},
        {"Philadelphia", Philadelphia},
        {"Baltimore", Baltimore},
        {"Washington, DC", Washington_DC},
        {"Pittsburgh", Pittsburgh},
        {"Cleveland", Cleveland},
        {"Detroit", Detroit},
        {"Chicago", Chicago},
        {"Indianapolis", Indianapolis},
        {"Nashville", Nashville},
        {"Atlanta", Atlanta},
        {"Houston", Houston},
        {"Austin", Austin},
        {"Dallas", Dallas},
        {"Denver", Denver},
        {"Albuquerque", Albuquerque},
        {"Phoenix", Phoenix},
        {"Sacramento", Sacramento}
    };
    auto it = cityMap.find(name);
    return (it != cityMap.end()) ? it->second : Unknown;
}
