//
//
//fun main() = with(System.`in`.bufferedReader()) {
//
//    val play_time = "02:03:55"
//    val adv_time = "00:14:15"
//    val logs : Array<String> = arrayOf(
//        "01:20:15-01:45:14",
//        "00:40:31-01:00:00",
//        "00:25:50-00:48:29",
//        "01:30:59-01:53:29",
//        "01:37:44-02:02:30"
//    )
//
//    var answer: String = ""
//    var maxViewers = 0
//    var bestStart = 0
//
//    val playTimeSec = timeToSec(play_time)
//    val adTimeSec = timeToSec(adv_time)
//
//    val viewers = IntArray(playTimeSec + 1)
//
//    for (i in logs) {
//        val (s,e) = i.split("-").map { timeToSec(it) }
//
//        for (j in s until e) {
//            viewers[j]++
//        }
//    }
//
//    for (j in 0.. playTimeSec - adTimeSec) {
//        val currentViewers = viewers.sliceArray(j until j + adTimeSec).sum()
//        if (currentViewers > maxViewers) {
//            maxViewers = currentViewers
//            bestStart = j
//        }
//    }
//
//    answer = secToTime(bestStart)
//
//}
//
//fun timeToSec(time:String) : Int {
//    val (h, m, s) = time.split(":").map { it.toInt() }
//    return h * 3600 + m * 60 + s
//}
//
//fun secToTime(time:Int) : String {
//    val h = time / 3600
//    val m = (time % 3600) / 60
//    val s = time % 60
//    return "%02d:%02d:%02d".format(h, m, s)
//}