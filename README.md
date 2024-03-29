# kiwi <img align="left" src="dev/logo_medium.png?raw=true" height="96">

Kit for Interactive World Integration | v0.0.2

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
- Designed for portability - kiwi consists of one single executable which you can drop into any project. When first launched, it creates a local configuration ini file. The idea is that you can keep the level editor and its local configuration with a grand total of 2 files. The idea behind this approach is that inside your game project the editor exists preconfigured for your particular development environment and this way you don't ever have to deal with any cross-project annoyances; kiwi has no installer, the executable is all you need.
- This program offers *some* advanced features. This project does not intend to compete or catch up with other editors. The aim of this project is to provide a minimalistic yet powerful featureset built around a transparent and intuitive workflow.

## Installation

kiwi is a portable program. See [releases](releases/) for binary distributions for Windows. For non-Windows systems you will have to build the program manually (see [build instructions](BUILDING.md)).

## Contribution

This project is **not** currently open for contributions. Please note that unless the PR is of exceptional quality or resolves some type of critical bug it will most likely be turned down so be forewarned before you attempt to contribute. If you absolutely need additional features then please consider forking the project.

## Credits

- [wxWidgets](https://www.wxwidgets.org/) - GUI library

# License

Copyright &copy; 2024 Danijel Durakovic

This project is licensed under the terms of the [GPLv3 license](LICENSE).
