package com.example.myapplication

/*
행렬의 세로 길이(행 개수) rows, 가로 길이(열 개수) columns,  회전들의 목록 queries
각 회전들을 배열에 적용한 뒤 위치가 바뀐 숫자들 중 가장 작은 숫자들을 순서대로 배열에 담아 return

rows,columns = 2 ..100
처음은 가로로1씩증가
queries = 1 .. 10,000

1 ≤ x1 < x2 ≤ rows,
1 ≤ y1 < y2 ≤ columns

*/


fun main() = with(System.`in`.bufferedReader()) {

    val rows : Int = 6
    val columns: Int = 6
    val queries: Array<IntArray> = arrayOf(
        intArrayOf(2,2,5,4),
        intArrayOf(3,3,6,6),
        intArrayOf(5,1,6,3))



    var arr = Array (rows) {Array (columns) {0}}
    var num = 1

    for (i in 0 until rows) {
        for (j in 0 until columns) {
            arr[i][j] = num
            num++
        }
    }

    val answer = mutableListOf<Int>()

    for (k in queries) {
        val x1 = k[0] - 1
        val y1 = k[1] - 1
        val x2 = k[2] - 1
        val y2 = k[3] - 1
        var min = Int.MAX_VALUE

        var prevValue = arr[x1+1][y1]

        for (col in y1..y2) {
            val temp = arr[x1][col]
            arr[x1][col] = prevValue
            prevValue = temp
            min = minOf(min, prevValue)
        }

        for (row in (x1 + 1)..x2) {
            val temp = arr[row][y2]
            arr[row][y2] = prevValue
            prevValue = temp
            min = minOf(min, prevValue)
        }

        for (col in (y2 - 1) downTo y1) {
            val temp = arr[x2][col]
            arr[x2][col] = prevValue
            prevValue = temp
            min = minOf(min, prevValue)
        }

        for (row in (x2 - 1) downTo x1) {
            val temp = arr[row][y1]
            arr[row][y1] = prevValue
            prevValue = temp
            min = minOf(min, prevValue)
        }
        answer.add(min)

    }

//    return answer.toIntArray()

}