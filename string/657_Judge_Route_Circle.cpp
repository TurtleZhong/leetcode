/**
 * Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
 * The move sequence is represented by a string. And each move is represent by a character.
 * The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
 */

#include <iostream>
#include <string>

using namespace std;

bool judgeCircle(string moves)
{
    if(moves.length() == 0)
        return true;
    int sum = 0;
    for (int i = 0; i < moves.length(); ++i)
    {
        if(moves[i]=='L' || moves[i]=='D')
            sum += -1;
        else if(moves[i]=='R' || moves[i]=='U')
            sum += 1;
    }
    return sum==0;
}

int main()
{
    string moves = "LR";
    cout << judgeCircle(moves) << endl;
    return 0;
}