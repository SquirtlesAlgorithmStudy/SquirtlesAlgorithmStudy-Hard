//
//  main.swift
//  SquirtlesAlgorithmJH
//
//  Created by 김지현 on 7/14/25.
//

import Foundation

func solution(_ n:Int) -> Int {
  var dp = [Int](repeating: 0, count: n+1)
  dp[0] = 1  // 그냥 계산 용이하게 1이라고 침

  for i in 1...n {
    for j in 0..<i {
      dp[i] += dp[j] * dp[i-1-j]
    }
  }

  return dp[n]
}

// C(n) -> n쌍 가지고 만들 수 있는 올바른 괄호의 개수

// 1. 이전 것의 결과가 다음 것의 결과 개수에 포함된다고 생각되어 dp로
// 2. 어쨌든 ( 으로 시작해야함
// 3. ( 에 대응하는 ) 가 어디에 위치하느냐
// 3-1. ( 다음에 바로 )가 온다면 나머지 C(n-1)
// 3-2. ( '한쌍' 그 다음 ) 가 온다면 C(1) 에다가 두쌍 쓰였으니까 C(n-2) 둘 곱한값
// 3-3. ( '두쌍' 그 다음 ) 가 온다면 C(2) 에다가 세쌍 쓰였으니까 C(n-3) 둘 곱한값 .....
// 4. 따라서 C(n) = 1*C(n-1) + C(1)*C(n-2) + C(2)*C(n-3) + .. + C(n-1)*1
