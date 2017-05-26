from msvcrt import getch
import os
import random
import threading
import time
import sys
import math

# Define blank list
board = []

random.seed()

# Function will print board like an actual board
def print_board(board):
    for row in board:
        print(" ".join(row))

size=10

# print_board(board)

myboard = []

for row in range(size):
    new = []
    for column in range(size):
        new.append("*")
    myboard.append(new)



# print (myboard[1][1])
# print_board(myboard)

def moveDown(x, y, emblem):
    if not x + 1 > size-1:
        if (myboard[x + 1][y] == '*'or myboard[x+1][y] == 'G'or(emblem=='C'and myboard[x+1][y] == 'U')):
            myboard[x][y] = '*'
            x = x + 1
            myboard[x][y] = emblem
    return x


def moveUp(x,y, emblem):
    if not x - 1 < 0:
        if (myboard[x - 1][y] == '*'or myboard[x-1][y] == 'G'or(emblem=='C'and myboard[x-1][y] == 'U')):
            myboard[x][y] = '*'
            x = x - 1
            myboard[x][y] = emblem
    return x


def moveLeft(x,y, emblem):
    if not y - 1 < 0:
        if (myboard[x][y - 1] == '*'or myboard[x][y-1] == 'G'or(emblem=='C'and myboard[x][y-1] == 'U')):
            myboard[x][y] = '*'
            y = y - 1
            myboard[x][y] = emblem
    return y


def moveRight(x,y, emblem):
    if not y + 1 > size-1:
        if (myboard[x][y + 1] == '*' or myboard[x][y + 1] == 'G'or(emblem=='C'and myboard[x][y+1] == 'U')):
            myboard[x][y] = '*'
            y = y + 1
            myboard[x][y] = emblem
    return y


def verticalWall(num, x, y):
    for z in range(x, x + num):
        if (z < size):
            myboard[z][y] = 'X'


def horizontalWall(num, x, y):
    for z in range(y, y + num):
        if (z < size):
            myboard[x][z] = 'X'


def clear():
    os.system('cls')

def startPos(emblem):
    temp='X'
    while not temp == '*':
        x=random.randint(0,size-1)
        y=random.randint(0,size-1)
        temp=myboard[x][y]
    myboard[x][y]=emblem
    return x, y

def endPos():
    temp='X'
    while not temp == '*':
        x=random.randint(0,size-1)
        y=random.randint(0,size-1)
        temp=myboard[x][y]
    myboard[x][y]='G'
    return x, y

def checkWin(x, y, emblem):
    if x==winX and y==winY:
        return True
    return False

def computerMove(computerx, computery, goalX, goalY):
    check=False
    while check==False:
        time.sleep(.5)
        distance=math.sqrt(math.pow(computerx-goalX,2)+math.pow(computery-goalY,2))
        #rep=random.randint(0,3)
        #if(rep==0):
        #   computerx = moveDown(computerx, computery, 'C')
        #if (rep == 1):
        #    computerx = moveUp(computerx, computery, 'C')
        #if (rep == 2):
        #    computery = moveRight(computerx, computery, 'C')
        #if (rep == 3):
        #    computery = moveLeft(computerx, computery, 'C')
        if(math.sqrt(math.pow((computerx+1)-winX,2)+math.pow(computery-winY,2))<distance and myboard[computerx+1][computery]!='X'):
            if(myboard[computerx+1][computery]=='U'):
                computerx = moveDown(computerx, computery, 'C')
                sys.exit(0)
            computerx = moveDown(computerx, computery, 'C')
        elif(math.sqrt(math.pow((computerx-1)-winX,2)+math.pow(computery-winY,2))<distance and myboard[computerx-1][computery]!='X'):
            if (myboard[computerx-1][computery] == 'U'):
                computerx = moveUp(computerx, computery, 'C')
                sys.exit(0)
            computerx = moveUp(computerx, computery, 'C')
        elif(math.sqrt(math.pow((computerx)-winX,2)+math.pow((computery-1)-winY,2))<distance and myboard[computerx][computery-1]!='X'):
            if (myboard[computerx][computery-1] == 'U'):
                computery = moveLeft(computerx, computery, 'C')
                sys.exit(0)
            computery=moveLeft(computerx, computery, 'C')
        elif (math.sqrt(math.pow((computerx)-winX,2)+math.pow((computery+1)-winY,2))<distance and myboard[computerx][computery+1]!='X'):
            if (myboard[computerx][computery + 1] == 'U'):
                computery = moveRight(computerx, computery, 'C')
                sys.exit(0)
            computery=moveRight(computerx, computery, 'C')
        # clear()
        # print_board(myboard)
        check=checkWin(computerx, computery, 'C')
        if(check):
            sys.exit(0)

def userMove(userx, usery):
    check=False
    while check==False:
        key = ord(getch())
        if key == 27:  # ESC
            check = True
        if key == 224:  # Special keys (arrows, f keys, ins, del, etc.)
            key = ord(getch())
            if key == 80:  # Down arrow
                userx = moveDown(userx, usery, 'U')
            # x += 1
            elif key == 72:  # Up arrow
                userx = moveUp(userx, usery, 'U')
            # x -= 1
            elif key == 75:
                usery = moveLeft(userx, usery, 'U')
            # y -= 1
            elif key == 77:
                usery = moveRight(userx, usery, 'U')
            # y += 1
            check = checkWin(userx, usery, 'U')
            # if (check == False):
            #     clear()
            #     print_board(myboard)

def refreshBoard(check):
    if(not check):
        clear()
        print_board(myboard)

for x in range(0, random.randint(0,4)):
    horizontalWall(random.randint(0,4), random.randint(0,size-1), random.randint(0,size-1))
for z in range(0, random.randint(0,4)):
    verticalWall(random.randint(0,4), random.randint(0,size-1), random.randint(0,size-1))

userx, usery=startPos('U')
computerx, computery=startPos('C')
winX, winY=endPos()
clear()
print_board(myboard)

end = False

threading1 = threading.Thread(target=computerMove, args=(computerx, computery, winX, winY))
threading1.daemon = True
threading1.start()

threading2=threading.Thread(target=userMove, args=(userx, usery))
threading2.daemon=True
threading2.start()

while end==False:
    time.sleep(0.2)
    refreshBoard(end)
    if (not threading1.is_alive()):
        end = True
        print("Computer Wins")
    if(not threading2.is_alive()):
        end = True
        print("Congratulations you win")

