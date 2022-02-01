# Pacman-OOP game

There is a simple C++ QT5 game (simple analog of Pacman) I've made during course in the school to demonstrate my ability to apply OOP to my code.

## Installation

There is a ready-to-launch build for windows - download this [google drive directory](https://drive.google.com/drive/folders/1VihOThE1IVG8TDIthqMBr1N9mWYLsqGA?usp=sharing) and run .exe file

If you have Linux or MacOS you have to install QT5 on your machine, clone this repository and build project yourself.

## Rules

After program starts you have to press 4 keys of character controls (up, left, bottom, right). Then use these keys to move your character.

Your goal i to reach cell with the finish flag but monsters will try to prevent you from reaching it.

Most cells on the field are water, fire, air and ground - they decrease power of your character when you step on them.

There are also two types of special cells (they are animated):

- blue portals which will teleport you into another portal cell.
- green cells that invert your controls - step again to make your controls back normal.

Be careful and good luck!
