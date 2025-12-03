# 🚗 Console Car Dodging Game (C - Windows Console)

### **Submitted By:** Mohul Sharma  

---

## 📌 **Overview**
This project is a console-based car dodging game written in **C** for Windows.  
Originally, the game only allowed **left/right movement** with the objective of **avoiding falling obstacles (letters)**.  

In this enhanced and final submitted version, several advanced features have been implemented to improve gameplay, engagement, and functionality.

---

## ✨ **New Features Added**
| Feature | Description |
|--------|-------------|
| **Background Music** | Continuous looping music during gameplay using `PlaySound()` |
| **Sound Effects** | Movement sound, scoring sound, and collision sound via `Beep()` |
| **Random Obstacle Generation** | Each obstacle spawns randomly in any of the 3 lanes |
| **High Score System** | Score is saved in `highscore.txt` and auto-loaded on next play |
| **Collision Detection** | Detects when the player hits an obstacle and ends the game |
| **Score Display** | Real-time score and high score update |
| **Smooth Controls** | Non-blocking key detection using `GetAsyncKeyState()` |
| **Screen Refresh Animation** | Clean redraw using `system("cls")` for smooth display |

---

## 🕹 **How to Play**
- Use **Left Arrow** `←` to move left  
- Use **Right Arrow** `→` to move right  
- Avoid hitting the falling `X` obstacle  
- Score increases every time an obstacle is dodged  
- Game ends when the obstacle hits your position  
- Try to beat the **High Score**!

---

## 📂 **Files Included**
| File | Purpose |
|------|--------|
| `main.c` | Game source code |
| `background.wav` | Music file for game audio |
| `highscore.txt` | Stores persistent high score |

---

## 🏗 **Requirements**
- Windows OS
- MinGW / GCC Compiler
- `winmm.lib` linked for audio playback

Compile using:
```bash
gcc main.c -o game -lwinmm
