/**
 * Anne Chen
 * CS 11, Spring 2016 Lab 4
 * 
 * This program obtains a triangle game board and takes in a set of 
 * moves as input from the user. If the move is invalid, it returns an 
 * error. If it is valid, it makes changes on the board according to the
 * input received and returns the new board.   
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "triangle_routines.h"

#define NMOVES 36
#define NHOLES 15

int moves[NMOVES][3] =
{
    {0, 1, 3},
    {3, 1, 0},
    {1, 3, 6},
    {6, 3, 1},
    {3, 6, 10},
    {10, 6, 3},
    {2, 4, 7},
    {7, 4, 2},
    {4, 7, 11},
    {11, 7, 4},
    {5, 8, 12},
    {12, 8, 5},
    {0, 2, 5},
    {5, 2, 0},
    {2, 5, 9},
    {9, 5, 2},
    {5, 9, 14},
    {14, 9, 5},
    {1, 4, 8},
    {8, 4, 1},
    {4, 8, 13},
    {13, 8, 4},
    {3, 7, 12},
    {12, 7, 3},
    {3, 4, 5},
    {5, 4, 3},
    {6, 7, 8},
    {8, 7, 6},
    {7, 8, 9},
    {9, 8, 7},
    {10, 11, 12},
    {12, 11, 10},
    {11, 12, 13},
    {13, 12, 11},
    {12, 13, 14},
    {14, 13, 12}
};

/* Return the number of pegs on the board. 
 */

int npegs(int board[])

{
    int i;
    int pegs = 0;

    for (i = 0; i < NHOLES; i++) {
        if (board[i] == 1) {
            pegs++;
        }
    }
    return pegs;
}

/* Return 1 if the move is valid on this board, otherwise return 0. To 
 * confirm that move is valid, the indices in the board, as given by 
 * move, must be filled with a 1, 1, and a 0 in that respective order.
 */

int valid_move(int board[], int move[])

{
 
    if (board[move[0]] == 1 && board[move[1]] == 1 && \
        board[move[2]] == 0) {
        return 1;
    }
    else {
        return 0; 
    }   
}

/* Make this move on this board by changing the board from 1, 1, 0 to 
 * 0, 0, 1 in the given indices. 
 */

void make_move(int board[], int move[])

{
    board[move[0]] = 0;
    board[move[1]] = 0;
    board[move[2]] = 1;
}

/* Unmake this move on this board by changing the values in board from
 * 0, 0, 1 back to 1, 1, 0 in the locations dictated by move. 
 */

void unmake_move(int board[], int move[])

{
    board[move[0]] = 1;
    board[move[1]] = 1;
    board[move[2]] = 0;
}

/* 
 * Solve the game starting from this board.  Return 1 if the game can
 * be solved; otherwise return 0.  Do not permanently alter the board 
 * passed in. Once a solution is found, print the boards making up the 
 * solution in reverse order. 
 */

int solve(int board[])
 
{
    int i = 0;
    int t = 0;
    
    if (npegs(board) == 1) {
        return t = 1;    
    }     
     
    else {
        for (i = 0; i < NMOVES; i++) {
            if (valid_move(board, moves[i]) == 1) { 
                make_move(board, moves[i]);
                t = solve(board);
                if (t == 1) {
                    triangle_print(board);
                    unmake_move(board, moves[i]);
                    break;
                }
                unmake_move(board, moves[i]);
            }
        }    
    }
    return t;
}

/*
 * This function creates a board, calls the triangle_input function on 
 * it and prints the input board with a message. It then solves the 
 * board and returns 0. 
 */

int main(void)

{
    
    int board[NHOLES];
    int t;
    
    triangle_input(board);
    printf("Here is the board you entered:\n");
    triangle_print(board);
    t = solve(board);
    triangle_print(board);
    
    if (t == 0) {
        fprintf(stderr, "There is no solution.\n");
    }
    
    return 0;
}
