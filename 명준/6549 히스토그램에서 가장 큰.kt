package com.example.myapplication

import java.util.Stack


/*
각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000)
그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1,000,000,000)가 주어진다.
이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다.
모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.

7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0

*/
fun main() = with(System.`in`.bufferedReader()) {
   var squares: String

   while (true) {
       squares = readLine()

       if (squares == "0") break

       val list = squares.split(" ").map { it.toLong() }
       val n = list[0].toInt()
       val num = list.subList(1, list.size).toLongArray()

       val stack = Stack<Int>()
       var answer = 0L

       for (i in 0 until n) {
           while (stack.isNotEmpty() && num[stack.peek()] >= num[i]) {
               val height = num[stack.pop()]
               val width = if (stack.isEmpty()) i else i - stack.peek() - 1
               answer = maxOf(answer, height * width)
           }
           stack.push(i)
       }

       while (stack.isNotEmpty()) {
           val height = num[stack.pop()]
           val width = if (stack.isEmpty()) n else n - stack.peek() - 1
           answer = maxOf(answer, height * width)
       }

       println(answer)
   }
}