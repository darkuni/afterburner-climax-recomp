# After Burner Climax Recompiled (private)

Static recompilation of **After Burner Climax** (Xbox 360 XBLA, SEGA AM2, 2010; Title ID 58410A06, default.xex 1.0.0.0 built 2009-12-21) to native Windows, using the [ReXGlue SDK](https://github.com/rexglue/rexglue-sdk) v0.9.0.

**Private repo.** `generated/` is the game's own PowerPC code machine-translated to C++. No game data is committed - you supply your own dump.

## Getting a build
GitHub Actions builds on every push to `main` (or run **Build Windows** by hand from the Actions tab). Download the artifact from the run, unzip it, and put your extracted game files in an `assets` folder next to the exe:

```
after_burner_climax.exe
*.dll
assets\
  default.xex
  media\...
```

## In-game settings (F1 or Esc)
Same menu as the Poker Smash / ReBirth recomps: display mode (also F11), window size, render resolution, VSync, aspect ratio, texture filtering, keyboard on/off, per-button key rebinding, quit. Saved to `after_burner_climax.toml` next to the exe. F3 = performance overlay. Runs as the full game.

### Default keyboard layout
| Action | Controller | Key |
|---|---|---|
| Fly (flick left/right = barrel roll) | Left stick | Arrow keys |
| Machine gun | A | Z |
| Missiles | B | X |
| Climax mode | LB / RB | C / V |
| Brake / accelerate | LT / RT | A / S |
| X / Y | X / Y | Q / W |
| Start / Back | Start / Back | Enter / Backspace |

## Layout
| Path | What |
|---|---|
| `after_burner_climax_manifest.toml` | ReXGlue project manifest (codegen input) |
| `after_burner_climax_overrides.toml` | Missed branch targets + pointer-only functions |
| `generated/` | Recompiled C++ output of `rexglue codegen` |
| `src/after_burner_climax_app.h` | App class - game folder default, Xenos GPU plugin, full-game license, first-launch defaults, menu/F11 binds |
| `src/game_menu.*`, `src/game_keys.h` | F1/Esc settings menu and this game's key layout |
| `tools/` | Package/XEX extraction (STFS, XEX2 basic + LZX), pointer-function scan, label check |
| `.github/workflows/build-windows.yml` | CI: LLVM + SDK (cached) + game, uploads exe + DLLs |

## Codegen fixes so far
- `0x824A7C68`, `0x824D9DD8`, `0x82441BA8`, `0x824D92B0`: small thunks reached only by `b` from other functions.
- 58 functions reachable only through vtables/callbacks (`tools/scan_pointer_funcs.py`).

Not affiliated with or endorsed by SEGA or Microsoft.
