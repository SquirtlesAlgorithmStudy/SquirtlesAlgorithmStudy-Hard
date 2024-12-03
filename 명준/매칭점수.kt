//package com.example.myapplication
//
//
//
///*
//한 웹페이지에 대해서 기본점수, 외부 링크 수, 링크점수, 그리고 매칭점수를 구할 수 있다.
//기본점수 = 텍스트 중 검색어가 등장하는 횟수
//외부링크 = (해당웹페이지) 에서 (다른 외부 페이지) 로 연결된 링크의 갯수
//링크점수 = (해당 페이지로 링크가 걸린 다른 웹페이지)의 기본점수 / 링크점수   의
//매칭점수 = 기본점수 + 링크점수
//
//1.HTML추출하고 파싱하기
//URL , 외부링크 ,    body에 등장한 검색횟수 구하기
//123 다 <전달할> 점수 계산한 후 받은 링크점수 계산하기
//매칭점수 + 링크점수로 매칭점수 계산후
//비교하여 index 반환, 같다면 낮은거
//
//
//
//
//
//검색어 words와 웹 페이지의 HTML 목록 pages가 주어질때 , 매칭점수가 가장 높은 웹 페이지의 index를 구하라, 여러개라면 번호가 작은거
//
//
//제한사항
//
//pages는 HTML 형식의 웹페이지가 문자열 형태로 들어있는 배열이고, 길이는 1 이상 20 이하이다.
//한 웹페이지 문자열의 길이는 1 이상 1,500 이하이다.
//웹페이지의 index는 pages 배열의 index와 같으며 0부터 시작한다.
//한 웹페이지의 url은 HTML의 태그 내에 태그의 값으로 주어진다.
//
//파싱할때
//
//
//입력 예시
//
//<html lang="ko" xml:lang="ko" xmlns="http://www.w3.org/1999/xhtml">
//<head>
//  <meta charset="utf-8">
//  <meta property="og:url" content="https://a.com"/>
//</head>
//<body>
//Blind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit.
//<a href="https://b.com"> Link to b </a>
//</body>
//</html>
//
//<html lang="ko" xml:lang="ko" xmlns="http://www.w3.org/1999/xhtml">
//<head>
//  <meta charset="utf-8">
//  <meta property="og:url" content="https://b.com"/>
//</head>
//<body>
//Suspendisse potenti. Vivamus venenatis tellus non turpis bibendum,
//<a href="https://a.com"> Link to a </a>
//blind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.
//<a href="https://c.com"> Link to c </a>
//</body>
//</html>
//
//
//<html lang="ko" xml:lang="ko" xmlns="http://www.w3.org/1999/xhtml">
//<head>
//  <meta charset="utf-8">
//  <meta property="og:url" content="https://c.com"/>
//</head>
//
//<body>
//Ut condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind
//
//<a href="https://a.com"> Link to a </a>
//</body>
//
//</html>
//
//
//1.HTML추출하고 파싱하기 -> URL , 외부링크 , 등장한 words 횟수구하기
//
// 다 <전달할> 점수 계산한 후 받은 링크점수 계산하기
//매칭점수 + 링크점수로 매칭점수 계산후
//비교하여 index 반환, 같다면 낮은거
//
//
//regex .*?
//
// */
//
//data class Pages(
//    val index : Int,
//    val url : String,
//    val basicScore : Int,
//    val link : List<String>,
//    var matchingScore : Double = 0.0 ,
//    var totalScore: Double = 0.0
//)
//
//fun findUrl(page : String) : String{
//    val urlRegex = ("<meta property=\"og:url\" content=\"(.*?)\"").toRegex()
//    return urlRegex.find(page)!!.groupValues[1]
//}
//
//fun findLinks(page: String) : List<String>{
//    val linkRegex = "<a href=\"(.*?)\"".toRegex()
//    return linkRegex.findAll(page).map { it.groupValues[1] }.toList()
//}
//
//
//fun wordsCount(page: String, word: String) : Int{
//    val body = page.substringAfter("<body>").substringBefore("</body>").lowercase()
//    val pattern = "\\b${word}\\b".toRegex()
//    return pattern.findAll(body).count()
//}
//
//
//
//fun main() = with(System.`in`.bufferedReader()) {
//    val word = "Muzi"
//    val solution = Solution()
//    val pages = arrayOf(
//        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"
//
//    )
//    val result = solution.solution(word, pages)
//    println(result)
//
//}
//
//
//
//class Solution {
//    fun solution(word: String, pages: Array<String>): Int {
//        var answer = 0
//        val smallWord = word.lowercase()
//
//        val parsePages = pages.mapIndexed { index, page ->
//            val url = findUrl(page)
//            val links = findLinks(page)
//            val basicScore = wordsCount(page, smallWord)
//            Pages(index,url,basicScore,links)
//        }
//
//        val urlToPages = parsePages.associateBy { it.url }
//
//        parsePages.forEach {pages ->
//            pages.link.forEach {link ->
//                if (pages.link.isNotEmpty()) {
//                    urlToPages[link]?.matchingScore =
//                        (urlToPages[link]?.matchingScore ?: 0.0) + (pages.basicScore / pages.link.size.toDouble())
//                }
//            }
//        }
//
//        parsePages.forEach {page ->
//            page.totalScore = page.matchingScore + page.basicScore
//        }
//
//        answer = parsePages.maxByOrNull { it.totalScore }!!.index
//
//        return answer
//    }
//
//}
