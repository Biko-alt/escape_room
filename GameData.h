#ifndef GAMEDATA_H
#define GAMEDATA_H

#include <string>
#include <vector>
#include <map>

struct GameObject {
    std::string id;
    std::string label;
    std::string text;
    std::string requiresItem;
    std::string lockedText;
    std::string grantsItem;
};

struct Puzzle {
    std::string prompt;
    std::string answer;
    std::string hint;
    std::string successMessage;
};

struct Room {
    std::string id;
    std::string title;
    std::string description;
    std::vector<GameObject> objects;
    Puzzle puzzle;
    std::string nextRoom;
};

std::map<std::string, Room> loadRooms();

#endif