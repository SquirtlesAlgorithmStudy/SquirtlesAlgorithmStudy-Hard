//
//  main.swift
//  SquirtlesAlgorithmJH
//
//  Created by 김지현 on 8/12/25.
//

import Foundation

let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
let N = input[0]
let X = input[1]

var total = [1] + Array(repeating: 0, count: 50)
var p = [1] + Array(repeating: 0, count: 50)

for i in 1 ... N {
  total[i] = total[i-1] * 2 + 3
  p[i] = p[i-1] * 2 + 1
}

func solution(_ N: Int, _ X: Int) -> Int {
  if N == 0 || X == 0 {
    return X == 0 ? 0 : 1
  }

  if total[N] / 2 >= X {
    return solution(N - 1, X - 1)

  } else if total[N] / 2 + 1 == X {
    return p[N - 1] + 1

  } else {
    return p[N - 1] + 1 + solution(N - 1, X - p[N])
  }
}

print(solution(N, X))
