#include <cstring>
#include <vector>
#include <string>

typedef struct {
    int x;
    int y;
} Point;

const int directions[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

bool walk(const std::vector<std::string> maze, char wall, bool** seen, 
        std::vector<Point> path, const Point& cur, const Point& end) {

    // 1. Base Case (off the map)
    // NOTE: length of maze[0] checks the width of the maze
    if (cur.x < 0 || cur.x >= maze[0].length()) { return 0; }
    if (cur.y < 0 || cur.y >= maze.size()) { return 0; }

    // 2. Base Case (on a wall)
    if (maze[cur.y][cur.y] == wall) { return 0; }

    // 3. Base Case (we reached the end)
    if (cur.x == end.x && cur.y == end.y) { 
        path.push_back(end);
        return 1; 
    }

    // 4. Base Case (have we been to here already?)
    if (seen[cur.y][cur.x]) { return 0; }

    // Recursion
    // NOTE: push to path, if position is invalid (check base cases) then pop it out
    path.push_back(cur);
    seen[cur.x][cur.y] = true;

    // checking all cardinal directions
    for (int i = 0; i < 4; i++) {
        int x = directions[i][0];
        int y = directions[i][1];

        Point newCur = {.x = cur.x + x, .y = cur.y + y};
        if (walk(maze, wall, seen, path, newCur, end)) {
            // we only exit the function if we reached the end
            return true;
        }
    }

    // if no direction possible, revert to old position
    path.pop_back();

    return false;
}

std::vector<Point> maze_solver(const std::vector<std::string> maze, char wall, 
        const Point& start, const Point& end) {

    bool** seen = new bool*[maze.size()];
    for (int i = 0; i < maze.size(); ++i) {
        bool* seen_row = new bool[maze[0].length()];
        memset(seen_row, 0, maze[0].length());
        seen[i] = seen_row;
    }

    std::vector<Point> path = {};

    walk(maze, wall, seen, path, start, end);
    return path;

}
