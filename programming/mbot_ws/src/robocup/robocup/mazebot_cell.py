class MazebotCell:
    def __init__(self, wall, wall_det, visit_counter, position_x, position_y):
        self.wall = wall
        self.wall_det = wall_det
        self.visit_counter = visit_counter
        self.position_x = position_x
        self.position_y = position_y

# Create grid of cells
grid = []
for i in range(30):
    row = []
    for j in range(30):
        cell = MazebotCell([False]*4, [False]*4, 0, i-15, j-15)
        row.append(cell)
    grid.append(row)

# Print positions of the cells
for i in range(30):
    for j in range(30):
        cell = grid[i][j]
        print(f"Cell positions \t({cell.position_x}, {cell.position_y}):   \t "
              f"[{i}][{j}]")
        