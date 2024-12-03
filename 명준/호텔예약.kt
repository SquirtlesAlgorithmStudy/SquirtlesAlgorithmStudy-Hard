fun main() = with(System.`in`.bufferedReader()) {
    val book_time = arrayOf(
        arrayOf("15:00", "17:00"),
        arrayOf("16:40", "18:20"),
        arrayOf("14:20", "15:20"),
        arrayOf("14:10", "19:20"),
        arrayOf("18:20", "21:20"))

    var answer = 0
    var checkRoom = mutableListOf<MutableList<Int>>()

    val bookTimeSort = book_time.toList().sortedBy { it.first() }

    bookTimeSort.forEach {

        val startTime = it.first().split(":")[0].toInt() * 60 + it.first().split(":")[1].toInt()
        val endTime = it.last().split(":")[0].toInt() * 60 + it.last().split(":")[1].toInt() + 10
        val roomTime = mutableListOf(startTime,endTime)

        if(checkRoom.isEmpty())  checkRoom.add(roomTime)

        else {
            var addCheck = true
            for(i in 0 until  checkRoom.size){
                if(checkRoom[i].last() <= startTime) {
                    addCheck = false
                    checkRoom[i].add(endTime)
                    break
                }
            }

            if(addCheck) checkRoom.add(roomTime)
        }

        answer = checkRoom.size
    }
//    return answer
//    println(answer)
}

//
//    return calculateMinRooms(book_time)
//}
//    fun calculateMinRooms(book_time: Array<Array<String>>): Int {
//        val sortedBookings = sortedBook(book_time)
//        val checkRoom = mutableListOf<MutableList<Int>>()
//
//        sortedBookings.forEach { (startTime, endTime) ->
//            assignRooms(checkRoom, startTime, endTime)
//        }
//
//        return checkRoom.size
//    }
//
//    fun assignRooms(checkRoom: MutableList<MutableList<Int>>, startTime: Int, endTime: Int) {
//
//        if (checkRoom.isEmpty()) {
//            checkRoom.add(mutableListOf(startTime, endTime))
//            return
//        }
//        var isRoomAdd = false
//        for (room in checkRoom) {
//            if (room.last() <= startTime) {
//                room.add(endTime)
//                isRoomAdd = true
//                break
//            }
//        }
//
//        if (!isRoomAdd) checkRoom.add(mutableListOf(startTime, endTime))
//    }
//
//
//    fun sortedBook(book_time: Array<Array<String>>): List<Pair<Int, Int>> {
//        return book_time.map {
//            val startTime = timeToMin(it[0])
//            val endTime = timeToMin(it[1]) + 10
//            startTime to endTime
//        }.sortedBy { it.first }
//    }
//
//    fun timeToMin(time: String): Int {
//        val (hour, min) = time.split(":").map { it.toInt() }
//        return (hour * 60) + min
//    }