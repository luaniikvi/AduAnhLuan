import pygame as pg
import numpy as np
import math
import random,sys
class Ball:
    def __init__(self,position, velocity):
        self.pos = np.array(position, dtype=np.float64)
        self.v = np.array(velocity , dtype=np.float64)
        self.color = (random.randint(0,255),random.randint(0,255),random.randint(0,255))
        self.is_in = True

def draw_arc(windown, center, radius, start_angle, end_angle, COLOR):
    
    p1 = center + (radius+100)*np.array([math.cos(start_angle), math.sin(start_angle)])
    p2 = center + (radius+100)*np.array([math.cos(end_angle), math.sin(end_angle)])
    pg.draw.polygon(windown, COLOR, [center,p1,p2] ,0)

def isBallInArc(center, ballpos, start_angle, end_angle):
    dx = ballpos[0]- center[0]
    dy = ballpos[1]- center[1]
    ball_angle = math.atan2(dy,dx)
    start_angle %= 2*math.pi
    end_angle %= 2*math.pi
    if(start_angle > end_angle):
        end_angle += 2*math.pi
    return start_angle <= ball_angle <= end_angle or (start_angle <= ball_angle + 2*math.pi <= end_angle)

pg.init()
#Attribute
FPS = 200
WIDTH, HEIGHT = 800, 800
CIRCLE_CENTER = (400, 400)
CIRCLE_RADIUS = 200
BALL_RADIUS = 10
ball_pos = np.array([400, 350], dtype = np.float64)
ball_vel = np.array([1,0], dtype= np.float64)
Gravity = (0,0.07)

arc_angle = 60
start_angle = math.radians(-arc_angle/2)
end_angle = math.radians(arc_angle/2)
spining_speed = 0.007

balls = [Ball(ball_pos,ball_vel)]

#color
BLACK = (0, 0, 0)
ORANGE = (255, 165, 0)
RED = (255, 0, 0)
WHITE = (255, 255, 255)
BACKGORUND_COLOR = BLACK

#set up windown
windown = pg.display.set_mode((WIDTH, HEIGHT))
clock = pg.time.Clock()
running = True
pausing = False

#running game
while running:
    #set UI
    pg.display.set_caption("Chaos Circle Game")
    
    # check event
    for event in pg.event.get():
        if event.type == pg.QUIT:
            running = False
        elif event.type == pg.KEYDOWN:
            if event.key == pg.K_ESCAPE:
                running = False
            elif event.key == pg.K_SPACE:
                pausing = True
    
    #Physics
    for ball in balls:
        ball.v += Gravity
        ball.pos += ball.v
    distance = np.linalg.norm(ball_pos - CIRCLE_CENTER)

    start_angle += spining_speed
    end_angle += spining_speed
    

    #draw
    windown.fill(BACKGORUND_COLOR)

    pg.draw.circle(windown,ORANGE, CIRCLE_CENTER, CIRCLE_RADIUS, 5)
    draw_arc(windown, CIRCLE_CENTER,CIRCLE_RADIUS, start_angle, end_angle, BLACK)

    for ball in balls:
        pg.draw.circle(windown,ball.color, ball.pos , BALL_RADIUS)
    while(pausing):
        for e in pg.event.get():
            if e.type == pg.QUIT:
                pause = False
                running = False
            if e.type == pg.KEYDOWN :
                if e.key == pg.K_SPACE:
                    pausing = False    
                



    #check collision
    for ball in balls:
        #remove lag
        if ball.pos[0] > WIDTH or ball.pos[0] < 0 or ball.pos[1] > HEIGHT or ball.pos[1] < 0:
            balls.remove(ball)
            balls.append(Ball(ball_pos, velocity=[random.uniform(-4,4), random.uniform(-4,4)]))
            balls.append(Ball(ball_pos, velocity=[random.uniform(-4,4), random.uniform(-4,4)]))

        distance = np.linalg.norm(ball.pos - CIRCLE_CENTER)
        if distance + BALL_RADIUS >= CIRCLE_RADIUS:
            if isBallInArc(CIRCLE_CENTER,ball.pos,start_angle,end_angle):
               ball.is_in = False
            if(ball.is_in):
                d = np.array(ball.pos - CIRCLE_CENTER, dtype= np.float64)
                ball.pos = np.array(CIRCLE_CENTER,dtype=np.float64) + (CIRCLE_RADIUS - BALL_RADIUS)*(d/math.sqrt(d[0]*d[0]+d[1]*d[1]))

                t = np.array([-d[1],d[0]], dtype = np.float64)

                proj_v_t = (np.dot(ball.v,t)/np.dot(t,t)) * t
                ball.v = 2*proj_v_t - ball.v
                
    #end draw
    pg.display.flip() #update frame
    clock.tick(FPS) # set frame

pg.quit()   