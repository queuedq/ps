// Debugging
func print2d(_ array: [[Any]]) {
  print("[")
  for element in array {
    print(element)
  }
  print("]")
}

class DisjointSet {
  var parent: [Int]
  var size: [Int]

  init(_ length: Int) {
    parent = [Int](0..<length)
    size = Array(repeating: 1, count: length)
  }

  func find(_ item: Int) -> Int {
    var x = item
    while x != parent[x] {
      parent[x] = parent[parent[x]]
      x = parent[x]
    }
    return x
  }

  func union(_ x: Int, _ y: Int) {
    var xRoot = find(x)
    var yRoot = find(y)
    if xRoot == yRoot {
      return
    }
    if size[xRoot] < size[yRoot] {
      (xRoot, yRoot) = (yRoot, xRoot)
    }
    parent[yRoot] = xRoot
    size[xRoot] = size[xRoot] + size[yRoot]
  }
}

// Input
var N = 0, K = 0, x = [Int](), y = [Int]()
let input = readLine()!
let split = input.split(separator: " ")
N = Int(split[0])!
K = Int(split[1])!

for _ in 0..<K {
  let input = readLine()!
  let split = input.split(separator: " ")
  let xx = Int(split[0])!
  let yy = Int(split[1])!
  x.append(xx)
  y.append(yy)
}

func map(_ x: Int, _ y: Int) -> Int { // Map to index of DisjointSet
  return (x - 1) * N + (y - 1)
}

func isOutOfBound(_ x: Int, _ y: Int) -> Bool {
  return x == 0 || x == N + 1 || y == 0 || y == N + 1
}

var civilSet = DisjointSet(N * N) // Unified civil
var year = 0
var currentCivil = [(x: Int, y: Int)]() // Current year's new civil
var isCivilized = Array(
    repeating: Array(repeating:false, count: N + 2),
    count: N + 2
  )
for i in 0..<K {
  isCivilized[x[i]][y[i]] = true // Initial civilization
  currentCivil.append((x: x[i], y: y[i]))
}


while true {
  // Unify civils
  for civ in currentCivil {
    if isCivilized[civ.x - 1][civ.y] {
      civilSet.union(map(civ.x - 1, civ.y), map(civ.x, civ.y))
    }
    if isCivilized[civ.x + 1][civ.y] {
      civilSet.union(map(civ.x + 1, civ.y), map(civ.x, civ.y))
    }
    if isCivilized[civ.x][civ.y - 1] {
      civilSet.union(map(civ.x, civ.y - 1), map(civ.x, civ.y))
    }
    if isCivilized[civ.x][civ.y + 1] {
      civilSet.union(map(civ.x, civ.y + 1), map(civ.x, civ.y))
    }
  }

  // Debug
  // print2d(isCivilized)
  // let civilView = (1...N).map { i in (1...N).map { j in civilSet.find(map(i, j)) } }
  // print2d(civilView)

  // Count civilizations
  var uniqueCivil = -2 // -2: Initial state, -1: Non-unique civil found
  for civ in currentCivil {
    if uniqueCivil == -2 {
      uniqueCivil = civilSet.find(map(civ.x, civ.y))
    } else if uniqueCivil != civilSet.find(map(civ.x, civ.y)) {
      uniqueCivil = -1
      break
    }
  }

  if uniqueCivil >= 0 {
    break
  }

  // Prepare next year
  year += 1
  var nextCivil = [(x: Int, y: Int)]()
  for civ in currentCivil {
    if !isOutOfBound(civ.x - 1, civ.y) && !isCivilized[civ.x - 1][civ.y] {
      isCivilized[civ.x - 1][civ.y] = true
      nextCivil.append((x: civ.x - 1, y: civ.y))
    }
    if !isOutOfBound(civ.x + 1, civ.y) && !isCivilized[civ.x + 1][civ.y] {
      isCivilized[civ.x + 1][civ.y] = true
      nextCivil.append((x: civ.x + 1, y: civ.y))
    }
    if !isOutOfBound(civ.x, civ.y - 1) && !isCivilized[civ.x][civ.y - 1] {
      isCivilized[civ.x][civ.y - 1] = true
      nextCivil.append((x: civ.x, y: civ.y - 1))
    }
    if !isOutOfBound(civ.x, civ.y + 1) && !isCivilized[civ.x][civ.y + 1] {
      isCivilized[civ.x][civ.y + 1] = true
      nextCivil.append((x: civ.x, y: civ.y + 1))
    }
  }

  currentCivil = nextCivil
}

print(year)
