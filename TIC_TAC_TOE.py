import pygame, sys,random

from pygame.locals import *
 
 
pygame.init()

FPS = 30	
fpsClock = pygame.time.Clock()
 
DISPLAYSURF= pygame.display.set_mode((500, 500))
 
pygame.display.set_caption('TIC_TAC_TOE')

WHITE = (255, 255, 255)
BLUE = ( 0, 0, 255)
RED= (255,0,0)
GREEN = (0, 255, 0)
BLACK = 0,0,0

DISPLAYSURF.fill(WHITE)
pygame.draw.line(DISPLAYSURF,BLACK,(200,100),(200,400))
pygame.draw.line(DISPLAYSURF,BLACK,(300,100),(300,400))
pygame.draw.line(DISPLAYSURF,BLACK,(100,200),(400,200))
pygame.draw.line(DISPLAYSURF,BLACK,(100,300),(400,300))

box_0 = [100,200,200,100,0]
box_1 = [200,200,300,100,0]
box_2 = [300,200,400,100,0]
box_3 = [100,300,200,200,0]
box_4 = [200,300,300,200,0]
box_5 = [300,300,400,200,0]
box_6 = [100,400,200,300,0]
box_7 = [200,400,300,300,0]
box_8 = [300,400,400,300,0]

matrix = [box_0,box_1,box_2,box_3,box_4,box_5,box_6,box_7,box_8]
var_matrix = matrix

def check_which_box(posn):
	if (posn[0] > box_0[0] and posn[0] < box_0[2] and posn[1] < box_0[1] and posn[1] > box_0[3]):
		return box_0
	elif (posn[0] > box_1[0] and posn[0] < box_1[2] and posn[1] < box_1[1] and posn[1] > box_1[3]):
		return box_1
	elif (posn[0] > box_2[0] and posn[0] < box_2[2] and posn[1] < box_2[1] and posn[1] > box_2[3]):
		return box_2
	elif (posn[0] > box_3[0] and posn[0] < box_3[2] and posn[1] < box_3[1] and posn[1] > box_3[3]):
		return box_3
	elif (posn[0] > box_4[0] and posn[0] < box_4[2] and posn[1] < box_4[1] and posn[1] > box_4[3]):
		return box_4
	elif (posn[0] > box_5[0] and posn[0] < box_5[2] and posn[1] < box_5[1] and posn[1] > box_5[3]):
		return box_5
	elif (posn[0] > box_6[0] and posn[0] < box_6[2] and posn[1] < box_6[1] and posn[1] > box_6[3]):
		return box_6
	elif (posn[0] > box_7[0] and posn[0] < box_7[2] and posn[1] < box_7[1] and posn[1] > box_7[3]):
		return box_7
	elif (posn[0] > box_8[0] and posn[0] < box_8[2] and posn[1] < box_8[1] and posn[1] > box_8[3]):
		return box_8
	else:
		return None

def find_index(box,var_matrix):
	i=0
	while i<len(var_matrix):
		if box==var_matrix[i]:
			return i
			break
		else:
			i=i+1
			continue
		
	return None
	

def draw_player_fig(box):
	pygame.draw.line(DISPLAYSURF,BLUE,(box[0]+20,box[1]-20),(box[2]-20,box[3]+20),2)
	pygame.draw.line(DISPLAYSURF,BLUE,(box[0]+20,box[1]-80),(box[2]-20,box[3]+80),2)

def draw_computer_fig(box):
	pygame.draw.circle(DISPLAYSURF,RED,((box[0]+box[2])/2,(box[1]+box[3])/2),40,2)

def display_win():
	fontObj = pygame.font.Font('freesansbold.ttf', 20)
	textSurfaceObj = fontObj.render('YOU WON!!', True, GREEN, BLUE)
	textRectObj = textSurfaceObj.get_rect()
	textRectObj.center = (250,450)
	DISPLAYSURF.blit(textSurfaceObj, textRectObj)

def display_lose():
	fontObj = pygame.font.Font('freesansbold.ttf', 20)
	textSurfaceObj = fontObj.render('SORRY U LOST!!', True, GREEN, BLUE)
	textRectObj = textSurfaceObj.get_rect()
	textRectObj.center = (250,450)
	DISPLAYSURF.blit(textSurfaceObj, textRectObj)

def display_tie():
	fontObj = pygame.font.Font('freesansbold.ttf', 20)
	textSurfaceObj = fontObj.render('GAME TIED!!', True, GREEN, BLUE)
	textRectObj = textSurfaceObj.get_rect()
	textRectObj.center = (250,450)
	DISPLAYSURF.blit(textSurfaceObj, textRectObj)

def check_for_win(matrix):
	return ((matrix[0][4]==1 and matrix[1][4]==1 and matrix[2][4]==1) or
			(matrix[3][4]==1 and matrix[4][4]==1 and matrix[5][4]==1) or
			(matrix[6][4]==1 and matrix[7][4]==1 and matrix[8][4]==1) or
			(matrix[0][4]==1 and matrix[3][4]==1 and matrix[6][4]==1) or
			(matrix[1][4]==1 and matrix[4][4]==1 and matrix[7][4]==1) or
			(matrix[2][4]==1 and matrix[5][4]==1 and matrix[8][4]==1) or
			(matrix[0][4]==1 and matrix[4][4]==1 and matrix[8][4]==1) or
			(matrix[2][4]==1 and matrix[4][4]==1 and matrix[6][4]==1))

def check_for_lose(matrix):
	return ((matrix[0][4]==2 and matrix[1][4]==2 and matrix[2][4]==2) or
			(matrix[3][4]==2 and matrix[4][4]==2 and matrix[5][4]==2) or
			(matrix[6][4]==2 and matrix[7][4]==2 and matrix[8][4]==2) or
			(matrix[0][4]==2 and matrix[3][4]==2 and matrix[6][4]==2) or
			(matrix[1][4]==2 and matrix[4][4]==2 and matrix[7][4]==2) or
			(matrix[2][4]==2 and matrix[5][4]==2 and matrix[8][4]==2) or
			(matrix[0][4]==2 and matrix[4][4]==2 and matrix[8][4]==2) or
			(matrix[2][4]==2 and matrix[4][4]==2 and matrix[6][4]==2))
def check_for_tie(matrix):
	a=True
	for i in var_matrix:
		if i[4]==0:
			a=False
	return a

def computer_move(matrix):

	if (matrix[0][4]==0 and matrix[1][4]==2 and matrix[2][4]==2): 
		draw_computer_fig(matrix[0])
		matrix[0][4]=2 
		return
	elif (matrix[0][4]==2 and matrix[1][4]==0 and matrix[2][4]==2):
		draw_computer_fig(matrix[1])
		matrix[1][4]=2 
		return
	elif (matrix[0][4]==2 and matrix[1][4]==2 and matrix[2][4]==0):
		draw_computer_fig(matrix[2])
		matrix[2][4]=2 
		return
	elif (matrix[3][4]==0 and matrix[4][4]==2 and matrix[5][4]==2):
		draw_computer_fig(matrix[3])
		matrix[3][4]=2 
		return
	elif (matrix[3][4]==2 and matrix[4][4]==0 and matrix[5][4]==2):
		draw_computer_fig(matrix[4])
		matrix[4][4]=2 
		return
	elif (matrix[3][4]==2 and matrix[4][4]==2 and matrix[5][4]==0):
		draw_computer_fig(matrix[5])
		matrix[5][2]=2 
		return
	elif (matrix[6][4]==0 and matrix[7][4]==2 and matrix[8][4]==2):
		draw_computer_fig(matrix[6])
		matrix[6][4]=2 
		return
	elif (matrix[6][4]==2 and matrix[7][4]==0 and matrix[8][4]==2):
		draw_computer_fig(matrix[7])
		matrix[7][4]=2 
		return
	elif (matrix[6][4]==2 and matrix[7][4]==2 and matrix[8][4]==0):
		draw_computer_fig(matrix[8])
		matrix[8][4]=2 
		return

	#############VERTICAL CHECK#######################
	elif (matrix[0][4]==0 and matrix[3][4]==2 and matrix[6][4]==2): 
		draw_computer_fig(matrix[0])
		matrix[0][4]=2 
		return
	elif (matrix[0][4]==2 and matrix[3][4]==0 and matrix[6][4]==2):
		draw_computer_fig(matrix[3])
		matrix[3][4]=2 
		return
	elif (matrix[0][4]==2 and matrix[3][4]==2 and matrix[6][4]==0):
		draw_computer_fig(matrix[6])
		matrix[6][4]=2 
		return
	elif (matrix[1][4]==0 and matrix[4][4]==2 and matrix[7][4]==2):
		draw_computer_fig(matrix[1])
		matrix[1][4]=2 
		return
	elif (matrix[1][4]==2 and matrix[4][4]==0 and matrix[7][4]==2):
		draw_computer_fig(matrix[4])
		matrix[4][4]=2 
		return
	elif (matrix[1][4]==2 and matrix[4][4]==2 and matrix[7][4]==0):
		draw_computer_fig(matrix[7])
		matrix[7][2]=2 
		return
	elif (matrix[2][4]==0 and matrix[5][4]==2 and matrix[8][4]==2):
		draw_computer_fig(matrix[2])
		matrix[2][4]=2 
		return
	elif (matrix[2][4]==2 and matrix[5][4]==0 and matrix[8][4]==2):
		draw_computer_fig(matrix[5])
		matrix[5][4]=2 
		return
	elif (matrix[2][4]==2 and matrix[5][4]==2 and matrix[8][4]==0):
		draw_computer_fig(matrix[8])
		matrix[8][4]=2 
		return

	###################CROSS CHECK###########################
	elif (matrix[0][4]==0 and matrix[4][4]==2 and matrix[8][4]==2): 
		draw_computer_fig(matrix[0])
		matrix[0][4]=2 
		return
	elif (matrix[0][4]==2 and matrix[4][4]==0 and matrix[8][4]==2):
		draw_computer_fig(matrix[4])
		matrix[4][4]=2 
		return
	elif (matrix[0][4]==2 and matrix[4][4]==2 and matrix[8][4]==0):
		draw_computer_fig(matrix[8])
		matrix[8][4]=2 
		return
	elif (matrix[2][4]==0 and matrix[4][4]==2 and matrix[6][4]==2): 
		draw_computer_fig(matrix[2])
		matrix[2][4]=2 
		return
	elif (matrix[2][4]==2 and matrix[4][4]==0 and matrix[6][4]==2):
		draw_computer_fig(matrix[4])
		matrix[4][4]=2 
		return
	elif (matrix[2][4]==2 and matrix[4][4]==2 and matrix[6][4]==0):
		draw_computer_fig(matrix[6])
		matrix[6][4]=2 
		return

	###### HORIZONTAL CHECK#############
	if (matrix[0][4]==0 and matrix[1][4]==1 and matrix[2][4]==1): 
		draw_computer_fig(matrix[0])
		matrix[0][4]=2 
		return
	elif (matrix[0][4]==1 and matrix[1][4]==0 and matrix[2][4]==1):
		draw_computer_fig(matrix[1])
		matrix[1][4]=2 
		return
	elif (matrix[0][4]==1 and matrix[1][4]==1 and matrix[2][4]==0):
		draw_computer_fig(matrix[2])
		matrix[2][4]=2 
		return
	elif (matrix[3][4]==0 and matrix[4][4]==1 and matrix[5][4]==1):
		draw_computer_fig(matrix[3])
		matrix[3][4]=2 
		return
	elif (matrix[3][4]==1 and matrix[4][4]==0 and matrix[5][4]==1):
		draw_computer_fig(matrix[4])
		matrix[4][4]=2 
		return
	elif (matrix[3][4]==1 and matrix[4][4]==1 and matrix[5][4]==0):
		draw_computer_fig(matrix[5])
		matrix[5][2]=2 
		return
	elif (matrix[6][4]==0 and matrix[7][4]==1 and matrix[8][4]==1):
		draw_computer_fig(matrix[6])
		matrix[6][4]=2 
		return
	elif (matrix[6][4]==1 and matrix[7][4]==0 and matrix[8][4]==1):
		draw_computer_fig(matrix[7])
		matrix[7][4]=2 
		return
	elif (matrix[6][4]==1 and matrix[7][4]==1 and matrix[8][4]==0):
		draw_computer_fig(matrix[8])
		matrix[8][4]=2 
		return

	#############VERTICAL CHECK#######################
	elif (matrix[0][4]==0 and matrix[3][4]==1 and matrix[6][4]==1): 
		draw_computer_fig(matrix[0])
		matrix[0][4]=2 
		return
	elif (matrix[0][4]==1 and matrix[3][4]==0 and matrix[6][4]==1):
		draw_computer_fig(matrix[3])
		matrix[3][4]=2 
		return
	elif (matrix[0][4]==1 and matrix[3][4]==1 and matrix[6][4]==0):
		draw_computer_fig(matrix[6])
		matrix[6][4]=2 
		return
	elif (matrix[1][4]==0 and matrix[4][4]==1 and matrix[7][4]==1):
		draw_computer_fig(matrix[1])
		matrix[1][4]=2 
		return
	elif (matrix[1][4]==1 and matrix[4][4]==0 and matrix[7][4]==1):
		draw_computer_fig(matrix[4])
		matrix[4][4]=2 
		return
	elif (matrix[1][4]==1 and matrix[4][4]==1 and matrix[7][4]==0):
		draw_computer_fig(matrix[7])
		matrix[7][2]=2 
		return
	elif (matrix[2][4]==0 and matrix[5][4]==1 and matrix[8][4]==1):
		draw_computer_fig(matrix[2])
		matrix[2][4]=2 
		return
	elif (matrix[2][4]==1 and matrix[5][4]==0 and matrix[8][4]==1):
		draw_computer_fig(matrix[5])
		matrix[5][4]=2 
		return
	elif (matrix[2][4]==1 and matrix[5][4]==1 and matrix[8][4]==0):
		draw_computer_fig(matrix[8])
		matrix[8][4]=2 
		return

	###################CROSS CHECK###########################
	elif (matrix[0][4]==0 and matrix[4][4]==1 and matrix[8][4]==1): 
		draw_computer_fig(matrix[0])
		matrix[0][4]=2 
		return
	elif (matrix[0][4]==1 and matrix[4][4]==0 and matrix[8][4]==1):
		draw_computer_fig(matrix[4])
		matrix[4][4]=2 
		return
	elif (matrix[0][4]==1 and matrix[4][4]==1 and matrix[8][4]==0):
		draw_computer_fig(matrix[8])
		matrix[8][4]=2 
		return
	elif (matrix[2][4]==0 and matrix[4][4]==1 and matrix[6][4]==1): 
		draw_computer_fig(matrix[2])
		matrix[2][4]=2 
		return
	elif (matrix[2][4]==1 and matrix[4][4]==0 and matrix[6][4]==1):
		draw_computer_fig(matrix[4])
		matrix[4][4]=2 
		return
	elif (matrix[2][4]==1 and matrix[4][4]==1 and matrix[6][4]==0):
		draw_computer_fig(matrix[6])
		matrix[6][4]=2 
		return

	else:
		possibleMoves=[]
		for i in var_matrix:
			if i[4]==0 :
				possibleMoves.append(i)
		if len(possibleMoves)!=0:
			box1 = random.choice(possibleMoves)
			draw_computer_fig(box1)
			box1[4]=2
		else:
			return None

	return


while True:
# main game loop
	
	for event in pygame.event.get():
 		
		if event.type == QUIT:
 
			pygame.quit()
 
			sys.exit()

		elif event.type == MOUSEBUTTONUP:
			POSITION= event.pos
			box=check_which_box(POSITION)
			if box==None:
				continue
			else: index=find_index(box,var_matrix)
			if index==None:
				continue
			elif not var_matrix[index][4]==0:
				continue
			else:
				draw_player_fig(box)
				var_matrix[index][4]=1
			
			if check_for_win(var_matrix):
				display_win()
				for m in var_matrix:
					m[4]=0
				continue
				
			elif check_for_lose(var_matrix):
				display_lose()
				for m in var_matrix:
					m[4]=0
				continue

			elif check_for_tie(var_matrix):
				display_tie()
				for m in var_matrix:
					m[4]=0
				continue

	
			computer_move(var_matrix)	
		 	
			if check_for_win(var_matrix):
				display_win()
				continue
				
			elif check_for_lose(var_matrix):
				display_lose()
				continue
			elif check_for_tie(var_matrix):
				display_tie()
				continue

			else:
				continue

  	pygame.display.update()
