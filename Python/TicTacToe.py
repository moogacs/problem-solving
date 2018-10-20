#Your assignment: Create a Tic Tac Toe game. You are free to use any IDE you like.

#Here are the requirements:

#2 players should be able to play the game (both sitting at the same computer)
#The board should be printed out every time a player makes a move
#You should be able to accept input of the player position and then place a symbol on the board

def display_board(board):
   print('\n'*100)
   print('\t {} \t | \t {} \t | \t {} \t'.format(board[1],board[2],board[3]))
   print('\t {} \t | \t {} \t | \t {} \t'.format(board[4],board[5],board[6]))
   print('\t {} \t | \t {} \t | \t {} \t'.format(board[7],board[8],board[9]))

def player_input():
    player1 = input("Player 1: Do you want to be 'X' or 'O'? ")
    while(True):
        if(player1 == 'X' or player1 == 'O'):
            return player1
        player1 = input('Please choose a valid marker!  ')

def place_marker(board, marker, position):

    board[position] = marker

def win_check(board, mark):

    for i in range(1,10):
        if i in range(1,4):
            if board[i] == board[i+3] == board[i+6] != ' ':
                return True
        if i in [1,4,7]:
            if board[i] == board[i+1] == board[i+2] != ' ':
                return True
        if i == 1:
            if board[i] == board[i+4] == board[i+8] != ' ':
                return True
        if i == 3:
            if board[i] == board[i+2] == board[i+4] != ' ':
                return True
    return False

import random

def choose_first():
    return random.randint(1,2)

def space_check(board, position):
    return board[position] == ' '

def full_board_check(board):
    for i in range(1,10):
        if board[i] == " ":
            return False

    return True

def player_choice(board):

    position = int(input('Where do you want to place your marker? choose(1-9) '))
    while True:
        if space_check(test_board,position) and position in range(1,10):
            return position
        position = int(input('This is not a free position! please enter a new one '))
        display_board(board)

def replay():

    answer = input('Do you want to play again? ')
    if answer.lower() == 'yes':
        return True
    return False

print('Welcome to Tic Tac Toe!')

while True:
    # Set the game up here
    test_board = [' ']*10
    game_start = input("Do you want to start playing? yes/no  ")

    if game_start[0].lower() == 'y':
        game_on = True
    else:
        game_on = False
        continue

    display_board(test_board)
    input1 = player_input()
    if input1 == 'O':
        input2 = 'X'
    else:
        input2 = 'O'
    turn = choose_first()
    print("Player {} will go first".format(turn))


    while game_on:
        #Player 1 Turn
        if turn == 1:
            if win_check(test_board,input2):
                print("Congrats! player 2 won! ")
                game_on = False
            elif full_board_check(test_board):
                print("The game is a draw! ")
                game_on = False
            else:
                place_marker(test_board,input1,player_choice(test_board))
                display_board(test_board)
                turn = 2
        else:
            #Player 2 Turn
            if win_check(test_board,input1):
                print("Congrats! player 1 won! ")
                game_on = False
            elif full_board_check(test_board):
                print("The game is a draw! ")
                game_on = False
            else:
                place_marker(test_board,input2,player_choice(test_board))
                display_board(test_board)
                turn = 1

    if not replay():
        break
