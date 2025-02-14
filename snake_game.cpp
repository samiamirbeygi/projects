#include <iostream>
#include <vector>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;

struct Point {
    int x, y;
};

const int width = 20, height = 20;
bool gameOver;
int score;
Point fruit;
vector<Point> snake;
char direction;

void setup() {
    gameOver = false;
    score = 0;
    snake.clear();
    snake.push_back({width / 2, height / 2}); // Initial snake position
    fruit.x = rand() % (width - 2) + 1;
    fruit.y = rand() % (height - 2) + 1;
    direction = 'd'; // Default direction (right)
}

void draw() {
    system("cls");
    for (int i = 0; i < width; i++) cout << "*";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) cout << "*";
            else {
                bool isSnake = false;
                for (const auto &segment : snake) {
                    if (segment.x == j && segment.y == i) {
                        cout << "o";
                        isSnake = true;
                        break;
                    }
                }
                if (!isSnake) {
                    if (j == fruit.x && i == fruit.y) cout << "@";
                    else cout << " ";
                }
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width; i++) cout << "*";
    cout << "\nScore: " << score << endl;
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        if ((key == 'w' && direction != 's') ||
            (key == 's' && direction != 'w') ||
            (key == 'a' && direction != 'd') ||
            (key == 'd' && direction != 'a')) {
            direction = key;
        }
    }
}

void logic() {
    Point newHead = snake[0];
    if (direction == 'w') newHead.y--;
    if (direction == 's') newHead.y++;
    if (direction == 'a') newHead.x--;
    if (direction == 'd') newHead.x++;

    // Check wall collision
    if (newHead.x <= 0 || newHead.x >= width - 1 || newHead.y < 0 || newHead.y >= height) {
        gameOver = true;
        return;
    }

    // Check self collision
    for (size_t i = 1; i < snake.size(); i++) {
        if (snake[i].x == newHead.x && snake[i].y == newHead.y) {
            gameOver = true;
            return;
        }
    }

    // Move snake
    snake.insert(snake.begin(), newHead);
    if (newHead.x == fruit.x && newHead.y == fruit.y) {
        score += 10;
        fruit.x = rand() % (width - 2) + 1;
        fruit.y = rand() % (height - 2) + 1;
    } else {
        snake.pop_back(); // Remove last segment if no fruit was eaten
    }
}

int main() {
    srand(time(NULL));
    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        this_thread::sleep_for(chrono::milliseconds(150)); // Control game speed
    }
    cout << "Game Over! Final Score: " << score << endl;
    return 0;
}