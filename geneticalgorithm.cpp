#include<bits/stdc++.h>
#include "side.cpp"
using namespace std;
struct Solution{
    double answer_,value_1,value_2,value_3;
    void fitness(){
        double ans = (6 * value_1 + (-value_2) + pow(value_3,200) )-25;
        answer_ = (ans==0) ? 9999 : abs(1/ans);
    }



};

int main(){
    random_device random_;
    uniform_real_distribution<double> range(-100,100);
    vector<Solution>solutions;
    const int NUM = 100;
    for(int i =0;i<NUM;i++){
        solutions.emplace_back(Solution{0,range(random_),range(random_),range(random_)});
    }
   
    for(auto& s:solutions){
        s.fitness();
    }
    sort(solutions.begin(),solutions.end(),[](const auto& left_hand_side, const auto& right_hand_side){
        return left_hand_side.answer_>right_hand_side.answer_;

    });
    for_each(solutions.begin(),solutions.end()+10,[](const auto& s){
        cout << termcolor::italic;
        cout << termcolor::bright_white << "                   ";
        cout << termcolor::bright_white << "                    ";
        cout << termcolor::bright_white <<   "             ^^^^^^";
        cout << termcolor::bright_green << termcolor::bold <<  "Rank " << static_cast<int>(s.answer_) << termcolor::reset;
        cout << termcolor::bright_white << "^^^^^^";
       
        cout << endl;
        cout << endl;
        cout << "                                                ";
        cout << termcolor::red<< "X:" << " " << s.value_1;

        cout <<  "      " << termcolor::yellow  << "Y:" << " " << s.value_2;
        cout <<  "     " << termcolor::cyan<< "Z:" << " "<< s.value_3;
        cout << endl;
        cout << endl;
        cout << endl;
        
            }
            );
    const int Sample_size = 1000;
    vector<Solution>sample;
    copy(solutions.begin(),solutions.end()+Sample_size,back_inserter(sample));
    solutions.clear();
    uniform_real_distribution<double>m(0.99,1.10);
    for_each(sample.begin(),sample.end(),[&](auto &s){
        s.value_1 *= m(random_);
        s.value_2 *= m(random_);
        s.value_3 *= m(random_);
    });

    uniform_int_distribution<int> cross(0,Sample_size-1);
    for(int i =0;i<NUM;i++){
        solutions.push_back(Solution{0,sample[cross(random_)].value_1,sample[cross(random_)].value_2,sample[cross(random_)].value_3
        });
    }

}


    
    

