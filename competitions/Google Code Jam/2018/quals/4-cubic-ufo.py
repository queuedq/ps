import math

def axis_rotation(axis, th):
  if axis == "x":
    return [[1, 0, 0], [0, math.cos(th), -math.sin(th)], [0, math.sin(th), math.cos(th)]]
  if axis == "y":
    return [[math.cos(th), 0, math.sin(th)], [0, 1, 0], [-math.sin(th), 0, math.cos(th)]]
  if axis == "z":
    return [[math.cos(th), -math.sin(th), 0], [math.sin(th), math.cos(th), 0], [0, 0, 1]]

def rotate(A, v):
  return [ A[0][0] * v[0] + A[0][1] * v[1] + A[0][2] * v[2],
           A[1][0] * v[0] + A[1][1] * v[1] + A[1][2] * v[2],
           A[2][0] * v[0] + A[2][1] * v[1] + A[2][2] * v[2]]

def combine(A, B):
  C = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
  for i in range(3):
    for j in range(3):
      C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + A[i][2]*B[2][j]
  return C


# def cubic_area(view):
#   return view[0] + view[1] + view[2]

def view_vector(area):
  if area < math.sqrt(2):
    x = (area + math.sqrt(2 - area*area)) / 2
    y = area - x
    z = 0
  else:
    x = (2 * area + math.sqrt(6 - 2 * area*area)) / 6
    y = x
    z = area - 2 * x
  return [x, y, z]

def get_rotation(v):
  x = v[0]
  y = v[1]
  z = v[2]
  dist_y = math.sqrt(x*x + z*z)
  angle_x = math.asin(dist_y)
  angle_y = math.asin(x / dist_y)
  return combine(axis_rotation("x", -angle_x), axis_rotation("y", -angle_y))


T = int(input())

for test in range(1, T+1):
  A = float(input())
  v = view_vector(A)
  # print(v)
  # print(get_rotation(v))
  v0 = rotate(get_rotation(v), [0.5, 0, 0])
  v1 = rotate(get_rotation(v), [0, 0.5, 0])
  v2 = rotate(get_rotation(v), [0, 0, 0.5])

  print("Case #" + str(test) + ":")
  print(" ".join(map(str, v0)))
  print(" ".join(map(str, v1)))
  print(" ".join(map(str, v2)))
