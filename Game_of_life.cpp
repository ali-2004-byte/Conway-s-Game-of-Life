#include <iostream>
#include <vector>
#include "raylib.h"
using namespace std;
class grid {
private:
	int rows;
	int columns; 
	int cellsize;
	vector<vector<bool>> grid_2d;
	vector<vector<bool>> temp_grid;
public:
	grid(int r, int c, int size):grid_2d(r, vector<bool>(c, false)),temp_grid(r,vector<bool>(c,false)) {
		rows = r/size;
		columns = c/size;
		cellsize = size;
	}
	void draw() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				Color color = grid_2d[i][j] ? Color{ 0,255,0,255 } : Color{ 25,25,25,255 };
				DrawRectangle(j * cellsize, i * cellsize, cellsize - 1, cellsize - 1, color);
			}
		}
	}
	void set_value(int row, int col, int value) {
		if (row >= 0 && row < rows && col >= 0 && col < columns) {
			grid_2d[row][col] = value;
		}
	}
	void set_temp() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				temp_grid[i][j] = grid_2d[i][j];
			}
		}
	}
	int count_neighbours(int row, int col) {
		vector<int> dr = { -1, -1,-1,0,0,1,1,1 };
		vector<int> dc = { -1, 0,1,-1,1,-1,0,1 };
		int count = 0;
		for (int i = 0; i < 8; i++) {
			int d = (row + dr[i] + rows) % rows;
			int c = (col + dc[i] + columns) % columns;
			
			if (temp_grid[d][c]) {
				count++;
			}
			
		}
		return count;
	}
	void game_play() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				// Checks each cell to see whether it is alive or dead
				if (temp_grid[i][j]) {
					//If alive then it must have 2 or 3 alive neighbours otherwise it is considered dead.
					// Having less than 2 alive neighbours is called Underpopulation.
					// Having more than 3 alive neighbours is call Overpopulation.
					int count = count_neighbours(i, j);
					if (count < 2 || count > 3) {
						set_value(i, j, 0);
					}
				}
				else {
					//If dead then it must have 3 alive neighbours and would be considered alive for the next generation.
					int count = count_neighbours(i, j);
					if (count == 3) {
						set_value(i, j, 1);
					}
				}
			}
		}
		set_temp();
	}
	//Fills up the grid randomly
	void FillRandom() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				int randomval = GetRandomValue(0, 4);
				if (randomval == 4) {
					grid_2d[i][j] = 1;
				}
			}
		}
	}
	void clear() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				grid_2d[i][j] = 0;
				temp_grid[i][j] = 0;
			}
		}
	}
};
int main() {
	const int window_width = 750;
	const int window_height = 950;
	const int CELL_SIZE = 25;
	int fps = 12;
	// Run variable decides whether our simulation is running or not
	bool run = false;
	Color Bleck = { 0, 0, 0,255 };
	Color Yellow = { 255,255,0,255 };
	grid GOL(window_height - 100, window_width, CELL_SIZE);
	GOL.FillRandom();
	GOL.set_temp();
	InitWindow(window_width, window_height, "Conway's Game of Life");
	SetTargetFPS(fps);
	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_ENTER)) {
			//If user presses enter, simulation will start running.
			run = true;
			SetWindowTitle("Running");
		}
		if (IsKeyPressed(KEY_SPACE)) {
			//If user presses spacebar, simulation will stop running.
			run = false;
			SetWindowTitle("Paused");
		}
		if (IsKeyPressed(KEY_C)) {
			//Pressing C would clear the grid.
			GOL.clear();
		}
		if (IsKeyPressed(KEY_R)) {
			//Pressing R would randomly fill the grid.
			GOL.FillRandom();
			GOL.set_temp();
		}
		if (IsKeyPressed(KEY_ESCAPE)) {
			//Press Escape to exit the simulation.
			break;
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			//If mouse left key is pressed then the cell at which the mouse is pointing is rendered alive.
			Vector2 mousepos= GetMousePosition();
			int x = mousepos.x / CELL_SIZE;
			int y = mousepos.y / CELL_SIZE;
			GOL.set_value(y, x, 1);
			GOL.set_temp();
		}
		BeginDrawing();
		ClearBackground(Bleck);
		DrawText("Conway's Game Of Life", 130, window_height - 70, 40, YELLOW);
		GOL.draw();
		if (run) {
			GOL.game_play();
		}
		EndDrawing();
	}

	CloseWindow();
}