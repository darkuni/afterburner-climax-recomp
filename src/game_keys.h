// After Burner Climax keyboard layout (used by game_menu.cpp).
// Controls: stick = fly (quick left/right flick = barrel roll), A = machine
// gun, B = missiles, LB/RB = Climax mode, LT = brake, RT = accelerate.
#pragma once

namespace recomp_ui::game_keys {

struct KeyBind {
  const char* cvar;
  const char* label;
  const char* default_key;
};

inline const KeyBind kKeyBinds[] = {
    {"keybind_lstick_up", "Fly up (stick)", "Up"},
    {"keybind_lstick_down", "Fly down (stick)", "Down"},
    {"keybind_lstick_left", "Fly left (stick)", "Left"},
    {"keybind_lstick_right", "Fly right (stick)", "Right"},
    {"keybind_a", "Machine gun (A)", "Z"},
    {"keybind_b", "Missiles (B)", "X"},
    {"keybind_left_shoulder", "Climax mode (LB)", "C"},
    {"keybind_right_shoulder", "Climax mode (RB)", "V"},
    {"keybind_left_trigger", "Brake (LT)", "A"},
    {"keybind_right_trigger", "Accelerate (RT)", "S"},
    {"keybind_x", "X button", "Q"},
    {"keybind_y", "Y button", "W"},
    {"keybind_dpad_up", "D-pad up", "Up"},
    {"keybind_dpad_down", "D-pad down", "Down"},
    {"keybind_dpad_left", "D-pad left", "Left"},
    {"keybind_dpad_right", "D-pad right", "Right"},
    {"keybind_start", "Start / pause", "Return"},
    {"keybind_back", "Back", "Backspace"},
};

inline const char* const kUnbound[] = {"keybind_lstick_press", "keybind_rstick_press",
                                       "keybind_guide"};

}  // namespace recomp_ui::game_keys
