#include <ConsoleDungeon.h>

int main()
{
    isGameOver = false;
    hasKey = false;
    player = " O ";
    key = " K ";
    door = " / ";
    size = 12;
    doorPos = { size - 2, 5 };
    winPos[0] = doorPos[0] + 1;
    winPos[1] = doorPos[1];
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
            // Draw a space at the left and right edges
            else if (x == 0) {
                std::cout << "   ";
            }
            else if (x == size - 1) {
                std::cout << "   ";
            }
            // Draw the left and right walls
            else if (x == 1 && y != 0 && y != size - 1) {
                std::cout << " | ";
            }
            else if (x == size - 2 && y != 0 && y != size - 1) {
                std::cout << " | ";
            }
            // Draw a space at the top and bottom edges
            else if (y == 0) {
                std::cout << "   ";
            }
            else if (y == size - 1) {
                std::cout << "   ";
            }
            // Draw the top and bottom walls
            else if (y == 1) {
                std::cout << "---";
            }
            else if (y == size - 2) {
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
    if (hasKey) {
        std::cout << "You have found the KEY!" << std::endl;
    }
    std::cout << incidentalMessage << std::endl;
}

void GetKeyPress()
{
    char keyPress = _getch();

    if (keyPress == 'w')
    {
        if (playerPos == doorPos && winPos[1] < playerPos[1])
        {
            if (hasKey) {
                --playerPos[1];
            }
            else {
                return;
            }
        }
        else if (playerPos[0] == doorPos[0] && playerPos[1] == doorPos[1] + 1)
        {
             --playerPos[1];
        }
        else if (playerPos[1] > 2 && playerPos[0] > 1 && playerPos[0] < size -2) {
            --playerPos[1];
        }
    }
    else if (keyPress == 's')
    {
        if (playerPos == doorPos && winPos[1] > playerPos[1])
        {
            if (hasKey) {
                ++playerPos[1];
            }
            else {
                return;
            }
        }
        else if (playerPos[0] == doorPos[0] && playerPos[1] == doorPos[1] - 1)
        {
             ++playerPos[1];
        }
        else if (playerPos[1] < (size - 3) && playerPos[0] > 1 && playerPos[0] < size - 2) {
            ++playerPos[1];
        }
    }
    else if (keyPress == 'd')
    {
        if (playerPos == doorPos && winPos[0] > playerPos[0])
        {
            if (hasKey) {
                ++playerPos[0];
            }
            else {
                return;
            }
        }
        else if (playerPos[0] == doorPos[0] - 1 && playerPos[1] == doorPos[1])
        {
            ++playerPos[0];
        }
        else if (playerPos[0] < (size - 3) && playerPos[1] > 1 && playerPos[1] < size - 2) {
            ++playerPos[0];
        }
    }
    else if (keyPress == 'a')
    {
        if (playerPos == doorPos && winPos[0] < playerPos[0])
        {
            if (hasKey) {
                --playerPos[0];
            }
            else {
                return;
            }
        }
        else if (playerPos[0] == doorPos[0] + 1 && playerPos[1] == doorPos[1])
        {
            --playerPos[0];
        }
        else if (playerPos[0] > 2 && playerPos[1] > 1 && playerPos[1] < size - 2) {
            --playerPos[0];
        }
    }
}

void CheckPosition()
{
    if (playerPos == keyPos)
    {
        hasKey = true;
        key = " . ";
    }
    if (playerPos == doorPos)
    {
        if (!hasKey) {
            incidentalMessage = "You have found a DOOR, but you need a KEY!";
        }
        else {
            incidentalMessage = "You have unlocked the DOOR with the KEY!";
        }
    }
    else
    {
        incidentalMessage = "";
    }
    if (playerPos == winPos) {
        incidentalMessage = "You have escaped the dungeon...\nYOU WIN!";
        DrawBoard();
        isGameOver = true;
    }
}
