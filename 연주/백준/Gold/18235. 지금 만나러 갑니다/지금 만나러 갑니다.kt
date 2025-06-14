import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.pow

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val input = br.readLine().split(" ")
    val max = input[0].toInt()
    val a = input[1].toInt()
    val b = input[2].toInt()

    val aSet = mutableSetOf<Int>(a)
    val bSet = mutableSetOf<Int>(b)

    var answer = 1
    while (true) {
        val offset = 2.0.pow(answer - 1).toInt()

        val oldASet = aSet.toSet()
        val oldBSet = bSet.toSet()
        aSet.clear()
        bSet.clear()
        oldASet.forEach { a ->
            listOf(a - offset, a + offset).forEach { newA ->
                if (isInLine(max, newA)) {
                    aSet.add(newA)
                }
            }
        }
        oldBSet.forEach { b ->
            listOf(b - offset, b + offset).forEach { newB ->
                if (isInLine(max, newB)) {
                    bSet.add(newB)
                }
            }
        }

        val hasCommon = if (aSet.size < bSet.size) {
            aSet.any { it in bSet }
        } else {
            bSet.any { it in aSet }
        }

        if (hasCommon) {
            break
        }

        if (aSet.isEmpty() && bSet.isEmpty()) {
            answer = -1
            break
        }

        answer++
    }

    println(answer)
}

fun isInLine(max: Int, curPos: Int): Boolean =
    curPos <= max && curPos >= 1