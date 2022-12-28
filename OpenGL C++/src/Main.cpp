#include "TestGame.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {
	TestGame game(SCREEN_WIDTH, SCREEN_HEIGHT, "Test");
	game.Run();
}