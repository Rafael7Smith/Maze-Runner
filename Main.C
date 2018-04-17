/* Rafael Smith, Ra760189 */
/* Homework #2 - 6 */
/* Maze Traversal */

#include <stdio.h>
#include <stdlib.h>


char maze[12][12] = {
  {'#','#','#','#','#','#','#','#','#','#','#','#'},
  {'#','.','.','.','#','.','.','.','.','.','.','#'},
  {'.','.','#','.','#','.','#','#','#','#','.','#'},
  {'#','#','#','.','#','.','.','.','.','#','.','#'},
  {'#','.','.','.','.','#','#','#','.','#','.','.'},
  {'#','#','#','#','.','#','.','#','.','#','.','#'},
  {'#','.','.','#','.','#','.','#','.','#','.','#'},
  {'#','#','.','#','.','#','.','#','.','#','.','#'},
  {'#','.','.','.','.','.','.','.','.','#','.','#'},
  {'#','#','#','#','#','#','.','#','#','#','.','#'},
  {'#','.','.','.','.','.','.','#','.','.','.','#'},
  {'#','#','#','#','#','#','#','#','#','#','#','#'}
};

int main()
{
  printmaze(maze);
  
  /* Starting position */
  maze[2][0]='X';  
  printmaze(maze);
  
  /* Pass the array and the starting position to the traverse function */
  mazeTraverse(maze, 2, 0);
  
return 0;
}

/*For Printing the maze, so we dont have to have several double for loops everywhere */
void printmaze(char lmaze[12][12]) 
{
  int i, j;
  
  for (i=0 ; i < 12; i++){
    for (j=0 ;  j < 12 ; j++){
      printf("%c", lmaze[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
    
}

int mazeTraverse(char lmaze[12][12],int row,int col)
{
  /* Needed for escape ladder */
  int x;
  
  /* Check down for path "." */
  /* Make sure we arent at the edge AND we have a path */
  if((row < 12) && (lmaze[row+1][col] == '.')) {
    /* Place an X where we are and print */
    lmaze[row+1][col] = 'X';
    printmaze(lmaze);
    
    /* If we made it to the edge of the array, we found the exit */
    if ((row+1) == 11) {
      printf("Solved\n");
      return 1;
    }else {
      x = mazeTraverse(lmaze, row+1, col);
      /* Escape ladder to end the loop when we got to the end */
      if (x == 1)
        return 1;
    }
  }
  
  /* Check right for path */
    if((col < 12) && (lmaze[row][col+1] == '.')) {
    lmaze[row][col+1] = 'X';
    printmaze(lmaze);
    if ((col+1) == 11) {
      printf("Solved\n");
      return 1;
    }else {
      x = mazeTraverse(lmaze, row, col+1);
            if (x == 1)
        return 1;
    }
  }
  
  /* Check up for path */
    if((row > 1) && (lmaze[row-1][col] == '.')) {
    lmaze[row-1][col] = 'X';
    printmaze(lmaze);
    if ((row-1) == 0) {
      printf("Solved\n");
      return 1;
    }else {
      x = mazeTraverse(lmaze, row-1, col);
            if (x == 1)
        return 1;
    }
  }
  
  /* Check left for path */
    if((col > 1) && (lmaze[row][col-1] == '.')) {
    lmaze[row][col-1] = 'X';
    printmaze(lmaze);
    if ((col-1) == 0) {
      printf("Solved\n");
      return 1;
    }else {
      x = mazeTraverse(lmaze, row, col-1);
            if (x == 1)
        return 1;
    }
  }
  return 0;
}
