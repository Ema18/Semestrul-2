# Coloring the map problem
DEBUG = True
COLORS = ['blue', 'yellow', 'red']

class State:
    def __init__(self, values):
        self.values = values

    def __str__(self):
        return str(self.values)

    def __repr__(self):
        return self.__str__()