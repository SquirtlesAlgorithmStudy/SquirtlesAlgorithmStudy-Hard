package com.example.myapplication

/*
N개의 아파트
설치된곳 station
전파범위 W

이 중에서 일부 아파트 옥상에는 4g 기지국이 설치
기술이 발전해 5g 수요가 높아져 4g 기지국을 5g 기지국으로 바꾸려 합니다.
그런데 5g 기지국은 4g 기지국보다 전달 범위가 좁아, 4g 기지국을 5g 기지국으로 바꾸면 어떤 아파트에는 전파가 도달하지 않습니다.

예를 들어 11개의 아파트 [4, 11] 번째 아파트 옥상에는 4g 기지국이 설치
만약 이 4g 기지국이 전파 도달 거리가 1인 5g 기지국으로 바뀔 경우 모든 아파트에 전파를 전달할 수 없습니다.
(전파의 도달 거리가 W일 땐, 기지국이 설치된 아파트를 기준으로 전파를 양쪽으로 W만큼 전달할 수 있습니다.)


N: 200,000,000 이하
stations: 10,000 이하
stations 오름차순 정렬, 배열에 담긴 수는 N보다 같거나 작은 자연수
W: 10,000 이하의 자연수


 */



fun main() = with(System.`in`.bufferedReader()) {
    val n : Int = 11
    val stations = arrayOf(4,11)
    val w : Int = 1

    var answer = 0
    var start = 1

    for (i in stations) {

        if (start < i - w) {
            val end = i - w
            val length = end - start
            var count = length / (w * 2 +1)

            if (length % (w * 2 +1) != 0) count++

            answer += count

        }

        start = i + w + 1

    }

    if (stations.last() + w + 1<= n){

        start = stations.last() + w +1
        val end = n+1
        val length = end - start

        var count = length / (w * 2 + 1)
        if (length % (w * 2 + 1) != 0) count++

        answer += count

    }

// return answer


}