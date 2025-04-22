#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
struct meetingInfo{
    int start, end;
};
vector<meetingInfo> meetingList;

bool compare(meetingInfo a, meetingInfo b){
    if(a.end != b.end) return a.end < b.end;
    return a.start < b.start;
}

int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        meetingInfo input;
        cin >> input.start >> input.end;

        meetingList.push_back(input);
    }

    sort(meetingList.begin(), meetingList.end(), compare);

    meetingInfo meeting = meetingList[0];
    int cnt = 1;
    for(int i=1; i<meetingList.size(); i++){
        if(meetingList[i].start >= meeting.end){
            meeting = meetingList[i];
            cnt++;
        }       
    }

    cout << cnt << "\n";
}