class UI:
    def __init__(self, ctrl):
        self.ctrl = ctrl

    @staticmethod
    def print_menu():
        s = 'Please select an option.\n'
        s += '1 - solve using BFS\n'
        s += '2 - solve using GBFS\n'
        s += '0 - EXIT\n'
        print(s)

    def run(self):
        while True:
            self.print_menu()
            opt = str(input('Your option: ')).strip()
            if opt == '1':
                sol = self.ctrl.bfs()
                print('Solution found by BFS: ' + str(sol))
            elif opt == '2':
                sol = self.ctrl.gbfs()
                print('Solution found by GBFS: ' + str(sol))
            elif opt == '0':
                break
            else:
                print('Wrong command!')
            print('Bye!')
