#ifndef GAME_H
#define GAME_H

struct GLFWwindow;
class Hexagon;

class Game
{
public:
    Game(const char* gameName, unsigned int width, unsigned int height);
    ~Game();

    int Initialise();
    void Render();
    void Update();
    void HandleEvents();

    inline bool IsRunning() const { return isRunning; };

private:
    int InitialiseGLEW();
    int InitialiseGLFW();
    int CreateWindow();

    GLFWwindow* window;
    bool isRunning;

    const char* gameName;
    unsigned int width;
    unsigned int height;

    // Objects
    Hexagon* hexagon;
};

#endif