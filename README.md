# **Conway's Game of Life**

Conway's Game of Life is a cellular automaton devised by mathematician John Conway. It simulates the evolution of a grid of cells based on a set of simple rules, where each cell can either be alive or dead. The program evolves the grid in discrete time steps, following these rules to create fascinating patterns and dynamics.
This project implements Conway's Game of Life using C++ and Raylib for graphics rendering. The program allows users to interact with the grid and observe how it evolves over time.

![image](https://github.com/user-attachments/assets/aadbba61-7c89-4668-9b8c-31c423e74729)

---

## **Features**

* **Interactive Grid**
  Users can toggle cell states by clicking on the grid.

* **Dynamic Simulation**
   Run and pause the simulation using keyboard inputs.

* **Random Initialization**
   Populate the grid with random cell states.

* **Clear Grid**
   Reset the grid to an empty state.

* **Adjustable Grid Size**
  The grid dynamically adjusts based on the provided window dimensions and cell size.

* **Seamless Wrapping**
  The grid wraps around at the edges, ensuring cells interact across boundaries.

---

## **Controls**

* **Enter**
  Start the simulation.

* **Space**
  Pause the simulation.

* **Key_C**
  Clear the grid.

* **Key_R**
   Randomly populate the grid.

* **Escape**
  Exit the program.

* **Mouse Left Click**
  Activate a cell at the cursor position.

---
## **Code Highlights**

### **Grid Class** 
Encapsulates all grid operations, including cell state management, neighbor counting, and game logic.

### **Game Logic**

* 1. A live cell with fewer than 2 or more than 3 neighbors dies (underpopulation/overpopulation).
* 2. A dead cell with exactly 3 neighbors becomes alive (reproduction).

### **Rendering**:

Cells are rendered using Raylib's DrawRectangle function, with distinct colors for live and dead cells.
The grid dynamically adjusts based on window dimensions and cell size.

---

## **Setup Instructions**


* **For Visual Studio**
Follow the official vcpkg installation guide: https://github.com/microsoft/vcpkg

Once extracted. Open it in terminal.

Enter _./bootstrap-vcpkg.bat_

This would download vcpkg executable which would be used to install, update and remove c++ libraries.

Run _./vcpkg integrate install_

This would integrate the package manager with our Visual Studio Installation.

Now,

./vcpkg install raylib:x64-windows

This would install raylib and would be ready to use.

---
  
## **Customization**

* Adjust Grid Size: Modify the CELL_SIZE, window_width, and window_height constants to change the grid's dimensions.
* Frame Rate: Modify the fps variable to control the simulation speed.




