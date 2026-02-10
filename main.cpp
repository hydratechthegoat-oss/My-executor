#include <stdint.h>
#include "offsets.hpp"

// This function runs the moment Roblox opens
void __attribute__((constructor)) initialize() {
    // 1. Get the address of where Roblox is loaded in RAM
    uintptr_t base = (uintptr_t)&initialize; 
    
    // 2. Find the "Game Manager" (ScriptContext)
    // We use your offset 0x3f0 from the DataModel namespace
    uintptr_t script_context = *(uintptr_t*)(base + Offsets::DataModel::ScriptContext);

    // 3. For now, let's do a simple "Tweak" to prove it works
    // Finding the LocalPlayer and setting Walkspeed to 100
    uintptr_t local_player = *(uintptr_t*)(base + Offsets::Player::LocalPlayer);
    uintptr_t character = *(uintptr_t*)(local_player + Offsets::Player::ModelInstance);
    uintptr_t humanoid = 0; // You'd need a function to find 'Humanoid' in the character
    
    // If you have the humanoid, you'd write:
    // *(float*)(humanoid + Offsets::Humanoid::Walkspeed) = 100.0f;
}
