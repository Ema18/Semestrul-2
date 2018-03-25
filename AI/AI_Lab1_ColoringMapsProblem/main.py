from Controller import Controller
from Problem import Problem
from UI import UI

if __name__ == '__main__':
    p = Problem('file.txt')
    c = Controller(p)
    ui = UI(c)
    ui.run()