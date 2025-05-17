#draw a heart
import turtle
t = turtle.Turtle()
t.hideturtle()
t.speed(0)
t.pensize(2)
t.pencolor('red')
t.fillcolor('red')
t.begin_fill()
t.left(50)
t.forward(133)
t.circle(50,200)
t.right(140)
t.circle(50,200)
t.forward(133)
t.end_fill()
turtle.done()

