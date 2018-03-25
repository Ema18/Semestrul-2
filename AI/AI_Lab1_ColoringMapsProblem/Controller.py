import functools

from State import State

DEBUG = True
COLORS = ['blue', 'yellow', 'red']

class Controller:
    def __init__(self, problem):
        self.problem = problem

    def order_states(self, states):
        sorted_states = sorted(states, key=functools.cmp_to_key(self.problem.heuristic))
        return sorted_states

    def bfs(self):
        found = False
        the_solution = None
        visited = []
        to_visit = [self.problem.initial_state]

        while to_visit != [] and not found:
            node = to_visit.pop(0)

            if DEBUG:
                print('bfs: visiting ' + str(node))

            visited.append(node)
            if self.problem.is_solution(node):
                found = True
                the_solution = node
            else:
                aux = []
                for x in self.problem.expand(node):
                    if x not in visited:
                        aux.append(x)
                to_visit = to_visit + aux
        return the_solution

    def gbfs(self):
        found = False
        the_solution = None
        visited = []
        to_visit = [self.problem.initial_state]

        while to_visit != [] and not found:
            node = to_visit.pop(0)

            if DEBUG:
                print('gbfs: visiting ' + str(node))

            visited.append(node)
            if self.problem.is_solution(node):
                found = True
                the_solution = node
            else:
                aux = []
                #if self.order_states(self.problem.expand(node)) is not None:
                for x in self.order_states(self.problem.expand(node)):
                    if x not in visited:
                        aux.append(x)
                to_visit = to_visit + aux
        return the_solution