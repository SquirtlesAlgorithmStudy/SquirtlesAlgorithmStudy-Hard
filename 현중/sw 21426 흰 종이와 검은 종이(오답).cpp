// sw 21426 흰 종이와 검은 종이

// #include <iostream>
// #include <vector>

// using namespace std;

// // 1. 직사각형 선언
// struct Rectangle
// {
//     int x1, y1, x2, y2;
// };

// // 2. 두 종이가 겹치는지 확인하고 -> 두 직사각형이 겹치지 않은 조건을 나열 -> 그 반대 return
// bool isOverlapping (const Rectangle & r1, const Rectangle & r2){
//     return !(r2.x2 <= r1.x1 || r1.x2 <= r2.x1 || r2.y2 <= r1.y1 || r1.y2 <= r2.y1);
// }

// // 3. 겹치는 부분 계산
// Rectangle getOverlap(const Rectangle & r1, const Rectangle & r2){
//     int x1 = max(r1.x1, r2.x1);
//     int y1 = max(r1.y1, r2.y1);
//     int x2 = min(r1.x2, r2.x2);
//     int y2 = min(r1.y2, r2.y2);

//     return {x1,y1,x2,y2};
// }

// // 4.
// bool isWhileVisible(const Rectangle &white, const Rectangle &black1, const Rectangle &black2){
//     // 1. 흰종이와 검정종이가 안겹치는 경우 => true
//     if(!isOverlapping(white, black1) && !isOverlapping(white, black2)){
//         return true;
//     }

//     // 2. 흰종이와 검정종이가 겹치는 경우
//     // 2.1 흰종이 전체를 덮이지 않은 영역으로 간주 -> uncovered 벡터에 저장
//     vector<Rectangle> uncovered;
//     uncovered.push_back(white);

//     // 2.2 검정종이
//     for(const auto &black : {black1, black2}){
//         vector<Rectangle> new_uncovered;

//     }
//         // 2.2.1 검은 종이를 덮는 영역을 계산하여 흰종이에서 덮이지 않은 영역 계산
//         // 만약 검은 종이가 덮이지 않은 영역과 겹친다면

//     for(const auto &black : {black1, black2}){

//     }
// }
// // 4.1 흰 종이가 두 검은 종이와 전혀 겹치지 않은 부분

#include <iostream>
#include <vector>
using namespace std;

struct Rectangle
{
    int x1, y1, x2, y2;
};

bool isOverlapping(const Rectangle &r1, const Rectangle &r2)
{
    return !(r1.x2 <= r2.x1 || r2.x2 <= r1.x1 || r1.y2 <= r2.y1 || r2.y2 <= r1.y1);
}

Rectangle getOverlap(const Rectangle &r1, const Rectangle &r2)
{
    int x1 = max(r1.x1, r2.x1);
    int y1 = max(r1.y1, r2.y1);
    int x2 = min(r1.x2, r2.x2);
    int y2 = min(r1.y2, r2.y2);
    return {x1, y1, x2, y2};
}

bool isWhitePaperVisible(const Rectangle &white, const Rectangle &black1, const Rectangle &black2)
{
    if (!isOverlapping(white, black1) && !isOverlapping(white, black2))
    {
        return true;
    }

    vector<Rectangle> uncovered; // Rectangle 객체들을 저장할 수 있는 vector 생성
    uncovered.push_back(white);  // 흰 종이가 덮히지 않은 상태로 시작

    for (const auto &black : {black1, black2})
    {
        vector<Rectangle> new_uncovered;
        for (const auto &rect : uncovered)
        {
            if (isOverlapping(rect, black))
            {
                Rectangle overlap = getOverlap(rect, black);
                if (rect.x1 < overlap.x1)
                    new_uncovered.push_back({rect.x1, rect.y1, overlap.x1, rect.y2});
                if (overlap.x2 < rect.x2)
                    new_uncovered.push_back({overlap.x2, rect.y1, rect.x2, rect.y2});
                if (rect.y1 < overlap.y1)
                    new_uncovered.push_back({overlap.x1, rect.y1, overlap.x2, overlap.y1});
                if (overlap.y2 < rect.y2)
                    new_uncovered.push_back({overlap.x1, overlap.y2, overlap.x2, rect.y2});
            }
            else
            {
                new_uncovered.push_back(rect);
            }
        }
        uncovered = new_uncovered;
    }

    return !uncovered.empty();
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        Rectangle white, black1, black2;
        cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;
        cin >> black1.x1 >> black1.y1 >> black1.x2 >> black1.y2;
        cin >> black2.x1 >> black2.y1 >> black2.x2 >> black2.y2;

        cout << (isWhitePaperVisible(white, black1, black2) ? "YES" : "NO") << endl;
    }
    return 0;
}
