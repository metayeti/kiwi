# kiwi <img align="left" src="dev/logo_medium.png?raw=true" height="96">

Kit for Interactive World Integration | v0.0.3 dev

---

( 🚧 -- UNDER CONSTRUCTION -- 🚧 )

This project is a work in progress and is not currently in any type of functional or useful state. Please grab a time machine and check back in at a later time.

---

## About

This is a free and open source, cross-platform, general-purpose 2D map editor intended for 2D game development. Its main features are:

- Fast and lightweight, with as little cruft as humanly possible.
- Scales well. Your enormous maps are safe here.
- Comes with a custom binary map format. Also offers a JSON-formatted export.
- Map importers for C++ and JavaScript.
- Designed for portability - kiwi consists of one single executable which you can drop into any project. When first launched, it creates a local configuration ini file - and that's your entire editing environment right there. The idea is that you can keep the level editor and its local configuration with a grand total of 2 files and that the editor exists preconfigured for your particular development environment within your game project. This way you don't ever have to deal with any cross-project annoyances; kiwi has no installer, the executable is all you need.
- This program offers *some* advanced features. This project does not intend to compete or catch up with other map editors. Basically, I built this tool specifically for my own very specific needs, and these may or may not align with yours. The aim of this project is to provide a minimalistic yet powerful featureset built around an intuitive map creation workflow.

## Screenshots

kiwi running on Windows 10:

![screenshot](/dev/screenshot.png?raw=true)

## Installation

kiwi is a portable program. See [releases](releases/) for binary distributions for Windows. For non-Windows systems you will have to build the program manually (it's not that hard - see [building instructions](BUILDING.md)).

## Help

See the [kiwi User Manual](manual/) for help.

## Contribution

This project is **not** currently open for contributions. Please note that unless the PR is of exceptional quality or resolves some type of critical bug, it will most likely be turned down - be forewarned before you attempt to contribute and potentially waste energy needlessly. If you absolutely require additional features and cannot possibly live without them, then please consider forking this project instead. (If you do happen to find a critical bug and have fixed it, then please do by all means issue a PR; dealing with feature requests and implementation PRs on the other hand is simply too much work for me to keep up with and I'd rather keep this project as a pet project than dedicate much time to it. This project is free to do what you wish with, as long as you adhere to the terms of the GPL3 license. This repository is the main version for this project, which I personally use for my own development purposes - you can of course go wild in your own versions.)

tldr; This project is open source, but not open for contributions (unless you fix something of critical nature).

## Thanks

- [wxWidgets](https://www.wxwidgets.org/) - GUI library

# License

Copyright &copy; 2024 Danijel Durakovic

This project is licensed under the terms of the [GPLv3 license](LICENSE).
