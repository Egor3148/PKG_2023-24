import matplotlib.pyplot as plt
from tkinter import ttk
from tkinter import *
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import re

class Point():
    '''Class point
    Contains the info about coordinates and the radius (default r = 5)'''

    #constructor
    def __init__(self, x, y, r=5):
        self.x = x  #center X
        self.y = y  #center Y
        self.r = r  #radius

#-----------------RASTERIZATION METHODS------------------

def drawByStep(p1, p2):
    '''Step algorithm
    Calculates the increment values 
    via horizontal and vertical distances'''

    x1, y1 = p1.x, p1.y
    x2, y2 = p2.x, p2.y
    #the order is important
    if x1 > x2:
        x1, x2 = x2, x1
        y1, y2 = y2, y1
    #distances values
    dx = x2 - x1
    dy = y2 - y1
    
    #result array
    xArr, yArr = [], []
    
    #Rasterization process itself
    for i in range(x1, x2 + 1):
        xArr.append(i)
        yArr.append(y1 + dy * (i - x1) / dx)
        
    return xArr, yArr


def drawByDDA(p1, p2):
    '''DDA algorithm
    Calculates the increment values via the max(dx, dy) values'''
    
    x1, y1 = p1.x, p1.y
    x2, y2 = p2.x, p2.y
    #the order is not so important
    #distances (absolute values)
    dx = abs(x2 - x1)
    dy = abs(y2 - y1)
    #max distance value (used to define increment values to "spread" the points in a plain manner)
    L = max(dx, dy)
    #increment values
    xIncr = dx / L
    y_incr = dy / L
    x = x1
    y = y1
    
    xArr, yArr = [], []
    #rasterization process itself
    for _ in range(L):
        xArr.append(x)
        yArr.append(y)
        x += xIncr
        y += y_incr
        
    return xArr, yArr


def drawByWu(p1, p2):
    '''Wu's algorithm
    Good for the situation when you need to rasterize a thick smooth line'''
    
    x1, y1 = p1.x, p1.y
    x2, y2 = p2.x, p2.y
    #the order of coordinates and values is important as the angle is important
    steep = abs(y2 - y1) > abs(x2 - x1)
    if steep:
        x1, y1 = y1, x1
        x2, y2 = y2, x2
    if x1 > x2:
        x1, x2 = x2, x1
        y1, y2 = y2, y1
    xArr, yArr = [], []
    
    if steep:
        xArr.append(x1)
        yArr.append(y1)
    else:
        xArr.append(y1)
        yArr.append(x1)
        
    if steep:
        xArr.append(x2)
        yArr.append(y2)
    else:
        xArr.append(y2)
        yArr.append(x2)
    #distances and gradient value
    dx = x2 - x1
    dy = y2 - y1
    gradient = dy / dx  #it's not any derivative
    
    y = y1 + gradient
    
    #rasterization process itself
    for i in range(x1 + 1, x2):
        if steep:
            xArr.append(i)
            yArr.append(round(y)) #coordinates are always integer (NO HALF-PIXELS!)
        else:
            xArr.append(round(y))
            yArr.append(i)
            
        if steep:
            xArr.append(i)
            yArr.append(round(y) + 1)
        else:
            xArr.append(round(y) + 1)
            yArr.append(i)
        y += gradient
        
    return xArr, yArr


def drawByBresenhamLine(p1, p2):
    '''Bresenham algorithm for lines'''
    
    x1, y1 = p1.x, p1.y
    x2, y2 = p2.x, p2.y
    #the order is not so important
    #distances (absolute values)
    dx = abs(x2 - x1)
    dy = abs(y2 - y1)
    #sign values for calculations
    signX = 1 if x1 < x2 else -1
    signY = 1 if y1 < y2 else -1
    #error value
    err = dx - dy
    
    xArr, yArr = [], []
    #rasterization process itself
    #appending new values while it isn't the destination point
    while x1 != x2 or y1 != y2:
        xArr.append(abs(x1))
        yArr.append(abs(y1))
        err2 = err * 2
        if (err2 > -dy):
            err -= dy
            x1 += signX
        if (err2 < dx):
            err += dx
            y1 += signY
            
    return xArr, yArr


def drawByBresenhamCircle(p1, r):
    '''Bresenham algorithm for circles'''
    
    x1, y1 = p1.x, p1.y
    x = r
    y = 0
    rerr = 1 - x
    xArr, yArr = [], []
    while x >= y:
        xArr.extend([x + x1, y + x1, -x + x1, -y + x1, -
                  x + x1, -y + x1, x + x1, y + x1])
        yArr.extend([y + y1, x + y1, y + y1, x + y1, -
                  y + y1, -x + y1, -y + y1, -x + y1])
        y += 1
        
        if rerr < 0:
            rerr += (2 * y) + 1
        else:
            x -= 1
            rerr += 2 * (y - x + 1)
            
    return xArr, yArr

#---------------------------DRAWING METHODS-----------------------

def draw():
    '''Draws the rasterized samples according to the input data'''
    
    #gathering input data
    p1.x = int(entr1.get()) if entr1.get() != '' else 180
    p1.y = int(entr2.get()) if entr1.get() != '' else 180
    p2.x = int(entr3.get()) if entr1.get() != '' else 210
    p2.y = int(entr4.get()) if entr1.get() != '' else 160
    p2.r = int(entr5.get()) if entr1.get() != '' else 5
    
    #defining the output data
    stepX, stepY = drawByStep(p1, p2)
    ddaX, ddaY = drawByDDA(p1, p2)
    brLnX, brLnY = drawByBresenhamLine(p1, p2)
    brCrcX, brCrcY = drawByBresenhamCircle(p1, p2.r)
    
    #output widgets creation
    ax1.clear()
    ax1.grid()
    ax1.minorticks_on()
    ax1.grid(which='major',
             color='k',
             linewidth=0.1)
    ax1.grid(which='minor',
             color='k',
             linewidth=0.1)
    ax1.plot(stepY, stepX, '-')
    ax1.plot(stepY, stepX, '.')
    ax1.title.set_text("Step algorithm")
    
    ax2.clear()
    ax2.grid()
    ax2.minorticks_on()
    ax2.grid(which='major',
             color='k',
             linewidth=0.1)
    ax2.grid(which='minor',
             color='k',
             linewidth=0.1)
    ax2.plot(ddaX, ddaY, '-')
    ax2.plot(ddaX, ddaY, '.')
    ax2.title.set_text("DDA algorithm")
    
    ax3.clear()
    ax3.grid()
    ax3.minorticks_on()
    ax3.grid(which='major',
             color='k',
             linewidth=0.1)
    ax3.grid(which='minor',
             color='k',
             linewidth=0.1)
    ax3.plot(brLnX, brLnY, '-')
    ax3.plot(brLnX, brLnY, '.')
    ax3.title.set_text("Bresenham line algorithm")
    
    ax4.clear()
    ax4.grid()
    ax4.minorticks_on()
    ax4.grid(which='major',
             color='k',
             linewidth=0.1)
    ax4.grid(which='minor',
             color='k',
             linewidth=0.1)
    ax4.plot(brCrcX, brCrcY, 'bo')
    ax4.title.set_text("Bresenham circle algorithm")
    
    ax1.set_ylabel("y",labelpad=1,loc='bottom')
    ax1.set_xlabel("x",labelpad=1,loc = 'left')
    
    ax2.set_ylabel("y",labelpad=1,loc='bottom')
    ax2.set_xlabel("x",labelpad=1,loc = 'left')
    
    ax3.set_ylabel("y",labelpad=1,loc='bottom')
    ax3.set_xlabel("x",labelpad=1,loc = 'left')
    
    ax4.set_ylabel("y",labelpad=1,loc='bottom')
    ax4.set_xlabel("x",labelpad=1,loc = 'left')
    
    canvas.draw()

#checks the input values
def isValid(newval):
    return re.match("\d+", newval) is not None

#-------------------------------MAIN-------------------------------

if __name__ == "__main__":
    #default values
    p1 = Point(180, 180)
    p2 = Point(210, 160)
    
    root = Tk()
    w, h = root.winfo_screenwidth(), root.winfo_screenheight()
    root.geometry(f"800x700+{w//2 - 200}+{h// - 200}")
    
    fig = plt.figure(figsize=(5, 5))
    frame1 = Frame(root)
    frame1.place(x=0, y=0, width=700, height=700)
    
    canvas = FigureCanvasTkAgg(fig, frame1)
    canvas.get_tk_widget().place(x=0, y=0, width=700, height=700)
    
    ax1 = fig.add_subplot(221)
    ax1.grid()
    ax1.minorticks_on()
    ax1.grid(which='major',
             color='k',
             linewidth=0.1)
    ax1.grid(which='minor',
             color='k',
             linewidth=0.1)
    
    ax2 = fig.add_subplot(222)
    ax2.grid()
    ax2.minorticks_on()
    ax2.grid(which='major',
             color='k',
             linewidth=0.1)
    ax2.grid(which='minor',
             color='k',
             linewidth=0.1)
    
    ax3 = fig.add_subplot(223)
    ax3.grid()
    ax3.minorticks_on()
    ax3.grid(which='major',
             color='k',
             linewidth=0.1)
    ax3.grid(which='minor',
             color='k',
             linewidth=0.1)
    
    ax4 = fig.add_subplot(224)
    ax4.grid()
    ax4.minorticks_on()
    ax4.grid(which='major',
             color='k',
             linewidth=0.1)
    ax4.grid(which='minor',
             color='k',
             linewidth=0.1)
    
    ax1.set_ylabel("y",labelpad=1,loc='bottom')
    ax1.set_xlabel("x",labelpad=1,loc = 'left')
    
    ax2.set_ylabel("y",labelpad=1,loc='bottom')
    ax2.set_xlabel("x",labelpad=1,loc = 'left')
    
    ax3.set_ylabel("y",labelpad=1,loc='bottom')
    ax3.set_xlabel("x",labelpad=1,loc = 'left')
    
    ax4.set_ylabel("y",labelpad=1,loc='bottom')
    ax4.set_xlabel("x",labelpad=1,loc = 'left')
    
    frame2 = Frame(root)
    frame2.place(x=700, y=0, width=2800, height=300)
    check = (root.register(isValid), "%P")
    entr1 = ttk.Entry(frame2, validate='key', validatecommand=check)
    entr1.place(x=30, y=20, width=60, height=20)
    
    entr2 = ttk.Entry(frame2)
    entr2.place(x=30, y=50, width=60, height=20)
    
    entr3 = ttk.Entry(frame2)
    entr3.place(x=30, y=80, width=60, height=20)
    
    entr4 = ttk.Entry(frame2)
    entr4.place(x=30, y=110, width=60, height=20)
    
    entr5 = ttk.Entry(frame2)
    entr5.place(x=30, y=140, width=60, height=20)
    
    lbl1 = ttk.Label(frame2, text='X1: ')
    lbl1.place(x=0, y=20, width=30, height=20)
    
    lbl2 = ttk.Label(frame2, text='Y1: ')
    lbl2.place(x=0, y=50, width=30, height=20)
    
    lbl3 = ttk.Label(frame2, text='X2: ')
    lbl3.place(x=0, y=80, width=30, height=20)
    
    lbl4 = ttk.Label(frame2, text='Y2: ')
    lbl4.place(x=0, y=110, width=30, height=20)
    
    lbl5 = ttk.Label(frame2, text='R: ')
    lbl5.place(x=0, y=140, width=30, height=20)

    btplot1 = Button(frame2, text='Draw', command=lambda: draw())
    btplot1.place(x=30, y=170, width=60, height=50)

    root.mainloop()
