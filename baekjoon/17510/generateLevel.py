path = '''
##########
#...##....
#.........
#........#
#...###..#
##..##...#
....##....
.....#....
#....#..##
'''.strip().split()

bridge = '''
#####
#####
#####
#####
#####
....#
.....
#....
#..##
#..##
#..##
#..##
#..##
#..##
...##
.....
.....
..###
'''.strip().split()

hallway = '''
#############.
#.............
#.############
#.............
#############.
#.............
#.############
#.............
#############.
'''.strip().split()

cornerU = '''
#...#...#..........
#.#.#.#.#.########.
#.#.#.#.#.#........
#.#.#.#.#.#.#######
#.#.#.#.#.#........
#.#.#.#.#.########.
#.#.#.#.#.#........
..#.#.#.#.#.#######
###...#...#........
'''.strip().split()

cornerD = '''
##################.
#...#...#...#...#..
#.#.#.#.#.#.#.#.#.#
#.#.#.#.#.#.#.#.#.#
#.#.#.#.#.#.#.#.#.#
#.#.#.#.#.#.#.#.#.#
#.#.#.#.#.#.#.#.#.#
..#.#.#.#.#.#.#.#.#
###...#...#...#...#
'''.strip().split()

player = ['P']
box = ['BB', 'BB']
storage = ['SS', 'SS']

def flip(m):
  return [s[::-1] for s in m]

def placeModule(level, m, pos):
  for i in range(len(m)):
    for j in range(len(m[0])):
      level[i+pos[0]][j+pos[1]] = m[i][j]

def levelToString(level):
  return '\n'.join(''.join(level[x]) for x in range(len(level)))

# Place modules

level = [['#']*64 for x in range(36)]

# Left bridges
for i in range(2):
  placeModule(level, bridge, (i*18, 0))
# Right bridges
for i in range(1):
  placeModule(level, flip(bridge), (i*18+9, 45))
# Paths
for i in range(2):
  for j in range(4):
    placeModule(level, flip(path), (i*18, j*10+5))
    placeModule(level, path, (i*18+9, j*10+5))
# Hallways
placeModule(level, cornerU, (0, 45))
placeModule(level, cornerD, (18*1+9, 45))
for i in range(2):
  placeModule(level, hallway, (9*i+9, 50))
# Player, box, storage
placeModule(level, player, (35, 41))
placeModule(level, box, (33, 43))
placeModule(level, storage, (6, 43))

print(36, 64)
print(levelToString(level))
