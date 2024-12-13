//package com.example.myapplication
//
//
//
///*
//
//
//징검다리를 건너야 하는 니니즈 친구들의 수는 무제한
//stones 배열의 크기는 1 이상 200,000 이하
//원소들의 값은 1 이상 200,000,000이하
//k는 1 이상 stones의 길이 이하인 자연수
//
//
//한 번에 건너뛸 수 있는 디딤돌의 최대 칸수 k
//
//
//슬라이딩 윈도우로 k개씩 묶고 -> 0이 되는 값 구해서 그게 가장 작은거
//
//2, 4, 5, 3, 2, 1, 4, 2, 5, 1
//
//[2, 4, 5], 3, 2, 1, 4, 2, 5, 1 -> [2,4,5]중 최댓값 5
//2, [4, 5, 3], 2, 1, 4, 2, 5, 1 -> [4,5,3]중 최댓값 5
//2, 4, [5, 3, 2], 1, 4, 2, 5, 1 -> [5,3,2]중 최댓값 5
//2, 4, 5, [3, 2, 1], 4, 2, 5, 1 -> [3,2,1]중 최댓값 3 5와 3 비교해서 작은 3 이 answer
//2, 4, 5, 3, [2, 1, 4], 2, 5, 1  -> [2,1,4]중 최댓값 4 3과 4 비교해서 작은값 3 answer
//2, 4, 5, 3, 2, [1, 4, 2], 5, 1  -> [1,4,2] 최댓값 4 answer 3
//2, 4, 5, 3, 2, 1, [4, 2, 5], 1 -> [4,2,5]중 최댓값 5 answer 3
//2, 4, 5, 3, 2, 1, 4, [2, 5, 1] ->  [2,5,1]중 최댓값 5 answer 3
//
// */
//
//
//
//
//import java.util.Deque
//import java.util.LinkedList
//
//fun main() {
//    val stones = intArrayOf(2, 4, 5, 3, 2, 1, 4, 2, 5, 1)
//    val k = 3
//
//    var answer = Int.MAX_VALUE
//    val window : Deque<Int> = LinkedList()
//
//    for (i in 0 until stones.size) {
//        if (window.isNotEmpty() && window.first() == i - k) window.removeFirst()
//
//        while (window.isNotEmpty() && stones[window.last()] <= stones[i]) {
//            window.removeLast()
//        }
//
//        window.addLast(i)
//
//        if (i >= k - 1) answer = minOf(answer, stones[window.first()])
//    }
//
////  return answer
//
//
////    println(answer)
//
//}