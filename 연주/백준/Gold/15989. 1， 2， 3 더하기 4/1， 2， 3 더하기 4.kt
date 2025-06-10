import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val dp = Array(10001) { IntArray(4) }
    dp[1][1] = 1
    dp[1][2] = 0
    dp[1][3] = 0
    dp[2][1] = 1
    dp[2][2] = 1
    dp[2][3] = 0
    dp[3][1] = 1
    dp[3][2] = 1
    dp[3][3] = 1
    for (i in 4..10000) {
        dp[i][1] = 1
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2]
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3]
    }

    val br = BufferedReader(InputStreamReader(System.`in`))
    val a = br.readLine().toInt()
    val arr = IntArray(a)
    for (i in 0 .. a - 1) {
        arr[i] = br.readLine().toInt()
    }

    for (i in arr) {
        println(dp[i][1] + dp[i][2] + dp[i][3])
    }
}
