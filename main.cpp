#include <iostream>
#include <string>
#include <vector>

// input coordinates
int x,y;


/*!
 * @brief The output of the game field tic-tac-toe.
 * @param field - array with data.
 */
void printField(std::vector<std::string> field)
{
    std::cout
            << "   1 2 3\n"
            << "  +-+-+-+\n";
    for(int i=0; i<3; i++)
    {
        std::cout << (i+1) << " |";
        for(int j=0; j<3; j++)
            std::cout << field[i][j] << '|';
        std::cout << "\n  +-+-+-+\n";
    }
}

/*!
 * @brief Input of coordinates with check for correctness.
 * @param field - playing field data array.
 */
void inputCoord(std::vector<std::string> field)
{
    while( true ) {
        std::cout << "Enter cell coordinates:";
        std::cin >> x >> y;

        // coordinate check
        if ((x >= 1) && (x <= 3) && (y >= 1) && (y <= 3) && (field[x - 1][y - 1] == ' '))
            break;

        // error output
        std::cout << "Wrong entry! Enter again.\n";
    }
}

/*!
 * @brief Calculation of the number of full lines of a certain player.
 * @param l1 - the first line of the field.
 * @param l2 - the second line of the field.
 * @param l3 - the third line of the field.
 * @param ch - player character ('X' or 'O').
 * @return Returns the number of full lines.
 */
int countOfSolutions(std::string l1, std::string l2, std::string l3, char ch)
{
    int count = 0;

    // horizontal line testing
    if( (l1[0] == ch) && (l1[1] == ch) && (l1[2] == ch) ) count++;
    if( (l2[0] == ch) && (l2[1] == ch) && (l2[2] == ch) ) count++;
    if( (l3[0] == ch) && (l3[1] == ch) && (l3[2] == ch) ) count++;
    // vertical line testing
    if( (l1[0] == ch) && (l2[0] == ch) && (l3[0] == ch) ) count++;
    if( (l1[1] == ch) && (l2[1] == ch) && (l3[1] == ch) ) count++;
    if( (l1[2] == ch) && (l2[2] == ch) && (l3[2] == ch) ) count++;
    // diagonal line testing
    if( (l1[0] == ch) && (l2[1] == ch) && (l3[2] == ch) ) count++;
    if( (l1[2] == ch) && (l2[1] == ch) && (l3[0] == ch) ) count++;

    return count;
}

int main() {
    std::vector<std::string> field = {"   ", "   ", "   "};
    int countBroken = 0;

    // displaying the current state of the field
    std::cout << "Current view of the field:" << std::endl;
    printField(field);

    while( true )
    {
        //----------------------------------------------------------------------
        // cross move

        // coordinate input
        std::cout << "\nThe move of the crosses.\n";
        inputCoord(field);

        // field mark
        field[x-1][y-1] = 'X';
        countBroken++;

        // displaying the current state of the field
        std::cout << "Current view of the field:" << std::endl;
        printField(field);

        // revealing victory
        if( countOfSolutions(field[0],field[1],field[2],'X') > 0 )
        {
            std::cout << "The crosses won!\n";
            break;
        }

        // revealing a draw
        if( countBroken == 9 )
        {
            std::cout << "Draw!\n";
            break;
        }

        //----------------------------------------------------------------------
        // zero move

        // coordinate input
        std::cout << "\nZero move.\n";
        inputCoord(field);

        // field mark
        field[x-1][y-1] = 'O';
        countBroken++;

        // displaying the current state of the field
        std::cout << "Current view of the field:" << std::endl;
        printField(field);

        // revealing victory
        if( countOfSolutions(field[0],field[1],field[2],'O') > 0 )
        {
            std::cout << "The zero have won!\n";
            break;
        }

        // revealing a draw
        if( countBroken == 9 )
        {
            std::cout << "Draw!n";
            break;
        }
        //----------------------------------------------------------------------
    }

    return 0;
}
