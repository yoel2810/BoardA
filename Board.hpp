#pragma once
#include <iostream>
#include <string>
#include "Direction.hpp"

using ariel::Direction;

namespace ariel
{
    class Board
    {
        private:
            unsigned int rows;
            unsigned int cols;
            char** mat; // the board
        
        public:
            unsigned int getRows() { return rows; }
            unsigned int getCols() { return cols; }
            
            Board(unsigned int r = 500, unsigned int c = 500)
            {

            }

            void post (unsigned int r, unsigned int c, Direction direction, std::string po)
            {

            }

            std::string read (unsigned int r, unsigned int c, Direction direction, unsigned int length)
            {
                return "chipopo";
            }

            void show ()
            {

            }
    };
};