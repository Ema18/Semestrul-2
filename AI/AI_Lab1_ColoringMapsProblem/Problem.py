from State import State

DEBUG = True
COLORS = ['blue', 'yellow', 'red']

class Problem:
    def __init__(self, input_file):
        self.input_file = input_file

        self.n, self.m, self.edges = None, None, None
        if not self.read_from_file():
            print('Error while reading from file.')
            exit(1)

        #all countries -> same color ('color 0' = no color)
        self.initial_state = State([0] * self.n)

        if DEBUG:
            print('Problem(): initial state = ' + str(self.initial_state))

    def get_nr_no_good(self, state):
        nr_no_good = 0

        # number of countries that are NOT colored yet
        for i in state.values:
            if i == 0:
                nr_no_good += 1

        # number of neighbours with the same colors
        for i in range(len(self.edges)):
            if state.values[self.edges[i][0]] == state.values[self.edges[i][1]]:
                nr_no_good += 1

        return nr_no_good

    def least_used_color(self, vector):
        c0 = vector.count(State.COLORS[0])
        c1 = vector.count(State.COLORS[1])
        c2 = vector.count(State.COLORS[2])

        # print('luc: ', str({COLORS[0]: c0, COLORS[1]: c1, COLORS[2]: c2}))
        return {0: c0, 1: c1, 2: c2}

    def is_solution(self, state):
        return self.get_nr_no_good(state) == 0

    @staticmethod
    def expand(state):
        for i in range(len(state.values)):
            if state.values[i] == 0:
                new_states = []
                for j in COLORS:
                    st = state.values[:]
                    st[i] = j
                    new_states.append(State(st))
                return new_states
        return []

    def heuristic(self, state1, state2):
        n1 = self.get_nr_no_good(state1)
        n2 = self.get_nr_no_good(state2)
        if n1 == n2:
            return 0
        return (n2 - n1) / abs(n2 - n1)

    def heuristic_2(self, state1, state2):
        c1 = state1.values.count(0)
        c2 = state2.values.count(0)

        s1 = state1.values[:-c1] # state1, without the final zeros
        s2 = state2.values[:-c2] # state2, without the final zeros

        vals = self.least_used_color(state1.values)
        if vals[s1[-1]] == vals[s2[-1]]:
            return 0
        return (vals[s2[-1]] - vals[s1[-1]]) / abs(vals[s2[-1]] - vals[s1[-1]])

    def read_from_file(self):
        try:
            fd = open(self.input_file, 'r')
            self.n = int(fd.readline().strip()) # number of countries
            self.m = int(fd.readline().strip()) # number of neighbours
            self.edges = []
            for i in range(self.m):
                x, y = fd.readline().strip().split(' ')
                x, y = int(x), int(y)
                self.edges.append((x, y))
        except IOError:
            return False

        if DEBUG:
            print('read_from_file ---->')
            print('n_countries = ' + str(self.n))
            print('n_neighbours = ' + str(self.m))
            print('edges = ' + str(self.edges))
            print('<---- read_from_file')

        return True