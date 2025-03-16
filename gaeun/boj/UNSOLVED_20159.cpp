
이해 불가능

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<int> card;
// vector<int> prefix_odd, prefix_even;
// int N;
// int result;

// int main(){
//     cin >> N;
//     prefix_even.resize(N,0);
//     prefix_odd.resize(N,0);
//     for(int i=0; i<N; i++){
//         int c;
//         cin >> c;
//         card.push_back(c);

//         if(i%2 == 0){
//             if(i==0){
//                 prefix_even[i] = c;
//                 prefix_odd[i] = 0;
//             } 
//             else{
//                 prefix_even[i] = prefix_even[i-1] + c;
//                 prefix_odd[i] = prefix_odd[i-1];
//             }             
//         }
//         else{
//             prefix_even[i] = prefix_even[i-1];
//             prefix_odd[i] = prefix_odd[i-1] + c;
//         }
//     }

//     int result = 0;
//     for(int i=0; i<N; i++){
//         int tmp = 0;
//         if(i-1 >= 0){
//             tmp += prefix_even[i-1];
//         }
//         tmp += prefix_odd[N-1] - prefix_odd[i];

//         cout << "i= " << i << ": " << tmp << endl;
//         result = max(tmp, result);
//     }

//     cout << result << endl;

// }