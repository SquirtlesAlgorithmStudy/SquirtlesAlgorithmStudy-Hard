#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
// #include <bits/stdc++.h>

using namespace std;

long long N; // 1~50만
list<pair<long long, long long>> li; 

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        long long s;
        cin >> s;
        li.push_back({i+1, s});
    }

    while(li.size() > 1){
        for(auto it=li.begin(); it!=li.end(); it++){
            long long add = 0;
            // 뒷 미생물 흡수여부 결정
            if(*it != li.back()){
                auto next = it;
                next++;

                if((*it).second >= (*next).second){
                    //(*it).second += (*next).second; -> 원소 값을 바꿔버리면 다음 loop에 영향을 미침. 
                    add += (*next).second; // 뒷 미생물, 앞 미생물 모두 확인 후 원소 값을 바꿀 수 있도록
                    li.erase(next);
                }
            }

            // 앞 미생물 흡수여부 결정
            if(*it != li.front()){
                auto prev = it;
                prev--;

                if((*it).second >= (*prev).second){
                    //(*it).second += (*prev).second;
                    add += (*prev).second;
                    li.erase(prev);
                }
            }

            (*it).second += add;
        }
        
    }

    cout << li.front().second << endl;
    cout << li.front().first << endl;

}

// index 결정과 erase 연산이 문제 일으킴 -> list로 해결.
// vector<pair<long long, long long>> sizes; // erase() 연산의 경우 vector는 최악의 O(N)을 갖지만, list는 O(1)을 갖는다.
// int 범위: 약 20억
// N개의 미생물, 각 미생물 크기는 최대 N. -> 20억/50만 = 4천인데, 50만 크기의 50만개 미생물이 합쳐지면 int 범위 넘음.
// long long 필수 이용

// int main(){
//     cin >> N;
//     for(int i=0; i<N; i++){
//         long long s;
//         cin >> s;
//         sizes.push_back({i+1, s});
//     }

//     while(sizes.size() > 1){
//         for(long long i=0; i<sizes.size(); i++){
//             if(i-1 >= 0 && sizes[i].second >= sizes[i-1].second){
//                 sizes[i].second += sizes[i-1].second;
//                 sizes.erase(remove(sizes.begin(), sizes.end(), sizes[i-1]),sizes.end());
//                 i--;
//                 continue;
//             }
//             if(i+1 < sizes.size() && sizes[i].second >= sizes[i+1].second){
//                 sizes[i].second += sizes[i+1].second;
//                 sizes.erase(remove(sizes.begin(), sizes.end(), sizes[i+1]),sizes.end());
//             }
//         }
//     }

//     cout << "initial location: " << sizes[0].first << endl << "final size: " << sizes[0].second << endl;
// }

