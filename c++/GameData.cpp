#include "GameData.h"

std::map<std::string, Room> loadRooms() {
    std::map<std::string, Room> rooms;

    // Stage 1: The Locked Server Room
    rooms["server_room"] = {
        "server_room",
        "Stage 1: The Locked Server Room",
        "Fluorescent lights flicker overhead. A heavy magnetic hatch blocks the exit, controlled by a terminal on the main desk.",
        {
            {
                "sticky_note",
                "Inspect Sticky Note",
                "A yellow note stuck to the monitor reads: 'PIN = Unix Epoch Year + Bits in a Byte.'",
                "",
                "",
                ""
            },
            {
                "toolbox",
                "Search Metal Toolbox",
                "Beneath a tangle of Ethernet cables, you find a small brass key.",
                "",
                "",
                "Brass Key"
            }
        },
        {
            "Enter the 4-digit terminal PIN to unlock the corridor hatch:",
            "1978",
            "Unix time began on January 1, 1970, and there are 8 bits in 1 byte.",
            "Access granted. The magnetic hatch hisses open into a dimly lit cooling corridor."
        },
        "cooling_corridor"
    };

    // Stage 2: The Cryo-Cooling Corridor
    rooms["cooling_corridor"] = {
        "cooling_corridor",
        "Stage 2: The Cryo-Cooling Corridor",
        "Rows of humming server racks line the hallway. At the far end stands a reinforced blast door with a keyword keypad.",
        {
            {
                "locker",
                "Open Steel Locker",
                "The brass key turns smoothly. Inside, you find a UV flashlight.",
                "Brass Key",
                "The locker is bolted shut. It has a small keyhole suited for a brass key.",
                "UV Flashlight"
            },
            {
                "concrete_wall",
                "Examine Concrete Wall",
                "Under the UV flashlight, hidden ink glows brightly on the wall: SHADOW",
                "UV Flashlight",
                "You see faint smudges on the concrete, but it is too dark to make anything out.",
                ""
            }
        },
        {
            "Enter the security override word for the blast door:",
            "SHADOW",
            "Unlock the steel locker using the key from Stage 1, then inspect the wall.",
            "Override accepted. The blast door slides open, revealing the final airlock."
        },
        "exit_airlock"
    };

    // Stage 3: The Exit Airlock
    rooms["exit_airlock"] = {
        "exit_airlock",
        "Stage 3: The Exit Airlock",
        "Fresh air circulates through the vents just beyond the outer door. One final keypad lock bars your escape.",
        {
            {
                "brass_plaque",
                "Read Brass Plaque",
                "Engraved on the wall: 'I speak without a mouth and hear without ears. I have no body, but I come alive with wind. What am I?'",
                "",
                "",
                ""
            },
            {
                "pressure_gauge",
                "Check Pressure Gauge",
                "Airlock pressure is equalized at 100%. Solve the plaque's riddle to trigger the door release.",
                "",
                "",
                ""
            }
        },
        {
            "Enter the 4-letter answer to unlock the exterior exit:",
            "ECHO",
            "Think about what happens when you shout into an empty canyon.",
            "Airlock disengaged! Sunlight floods the corridor as you step outside."
        },
        "escaped"
    };

    return rooms;
}