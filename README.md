# LightsControllerApp

LEDs controlling app that uses game state integration features for games.
Communicates through SerialPort with homemade led controller (Arduino with custom board).

## Supported games:
- Counter-Strike: Global Offensive [Game State Integration](https://developer.valvesoftware.com/wiki/Counter-Strike:_Global_Offensive_Game_State_Integration)
- more to be added

## How to add games and events

- Create a game handler (must inherit form `GameHandler` class)
- Create event handlers (must inherit form `EventHandler` class)

## Future plans

- I plan to rework event checking system to be more easily extendable
- I need to make some changes to threading. It looks like it's unstable sometimes

## Dependencies
- [POCO C++ Libraries](https://pocoproject.org/)
- [SerialPort by manashmandal](https://github.com/manashmandal/SerialPort)
