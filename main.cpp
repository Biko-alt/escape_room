#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <limits>
#include "GameData.h"

std::string normalizeInput(const std::string& input) {
    size_t start = input.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    size_t end = input.find_last_not_of(" \t\r\n");
    std::string trimmed = input.substr(start, end - start + 1);

    std::transform(trimmed.begin(), trimmed.end(), trimmed.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return trimmed;
}

bool hasItem(const std::vector<std::string>& inventory, const std::string& item) {
    return std::find(inventory.begin(), inventory.end(), item) != inventory.end();
}

void printDivider() {
    std::cout << "\n============================================================\n";
}

int main() {
    std::map<std::string, Room> rooms = loadRooms();
    std::string currentRoomId = "server_room";
    std::vector<std::string> inventory;
    std::string lastMessage = "You wake up inside a locked facility. Inspect your surroundings to find a way out.";
    int moves = 0;
    int hintsUsed = 0;
    bool escaped = false;

    while (true) {
        printDivider();
        std::cout << " PROTOCOL ZERO | Moves: " << moves << " | Hints Used: " << hintsUsed << "\n";
        printDivider();

        if (escaped) {
            std::cout << "\n[SYSTEM MESSAGE]: " << lastMessage << "\n\n";
            std::cout << "*** SYSTEM BREACHED — YOU ESCAPED! ***\n";
            std::cout << "You bypassed all three security layers in " << moves
                      << " moves using " << hintsUsed << " hints.\n\n";
            std::cout << "1. Play Again\n";
            std::cout << "2. Quit\n";
            std::cout << "\nSelect an option: ";

            int choice;
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (choice == 1) {
                currentRoomId = "server_room";
                inventory.clear();
                lastMessage = "Simulation restarted. Inspect your surroundings to find a way out.";
                moves = 0;
                hintsUsed = 0;
                escaped = false;
                continue;
            } else if (choice == 2) {
                std::cout << "Exiting Protocol Zero. Goodbye!\n";
                break;
            }
            continue;
        }

        Room& room = rooms[currentRoomId];

        std::cout << "\n" << room.title << "\n";
        std::cout << room.description << "\n\n";

        std::cout << "Inventory: ";
        if (inventory.empty()) {
            std::cout << "[Empty]";
        } else {
            for (size_t i = 0; i < inventory.size(); ++i) {
                std::cout << "[" << inventory[i] << "]" << (i + 1 < inventory.size() ? " " : "");
            }
        }
        std::cout << "\n\n";

        std::cout << "[LOG]: " << lastMessage << "\n\n";

        std::cout << "Actions:\n";
        int optionNum = 1;
        for (const auto& obj : room.objects) {
            std::cout << "  " << optionNum++ << ". " << obj.label << "\n";
        }
        int solveOption = optionNum++;
        int hintOption = optionNum++;
        int restartOption = optionNum++;
        int quitOption = optionNum++;

        std::cout << "  " << solveOption << ". Enter Security Code\n";
        std::cout << "  " << hintOption << ". Request Hint\n";
        std::cout << "  " << restartOption << ". Restart Game\n";
        std::cout << "  " << quitOption << ". Quit\n";

        std::cout << "\nChoose an action (1-" << (optionNum - 1) << "): ";
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            lastMessage = "Invalid input. Please enter a number from the menu.";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice >= 1 && choice <= static_cast<int>(room.objects.size())) {
            const GameObject& obj = room.objects[choice - 1];
            moves++;

            if (!obj.requiresItem.empty() && !hasItem(inventory, obj.requiresItem)) {
                lastMessage = obj.lockedText;
            } else {
                lastMessage = obj.text;
                if (!obj.grantsItem.empty() && !hasItem(inventory, obj.grantsItem)) {
                    inventory.push_back(obj.grantsItem);
                    lastMessage += "  --> [Item Acquired: " + obj.grantsItem + "]";
                }
            }
        } else if (choice == solveOption) {
            std::cout << "\n" << room.puzzle.prompt << " ";
            std::string rawAnswer;
            std::getline(std::cin, rawAnswer);
            std::string answer = normalizeInput(rawAnswer);
            moves++;

            if (answer == normalizeInput(room.puzzle.answer)) {
                lastMessage = room.puzzle.successMessage;
                if (room.nextRoom == "escaped") {
                    escaped = true;
                } else {
                    currentRoomId = room.nextRoom;
                }
            } else {
                lastMessage = "'" + answer + "' did not work. The lock buzzes red.";
            }
        } else if (choice == hintOption) {
            hintsUsed++;
            lastMessage = "[HINT]: " + room.puzzle.hint;
        } else if (choice == restartOption) {
            currentRoomId = "server_room";
            inventory.clear();
            lastMessage = "Game restarted. Inspect your surroundings to find a way out.";
            moves = 0;
            hintsUsed = 0;
        } else if (choice == quitOption) {
            std::cout << "Exiting Protocol Zero. Goodbye!\n";
            break;
        } else {
            lastMessage = "Invalid option. Select a valid number from the list.";
        }
    }

    return 0;
}