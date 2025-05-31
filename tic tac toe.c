#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char xo[10];

void reset_bored();
void creat();
void mark_bored(int choice, char mark);
int wenner();
int robot_choice();

int main()
{
  int choice, player, x, mode;
  char mark, replay;

  srand(time(NULL));

  printf("Choose mode:\n1. Player vs Player\n2. Player vs Robot\nEnter choice: ");
  scanf("%d", &mode);

  do
  {
    reset_bored();
    x = -1;
    player = 1;

    do
    {
      creat();
      printf("Player %d, enter a number: ", player);

      if (mode == 2 && player == 2)
      {
        choice = robot_choice();
        printf("Robot chooses: %d\n", choice);
      }
      else
      {
        scanf("%d", &choice);
      }

      mark = (player == 1) ? 'X' : 'O';
      if (choice >= 1 && choice <= 9 && xo[choice] == ('0' + choice)) {
        mark_bored(choice, mark);
      }
      else
      {
        printf("Invalid move! Try again.\n");
        continue;
      }

      x = wenner();
      if (x == -1)
        player = (player == 1) ? 2 : 1;

    } while (x == -1);

    creat();

    if (x == 1)
    {
      printf("Player %d Won the game!\n", (player == 1) ? 2 : 1);
    }
    else
    {
      printf("<------ Match Tie ------>\n");
    }

    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &replay);

  } while (replay == 'y' || replay == 'Y');

  return 0;
}

void reset_bored()
{
  for (int x = 1; x <= 9; x++)
    xo[x] = '0' + x;
}

void creat()
{
  printf("\n\nTic Tac Toe\n\n");
  printf("Player 1 (X) -- Player 2 (O)\n\n");

  printf(" %c   |  %c   |  %c   \n", xo[1], xo[2], xo[3]);
  printf("--------------------\n");
  printf(" %c   |  %c   |  %c   \n", xo[4], xo[5], xo[6]);
  printf("--------------------\n");
  printf(" %c   |  %c   |  %c   \n", xo[7], xo[8], xo[9]);
}

void mark_bored(int choice, char mark)
{
  xo[choice] = mark;
}

int wenner()
{
  int cond_wen[8][3] = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {3, 5, 7}};

  for (int x = 0; x < 8; x++)
  {
    if (xo[cond_wen[x][0]] == xo[cond_wen[x][1]] && xo[cond_wen[x][1]] == xo[cond_wen[x][2]])
    {
      return 1;
    }
  }

  for (int x1 = 1; x1 <= 9; x1++)
  {
    if (xo[x1] >= '1' && xo[x1] <= '9')
      return -1;
  }

  return 0;
}

int robot_choice()
{
  int available[9], count = 0;

  for (int x = 1; x <= 9; x++)
  {
    if (xo[x] == ('0' + x))
    {
      available[count++] = x;
    }
  }

  if (count == 0)
    return -1; 
  return available[rand() % count];
}
