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
- Designed for portability - kiwi consists of one single executable which you can drop into any project. When first launched, it creates a local configuration ini file. The idea is that you can keep the level editor and its local configuration with a grand total of 2 files. The idea behind this approach is that inside your game project the editor exists preconfigured for your particular development environment and this way you don't ever have to deal with any cross-project annoyances; kiwi has no installer, the executable is all you need.
- This program offers *some* advanced features. This project does not intend to compete or catch up with other map editors. Basically - I built this tool specifically for my own specific needs - these may or may not align with yours. The aim of this project is to provide a minimalistic, powerful featureset built for an intuitive map creation workflow.

![screenshot](/dev/screenshow.png?raw=true)

## Installation

kiwi is a portable program. See [releases](releases/) for binary distributions for Windows. For non-Windows systems you will have to build the program manually (see [build instructions](BUILDING.md)).

## Contribution

This project is **not** currently open for contributions. Please note that unless the PR is of exceptional quality or resolves some type of critical bug it will very likely be turned down so be forewarned before you attempt to contribute (and waste energy needlessly). If you absolutely require additional features and cannot possibly live without them, then please consider forking this project instead. If you do happen to find a critical bug and have fixed it, then please by do all means issue a PR, but dealing with feature requests and implementation PRs is simply too much work for me to keep up with and I'd rather keep this project a pet project than dedicate too much time to it. This project is free to do what you wish with - as long as you adhere to the GPL3 terms - this repository is simply the main version which I personally use for my own development purposes, but you can go wild in yours if that's your desire.

tldr; This project is open source, but not open for contributions (unless you fix something extremely broken).

## Credits

- [wxWidgets](https://www.wxwidgets.org/) - GUI library

# License

Copyright &copy; 2024 Danijel Durakovic

This project is licensed under the terms of the [GPLv3 license](LICENSE).
