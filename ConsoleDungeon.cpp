#include <ConsoleDungeon.h>

int main()
{
    isGameOver = false;
    hasKey = false;
    player = " O ";
    key = " K ";
    door = " / ";
    size = 10;
    doorPos = {size-1, 5};
    std::cout << "CONSOLE DUNGEON\n";
    StartNewGame();
    system("pause");
}

void StartNewGame()
{
    while (!isGameOver)
    {
        DrawBoard();
        GetKeyPress();
        CheckPosition();
    }
}

void DrawBoard()
{
    system("CLS");
    std::cout << std::endl;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {

            // Draw the player
            if (x == playerPos[0] && y == playerPos[1]) {
                std::cout << player;
            }
            // Draw the key
            else if (x == keyPos[0] && y == keyPos[1]) {
                std::cout << key;
            }
            // Draw the door
            else if (x == doorPos[0] && y == doorPos[1]) {
                std::cout << door;
            }

            // Draw the left and right walls
            else if (x == 0) {
                std::cout << " | ";
            }
            else if (x == size - 1) {
                std::cout << " | ";
            }
            // Draw the top and bottom walls
            else if (y == 0) {
                std::cout << "---";
            }
            else if (y == size - 1) {
                std::cout << "---";
            }
            // Draw the floor
            else {
                std::cout << " . ";
            }

            // Break line for the edge of the room
            if (x == size - 1) {
                std::cout << "\n";
            }
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    if (hasKey) {
        std::cout << "You have found the key!" << std::endl;
    }
}

void GetKeyPress()
{
    char keyPress = _getch();
    if (keyPress == 'w' && playerPos[1] > 1)
    {
        --playerPos[1];
    }
    else if (keyPress == 's' && playerPos[1] < (size - 2))
    {
        ++playerPos[1];
    }
    else if (keyPress == 'd' && playerPos[0] < (size - 2))
    {
        ++playerPos[0];
    }
    else if (keyPress == 'a' && playerPos[0] > 1)
    {
        --playerPos[0];
    }
}

void CheckPosition()
{
    if (playerPos == keyPos)
    {
        hasKey = true;
        key = " . ";
    }
}
