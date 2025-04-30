# Project PAA 24/25  
### **Turn-Based Strategy Game**  

## Overview  
**Project PAA 24/25** is a **turn-based strategy game** built using **Unreal Engine 5**.  
The game features a **grid-based combat system** where players face an AI opponent that can operate in **two different modes**:  

- **Random AI** → Makes unpredictable moves and attacks randomly.  
- **Strategic AI** → Uses pathfinding (A* algorithm) to optimize movement toward the best attack position.  

The battle begins with a **Coin Flip** that determines which player acts first.  

---

## Gameplay Mechanics  
 **AI Selection** – Choose between **Random AI** or **Strategic AI** before the match starts.  
 **Coin Flip System** – Click **Coin Flip** to determine turn order.  
 **Unit Placement** – Position player units on the battlefield grid.  
 **Turn Execution** – Units move and attack based on their capabilities.  
 **End Turn** – Click **End Turn** once all unit actions are completed.  
 **Win Condition** – The game ends when all enemy units or all player units are eliminated.  

---

## AI Behavior  
### **Random AI**  
✔ Moves unpredictably within its allowed movement range.  
✔ Attacks a **random target** within attack range.  

### **Strategic AI (Pathfinding)**  
✔ Identifies the **nearest player unit** using `FindClosestPlayerUnit()`.  
✔ Uses **pathfinding A*** to calculate the **most efficient movement route**.  
✔ Moves **step-by-step**, avoiding obstacles and optimizing positioning.  

---

## Code Structure  

/Source
├── TurnBasedGameMode.cpp   # Manages game rules, turns, and AI logic.
├── AUnitBase.cpp           # Unit logic (movement, attack, state updates).
├── AGridLine.cpp           # Grid system generation and management.
├── TurnIndicatorWidget.cpp # UI for displaying turn status and player actions.
├── GridPlayerController.cpp # Handles player input and unit selection.
├── UnitInfoWidget.cpp      # Displays unit information in the UI.
├── Obstacle.cpp            # Defines obstacles that restrict movement on the grid.
├── CellActor.cpp           # Represents individual grid cells.

Each component contributes to the **game mechanics**, **AI behavior**, and **user interaction**.

---

## Key Features & Notes  
✔ **Turn-based system** with separate player and AI actions.  
✔ **AI behavior must be selected at the start** —it cannot be changed during the game.  
✔ **Coin Flip system** ensures fair turn order selection.  
✔ **All units have defined movement and attack limits** based on their attributes.  
✔ **Strategic AI moves logically step-by-step**, avoiding direct teleportation across the grid.  

--- 
